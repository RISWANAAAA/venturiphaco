#ifndef FOOTPEDAL_H
#define FOOTPEDAL_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "doctor.h"
#include"mainwindow.h"

#define PATH "phaco1.db"

class doctor;
class MainWindow;


namespace Ui {
class footpedal;
}

class footpedal : public QDialog
{
    Q_OBJECT

public:
    explicit footpedal(QWidget *parent = nullptr);
    ~footpedal();

    void createAndSetupComboBoxes();
        void setupConnections();

          void exportGPIO(int gpioNumber);
          void setGPIODirection(int gpioNumber, const QString &direction);
          void writeGPIOValue(int gpioNumber, int value);
          int readGPIOValue(int gpioNumber);
          void change_settings();
            void performAction(const QString &action, int gpioNumber);
public slots:
            void combobox1(const QString &text);
            void combobox2(const QString &text);
            void combobox3(const QString &text);
            void combobox4(const QString &text);
            void storeComboBoxSelection(int index);


signals:
    void moveTopToBottom();    // Signal for moving pushbutton from top to bottom
    void moveBottomToTop();    // Signal for moving pushbutton from bottom to top
    void performReflux();      // Signal for performing reflux action
    void togglePower();        // Signal for toggling power on/off

    void continous_irrigation();
    void powerdm();

private slots:
    void Back();

// void handleComboBoxChange(int index);
    void SaveForAll();






  //  void on_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::footpedal *ui;
    QString left;
    QString right;
    QString bleft;
    QString bright;
    doctor *d1;
    int pinTopLeft;
       int pinTopRight;
       int pinBottomLeft;
       int pinBottomRight;
       int index;
        int gpioNumber;
        MainWindow *m;
        QString leftFootcomAction;
           QString rightFootcomAction;
           QString bleftFootcomAction;
           QString brightFootcomAction;

};

#endif // FOOTPEDAL_H
