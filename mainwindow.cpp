#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "employe.h"
#include <iostream>
#include<QTextStream>
#include<QIntValidator>
#include <QMainWindow>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeWidget(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_7_clicked()
{
    close();
}
void MainWindow::changeWidget(int i){
    ui->Traitement->hide();
    ui->DashBoard->hide();
    ui->Materiel->hide();
    ui->Patient->hide();
    ui->Atelier->hide();
    ui->Employe->hide();
    ui->Rdv->hide();

    switch (i){
    case 1 :
        ui->DashBoard->show();
        break;
    case 2 :
        ui-> Traitement->show();
        break;
    case 3 :

        break;
    case 4 :
        ui->Materiel->show();
        break;

    case 5 :
        ui->Patient->show();
        break;
    case 6 :
        ui->Atelier->show();
        break;
    case 7 :
        ui->Employe->show();
        break;
    case 8 :
        ui->Rdv->show();
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    changeWidget(1);
}


void MainWindow::on_pushButton_3_clicked()
{
    changeWidget(2);
}

void MainWindow::on_Rdv_top_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
    changeWidget(4);
}

void MainWindow::on_pushButton_2_clicked()
{
    changeWidget(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    changeWidget(6);
}

void MainWindow::on_pushButton_8_clicked()
{
    changeWidget(7);
}

void MainWindow::on_pushButton_5_clicked()
{
    changeWidget(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    Connexion c;
    //c.displayTraitInListView(ui->listView);
}

void MainWindow::on_pushButton_14_clicked()
{
    //Connexion c;
    //Traitement T(0,ui->TypeTrait->text(),ui->DateTrait->date(),ui->DescriptionTrait->text(),ui->PrixTrait->value());
    //c.addTrait(T);
}

void MainWindow::on_pushButton_59_clicked()
{

}

void MainWindow::on_pushButton_24_clicked()
{
    Connexion c;
    //c.deleteTrait(ui->PrixTrait_4->value());
}

void MainWindow::on_Ajouter_emp_clicked()
{
    //int ID_C=ui->le_ID_C->text().toInt();
    int ide=20;
    QString NOM=ui->NomEmp->text();
    QString PRENOM=ui->PrenomEmp->text();
    QString Etat=ui->EtatEmp->currentText();
    double salaire=ui->salaireEmp->text().toInt();
    QString sexe;
    if (ui->Homme->isChecked())
        sexe="Homme";
    else if (ui->Femme->isChecked())
        sexe="femme";
       /*ui->NOM->setMaxLength(20);
       ui->PRENOM->setMaxLength(20);*/


    Employe E  (ide,NOM,PRENOM,Etat,sexe,salaire);
    cout <<ide<<salaire<<endl;
    //Employe E  (0,"saif","chkili","docteur","homme",170);

bool test=E.ajouter();
if(test)
 {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                               QObject::tr("ajout successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
  //ui->tab_emp->setModel(E.afficher());
    displayEmployesInListView(ui->tab_emp);
           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                               QObject::tr("ajout failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
//ui->tab_emp->setModel(E.afficher());
  displayEmployesInListView(ui->tab_emp);

}

void MainWindow::on_supprimer_emp_clicked()
{
    int ide=ui->id_emp->text().toInt();
    Employe E;
    bool test=E.supprimer(ide);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Suppression effectuée\n"
                            "Click Cancel non to exit.") , QMessageBox :: Cancel);
        //ui->tab_emp->setModel(E.afficher());
          displayEmployesInListView(ui->tab_emp2);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    //ui->tab_emp->setModel(E.afficher());
      displayEmployesInListView(ui->tab_emp2);
}

void MainWindow::on_modifier_emp_clicked()
{
    int ide= ui ->Ide_modifier->text().toInt();
    QString NOM=ui->NomEmp_modifier->text();
    QString PRENOM=ui->PrenomEmp_modifier->text();
    QString Etat=ui->etatEmp_modifier->currentText();
    double salaire=ui->salaireEmp_modifier->text().toInt();
    QString sexe;
    if (ui->Homme_modifier->isChecked())
        sexe="Homme";
    else if (ui->Femme_modifier->isChecked())
        sexe="femme";
       /*ui->NOM->setMaxLength(20);
       ui->PRENOM->setMaxLength(20);*/


    Employe E  (ide,NOM,PRENOM,Etat,sexe,salaire);
           bool test=E.modifier(ide,NOM,PRENOM,Etat,sexe,salaire);
            if (test)
        {
                QMessageBox::information(nullptr, QObject::tr("modifie un client"),
                                  QObject::tr("client modifie.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }

        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("Modification non effectuée.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        //ui->tab_emp3->setModel((C.afficher()));
            displayEmployesInListView(ui->tab_emp3);
}

void MainWindow::on_refresh_emp0_clicked()
{
    displayEmployesInListView(ui->tab_emp0);
}

void MainWindow::on_refresh_emp_clicked()
{
    displayEmployesInListView(ui->tab_emp);
}

void MainWindow::on_refresh_emp2_clicked()
{
    displayEmployesInListView(ui->tab_emp2);
}

void MainWindow::on_refresh_emp3_clicked()
{
    displayEmployesInListView(ui->tab_emp3);
}

void MainWindow::on_Exporter_pdf_emp_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/chche/OneDrive/Desktop/emp.pdf");
           QPainter painter;

           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
           }

           QSqlQuery query;
           qDebug() << query.prepare("select sysdate from dual ");
           if (query.exec()) {

               if (query.next()) {
                   // Extract the datetime from the query result
                   QDateTime dateTime = query.value(0).toDateTime();

                   // Format the datetime as a string
                   QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");

                   // Draw the datetime on the PDF
                   painter.drawText(850, 50, dateTimeString);

                   QPen penred(Qt::black);
                   painter.setFont(QFont("Arial", 30));
                   penred.setWidth(1);
                   painter.setPen(penred);

                   painter.drawText(350, 100, " Employés");
                   painter.setFont(QFont("Arial", 30));
                   painter.setPen(Qt::red);
               }
           }
           // End the painting on the printer
           painter.end();

           // Open the PDF using the default application
           QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/chche/OneDrive/Desktop/emp.pdf"));
}
