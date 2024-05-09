#include "dialog.h"
#include "ui_dialog.h"
#include <QPainterPath>
#include <QPainter>
#include <QtMath>
#include <QMessageBox>
#include <iostream>
#include <QLabel>
using namespace std;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Captcha cp;
    cp.randomize();
    cp.setDifficulty(3);
    cp.loadDictionary("C:/Users/pc/Desktop/Nouveau dossier (3)/QtCaptcha-master/dictionary.txt");
    cp.setTextGeneration(Captcha::TextGeneration_Dictionary);
    cp.generateText();
    code=cp.captchaText();
    ui->label->setText(code);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //painter.drawImage(30, 30, cp.captchaImage());



}
   /* void Dialog::paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        Captcha cp;
        cp.randomize();
        cp.setDifficulty(3);
        cp.generateText();
        painter.drawImage(30, 30, cp.captchaImage());

        // Mettre à jour le texte du captcha dans le QLineEdit
        //ui->text->setText(cp.captchaText());
    }*/

void Dialog::on_button_clicked()
{
    // Récupérer le texte saisi par l'utilisateur
        QString userInput = ui->text->text();

        // Récupérer le texte du captcha généré
        Captcha cp;
        cp.randomize();
        cp.setDifficulty(3);
        cp.generateText();
        QString captchaText = cp.captchaText();
cout << code.toStdString() << endl ;
        // Vérifier si le texte saisi correspond au texte du captcha
        if (userInput == code) {
            QMessageBox::information(this, "Validation", "Captcha correct !");
            close();
        } else {
            QMessageBox::warning(this, "Validation", "Captcha incorrect !");
        }

}
