/****************************************************************************
** Meta object code from reading C++ file 'avsmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "avsmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'avsmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_avsmode_t {
    QByteArrayData data[67];
    char stringdata0[1038];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_avsmode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_avsmode_t qt_meta_stringdata_avsmode = {
    {
QT_MOC_LITERAL(0, 0, 7), // "avsmode"
QT_MOC_LITERAL(1, 8, 18), // "sensorValueChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "value"
QT_MOC_LITERAL(4, 34, 15), // "surgeonSelected"
QT_MOC_LITERAL(5, 50, 11), // "surgeonName"
QT_MOC_LITERAL(6, 62, 9), // "left_foot"
QT_MOC_LITERAL(7, 72, 10), // "right_foot"
QT_MOC_LITERAL(8, 83, 11), // "bottom_left"
QT_MOC_LITERAL(9, 95, 12), // "bottom_right"
QT_MOC_LITERAL(10, 108, 14), // "con_irrigation"
QT_MOC_LITERAL(11, 123, 2), // "on"
QT_MOC_LITERAL(12, 126, 11), // "sendsurgeon"
QT_MOC_LITERAL(13, 138, 10), // "on_clicked"
QT_MOC_LITERAL(14, 149, 5), // "digit"
QT_MOC_LITERAL(15, 155, 15), // "on_clickedenter"
QT_MOC_LITERAL(16, 171, 14), // "footpedalcheck"
QT_MOC_LITERAL(17, 186, 15), // "readsensorvalue"
QT_MOC_LITERAL(18, 202, 22), // "onComboBoxIndexChanged"
QT_MOC_LITERAL(19, 225, 5), // "index"
QT_MOC_LITERAL(20, 231, 16), // "receiveAvsValues"
QT_MOC_LITERAL(21, 248, 13), // "comboBoxValue"
QT_MOC_LITERAL(22, 262, 5), // "combo"
QT_MOC_LITERAL(23, 268, 3), // "dia"
QT_MOC_LITERAL(24, 272, 6), // "ia1vac"
QT_MOC_LITERAL(25, 279, 6), // "ia1asp"
QT_MOC_LITERAL(26, 286, 6), // "ia2vac"
QT_MOC_LITERAL(27, 293, 6), // "ia2asp"
QT_MOC_LITERAL(28, 300, 6), // "vitcut"
QT_MOC_LITERAL(29, 307, 6), // "vitvac"
QT_MOC_LITERAL(30, 314, 6), // "vitasp"
QT_MOC_LITERAL(31, 321, 7), // "ia1mode"
QT_MOC_LITERAL(32, 329, 7), // "ia2mode"
QT_MOC_LITERAL(33, 337, 10), // "vitvacmode"
QT_MOC_LITERAL(34, 348, 17), // "on_DIABUT_clicked"
QT_MOC_LITERAL(35, 366, 15), // "avsmodechanging"
QT_MOC_LITERAL(36, 382, 5), // "moved"
QT_MOC_LITERAL(37, 388, 4), // "gpio"
QT_MOC_LITERAL(38, 393, 25), // "movePushButtonBottomToTop"
QT_MOC_LITERAL(39, 419, 10), // "footreflux"
QT_MOC_LITERAL(40, 430, 19), // "continousirrigation"
QT_MOC_LITERAL(41, 450, 19), // "on_butdiaup_clicked"
QT_MOC_LITERAL(42, 470, 21), // "on_butdiadown_clicked"
QT_MOC_LITERAL(43, 492, 19), // "on_butia1up_clicked"
QT_MOC_LITERAL(44, 512, 21), // "on_butia1down_clicked"
QT_MOC_LITERAL(45, 534, 23), // "on_butia1flowup_clicked"
QT_MOC_LITERAL(46, 558, 25), // "on_butia1flowdown_clicked"
QT_MOC_LITERAL(47, 584, 22), // "on_butia2vacup_clicked"
QT_MOC_LITERAL(48, 607, 24), // "on_butia2vacdown_clicked"
QT_MOC_LITERAL(49, 632, 23), // "on_butia2flowup_clicked"
QT_MOC_LITERAL(50, 656, 25), // "on_butia2flowdown_clicked"
QT_MOC_LITERAL(51, 682, 19), // "on_butvitup_clicked"
QT_MOC_LITERAL(52, 702, 21), // "on_butvitdown_clicked"
QT_MOC_LITERAL(53, 724, 22), // "on_butvitvacup_clicked"
QT_MOC_LITERAL(54, 747, 24), // "on_butvitvacdown_clicked"
QT_MOC_LITERAL(55, 772, 23), // "on_butvitflowup_clicked"
QT_MOC_LITERAL(56, 796, 25), // "on_butvitflowdown_clicked"
QT_MOC_LITERAL(57, 822, 17), // "on_IA1BUT_clicked"
QT_MOC_LITERAL(58, 840, 17), // "on_IA2BUT_clicked"
QT_MOC_LITERAL(59, 858, 24), // "on_VITRECTOMYBUT_clicked"
QT_MOC_LITERAL(60, 883, 16), // "on_butCI_clicked"
QT_MOC_LITERAL(61, 900, 25), // "on_SETTINGS_BUT_2_clicked"
QT_MOC_LITERAL(62, 926, 22), // "on_butposition_clicked"
QT_MOC_LITERAL(63, 949, 21), // "on_butia1mode_clicked"
QT_MOC_LITERAL(64, 971, 21), // "on_butia2mode_clicked"
QT_MOC_LITERAL(65, 993, 21), // "on_vitvacmode_clicked"
QT_MOC_LITERAL(66, 1015, 22) // "on_butvitonoff_clicked"

    },
    "avsmode\0sensorValueChanged\0\0value\0"
    "surgeonSelected\0surgeonName\0left_foot\0"
    "right_foot\0bottom_left\0bottom_right\0"
    "con_irrigation\0on\0sendsurgeon\0on_clicked\0"
    "digit\0on_clickedenter\0footpedalcheck\0"
    "readsensorvalue\0onComboBoxIndexChanged\0"
    "index\0receiveAvsValues\0comboBoxValue\0"
    "combo\0dia\0ia1vac\0ia1asp\0ia2vac\0ia2asp\0"
    "vitcut\0vitvac\0vitasp\0ia1mode\0ia2mode\0"
    "vitvacmode\0on_DIABUT_clicked\0"
    "avsmodechanging\0moved\0gpio\0"
    "movePushButtonBottomToTop\0footreflux\0"
    "continousirrigation\0on_butdiaup_clicked\0"
    "on_butdiadown_clicked\0on_butia1up_clicked\0"
    "on_butia1down_clicked\0on_butia1flowup_clicked\0"
    "on_butia1flowdown_clicked\0"
    "on_butia2vacup_clicked\0on_butia2vacdown_clicked\0"
    "on_butia2flowup_clicked\0"
    "on_butia2flowdown_clicked\0on_butvitup_clicked\0"
    "on_butvitdown_clicked\0on_butvitvacup_clicked\0"
    "on_butvitvacdown_clicked\0"
    "on_butvitflowup_clicked\0"
    "on_butvitflowdown_clicked\0on_IA1BUT_clicked\0"
    "on_IA2BUT_clicked\0on_VITRECTOMYBUT_clicked\0"
    "on_butCI_clicked\0on_SETTINGS_BUT_2_clicked\0"
    "on_butposition_clicked\0on_butia1mode_clicked\0"
    "on_butia2mode_clicked\0on_vitvacmode_clicked\0"
    "on_butvitonoff_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_avsmode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  244,    2, 0x06 /* Public */,
       4,    1,  247,    2, 0x06 /* Public */,
       6,    1,  250,    2, 0x06 /* Public */,
       7,    1,  253,    2, 0x06 /* Public */,
       8,    1,  256,    2, 0x06 /* Public */,
       9,    1,  259,    2, 0x06 /* Public */,
      10,    1,  262,    2, 0x06 /* Public */,
      12,    1,  265,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  268,    2, 0x0a /* Public */,
      15,    0,  271,    2, 0x0a /* Public */,
      16,    0,  272,    2, 0x0a /* Public */,
      17,    0,  273,    2, 0x0a /* Public */,
      18,    1,  274,    2, 0x0a /* Public */,
      20,   13,  277,    2, 0x0a /* Public */,
      34,    0,  304,    2, 0x0a /* Public */,
      35,    1,  305,    2, 0x0a /* Public */,
      36,    1,  308,    2, 0x0a /* Public */,
      38,    1,  311,    2, 0x0a /* Public */,
      39,    1,  314,    2, 0x0a /* Public */,
      40,    1,  317,    2, 0x0a /* Public */,
      41,    0,  320,    2, 0x08 /* Private */,
      42,    0,  321,    2, 0x08 /* Private */,
      43,    0,  322,    2, 0x08 /* Private */,
      44,    0,  323,    2, 0x08 /* Private */,
      45,    0,  324,    2, 0x08 /* Private */,
      46,    0,  325,    2, 0x08 /* Private */,
      47,    0,  326,    2, 0x08 /* Private */,
      48,    0,  327,    2, 0x08 /* Private */,
      49,    0,  328,    2, 0x08 /* Private */,
      50,    0,  329,    2, 0x08 /* Private */,
      51,    0,  330,    2, 0x08 /* Private */,
      52,    0,  331,    2, 0x08 /* Private */,
      53,    0,  332,    2, 0x08 /* Private */,
      54,    0,  333,    2, 0x08 /* Private */,
      55,    0,  334,    2, 0x08 /* Private */,
      56,    0,  335,    2, 0x08 /* Private */,
      57,    0,  336,    2, 0x08 /* Private */,
      58,    0,  337,    2, 0x08 /* Private */,
      59,    0,  338,    2, 0x08 /* Private */,
      60,    0,  339,    2, 0x08 /* Private */,
      61,    0,  340,    2, 0x08 /* Private */,
      62,    0,  341,    2, 0x08 /* Private */,
      63,    0,  342,    2, 0x08 /* Private */,
      64,    0,  343,    2, 0x08 /* Private */,
      65,    0,  344,    2, 0x08 /* Private */,
      66,    0,  345,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,    3,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void avsmode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<avsmode *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sensorValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->surgeonSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->left_foot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->right_foot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->bottom_left((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->bottom_right((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->con_irrigation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->sendsurgeon((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_clickedenter(); break;
        case 10: _t->footpedalcheck(); break;
        case 11: { int _r = _t->readsensorvalue();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->onComboBoxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->receiveAvsValues((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13]))); break;
        case 14: _t->on_DIABUT_clicked(); break;
        case 15: _t->avsmodechanging((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->moved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->movePushButtonBottomToTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->footreflux((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->continousirrigation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_butdiaup_clicked(); break;
        case 21: _t->on_butdiadown_clicked(); break;
        case 22: _t->on_butia1up_clicked(); break;
        case 23: _t->on_butia1down_clicked(); break;
        case 24: _t->on_butia1flowup_clicked(); break;
        case 25: _t->on_butia1flowdown_clicked(); break;
        case 26: _t->on_butia2vacup_clicked(); break;
        case 27: _t->on_butia2vacdown_clicked(); break;
        case 28: _t->on_butia2flowup_clicked(); break;
        case 29: _t->on_butia2flowdown_clicked(); break;
        case 30: _t->on_butvitup_clicked(); break;
        case 31: _t->on_butvitdown_clicked(); break;
        case 32: _t->on_butvitvacup_clicked(); break;
        case 33: _t->on_butvitvacdown_clicked(); break;
        case 34: _t->on_butvitflowup_clicked(); break;
        case 35: _t->on_butvitflowdown_clicked(); break;
        case 36: _t->on_IA1BUT_clicked(); break;
        case 37: _t->on_IA2BUT_clicked(); break;
        case 38: _t->on_VITRECTOMYBUT_clicked(); break;
        case 39: _t->on_butCI_clicked(); break;
        case 40: _t->on_SETTINGS_BUT_2_clicked(); break;
        case 41: _t->on_butposition_clicked(); break;
        case 42: _t->on_butia1mode_clicked(); break;
        case 43: _t->on_butia2mode_clicked(); break;
        case 44: _t->on_vitvacmode_clicked(); break;
        case 45: _t->on_butvitonoff_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (avsmode::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::sensorValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (avsmode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::surgeonSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (avsmode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::left_foot)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (avsmode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::right_foot)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (avsmode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::bottom_left)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (avsmode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::bottom_right)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (avsmode::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::con_irrigation)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (avsmode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&avsmode::sendsurgeon)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject avsmode::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_avsmode.data,
    qt_meta_data_avsmode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *avsmode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *avsmode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_avsmode.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int avsmode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void avsmode::sensorValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void avsmode::surgeonSelected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void avsmode::left_foot(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void avsmode::right_foot(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void avsmode::bottom_left(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void avsmode::bottom_right(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void avsmode::con_irrigation(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void avsmode::sendsurgeon(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
