#include "mail.h"
#include "ui_mail.h"
#include "smtp.h"

mail::mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mail)
{
    ui->setupUi(this);
}

mail::~mail()
{
    delete ui;
}

void mail::on_exitBtn_clicked()
{
    close();
}

void mail::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
