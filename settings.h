#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "general.h"
#include "display.h"
#include "footpedal.h"
#include "doctor.h"

class doctor;
class footpedal;

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

private slots:
    void Back();

  //  void Logs();

    void General();

    void Display();

    void Surgeon();

    void Footpedal();

private:
    Ui::settings *ui;
    general *g;
    display *d2;
    doctor *s;
    footpedal *p;
};

#endif // SETTINGS_H
