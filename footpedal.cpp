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
    exportGPIO(961);
    exportGPIO(962);
    exportGPIO(963);
    exportGPIO(964);

    setGPIODirection(961,"in");
    setGPIODirection(962,"in");
    setGPIODirection(963,"in");
    setGPIODirection(964,"in");

    setupConnections();

    connect(ui->backbut, &QPushButton::clicked, this, &footpedal::Back);
    connect(ui->savebut, &QPushButton::clicked, this, &footpedal::SaveForAll);

    QStringList options = {"Increment", "Decrement", "Reflux", "Continuous Irrigation", "PDM", "Power On/Off"};
    ui->left_footcom->addItems(options);
    ui->right_footcom->addItems(options);
    ui->bleft_footcom->addItems(options);
    ui->bright_footcom->addItems(options);
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

void footpedal::SaveForAll()
{
    d1->IASaveBut();
    QMessageBox::information(nullptr, "Info", "Saved Successfully");


}

void footpedal::performAction(const QString &action, int gpioNumber)
{
    if (action == "Increment") {
        emit moveTopToBottom();
        qDebug() << "Increment for GPIO" << gpioNumber;
    } else if (action == "Decrement") {
        emit moveBottomToTop();
        qDebug() << "Decrement for GPIO" << gpioNumber;
    } else if (action == "Reflux") {
        emit performReflux();
        qDebug() << "Reflux for GPIO" << gpioNumber;
    } else if (action == "Power On/Off") {
        emit togglePower();
        qDebug() << "Power On/Off for GPIO" << gpioNumber;
    } else if (action == "PDM") {
        emit powerdm();
        qDebug() << "PDM for GPIO" << gpioNumber;
    } else if (action == "Continuous Irrigation") {
        emit continous_irrigation();
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
    // Perform actions based on the stored combo box values
    performAction(leftFootcomAction, 961);
    performAction(rightFootcomAction, 962);
    performAction(bleftFootcomAction, 963);
    performAction(brightFootcomAction, 964);
}
