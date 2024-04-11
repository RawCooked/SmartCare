#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "employe.h"
#include "users.h"
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
#include <QtPrintSupport/QPrintDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <random>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeWidget(1);
    Employe E;
    //ui->Nbre_emp->setText(QString::number(E.NbreEmploye())+" Employes");
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
    int ide = 20;
    QString NOM = ui->NomEmp->text();
    QString PRENOM = ui->PrenomEmp->text();
    QString Etat = ui->EtatEmp->currentText();
    double salaire = ui->salaireEmp->text().toDouble();
    QString sexe;
    int idu=0;
    if (ui->Homme->isChecked())
        sexe = "Homme";
    else if (ui->Femme->isChecked())
        sexe = "Femme";

    if (ui->NomEmp->text().isEmpty() || ui->PrenomEmp->text().isEmpty() || ui->salaireEmp->text().isEmpty() || (ui->Homme->isChecked() == false && ui->Femme->isChecked() == false)) {
        QMessageBox::critical(nullptr, QObject::tr("Champs vides"),
                              QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Cancel);
    } else {
        Employe E(ide, NOM, PRENOM, Etat, sexe, salaire);
        QString mdp=generateRandomString(4);
        bool test = E.ajouter();
        QSqlQuery query;
        QString queryString = "SELECT id_emp FROM Employe where nom_e='" + NOM + "' AND prenom_e='" + PRENOM + "' AND etat='" + Etat + "'";
        if (query.exec(queryString)) {
            if (query.next()) {
                idu = query.value(0).toInt();
            }
        }
       NOM+=generateRandomString(2);
       users U(idu,NOM,mdp,Etat);
        bool test0= U.ajouter();
        if (test && test0) {
            QString message = "ajouté avec succès\nVotre nom d'utilisateur est : " + NOM +
                                  "\nVotre mot de passe est : " + mdp;

                QMessageBox::information(nullptr, "Succès", message);
            ui->tab_emp->setModel(E.afficher());
            //displayEmployesInListView(ui->tab_emp);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                  QObject::tr("ajout failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
        ui->tab_emp->setModel(E.afficher());
       // displayEmployesInListView(ui->tab_emp);
    }
}


void MainWindow::on_supprimer_emp_clicked()
{
    int ide=ui->id_emp->text().toInt();
    Employe E;
    users u;
    bool test=E.supprimer(ide);
    bool test0=u.supprimer(ide);
    if (test && test0)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Suppression effectuée\n"
                            "Click Cancel non to exit.") , QMessageBox :: Cancel);
        ui->tab_emp->setModel(E.afficher());
          //displayEmployesInListView(ui->tab_emp2);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    ui->tab_emp->setModel(E.afficher());
     // displayEmployesInListView(ui->tab_emp2);
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

    if (ui->NomEmp_modifier->text().isEmpty() || ui->PrenomEmp_modifier->text().isEmpty() || ui->salaireEmp_modifier->text().isEmpty() || (ui->Homme_modifier->isChecked() == false && ui->Femme_modifier->isChecked() == false)) {
        QMessageBox::critical(nullptr, QObject::tr("Champs vides"),
                              QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Cancel);
    } else {
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
        ui->tab_emp3->setModel((E.afficher()));
           // displayEmployesInListView(ui->tab_emp3);
        }
}
void MainWindow::on_refresh_emp_clicked()
{
    Employe E;
    ui->tab_emp->setModel((E.afficher()));
    ui->Nbre_emp->setText(QString::number(E.NbreEmploye())+" Employes");
}

void MainWindow::on_refresh_emp2_clicked()
{
    Employe E;
    ui->tab_emp2->setModel((E.afficher()));
}

void MainWindow::on_refresh_emp3_clicked()
{
    Employe E;
    ui->tab_emp3->setModel((E.afficher()));
}

void MainWindow::on_Exporter_pdf_emp_clicked()
{
    Employe E;
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/chche/OneDrive/Desktop/emp.pdf");
    QPainter painter;

    if (!painter.begin(&printer)) {
        qWarning("failed to open file, is it writable?");
    }

    // Load images and resize
    QImage imageLeft("C:/Users/chche/Downloads/feather/feather/Capture-removebg-preview.png");

    QSqlQuery query;
    qDebug() << query.prepare("SELECT * FROM Employe");
    if (query.exec()) {
        // Draw left image
        painter.drawImage(200, 50, imageLeft);

        if (query.next()) {
            QDateTime dateTime = query.value(0).toDateTime();
            QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");

            // Draw the datetime on the PDF
            painter.drawText(600, 50, dateTimeString);

            QPen penred(Qt::red);
            painter.setFont(QFont("Arial", 30));
            penred.setWidth(1);
            painter.setPen(penred);

            QFontMetrics fm(painter.font());
            QString employesText = " Employés";
            QRect textRect = fm.boundingRect(0, 0, 1000, 1000, Qt::AlignCenter, employesText);
            int xText = (printer.width() - textRect.width()) / 2; // Center horizontally
            painter.drawText(xText, 100, employesText);


            painter.setFont(QFont("Arial", 15));
            painter.setPen(Qt::blue);

            // Draw table headers
            painter.drawText(60, 180, "id");
            painter.drawText(210, 180, "nom");
            painter.drawText(360, 180, "prenom");
            painter.drawText(510, 180, "etat");
            painter.drawText(660, 180, "sexe");
            painter.drawText(810, 180, "salaire");
             painter.setPen(Qt::black);
             // Draw table outline
             painter.drawRect(50, 150, 900, 50 + 50 * E.NbreEmploye()); // Increased height for the header row
            for (int i = 0; i < 6; ++i) {
                painter.drawLine(50 + 150 * i, 150, 50 + 150 * i, 200 + 50 * E.NbreEmploye()); // Vertical lines
            }
            for (int i = 0; i < E.NbreEmploye(); ++i) {
                painter.drawLine(50, 200 + 50 * i, 950, 200 + 50 * i); // Horizontal lines
            }

            int row = 0;
            // Fetch and draw table data
            do {
                QString column1Data = query.value(0).toString();
                QString column2Data = query.value(1).toString();
                QString column3Data = query.value(2).toString();
                QString column4Data = query.value(3).toString();
                QString column5Data = query.value(4).toString();
                QString column6Data = query.value(5).toString();
                // Fetch more data as needed

                painter.drawText(60, 230 + row * 50, column1Data);
                painter.drawText(210, 230 + row * 50, column2Data);
                painter.drawText(360, 230 + row * 50, column3Data);
                painter.drawText(510, 230 + row * 50, column4Data);
                painter.drawText(660, 230 + row * 50, column5Data);
                painter.drawText(810, 230 + row * 50, column6Data);
                // Draw more data as needed

                ++row;
            } while (query.next());
        }
    }

    painter.end();
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/chche/OneDrive/Desktop/emp.pdf"));
}




