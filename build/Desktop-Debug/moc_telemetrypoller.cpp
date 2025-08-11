/****************************************************************************
** Meta object code from reading C++ file 'telemetrypoller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../devices/devicelib/telemetrypoller.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telemetrypoller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_TelemetryPoller_t {
    uint offsetsAndSizes[22];
    char stringdata0[16];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[15];
    char stringdata5[6];
    char stringdata6[15];
    char stringdata7[17];
    char stringdata8[14];
    char stringdata9[11];
    char stringdata10[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TelemetryPoller_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TelemetryPoller_t qt_meta_stringdata_TelemetryPoller = {
    {
        QT_MOC_LITERAL(0, 15),  // "TelemetryPoller"
        QT_MOC_LITERAL(16, 17),  // "telemetryReceived"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 8),  // "deviceId"
        QT_MOC_LITERAL(44, 14),  // "TelemetryEntry"
        QT_MOC_LITERAL(59, 5),  // "entry"
        QT_MOC_LITERAL(65, 14),  // "statusReceived"
        QT_MOC_LITERAL(80, 16),  // "StatusFlagsEntry"
        QT_MOC_LITERAL(97, 13),  // "eventReceived"
        QT_MOC_LITERAL(111, 10),  // "EventEntry"
        QT_MOC_LITERAL(122, 11)   // "pollDevices"
    },
    "TelemetryPoller",
    "telemetryReceived",
    "",
    "deviceId",
    "TelemetryEntry",
    "entry",
    "statusReceived",
    "StatusFlagsEntry",
    "eventReceived",
    "EventEntry",
    "pollDevices"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TelemetryPoller[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       6,    2,   43,    2, 0x06,    4 /* Public */,
       8,    2,   48,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   53,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    3,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TelemetryPoller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TelemetryPoller.offsetsAndSizes,
    qt_meta_data_TelemetryPoller,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TelemetryPoller_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TelemetryPoller, std::true_type>,
        // method 'telemetryReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const TelemetryEntry &, std::false_type>,
        // method 'statusReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const StatusFlagsEntry &, std::false_type>,
        // method 'eventReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EventEntry &, std::false_type>,
        // method 'pollDevices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TelemetryPoller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TelemetryPoller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->telemetryReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<TelemetryEntry>>(_a[2]))); break;
        case 1: _t->statusReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<StatusFlagsEntry>>(_a[2]))); break;
        case 2: _t->eventReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<EventEntry>>(_a[2]))); break;
        case 3: _t->pollDevices(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TelemetryPoller::*)(int , const TelemetryEntry & );
            if (_t _q_method = &TelemetryPoller::telemetryReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TelemetryPoller::*)(int , const StatusFlagsEntry & );
            if (_t _q_method = &TelemetryPoller::statusReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TelemetryPoller::*)(int , const EventEntry & );
            if (_t _q_method = &TelemetryPoller::eventReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *TelemetryPoller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelemetryPoller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TelemetryPoller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TelemetryPoller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TelemetryPoller::telemetryReceived(int _t1, const TelemetryEntry & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TelemetryPoller::statusReceived(int _t1, const StatusFlagsEntry & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TelemetryPoller::eventReceived(int _t1, const EventEntry & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
