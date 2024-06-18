#ifndef LEARNER_H
#define LEARNER_H

#include <QDialog>

namespace Ui {
class learner;
}

class learner : public QDialog
{
    Q_OBJECT

public:
    explicit learner(QWidget *parent = nullptr);
    ~learner();

private:
    Ui::learner *ui;
};

#endif // LEARNER_H
