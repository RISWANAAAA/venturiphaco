/****************************************************************************
** Meta object code from reading C++ file 'footpedal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "footpedal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'footpedal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_footpedal_t {
    QByteArrayData data[19];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_footpedal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_footpedal_t qt_meta_stringdata_footpedal = {
    {
QT_MOC_LITERAL(0, 0, 9), // "footpedal"
QT_MOC_LITERAL(1, 10, 15), // "moveTopToBottom"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "value"
QT_MOC_LITERAL(4, 33, 15), // "moveBottomToTop"
QT_MOC_LITERAL(5, 49, 13), // "performReflux"
QT_MOC_LITERAL(6, 63, 11), // "togglePower"
QT_MOC_LITERAL(7, 75, 20), // "continous_irrigation"
QT_MOC_LITERAL(8, 96, 7), // "powerdm"
QT_MOC_LITERAL(9, 104, 6), // "value1"
QT_MOC_LITERAL(10, 111, 9), // "combobox1"
QT_MOC_LITERAL(11, 121, 4), // "text"
QT_MOC_LITERAL(12, 126, 9), // "combobox2"
QT_MOC_LITERAL(13, 136, 9), // "combobox3"
QT_MOC_LITERAL(14, 146, 9), // "combobox4"
QT_MOC_LITERAL(15, 156, 22), // "storeComboBoxSelection"
QT_MOC_LITERAL(16, 179, 5), // "index"
QT_MOC_LITERAL(17, 185, 4), // "Back"
QT_MOC_LITERAL(18, 190, 21) // "on_pushButton_clicked"

    },
    "footpedal\0moveTopToBottom\0\0value\0"
    "moveBottomToTop\0performReflux\0togglePower\0"
    "continous_irrigation\0powerdm\0value1\0"
    "combobox1\0text\0combobox2\0combobox3\0"
    "combobox4\0storeComboBoxSelection\0index\0"
    "Back\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_footpedal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       7,    1,   91,    2, 0x06 /* Public */,
       8,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   97,    2, 0x0a /* Public */,
      12,    1,  100,    2, 0x0a /* Public */,
      13,    1,  103,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      15,    1,  109,    2, 0x0a /* Public */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void footpedal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<footpedal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->moveTopToBottom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->moveBottomToTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->performReflux((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->togglePower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->continous_irrigation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->powerdm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->combobox1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->combobox2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->combobox3((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->combobox4((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->storeComboBoxSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->Back(); break;
        case 12: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (footpedal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&footpedal::moveTopToBottom)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (footpedal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&footpedal::moveBottomToTop)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (footpedal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&footpedal::performReflux)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (footpedal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&footpedal::togglePower)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (footpedal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&footpedal::continous_irrigation)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (footpedal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&footpedal::powerdm)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject footpedal::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_footpedal.data,
    qt_meta_data_footpedal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *footpedal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *footpedal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_footpedal.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int footpedal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void footpedal::moveTopToBottom(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void footpedal::moveBottomToTop(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void footpedal::performReflux(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void footpedal::togglePower(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void footpedal::continous_irrigation(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void footpedal::powerdm(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
