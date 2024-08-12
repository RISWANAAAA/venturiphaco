#include "footpedal.h"
#include "ui_footpedal.h"
#include <QMessageBox>
#include <QDebug>

footpedal::footpedal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::footpedal)
{
    ui->setupUi(this);
    move(0,0);
    d1 = new doctor;

    // Export and set direction of GPIOs
    exportGPIO(961);
        exportGPIO(962);
        exportGPIO(963);
        exportGPIO(964);

        setGPIODirection(961, "in");
        setGPIODirection(962, "in");
        setGPIODirection(963, "in");
        setGPIODirection(964, "in");

        qDebug() << "GPIO 961 direction set to in";
        qDebug() << "GPIO 962 direction set to in";
        qDebug() << "GPIO 963 direction set to in";
        qDebug() << "GPIO 964 direction set to in";

        readInitialGPIOValues(); // Read initial values

    // Read GPIO values


    // Set up connections
    setupConnections();

    connect(ui->backbut, &QPushButton::clicked, this, &footpedal::Back);
    connect(ui->savebut, &QPushButton::clicked, this, &footpedal::on_pushButton_clicked);
    QTimer *timer=new QTimer;
    connect(timer,&QTimer::timeout,this,&footpedal::readInitialGPIOValues);
    timer->start(1000);
}

footpedal::~footpedal()
{
    delete ui;
}

void footpedal::Back()
{
    this->close();
}

void footpedal::setupConnections()
{
    connect(ui->left_footcom, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
    connect(ui->right_footcom, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
    connect(ui->bleft_footcom, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
    connect(ui->bright_footcom, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &footpedal::storeComboBoxSelection);
}
void footpedal::storeComboBoxSelection(int index)
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
    if (comboBox)
    {
        QString action = comboBox->itemText(index);

        if (comboBox == ui->left_footcom) {
            leftFootcomAction = action;
        } else if (comboBox == ui->right_footcom) {
            rightFootcomAction = action;
        } else if (comboBox == ui->bleft_footcom) {
            bleftFootcomAction = action;
        } else if (comboBox == ui->bright_footcom) {
            brightFootcomAction = action;
        }
    }
}

void footpedal::readInitialGPIOValues()
{
    qDebug() << "readInitialGPIOValues function entered.";

    int value1 = readGPIOValue(961);
    int value2 = readGPIOValue(962);
    int value3 = readGPIOValue(963);
    int value4 = readGPIOValue(964);

    qDebug() << "GPIO 961 value:" << value1;
    qDebug() << "GPIO 962 value:" << value2;
    qDebug() << "GPIO 963 value:" << value3;
    qDebug() << "GPIO 964 value:" << value4;

    qDebug() << "Initial GPIO Values:" << value1 << value2 << value3 << value4;

    if (leftFootcomAction == "Continuous Irrigation") {
        qDebug() << "Continuous Irrigation action detected.";
        if (value1 == 0) {
            emit continous_irrigation(value1);
            qDebug() << "Continuous Irrigation performed.";
        }
    } else if (leftFootcomAction == "Power ON/OFF") {
        qDebug() << "Power ON/OFF action detected.";
        if (value1 == 0) {
            emit togglePower(value1);
            qDebug() << "Power toggled.";
        }
    } else if (leftFootcomAction == "Increment") {
        qDebug() << "Increment action detected.";
        qDebug() << "leftFootcomAction value:" << leftFootcomAction;
        if (value1 == 0) {
      emit moveTopToBottom(0);
            qDebug() << "Button moved from top to bottom.";
        }
    } else if (leftFootcomAction == "Decrement") {
        qDebug() << "Decrement action detected.";

        if (value1 == 0) {
            emit moveBottomToTop(value1);
            qDebug() << "Button moved from bottom to top.";
        }
    } else if (leftFootcomAction == "PDM") {
        qDebug() << "PDM action detected.";
        if (value1 == 0) {
            emit powerdm(value1);
            qDebug() << "PDM activated.";
        }
    }

    // Add similar conditions for other GPIO pins as needed
}



void footpedal::performAction(const QString &action, int gpioNumber)
{
    if (action == "Increment") {
        //emit moveTopToBottom();
        qDebug() << "Increment for GPIO" << gpioNumber;

    } else if (action == "Decrement") {
       // emit moveBottomToTop();
        qDebug() << "Decrement for GPIO" << gpioNumber;
    } else if (action == "Reflux") {
       // emit performReflux();
        qDebug() << "Reflux for GPIO" << gpioNumber;
    } else if (action == "Power On/Off") {
       // emit togglePower();
        qDebug() << "Power On/Off for GPIO" << gpioNumber;
    } else if (action == "PDM") {
       // emit powerdm();
        qDebug() << "PDM for GPIO" << gpioNumber;
    } else if (action == "Continuous Irrigation") {
       // emit continous_irrigation();
        qDebug() << "Continuous Irrigation for GPIO" << gpioNumber;
    }
}

void footpedal::exportGPIO(int gpioNumber)
{
    QFile file("/sys/class/gpio/export");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << gpioNumber;
        file.close();
    }
}

void footpedal::setGPIODirection(int gpioNumber, const QString &direction)
{
    QFile file(QString("/sys/class/gpio/gpio%1/direction").arg(gpioNumber));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << direction;
        file.close();
    }
}

void footpedal::writeGPIOValue(int gpioNumber, int value)
{
    QFile file(QString("/sys/class/gpio/gpio%1/value").arg(gpioNumber));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << value;
        file.close();
    }
}

int footpedal::readGPIOValue(int gpioNumber)
{
    QFile file(QString("/sys/class/gpio/gpio%1/value").arg(gpioNumber));
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        int value;
        stream >> value;
        file.close();
        return value;
    }
    return -1;
}

void footpedal::change_settings()
{
    QString text = ui->left_footcom->currentText();
    if (text == "Increment")
    {
        index = 0;
    }
    else if (text == "Decrement")
    {
        index = 1;
    }
    qDebug() << index;

    //emit cs(index);
}

void footpedal::combobox1(const QString &text)
{
    ui->left_footcom->setCurrentText(text);
}

void footpedal::combobox2(const QString &text)
{
    ui->right_footcom->setCurrentText(text);
}

void footpedal::combobox3(const QString &text)
{
    ui->bleft_footcom->setCurrentText(text);
}

void footpedal::combobox4(const QString &text)
{
    ui->bright_footcom->setCurrentText(text);
}

void footpedal::on_pushButton_clicked()
{
    readInitialGPIOValues();
    // Perform actions based on the stored combo box values
    performAction(leftFootcomAction, 961);
    performAction(rightFootcomAction, 962);
    performAction(bleftFootcomAction, 963);
    performAction(brightFootcomAction, 964);
}
