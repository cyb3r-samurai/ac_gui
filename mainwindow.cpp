#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    initObjects();
    startThreads();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    close();
}

void MainWindow::startThreads()
{
    connect(thread_ac, &QThread::started, m_ac, &AC::connectToModBus);
    connect(thread_messageProcessor, &QThread::started, m_messageProcessor, &MessageProcessor::startTimer);
    connect(thread_planFactory, &QThread::started, m_planFactory, &PlanFactory::start);
    connect(thread_dataServer, &QThread::started, m_dataServer, &DataServer::connect_server);
    connect(thread_p2SocketHandler, &QThread::started, m_p2SocketHandler, &P2SocketHandler::start);


    thread_reportStateChecker->start();
    thread_ac->start();
    thread_planFactory->start();
    thread_messageProcessor->start();
    thread_dataServer->start();
    thread_p2SocketHandler->start();
    thread_tcpServer->start();

}

void MainWindow::initObjects()
{
    // init plan storage
    m_planStoragePtr = std::make_shared<PlanStorage>();

    // initiating objects
    m_p2SocketHandler = new P2SocketHandler();
    m_tcpServer = new TcpServer();
    m_planFactory = new PlanFactory(m_planStoragePtr);
    m_ac = new AC(m_planStoragePtr);
    m_reportStateChecker = new ReportStateChecker(m_planStoragePtr);
    m_messageProcessor = new MessageProcessor(m_planStoragePtr, m_reportStateChecker, m_ac, m_planFactory);
    m_dataServer = new DataServer(m_p2SocketHandler);

    // initiating connecetion between diffrent threads

    connect(m_tcpServer, &TcpServer::client_msg_received,
            m_messageProcessor, &MessageProcessor::on_client_msg_recieved);
    connect(m_tcpServer, &TcpServer::connected,
            m_messageProcessor, &MessageProcessor::on_connected);
    connect(m_messageProcessor, &MessageProcessor::message_created,
            m_tcpServer, &TcpServer::on_message_ready);

    connect(m_ac, &AC::accept_cell, m_dataServer, &DataServer::onAcceptCel);
    connect(m_ac, &AC::finish_data_chanel, m_dataServer, &DataServer::onStop);
    connect(m_ac, &AC::stopSending, m_dataServer, &DataServer::onTotalStop);
    connect(m_ac, &AC::finish_segment, m_dataServer, &DataServer::onFinishSegment);

    connect(m_planFactory, &PlanFactory::stopDataChanel,
            m_dataServer, &DataServer::onStopDataChanel);
    connect(m_planFactory, &PlanFactory::stopSegment,
            m_dataServer, &DataServer::onStopSegment);

    //moving to threads

    thread_tcpServer = new QThread(this);
    thread_ac = new QThread(this);
    thread_messageProcessor = new QThread(this);
    thread_planFactory = new QThread(this);
    thread_dataServer = new QThread(this);
    thread_reportStateChecker = new QThread(this);
    thread_p2SocketHandler = new QThread(this);

    m_tcpServer->moveToThread(thread_tcpServer);
    m_ac->moveToThread(thread_ac);

    m_planFactory->moveToThread(thread_planFactory);
    m_dataServer->moveToThread(thread_dataServer);
    m_reportStateChecker->moveToThread(thread_reportStateChecker);
    m_p2SocketHandler->moveToThread(thread_p2SocketHandler);
    m_messageProcessor->moveToThread(thread_messageProcessor);

}


void MainWindow::closeEvent(QCloseEvent* event) {

    if (m_p2SocketHandler) {
        QMetaObject::invokeMethod(m_p2SocketHandler,"stop", Qt::QueuedConnection);
        thread_p2SocketHandler->quit();
        if(!thread_p2SocketHandler->wait(2000)) {
            qWarning() << "thread_not finished";
        }
        m_p2SocketHandler->deleteLater();
    }
    if (m_dataServer){
        QMetaObject::invokeMethod(m_dataServer,"stop", Qt::QueuedConnection);
        thread_dataServer->quit();
        if(!thread_dataServer->wait(2000)) {
            qWarning() << "thread_not finished";
        }
        m_dataServer->deleteLater();
    }
    if (m_tcpServer) {
        QMetaObject::invokeMethod(m_tcpServer,"stop", Qt::QueuedConnection);
        thread_tcpServer->quit();
        if(!thread_tcpServer->wait(2000)) {
            qWarning() << "thread_not finished";
        }
        m_tcpServer->deleteLater();
    }
    if (m_messageProcessor){
        QMetaObject::invokeMethod(m_messageProcessor, "stop", Qt::QueuedConnection);
        thread_messageProcessor->quit();
        if(!thread_messageProcessor->wait(2000)){
            qWarning() << "thread_not finished";
        }
        m_messageProcessor->deleteLater();
    }
    if (m_planFactory){
        QMetaObject::invokeMethod(m_planFactory,"stop", Qt::QueuedConnection);
        thread_planFactory->quit();
        if(!thread_planFactory->wait(2000)){
            qWarning() << "thread_not finished";
        }
        m_planFactory->deleteLater();
    }
    if(m_ac) {
        QMetaObject::invokeMethod(m_ac,"stop", Qt::QueuedConnection);
        thread_ac->quit();
        if(!thread_ac->wait(2000)){
            qWarning() << "thread_not finished";
        }
        m_ac->deleteLater();
    }

    if(m_reportStateChecker) {
        thread_reportStateChecker->quit();
        if(!thread_reportStateChecker->wait(2000)){
            qWarning() << "thread_not finished";
        }
        m_reportStateChecker->deleteLater();
    }


    QMainWindow::closeEvent(event);
}
