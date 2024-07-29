#ifndef ANOTHER_H
#define ANOTHER_H

#include <QDialog>
#include <QPainter>
#include <QPen>


namespace Ui {
class another;
}

class another : public QDialog
{
    Q_OBJECT

public:
    explicit another(QWidget *parent = nullptr);
    ~another();

    void setValue(int value);
    void setValue1(int value);
    void setValue2(int value);

protected:
    void paintEvent(QPaintEvent *event) override;




private:
    Ui::another *ui;
    int m_value;
    int m_value1;
    int m_value2;
};

#endif // ANOTHER_H
