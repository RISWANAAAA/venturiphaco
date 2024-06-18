/****************************************************************************
** Meta object code from reading C++ file 'doctor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "doctor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doctor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_doctor_t {
    QByteArrayData data[20];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_doctor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_doctor_t qt_meta_stringdata_doctor = {
    {
QT_MOC_LITERAL(0, 0, 6), // "doctor"
QT_MOC_LITERAL(1, 7, 10), // "on_clicked"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "digit"
QT_MOC_LITERAL(4, 25, 15), // "on_clickedenter"
QT_MOC_LITERAL(5, 41, 12), // "PhacoSaveBut"
QT_MOC_LITERAL(6, 54, 10), // "DiaSaveBut"
QT_MOC_LITERAL(7, 65, 9), // "IASaveBut"
QT_MOC_LITERAL(8, 75, 10), // "VitSaveBut"
QT_MOC_LITERAL(9, 86, 5), // "click"
QT_MOC_LITERAL(10, 92, 3), // "tab"
QT_MOC_LITERAL(11, 96, 12), // "DiathermyBut"
QT_MOC_LITERAL(12, 109, 8), // "PhacoBut"
QT_MOC_LITERAL(13, 118, 23), // "IrrigationAspirationBut"
QT_MOC_LITERAL(14, 142, 13), // "VitrectomyBut"
QT_MOC_LITERAL(15, 156, 7), // "BackBut"
QT_MOC_LITERAL(16, 164, 10), // "Epinucleus"
QT_MOC_LITERAL(17, 175, 4), // "Quad"
QT_MOC_LITERAL(18, 180, 4), // "Chop"
QT_MOC_LITERAL(19, 185, 6) // "Sculpt"

    },
    "doctor\0on_clicked\0\0digit\0on_clickedenter\0"
    "PhacoSaveBut\0DiaSaveBut\0IASaveBut\0"
    "VitSaveBut\0click\0tab\0DiathermyBut\0"
    "PhacoBut\0IrrigationAspirationBut\0"
    "VitrectomyBut\0BackBut\0Epinucleus\0Quad\0"
    "Chop\0Sculpt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_doctor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x0a /* Public */,
       4,    0,   97,    2, 0x0a /* Public */,
       5,    0,   98,    2, 0x0a /* Public */,
       6,    0,   99,    2, 0x0a /* Public */,
       7,    0,  100,    2, 0x0a /* Public */,
       8,    0,  101,    2, 0x0a /* Public */,
       9,    1,  102,    2, 0x0a /* Public */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

       0        // eod
};

void doctor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<doctor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_clickedenter(); break;
        case 2: _t->PhacoSaveBut(); break;
        case 3: _t->DiaSaveBut(); break;
        case 4: _t->IASaveBut(); break;
        case 5: _t->VitSaveBut(); break;
        case 6: _t->click((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->DiathermyBut(); break;
        case 8: _t->PhacoBut(); break;
        case 9: _t->IrrigationAspirationBut(); break;
        case 10: _t->VitrectomyBut(); break;
        case 11: _t->BackBut(); break;
        case 12: _t->Epinucleus(); break;
        case 13: _t->Quad(); break;
        case 14: _t->Chop(); break;
        case 15: _t->Sculpt(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject doctor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_doctor.data,
    qt_meta_data_doctor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *doctor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *doctor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_doctor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int doctor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
