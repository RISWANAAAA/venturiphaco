#include "footpedal.h"
#include "ui_footpedal.h"
#include <QMessageBox>
#include <QDebug>
#include<QSqlError>

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
updateFootpedalComboBoxes("Surgeon 1");
    // Read GPIO values


    // Set up connections
    setupConnections();

    connect(ui->backbut, &QPushButton::clicked, this, &footpedal::Back);
    connect(ui->savebut, &QPushButton::clicked, this, &footpedal::on_pushButton_clicked);
    QTimer *timer=new QTimer;
    connect(timer,&QTimer::timeout,this,&footpedal::readInitialGPIOValues);
    timer->start(300);
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
    qDebug() << "Initial GPIO 961 Value:" << value1;

    int value2 = readGPIOValue(962);
    qDebug() << "Initial GPIO 962 Value:" << value2;
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
            qDebug() << "Power toggled."<<value1;
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
     qDebug() << "leftFootcomAction value:" << leftFootcomAction;
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
    //bottom right
    if (brightFootcomAction == "Continuous Irrigation") {
        qDebug() << "GPIO 962 - Continuous Irrigation action detected.";
        if (value2 == 0) {
            emit continous_irrigation(value2);
            qDebug() << "GPIO 962 - Continuous Irrigation performed.";
        }
    } else if (brightFootcomAction == "Power ON/OFF") {
        qDebug() << "GPIO 962 - Power ON/OFF action detected.";
        if (value2 == 0) {
            emit togglePower(value2);
            qDebug() << "GPIO 962 - Power toggled." << value2;
        }
    } else if (brightFootcomAction == "Increment") {
        qDebug() << "GPIO 962 - Increment action detected.";
        if (value2 == 0) {
            emit moveTopToBottom(0);
            qDebug() << "GPIO 962 - Button moved from top to bottom.";
        }
    } else if (brightFootcomAction == "Decrement") {
        qDebug() << "GPIO 962 - Decrement action detected.";
        if (value2 == 0) {
            emit moveBottomToTop(value2);
            qDebug() << "GPIO 962 - Button moved from bottom to top.";
        }
    } else if (brightFootcomAction == "PDM") {
        qDebug() << "GPIO 962 - PDM action detected.";
        if (value2 == 0) {
            emit powerdm(value2);
            qDebug() << "GPIO 962 - PDM activated.";
        }
    }
    //topright

    if (rightFootcomAction == "Continuous Irrigation") {
        qDebug() << "GPIO 963 - Continuous Irrigation action detected.";
        if (value3 == 0) {
            emit continous_irrigation(value3);
            qDebug() << "GPIO 963 - Continuous Irrigation performed.";
        }
    } else if (rightFootcomAction == "Power ON/OFF") {
        qDebug() << "GPIO 962 - Power ON/OFF action detected.";
        if (value3 == 0) {
            emit togglePower(value3);
            qDebug() << "GPIO 963 - Power toggled." << value3;
        }
    } else if (rightFootcomAction == "Increment") {
        qDebug() << "GPIO 963 - Increment action detected.";
        if (value3 == 0) {
            emit moveTopToBottom(0);
            qDebug() << "GPIO 963 - Button moved from top to bottom.";
        }
    } else if (rightFootcomAction == "Decrement") {
        qDebug() << "GPIO 963 - Decrement action detected.";
        if (value3 == 0) {
            emit moveBottomToTop(value3);
            qDebug() << "GPIO 963 - Button moved from bottom to top.";
        }
    } else if (rightFootcomAction == "PDM") {
        qDebug() << "GPIO 963 - PDM action detected.";
        if (value3 == 0) {
            emit powerdm(value3);
            qDebug() << "GPIO 963 - PDM activated.";
        }
    }
    //bottom right
    if (bleftFootcomAction == "Continuous Irrigation") {
        qDebug() << "GPIO 964 - Continuous Irrigation action detected.";
        if (value4 == 0) {
            emit continous_irrigation(value4);
            qDebug() << "GPIO 964 - Continuous Irrigation performed.";
        }
    } else if (bleftFootcomAction == "Power ON/OFF") {
        qDebug() << "GPIO 964 - Power ON/OFF action detected.";
        if (value4 == 0) {
            emit togglePower(value4);
            qDebug() << "GPIO 964 - Power toggled." <<value4;
        }
    } else if (bleftFootcomAction == "Increment") {
        qDebug() << "GPIO 964 - Increment action detected.";
        if (value4 == 0) {
            emit moveTopToBottom(0);
            qDebug() << "GPIO 964 - Button moved from top to bottom.";
        }
    } else if (bleftFootcomAction == "Decrement") {
        qDebug() << "GPIO 964 - Decrement action detected.";
        if (value4 == 0) {
            emit moveBottomToTop(value4);
            qDebug() << "GPIO 964 - Button moved from bottom to top.";
        }
    } else if (bleftFootcomAction == "PDM") {
        qDebug() << "GPIO 964 - PDM action detected.";
        if (value4 == 0) {
            emit powerdm(value4);
            qDebug() << "GPIO 964 - PDM activated.";
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
void footpedal::updateFootpedalComboBoxes(const QString &surgeonName) {
    QSqlQuery query(db);
    query.prepare(
        "SELECT footleft, footright, footbottomleft, footbottomright "
        "FROM phacohigh "
        "WHERE surgeon = :surgeon"
    );
    query.bindValue(":surgeon", surgeonName);

    qDebug() << "Selected surgeon in footpedal and fetching data for surgeon:" << surgeonName;

    if (!query.exec()) {
        qDebug() << "Failed to fetch footpedal data for surgeon:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        // Retrieve values from the query result
        QString footLeftValue = query.value("footleft").toString();
        QString footRightValue = query.value("footright").toString();
        QString footBLeftValue = query.value("footbottomleft").toString();
        QString footNRightValue = query.value("footbottomright").toString();

        // Debug output to check retrieved values
        qDebug() << "Foot pedal values retrieved:"
                 << "footleft:" << footLeftValue
                 << "footright:" << footRightValue
                 << "footbleft:" << footBLeftValue
                 << "footnright:" << footNRightValue;

        // Set the retrieved values to the combo boxes
        ui->left_footcom->setCurrentText(footLeftValue);
        ui->right_footcom->setCurrentText(footRightValue);
        ui->bleft_footcom->setCurrentText(footBLeftValue);
        ui->bright_footcom->setCurrentText(footNRightValue);

        // Debug output to confirm the values were set correctly
        qDebug() << "ComboBox values set:"
                 << "left_footcom:" << ui->left_footcom->currentText()
                 << "right_footcom:" << ui->right_footcom->currentText()
                 << "bleft_footcom:" << ui->bleft_footcom->currentText()
                 << "bright_footcom:" << ui->bright_footcom->currentText();
}
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
void footpedal::setSurgeonName(const QString &name) {
    currentSurgeonName = name;
}

void footpedal::on_pushButton_clicked()
{
    if (currentSurgeonName.isEmpty()) {
            qDebug() << "Surgeon name is not set. Cannot save footpedal settings.";
            return;
        }

        QString footLeftValue = ui->left_footcom->currentText();
        QString footRightValue = ui->right_footcom->currentText();
        QString footBLeftValue = ui->bleft_footcom->currentText();
        QString footNRightValue = ui->bright_footcom->currentText();

        qDebug() << "Saving footpedal settings for surgeon:" << currentSurgeonName;
        qDebug() << "footleft:" << footLeftValue << "footright:" << footRightValue;
        qDebug() << "footbleft:" << footBLeftValue << "footnright:" << footNRightValue;

        QSqlQuery query(db);
        query.prepare(
            "UPDATE phacohigh "
            "SET footleft = :footleft, "
            "footright = :footright, "
            "footbottomleft = :footbleft, "
            "footbottomright = :footnright "
            "WHERE surgeon = :surgeon"
        );
        query.bindValue(":footleft", footLeftValue);
        query.bindValue(":footright", footRightValue);
        query.bindValue(":footbleft", footBLeftValue);
        query.bindValue(":footnright", footNRightValue);
        query.bindValue(":surgeon", currentSurgeonName);

        if (!query.exec()) {
            qDebug() << "Failed to update footpedal data for surgeon:" << query.lastError().text();
            return;
        }

        qDebug() << "Footpedal settings saved successfully for surgeon:" << currentSurgeonName;
    readInitialGPIOValues();
    // Perform actions based on the stored combo box values
    performAction(leftFootcomAction, 961);
    performAction(rightFootcomAction, 962);
    performAction(bleftFootcomAction, 963);
    performAction(brightFootcomAction, 964);
}
