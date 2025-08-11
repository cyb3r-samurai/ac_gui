/****************************************************************************
** Meta object code from reading C++ file 'dataserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../dataserver.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataserver.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_DataServer_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[12];
    char stringdata5[7];
    char stringdata6[17];
    char stringdata7[15];
    char stringdata8[12];
    char stringdata9[16];
    char stringdata10[19];
    char stringdata11[19];
    char stringdata12[7];
    char stringdata13[14];
    char stringdata14[19];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DataServer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DataServer_t qt_meta_stringdata_DataServer = {
    {
        QT_MOC_LITERAL(0, 10),  // "DataServer"
        QT_MOC_LITERAL(11, 12),  // "readyReadTcp"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 12),  // "readyReadUdp"
        QT_MOC_LITERAL(38, 11),  // "onAcceptCel"
        QT_MOC_LITERAL(50, 6),  // "onStop"
        QT_MOC_LITERAL(57, 16),  // "onStopDataChanel"
        QT_MOC_LITERAL(74, 14),  // "connect_server"
        QT_MOC_LITERAL(89, 11),  // "onTotalStop"
        QT_MOC_LITERAL(101, 15),  // "onFinishSegment"
        QT_MOC_LITERAL(117, 18),  // "data_chanel_number"
        QT_MOC_LITERAL(136, 18),  // "real_chanel_number"
        QT_MOC_LITERAL(155, 6),  // "sector"
        QT_MOC_LITERAL(162, 13),  // "onStopSegment"
        QT_MOC_LITERAL(176, 18),  // "real_chenel_number"
        QT_MOC_LITERAL(195, 4)   // "stop"
    },
    "DataServer",
    "readyReadTcp",
    "",
    "readyReadUdp",
    "onAcceptCel",
    "onStop",
    "onStopDataChanel",
    "connect_server",
    "onTotalStop",
    "onFinishSegment",
    "data_chanel_number",
    "real_chanel_number",
    "sector",
    "onStopSegment",
    "real_chenel_number",
    "stop"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DataServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    7,   76,    2, 0x0a,    3 /* Public */,
       5,    3,   91,    2, 0x0a,   11 /* Public */,
       6,    1,   98,    2, 0x0a,   15 /* Public */,
       7,    0,  101,    2, 0x0a,   17 /* Public */,
       8,    0,  102,    2, 0x0a,   18 /* Public */,
       9,    3,  103,    2, 0x0a,   19 /* Public */,
      13,    3,  110,    2, 0x0a,   23 /* Public */,
      15,    0,  117,    2, 0x0a,   27 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,   12,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   10,   14,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DataServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataServer.offsetsAndSizes,
    qt_meta_data_DataServer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_DataServer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DataServer, std::true_type>,
        // method 'readyReadTcp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyReadUdp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAcceptCel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onStopDataChanel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'connect_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTotalStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFinishSegment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onStopSegment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DataServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->readyReadTcp(); break;
        case 1: _t->readyReadUdp(); break;
        case 2: _t->onAcceptCel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7]))); break;
        case 3: _t->onStop((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->onStopDataChanel((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 5: _t->connect_server(); break;
        case 6: _t->onTotalStop(); break;
        case 7: _t->onFinishSegment((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->onStopSegment((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[3]))); break;
        case 9: _t->stop(); break;
        default: ;
        }
    }
}

const QMetaObject *DataServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
