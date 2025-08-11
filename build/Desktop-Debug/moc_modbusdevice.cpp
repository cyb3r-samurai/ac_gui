/****************************************************************************
** Meta object code from reading C++ file 'modbusdevice.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../modbus/modbusdevice.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbusdevice.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ModbusReplyHandler_t {
    uint offsetsAndSizes[12];
    char stringdata0[19];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[5];
    char stringdata5[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ModbusReplyHandler_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ModbusReplyHandler_t qt_meta_stringdata_ModbusReplyHandler = {
    {
        QT_MOC_LITERAL(0, 18),  // "ModbusReplyHandler"
        QT_MOC_LITERAL(19, 8),  // "complete"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 14),  // "QList<quint16>"
        QT_MOC_LITERAL(44, 4),  // "data"
        QT_MOC_LITERAL(49, 7)   // "handler"
    },
    "ModbusReplyHandler",
    "complete",
    "",
    "QList<quint16>",
    "data",
    "handler"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ModbusReplyHandler[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   29,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ModbusReplyHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ModbusReplyHandler.offsetsAndSizes,
    qt_meta_data_ModbusReplyHandler,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ModbusReplyHandler_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ModbusReplyHandler, std::true_type>,
        // method 'complete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<quint16> &, std::false_type>,
        // method 'handler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ModbusReplyHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusReplyHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< std::add_pointer_t<QList<quint16>>>(_a[1]))); break;
        case 1: _t->handler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<quint16> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModbusReplyHandler::*)(const QVector<quint16> & );
            if (_t _q_method = &ModbusReplyHandler::complete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ModbusReplyHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusReplyHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusReplyHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusReplyHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ModbusReplyHandler::complete(const QVector<quint16> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {
struct qt_meta_stringdata_ModbusDevice_t {
    uint offsetsAndSizes[10];
    char stringdata0[13];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ModbusDevice_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ModbusDevice_t qt_meta_stringdata_ModbusDevice = {
    {
        QT_MOC_LITERAL(0, 12),  // "ModbusDevice"
        QT_MOC_LITERAL(13, 20),  // "onModbusStateChanged"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 20),  // "QModbusDevice::State"
        QT_MOC_LITERAL(56, 5)   // "state"
    },
    "ModbusDevice",
    "onModbusStateChanged",
    "",
    "QModbusDevice::State",
    "state"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ModbusDevice[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject ModbusDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ModbusDevice.offsetsAndSizes,
    qt_meta_data_ModbusDevice,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ModbusDevice_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ModbusDevice, std::true_type>,
        // method 'onModbusStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModbusDevice::State, std::false_type>
    >,
    nullptr
} };

void ModbusDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusDevice *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onModbusStateChanged((*reinterpret_cast< std::add_pointer_t<QModbusDevice::State>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ModbusDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusDevice.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "DeviceInterface"))
        return static_cast< DeviceInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
