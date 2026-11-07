/****************************************************************************
** Meta object code from reading C++ file 'Scanner.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/Scanner.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7ScannerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN7ScannerE = QtMocHelpers::stringData(
    "Scanner",
    "busyChanged",
    "",
    "statusChanged",
    "scanFinished",
    "filesFound",
    "candidatesChanged",
    "externalDevicesChanged",
    "romSearchChanged",
    "deviceConnected",
    "path",
    "label",
    "deviceDisconnected",
    "removeCandidate",
    "index",
    "scanCommonLocations",
    "scanDirectory",
    "scanRomsDirectory",
    "scanExternalLaunchers",
    "scanSteamLibraries",
    "refreshExternalDevices",
    "busy",
    "status",
    "candidates",
    "QVariantList",
    "externalDevices",
    "romSearch"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN7ScannerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       5,  133, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    6 /* Public */,
       3,    0,  105,    2, 0x06,    7 /* Public */,
       4,    1,  106,    2, 0x06,    8 /* Public */,
       6,    0,  109,    2, 0x06,   10 /* Public */,
       7,    0,  110,    2, 0x06,   11 /* Public */,
       8,    0,  111,    2, 0x06,   12 /* Public */,
       9,    2,  112,    2, 0x06,   13 /* Public */,
      12,    1,  117,    2, 0x06,   16 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,  120,    2, 0x02,   18 /* Public */,
      15,    0,  123,    2, 0x02,   20 /* Public */,
      16,    1,  124,    2, 0x02,   21 /* Public */,
      17,    1,  127,    2, 0x02,   23 /* Public */,
      18,    0,  130,    2, 0x02,   25 /* Public */,
      19,    0,  131,    2, 0x02,   26 /* Public */,
      20,    0,  132,    2, 0x02,   27 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::QString,   10,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      21, QMetaType::Bool, 0x00015001, uint(0), 0,
      22, QMetaType::QString, 0x00015001, uint(1), 0,
      23, 0x80000000 | 24, 0x00015009, uint(3), 0,
      25, 0x80000000 | 24, 0x00015009, uint(4), 0,
      26, QMetaType::Bool, 0x00015001, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Scanner::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN7ScannerE.offsetsAndSizes,
    qt_meta_data_ZN7ScannerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN7ScannerE_t,
        // property 'busy'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'status'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'candidates'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'externalDevices'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'romSearch'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Scanner, std::true_type>,
        // method 'busyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'statusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scanFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'candidatesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'externalDevicesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'romSearchChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deviceConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'deviceDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'removeCandidate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'scanCommonLocations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scanDirectory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'scanRomsDirectory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'scanExternalLaunchers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scanSteamLibraries'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshExternalDevices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Scanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Scanner *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->busyChanged(); break;
        case 1: _t->statusChanged(); break;
        case 2: _t->scanFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->candidatesChanged(); break;
        case 4: _t->externalDevicesChanged(); break;
        case 5: _t->romSearchChanged(); break;
        case 6: _t->deviceConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->deviceDisconnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->removeCandidate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->scanCommonLocations(); break;
        case 10: _t->scanDirectory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->scanRomsDirectory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->scanExternalLaunchers(); break;
        case 13: _t->scanSteamLibraries(); break;
        case 14: _t->refreshExternalDevices(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Scanner::*)();
            if (_q_method_type _q_method = &Scanner::busyChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Scanner::*)();
            if (_q_method_type _q_method = &Scanner::statusChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Scanner::*)(int );
            if (_q_method_type _q_method = &Scanner::scanFinished; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Scanner::*)();
            if (_q_method_type _q_method = &Scanner::candidatesChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (Scanner::*)();
            if (_q_method_type _q_method = &Scanner::externalDevicesChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (Scanner::*)();
            if (_q_method_type _q_method = &Scanner::romSearchChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (Scanner::*)(const QString & , const QString & );
            if (_q_method_type _q_method = &Scanner::deviceConnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (Scanner::*)(const QString & );
            if (_q_method_type _q_method = &Scanner::deviceDisconnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->busy(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->status(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->candidates(); break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = _t->externalDevices(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->romSearch(); break;
        default: break;
        }
    }
}

const QMetaObject *Scanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scanner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN7ScannerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Scanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Scanner::busyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Scanner::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Scanner::scanFinished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Scanner::candidatesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Scanner::externalDevicesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Scanner::romSearchChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Scanner::deviceConnected(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Scanner::deviceDisconnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
