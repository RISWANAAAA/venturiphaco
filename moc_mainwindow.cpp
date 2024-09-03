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
    QByteArrayData data[196];
    char stringdata0[2579];
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
QT_MOC_LITERAL(10, 111, 22), // "onComboBoxIndexChanged"
QT_MOC_LITERAL(11, 134, 5), // "index"
QT_MOC_LITERAL(12, 140, 17), // "onPdmModeSelected"
QT_MOC_LITERAL(13, 158, 18), // "onPdmModeSelected1"
QT_MOC_LITERAL(14, 177, 18), // "onPdmModeSelected2"
QT_MOC_LITERAL(15, 196, 18), // "onPdmModeSelected3"
QT_MOC_LITERAL(16, 215, 11), // "userMessage"
QT_MOC_LITERAL(17, 227, 8), // "minValue"
QT_MOC_LITERAL(18, 236, 8), // "maxValue"
QT_MOC_LITERAL(19, 245, 14), // "updateLineedit"
QT_MOC_LITERAL(20, 260, 10), // "QLineEdit*"
QT_MOC_LITERAL(21, 271, 8), // "lineEdit"
QT_MOC_LITERAL(22, 280, 9), // "prevValue"
QT_MOC_LITERAL(23, 290, 10), // "on_clicked"
QT_MOC_LITERAL(24, 301, 5), // "digit"
QT_MOC_LITERAL(25, 307, 15), // "on_clickedenter"
QT_MOC_LITERAL(26, 323, 7), // "current"
QT_MOC_LITERAL(27, 331, 3), // "tab"
QT_MOC_LITERAL(28, 335, 10), // "updateline"
QT_MOC_LITERAL(29, 346, 9), // "tabupdate"
QT_MOC_LITERAL(30, 356, 14), // "footpedalcheck"
QT_MOC_LITERAL(31, 371, 17), // "updateElapsedTime"
QT_MOC_LITERAL(32, 389, 17), // "updateProgressBar"
QT_MOC_LITERAL(33, 407, 7), // "motoron"
QT_MOC_LITERAL(34, 415, 8), // "motoroff"
QT_MOC_LITERAL(35, 424, 10), // "motorccwon"
QT_MOC_LITERAL(36, 435, 14), // "increasebutton"
QT_MOC_LITERAL(37, 450, 5), // "input"
QT_MOC_LITERAL(38, 456, 14), // "decreasebutton"
QT_MOC_LITERAL(39, 471, 8), // "powervit"
QT_MOC_LITERAL(40, 480, 10), // "powercheck"
QT_MOC_LITERAL(41, 491, 12), // "DIATHERMYBUT"
QT_MOC_LITERAL(42, 504, 25), // "onMainLineEditTextChanged"
QT_MOC_LITERAL(43, 530, 7), // "dpowmax"
QT_MOC_LITERAL(44, 538, 25), // "movePushButtonTopToBottom"
QT_MOC_LITERAL(45, 564, 25), // "movePushButtonBottomToTop"
QT_MOC_LITERAL(46, 590, 10), // "footreflux"
QT_MOC_LITERAL(47, 601, 19), // "powerdeliverymethod"
QT_MOC_LITERAL(48, 621, 19), // "continousirrigation"
QT_MOC_LITERAL(49, 641, 2), // "on"
QT_MOC_LITERAL(50, 644, 10), // "poweronoff"
QT_MOC_LITERAL(51, 655, 4), // "gpio"
QT_MOC_LITERAL(52, 660, 7), // "poweron"
QT_MOC_LITERAL(53, 668, 23), // "onCutMode_vitComChanged"
QT_MOC_LITERAL(54, 692, 24), // "onCutMode_vitComChanged1"
QT_MOC_LITERAL(55, 717, 24), // "onCutMode_vitComChanged2"
QT_MOC_LITERAL(56, 742, 24), // "onCutMode_vitComChanged3"
QT_MOC_LITERAL(57, 767, 12), // "receivecombo"
QT_MOC_LITERAL(58, 780, 4), // "text"
QT_MOC_LITERAL(59, 785, 11), // "performpump"
QT_MOC_LITERAL(60, 797, 13), // "receiveValues"
QT_MOC_LITERAL(61, 811, 13), // "comboBoxValue"
QT_MOC_LITERAL(62, 825, 5), // "combo"
QT_MOC_LITERAL(63, 831, 3), // "dia"
QT_MOC_LITERAL(64, 835, 6), // "us1pow"
QT_MOC_LITERAL(65, 842, 6), // "us1vac"
QT_MOC_LITERAL(66, 849, 6), // "us1asp"
QT_MOC_LITERAL(67, 856, 6), // "us2pow"
QT_MOC_LITERAL(68, 863, 6), // "us2vac"
QT_MOC_LITERAL(69, 870, 6), // "us2asp"
QT_MOC_LITERAL(70, 877, 6), // "us3pow"
QT_MOC_LITERAL(71, 884, 6), // "us3vac"
QT_MOC_LITERAL(72, 891, 6), // "us3asp"
QT_MOC_LITERAL(73, 898, 6), // "us4pow"
QT_MOC_LITERAL(74, 905, 6), // "us4vac"
QT_MOC_LITERAL(75, 912, 6), // "us4asp"
QT_MOC_LITERAL(76, 919, 6), // "ia1vac"
QT_MOC_LITERAL(77, 926, 6), // "ia1asp"
QT_MOC_LITERAL(78, 933, 6), // "ia2vac"
QT_MOC_LITERAL(79, 940, 6), // "ia2asp"
QT_MOC_LITERAL(80, 947, 6), // "vitcut"
QT_MOC_LITERAL(81, 954, 6), // "vitvac"
QT_MOC_LITERAL(82, 961, 6), // "vitasp"
QT_MOC_LITERAL(83, 968, 7), // "powmode"
QT_MOC_LITERAL(84, 976, 7), // "vacmode"
QT_MOC_LITERAL(85, 984, 9), // "powmethod"
QT_MOC_LITERAL(86, 994, 10), // "us2powmode"
QT_MOC_LITERAL(87, 1005, 10), // "us2vacmode"
QT_MOC_LITERAL(88, 1016, 14), // "us2powermethod"
QT_MOC_LITERAL(89, 1031, 10), // "us3powmode"
QT_MOC_LITERAL(90, 1042, 10), // "us3vacmode"
QT_MOC_LITERAL(91, 1053, 14), // "us3powermethod"
QT_MOC_LITERAL(92, 1068, 10), // "us4powmode"
QT_MOC_LITERAL(93, 1079, 10), // "us4vacmode"
QT_MOC_LITERAL(94, 1090, 14), // "us4powermethod"
QT_MOC_LITERAL(95, 1105, 7), // "ia1mode"
QT_MOC_LITERAL(96, 1113, 7), // "ia2mode"
QT_MOC_LITERAL(97, 1121, 7), // "vitmode"
QT_MOC_LITERAL(98, 1129, 10), // "vitvacmode"
QT_MOC_LITERAL(99, 1140, 7), // "label43"
QT_MOC_LITERAL(100, 1148, 7), // "sensor2"
QT_MOC_LITERAL(101, 1156, 14), // "ULTRASONICBUT1"
QT_MOC_LITERAL(102, 1171, 14), // "ULTRASONICBUT2"
QT_MOC_LITERAL(103, 1186, 14), // "ULTRASONICBUT4"
QT_MOC_LITERAL(104, 1201, 14), // "IRRIGATIONBUT1"
QT_MOC_LITERAL(105, 1216, 14), // "IRRIGATIONBUT2"
QT_MOC_LITERAL(106, 1231, 13), // "VITRECTOMYBUT"
QT_MOC_LITERAL(107, 1245, 8), // "diapowup"
QT_MOC_LITERAL(108, 1254, 10), // "diapowdown"
QT_MOC_LITERAL(109, 1265, 8), // "vitcutup"
QT_MOC_LITERAL(110, 1274, 10), // "vitcutdown"
QT_MOC_LITERAL(111, 1285, 8), // "vitvacup"
QT_MOC_LITERAL(112, 1294, 10), // "vitvacdown"
QT_MOC_LITERAL(113, 1305, 9), // "vitflowup"
QT_MOC_LITERAL(114, 1315, 11), // "vitflowdown"
QT_MOC_LITERAL(115, 1327, 8), // "ia2vacup"
QT_MOC_LITERAL(116, 1336, 10), // "ia2vacdown"
QT_MOC_LITERAL(117, 1347, 9), // "ia2flowup"
QT_MOC_LITERAL(118, 1357, 11), // "ia2flowdown"
QT_MOC_LITERAL(119, 1369, 8), // "ia1vacup"
QT_MOC_LITERAL(120, 1378, 10), // "ia1vacdown"
QT_MOC_LITERAL(121, 1389, 9), // "ia1flowup"
QT_MOC_LITERAL(122, 1399, 11), // "ia1flowdown"
QT_MOC_LITERAL(123, 1411, 8), // "US1POWUP"
QT_MOC_LITERAL(124, 1420, 10), // "US1POWDOWN"
QT_MOC_LITERAL(125, 1431, 10), // "US1VACDOWN"
QT_MOC_LITERAL(126, 1442, 8), // "US1VACUP"
QT_MOC_LITERAL(127, 1451, 11), // "US1FLOWDOWN"
QT_MOC_LITERAL(128, 1463, 9), // "US1FLOWUP"
QT_MOC_LITERAL(129, 1473, 8), // "us2powup"
QT_MOC_LITERAL(130, 1482, 10), // "us2powdown"
QT_MOC_LITERAL(131, 1493, 8), // "us2vacup"
QT_MOC_LITERAL(132, 1502, 10), // "us2vacdown"
QT_MOC_LITERAL(133, 1513, 9), // "us2flowup"
QT_MOC_LITERAL(134, 1523, 11), // "us2flowdown"
QT_MOC_LITERAL(135, 1535, 14), // "ULTRASONICBUT3"
QT_MOC_LITERAL(136, 1550, 8), // "us3powup"
QT_MOC_LITERAL(137, 1559, 10), // "us3powdown"
QT_MOC_LITERAL(138, 1570, 8), // "us3vacup"
QT_MOC_LITERAL(139, 1579, 10), // "us3vacdown"
QT_MOC_LITERAL(140, 1590, 9), // "us3flowup"
QT_MOC_LITERAL(141, 1600, 11), // "us3flowdown"
QT_MOC_LITERAL(142, 1612, 8), // "us4powup"
QT_MOC_LITERAL(143, 1621, 10), // "us4powdown"
QT_MOC_LITERAL(144, 1632, 8), // "us4vacup"
QT_MOC_LITERAL(145, 1641, 10), // "us4vacdown"
QT_MOC_LITERAL(146, 1652, 9), // "us4flowup"
QT_MOC_LITERAL(147, 1662, 11), // "us4flowdown"
QT_MOC_LITERAL(148, 1674, 11), // "SETTINGSBUT"
QT_MOC_LITERAL(149, 1686, 7), // "BACKBUT"
QT_MOC_LITERAL(150, 1694, 20), // "us1_linear_nonlinear"
QT_MOC_LITERAL(151, 1715, 20), // "us2_linear_nonlinear"
QT_MOC_LITERAL(152, 1736, 20), // "us3_linear_nonlinear"
QT_MOC_LITERAL(153, 1757, 20), // "us4_linear_nonlinear"
QT_MOC_LITERAL(154, 1778, 20), // "ia1_linear_nonlinear"
QT_MOC_LITERAL(155, 1799, 20), // "ia2_linear_nonlinear"
QT_MOC_LITERAL(156, 1820, 20), // "vit_linear_nonlinear"
QT_MOC_LITERAL(157, 1841, 12), // "pulseup_mode"
QT_MOC_LITERAL(158, 1854, 14), // "pulsedown_mode"
QT_MOC_LITERAL(159, 1869, 15), // "ocuburstup_mode"
QT_MOC_LITERAL(160, 1885, 17), // "ocuburstdown_mode"
QT_MOC_LITERAL(161, 1903, 18), // "singleburstup_mode"
QT_MOC_LITERAL(162, 1922, 20), // "singleburstdown_mode"
QT_MOC_LITERAL(163, 1943, 17), // "multiburstup_mode"
QT_MOC_LITERAL(164, 1961, 19), // "multiburstdown_mode"
QT_MOC_LITERAL(165, 1981, 15), // "ocupulseup_mode"
QT_MOC_LITERAL(166, 1997, 17), // "ocupulsedown_mode"
QT_MOC_LITERAL(167, 2015, 16), // "coldphacoup_mode"
QT_MOC_LITERAL(168, 2032, 18), // "coldphacodown_mode"
QT_MOC_LITERAL(169, 2051, 17), // "coldphaco1up_mode"
QT_MOC_LITERAL(170, 2069, 19), // "coldphaco1down_mode"
QT_MOC_LITERAL(171, 2089, 21), // "updatehandpieceStatus"
QT_MOC_LITERAL(172, 2111, 12), // "updatesensor"
QT_MOC_LITERAL(173, 2124, 21), // "onUpdateStatusTimeout"
QT_MOC_LITERAL(174, 2146, 12), // "updateTimers"
QT_MOC_LITERAL(175, 2159, 15), // "settings_action"
QT_MOC_LITERAL(176, 2175, 19), // "on_us1onoff_clicked"
QT_MOC_LITERAL(177, 2195, 19), // "on_us2onoff_clicked"
QT_MOC_LITERAL(178, 2215, 19), // "on_us3onoff_clicked"
QT_MOC_LITERAL(179, 2235, 19), // "on_us4onoff_clicked"
QT_MOC_LITERAL(180, 2255, 19), // "on_vitonoff_clicked"
QT_MOC_LITERAL(181, 2275, 17), // "doctorwindow_show"
QT_MOC_LITERAL(182, 2293, 20), // "footpedalwindow_show"
QT_MOC_LITERAL(183, 2314, 21), // "on_us1vacmode_clicked"
QT_MOC_LITERAL(184, 2336, 21), // "on_us2vacmode_clicked"
QT_MOC_LITERAL(185, 2358, 21), // "on_us3vacmode_clicked"
QT_MOC_LITERAL(186, 2380, 21), // "on_vitvacmode_clicked"
QT_MOC_LITERAL(187, 2402, 21), // "on_us4vacmode_clicked"
QT_MOC_LITERAL(188, 2424, 15), // "updateComboBox1"
QT_MOC_LITERAL(189, 2440, 15), // "updateComboBox2"
QT_MOC_LITERAL(190, 2456, 15), // "updateComboBox3"
QT_MOC_LITERAL(191, 2472, 15), // "updateComboBox4"
QT_MOC_LITERAL(192, 2488, 21), // "updateButtonSelection"
QT_MOC_LITERAL(193, 2510, 16), // "on_CI4_2_clicked"
QT_MOC_LITERAL(194, 2527, 25), // "on_SETTINGS_BUT_2_clicked"
QT_MOC_LITERAL(195, 2553, 25) // "onSurgeonSelectionChanged"

    },
    "MainWindow\0sensorValueChanged\0\0value\0"
    "surgeonSelected\0surgeonName\0left_foot\0"
    "right_foot\0bottom_left\0bottom_right\0"
    "onComboBoxIndexChanged\0index\0"
    "onPdmModeSelected\0onPdmModeSelected1\0"
    "onPdmModeSelected2\0onPdmModeSelected3\0"
    "userMessage\0minValue\0maxValue\0"
    "updateLineedit\0QLineEdit*\0lineEdit\0"
    "prevValue\0on_clicked\0digit\0on_clickedenter\0"
    "current\0tab\0updateline\0tabupdate\0"
    "footpedalcheck\0updateElapsedTime\0"
    "updateProgressBar\0motoron\0motoroff\0"
    "motorccwon\0increasebutton\0input\0"
    "decreasebutton\0powervit\0powercheck\0"
    "DIATHERMYBUT\0onMainLineEditTextChanged\0"
    "dpowmax\0movePushButtonTopToBottom\0"
    "movePushButtonBottomToTop\0footreflux\0"
    "powerdeliverymethod\0continousirrigation\0"
    "on\0poweronoff\0gpio\0poweron\0"
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
    "SETTINGSBUT\0BACKBUT\0us1_linear_nonlinear\0"
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
    "updateTimers\0settings_action\0"
    "on_us1onoff_clicked\0on_us2onoff_clicked\0"
    "on_us3onoff_clicked\0on_us4onoff_clicked\0"
    "on_vitonoff_clicked\0doctorwindow_show\0"
    "footpedalwindow_show\0on_us1vacmode_clicked\0"
    "on_us2vacmode_clicked\0on_us3vacmode_clicked\0"
    "on_vitvacmode_clicked\0on_us4vacmode_clicked\0"
    "updateComboBox1\0updateComboBox2\0"
    "updateComboBox3\0updateComboBox4\0"
    "updateButtonSelection\0on_CI4_2_clicked\0"
    "on_SETTINGS_BUT_2_clicked\0"
    "onSurgeonSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     141,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  719,    2, 0x06 /* Public */,
       4,    1,  722,    2, 0x06 /* Public */,
       6,    1,  725,    2, 0x06 /* Public */,
       7,    1,  728,    2, 0x06 /* Public */,
       8,    1,  731,    2, 0x06 /* Public */,
       9,    1,  734,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  737,    2, 0x0a /* Public */,
      12,    0,  740,    2, 0x0a /* Public */,
      13,    0,  741,    2, 0x0a /* Public */,
      14,    0,  742,    2, 0x0a /* Public */,
      15,    0,  743,    2, 0x0a /* Public */,
      16,    3,  744,    2, 0x0a /* Public */,
      19,    4,  751,    2, 0x0a /* Public */,
      23,    1,  760,    2, 0x0a /* Public */,
      25,    0,  763,    2, 0x0a /* Public */,
      26,    1,  764,    2, 0x0a /* Public */,
      28,    0,  767,    2, 0x0a /* Public */,
      29,    1,  768,    2, 0x0a /* Public */,
      30,    0,  771,    2, 0x0a /* Public */,
      31,    0,  772,    2, 0x0a /* Public */,
      32,    0,  773,    2, 0x0a /* Public */,
      33,    1,  774,    2, 0x0a /* Public */,
      34,    0,  777,    2, 0x0a /* Public */,
      35,    0,  778,    2, 0x0a /* Public */,
      36,    1,  779,    2, 0x0a /* Public */,
      38,    1,  782,    2, 0x0a /* Public */,
      39,    0,  785,    2, 0x0a /* Public */,
      40,    0,  786,    2, 0x0a /* Public */,
      41,    0,  787,    2, 0x0a /* Public */,
      42,    1,  788,    2, 0x0a /* Public */,
      44,    0,  791,    2, 0x0a /* Public */,
      45,    0,  792,    2, 0x0a /* Public */,
      46,    0,  793,    2, 0x0a /* Public */,
      47,    0,  794,    2, 0x0a /* Public */,
      48,    1,  795,    2, 0x0a /* Public */,
      50,    1,  798,    2, 0x0a /* Public */,
      52,    0,  801,    2, 0x0a /* Public */,
      53,    1,  802,    2, 0x0a /* Public */,
      54,    1,  805,    2, 0x0a /* Public */,
      55,    1,  808,    2, 0x0a /* Public */,
      56,    1,  811,    2, 0x0a /* Public */,
      57,    1,  814,    2, 0x0a /* Public */,
      59,    1,  817,    2, 0x0a /* Public */,
      60,   38,  820,    2, 0x0a /* Public */,
      99,    0,  897,    2, 0x08 /* Private */,
     100,    0,  898,    2, 0x08 /* Private */,
     101,    0,  899,    2, 0x08 /* Private */,
     102,    0,  900,    2, 0x08 /* Private */,
     103,    0,  901,    2, 0x08 /* Private */,
     104,    0,  902,    2, 0x08 /* Private */,
     105,    0,  903,    2, 0x08 /* Private */,
     106,    0,  904,    2, 0x08 /* Private */,
     107,    0,  905,    2, 0x08 /* Private */,
     108,    0,  906,    2, 0x08 /* Private */,
     109,    0,  907,    2, 0x08 /* Private */,
     110,    0,  908,    2, 0x08 /* Private */,
     111,    0,  909,    2, 0x08 /* Private */,
     112,    0,  910,    2, 0x08 /* Private */,
     113,    0,  911,    2, 0x08 /* Private */,
     114,    0,  912,    2, 0x08 /* Private */,
     115,    0,  913,    2, 0x08 /* Private */,
     116,    0,  914,    2, 0x08 /* Private */,
     117,    0,  915,    2, 0x08 /* Private */,
     118,    0,  916,    2, 0x08 /* Private */,
     119,    0,  917,    2, 0x08 /* Private */,
     120,    0,  918,    2, 0x08 /* Private */,
     121,    0,  919,    2, 0x08 /* Private */,
     122,    0,  920,    2, 0x08 /* Private */,
     123,    0,  921,    2, 0x08 /* Private */,
     124,    0,  922,    2, 0x08 /* Private */,
     125,    0,  923,    2, 0x08 /* Private */,
     126,    0,  924,    2, 0x08 /* Private */,
     127,    0,  925,    2, 0x08 /* Private */,
     128,    0,  926,    2, 0x08 /* Private */,
     129,    0,  927,    2, 0x08 /* Private */,
     130,    0,  928,    2, 0x08 /* Private */,
     131,    0,  929,    2, 0x08 /* Private */,
     132,    0,  930,    2, 0x08 /* Private */,
     133,    0,  931,    2, 0x08 /* Private */,
     134,    0,  932,    2, 0x08 /* Private */,
     135,    0,  933,    2, 0x08 /* Private */,
     136,    0,  934,    2, 0x08 /* Private */,
     137,    0,  935,    2, 0x08 /* Private */,
     138,    0,  936,    2, 0x08 /* Private */,
     139,    0,  937,    2, 0x08 /* Private */,
     140,    0,  938,    2, 0x08 /* Private */,
     141,    0,  939,    2, 0x08 /* Private */,
     142,    0,  940,    2, 0x08 /* Private */,
     143,    0,  941,    2, 0x08 /* Private */,
     144,    0,  942,    2, 0x08 /* Private */,
     145,    0,  943,    2, 0x08 /* Private */,
     146,    0,  944,    2, 0x08 /* Private */,
     147,    0,  945,    2, 0x08 /* Private */,
     148,    0,  946,    2, 0x08 /* Private */,
     149,    0,  947,    2, 0x08 /* Private */,
     150,    0,  948,    2, 0x08 /* Private */,
     151,    0,  949,    2, 0x08 /* Private */,
     152,    0,  950,    2, 0x08 /* Private */,
     153,    0,  951,    2, 0x08 /* Private */,
     154,    0,  952,    2, 0x08 /* Private */,
     155,    0,  953,    2, 0x08 /* Private */,
     156,    0,  954,    2, 0x08 /* Private */,
     157,    0,  955,    2, 0x08 /* Private */,
     158,    0,  956,    2, 0x08 /* Private */,
     159,    0,  957,    2, 0x08 /* Private */,
     160,    0,  958,    2, 0x08 /* Private */,
     161,    0,  959,    2, 0x08 /* Private */,
     162,    0,  960,    2, 0x08 /* Private */,
     163,    0,  961,    2, 0x08 /* Private */,
     164,    0,  962,    2, 0x08 /* Private */,
     165,    0,  963,    2, 0x08 /* Private */,
     166,    0,  964,    2, 0x08 /* Private */,
     167,    0,  965,    2, 0x08 /* Private */,
     168,    0,  966,    2, 0x08 /* Private */,
     169,    0,  967,    2, 0x08 /* Private */,
     170,    0,  968,    2, 0x08 /* Private */,
     171,    0,  969,    2, 0x08 /* Private */,
     172,    0,  970,    2, 0x08 /* Private */,
     173,    0,  971,    2, 0x08 /* Private */,
     174,    0,  972,    2, 0x08 /* Private */,
     175,    1,  973,    2, 0x08 /* Private */,
     176,    0,  976,    2, 0x08 /* Private */,
     177,    0,  977,    2, 0x08 /* Private */,
     178,    0,  978,    2, 0x08 /* Private */,
     179,    0,  979,    2, 0x08 /* Private */,
     180,    0,  980,    2, 0x08 /* Private */,
     181,    0,  981,    2, 0x08 /* Private */,
     182,    0,  982,    2, 0x08 /* Private */,
     183,    0,  983,    2, 0x08 /* Private */,
     184,    0,  984,    2, 0x08 /* Private */,
     185,    0,  985,    2, 0x08 /* Private */,
     186,    0,  986,    2, 0x08 /* Private */,
     187,    0,  987,    2, 0x08 /* Private */,
     188,    1,  988,    2, 0x08 /* Private */,
     189,    1,  991,    2, 0x08 /* Private */,
     190,    1,  994,    2, 0x08 /* Private */,
     191,    1,  997,    2, 0x08 /* Private */,
     192,    1, 1000,    2, 0x08 /* Private */,
     193,    0, 1003,    2, 0x08 /* Private */,
     194,    0, 1004,    2, 0x08 /* Private */,
     195,    1, 1005,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   17,   18,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Int, QMetaType::Int, QMetaType::Int,   21,   22,    3,   18,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   37,
    QMetaType::Int, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
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
    QMetaType::Void, QMetaType::Int,   11,
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
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

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
        case 6: _t->onComboBoxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onPdmModeSelected(); break;
        case 8: _t->onPdmModeSelected1(); break;
        case 9: _t->onPdmModeSelected2(); break;
        case 10: _t->onPdmModeSelected3(); break;
        case 11: _t->userMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->updateLineedit((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 13: _t->on_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_clickedenter(); break;
        case 15: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->updateline(); break;
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
        case 26: _t->powervit(); break;
        case 27: _t->powercheck(); break;
        case 28: _t->DIATHERMYBUT(); break;
        case 29: _t->onMainLineEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->movePushButtonTopToBottom(); break;
        case 31: _t->movePushButtonBottomToTop(); break;
        case 32: _t->footreflux(); break;
        case 33: _t->powerdeliverymethod(); break;
        case 34: _t->continousirrigation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->poweronoff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->poweron(); break;
        case 37: _t->onCutMode_vitComChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->onCutMode_vitComChanged1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->onCutMode_vitComChanged2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->onCutMode_vitComChanged3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->receivecombo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->performpump((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->receiveValues((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< int(*)>(_a[14])),(*reinterpret_cast< int(*)>(_a[15])),(*reinterpret_cast< int(*)>(_a[16])),(*reinterpret_cast< int(*)>(_a[17])),(*reinterpret_cast< int(*)>(_a[18])),(*reinterpret_cast< int(*)>(_a[19])),(*reinterpret_cast< int(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])),(*reinterpret_cast< int(*)>(_a[22])),(*reinterpret_cast< const QString(*)>(_a[23])),(*reinterpret_cast< const QString(*)>(_a[24])),(*reinterpret_cast< const QString(*)>(_a[25])),(*reinterpret_cast< const QString(*)>(_a[26])),(*reinterpret_cast< const QString(*)>(_a[27])),(*reinterpret_cast< const QString(*)>(_a[28])),(*reinterpret_cast< const QString(*)>(_a[29])),(*reinterpret_cast< const QString(*)>(_a[30])),(*reinterpret_cast< const QString(*)>(_a[31])),(*reinterpret_cast< const QString(*)>(_a[32])),(*reinterpret_cast< const QString(*)>(_a[33])),(*reinterpret_cast< const QString(*)>(_a[34])),(*reinterpret_cast< const QString(*)>(_a[35])),(*reinterpret_cast< const QString(*)>(_a[36])),(*reinterpret_cast< const QString(*)>(_a[37])),(*reinterpret_cast< const QString(*)>(_a[38]))); break;
        case 44: _t->label43(); break;
        case 45: _t->sensor2(); break;
        case 46: _t->ULTRASONICBUT1(); break;
        case 47: _t->ULTRASONICBUT2(); break;
        case 48: _t->ULTRASONICBUT4(); break;
        case 49: _t->IRRIGATIONBUT1(); break;
        case 50: _t->IRRIGATIONBUT2(); break;
        case 51: _t->VITRECTOMYBUT(); break;
        case 52: _t->diapowup(); break;
        case 53: _t->diapowdown(); break;
        case 54: _t->vitcutup(); break;
        case 55: _t->vitcutdown(); break;
        case 56: _t->vitvacup(); break;
        case 57: _t->vitvacdown(); break;
        case 58: _t->vitflowup(); break;
        case 59: _t->vitflowdown(); break;
        case 60: _t->ia2vacup(); break;
        case 61: _t->ia2vacdown(); break;
        case 62: _t->ia2flowup(); break;
        case 63: _t->ia2flowdown(); break;
        case 64: _t->ia1vacup(); break;
        case 65: _t->ia1vacdown(); break;
        case 66: _t->ia1flowup(); break;
        case 67: _t->ia1flowdown(); break;
        case 68: _t->US1POWUP(); break;
        case 69: _t->US1POWDOWN(); break;
        case 70: _t->US1VACDOWN(); break;
        case 71: _t->US1VACUP(); break;
        case 72: _t->US1FLOWDOWN(); break;
        case 73: _t->US1FLOWUP(); break;
        case 74: _t->us2powup(); break;
        case 75: _t->us2powdown(); break;
        case 76: _t->us2vacup(); break;
        case 77: _t->us2vacdown(); break;
        case 78: _t->us2flowup(); break;
        case 79: _t->us2flowdown(); break;
        case 80: _t->ULTRASONICBUT3(); break;
        case 81: _t->us3powup(); break;
        case 82: _t->us3powdown(); break;
        case 83: _t->us3vacup(); break;
        case 84: _t->us3vacdown(); break;
        case 85: _t->us3flowup(); break;
        case 86: _t->us3flowdown(); break;
        case 87: _t->us4powup(); break;
        case 88: _t->us4powdown(); break;
        case 89: _t->us4vacup(); break;
        case 90: _t->us4vacdown(); break;
        case 91: _t->us4flowup(); break;
        case 92: _t->us4flowdown(); break;
        case 93: _t->SETTINGSBUT(); break;
        case 94: _t->BACKBUT(); break;
        case 95: _t->us1_linear_nonlinear(); break;
        case 96: _t->us2_linear_nonlinear(); break;
        case 97: _t->us3_linear_nonlinear(); break;
        case 98: _t->us4_linear_nonlinear(); break;
        case 99: _t->ia1_linear_nonlinear(); break;
        case 100: _t->ia2_linear_nonlinear(); break;
        case 101: _t->vit_linear_nonlinear(); break;
        case 102: _t->pulseup_mode(); break;
        case 103: _t->pulsedown_mode(); break;
        case 104: _t->ocuburstup_mode(); break;
        case 105: _t->ocuburstdown_mode(); break;
        case 106: _t->singleburstup_mode(); break;
        case 107: _t->singleburstdown_mode(); break;
        case 108: _t->multiburstup_mode(); break;
        case 109: _t->multiburstdown_mode(); break;
        case 110: _t->ocupulseup_mode(); break;
        case 111: _t->ocupulsedown_mode(); break;
        case 112: _t->coldphacoup_mode(); break;
        case 113: _t->coldphacodown_mode(); break;
        case 114: _t->coldphaco1up_mode(); break;
        case 115: _t->coldphaco1down_mode(); break;
        case 116: _t->updatehandpieceStatus(); break;
        case 117: _t->updatesensor(); break;
        case 118: _t->onUpdateStatusTimeout(); break;
        case 119: _t->updateTimers(); break;
        case 120: _t->settings_action((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 121: _t->on_us1onoff_clicked(); break;
        case 122: _t->on_us2onoff_clicked(); break;
        case 123: _t->on_us3onoff_clicked(); break;
        case 124: _t->on_us4onoff_clicked(); break;
        case 125: _t->on_vitonoff_clicked(); break;
        case 126: _t->doctorwindow_show(); break;
        case 127: _t->footpedalwindow_show(); break;
        case 128: _t->on_us1vacmode_clicked(); break;
        case 129: _t->on_us2vacmode_clicked(); break;
        case 130: _t->on_us3vacmode_clicked(); break;
        case 131: _t->on_vitvacmode_clicked(); break;
        case 132: _t->on_us4vacmode_clicked(); break;
        case 133: _t->updateComboBox1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 134: _t->updateComboBox2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 135: _t->updateComboBox3((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 136: _t->updateComboBox4((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 137: _t->updateButtonSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 138: _t->on_CI4_2_clicked(); break;
        case 139: _t->on_SETTINGS_BUT_2_clicked(); break;
        case 140: _t->onSurgeonSelectionChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
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
        if (_id < 141)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 141;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 141)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 141;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
