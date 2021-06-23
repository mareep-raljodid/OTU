/****************************************************************************
** Meta object code from reading C++ file 'roscli.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ODOT_UI+BE/roscli.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roscli.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rosCLI_t {
    QByteArrayData data[11];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rosCLI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rosCLI_t qt_meta_stringdata_rosCLI = {
    {
QT_MOC_LITERAL(0, 0, 6), // "rosCLI"
QT_MOC_LITERAL(1, 7, 12), // "startSensors"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "txt"
QT_MOC_LITERAL(4, 25, 11), // "startRecord"
QT_MOC_LITERAL(5, 37, 10), // "stopRecord"
QT_MOC_LITERAL(6, 48, 11), // "pauseRecord"
QT_MOC_LITERAL(7, 60, 12), // "resumeRecord"
QT_MOC_LITERAL(8, 73, 12), // "setIP_CAMERA"
QT_MOC_LITERAL(9, 86, 15), // "openRecordFiles"
QT_MOC_LITERAL(10, 102, 19) // "deleteLastRecording"

    },
    "rosCLI\0startSensors\0\0txt\0startRecord\0"
    "stopRecord\0pauseRecord\0resumeRecord\0"
    "setIP_CAMERA\0openRecordFiles\0"
    "deleteLastRecording"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rosCLI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x02 /* Public */,
       4,    1,   57,    2, 0x02 /* Public */,
       5,    1,   60,    2, 0x02 /* Public */,
       6,    1,   63,    2, 0x02 /* Public */,
       7,    1,   66,    2, 0x02 /* Public */,
       8,    1,   69,    2, 0x02 /* Public */,
       9,    1,   72,    2, 0x02 /* Public */,
      10,    1,   75,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void rosCLI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rosCLI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startSensors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->stopRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->pauseRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->resumeRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setIP_CAMERA((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->openRecordFiles((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->deleteLastRecording((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rosCLI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_rosCLI.data,
    qt_meta_data_rosCLI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rosCLI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rosCLI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rosCLI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rosCLI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
