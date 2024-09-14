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
    QByteArrayData data[182];
    char stringdata0[2344];
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
QT_MOC_LITERAL(4, 37, 15), // "surgeonSelected"
QT_MOC_LITERAL(5, 53, 11), // "surgeonName"
QT_MOC_LITERAL(6, 65, 9), // "left_foot"
QT_MOC_LITERAL(7, 75, 10), // "right_foot"
QT_MOC_LITERAL(8, 86, 11), // "bottom_left"
QT_MOC_LITERAL(9, 98, 12), // "bottom_right"
QT_MOC_LITERAL(10, 111, 14), // "con_irrigation"
QT_MOC_LITERAL(11, 126, 2), // "on"
QT_MOC_LITERAL(12, 129, 11), // "sendsurgeon"
QT_MOC_LITERAL(13, 141, 22), // "onComboBoxIndexChanged"
QT_MOC_LITERAL(14, 164, 5), // "index"
QT_MOC_LITERAL(15, 170, 17), // "onPdmModeSelected"
QT_MOC_LITERAL(16, 188, 4), // "gpio"
QT_MOC_LITERAL(17, 193, 18), // "onPdmModeSelected1"
QT_MOC_LITERAL(18, 212, 18), // "onPdmModeSelected2"
QT_MOC_LITERAL(19, 231, 18), // "onPdmModeSelected3"
QT_MOC_LITERAL(20, 250, 14), // "updateLineedit"
QT_MOC_LITERAL(21, 265, 10), // "QLineEdit*"
QT_MOC_LITERAL(22, 276, 8), // "lineEdit"
QT_MOC_LITERAL(23, 285, 9), // "prevValue"
QT_MOC_LITERAL(24, 295, 8), // "maxValue"
QT_MOC_LITERAL(25, 304, 10), // "on_clicked"
QT_MOC_LITERAL(26, 315, 5), // "digit"
QT_MOC_LITERAL(27, 321, 15), // "on_clickedenter"
QT_MOC_LITERAL(28, 337, 7), // "current"
QT_MOC_LITERAL(29, 345, 3), // "tab"
QT_MOC_LITERAL(30, 349, 9), // "tabupdate"
QT_MOC_LITERAL(31, 359, 14), // "footpedalcheck"
QT_MOC_LITERAL(32, 374, 17), // "updateElapsedTime"
QT_MOC_LITERAL(33, 392, 17), // "updateProgressBar"
QT_MOC_LITERAL(34, 410, 7), // "motoron"
QT_MOC_LITERAL(35, 418, 8), // "motoroff"
QT_MOC_LITERAL(36, 427, 10), // "motorccwon"
QT_MOC_LITERAL(37, 438, 14), // "increasebutton"
QT_MOC_LITERAL(38, 453, 5), // "input"
QT_MOC_LITERAL(39, 459, 14), // "decreasebutton"
QT_MOC_LITERAL(40, 474, 12), // "DIATHERMYBUT"
QT_MOC_LITERAL(41, 487, 5), // "moved"
QT_MOC_LITERAL(42, 493, 25), // "movePushButtonBottomToTop"
QT_MOC_LITERAL(43, 519, 10), // "footreflux"
QT_MOC_LITERAL(44, 530, 19), // "continousirrigation"
QT_MOC_LITERAL(45, 550, 10), // "poweronoff"
QT_MOC_LITERAL(46, 561, 23), // "onCutMode_vitComChanged"
QT_MOC_LITERAL(47, 585, 24), // "onCutMode_vitComChanged1"
QT_MOC_LITERAL(48, 610, 24), // "onCutMode_vitComChanged2"
QT_MOC_LITERAL(49, 635, 24), // "onCutMode_vitComChanged3"
QT_MOC_LITERAL(50, 660, 12), // "receivecombo"
QT_MOC_LITERAL(51, 673, 4), // "text"
QT_MOC_LITERAL(52, 678, 11), // "performpump"
QT_MOC_LITERAL(53, 690, 13), // "receiveValues"
QT_MOC_LITERAL(54, 704, 13), // "comboBoxValue"
QT_MOC_LITERAL(55, 718, 5), // "combo"
QT_MOC_LITERAL(56, 724, 3), // "dia"
QT_MOC_LITERAL(57, 728, 6), // "us1pow"
QT_MOC_LITERAL(58, 735, 6), // "us1vac"
QT_MOC_LITERAL(59, 742, 6), // "us1asp"
QT_MOC_LITERAL(60, 749, 6), // "us2pow"
QT_MOC_LITERAL(61, 756, 6), // "us2vac"
QT_MOC_LITERAL(62, 763, 6), // "us2asp"
QT_MOC_LITERAL(63, 770, 6), // "us3pow"
QT_MOC_LITERAL(64, 777, 6), // "us3vac"
QT_MOC_LITERAL(65, 784, 6), // "us3asp"
QT_MOC_LITERAL(66, 791, 6), // "us4pow"
QT_MOC_LITERAL(67, 798, 6), // "us4vac"
QT_MOC_LITERAL(68, 805, 6), // "us4asp"
QT_MOC_LITERAL(69, 812, 6), // "ia1vac"
QT_MOC_LITERAL(70, 819, 6), // "ia1asp"
QT_MOC_LITERAL(71, 826, 6), // "ia2vac"
QT_MOC_LITERAL(72, 833, 6), // "ia2asp"
QT_MOC_LITERAL(73, 840, 6), // "vitcut"
QT_MOC_LITERAL(74, 847, 6), // "vitvac"
QT_MOC_LITERAL(75, 854, 6), // "vitasp"
QT_MOC_LITERAL(76, 861, 7), // "powmode"
QT_MOC_LITERAL(77, 869, 7), // "vacmode"
QT_MOC_LITERAL(78, 877, 9), // "powmethod"
QT_MOC_LITERAL(79, 887, 10), // "us2powmode"
QT_MOC_LITERAL(80, 898, 10), // "us2vacmode"
QT_MOC_LITERAL(81, 909, 14), // "us2powermethod"
QT_MOC_LITERAL(82, 924, 10), // "us3powmode"
QT_MOC_LITERAL(83, 935, 10), // "us3vacmode"
QT_MOC_LITERAL(84, 946, 14), // "us3powermethod"
QT_MOC_LITERAL(85, 961, 10), // "us4powmode"
QT_MOC_LITERAL(86, 972, 10), // "us4vacmode"
QT_MOC_LITERAL(87, 983, 14), // "us4powermethod"
QT_MOC_LITERAL(88, 998, 7), // "ia1mode"
QT_MOC_LITERAL(89, 1006, 7), // "ia2mode"
QT_MOC_LITERAL(90, 1014, 7), // "vitmode"
QT_MOC_LITERAL(91, 1022, 10), // "vitvacmode"
QT_MOC_LITERAL(92, 1033, 7), // "label43"
QT_MOC_LITERAL(93, 1041, 7), // "sensor2"
QT_MOC_LITERAL(94, 1049, 14), // "ULTRASONICBUT1"
QT_MOC_LITERAL(95, 1064, 14), // "ULTRASONICBUT2"
QT_MOC_LITERAL(96, 1079, 14), // "ULTRASONICBUT4"
QT_MOC_LITERAL(97, 1094, 14), // "IRRIGATIONBUT1"
QT_MOC_LITERAL(98, 1109, 14), // "IRRIGATIONBUT2"
QT_MOC_LITERAL(99, 1124, 13), // "VITRECTOMYBUT"
QT_MOC_LITERAL(100, 1138, 8), // "diapowup"
QT_MOC_LITERAL(101, 1147, 10), // "diapowdown"
QT_MOC_LITERAL(102, 1158, 8), // "vitcutup"
QT_MOC_LITERAL(103, 1167, 10), // "vitcutdown"
QT_MOC_LITERAL(104, 1178, 8), // "vitvacup"
QT_MOC_LITERAL(105, 1187, 10), // "vitvacdown"
QT_MOC_LITERAL(106, 1198, 9), // "vitflowup"
QT_MOC_LITERAL(107, 1208, 11), // "vitflowdown"
QT_MOC_LITERAL(108, 1220, 8), // "ia2vacup"
QT_MOC_LITERAL(109, 1229, 10), // "ia2vacdown"
QT_MOC_LITERAL(110, 1240, 9), // "ia2flowup"
QT_MOC_LITERAL(111, 1250, 11), // "ia2flowdown"
QT_MOC_LITERAL(112, 1262, 8), // "ia1vacup"
QT_MOC_LITERAL(113, 1271, 10), // "ia1vacdown"
QT_MOC_LITERAL(114, 1282, 9), // "ia1flowup"
QT_MOC_LITERAL(115, 1292, 11), // "ia1flowdown"
QT_MOC_LITERAL(116, 1304, 8), // "US1POWUP"
QT_MOC_LITERAL(117, 1313, 10), // "US1POWDOWN"
QT_MOC_LITERAL(118, 1324, 10), // "US1VACDOWN"
QT_MOC_LITERAL(119, 1335, 8), // "US1VACUP"
QT_MOC_LITERAL(120, 1344, 11), // "US1FLOWDOWN"
QT_MOC_LITERAL(121, 1356, 9), // "US1FLOWUP"
QT_MOC_LITERAL(122, 1366, 8), // "us2powup"
QT_MOC_LITERAL(123, 1375, 10), // "us2powdown"
QT_MOC_LITERAL(124, 1386, 8), // "us2vacup"
QT_MOC_LITERAL(125, 1395, 10), // "us2vacdown"
QT_MOC_LITERAL(126, 1406, 9), // "us2flowup"
QT_MOC_LITERAL(127, 1416, 11), // "us2flowdown"
QT_MOC_LITERAL(128, 1428, 14), // "ULTRASONICBUT3"
QT_MOC_LITERAL(129, 1443, 8), // "us3powup"
QT_MOC_LITERAL(130, 1452, 10), // "us3powdown"
QT_MOC_LITERAL(131, 1463, 8), // "us3vacup"
QT_MOC_LITERAL(132, 1472, 10), // "us3vacdown"
QT_MOC_LITERAL(133, 1483, 9), // "us3flowup"
QT_MOC_LITERAL(134, 1493, 11), // "us3flowdown"
QT_MOC_LITERAL(135, 1505, 8), // "us4powup"
QT_MOC_LITERAL(136, 1514, 10), // "us4powdown"
QT_MOC_LITERAL(137, 1525, 8), // "us4vacup"
QT_MOC_LITERAL(138, 1534, 10), // "us4vacdown"
QT_MOC_LITERAL(139, 1545, 9), // "us4flowup"
QT_MOC_LITERAL(140, 1555, 11), // "us4flowdown"
QT_MOC_LITERAL(141, 1567, 7), // "BACKBUT"
QT_MOC_LITERAL(142, 1575, 20), // "us1_linear_nonlinear"
QT_MOC_LITERAL(143, 1596, 20), // "us2_linear_nonlinear"
QT_MOC_LITERAL(144, 1617, 20), // "us3_linear_nonlinear"
QT_MOC_LITERAL(145, 1638, 20), // "us4_linear_nonlinear"
QT_MOC_LITERAL(146, 1659, 20), // "ia1_linear_nonlinear"
QT_MOC_LITERAL(147, 1680, 20), // "ia2_linear_nonlinear"
QT_MOC_LITERAL(148, 1701, 20), // "vit_linear_nonlinear"
QT_MOC_LITERAL(149, 1722, 12), // "pulseup_mode"
QT_MOC_LITERAL(150, 1735, 14), // "pulsedown_mode"
QT_MOC_LITERAL(151, 1750, 15), // "ocuburstup_mode"
QT_MOC_LITERAL(152, 1766, 17), // "ocuburstdown_mode"
QT_MOC_LITERAL(153, 1784, 18), // "singleburstup_mode"
QT_MOC_LITERAL(154, 1803, 20), // "singleburstdown_mode"
QT_MOC_LITERAL(155, 1824, 17), // "multiburstup_mode"
QT_MOC_LITERAL(156, 1842, 19), // "multiburstdown_mode"
QT_MOC_LITERAL(157, 1862, 15), // "ocupulseup_mode"
QT_MOC_LITERAL(158, 1878, 17), // "ocupulsedown_mode"
QT_MOC_LITERAL(159, 1896, 16), // "coldphacoup_mode"
QT_MOC_LITERAL(160, 1913, 18), // "coldphacodown_mode"
QT_MOC_LITERAL(161, 1932, 17), // "coldphaco1up_mode"
QT_MOC_LITERAL(162, 1950, 19), // "coldphaco1down_mode"
QT_MOC_LITERAL(163, 1970, 21), // "updatehandpieceStatus"
QT_MOC_LITERAL(164, 1992, 12), // "updatesensor"
QT_MOC_LITERAL(165, 2005, 21), // "onUpdateStatusTimeout"
QT_MOC_LITERAL(166, 2027, 12), // "updateTimers"
QT_MOC_LITERAL(167, 2040, 19), // "on_us1onoff_clicked"
QT_MOC_LITERAL(168, 2060, 19), // "on_us2onoff_clicked"
QT_MOC_LITERAL(169, 2080, 19), // "on_us3onoff_clicked"
QT_MOC_LITERAL(170, 2100, 19), // "on_us4onoff_clicked"
QT_MOC_LITERAL(171, 2120, 19), // "on_vitonoff_clicked"
QT_MOC_LITERAL(172, 2140, 17), // "doctorwindow_show"
QT_MOC_LITERAL(173, 2158, 11), // "Sugroenname"
QT_MOC_LITERAL(174, 2170, 20), // "footpedalwindow_show"
QT_MOC_LITERAL(175, 2191, 21), // "on_us1vacmode_clicked"
QT_MOC_LITERAL(176, 2213, 21), // "on_us2vacmode_clicked"
QT_MOC_LITERAL(177, 2235, 21), // "on_us3vacmode_clicked"
QT_MOC_LITERAL(178, 2257, 21), // "on_vitvacmode_clicked"
QT_MOC_LITERAL(179, 2279, 21), // "on_us4vacmode_clicked"
QT_MOC_LITERAL(180, 2301, 16), // "on_CI4_2_clicked"
QT_MOC_LITERAL(181, 2318, 25) // "on_SETTINGS_BUT_2_clicked"

    },
    "MainWindow\0sensorValueChanged\0\0value\0"
    "surgeonSelected\0surgeonName\0left_foot\0"
    "right_foot\0bottom_left\0bottom_right\0"
    "con_irrigation\0on\0sendsurgeon\0"
    "onComboBoxIndexChanged\0index\0"
    "onPdmModeSelected\0gpio\0onPdmModeSelected1\0"
    "onPdmModeSelected2\0onPdmModeSelected3\0"
    "updateLineedit\0QLineEdit*\0lineEdit\0"
    "prevValue\0maxValue\0on_clicked\0digit\0"
    "on_clickedenter\0current\0tab\0tabupdate\0"
    "footpedalcheck\0updateElapsedTime\0"
    "updateProgressBar\0motoron\0motoroff\0"
    "motorccwon\0increasebutton\0input\0"
    "decreasebutton\0DIATHERMYBUT\0moved\0"
    "movePushButtonBottomToTop\0footreflux\0"
    "continousirrigation\0poweronoff\0"
    "onCutMode_vitComChanged\0"
    "onCutMode_vitComChanged1\0"
    "onCutMode_vitComChanged2\0"
    "onCutMode_vitComChanged3\0receivecombo\0"
    "text\0performpump\0receiveValues\0"
    "comboBoxValue\0combo\0dia\0us1pow\0us1vac\0"
    "us1asp\0us2pow\0us2vac\0us2asp\0us3pow\0"
    "us3vac\0us3asp\0us4pow\0us4vac\0us4asp\0"
    "ia1vac\0ia1asp\0ia2vac\0ia2asp\0vitcut\0"
    "vitvac\0vitasp\0powmode\0vacmode\0powmethod\0"
    "us2powmode\0us2vacmode\0us2powermethod\0"
    "us3powmode\0us3vacmode\0us3powermethod\0"
    "us4powmode\0us4vacmode\0us4powermethod\0"
    "ia1mode\0ia2mode\0vitmode\0vitvacmode\0"
    "label43\0sensor2\0ULTRASONICBUT1\0"
    "ULTRASONICBUT2\0ULTRASONICBUT4\0"
    "IRRIGATIONBUT1\0IRRIGATIONBUT2\0"
    "VITRECTOMYBUT\0diapowup\0diapowdown\0"
    "vitcutup\0vitcutdown\0vitvacup\0vitvacdown\0"
    "vitflowup\0vitflowdown\0ia2vacup\0"
    "ia2vacdown\0ia2flowup\0ia2flowdown\0"
    "ia1vacup\0ia1vacdown\0ia1flowup\0ia1flowdown\0"
    "US1POWUP\0US1POWDOWN\0US1VACDOWN\0US1VACUP\0"
    "US1FLOWDOWN\0US1FLOWUP\0us2powup\0"
    "us2powdown\0us2vacup\0us2vacdown\0us2flowup\0"
    "us2flowdown\0ULTRASONICBUT3\0us3powup\0"
    "us3powdown\0us3vacup\0us3vacdown\0us3flowup\0"
    "us3flowdown\0us4powup\0us4powdown\0"
    "us4vacup\0us4vacdown\0us4flowup\0us4flowdown\0"
    "BACKBUT\0us1_linear_nonlinear\0"
    "us2_linear_nonlinear\0us3_linear_nonlinear\0"
    "us4_linear_nonlinear\0ia1_linear_nonlinear\0"
    "ia2_linear_nonlinear\0vit_linear_nonlinear\0"
    "pulseup_mode\0pulsedown_mode\0ocuburstup_mode\0"
    "ocuburstdown_mode\0singleburstup_mode\0"
    "singleburstdown_mode\0multiburstup_mode\0"
    "multiburstdown_mode\0ocupulseup_mode\0"
    "ocupulsedown_mode\0coldphacoup_mode\0"
    "coldphacodown_mode\0coldphaco1up_mode\0"
    "coldphaco1down_mode\0updatehandpieceStatus\0"
    "updatesensor\0onUpdateStatusTimeout\0"
    "updateTimers\0on_us1onoff_clicked\0"
    "on_us2onoff_clicked\0on_us3onoff_clicked\0"
    "on_us4onoff_clicked\0on_vitonoff_clicked\0"
    "doctorwindow_show\0Sugroenname\0"
    "footpedalwindow_show\0on_us1vacmode_clicked\0"
    "on_us2vacmode_clicked\0on_us3vacmode_clicked\0"
    "on_vitvacmode_clicked\0on_us4vacmode_clicked\0"
    "on_CI4_2_clicked\0on_SETTINGS_BUT_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     128,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  654,    2, 0x06 /* Public */,
       4,    1,  657,    2, 0x06 /* Public */,
       6,    1,  660,    2, 0x06 /* Public */,
       7,    1,  663,    2, 0x06 /* Public */,
       8,    1,  666,    2, 0x06 /* Public */,
       9,    1,  669,    2, 0x06 /* Public */,
      10,    1,  672,    2, 0x06 /* Public */,
      12,    1,  675,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  678,    2, 0x0a /* Public */,
      15,    1,  681,    2, 0x0a /* Public */,
      17,    1,  684,    2, 0x0a /* Public */,
      18,    1,  687,    2, 0x0a /* Public */,
      19,    1,  690,    2, 0x0a /* Public */,
      20,    4,  693,    2, 0x0a /* Public */,
      25,    1,  702,    2, 0x0a /* Public */,
      27,    0,  705,    2, 0x0a /* Public */,
      28,    1,  706,    2, 0x0a /* Public */,
      30,    1,  709,    2, 0x0a /* Public */,
      31,    0,  712,    2, 0x0a /* Public */,
      32,    0,  713,    2, 0x0a /* Public */,
      33,    0,  714,    2, 0x0a /* Public */,
      34,    1,  715,    2, 0x0a /* Public */,
      35,    0,  718,    2, 0x0a /* Public */,
      36,    0,  719,    2, 0x0a /* Public */,
      37,    1,  720,    2, 0x0a /* Public */,
      39,    1,  723,    2, 0x0a /* Public */,
      40,    0,  726,    2, 0x0a /* Public */,
      41,    1,  727,    2, 0x0a /* Public */,
      42,    1,  730,    2, 0x0a /* Public */,
      43,    1,  733,    2, 0x0a /* Public */,
      44,    1,  736,    2, 0x0a /* Public */,
      45,    1,  739,    2, 0x0a /* Public */,
      46,    1,  742,    2, 0x0a /* Public */,
      47,    1,  745,    2, 0x0a /* Public */,
      48,    1,  748,    2, 0x0a /* Public */,
      49,    1,  751,    2, 0x0a /* Public */,
      50,    1,  754,    2, 0x0a /* Public */,
      52,    1,  757,    2, 0x0a /* Public */,
      53,   38,  760,    2, 0x0a /* Public */,
      92,    0,  837,    2, 0x08 /* Private */,
      93,    0,  838,    2, 0x08 /* Private */,
      94,    0,  839,    2, 0x08 /* Private */,
      95,    0,  840,    2, 0x08 /* Private */,
      96,    0,  841,    2, 0x08 /* Private */,
      97,    0,  842,    2, 0x08 /* Private */,
      98,    0,  843,    2, 0x08 /* Private */,
      99,    0,  844,    2, 0x08 /* Private */,
     100,    0,  845,    2, 0x08 /* Private */,
     101,    0,  846,    2, 0x08 /* Private */,
     102,    0,  847,    2, 0x08 /* Private */,
     103,    0,  848,    2, 0x08 /* Private */,
     104,    0,  849,    2, 0x08 /* Private */,
     105,    0,  850,    2, 0x08 /* Private */,
     106,    0,  851,    2, 0x08 /* Private */,
     107,    0,  852,    2, 0x08 /* Private */,
     108,    0,  853,    2, 0x08 /* Private */,
     109,    0,  854,    2, 0x08 /* Private */,
     110,    0,  855,    2, 0x08 /* Private */,
     111,    0,  856,    2, 0x08 /* Private */,
     112,    0,  857,    2, 0x08 /* Private */,
     113,    0,  858,    2, 0x08 /* Private */,
     114,    0,  859,    2, 0x08 /* Private */,
     115,    0,  860,    2, 0x08 /* Private */,
     116,    0,  861,    2, 0x08 /* Private */,
     117,    0,  862,    2, 0x08 /* Private */,
     118,    0,  863,    2, 0x08 /* Private */,
     119,    0,  864,    2, 0x08 /* Private */,
     120,    0,  865,    2, 0x08 /* Private */,
     121,    0,  866,    2, 0x08 /* Private */,
     122,    0,  867,    2, 0x08 /* Private */,
     123,    0,  868,    2, 0x08 /* Private */,
     124,    0,  869,    2, 0x08 /* Private */,
     125,    0,  870,    2, 0x08 /* Private */,
     126,    0,  871,    2, 0x08 /* Private */,
     127,    0,  872,    2, 0x08 /* Private */,
     128,    0,  873,    2, 0x08 /* Private */,
     129,    0,  874,    2, 0x08 /* Private */,
     130,    0,  875,    2, 0x08 /* Private */,
     131,    0,  876,    2, 0x08 /* Private */,
     132,    0,  877,    2, 0x08 /* Private */,
     133,    0,  878,    2, 0x08 /* Private */,
     134,    0,  879,    2, 0x08 /* Private */,
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
     157,    0,  902,    2, 0x08 /* Private */,
     158,    0,  903,    2, 0x08 /* Private */,
     159,    0,  904,    2, 0x08 /* Private */,
     160,    0,  905,    2, 0x08 /* Private */,
     161,    0,  906,    2, 0x08 /* Private */,
     162,    0,  907,    2, 0x08 /* Private */,
     163,    0,  908,    2, 0x08 /* Private */,
     164,    0,  909,    2, 0x08 /* Private */,
     165,    0,  910,    2, 0x08 /* Private */,
     166,    0,  911,    2, 0x08 /* Private */,
     167,    0,  912,    2, 0x08 /* Private */,
     168,    0,  913,    2, 0x08 /* Private */,
     169,    0,  914,    2, 0x08 /* Private */,
     170,    0,  915,    2, 0x08 /* Private */,
     171,    0,  916,    2, 0x08 /* Private */,
     172,    1,  917,    2, 0x08 /* Private */,
     174,    0,  920,    2, 0x08 /* Private */,
     175,    0,  921,    2, 0x08 /* Private */,
     176,    0,  922,    2, 0x08 /* Private */,
     177,    0,  923,    2, 0x08 /* Private */,
     178,    0,  924,    2, 0x08 /* Private */,
     179,    0,  925,    2, 0x08 /* Private */,
     180,    0,  926,    2, 0x08 /* Private */,
     181,    0,  927,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, 0x80000000 | 21, QMetaType::Int, QMetaType::Int, QMetaType::Int,   22,   23,    3,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   38,
    QMetaType::Int, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,
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
    QMetaType::Void, QMetaType::QString,  173,
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
        case 1: _t->surgeonSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->left_foot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->right_foot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->bottom_left((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->bottom_right((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->con_irrigation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->sendsurgeon((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onComboBoxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onPdmModeSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onPdmModeSelected1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onPdmModeSelected2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->onPdmModeSelected3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->updateLineedit((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 14: _t->on_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_clickedenter(); break;
        case 16: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->tabupdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->footpedalcheck(); break;
        case 19: _t->updateElapsedTime(); break;
        case 20: _t->updateProgressBar(); break;
        case 21: _t->motoron((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 22: _t->motoroff(); break;
        case 23: _t->motorccwon(); break;
        case 24: { int _r = _t->increasebutton((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { int _r = _t->decreasebutton((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->DIATHERMYBUT(); break;
        case 27: _t->moved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->movePushButtonBottomToTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->footreflux((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->continousirrigation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->poweronoff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->onCutMode_vitComChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->onCutMode_vitComChanged1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->onCutMode_vitComChanged2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->onCutMode_vitComChanged3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->receivecombo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 37: _t->performpump((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->receiveValues((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< int(*)>(_a[14])),(*reinterpret_cast< int(*)>(_a[15])),(*reinterpret_cast< int(*)>(_a[16])),(*reinterpret_cast< int(*)>(_a[17])),(*reinterpret_cast< int(*)>(_a[18])),(*reinterpret_cast< int(*)>(_a[19])),(*reinterpret_cast< int(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])),(*reinterpret_cast< int(*)>(_a[22])),(*reinterpret_cast< const QString(*)>(_a[23])),(*reinterpret_cast< const QString(*)>(_a[24])),(*reinterpret_cast< const QString(*)>(_a[25])),(*reinterpret_cast< const QString(*)>(_a[26])),(*reinterpret_cast< const QString(*)>(_a[27])),(*reinterpret_cast< const QString(*)>(_a[28])),(*reinterpret_cast< const QString(*)>(_a[29])),(*reinterpret_cast< const QString(*)>(_a[30])),(*reinterpret_cast< const QString(*)>(_a[31])),(*reinterpret_cast< const QString(*)>(_a[32])),(*reinterpret_cast< const QString(*)>(_a[33])),(*reinterpret_cast< const QString(*)>(_a[34])),(*reinterpret_cast< const QString(*)>(_a[35])),(*reinterpret_cast< const QString(*)>(_a[36])),(*reinterpret_cast< const QString(*)>(_a[37])),(*reinterpret_cast< const QString(*)>(_a[38]))); break;
        case 39: _t->label43(); break;
        case 40: _t->sensor2(); break;
        case 41: _t->ULTRASONICBUT1(); break;
        case 42: _t->ULTRASONICBUT2(); break;
        case 43: _t->ULTRASONICBUT4(); break;
        case 44: _t->IRRIGATIONBUT1(); break;
        case 45: _t->IRRIGATIONBUT2(); break;
        case 46: _t->VITRECTOMYBUT(); break;
        case 47: _t->diapowup(); break;
        case 48: _t->diapowdown(); break;
        case 49: _t->vitcutup(); break;
        case 50: _t->vitcutdown(); break;
        case 51: _t->vitvacup(); break;
        case 52: _t->vitvacdown(); break;
        case 53: _t->vitflowup(); break;
        case 54: _t->vitflowdown(); break;
        case 55: _t->ia2vacup(); break;
        case 56: _t->ia2vacdown(); break;
        case 57: _t->ia2flowup(); break;
        case 58: _t->ia2flowdown(); break;
        case 59: _t->ia1vacup(); break;
        case 60: _t->ia1vacdown(); break;
        case 61: _t->ia1flowup(); break;
        case 62: _t->ia1flowdown(); break;
        case 63: _t->US1POWUP(); break;
        case 64: _t->US1POWDOWN(); break;
        case 65: _t->US1VACDOWN(); break;
        case 66: _t->US1VACUP(); break;
        case 67: _t->US1FLOWDOWN(); break;
        case 68: _t->US1FLOWUP(); break;
        case 69: _t->us2powup(); break;
        case 70: _t->us2powdown(); break;
        case 71: _t->us2vacup(); break;
        case 72: _t->us2vacdown(); break;
        case 73: _t->us2flowup(); break;
        case 74: _t->us2flowdown(); break;
        case 75: _t->ULTRASONICBUT3(); break;
        case 76: _t->us3powup(); break;
        case 77: _t->us3powdown(); break;
        case 78: _t->us3vacup(); break;
        case 79: _t->us3vacdown(); break;
        case 80: _t->us3flowup(); break;
        case 81: _t->us3flowdown(); break;
        case 82: _t->us4powup(); break;
        case 83: _t->us4powdown(); break;
        case 84: _t->us4vacup(); break;
        case 85: _t->us4vacdown(); break;
        case 86: _t->us4flowup(); break;
        case 87: _t->us4flowdown(); break;
        case 88: _t->BACKBUT(); break;
        case 89: _t->us1_linear_nonlinear(); break;
        case 90: _t->us2_linear_nonlinear(); break;
        case 91: _t->us3_linear_nonlinear(); break;
        case 92: _t->us4_linear_nonlinear(); break;
        case 93: _t->ia1_linear_nonlinear(); break;
        case 94: _t->ia2_linear_nonlinear(); break;
        case 95: _t->vit_linear_nonlinear(); break;
        case 96: _t->pulseup_mode(); break;
        case 97: _t->pulsedown_mode(); break;
        case 98: _t->ocuburstup_mode(); break;
        case 99: _t->ocuburstdown_mode(); break;
        case 100: _t->singleburstup_mode(); break;
        case 101: _t->singleburstdown_mode(); break;
        case 102: _t->multiburstup_mode(); break;
        case 103: _t->multiburstdown_mode(); break;
        case 104: _t->ocupulseup_mode(); break;
        case 105: _t->ocupulsedown_mode(); break;
        case 106: _t->coldphacoup_mode(); break;
        case 107: _t->coldphacodown_mode(); break;
        case 108: _t->coldphaco1up_mode(); break;
        case 109: _t->coldphaco1down_mode(); break;
        case 110: _t->updatehandpieceStatus(); break;
        case 111: _t->updatesensor(); break;
        case 112: _t->onUpdateStatusTimeout(); break;
        case 113: _t->updateTimers(); break;
        case 114: _t->on_us1onoff_clicked(); break;
        case 115: _t->on_us2onoff_clicked(); break;
        case 116: _t->on_us3onoff_clicked(); break;
        case 117: _t->on_us4onoff_clicked(); break;
        case 118: _t->on_vitonoff_clicked(); break;
        case 119: _t->doctorwindow_show((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 120: _t->footpedalwindow_show(); break;
        case 121: _t->on_us1vacmode_clicked(); break;
        case 122: _t->on_us2vacmode_clicked(); break;
        case 123: _t->on_us3vacmode_clicked(); break;
        case 124: _t->on_vitvacmode_clicked(); break;
        case 125: _t->on_us4vacmode_clicked(); break;
        case 126: _t->on_CI4_2_clicked(); break;
        case 127: _t->on_SETTINGS_BUT_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 21:
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
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::surgeonSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::left_foot)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::right_foot)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::bottom_left)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::bottom_right)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::con_irrigation)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendsurgeon)) {
                *result = 7;
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
        if (_id < 128)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 128;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 128)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 128;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sensorValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::surgeonSelected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::left_foot(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::right_foot(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::bottom_left(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::bottom_right(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::con_irrigation(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::sendsurgeon(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
