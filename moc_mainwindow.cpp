/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
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
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[157];
    char stringdata0[2327];
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
QT_MOC_LITERAL(19, 195, 9), // "tabupdate"
QT_MOC_LITERAL(20, 205, 5), // "index"
QT_MOC_LITERAL(21, 211, 14), // "footpedalcheck"
QT_MOC_LITERAL(22, 226, 17), // "updateElapsedTime"
QT_MOC_LITERAL(23, 244, 17), // "updateProgressBar"
QT_MOC_LITERAL(24, 262, 7), // "motoron"
QT_MOC_LITERAL(25, 270, 8), // "motoroff"
QT_MOC_LITERAL(26, 279, 10), // "motorccwon"
QT_MOC_LITERAL(27, 290, 14), // "increasebutton"
QT_MOC_LITERAL(28, 305, 12), // "increaseline"
QT_MOC_LITERAL(29, 318, 14), // "decreasebutton"
QT_MOC_LITERAL(30, 333, 12), // "decreaseline"
QT_MOC_LITERAL(31, 346, 9), // "vacbutton"
QT_MOC_LITERAL(32, 356, 7), // "vacline"
QT_MOC_LITERAL(33, 364, 8), // "powervit"
QT_MOC_LITERAL(34, 373, 10), // "powercheck"
QT_MOC_LITERAL(35, 384, 12), // "DIATHERMYBUT"
QT_MOC_LITERAL(36, 397, 25), // "onMainLineEditTextChanged"
QT_MOC_LITERAL(37, 423, 7), // "dpowmax"
QT_MOC_LITERAL(38, 431, 25), // "movePushButtonTopToBottom"
QT_MOC_LITERAL(39, 457, 25), // "movePushButtonBottomToTop"
QT_MOC_LITERAL(40, 483, 10), // "footreflux"
QT_MOC_LITERAL(41, 494, 19), // "powerdeliverymethod"
QT_MOC_LITERAL(42, 514, 19), // "continousirrigation"
QT_MOC_LITERAL(43, 534, 10), // "poweronoff"
QT_MOC_LITERAL(44, 545, 7), // "poweron"
QT_MOC_LITERAL(45, 553, 12), // "updateValues"
QT_MOC_LITERAL(46, 566, 7), // "surgeon"
QT_MOC_LITERAL(47, 574, 6), // "values"
QT_MOC_LITERAL(48, 581, 23), // "onCutMode_vitComChanged"
QT_MOC_LITERAL(49, 605, 24), // "onCutMode_vitComChanged1"
QT_MOC_LITERAL(50, 630, 24), // "onCutMode_vitComChanged2"
QT_MOC_LITERAL(51, 655, 24), // "onCutMode_vitComChanged3"
QT_MOC_LITERAL(52, 680, 7), // "label43"
QT_MOC_LITERAL(53, 688, 7), // "sensor2"
QT_MOC_LITERAL(54, 696, 14), // "ULTRASONICBUT1"
QT_MOC_LITERAL(55, 711, 14), // "ULTRASONICBUT2"
QT_MOC_LITERAL(56, 726, 14), // "ULTRASONICBUT4"
QT_MOC_LITERAL(57, 741, 14), // "IRRIGATIONBUT1"
QT_MOC_LITERAL(58, 756, 14), // "IRRIGATIONBUT2"
QT_MOC_LITERAL(59, 771, 13), // "VITRECTOMYBUT"
QT_MOC_LITERAL(60, 785, 8), // "diapowup"
QT_MOC_LITERAL(61, 794, 10), // "diapowdown"
QT_MOC_LITERAL(62, 805, 8), // "vitcutup"
QT_MOC_LITERAL(63, 814, 10), // "vitcutdown"
QT_MOC_LITERAL(64, 825, 8), // "vitvacup"
QT_MOC_LITERAL(65, 834, 10), // "vitvacdown"
QT_MOC_LITERAL(66, 845, 9), // "vitflowup"
QT_MOC_LITERAL(67, 855, 11), // "vitflowdown"
QT_MOC_LITERAL(68, 867, 8), // "ia2vacup"
QT_MOC_LITERAL(69, 876, 10), // "ia2vacdown"
QT_MOC_LITERAL(70, 887, 9), // "ia2flowup"
QT_MOC_LITERAL(71, 897, 11), // "ia2flowdown"
QT_MOC_LITERAL(72, 909, 8), // "ia1vacup"
QT_MOC_LITERAL(73, 918, 10), // "ia1vacdown"
QT_MOC_LITERAL(74, 929, 9), // "ia1flowup"
QT_MOC_LITERAL(75, 939, 11), // "ia1flowdown"
QT_MOC_LITERAL(76, 951, 8), // "US1POWUP"
QT_MOC_LITERAL(77, 960, 10), // "US1POWDOWN"
QT_MOC_LITERAL(78, 971, 10), // "US1VACDOWN"
QT_MOC_LITERAL(79, 982, 8), // "US1VACUP"
QT_MOC_LITERAL(80, 991, 11), // "US1FLOWDOWN"
QT_MOC_LITERAL(81, 1003, 9), // "US1FLOWUP"
QT_MOC_LITERAL(82, 1013, 8), // "us2powup"
QT_MOC_LITERAL(83, 1022, 10), // "us2powdown"
QT_MOC_LITERAL(84, 1033, 8), // "us2vacup"
QT_MOC_LITERAL(85, 1042, 10), // "us2vacdown"
QT_MOC_LITERAL(86, 1053, 9), // "us2flowup"
QT_MOC_LITERAL(87, 1063, 11), // "us2flowdown"
QT_MOC_LITERAL(88, 1075, 14), // "ULTRASONICBUT3"
QT_MOC_LITERAL(89, 1090, 8), // "us3powup"
QT_MOC_LITERAL(90, 1099, 10), // "us3powdown"
QT_MOC_LITERAL(91, 1110, 8), // "us3vacup"
QT_MOC_LITERAL(92, 1119, 10), // "us3vacdown"
QT_MOC_LITERAL(93, 1130, 9), // "us3flowup"
QT_MOC_LITERAL(94, 1140, 11), // "us3flowdown"
QT_MOC_LITERAL(95, 1152, 8), // "us4powup"
QT_MOC_LITERAL(96, 1161, 10), // "us4powdown"
QT_MOC_LITERAL(97, 1172, 8), // "us4vacup"
QT_MOC_LITERAL(98, 1181, 10), // "us4vacdown"
QT_MOC_LITERAL(99, 1192, 9), // "us4flowup"
QT_MOC_LITERAL(100, 1202, 11), // "us4flowdown"
QT_MOC_LITERAL(101, 1214, 11), // "SETTINGSBUT"
QT_MOC_LITERAL(102, 1226, 7), // "BACKBUT"
QT_MOC_LITERAL(103, 1234, 17), // "on_DIABUT_clicked"
QT_MOC_LITERAL(104, 1252, 20), // "us1_linear_nonlinear"
QT_MOC_LITERAL(105, 1273, 20), // "us2_linear_nonlinear"
QT_MOC_LITERAL(106, 1294, 20), // "us3_linear_nonlinear"
QT_MOC_LITERAL(107, 1315, 20), // "us4_linear_nonlinear"
QT_MOC_LITERAL(108, 1336, 20), // "ia1_linear_nonlinear"
QT_MOC_LITERAL(109, 1357, 20), // "ia2_linear_nonlinear"
QT_MOC_LITERAL(110, 1378, 20), // "vit_linear_nonlinear"
QT_MOC_LITERAL(111, 1399, 21), // "updatehandpieceStatus"
QT_MOC_LITERAL(112, 1421, 12), // "updatesensor"
QT_MOC_LITERAL(113, 1434, 21), // "onUpdateStatusTimeout"
QT_MOC_LITERAL(114, 1456, 12), // "updateTimers"
QT_MOC_LITERAL(115, 1469, 15), // "settings_action"
QT_MOC_LITERAL(116, 1485, 19), // "on_us1onoff_clicked"
QT_MOC_LITERAL(117, 1505, 19), // "on_us2onoff_clicked"
QT_MOC_LITERAL(118, 1525, 19), // "on_us3onoff_clicked"
QT_MOC_LITERAL(119, 1545, 19), // "on_us4onoff_clicked"
QT_MOC_LITERAL(120, 1565, 19), // "on_vitonoff_clicked"
QT_MOC_LITERAL(121, 1585, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(122, 1609, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(123, 1633, 21), // "on_us1vacmode_clicked"
QT_MOC_LITERAL(124, 1655, 21), // "on_us2vacmode_clicked"
QT_MOC_LITERAL(125, 1677, 21), // "on_us3vacmode_clicked"
QT_MOC_LITERAL(126, 1699, 21), // "on_vitvacmode_clicked"
QT_MOC_LITERAL(127, 1721, 21), // "on_us4vacmode_clicked"
QT_MOC_LITERAL(128, 1743, 15), // "updateComboBox1"
QT_MOC_LITERAL(129, 1759, 4), // "text"
QT_MOC_LITERAL(130, 1764, 15), // "updateComboBox2"
QT_MOC_LITERAL(131, 1780, 15), // "updateComboBox3"
QT_MOC_LITERAL(132, 1796, 15), // "updateComboBox4"
QT_MOC_LITERAL(133, 1812, 16), // "onSurgeonChanged"
QT_MOC_LITERAL(134, 1829, 21), // "updateButtonSelection"
QT_MOC_LITERAL(135, 1851, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(136, 1875, 24), // "on_pushButton_44_clicked"
QT_MOC_LITERAL(137, 1900, 24), // "on_pushButton_45_clicked"
QT_MOC_LITERAL(138, 1925, 24), // "on_pushButton_46_clicked"
QT_MOC_LITERAL(139, 1950, 24), // "on_pushButton_47_clicked"
QT_MOC_LITERAL(140, 1975, 24), // "on_pushButton_48_clicked"
QT_MOC_LITERAL(141, 2000, 24), // "on_pushButton_49_clicked"
QT_MOC_LITERAL(142, 2025, 24), // "on_pushButton_50_clicked"
QT_MOC_LITERAL(143, 2050, 24), // "on_pushButton_51_clicked"
QT_MOC_LITERAL(144, 2075, 24), // "on_pushButton_52_clicked"
QT_MOC_LITERAL(145, 2100, 24), // "on_pushButton_53_clicked"
QT_MOC_LITERAL(146, 2125, 24), // "on_pushButton_54_clicked"
QT_MOC_LITERAL(147, 2150, 24), // "on_pushButton_55_clicked"
QT_MOC_LITERAL(148, 2175, 25), // "on_SETTINGS_BUT_3_clicked"
QT_MOC_LITERAL(149, 2201, 16), // "on_CI5_2_clicked"
QT_MOC_LITERAL(150, 2218, 14), // "on_CI1_clicked"
QT_MOC_LITERAL(151, 2233, 14), // "on_CI2_clicked"
QT_MOC_LITERAL(152, 2248, 14), // "on_CI3_clicked"
QT_MOC_LITERAL(153, 2263, 14), // "on_CI4_clicked"
QT_MOC_LITERAL(154, 2278, 16), // "on_CI5_3_clicked"
QT_MOC_LITERAL(155, 2295, 16), // "on_CI5_4_clicked"
QT_MOC_LITERAL(156, 2312, 14) // "on_CI5_clicked"

    },
    "MainWindow\0sensorValueChanged\0\0value\0"
    "userMessage\0minValue\0maxValue\0"
    "updateLineedit\0QLineEdit*\0lineEdit\0"
    "prevValue\0on_clicked\0digit\0on_clickedenter\0"
    "changeButtonColor\0tabIndex\0current\0"
    "tab\0updateline\0tabupdate\0index\0"
    "footpedalcheck\0updateElapsedTime\0"
    "updateProgressBar\0motoron\0motoroff\0"
    "motorccwon\0increasebutton\0increaseline\0"
    "decreasebutton\0decreaseline\0vacbutton\0"
    "vacline\0powervit\0powercheck\0DIATHERMYBUT\0"
    "onMainLineEditTextChanged\0dpowmax\0"
    "movePushButtonTopToBottom\0"
    "movePushButtonBottomToTop\0footreflux\0"
    "powerdeliverymethod\0continousirrigation\0"
    "poweronoff\0poweron\0updateValues\0surgeon\0"
    "values\0onCutMode_vitComChanged\0"
    "onCutMode_vitComChanged1\0"
    "onCutMode_vitComChanged2\0"
    "onCutMode_vitComChanged3\0label43\0"
    "sensor2\0ULTRASONICBUT1\0ULTRASONICBUT2\0"
    "ULTRASONICBUT4\0IRRIGATIONBUT1\0"
    "IRRIGATIONBUT2\0VITRECTOMYBUT\0diapowup\0"
    "diapowdown\0vitcutup\0vitcutdown\0vitvacup\0"
    "vitvacdown\0vitflowup\0vitflowdown\0"
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
    "vit_linear_nonlinear\0updatehandpieceStatus\0"
    "updatesensor\0onUpdateStatusTimeout\0"
    "updateTimers\0settings_action\0"
    "on_us1onoff_clicked\0on_us2onoff_clicked\0"
    "on_us3onoff_clicked\0on_us4onoff_clicked\0"
    "on_vitonoff_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_us1vacmode_clicked\0"
    "on_us2vacmode_clicked\0on_us3vacmode_clicked\0"
    "on_vitvacmode_clicked\0on_us4vacmode_clicked\0"
    "updateComboBox1\0text\0updateComboBox2\0"
    "updateComboBox3\0updateComboBox4\0"
    "onSurgeonChanged\0updateButtonSelection\0"
    "on_pushButton_6_clicked\0"
    "on_pushButton_44_clicked\0"
    "on_pushButton_45_clicked\0"
    "on_pushButton_46_clicked\0"
    "on_pushButton_47_clicked\0"
    "on_pushButton_48_clicked\0"
    "on_pushButton_49_clicked\0"
    "on_pushButton_50_clicked\0"
    "on_pushButton_51_clicked\0"
    "on_pushButton_52_clicked\0"
    "on_pushButton_53_clicked\0"
    "on_pushButton_54_clicked\0"
    "on_pushButton_55_clicked\0"
    "on_SETTINGS_BUT_3_clicked\0on_CI5_2_clicked\0"
    "on_CI1_clicked\0on_CI2_clicked\0"
    "on_CI3_clicked\0on_CI4_clicked\0"
    "on_CI5_3_clicked\0on_CI5_4_clicked\0"
    "on_CI5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     138,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  704,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,  707,    2, 0x0a /* Public */,
       7,    4,  714,    2, 0x0a /* Public */,
      11,    1,  723,    2, 0x0a /* Public */,
      13,    0,  726,    2, 0x0a /* Public */,
      14,    1,  727,    2, 0x0a /* Public */,
      16,    1,  730,    2, 0x0a /* Public */,
      18,    0,  733,    2, 0x0a /* Public */,
      19,    1,  734,    2, 0x0a /* Public */,
      21,    0,  737,    2, 0x0a /* Public */,
      22,    0,  738,    2, 0x0a /* Public */,
      23,    0,  739,    2, 0x0a /* Public */,
      24,    1,  740,    2, 0x0a /* Public */,
      25,    0,  743,    2, 0x0a /* Public */,
      26,    0,  744,    2, 0x0a /* Public */,
      27,    1,  745,    2, 0x0a /* Public */,
      29,    1,  748,    2, 0x0a /* Public */,
      31,    1,  751,    2, 0x0a /* Public */,
      33,    0,  754,    2, 0x0a /* Public */,
      34,    0,  755,    2, 0x0a /* Public */,
      35,    0,  756,    2, 0x0a /* Public */,
      36,    1,  757,    2, 0x0a /* Public */,
      38,    0,  760,    2, 0x0a /* Public */,
      39,    0,  761,    2, 0x0a /* Public */,
      40,    0,  762,    2, 0x0a /* Public */,
      41,    0,  763,    2, 0x0a /* Public */,
      42,    0,  764,    2, 0x0a /* Public */,
      43,    0,  765,    2, 0x0a /* Public */,
      44,    0,  766,    2, 0x0a /* Public */,
      45,    3,  767,    2, 0x0a /* Public */,
      48,    1,  774,    2, 0x0a /* Public */,
      49,    1,  777,    2, 0x0a /* Public */,
      50,    1,  780,    2, 0x0a /* Public */,
      51,    1,  783,    2, 0x0a /* Public */,
      52,    0,  786,    2, 0x08 /* Private */,
      53,    0,  787,    2, 0x08 /* Private */,
      54,    0,  788,    2, 0x08 /* Private */,
      55,    0,  789,    2, 0x08 /* Private */,
      56,    0,  790,    2, 0x08 /* Private */,
      57,    0,  791,    2, 0x08 /* Private */,
      58,    0,  792,    2, 0x08 /* Private */,
      59,    0,  793,    2, 0x08 /* Private */,
      60,    0,  794,    2, 0x08 /* Private */,
      61,    0,  795,    2, 0x08 /* Private */,
      62,    0,  796,    2, 0x08 /* Private */,
      63,    0,  797,    2, 0x08 /* Private */,
      64,    0,  798,    2, 0x08 /* Private */,
      65,    0,  799,    2, 0x08 /* Private */,
      66,    0,  800,    2, 0x08 /* Private */,
      67,    0,  801,    2, 0x08 /* Private */,
      68,    0,  802,    2, 0x08 /* Private */,
      69,    0,  803,    2, 0x08 /* Private */,
      70,    0,  804,    2, 0x08 /* Private */,
      71,    0,  805,    2, 0x08 /* Private */,
      72,    0,  806,    2, 0x08 /* Private */,
      73,    0,  807,    2, 0x08 /* Private */,
      74,    0,  808,    2, 0x08 /* Private */,
      75,    0,  809,    2, 0x08 /* Private */,
      76,    0,  810,    2, 0x08 /* Private */,
      77,    0,  811,    2, 0x08 /* Private */,
      78,    0,  812,    2, 0x08 /* Private */,
      79,    0,  813,    2, 0x08 /* Private */,
      80,    0,  814,    2, 0x08 /* Private */,
      81,    0,  815,    2, 0x08 /* Private */,
      82,    0,  816,    2, 0x08 /* Private */,
      83,    0,  817,    2, 0x08 /* Private */,
      84,    0,  818,    2, 0x08 /* Private */,
      85,    0,  819,    2, 0x08 /* Private */,
      86,    0,  820,    2, 0x08 /* Private */,
      87,    0,  821,    2, 0x08 /* Private */,
      88,    0,  822,    2, 0x08 /* Private */,
      89,    0,  823,    2, 0x08 /* Private */,
      90,    0,  824,    2, 0x08 /* Private */,
      91,    0,  825,    2, 0x08 /* Private */,
      92,    0,  826,    2, 0x08 /* Private */,
      93,    0,  827,    2, 0x08 /* Private */,
      94,    0,  828,    2, 0x08 /* Private */,
      95,    0,  829,    2, 0x08 /* Private */,
      96,    0,  830,    2, 0x08 /* Private */,
      97,    0,  831,    2, 0x08 /* Private */,
      98,    0,  832,    2, 0x08 /* Private */,
      99,    0,  833,    2, 0x08 /* Private */,
     100,    0,  834,    2, 0x08 /* Private */,
     101,    0,  835,    2, 0x08 /* Private */,
     102,    0,  836,    2, 0x08 /* Private */,
     103,    0,  837,    2, 0x08 /* Private */,
     104,    0,  838,    2, 0x08 /* Private */,
     105,    0,  839,    2, 0x08 /* Private */,
     106,    0,  840,    2, 0x08 /* Private */,
     107,    0,  841,    2, 0x08 /* Private */,
     108,    0,  842,    2, 0x08 /* Private */,
     109,    0,  843,    2, 0x08 /* Private */,
     110,    0,  844,    2, 0x08 /* Private */,
     111,    0,  845,    2, 0x08 /* Private */,
     112,    0,  846,    2, 0x08 /* Private */,
     113,    0,  847,    2, 0x08 /* Private */,
     114,    0,  848,    2, 0x08 /* Private */,
     115,    1,  849,    2, 0x08 /* Private */,
     116,    0,  852,    2, 0x08 /* Private */,
     117,    0,  853,    2, 0x08 /* Private */,
     118,    0,  854,    2, 0x08 /* Private */,
     119,    0,  855,    2, 0x08 /* Private */,
     120,    0,  856,    2, 0x08 /* Private */,
     121,    0,  857,    2, 0x08 /* Private */,
     122,    0,  858,    2, 0x08 /* Private */,
     123,    0,  859,    2, 0x08 /* Private */,
     124,    0,  860,    2, 0x08 /* Private */,
     125,    0,  861,    2, 0x08 /* Private */,
     126,    0,  862,    2, 0x08 /* Private */,
     127,    0,  863,    2, 0x08 /* Private */,
     128,    1,  864,    2, 0x08 /* Private */,
     130,    1,  867,    2, 0x08 /* Private */,
     131,    1,  870,    2, 0x08 /* Private */,
     132,    1,  873,    2, 0x08 /* Private */,
     133,    0,  876,    2, 0x08 /* Private */,
     134,    1,  877,    2, 0x08 /* Private */,
     135,    0,  880,    2, 0x08 /* Private */,
     136,    0,  881,    2, 0x08 /* Private */,
     137,    0,  882,    2, 0x08 /* Private */,
     138,    0,  883,    2, 0x08 /* Private */,
     139,    0,  884,    2, 0x08 /* Private */,
     140,    0,  885,    2, 0x08 /* Private */,
     141,    0,  886,    2, 0x08 /* Private */,
     142,    0,  887,    2, 0x08 /* Private */,
     143,    0,  888,    2, 0x08 /* Private */,
     144,    0,  889,    2, 0x08 /* Private */,
     145,    0,  890,    2, 0x08 /* Private */,
     146,    0,  891,    2, 0x08 /* Private */,
     147,    0,  892,    2, 0x08 /* Private */,
     148,    0,  893,    2, 0x08 /* Private */,
     149,    0,  894,    2, 0x08 /* Private */,
     150,    0,  895,    2, 0x08 /* Private */,
     151,    0,  896,    2, 0x08 /* Private */,
     152,    0,  897,    2, 0x08 /* Private */,
     153,    0,  898,    2, 0x08 /* Private */,
     154,    0,  899,    2, 0x08 /* Private */,
     155,    0,  900,    2, 0x08 /* Private */,
     156,    0,  901,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,    3,    6,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,   28,
    QMetaType::Void, 0x80000000 | 8,   30,
    QMetaType::Void, 0x80000000 | 8,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QStringList,   46,   15,   47,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
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
    QMetaType::Void, QMetaType::Int,   20,
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
    QMetaType::Void, QMetaType::QString,  129,
    QMetaType::Void, QMetaType::QString,  129,
    QMetaType::Void, QMetaType::QString,  129,
    QMetaType::Void, QMetaType::QString,  129,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
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
        (void)_t;
        switch (_id) {
        case 0: _t->sensorValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->userMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updateLineedit((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->on_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_clickedenter(); break;
        case 5: _t->changeButtonColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateline(); break;
        case 8: _t->tabupdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->footpedalcheck(); break;
        case 10: _t->updateElapsedTime(); break;
        case 11: _t->updateProgressBar(); break;
        case 12: _t->motoron((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 13: _t->motoroff(); break;
        case 14: _t->motorccwon(); break;
        case 15: _t->increasebutton((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 16: _t->decreasebutton((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 17: _t->vacbutton((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 18: _t->powervit(); break;
        case 19: _t->powercheck(); break;
        case 20: _t->DIATHERMYBUT(); break;
        case 21: _t->onMainLineEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->movePushButtonTopToBottom(); break;
        case 23: _t->movePushButtonBottomToTop(); break;
        case 24: _t->footreflux(); break;
        case 25: _t->powerdeliverymethod(); break;
        case 26: _t->continousirrigation(); break;
        case 27: _t->poweronoff(); break;
        case 28: _t->poweron(); break;
        case 29: _t->updateValues((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3]))); break;
        case 30: _t->onCutMode_vitComChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->onCutMode_vitComChanged1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->onCutMode_vitComChanged2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->onCutMode_vitComChanged3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->label43(); break;
        case 35: _t->sensor2(); break;
        case 36: _t->ULTRASONICBUT1(); break;
        case 37: _t->ULTRASONICBUT2(); break;
        case 38: _t->ULTRASONICBUT4(); break;
        case 39: _t->IRRIGATIONBUT1(); break;
        case 40: _t->IRRIGATIONBUT2(); break;
        case 41: _t->VITRECTOMYBUT(); break;
        case 42: _t->diapowup(); break;
        case 43: _t->diapowdown(); break;
        case 44: _t->vitcutup(); break;
        case 45: _t->vitcutdown(); break;
        case 46: _t->vitvacup(); break;
        case 47: _t->vitvacdown(); break;
        case 48: _t->vitflowup(); break;
        case 49: _t->vitflowdown(); break;
        case 50: _t->ia2vacup(); break;
        case 51: _t->ia2vacdown(); break;
        case 52: _t->ia2flowup(); break;
        case 53: _t->ia2flowdown(); break;
        case 54: _t->ia1vacup(); break;
        case 55: _t->ia1vacdown(); break;
        case 56: _t->ia1flowup(); break;
        case 57: _t->ia1flowdown(); break;
        case 58: _t->US1POWUP(); break;
        case 59: _t->US1POWDOWN(); break;
        case 60: _t->US1VACDOWN(); break;
        case 61: _t->US1VACUP(); break;
        case 62: _t->US1FLOWDOWN(); break;
        case 63: _t->US1FLOWUP(); break;
        case 64: _t->us2powup(); break;
        case 65: _t->us2powdown(); break;
        case 66: _t->us2vacup(); break;
        case 67: _t->us2vacdown(); break;
        case 68: _t->us2flowup(); break;
        case 69: _t->us2flowdown(); break;
        case 70: _t->ULTRASONICBUT3(); break;
        case 71: _t->us3powup(); break;
        case 72: _t->us3powdown(); break;
        case 73: _t->us3vacup(); break;
        case 74: _t->us3vacdown(); break;
        case 75: _t->us3flowup(); break;
        case 76: _t->us3flowdown(); break;
        case 77: _t->us4powup(); break;
        case 78: _t->us4powdown(); break;
        case 79: _t->us4vacup(); break;
        case 80: _t->us4vacdown(); break;
        case 81: _t->us4flowup(); break;
        case 82: _t->us4flowdown(); break;
        case 83: _t->SETTINGSBUT(); break;
        case 84: _t->BACKBUT(); break;
        case 85: _t->on_DIABUT_clicked(); break;
        case 86: _t->us1_linear_nonlinear(); break;
        case 87: _t->us2_linear_nonlinear(); break;
        case 88: _t->us3_linear_nonlinear(); break;
        case 89: _t->us4_linear_nonlinear(); break;
        case 90: _t->ia1_linear_nonlinear(); break;
        case 91: _t->ia2_linear_nonlinear(); break;
        case 92: _t->vit_linear_nonlinear(); break;
        case 93: _t->updatehandpieceStatus(); break;
        case 94: _t->updatesensor(); break;
        case 95: _t->onUpdateStatusTimeout(); break;
        case 96: _t->updateTimers(); break;
        case 97: _t->settings_action((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 98: _t->on_us1onoff_clicked(); break;
        case 99: _t->on_us2onoff_clicked(); break;
        case 100: _t->on_us3onoff_clicked(); break;
        case 101: _t->on_us4onoff_clicked(); break;
        case 102: _t->on_vitonoff_clicked(); break;
        case 103: _t->on_pushButton_4_clicked(); break;
        case 104: _t->on_pushButton_5_clicked(); break;
        case 105: _t->on_us1vacmode_clicked(); break;
        case 106: _t->on_us2vacmode_clicked(); break;
        case 107: _t->on_us3vacmode_clicked(); break;
        case 108: _t->on_vitvacmode_clicked(); break;
        case 109: _t->on_us4vacmode_clicked(); break;
        case 110: _t->updateComboBox1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 111: _t->updateComboBox2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 112: _t->updateComboBox3((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 113: _t->updateComboBox4((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 114: _t->onSurgeonChanged(); break;
        case 115: _t->updateButtonSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 116: _t->on_pushButton_6_clicked(); break;
        case 117: _t->on_pushButton_44_clicked(); break;
        case 118: _t->on_pushButton_45_clicked(); break;
        case 119: _t->on_pushButton_46_clicked(); break;
        case 120: _t->on_pushButton_47_clicked(); break;
        case 121: _t->on_pushButton_48_clicked(); break;
        case 122: _t->on_pushButton_49_clicked(); break;
        case 123: _t->on_pushButton_50_clicked(); break;
        case 124: _t->on_pushButton_51_clicked(); break;
        case 125: _t->on_pushButton_52_clicked(); break;
        case 126: _t->on_pushButton_53_clicked(); break;
        case 127: _t->on_pushButton_54_clicked(); break;
        case 128: _t->on_pushButton_55_clicked(); break;
        case 129: _t->on_SETTINGS_BUT_3_clicked(); break;
        case 130: _t->on_CI5_2_clicked(); break;
        case 131: _t->on_CI1_clicked(); break;
        case 132: _t->on_CI2_clicked(); break;
        case 133: _t->on_CI3_clicked(); break;
        case 134: _t->on_CI4_clicked(); break;
        case 135: _t->on_CI5_3_clicked(); break;
        case 136: _t->on_CI5_4_clicked(); break;
        case 137: _t->on_CI5_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
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
        if (_id < 138)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 138;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 138)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 138;
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
