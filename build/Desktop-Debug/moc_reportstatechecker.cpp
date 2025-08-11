/****************************************************************************
** Meta object code from reading C++ file 'reportstatechecker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../reportstatechecker.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reportstatechecker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ReportStateChecker_t {
    uint offsetsAndSizes[28];
    char stringdata0[19];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[30];
    char stringdata4[15];
    char stringdata5[25];
    char stringdata6[19];
    char stringdata7[29];
    char stringdata8[8];
    char stringdata9[10];
    char stringdata10[17];
    char stringdata11[17];
    char stringdata12[16];
    char stringdata13[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ReportStateChecker_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ReportStateChecker_t qt_meta_stringdata_ReportStateChecker = {
    {
        QT_MOC_LITERAL(0, 18),  // "ReportStateChecker"
        QT_MOC_LITERAL(19, 18),  // "reciveStateCreated"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 29),  // "std::shared_ptr<RecieveState>"
        QT_MOC_LITERAL(69, 14),  // "acStateCreated"
        QT_MOC_LITERAL(84, 24),  // "std::shared_ptr<AcState>"
        QT_MOC_LITERAL(109, 18),  // "sessionInfoCreated"
        QT_MOC_LITERAL(128, 28),  // "std::shared_ptr<SessionInfo>"
        QT_MOC_LITERAL(157, 7),  // "onTimer"
        QT_MOC_LITERAL(165, 9),  // "onRequest"
        QT_MOC_LITERAL(175, 16),  // "onAcStateRequest"
        QT_MOC_LITERAL(192, 16),  // "onStartingServer"
        QT_MOC_LITERAL(209, 15),  // "create_ac_state"
        QT_MOC_LITERAL(225, 19)   // "create_session_info"
    },
    "ReportStateChecker",
    "reciveStateCreated",
    "",
    "std::shared_ptr<RecieveState>",
    "acStateCreated",
    "std::shared_ptr<AcState>",
    "sessionInfoCreated",
    "std::shared_ptr<SessionInfo>",
    "onTimer",
    "onRequest",
    "onAcStateRequest",
    "onStartingServer",
    "create_ac_state",
    "create_session_info"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ReportStateChecker[] = {

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
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    1,   71,    2, 0x06,    3 /* Public */,
       6,    1,   74,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   77,    2, 0x0a,    7 /* Public */,
       9,    1,   78,    2, 0x0a,    8 /* Public */,
      10,    1,   81,    2, 0x0a,   10 /* Public */,
      11,    0,   84,    2, 0x0a,   12 /* Public */,
      12,    0,   85,    2, 0x0a,   13 /* Public */,
      13,    0,   86,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ReportStateChecker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ReportStateChecker.offsetsAndSizes,
    qt_meta_data_ReportStateChecker,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ReportStateChecker_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ReportStateChecker, std::true_type>,
        // method 'reciveStateCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<RecieveState>, std::false_type>,
        // method 'acStateCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<AcState>, std::false_type>,
        // method 'sessionInfoCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<SessionInfo>, std::false_type>,
        // method 'onTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<long long, std::false_type>,
        // method 'onAcStateRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<long long, std::false_type>,
        // method 'onStartingServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_ac_state'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_session_info'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ReportStateChecker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReportStateChecker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reciveStateCreated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<RecieveState>>>(_a[1]))); break;
        case 1: _t->acStateCreated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<AcState>>>(_a[1]))); break;
        case 2: _t->sessionInfoCreated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<SessionInfo>>>(_a[1]))); break;
        case 3: _t->onTimer(); break;
        case 4: _t->onRequest((*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[1]))); break;
        case 5: _t->onAcStateRequest((*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[1]))); break;
        case 6: _t->onStartingServer(); break;
        case 7: _t->create_ac_state(); break;
        case 8: _t->create_session_info(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReportStateChecker::*)(std::shared_ptr<RecieveState> );
            if (_t _q_method = &ReportStateChecker::reciveStateCreated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ReportStateChecker::*)(std::shared_ptr<AcState> );
            if (_t _q_method = &ReportStateChecker::acStateCreated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ReportStateChecker::*)(std::shared_ptr<SessionInfo> );
            if (_t _q_method = &ReportStateChecker::sessionInfoCreated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ReportStateChecker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReportStateChecker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReportStateChecker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ReportStateChecker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ReportStateChecker::reciveStateCreated(std::shared_ptr<RecieveState> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ReportStateChecker::acStateCreated(std::shared_ptr<AcState> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ReportStateChecker::sessionInfoCreated(std::shared_ptr<SessionInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
