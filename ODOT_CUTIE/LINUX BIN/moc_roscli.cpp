/****************************************************************************
** Meta object code from reading C++ file 'roscli.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ODOT_UI+BE/roscli.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roscli.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rosCLI_t {
    const uint offsetsAndSize[24];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_rosCLI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_rosCLI_t qt_meta_stringdata_rosCLI = {
    {
QT_MOC_LITERAL(0, 6), // "rosCLI"
QT_MOC_LITERAL(7, 11), // "textChanged"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 4), // "text"
QT_MOC_LITERAL(25, 12), // "startSensors"
QT_MOC_LITERAL(38, 3), // "txt"
QT_MOC_LITERAL(42, 11), // "startRecord"
QT_MOC_LITERAL(54, 10), // "stopRecord"
QT_MOC_LITERAL(65, 19), // "pause_resume_Record"
QT_MOC_LITERAL(85, 12), // "setIP_CAMERA"
QT_MOC_LITERAL(98, 15), // "openRecordFiles"
QT_MOC_LITERAL(114, 19) // "deleteLastRecording"

    },
    "rosCLI\0textChanged\0\0text\0startSensors\0"
    "txt\0startRecord\0stopRecord\0"
    "pause_resume_Record\0setIP_CAMERA\0"
    "openRecordFiles\0deleteLastRecording"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rosCLI[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   65,    2, 0x02,    3 /* Public */,
       6,    1,   68,    2, 0x02,    5 /* Public */,
       7,    1,   71,    2, 0x02,    7 /* Public */,
       8,    1,   74,    2, 0x02,    9 /* Public */,
       9,    1,   77,    2, 0x02,   11 /* Public */,
      10,    1,   80,    2, 0x02,   13 /* Public */,
      11,    1,   83,    2, 0x02,   15 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00015103, uint(0), 0,

       0        // eod
};

void rosCLI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rosCLI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->startSensors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->stopRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->pause_resume_Record((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setIP_CAMERA((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->openRecordFiles((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->deleteLastRecording((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<rosCLI *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<rosCLI *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject rosCLI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_rosCLI.offsetsAndSize,
    qt_meta_data_rosCLI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_rosCLI_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>

>,
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
