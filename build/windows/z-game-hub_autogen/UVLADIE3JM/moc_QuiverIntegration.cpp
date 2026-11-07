/****************************************************************************
** Meta object code from reading C++ file 'QuiverIntegration.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/QuiverIntegration.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QuiverIntegration.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QuiverIntegrationE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN17QuiverIntegrationE = QtMocHelpers::stringData(
    "QuiverIntegration",
    "appsChanged",
    "",
    "catalogStatusChanged",
    "catalogBusyChanged",
    "operationStatusChanged",
    "operationBusyChanged",
    "releaseAssetsChanged",
    "pendingAppChanged",
    "installedExecutablesChanged",
    "errorOccurred",
    "message",
    "appInstalled",
    "title",
    "QVariantList",
    "executables",
    "iconUrl",
    "refreshCatalog",
    "openOrPrepareApp",
    "QVariantMap",
    "app",
    "installSelectedRelease",
    "asset",
    "launchInstalledApp",
    "executablePath",
    "appsDirectory",
    "apps",
    "catalogStatus",
    "catalogBusy",
    "operationStatus",
    "operationBusy",
    "releaseAssets",
    "pendingApp",
    "installedExecutables"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN17QuiverIntegrationE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       8,  133, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    9 /* Public */,
       3,    0,  105,    2, 0x06,   10 /* Public */,
       4,    0,  106,    2, 0x06,   11 /* Public */,
       5,    0,  107,    2, 0x06,   12 /* Public */,
       6,    0,  108,    2, 0x06,   13 /* Public */,
       7,    0,  109,    2, 0x06,   14 /* Public */,
       8,    0,  110,    2, 0x06,   15 /* Public */,
       9,    0,  111,    2, 0x06,   16 /* Public */,
      10,    1,  112,    2, 0x06,   17 /* Public */,
      12,    3,  115,    2, 0x06,   19 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  122,    2, 0x02,   23 /* Public */,
      18,    1,  123,    2, 0x02,   24 /* Public */,
      21,    1,  126,    2, 0x02,   26 /* Public */,
      23,    1,  129,    2, 0x02,   28 /* Public */,
      25,    0,  132,    2, 0x102,   30 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 14, QMetaType::QString,   13,   15,   16,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   22,
    QMetaType::Bool, QMetaType::QString,   24,
    QMetaType::QString,

 // properties: name, type, flags, notifyId, revision
      26, 0x80000000 | 14, 0x00015009, uint(0), 0,
      27, QMetaType::QString, 0x00015001, uint(1), 0,
      28, QMetaType::Bool, 0x00015001, uint(2), 0,
      29, QMetaType::QString, 0x00015001, uint(3), 0,
      30, QMetaType::Bool, 0x00015001, uint(4), 0,
      31, 0x80000000 | 14, 0x00015009, uint(5), 0,
      32, 0x80000000 | 19, 0x00015009, uint(6), 0,
      33, 0x80000000 | 14, 0x00015009, uint(7), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QuiverIntegration::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN17QuiverIntegrationE.offsetsAndSizes,
    qt_meta_data_ZN17QuiverIntegrationE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN17QuiverIntegrationE_t,
        // property 'apps'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'catalogStatus'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'catalogBusy'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'operationStatus'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'operationBusy'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'releaseAssets'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'pendingApp'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::true_type>,
        // property 'installedExecutables'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QuiverIntegration, std::true_type>,
        // method 'appsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'catalogStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'catalogBusyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'operationStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'operationBusyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'releaseAssetsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pendingAppChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'installedExecutablesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'appInstalled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'refreshCatalog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openOrPrepareApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'installSelectedRelease'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'launchInstalledApp'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'appsDirectory'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void QuiverIntegration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QuiverIntegration *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->appsChanged(); break;
        case 1: _t->catalogStatusChanged(); break;
        case 2: _t->catalogBusyChanged(); break;
        case 3: _t->operationStatusChanged(); break;
        case 4: _t->operationBusyChanged(); break;
        case 5: _t->releaseAssetsChanged(); break;
        case 6: _t->pendingAppChanged(); break;
        case 7: _t->installedExecutablesChanged(); break;
        case 8: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->appInstalled((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 10: _t->refreshCatalog(); break;
        case 11: _t->openOrPrepareApp((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 12: _t->installSelectedRelease((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 13: { bool _r = _t->launchInstalledApp((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->appsDirectory();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::appsChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::catalogStatusChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::catalogBusyChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::operationStatusChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::operationBusyChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::releaseAssetsChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::pendingAppChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)();
            if (_q_method_type _q_method = &QuiverIntegration::installedExecutablesChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)(const QString & );
            if (_q_method_type _q_method = &QuiverIntegration::errorOccurred; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (QuiverIntegration::*)(const QString & , const QVariantList & , const QString & );
            if (_q_method_type _q_method = &QuiverIntegration::appInstalled; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->apps(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->catalogStatus(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->catalogBusy(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->operationStatus(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->operationBusy(); break;
        case 5: *reinterpret_cast< QVariantList*>(_v) = _t->releaseAssets(); break;
        case 6: *reinterpret_cast< QVariantMap*>(_v) = _t->pendingApp(); break;
        case 7: *reinterpret_cast< QVariantList*>(_v) = _t->installedExecutables(); break;
        default: break;
        }
    }
}

const QMetaObject *QuiverIntegration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuiverIntegration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN17QuiverIntegrationE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuiverIntegration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QuiverIntegration::appsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QuiverIntegration::catalogStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QuiverIntegration::catalogBusyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QuiverIntegration::operationStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QuiverIntegration::operationBusyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QuiverIntegration::releaseAssetsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QuiverIntegration::pendingAppChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QuiverIntegration::installedExecutablesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QuiverIntegration::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QuiverIntegration::appInstalled(const QString & _t1, const QVariantList & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
