/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[106];
    char stringdata0[1481];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "sensorValueChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "value"
QT_MOC_LITERAL(4, 37, 11), // "userMessage"
QT_MOC_LITERAL(5, 49, 8), // "minValue"
QT_MOC_LITERAL(6, 58, 8), // "maxValue"
QT_MOC_LITERAL(7, 67, 14), // "updateLineedit"
QT_MOC_LITERAL(8, 82, 10), // "QLineEdit*"
QT_MOC_LITERAL(9, 93, 8), // "lineEdit"
QT_MOC_LITERAL(10, 102, 9), // "prevValue"
QT_MOC_LITERAL(11, 112, 10), // "on_clicked"
QT_MOC_LITERAL(12, 123, 5), // "digit"
QT_MOC_LITERAL(13, 129, 15), // "on_clickedenter"
QT_MOC_LITERAL(14, 145, 17), // "changeButtonColor"
QT_MOC_LITERAL(15, 163, 8), // "tabIndex"
QT_MOC_LITERAL(16, 172, 7), // "current"
QT_MOC_LITERAL(17, 180, 3), // "tab"
QT_MOC_LITERAL(18, 184, 10), // "updateline"
QT_MOC_LITERAL(19, 195, 5), // "index"
QT_MOC_LITERAL(20, 201, 9), // "tabupdate"
QT_MOC_LITERAL(21, 211, 10), // "startphaco"
QT_MOC_LITERAL(22, 222, 17), // "updateElapsedTime"
QT_MOC_LITERAL(23, 240, 14), // "ULTRASONICBUT1"
QT_MOC_LITERAL(24, 255, 14), // "ULTRASONICBUT2"
QT_MOC_LITERAL(25, 270, 14), // "ULTRASONICBUT4"
QT_MOC_LITERAL(26, 285, 14), // "IRRIGATIONBUT1"
QT_MOC_LITERAL(27, 300, 14), // "IRRIGATIONBUT2"
QT_MOC_LITERAL(28, 315, 13), // "VITRECTOMYBUT"
QT_MOC_LITERAL(29, 329, 12), // "DIATHERMYBUT"
QT_MOC_LITERAL(30, 342, 8), // "diapowup"
QT_MOC_LITERAL(31, 351, 10), // "diapowdown"
QT_MOC_LITERAL(32, 362, 8), // "vitcutup"
QT_MOC_LITERAL(33, 371, 10), // "vitcutdown"
QT_MOC_LITERAL(34, 382, 8), // "vitvacup"
QT_MOC_LITERAL(35, 391, 10), // "vitvacdown"
QT_MOC_LITERAL(36, 402, 9), // "vitflowup"
QT_MOC_LITERAL(37, 412, 11), // "vitflowdown"
QT_MOC_LITERAL(38, 424, 8), // "ia2vacup"
QT_MOC_LITERAL(39, 433, 10), // "ia2vacdown"
QT_MOC_LITERAL(40, 444, 9), // "ia2flowup"
QT_MOC_LITERAL(41, 454, 11), // "ia2flowdown"
QT_MOC_LITERAL(42, 466, 8), // "ia1vacup"
QT_MOC_LITERAL(43, 475, 10), // "ia1vacdown"
QT_MOC_LITERAL(44, 486, 9), // "ia1flowup"
QT_MOC_LITERAL(45, 496, 11), // "ia1flowdown"
QT_MOC_LITERAL(46, 508, 8), // "US1POWUP"
QT_MOC_LITERAL(47, 517, 10), // "US1POWDOWN"
QT_MOC_LITERAL(48, 528, 10), // "US1VACDOWN"
QT_MOC_LITERAL(49, 539, 8), // "US1VACUP"
QT_MOC_LITERAL(50, 548, 11), // "US1FLOWDOWN"
QT_MOC_LITERAL(51, 560, 9), // "US1FLOWUP"
QT_MOC_LITERAL(52, 570, 8), // "us2powup"
QT_MOC_LITERAL(53, 579, 10), // "us2powdown"
QT_MOC_LITERAL(54, 590, 8), // "us2vacup"
QT_MOC_LITERAL(55, 599, 10), // "us2vacdown"
QT_MOC_LITERAL(56, 610, 9), // "us2flowup"
QT_MOC_LITERAL(57, 620, 11), // "us2flowdown"
QT_MOC_LITERAL(58, 632, 14), // "ULTRASONICBUT3"
QT_MOC_LITERAL(59, 647, 8), // "us3powup"
QT_MOC_LITERAL(60, 656, 10), // "us3powdown"
QT_MOC_LITERAL(61, 667, 8), // "us3vacup"
QT_MOC_LITERAL(62, 676, 10), // "us3vacdown"
QT_MOC_LITERAL(63, 687, 9), // "us3flowup"
QT_MOC_LITERAL(64, 697, 11), // "us3flowdown"
QT_MOC_LITERAL(65, 709, 8), // "us4powup"
QT_MOC_LITERAL(66, 718, 10), // "us4powdown"
QT_MOC_LITERAL(67, 729, 8), // "us4vacup"
QT_MOC_LITERAL(68, 738, 10), // "us4vacdown"
QT_MOC_LITERAL(69, 749, 9), // "us4flowup"
QT_MOC_LITERAL(70, 759, 11), // "us4flowdown"
QT_MOC_LITERAL(71, 771, 11), // "SETTINGSBUT"
QT_MOC_LITERAL(72, 783, 7), // "BACKBUT"
QT_MOC_LITERAL(73, 791, 17), // "on_DIABUT_clicked"
QT_MOC_LITERAL(74, 809, 20), // "us1_linear_nonlinear"
QT_MOC_LITERAL(75, 830, 20), // "us2_linear_nonlinear"
QT_MOC_LITERAL(76, 851, 20), // "us3_linear_nonlinear"
QT_MOC_LITERAL(77, 872, 20), // "us4_linear_nonlinear"
QT_MOC_LITERAL(78, 893, 20), // "ia1_linear_nonlinear"
QT_MOC_LITERAL(79, 914, 20), // "ia2_linear_nonlinear"
QT_MOC_LITERAL(80, 935, 20), // "vit_linear_nonlinear"
QT_MOC_LITERAL(81, 956, 10), // "on_off_vit"
QT_MOC_LITERAL(82, 967, 10), // "on_off_us2"
QT_MOC_LITERAL(83, 978, 10), // "on_off_us3"
QT_MOC_LITERAL(84, 989, 10), // "on_off_us4"
QT_MOC_LITERAL(85, 1000, 9), // "HANDPIECE"
QT_MOC_LITERAL(86, 1010, 12), // "updatesensor"
QT_MOC_LITERAL(87, 1023, 21), // "continous_irrigation1"
QT_MOC_LITERAL(88, 1045, 21), // "continous_irrigation2"
QT_MOC_LITERAL(89, 1067, 21), // "continous_irrigation3"
QT_MOC_LITERAL(90, 1089, 21), // "continous_irrigation4"
QT_MOC_LITERAL(91, 1111, 21), // "continous_irrigation5"
QT_MOC_LITERAL(92, 1133, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(93, 1157, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(94, 1181, 24), // "on_pushButton_44_clicked"
QT_MOC_LITERAL(95, 1206, 24), // "on_pushButton_45_clicked"
QT_MOC_LITERAL(96, 1231, 24), // "on_pushButton_46_clicked"
QT_MOC_LITERAL(97, 1256, 24), // "on_pushButton_47_clicked"
QT_MOC_LITERAL(98, 1281, 24), // "on_pushButton_49_clicked"
QT_MOC_LITERAL(99, 1306, 24), // "on_pushButton_48_clicked"
QT_MOC_LITERAL(100, 1331, 24), // "on_pushButton_50_clicked"
QT_MOC_LITERAL(101, 1356, 24), // "on_pushButton_51_clicked"
QT_MOC_LITERAL(102, 1381, 24), // "on_pushButton_52_clicked"
QT_MOC_LITERAL(103, 1406, 24), // "on_pushButton_53_clicked"
QT_MOC_LITERAL(104, 1431, 24), // "on_pushButton_54_clicked"
QT_MOC_LITERAL(105, 1456, 24) // "on_pushButton_55_clicked"

    },
    "MainWindow\0sensorValueChanged\0\0value\0"
    "userMessage\0minValue\0maxValue\0"
    "updateLineedit\0QLineEdit*\0lineEdit\0"
    "prevValue\0on_clicked\0digit\0on_clickedenter\0"
    "changeButtonColor\0tabIndex\0current\0"
    "tab\0updateline\0index\0tabupdate\0"
    "startphaco\0updateElapsedTime\0"
    "ULTRASONICBUT1\0ULTRASONICBUT2\0"
    "ULTRASONICBUT4\0IRRIGATIONBUT1\0"
    "IRRIGATIONBUT2\0VITRECTOMYBUT\0DIATHERMYBUT\0"
    "diapowup\0diapowdown\0vitcutup\0vitcutdown\0"
    "vitvacup\0vitvacdown\0vitflowup\0vitflowdown\0"
    "ia2vacup\0ia2vacdown\0ia2flowup\0ia2flowdown\0"
    "ia1vacup\0ia1vacdown\0ia1flowup\0ia1flowdown\0"
    "US1POWUP\0US1POWDOWN\0US1VACDOWN\0US1VACUP\0"
    "US1FLOWDOWN\0US1FLOWUP\0us2powup\0"
    "us2powdown\0us2vacup\0us2vacdown\0us2flowup\0"
    "us2flowdown\0ULTRASONICBUT3\0us3powup\0"
    "us3powdown\0us3vacup\0us3vacdown\0us3flowup\0"
    "us3flowdown\0us4powup\0us4powdown\0"
    "us4vacup\0us4vacdown\0us4flowup\0us4flowdown\0"
    "SETTINGSBUT\0BACKBUT\0on_DIABUT_clicked\0"
    "us1_linear_nonlinear\0us2_linear_nonlinear\0"
    "us3_linear_nonlinear\0us4_linear_nonlinear\0"
    "ia1_linear_nonlinear\0ia2_linear_nonlinear\0"
    "vit_linear_nonlinear\0on_off_vit\0"
    "on_off_us2\0on_off_us3\0on_off_us4\0"
    "HANDPIECE\0updatesensor\0continous_irrigation1\0"
    "continous_irrigation2\0continous_irrigation3\0"
    "continous_irrigation4\0continous_irrigation5\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_44_clicked\0"
    "on_pushButton_45_clicked\0"
    "on_pushButton_46_clicked\0"
    "on_pushButton_47_clicked\0"
    "on_pushButton_49_clicked\0"
    "on_pushButton_48_clicked\0"
    "on_pushButton_50_clicked\0"
    "on_pushButton_51_clicked\0"
    "on_pushButton_52_clicked\0"
    "on_pushButton_53_clicked\0"
    "on_pushButton_54_clicked\0"
    "on_pushButton_55_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      94,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  484,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,  487,    2, 0x0a /* Public */,
       7,    4,  494,    2, 0x0a /* Public */,
      11,    1,  503,    2, 0x0a /* Public */,
      13,    0,  506,    2, 0x0a /* Public */,
      14,    1,  507,    2, 0x0a /* Public */,
      16,    1,  510,    2, 0x0a /* Public */,
      18,    1,  513,    2, 0x0a /* Public */,
      20,    1,  516,    2, 0x0a /* Public */,
      21,    0,  519,    2, 0x0a /* Public */,
      22,    0,  520,    2, 0x0a /* Public */,
      23,    0,  521,    2, 0x08 /* Private */,
      24,    0,  522,    2, 0x08 /* Private */,
      25,    0,  523,    2, 0x08 /* Private */,
      26,    0,  524,    2, 0x08 /* Private */,
      27,    0,  525,    2, 0x08 /* Private */,
      28,    0,  526,    2, 0x08 /* Private */,
      29,    0,  527,    2, 0x08 /* Private */,
      30,    0,  528,    2, 0x08 /* Private */,
      31,    0,  529,    2, 0x08 /* Private */,
      32,    0,  530,    2, 0x08 /* Private */,
      33,    0,  531,    2, 0x08 /* Private */,
      34,    0,  532,    2, 0x08 /* Private */,
      35,    0,  533,    2, 0x08 /* Private */,
      36,    0,  534,    2, 0x08 /* Private */,
      37,    0,  535,    2, 0x08 /* Private */,
      38,    0,  536,    2, 0x08 /* Private */,
      39,    0,  537,    2, 0x08 /* Private */,
      40,    0,  538,    2, 0x08 /* Private */,
      41,    0,  539,    2, 0x08 /* Private */,
      42,    0,  540,    2, 0x08 /* Private */,
      43,    0,  541,    2, 0x08 /* Private */,
      44,    0,  542,    2, 0x08 /* Private */,
      45,    0,  543,    2, 0x08 /* Private */,
      46,    0,  544,    2, 0x08 /* Private */,
      47,    0,  545,    2, 0x08 /* Private */,
      48,    0,  546,    2, 0x08 /* Private */,
      49,    0,  547,    2, 0x08 /* Private */,
      50,    0,  548,    2, 0x08 /* Private */,
      51,    0,  549,    2, 0x08 /* Private */,
      52,    0,  550,    2, 0x08 /* Private */,
      53,    0,  551,    2, 0x08 /* Private */,
      54,    0,  552,    2, 0x08 /* Private */,
      55,    0,  553,    2, 0x08 /* Private */,
      56,    0,  554,    2, 0x08 /* Private */,
      57,    0,  555,    2, 0x08 /* Private */,
      58,    0,  556,    2, 0x08 /* Private */,
      59,    0,  557,    2, 0x08 /* Private */,
      60,    0,  558,    2, 0x08 /* Private */,
      61,    0,  559,    2, 0x08 /* Private */,
      62,    0,  560,    2, 0x08 /* Private */,
      63,    0,  561,    2, 0x08 /* Private */,
      64,    0,  562,    2, 0x08 /* Private */,
      65,    0,  563,    2, 0x08 /* Private */,
      66,    0,  564,    2, 0x08 /* Private */,
      67,    0,  565,    2, 0x08 /* Private */,
      68,    0,  566,    2, 0x08 /* Private */,
      69,    0,  567,    2, 0x08 /* Private */,
      70,    0,  568,    2, 0x08 /* Private */,
      71,    0,  569,    2, 0x08 /* Private */,
      72,    0,  570,    2, 0x08 /* Private */,
      73,    0,  571,    2, 0x08 /* Private */,
      74,    0,  572,    2, 0x08 /* Private */,
      75,    0,  573,    2, 0x08 /* Private */,
      76,    0,  574,    2, 0x08 /* Private */,
      77,    0,  575,    2, 0x08 /* Private */,
      78,    0,  576,    2, 0x08 /* Private */,
      79,    0,  577,    2, 0x08 /* Private */,
      80,    0,  578,    2, 0x08 /* Private */,
      81,    0,  579,    2, 0x08 /* Private */,
      82,    0,  580,    2, 0x08 /* Private */,
      83,    0,  581,    2, 0x08 /* Private */,
      84,    0,  582,    2, 0x08 /* Private */,
      85,    0,  583,    2, 0x08 /* Private */,
      86,    0,  584,    2, 0x08 /* Private */,
      87,    0,  585,    2, 0x08 /* Private */,
      88,    0,  586,    2, 0x08 /* Private */,
      89,    0,  587,    2, 0x08 /* Private */,
      90,    0,  588,    2, 0x08 /* Private */,
      91,    0,  589,    2, 0x08 /* Private */,
      92,    0,  590,    2, 0x08 /* Private */,
      93,    0,  591,    2, 0x08 /* Private */,
      94,    0,  592,    2, 0x08 /* Private */,
      95,    0,  593,    2, 0x08 /* Private */,
      96,    0,  594,    2, 0x08 /* Private */,
      97,    0,  595,    2, 0x08 /* Private */,
      98,    0,  596,    2, 0x08 /* Private */,
      99,    0,  597,    2, 0x08 /* Private */,
     100,    0,  598,    2, 0x08 /* Private */,
     101,    0,  599,    2, 0x08 /* Private */,
     102,    0,  600,    2, 0x08 /* Private */,
     103,    0,  601,    2, 0x08 /* Private */,
     104,    0,  602,    2, 0x08 /* Private */,
     105,    0,  603,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,    3,    6,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sensorValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->userMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updateLineedit((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->on_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_clickedenter(); break;
        case 5: _t->changeButtonColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateline((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->tabupdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->startphaco(); break;
        case 10: _t->updateElapsedTime(); break;
        case 11: _t->ULTRASONICBUT1(); break;
        case 12: _t->ULTRASONICBUT2(); break;
        case 13: _t->ULTRASONICBUT4(); break;
        case 14: _t->IRRIGATIONBUT1(); break;
        case 15: _t->IRRIGATIONBUT2(); break;
        case 16: _t->VITRECTOMYBUT(); break;
        case 17: _t->DIATHERMYBUT(); break;
        case 18: _t->diapowup(); break;
        case 19: _t->diapowdown(); break;
        case 20: _t->vitcutup(); break;
        case 21: _t->vitcutdown(); break;
        case 22: _t->vitvacup(); break;
        case 23: _t->vitvacdown(); break;
        case 24: _t->vitflowup(); break;
        case 25: _t->vitflowdown(); break;
        case 26: _t->ia2vacup(); break;
        case 27: _t->ia2vacdown(); break;
        case 28: _t->ia2flowup(); break;
        case 29: _t->ia2flowdown(); break;
        case 30: _t->ia1vacup(); break;
        case 31: _t->ia1vacdown(); break;
        case 32: _t->ia1flowup(); break;
        case 33: _t->ia1flowdown(); break;
        case 34: _t->US1POWUP(); break;
        case 35: _t->US1POWDOWN(); break;
        case 36: _t->US1VACDOWN(); break;
        case 37: _t->US1VACUP(); break;
        case 38: _t->US1FLOWDOWN(); break;
        case 39: _t->US1FLOWUP(); break;
        case 40: _t->us2powup(); break;
        case 41: _t->us2powdown(); break;
        case 42: _t->us2vacup(); break;
        case 43: _t->us2vacdown(); break;
        case 44: _t->us2flowup(); break;
        case 45: _t->us2flowdown(); break;
        case 46: _t->ULTRASONICBUT3(); break;
        case 47: _t->us3powup(); break;
        case 48: _t->us3powdown(); break;
        case 49: _t->us3vacup(); break;
        case 50: _t->us3vacdown(); break;
        case 51: _t->us3flowup(); break;
        case 52: _t->us3flowdown(); break;
        case 53: _t->us4powup(); break;
        case 54: _t->us4powdown(); break;
        case 55: _t->us4vacup(); break;
        case 56: _t->us4vacdown(); break;
        case 57: _t->us4flowup(); break;
        case 58: _t->us4flowdown(); break;
        case 59: _t->SETTINGSBUT(); break;
        case 60: _t->BACKBUT(); break;
        case 61: _t->on_DIABUT_clicked(); break;
        case 62: _t->us1_linear_nonlinear(); break;
        case 63: _t->us2_linear_nonlinear(); break;
        case 64: _t->us3_linear_nonlinear(); break;
        case 65: _t->us4_linear_nonlinear(); break;
        case 66: _t->ia1_linear_nonlinear(); break;
        case 67: _t->ia2_linear_nonlinear(); break;
        case 68: _t->vit_linear_nonlinear(); break;
        case 69: _t->on_off_vit(); break;
        case 70: _t->on_off_us2(); break;
        case 71: _t->on_off_us3(); break;
        case 72: _t->on_off_us4(); break;
        case 73: _t->HANDPIECE(); break;
        case 74: _t->updatesensor(); break;
        case 75: _t->continous_irrigation1(); break;
        case 76: _t->continous_irrigation2(); break;
        case 77: _t->continous_irrigation3(); break;
        case 78: _t->continous_irrigation4(); break;
        case 79: _t->continous_irrigation5(); break;
        case 80: _t->on_pushButton_5_clicked(); break;
        case 81: _t->on_pushButton_6_clicked(); break;
        case 82: _t->on_pushButton_44_clicked(); break;
        case 83: _t->on_pushButton_45_clicked(); break;
        case 84: _t->on_pushButton_46_clicked(); break;
        case 85: _t->on_pushButton_47_clicked(); break;
        case 86: _t->on_pushButton_49_clicked(); break;
        case 87: _t->on_pushButton_48_clicked(); break;
        case 88: _t->on_pushButton_50_clicked(); break;
        case 89: _t->on_pushButton_51_clicked(); break;
        case 90: _t->on_pushButton_52_clicked(); break;
        case 91: _t->on_pushButton_53_clicked(); break;
        case 92: _t->on_pushButton_54_clicked(); break;
        case 93: _t->on_pushButton_55_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sensorValueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 94)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 94;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 94)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 94;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sensorValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
