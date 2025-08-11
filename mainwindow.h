#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TcpServer.h"
#include "cellstorage.h"

#include "ac.h"
#include "Message.h"
#include "messageprocessor.h"
#include "packet.h"
#include "planfactory.h"
#include "planstorage.h"
#include "reportstatechecker.h"
#include "dataserver.h"
#include "planstorage.h"

#include <memory>

#include <QMainWindow>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::MainWindow *ui;

    std::shared_ptr<PlanStorage> m_planStoragePtr;

    AC* m_ac;
    MessageProcessor *m_messageProcessor;
    ReportStateChecker* m_reportStateChecker;
    DataServer* m_dataServer;
    TcpServer* m_tcpServer;
    PlanFactory* m_planFactory;
    P2SocketHandler* m_p2SocketHandler;

    QThread* thread_tcpServer;
    QThread* thread_messageProcessor;
    QThread* thread_ac;
    QThread* thread_planFactory;
    QThread* thread_dataServer;
    QThread* thread_reportStateChecker;
    QThread* thread_p2SocketHandler;

    void startThreads();
    void initObjects();
};
#endif // MAINWINDOW_H
