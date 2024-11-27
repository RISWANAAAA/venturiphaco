/****************************************************************************
** Meta object code from reading C++ file 'prime.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "prime.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prime.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_prime_t {
    QByteArrayData data[21];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_prime_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_prime_t qt_meta_stringdata_prime = {
    {
QT_MOC_LITERAL(0, 0, 5), // "prime"
QT_MOC_LITERAL(1, 6, 10), // "sendsignal"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "text"
QT_MOC_LITERAL(4, 23, 5), // "timer"
QT_MOC_LITERAL(5, 29, 10), // "primetimer"
QT_MOC_LITERAL(6, 40, 7), // "current"
QT_MOC_LITERAL(7, 48, 3), // "tab"
QT_MOC_LITERAL(8, 52, 10), // "Start_Tune"
QT_MOC_LITERAL(9, 63, 22), // "onComboBoxIndexChanged"
QT_MOC_LITERAL(10, 86, 5), // "index"
QT_MOC_LITERAL(11, 92, 20), // "setLastSelectedValue"
QT_MOC_LITERAL(12, 113, 4), // "Tune"
QT_MOC_LITERAL(13, 118, 16), // "comboboxselected"
QT_MOC_LITERAL(14, 135, 5), // "Prime"
QT_MOC_LITERAL(15, 141, 5), // "Clean"
QT_MOC_LITERAL(16, 147, 28), // "on_start_prime_but_2_clicked"
QT_MOC_LITERAL(17, 176, 28), // "on_begin_clean_but_2_clicked"
QT_MOC_LITERAL(18, 205, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(19, 229, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(20, 253, 19) // "on_Tune_but_clicked"

    },
    "prime\0sendsignal\0\0text\0timer\0primetimer\0"
    "current\0tab\0Start_Tune\0onComboBoxIndexChanged\0"
    "index\0setLastSelectedValue\0Tune\0"
    "comboboxselected\0Prime\0Clean\0"
    "on_start_prime_but_2_clicked\0"
    "on_begin_clean_but_2_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_8_clicked\0"
    "on_Tune_but_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_prime[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   97,    2, 0x0a /* Public */,
       5,    0,   98,    2, 0x0a /* Public */,
       6,    1,   99,    2, 0x0a /* Public */,
       8,    0,  102,    2, 0x0a /* Public */,
       9,    1,  103,    2, 0x0a /* Public */,
      11,    0,  106,    2, 0x0a /* Public */,
      12,    0,  107,    2, 0x0a /* Public */,
      13,    0,  108,    2, 0x0a /* Public */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void prime::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<prime *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendsignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->timer(); break;
        case 2: _t->primetimer(); break;
        case 3: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->Start_Tune(); break;
        case 5: _t->onComboBoxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setLastSelectedValue(); break;
        case 7: _t->Tune(); break;
        case 8: _t->comboboxselected(); break;
        case 9: _t->Prime(); break;
        case 10: _t->Clean(); break;
        case 11: _t->on_start_prime_but_2_clicked(); break;
        case 12: _t->on_begin_clean_but_2_clicked(); break;
        case 13: _t->on_pushButton_5_clicked(); break;
        case 14: _t->on_pushButton_8_clicked(); break;
        case 15: _t->on_Tune_but_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (prime::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&prime::sendsignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject prime::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_prime.data,
    qt_meta_data_prime,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *prime::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *prime::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_prime.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int prime::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void prime::sendsignal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
