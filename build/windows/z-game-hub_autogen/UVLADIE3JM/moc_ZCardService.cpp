/****************************************************************************
** Meta object code from reading C++ file 'ZCardService.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ZCardService.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZCardService.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12ZCardServiceE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN12ZCardServiceE = QtMocHelpers::stringData(
    "ZCardService",
    "cardChanged",
    "",
    "statusChanged",
    "reportChanged",
    "busyChanged",
    "cardsChanged",
    "openCard",
    "path",
    "clearCard",
    "buildCard",
    "source",
    "output",
    "format",
    "resolveLaunchPlan",
    "QVariantMap",
    "showMessage",
    "message",
    "scanCards",
    "registerCard",
    "entries",
    "QVariantList",
    "currentPath",
    "currentFormat",
    "status",
    "report",
    "busy",
    "cards"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN12ZCardServiceE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       7,  110, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    8 /* Public */,
       3,    0,   87,    2, 0x06,    9 /* Public */,
       4,    0,   88,    2, 0x06,   10 /* Public */,
       5,    0,   89,    2, 0x06,   11 /* Public */,
       6,    0,   90,    2, 0x06,   12 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   91,    2, 0x02,   13 /* Public */,
       9,    0,   94,    2, 0x02,   15 /* Public */,
      10,    3,   95,    2, 0x02,   16 /* Public */,
      14,    0,  102,    2, 0x02,   20 /* Public */,
      16,    1,  103,    2, 0x02,   21 /* Public */,
      18,    0,  106,    2, 0x02,   23 /* Public */,
      19,    1,  107,    2, 0x02,   24 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,
    0x80000000 | 15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    8,

 // properties: name, type, flags, notifyId, revision
      20, 0x80000000 | 21, 0x00015009, uint(0), 0,
      22, QMetaType::QString, 0x00015001, uint(0), 0,
      23, QMetaType::QString, 0x00015001, uint(0), 0,
      24, QMetaType::QString, 0x00015001, uint(1), 0,
      25, QMetaType::QString, 0x00015001, uint(2), 0,
      26, QMetaType::Bool, 0x00015001, uint(3), 0,
      27, 0x80000000 | 21, 0x00015009, uint(4), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZCardService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN12ZCardServiceE.offsetsAndSizes,
    qt_meta_data_ZN12ZCardServiceE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN12ZCardServiceE_t,
        // property 'entries'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'currentPath'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentFormat'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'status'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'report'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'busy'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'cards'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZCardService, std::true_type>,
        // method 'cardChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'statusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reportChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'busyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cardsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openCard'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'clearCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buildCard'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'resolveLaunchPlan'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>,
        // method 'showMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'scanCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registerCard'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void ZCardService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ZCardService *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cardChanged(); break;
        case 1: _t->statusChanged(); break;
        case 2: _t->reportChanged(); break;
        case 3: _t->busyChanged(); break;
        case 4: _t->cardsChanged(); break;
        case 5: { bool _r = _t->openCard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->clearCard(); break;
        case 7: { bool _r = _t->buildCard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { QVariantMap _r = _t->resolveLaunchPlan();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->showMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->scanCards(); break;
        case 11: { bool _r = _t->registerCard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (ZCardService::*)();
            if (_q_method_type _q_method = &ZCardService::cardChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (ZCardService::*)();
            if (_q_method_type _q_method = &ZCardService::statusChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (ZCardService::*)();
            if (_q_method_type _q_method = &ZCardService::reportChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (ZCardService::*)();
            if (_q_method_type _q_method = &ZCardService::busyChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (ZCardService::*)();
            if (_q_method_type _q_method = &ZCardService::cardsChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->entries(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentPath(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->currentFormat(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->status(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->report(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->busy(); break;
        case 6: *reinterpret_cast< QVariantList*>(_v) = _t->cards(); break;
        default: break;
        }
    }
}

const QMetaObject *ZCardService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZCardService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN12ZCardServiceE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ZCardService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ZCardService::cardChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ZCardService::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ZCardService::reportChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ZCardService::busyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ZCardService::cardsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
