/****************************************************************************
** Meta object code from reading C++ file 'p2sockethandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../p2sockethandler.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'p2sockethandler.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_P2SocketHandler_t {
    uint offsetsAndSizes[16];
    char stringdata0[16];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[24];
    char stringdata5[9];
    char stringdata6[6];
    char stringdata7[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_P2SocketHandler_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_P2SocketHandler_t qt_meta_stringdata_P2SocketHandler = {
    {
        QT_MOC_LITERAL(0, 15),  // "P2SocketHandler"
        QT_MOC_LITERAL(16, 12),  // "p2StateChnge"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 4),  // "Send"
        QT_MOC_LITERAL(35, 23),  // "std::shared_ptr<Report>"
        QT_MOC_LITERAL(59, 8),  // "sendData"
        QT_MOC_LITERAL(68, 5),  // "start"
        QT_MOC_LITERAL(74, 4)   // "stop"
    },
    "P2SocketHandler",
    "p2StateChnge",
    "",
    "Send",
    "std::shared_ptr<Report>",
    "sendData",
    "start",
    "stop"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_P2SocketHandler[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   47,    2, 0x0a,    3 /* Public */,
       5,    1,   50,    2, 0x0a,    5 /* Public */,
       6,    0,   53,    2, 0x0a,    7 /* Public */,
       7,    0,   54,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject P2SocketHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_P2SocketHandler.offsetsAndSizes,
    qt_meta_data_P2SocketHandler,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_P2SocketHandler_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<P2SocketHandler, std::true_type>,
        // method 'p2StateChnge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'Send'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Report>, std::false_type>,
        // method 'sendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void P2SocketHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<P2SocketHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->p2StateChnge((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->Send((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Report>>>(_a[1]))); break;
        case 2: _t->sendData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->start(); break;
        case 4: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (P2SocketHandler::*)(bool );
            if (_t _q_method = &P2SocketHandler::p2StateChnge; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *P2SocketHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *P2SocketHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_P2SocketHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int P2SocketHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void P2SocketHandler::p2StateChnge(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