void MainWindow::on_tri_emp_clicked()
{
    Employe E;
QString critere=ui->critere_tri_emp->currentText();
QString ordre;
if (ui->croissant_emp->isChecked())
    ordre="ASC";
else if (ui->dcroissat_emp->isChecked())
    ordre="DESC";
ui->tab_emp0->setModel(E.trier(critere,ordre));
}

void MainWindow::on_recherche_emp_clicked()
{
    Employe E;
    QString aux=ui->Recherche_emp->text();
    ui->tab_emp0->setModel(E.rechercher(aux));
}
void MainWindow::on_refresh_emp0_clicked()
{
    Employe E;
    ui->Nbre_emp->setText(QString::number(E.NbreEmploye())+" Employes");
    ui->tab_emp0->setModel(E.afficher());
    QMap<QString, int> employeStatisticsByCategory = E.getEmployeStatisticsByCategory();

    // Créer un nouveau graphique
    QChart *chart = new QChart();

    // Ajouter les données au graphique
    QBarSeries *series = new QBarSeries();
    for (auto it = employeStatisticsByCategory.begin(); it != employeStatisticsByCategory.end(); ++it) {
        QBarSet *set = new QBarSet(it.key());
        *set << it.value();
        series->append(set);
    }

    chart->addSeries(series);
    chart->createDefaultAxes();

    // Supprimer le layout précédent
    if (ui->widget_7->layout()) {
        QLayoutItem *child;
        while ((child = ui->widget_7->layout()->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    }

    // Créer un nouveau layout si nécessaire
    if (!ui->widget_7->layout()) {
        QVBoxLayout *mainLayout = new QVBoxLayout(ui->widget_7);
        ui->widget_7->setLayout(mainLayout);
    }

    // Ajouter le graphique au layout
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->widget_7->layout()->addWidget(chartView);
}


void MainWindow::on_translate_clicked()
{
    QString url = "http://translate.googleapis.com/translate_a/single?client=gtx";
    QString l1,l2;
    if (ui->l1->currentText() == "english") {
        l1 = "en";
    } else if (ui->l1->currentText() == "french") {
        l1 = "fr";
    } else if (ui->l1->currentText() == "arabic") {
        l1 = "ar";
    }


    if (ui->l2->currentText() == "english") {
        l2 = "en";
    } else if (ui->l2->currentText() == "french") {
        l2 = "fr";
    } else if (ui->l2->currentText() == "arabic") {
        l2 = "ar";
    }

    url.append("&sl="+l1+"&tl="+l2+"&dt=t&q=");
    url.append(ui->texttotranslate->text());
    qInfo() << "url: " + url;

    // Make an HTTP request
    QNetworkAccessManager *nam = new QNetworkAccessManager();
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onTranslationReceived(QNetworkReply*)));
    nam->get(QNetworkRequest(QUrl(url)));
 }
void MainWindow::onTranslationReceived(QNetworkReply* reply)
{
    // Check for errors
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Network error: " << reply->errorString();
        return;
    }

    // Parse the response
    QByteArray responseData = reply->readAll();
    qInfo() << "Response data:" << responseData; // Debug output

    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

    // Check if parsing was successful
    if (jsonResponse.isNull()) {
        qWarning() << "Failed to parse JSON response";
        return;
    }

    // Assuming the JSON response structure
    QJsonArray translationArray = jsonResponse.array();
    if (translationArray.isEmpty()) {
        qWarning() << "Translation array is empty";
        return;
    }

    QJsonArray translationGroupArray = translationArray.at(0).toArray();
    if (translationGroupArray.isEmpty()) {
        qWarning() << "Translation group array is empty";
        return;
    }

    QJsonArray translationItemArray = translationGroupArray.at(0).toArray();
    if (translationItemArray.isEmpty()) {
        qWarning() << "Translation item array is empty";
        return;
    }

    QString translation = translationItemArray.at(0).toString();

    // Display the translation
    if (!translation.isEmpty()) {
        ui->translatedtext->setText(translation);
    } else {
        qWarning() << "Translation not available";
        ui->translatedtext->setText("Translation not available");
    }
}


