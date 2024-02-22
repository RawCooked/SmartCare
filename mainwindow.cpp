#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>




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
    ui->widget_17->hide();


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
        ui->widget_17->show();
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
    ui->widget_17->show();
    changeWidget(8);

}

void MainWindow::on_pushButton_9_clicked()
{
    Connexion c;
    //c.displayTraitInListView(ui->listView);
}

void MainWindow::on_pushButton_14_clicked()
{
    Connexion c;
    Traitement T(0,ui->TypeTrait->text(),ui->DateTrait->date(),ui->DescriptionTrait->text(),ui->PrixTrait->value());
    c.addTrait(T);
}

void MainWindow::on_pushButton_59_clicked()
{

}

void MainWindow::on_pushButton_24_clicked()
{
    Connexion c;
    c.deleteTrait(ui->PrixTrait_4->value());
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->widget_16->show();
    ui->widget_19->hide();
    ui->widget_40->hide();


}

void MainWindow::on_pushButton_21_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if(username == "kousay" && password=="ls1"){
        QMessageBox::information(this,"sign in","usename and password are correct" );
        ui->widget_17->hide();
    }
    else
        QMessageBox::warning(this,"sign in","usename and password are not correct");

}

void MainWindow::on_pushButton_27_clicked()
{
    ui->widget_17->show();

}

void MainWindow::on_pushButton_28_clicked()
{
    ui->widget_42->hide();
    ui->widget_19->show();
    ui->widget_40->show();

}
