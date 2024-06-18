#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class keypad;
}

class keypad : public QWidget
{
    Q_OBJECT

public:
    explicit keypad(QWidget *parent = nullptr);
    ~keypad();
    QString digit;
    QString text1;
  //  bool back = false;

signals:
    void textsignal(const QString& digit);
    //void backsignal();
    void entersignal();

private slots:
    void entertext();
    //void enterback();
    void enterenter();






private:
    Ui::keypad *ui;

};

#endif // KEYPAD_H
