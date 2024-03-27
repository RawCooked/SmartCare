#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "connexion.h"
#include <QCryptographicHash>
#include <QMessageBox>
#include <iostream>
#include "users.h"
using namespace std;
LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_login_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString hashedPasswordHex = QString(hashedPassword.toHex());
    //cout << hashedPasswordHex;
    QSqlQuery query;
        query.prepare("SELECT * FROM users WHERE user_name = :username AND mdp = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", hashedPasswordHex);

        if (query.exec() && query.next()) {
            QMessageBox::information(this, "Login Successful", "Welcome, " + username + "!");
            this->hide();
            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password. Please try again."+hashedPasswordHex);
        }
}

void LoginWindow::on_pushButton_2_clicked()
{
    close();
}
