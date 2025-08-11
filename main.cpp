#include "mainwindow.h"
#include "logger.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("NII_RTS");
    a.setOrganizationDomain("MyDomain");
    a.setApplicationName("AC");

    Logger* logger = new Logger;
    logger->installMsgHandler();

    MainWindow w;
    w.show();
    return a.exec();

    delete logger;
}
