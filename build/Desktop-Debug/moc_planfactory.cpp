/****************************************************************************
** Meta object code from reading C++ file 'planfactory.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../planfactory.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planfactory.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_PlanFactory_t {
    uint offsetsAndSizes[32];
    char stringdata0[12];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[12];
    char stringdata5[14];
    char stringdata6[19];
    char stringdata7[7];
    char stringdata8[15];
    char stringdata9[21];
    char stringdata10[24];
    char stringdata11[11];
    char stringdata12[4];
    char stringdata13[11];
    char stringdata14[6];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PlanFactory_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PlanFactory_t qt_meta_stringdata_PlanFactory = {
    {
        QT_MOC_LITERAL(0, 11),  // "PlanFactory"
        QT_MOC_LITERAL(12, 14),  // "messageHandled"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 14),  // "stopDataChanel"
        QT_MOC_LITERAL(43, 11),  // "stopSegment"
        QT_MOC_LITERAL(55, 13),  // "chanel_number"
        QT_MOC_LITERAL(69, 18),  // "real_chanel_number"
        QT_MOC_LITERAL(88, 6),  // "sector"
        QT_MOC_LITERAL(95, 14),  // "onPlanRecieved"
        QT_MOC_LITERAL(110, 20),  // "std::shared_ptr<Cel>"
        QT_MOC_LITERAL(131, 23),  // "onP2SocketStateChanging"
        QT_MOC_LITERAL(155, 10),  // "createPlan"
        QT_MOC_LITERAL(166, 3),  // "cel"
        QT_MOC_LITERAL(170, 10),  // "clearPlans"
        QT_MOC_LITERAL(181, 5),  // "start"
        QT_MOC_LITERAL(187, 4)   // "stop"
    },
    "PlanFactory",
    "messageHandled",
    "",
    "stopDataChanel",
    "stopSegment",
    "chanel_number",
    "real_chanel_number",
    "sector",
    "onPlanRecieved",
    "std::shared_ptr<Cel>",
    "onP2SocketStateChanging",
    "createPlan",
    "cel",
    "clearPlans",
    "start",
    "stop"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PlanFactory[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       3,    1,   73,    2, 0x06,    4 /* Public */,
       4,    3,   76,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   83,    2, 0x0a,   10 /* Public */,
      10,    1,   88,    2, 0x0a,   13 /* Public */,
      11,    1,   91,    2, 0x0a,   15 /* Public */,
      13,    0,   94,    2, 0x0a,   17 /* Public */,
      14,    0,   95,    2, 0x0a,   18 /* Public */,
      15,    0,   96,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::UChar,    2,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,    5,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, 0x80000000 | 9,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlanFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PlanFactory.offsetsAndSizes,
    qt_meta_data_PlanFactory,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PlanFactory_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlanFactory, std::true_type>,
        // method 'messageHandled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<long long, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'stopDataChanel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'stopSegment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'onPlanRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Cel>, std::false_type>,
        QtPrivate::TypeAndForceComplete<long long, std::false_type>,
        // method 'onP2SocketStateChanging'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'createPlan'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Cel>, std::false_type>,
        // method 'clearPlans'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlanFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlanFactory *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->messageHandled((*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[2]))); break;
        case 1: _t->stopDataChanel((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 2: _t->stopSegment((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[3]))); break;
        case 3: _t->onPlanRecieved((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Cel>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[2]))); break;
        case 4: _t->onP2SocketStateChanging((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: { int _r = _t->createPlan((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Cel>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->clearPlans(); break;
        case 7: _t->start(); break;
        case 8: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlanFactory::*)(long long , quint8 );
            if (_t _q_method = &PlanFactory::messageHandled; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlanFactory::*)(quint8 );
            if (_t _q_method = &PlanFactory::stopDataChanel; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlanFactory::*)(quint8 , quint8 , quint8 );
            if (_t _q_method = &PlanFactory::stopSegment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *PlanFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlanFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlanFactory.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlanFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void PlanFactory::messageHandled(long long _t1, quint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlanFactory::stopDataChanel(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlanFactory::stopSegment(quint8 _t1, quint8 _t2, quint8 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
