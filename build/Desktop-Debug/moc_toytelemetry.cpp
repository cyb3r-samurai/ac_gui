/****************************************************************************
** Meta object code from reading C++ file 'toytelemetry.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../toytelemetry.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toytelemetry.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ToyTelemetry_t {
    uint offsetsAndSizes[26];
    char stringdata0[13];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[30];
    char stringdata4[29];
    char stringdata5[17];
    char stringdata6[19];
    char stringdata7[7];
    char stringdata8[13];
    char stringdata9[12];
    char stringdata10[5];
    char stringdata11[13];
    char stringdata12[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ToyTelemetry_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ToyTelemetry_t qt_meta_stringdata_ToyTelemetry = {
    {
        QT_MOC_LITERAL(0, 12),  // "ToyTelemetry"
        QT_MOC_LITERAL(13, 17),  // "telemetryRecieved"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 29),  // "std::vector<sector_telemetry>"
        QT_MOC_LITERAL(62, 28),  // "startingDeviceStatesRecieved"
        QT_MOC_LITERAL(91, 16),  // "std::vector<DOS>"
        QT_MOC_LITERAL(108, 18),  // "deviceStateChanged"
        QT_MOC_LITERAL(127, 6),  // "device"
        QT_MOC_LITERAL(134, 12),  // "startPolling"
        QT_MOC_LITERAL(147, 11),  // "probability"
        QT_MOC_LITERAL(159, 4),  // "stop"
        QT_MOC_LITERAL(164, 12),  // "onStateTimer"
        QT_MOC_LITERAL(177, 16)   // "onTelemetryTimer"
    },
    "ToyTelemetry",
    "telemetryRecieved",
    "",
    "std::vector<sector_telemetry>",
    "startingDeviceStatesRecieved",
    "std::vector<DOS>",
    "deviceStateChanged",
    "device",
    "startPolling",
    "probability",
    "stop",
    "onStateTimer",
    "onTelemetryTimer"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ToyTelemetry[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    1,   59,    2, 0x06,    3 /* Public */,
       6,    1,   62,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   65,    2, 0x0a,    7 /* Public */,
      10,    0,   68,    2, 0x0a,    9 /* Public */,
      11,    0,   69,    2, 0x08,   10 /* Private */,
      12,    0,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ToyTelemetry::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ToyTelemetry.offsetsAndSizes,
    qt_meta_data_ToyTelemetry,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ToyTelemetry_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ToyTelemetry, std::true_type>,
        // method 'telemetryRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<sector_telemetry> &, std::false_type>,
        // method 'startingDeviceStatesRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<DOS> &, std::false_type>,
        // method 'deviceStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const device &, std::false_type>,
        // method 'startPolling'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStateTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTelemetryTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ToyTelemetry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToyTelemetry *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->telemetryRecieved((*reinterpret_cast< std::add_pointer_t<std::vector<sector_telemetry>>>(_a[1]))); break;
        case 1: _t->startingDeviceStatesRecieved((*reinterpret_cast< std::add_pointer_t<std::vector<DOS>>>(_a[1]))); break;
        case 2: _t->deviceStateChanged((*reinterpret_cast< std::add_pointer_t<device>>(_a[1]))); break;
        case 3: _t->startPolling((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 4: _t->stop(); break;
        case 5: _t->onStateTimer(); break;
        case 6: _t->onTelemetryTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ToyTelemetry::*)(const std::vector<sector_telemetry> & );
            if (_t _q_method = &ToyTelemetry::telemetryRecieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ToyTelemetry::*)(const std::vector<DOS> & );
            if (_t _q_method = &ToyTelemetry::startingDeviceStatesRecieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ToyTelemetry::*)(const device & );
            if (_t _q_method = &ToyTelemetry::deviceStateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ToyTelemetry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToyTelemetry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToyTelemetry.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ToyTelemetry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ToyTelemetry::telemetryRecieved(const std::vector<sector_telemetry> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ToyTelemetry::startingDeviceStatesRecieved(const std::vector<DOS> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ToyTelemetry::deviceStateChanged(const device & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
