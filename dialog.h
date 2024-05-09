#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "captcha.h"
#include <QPaintEvent>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString code;

private:
    Ui::Dialog *ui;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *);
private slots:
    void on_button_clicked();
};

#endif // DIALOG_H
