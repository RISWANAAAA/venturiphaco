#ifndef TUNING_H
#define TUNING_H

#include <QDialog>
#include<QPainter>
#include<QTimer>
#include<QtMath>
#include"mainwindow.h"
#include"hwhandler.h"
#include"vaccum.h"

#define TUNE_LOWERFREQ_COUNT 2564 //100000/2631=38KHz      100000/2777=36.0KHz
#define TUNE_HIGHFREQ_COUNT 2325  //100000/2272 100000/2380=42KHz      10000/2500 = 40KHz


#define ADS7841_FS_CH0	          0x97		//CH0    0x97
#define ADS7841_SENSOR_CH1         0xD7		//CH1    0xD7
#define ADS7841_CURRENTSENSOR_CH2    0xA7		//CH2    0xA7
#define ADS7841_VOLTAGESENSOR_CH3  0xE7		//CH3    0xE7


#define XPAR_AXI_ADITHYA_0_BASEADDR 0x43C20000
#define XPAR_AXI_SPEAK_0_BASEADDR   0x43C30000


namespace Ui {
class tuning;
}

class tuning : public QDialog
{
    Q_OBJECT

public:
    explicit tuning(QWidget *parent = nullptr);
    ~tuning();
    // Sets the progress value (0-100)
    void setValue(int value);
    void updateCircle();
    void resizeEvent(QResizeEvent *event);
    void exportGPIO(int pin);
    void setGPIODirection(const QString &direction,int pin);
    int readGPIOValue(int pin);
    void updatehandpieceStatus();
    void updateProgress();

void resetState();
int Tune_Phaco();
int ADC_value();
void loose_tip();
public slots:
void on_pushButton_clicked();

protected:
    // Override paintEvent to draw the circular progress bar
    void paintEvent(QPaintEvent *event) override;
    void paintEvent1(QPaintEvent *event);

private slots:

    void on_But_Next_clicked();

    void on_But_Handpiece_clicked();

    void on_But_value_clicked();

signals:
    void sendvisibleisgnale(bool status);
    void sendfreq(int count);
    void activatemain();

private:
    Ui::tuning *ui;
    int m_value=0; // Holds the current value of the progress (0 to 100)
    int m_value1=0; // Holds the current value of the progress (0 to 100)
    int currentCircle;
    QTimer *timer;
     bool isRunning=false;
     QTimer *timer1;
      QColor circleColor; // New member variable for color
      MainWindow *main;
      hwhandler *hand;
      QTimer *handpiece;
      Vaccum *vacSensor;
      bool powerState;
        bool tuneCompleted = false;
      int nADCValue;
        int statushp;

};

#endif // TUNING_H
