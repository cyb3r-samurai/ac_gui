#include "TcpServer.h"
#include <QTimer>
#include <qnativeinterface.h>
#include <dataserver.h>

#define HEADER_SIZE 16

TcpServer::TcpServer(QObject* parent) :
    QObject{parent}
{
    loadSettings();
  //  saveSettings();
    server_ = new QTcpServer(this);
    started_ = server_->listen(QHostAddress::Any, 5555);
    if (!started_) {
        qWarning() << "Server could not start";
        QTimer::singleShot(500, this, &TcpServer::Timequit);
    } else {
        qInfo() <<"Server started";
    }


    connect(server_, &QTcpServer::newConnection, this, &TcpServer::on_client_connecting);

}
void TcpServer::stop() {
//    socket_->deleteLater();

    server_->deleteLater();

}

TcpServer::~TcpServer()
{
    stop();
}

bool TcpServer::isStarted() const
{
    return started_;
}

void TcpServer::Timequit()
{

}

void TcpServer::setAffinity(int cpuCore)
{

}

void TcpServer::on_client_connecting()
{
    qInfo() << "П1 connected to server";
    socket_ = server_->nextPendingConnection();
 //   socket_->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,64*1024*1024);
    connect(socket_, &QTcpSocket::readyRead, this, &TcpServer::client_data_ready);
    connect(socket_, &QTcpSocket::disconnected, this, &TcpServer::client_disconnected);
    client_connected = true;

    emit connected();
}

void TcpServer::client_disconnected()
{
    qInfo() << "Client Disconected";
    client_connected = false;
}

void TcpServer::client_data_ready()
{
    if(!header_readed) {
        if(socket_->bytesAvailable() >= HEADER_SIZE){
            header_bytes = socket_->read(HEADER_SIZE);
            header_ = DeserializeHeader(header_bytes);
            data_size = header_.n;
            qDebug() << header_.n;
            header_readed = true;
        }
    }
    if(header_readed) {
        if(data_size >0) {
            QByteArray chunk = socket_->read(qMin(data_size,socket_->bytesAvailable()));
            msg_bytes += chunk;;
            data_size -= chunk.size();
        }
        if(data_size == 0){
            emit client_msg_received(header_, msg_bytes);
            header_readed = false;
            msg_bytes.clear();
            header_bytes.clear();
        }
    }
}

void TcpServer::on_message_ready(const Header& header, const QByteArray& data)
{
    QByteArray header_bytes = header.serializeStruct();
    QByteArray packet;
    packet.append(header_bytes);
    packet.append(data);
   // socket_->write(header_bytes);
    socket_->write(packet);
}

bool TcpServer::getClient_connected() const
{
    return client_connected;
}


Header TcpServer::DeserializeHeader(QByteArray &data)
{
    Header header;
    QDataStream stream(data);
    stream.setByteOrder(QDataStream::LittleEndian);

    stream >> header.version >> header.msg_type >>header.zero >> header.time >> header.n;

    return header;
}

void TcpServer::loadSettings()
{
    QSettings settings;
    qDebug()<<"Путь к конфигурационному файлу:"<< settings.fileName();
    m_preferences.port = settings.value("port", 5555).toInt();
}

void TcpServer::saveSettings()
{
    QSettings settings;
    settings.setValue("port", 5555);
    settings.setValue("p2/port", 4444);
    settings.setValue("p2/ip", "192.168.220.88");

}

