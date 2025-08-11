/****************************************************************************
** Meta object code from reading C++ file 'messageprocessor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../messageprocessor.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messageprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MessageProcessor_t {
    uint offsetsAndSizes[46];
    char stringdata0[17];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[13];
    char stringdata5[21];
    char stringdata6[6];
    char stringdata7[25];
    char stringdata8[23];
    char stringdata9[13];
    char stringdata10[7];
    char stringdata11[7];
    char stringdata12[11];
    char stringdata13[13];
    char stringdata14[11];
    char stringdata15[5];
    char stringdata16[21];
    char stringdata17[30];
    char stringdata18[22];
    char stringdata19[29];
    char stringdata20[17];
    char stringdata21[25];
    char stringdata22[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MessageProcessor_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MessageProcessor_t qt_meta_stringdata_MessageProcessor = {
    {
        QT_MOC_LITERAL(0, 16),  // "MessageProcessor"
        QT_MOC_LITERAL(17, 15),  // "message_created"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 6),  // "Header"
        QT_MOC_LITERAL(41, 12),  // "cel_recieved"
        QT_MOC_LITERAL(54, 20),  // "std::shared_ptr<Cel>"
        QT_MOC_LITERAL(75, 5),  // "m_cel"
        QT_MOC_LITERAL(81, 24),  // "timeToCreateStartMessage"
        QT_MOC_LITERAL(106, 22),  // "on_client_msg_recieved"
        QT_MOC_LITERAL(129, 12),  // "handlePacket"
        QT_MOC_LITERAL(142, 6),  // "Packet"
        QT_MOC_LITERAL(149, 6),  // "packet"
        QT_MOC_LITERAL(156, 10),  // "savePacket"
        QT_MOC_LITERAL(167, 12),  // "on_connected"
        QT_MOC_LITERAL(180, 10),  // "startTimer"
        QT_MOC_LITERAL(191, 4),  // "stop"
        QT_MOC_LITERAL(196, 20),  // "onReciveStateCreated"
        QT_MOC_LITERAL(217, 29),  // "std::shared_ptr<RecieveState>"
        QT_MOC_LITERAL(247, 21),  // "onSessionStateCreated"
        QT_MOC_LITERAL(269, 28),  // "std::shared_ptr<SessionInfo>"
        QT_MOC_LITERAL(298, 16),  // "onAcStateCreated"
        QT_MOC_LITERAL(315, 24),  // "std::shared_ptr<AcState>"
        QT_MOC_LITERAL(340, 14)   // "statusResponse"
    },
    "MessageProcessor",
    "message_created",
    "",
    "Header",
    "cel_recieved",
    "std::shared_ptr<Cel>",
    "m_cel",
    "timeToCreateStartMessage",
    "on_client_msg_recieved",
    "handlePacket",
    "Packet",
    "packet",
    "savePacket",
    "on_connected",
    "startTimer",
    "stop",
    "onReciveStateCreated",
    "std::shared_ptr<RecieveState>",
    "onSessionStateCreated",
    "std::shared_ptr<SessionInfo>",
    "onAcStateCreated",
    "std::shared_ptr<AcState>",
    "statusResponse"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MessageProcessor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   92,    2, 0x06,    1 /* Public */,
       4,    1,   97,    2, 0x06,    4 /* Public */,
       7,    0,  100,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,  101,    2, 0x0a,    7 /* Public */,
       9,    1,  106,    2, 0x0a,   10 /* Public */,
      12,    1,  109,    2, 0x0a,   12 /* Public */,
      13,    0,  112,    2, 0x0a,   14 /* Public */,
      14,    0,  113,    2, 0x0a,   15 /* Public */,
      15,    0,  114,    2, 0x0a,   16 /* Public */,
      16,    1,  115,    2, 0x08,   17 /* Private */,
      18,    1,  118,    2, 0x08,   19 /* Private */,
      20,    1,  121,    2, 0x08,   21 /* Private */,
      22,    2,  124,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::UChar,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject MessageProcessor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MessageProcessor.offsetsAndSizes,
    qt_meta_data_MessageProcessor,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MessageProcessor_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MessageProcessor, std::true_type>,
        // method 'message_created'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Header, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'cel_recieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Cel>, std::false_type>,
        // method 'timeToCreateStartMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_client_msg_recieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Header &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'handlePacket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Packet &, std::false_type>,
        // method 'savePacket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Packet &, std::false_type>,
        // method 'on_connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onReciveStateCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<RecieveState>, std::false_type>,
        // method 'onSessionStateCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<SessionInfo>, std::false_type>,
        // method 'onAcStateCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<AcState>, std::false_type>,
        // method 'statusResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<long long, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>
    >,
    nullptr
} };

void MessageProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageProcessor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->message_created((*reinterpret_cast< std::add_pointer_t<Header>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 1: _t->cel_recieved((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Cel>>>(_a[1]))); break;
        case 2: _t->timeToCreateStartMessage(); break;
        case 3: _t->on_client_msg_recieved((*reinterpret_cast< std::add_pointer_t<Header>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 4: _t->handlePacket((*reinterpret_cast< std::add_pointer_t<Packet>>(_a[1]))); break;
        case 5: _t->savePacket((*reinterpret_cast< std::add_pointer_t<Packet>>(_a[1]))); break;
        case 6: _t->on_connected(); break;
        case 7: _t->startTimer(); break;
        case 8: _t->stop(); break;
        case 9: _t->onReciveStateCreated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<RecieveState>>>(_a[1]))); break;
        case 10: _t->onSessionStateCreated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<SessionInfo>>>(_a[1]))); break;
        case 11: _t->onAcStateCreated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<AcState>>>(_a[1]))); break;
        case 12: _t->statusResponse((*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MessageProcessor::*)(Header , QByteArray );
            if (_t _q_method = &MessageProcessor::message_created; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MessageProcessor::*)(std::shared_ptr<Cel> );
            if (_t _q_method = &MessageProcessor::cel_recieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MessageProcessor::*)();
            if (_t _q_method = &MessageProcessor::timeToCreateStartMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *MessageProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageProcessor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MessageProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MessageProcessor::message_created(Header _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageProcessor::cel_recieved(std::shared_ptr<Cel> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MessageProcessor::timeToCreateStartMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
