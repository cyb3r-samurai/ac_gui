#include "p2sockethandler.h"
#include "QThread"

P2SocketHandler::P2SocketHandler(QObject *parent)
    : QObject{parent}
{}

P2SocketHandler::~P2SocketHandler()
{
    stop();
}
void P2SocketHandler::start()
{
    loadSettings();

    reconnectTimer = new QTimer;
    reconnectTimer->setSingleShot(true);
    connect(reconnectTimer, &QTimer::timeout, this, [this]() {

            m_socket->abort();
            m_socket->connectToHost(m_ip, m_port);
            m_socket->waitForConnected(4000);
            if(m_socket->state() != QAbstractSocket::ConnectedState){
                reconnectTimer->start(5000);
            }
    });

 //   QThread* socket_thread;
 //   socket_thread = new QThread();

    m_socket = new QTcpSocket(this);
 //   m_socket->moveToThread(socket_thread);
 //   socket_thread->start(QThread::TimeCriticalPriority);

    m_socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    m_socket->setSocketOption(QAbstractSocket::SendBufferSizeSocketOption, 4 * 1024 * 1024);
    m_socket->connectToHost(m_ip, m_port);

#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
    connect(m_socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError)
#else
    connect(m_socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, [this](QAbstractSocket::SocketError)
#endif
            {
                qWarning() <<  "TCP P2"  << QString(m_socket->errorString());
                if(m_socket->state()!= QAbstractSocket::ConnectedState) {
                    connected = false;
                    reconnectTimer->start(5000);
                }
            });

    connect(m_socket, &QTcpSocket::stateChanged, this, [this](int state)
            {
                if (state == QAbstractSocket::UnconnectedState)
                {
                    qWarning() << "Соединение с П2 не установленно";
                    connected = false;
                }
                else if (state == QAbstractSocket::ConnectedState)
                {
                    qDebug() << "Соединение с П2 установлено";
                    connected = true;
                    emit p2StateChnge(connected);
                }
            });
    connect(m_socket, &QTcpSocket::disconnected, this, [this](){
        if(m_socket->state() != QAbstractSocket::ConnectedState){
            connected= false;
            reconnectTimer->start(5000);
            emit p2StateChnge(connected);
        }
});
}

void P2SocketHandler::stop()
{
    m_socket->deleteLater();
   reconnectTimer->deleteLater();
}

void P2SocketHandler::Send(std::shared_ptr<Report>report)
{
    if(connected){
        QByteArray data = report->serializeStruct();
    Header header;
    header.msg_type = 0x82;
    header.n = 20 + (2 * report->m);
    header.time = getTime();

    Q_ASSERT(data.size() == header.n);
    QByteArray packet;
    packet.append(header.serializeStruct());
    packet.append(data);

 //   m_socket->write(header.serializeStruct());
  //  m_socket->write(data);
    // int fd = m_socket->socketDescriptor();
    // ssize_t bytesSent =0;
    // if(fd != -1) {
    //     bytesSent  = ::send(fd, packet.constData(),data.size(),MSG_NOSIGNAL);
    // }
    // if(bytesSent == -1) {
    //     switch(errno) {
    //     case EAGAIN:
    //         qWarning() << "socket buffer full, would block";
    //         break;
    //     case ECONNRESET:
    //         qWarning() << "connection reset by peer";
    //         break;
    //     default:
    //         qWarning() << "send error" << strerror(errno);

    //     }
    // }
    // else{
    // count += bytesSent;
    count +=  m_socket->write(packet);

    if (count > 1000000){
        qDebug() << "Отаправленно 1000000 байт в П2";
        count = 0;
    }
    // if(bytesSent != static_cast<ssize_t>(data.size())) {
    //     qWarning() << "partial write:" << bytesSent << "of" << data.size();
    // }
   // }
    }
}

void P2SocketHandler::sendData(const QByteArray &data)
{
    if (connected) {
        if(m_socket->bytesToWrite() < 4 * 1024 * 1024){
          //  if(!m_socket->waitForBytesWritten(0)) {
           //     qDebug() << "system socket not ready";
           // }
           // else {
            count += m_socket->write(data);
            if (count > 1000000){
                qDebug() << "Отаправленно 1000000 байт в П2";
                count = 0;
            }
       //     m_socket->flush();
            }
       // }
        else {
    //        qDebug()<< "qt buffer overflow";
        }
    }
}

void P2SocketHandler::loadSettings()
{
    QSettings settings;
    m_port = settings.value("p2/port", 4444).toInt();
    m_ip = settings.value("p2/ip", "127.0.0.1").toString();
}

double P2SocketHandler::getTime() const
{
    auto now = QDateTime::currentDateTime();
    double OADate2 = (now.toMSecsSinceEpoch() /86400000.0) + 25569.0;

    return OADate2;
}
