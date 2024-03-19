#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "rendez_vous.h"
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QUrl>
#include <QtPrintSupport/QPrintDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts>


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
    ui->stat_wiget->hide();


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
    ui->stat_wiget->show();

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

        if((type == "urgent" ||type == "nourgent") && (prix!=0)){
            QMessageBox::information(this,"Ajout","les entrés sont valide" );

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

        else
            QMessageBox::warning(this,"sign in","les entrés ne sont pas valide");



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

        if((type == "urgent" ||type == "nourgent") && (prix!=0)){
            bool test =r.modifierR(idr,date,prix,type);
            QMessageBox::information(this,"Ajout","les entrés sont valide" );
        if(test)
        {//ui->listView3_rdv->setModel(r.afficherR());
            QMessageBox::information(nullptr, QObject::tr("modifier un rdv"),
                                     QObject::tr("rdv  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Modifier un rdv"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

}
        else
            QMessageBox::warning(this,"sign in","les entrés ne sont pas valide");

}

void MainWindow::on_pushButton_58_clicked()
{
    Rdv R;
    R.displayRdvInListView(ui->listView3_rdv);
}

void MainWindow::on_bttrirdv_clicked()
{


    Rdv r;
    r.displayRdvInListViewTri(ui->listView1_rdv);

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

               // Style for "Rendez-vous" text and outer border
               {
                   // Draw the image to the left
                   QImage image("C:/Users/Dell/Desktop/SmartCare/image2.png");  // Replace with the actual path to your image
                   QRectF imageRect(50, 90, 200, 120);  // Adjust the rectangle size and position for the image
                   painter.drawImage(imageRect, image);

                   // Draw the image to the right (Corrected)
                   QImage image1("C:/Users/Dell/Desktop/SmartCare/logo.jpg");  // Replace with the actual path to your image
                   QRectF image1Rect(700, 90, 200, 120);  // Adjust the rectangle size and position for the image
                   painter.drawImage(image1Rect, image1);  // Corrected variable name to image1

                   QFont fontRdvText("Arial", 30, QFont::Bold);  // Bold font
                   painter.setFont(fontRdvText);
                   QPen penRdvText(Qt::red);  // Choose the color after setting the font
                   penRdvText.setWidth(1);
                   painter.setPen(penRdvText);

                   // Draw "Rendez-vous" with styling
                   QRectF textRect(350, 90, 300, 120);  // Adjust the rectangle size and position as needed
                   painter.drawText(textRect, Qt::AlignCenter, "Rendez-vous");  // Center the text

                   // Increase the dimensions of the inner black frame
                   QRectF enlargedRect = textRect.adjusted(-10, -10, 10, 10);

                   // Draw a black frame around the text with increased dimensions
                   QPen penFrame(Qt::black);
                   penFrame.setWidth(2);
                   painter.setPen(penFrame);
                   painter.drawRect(enlargedRect);

                   // Increase the dimensions of the outer border
                   QRectF outerRect = enlargedRect.adjusted(-20, -20, 20, 20);

                   // Draw a black frame around the outer rectangle
                   painter.drawRect(outerRect);
               }





           }

       }
       QString type_r, idr, prix_r, date_r;
       QSqlQuery qry;
       int i = 250; // Position verticale de départ du tableau
       int k = 0;
       int tableWidth = 559; // Largeur totale du tableau (somme des largeurs des colonnes)
       int tableHeight = 80; // Hauteur d'une ligne du tableau
       int pageWidth = 595; // Largeur de la page (en supposant une page A4 standard)
       int pageHeight = 842; // Hauteur de la page (en supposant une page A4 standard)
       int tableStartY = (pageHeight - (k / 13 + 1) * tableHeight) / 2; // Calcul de la position verticale de départ du tableau
       int tableStartX = (pageWidth - tableWidth) / 2 + 200; // Augmentation de la position horizontale de départ du tableau

       if (qry.exec("select * from rdv"))
       {
           while (qry.next())
           {
               if (k % 13 == 0)
               {
                   i = tableStartY; // Réinitialisation de la position verticale pour commencer une nouvelle rangée du tableau
                   painter.setFont(QFont("Arial", 10));
                   QPen penblack(Qt::black);
                   painter.setPen(penblack);
                   painter.drawText(tableStartX, i - 50, "id");
                   painter.drawText(tableStartX + 90, i - 50, "Type");
                   painter.drawText(tableStartX + 230, i - 50, "Date");
                   painter.drawText(tableStartX + 420, i - 50, "Prix");
               }

               painter.setFont(QFont("Arial", 10));
               QPen penblack(Qt::black);
               painter.setPen(penblack);
               int j = 0;
               idr = qry.value(0).toString();
               painter.drawText(tableStartX + j * 20, i, idr);
               j++;
               type_r = qry.value(1).toString();
               painter.drawText(tableStartX + j * 90, i, type_r);
               j++;
               date_r = qry.value(2).toString();
               painter.drawText(tableStartX + j * 100, i, date_r);
               j++;
               prix_r = qry.value(3).toString();
               painter.drawText(tableStartX + j * 139, i, prix_r);
               j++;
               i += tableHeight; // Passage à la ligne suivante du tableau
               k++;
           }
       }




       // End the painting on the printer
       painter.end();

       // Open the PDF using the default application
       QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Dell/Desktop/rdv.pdf"));

}





void MainWindow::on_imprimer_clicked()
{
    QPrinter printer;
        printer.setPrinterName ("le nom de l'imprimante");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()== QDialog::Rejected)return;
        ui->listView1_rdv->render(&printer);
}

void MainWindow::on_pushButton_41_clicked()
{


        // Obtenir les statistiques par catégorie
        QMap<QString, int> materialStatisticsByCategory = r.getRdvlStatisticsByType();

        // Créer un nouveau graphique
        QChart *chart = new QChart();

        // Ajouter les données au graphique
        QBarSeries *series = new QBarSeries();
        for (auto it = materialStatisticsByCategory.begin(); it != materialStatisticsByCategory.end(); ++it) {
            QBarSet *set = new QBarSet(it.key());
            *set << it.value();
            series->append(set);
        }

        chart->addSeries(series);
        chart->createDefaultAxes();

        // Supprimer le layout précédent
        if (ui->stat_wiget->layout()) {
            QLayoutItem *child;
            while ((child = ui->stat_wiget->layout()->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }
        }

        // Créer un nouveau layout si nécessaire
        if (!ui->stat_wiget->layout()) {
            QVBoxLayout *mainLayout = new QVBoxLayout(ui->stat_wiget);
            ui->stat_wiget->setLayout(mainLayout);
        }

        // Afficher le graphique
        QChartView *chartView = new QChartView(chart);
        QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(ui->stat_wiget->layout());
        if (mainLayout) {
            mainLayout->addWidget(chartView);
        }
        ui->stat_wiget->show();
}

void MainWindow::on_recherche_rdv_textChanged(const QString &arg1)
{
    Rdv r;
            QVector<QStringList> a = r.selectAllRdv();
            QVector<QStringList> finalList;

            // Filtrer les traitements en fonction du texte entré dans la QLineEdit
            for (const QStringList& rdv : a) {
                if (rdv[0].contains(arg1)) {
                    finalList.append(rdv);
                }
            }

            // Afficher les traitements filtrés dans le QListView
            r.displayRdvListViewUpdated(ui->listView1_rdv, finalList);

            // Si la QLineEdit est vide, afficher tous les traitements
            if (arg1.isEmpty()) {
                r.displayRdvInListView(ui->listView1_rdv);
            }
}
