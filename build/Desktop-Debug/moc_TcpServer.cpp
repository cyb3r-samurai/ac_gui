/****************************************************************************
** Meta object code from reading C++ file 'TcpServer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TcpServer.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpServer.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_TcpServer_t {
    uint offsetsAndSizes[30];
    char stringdata0[10];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[20];
    char stringdata5[7];
    char stringdata6[10];
    char stringdata7[7];
    char stringdata8[20];
    char stringdata9[9];
    char stringdata10[17];
    char stringdata11[5];
    char stringdata12[21];
    char stringdata13[20];
    char stringdata14[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TcpServer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TcpServer_t qt_meta_stringdata_TcpServer = {
    {
        QT_MOC_LITERAL(0, 9),  // "TcpServer"
        QT_MOC_LITERAL(10, 15),  // "ClientConnected"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 12),  // "DataRecieved"
        QT_MOC_LITERAL(40, 19),  // "client_msg_received"
        QT_MOC_LITERAL(60, 6),  // "Header"
        QT_MOC_LITERAL(67, 9),  // "connected"
        QT_MOC_LITERAL(77, 6),  // "finish"
        QT_MOC_LITERAL(84, 19),  // "connect_data_server"
        QT_MOC_LITERAL(104, 8),  // "Timequit"
        QT_MOC_LITERAL(113, 16),  // "on_message_ready"
        QT_MOC_LITERAL(130, 4),  // "stop"
        QT_MOC_LITERAL(135, 20),  // "on_client_connecting"
        QT_MOC_LITERAL(156, 19),  // "client_disconnected"
        QT_MOC_LITERAL(176, 17)   // "client_data_ready"
    },
    "TcpServer",
    "ClientConnected",
    "",
    "DataRecieved",
    "client_msg_received",
    "Header",
    "connected",
    "finish",
    "connect_data_server",
    "Timequit",
    "on_message_ready",
    "stop",
    "on_client_connecting",
    "client_disconnected",
    "client_data_ready"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TcpServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    1,   87,    2, 0x06,    2 /* Public */,
       4,    2,   90,    2, 0x06,    4 /* Public */,
       6,    0,   95,    2, 0x06,    7 /* Public */,
       7,    0,   96,    2, 0x06,    8 /* Public */,
       8,    0,   97,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   98,    2, 0x0a,   10 /* Public */,
      10,    2,   99,    2, 0x0a,   11 /* Public */,
      11,    0,  104,    2, 0x0a,   14 /* Public */,
      12,    0,  105,    2, 0x08,   15 /* Private */,
      13,    0,  106,    2, 0x08,   16 /* Private */,
      14,    0,  107,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpServer.offsetsAndSizes,
    qt_meta_data_TcpServer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpServer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TcpServer, std::true_type>,
        // method 'ClientConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DataRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'client_msg_received'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Header &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'finish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connect_data_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Timequit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_message_ready'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Header &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_client_connecting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'client_disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'client_data_ready'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClientConnected(); break;
        case 1: _t->DataRecieved((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 2: _t->client_msg_received((*reinterpret_cast< std::add_pointer_t<Header>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 3: _t->connected(); break;
        case 4: _t->finish(); break;
        case 5: _t->connect_data_server(); break;
        case 6: _t->Timequit(); break;
        case 7: _t->on_message_ready((*reinterpret_cast< std::add_pointer_t<Header>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 8: _t->stop(); break;
        case 9: _t->on_client_connecting(); break;
        case 10: _t->client_disconnected(); break;
        case 11: _t->client_data_ready(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpServer::*)();
            if (_t _q_method = &TcpServer::ClientConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QByteArray );
            if (_t _q_method = &TcpServer::DataRecieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(const Header & , const QByteArray & );
            if (_t _q_method = &TcpServer::client_msg_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)();
            if (_t _q_method = &TcpServer::connected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)();
            if (_t _q_method = &TcpServer::finish; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)();
            if (_t _q_method = &TcpServer::connect_data_server; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TcpServer::ClientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpServer::DataRecieved(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServer::client_msg_received(const Header & _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpServer::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TcpServer::finish()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TcpServer::connect_data_server()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
