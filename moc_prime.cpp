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
    QByteArrayData data[17];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_prime_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_prime_t qt_meta_stringdata_prime = {
    {
QT_MOC_LITERAL(0, 0, 5), // "prime"
QT_MOC_LITERAL(1, 6, 5), // "timer"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 10), // "primetimer"
QT_MOC_LITERAL(4, 24, 7), // "current"
QT_MOC_LITERAL(5, 32, 3), // "tab"
QT_MOC_LITERAL(6, 36, 10), // "Start_Tune"
QT_MOC_LITERAL(7, 47, 4), // "Tune"
QT_MOC_LITERAL(8, 52, 5), // "Prime"
QT_MOC_LITERAL(9, 58, 5), // "Clean"
QT_MOC_LITERAL(10, 64, 28), // "on_start_prime_but_2_clicked"
QT_MOC_LITERAL(11, 93, 28), // "on_begin_clean_but_2_clicked"
QT_MOC_LITERAL(12, 122, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(13, 146, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(14, 170, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(15, 194, 19), // "on_Tune_but_clicked"
QT_MOC_LITERAL(16, 214, 21) // "on_pushButton_clicked"

    },
    "prime\0timer\0\0primetimer\0current\0tab\0"
    "Start_Tune\0Tune\0Prime\0Clean\0"
    "on_start_prime_but_2_clicked\0"
    "on_begin_clean_but_2_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_8_clicked\0on_Tune_but_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_prime[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    1,   86,    2, 0x0a /* Public */,
       6,    0,   89,    2, 0x0a /* Public */,
       7,    0,   90,    2, 0x0a /* Public */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
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
    QMetaType::Void,

       0        // eod
};

void prime::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<prime *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timer(); break;
        case 1: _t->primetimer(); break;
        case 2: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Start_Tune(); break;
        case 4: _t->Tune(); break;
        case 5: _t->Prime(); break;
        case 6: _t->Clean(); break;
        case 7: _t->on_start_prime_but_2_clicked(); break;
        case 8: _t->on_begin_clean_but_2_clicked(); break;
        case 9: _t->on_pushButton_5_clicked(); break;
        case 10: _t->on_pushButton_6_clicked(); break;
        case 11: _t->on_pushButton_8_clicked(); break;
        case 12: _t->on_Tune_but_clicked(); break;
        case 13: _t->on_pushButton_clicked(); break;
        default: ;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
