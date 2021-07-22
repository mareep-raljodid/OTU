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
    QByteArrayData data[21];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rosCLI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rosCLI_t qt_meta_stringdata_rosCLI = {
    {
QT_MOC_LITERAL(0, 0, 6), // "rosCLI"
QT_MOC_LITERAL(1, 7, 11), // "textChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "text"
QT_MOC_LITERAL(4, 25, 9), // "cs_change"
QT_MOC_LITERAL(5, 35, 4), // "init"
QT_MOC_LITERAL(6, 40, 12), // "startSensors"
QT_MOC_LITERAL(7, 53, 3), // "txt"
QT_MOC_LITERAL(8, 57, 11), // "startRecord"
QT_MOC_LITERAL(9, 69, 10), // "stopRecord"
QT_MOC_LITERAL(10, 80, 19), // "pause_resume_Record"
QT_MOC_LITERAL(11, 100, 5), // "setIP"
QT_MOC_LITERAL(12, 106, 15), // "openRecordFiles"
QT_MOC_LITERAL(13, 122, 19), // "deleteLastRecording"
QT_MOC_LITERAL(14, 142, 3), // "cam"
QT_MOC_LITERAL(15, 146, 5), // "lidar"
QT_MOC_LITERAL(16, 152, 3), // "gps"
QT_MOC_LITERAL(17, 156, 6), // "cam_ip"
QT_MOC_LITERAL(18, 163, 13), // "last_bag_date"
QT_MOC_LITERAL(19, 177, 9), // "curr_sens"
QT_MOC_LITERAL(20, 187, 12) // "last_bag_loc"

    },
    "rosCLI\0textChanged\0\0text\0cs_change\0"
    "init\0startSensors\0txt\0startRecord\0"
    "stopRecord\0pause_resume_Record\0setIP\0"
    "openRecordFiles\0deleteLastRecording\0"
    "cam\0lidar\0gps\0cam_ip\0last_bag_date\0"
    "curr_sens\0last_bag_loc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rosCLI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       8,   90, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   68,    2, 0x02 /* Public */,
       6,    1,   69,    2, 0x02 /* Public */,
       8,    1,   72,    2, 0x02 /* Public */,
       9,    1,   75,    2, 0x02 /* Public */,
      10,    1,   78,    2, 0x02 /* Public */,
      11,    1,   81,    2, 0x02 /* Public */,
      12,    1,   84,    2, 0x02 /* Public */,
      13,    1,   87,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495001,
      15, QMetaType::QString, 0x00495001,
      16, QMetaType::QString, 0x00495001,
      17, QMetaType::QString, 0x00495001,
      18, QMetaType::QString, 0x00495001,
      19, QMetaType::QString, 0x00495001,
      20, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       1,
       1,
       1,
       1,
       1,
       1,

       0        // eod
};

void rosCLI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rosCLI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->cs_change(); break;
        case 2: _t->init(); break;
        case 3: _t->startSensors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->startRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->stopRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->pause_resume_Record((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setIP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->openRecordFiles((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->deleteLastRecording((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (rosCLI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rosCLI::textChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (rosCLI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rosCLI::cs_change)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<rosCLI *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->get_c(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->get_l(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->get_g(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->get_cip(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->get_lbd(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->get_cs(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->get_lbl(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<rosCLI *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void rosCLI::textChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rosCLI::cs_change()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
