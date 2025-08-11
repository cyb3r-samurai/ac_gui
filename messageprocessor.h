#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QThread>
#include <QList>

#include "ac.h"
#include "acstatehandler.h"
#include "Message.h"
#include "messagebroker.h"
#include "packet.h"
#include "planstorage.h"
#include "planfactory.h"
#include "reportstatechecker.h"
#include "messagehandler.h"
#include "celhandler.h"
#include "stophandler.h"
#include "sequentialidprovider.h"
#include "sessionrequesthandler.h"

#include <functional>

class MessageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit MessageProcessor(std::shared_ptr<PlanStorage> p_s, ReportStateChecker * r_s, AC* ac, PlanFactory* p_f, QObject *parent = nullptr);
    ~MessageProcessor();

signals:
    void message_created(Header, QByteArray);
    void cel_recieved(std::shared_ptr<Cel> m_cel);
    void timeToCreateStartMessage();

public slots:
    void on_client_msg_recieved(const Header&, const QByteArray&);
    void handlePacket(const Packet& packet);
    void savePacket(const Packet& packet);
    void on_connected();
    void startTimer();
    void stop();

private slots:
    void onReciveStateCreated(std::shared_ptr<RecieveState>);
    void onSessionStateCreated(std::shared_ptr<SessionInfo>);
    void onAcStateCreated(std::shared_ptr<AcState>);
    void statusResponse(long long, quint8);

private:
    std::shared_ptr<PlanStorage> m_planStoragePtr;
    AC* m_ac;
    PlanFactory* m_planFactory;

    QTimer* m_timer;

    bool m_connected = false;

    QVector<Packet>* m_packet_storage;
    QList<std::shared_ptr<MessageHandler>> m_msg_handlers;
    ReportStateChecker* m_state_checker;

    std::map<int, SectorPlan>* m_test_data;

    quint32 seconds_since_epoch();
    QDateTime secondsToDatetime(quint32 sec) const;
    void print_current_state() const;
    void initHandlers();
    void initResponceMessageCreation();
    void initMessageBroker();
    void initPacketStorage();
    double getTime() const;
};

#endif // MESSAGEPROCESSOR_H
