#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include "rendez_vous.h"
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
    click = new QMediaPlayer();
        click->setMedia(QUrl::fromLocalFile("C:/Users/Dell/Desktop/SmartCare/Click.mp3"));
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

void MainWindow::on_pushButton_22_clicked()
{
    close();
}

void MainWindow::on_btajoutRdv_clicked()
{

    // Configuration du son de clic
        click->setMedia(QUrl::fromLocalFile("C:/Users/Dell/Desktop/SmartCare/Click.mp3"));
        click->play();
        qDebug() << click->errorString(); // Affiche les messages d'erreur liés à la lecture du son
        // Récupération des valeurs saisies dans les champs de l'interface utilisateur

        QString type = ui->TypeRdv_1->text();
        QDate date = ui->DateRdv_1->date();
        int prix = ui->prixRdv1->text().toInt();

        // Instanciation d'un objet de la classe 'rdv' en utilisant les informations saisies
        Rdv R(0,date,prix,type);

        // Appel de la méthode 'ajouterR()' pour ajouter le rdv à la base de données
        bool test = R.ajouterR();

        if (test)
        {
            // Mise à jour du modèle de la table dans l'interface utilisateur
            //ui->listView1_rdv->setModel(r.afficherR());

            // Affichage d'une boîte de dialogue informative en cas de succès
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n" "Click cancel to exist\n"), QMessageBox::Cancel);
        }
        else
        {
            // Affichage d'une boîte de dialogue d'erreur en cas d'échec
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                   QObject::tr("Ajout non effectué.\n""Click cancel to exist."),
                                   QMessageBox::Cancel);
        }


}

void MainWindow::on_pushButton_40_clicked()
{
    Rdv R;
    R.displayRdvInListView(ui->listView1_rdv);
}

void MainWindow::on_pushButton_50_clicked()
{
    Rdv R;
    R.displayRdvInListView(ui->listView2_rdv);
}

void MainWindow::on_btsuppRdv_clicked()
{
    click->setMedia(QUrl::fromLocalFile("C:/Users/Dell/Desktop/SmartCare/Click.mp3"));
        click->play();
        qDebug()<<click ->errorString();
        int idr=ui->idr_1->value();
            bool test=r.supprimerR(idr);
            if (test)
              {

                QMessageBox :: information (nullptr, QObject::tr("OK"),
                QObject::tr("Suppression effectué\n" "Click cancel to exist\n"), QMessageBox::Cancel);

              }
            else
              {  QMessageBox::critical(nullptr , QObject::tr("NOT OK"),
                                     QObject::tr("Suppression non effectué.\n""Click cancel to exist.")
                                     ,QMessageBox::Cancel);

              }
}

void MainWindow::on_btmdfrdv_clicked()
{
    click->setMedia(QUrl::fromLocalFile("C:/Users/Dell/Desktop/SmartCare/Click.mp3"));
        click->play();
        qDebug()<<click ->errorString();
        int idr = ui->idr_3->text().toInt();
        QString type = ui->TypeRdv_2->text();
        QDate date= ui->DateRdv_2->date();

        int prix = ui->prixRdv_2->text().toInt();



        Rdv R(idr,date,prix,type);
        bool test =r.modifierR(idr,date,prix,type);

        if(test)
        {//ui->listView3_rdv->setModel(r.afficherR());
            QMessageBox::information(nullptr, QObject::tr("modifier un rdv"),
                                     QObject::tr("rdv  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un rdv"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_58_clicked()
{
    Rdv R;
    R.displayRdvInListView(ui->listView3_rdv);
}

void MainWindow::on_bttrirdv_clicked()
{
    Rdv R;
    click->setMedia(QUrl::fromLocalFile("C:/Users/Dell/Desktop/SmartCare/Click.mp3"));
        click->play();
        qDebug()<<click ->errorString();
        QString critere=ui->tris_2->currentText();
            QString mode;
             if (ui->asc->isChecked()==true)
        {
                 mode="ASC";
        }
             else if(ui->desc->isChecked()==true)
             {
                 mode="DESC";
             }
          ui->listView1_rdv->setModel(r.trierR(critere,mode));
          bool test =r.trierR(critere,mode);
          if(test)
          {
              R.displayRdvInListView(ui->listView1_rdv);
              QMessageBox::information(nullptr, QObject::tr("modifier un rdv"),
                                       QObject::tr("rdv  modifié.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

          }
          else
              QMessageBox::critical(nullptr, QObject::tr("Modifier un rdv"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_btajoutRdv_2_clicked()
{
    QPrinter printer;
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName("C:/Users/Dell/Desktop/rdv.pdf");
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

               painter.drawText(350, 100, " Rendez-vous");
               painter.setFont(QFont("Arial", 30));
               painter.setPen(Qt::black);
           }
       }
       // End the painting on the printer
       painter.end();

       // Open the PDF using the default application
       QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Dell/Desktop/rdv.pdf"));

}
