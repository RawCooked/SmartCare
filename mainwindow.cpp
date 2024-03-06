#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"



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

void MainWindow::on_pushButton_16_clicked()
{
    Connexion c;

   materiel m(ui->nom_mate->text().toStdString(), ui->categorie_mat->text().toStdString(), ui->etat_mat->text().toStdString());
    c.addmateriel(m);
}

void MainWindow::on_pushButton_22_clicked()
{
    Connexion c;
       int idToDelete = ui->id->text().toInt();
       c.deletemateriel(idToDelete);
}

void MainWindow::on_pushButton_23_clicked()
{
    Connexion c;
       materiel m(ui->idmat->text().toInt(),ui->nom->text().toStdString(),ui->categorie->text().toStdString(),ui->etat->text().toStdString());
       c.updateMateriel(m);
}



void MainWindow::on_pushButton_28_clicked()
{
    Connexion c;
      c.displayWMAterieltInListView(ui->listView_14);
}
