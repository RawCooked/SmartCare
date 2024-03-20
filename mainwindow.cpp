#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "materiel.h"
#include <QMessageBox>
#include <QtCharts> // Inclure le fichier d'en-tête pour les graphiques de Qt
#include <QLabel>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_23, &QPushButton::clicked, this, &MainWindow::on_pushButton_23_clicked);
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
    QString errorMessage = "The following field(s) is/are empty:";
    if (ui->nom_mate->text().isEmpty()) {
        errorMessage += "\n- nom";
    }
    if (ui->categorie_mat->text().isEmpty()) {
        errorMessage += "\n- etat ";
    }
    if (ui->etat_mat->text().isEmpty()) {
        errorMessage += "\n- categorie";
    }

    if (errorMessage != "The following field(s) is/are empty:") {
        QMessageBox::information(this, "Error", errorMessage, QMessageBox::Ok);
        return;
    }

    Connexion c;
    materiel m(ui->nom_mate->text().toStdString(), ui->categorie_mat->text().toStdString(), ui->etat_mat->text().toStdString());
    c.addmateriel(m);
}


void MainWindow::on_pushButton_28_clicked()
{
    Connexion c;
    c.displayWMAterieltInListView(ui->listView_14);
}



void MainWindow::on_pushButton_35_clicked()
{
    Connexion c;
       int idToDelete = ui->id->text().toInt();
       c.deletemateriel(idToDelete);

}

void MainWindow::on_pushButton_22_clicked()
{
    QString errorMessage = "The following field(s) is/are empty:";
    if (ui->idmat->text().isEmpty()) {
        errorMessage += "\n- ID";
    }
    if (ui->nom->text().isEmpty()) {
        errorMessage += "\n- nom";
    }
    if (ui->categorie->text().isEmpty()) {
        errorMessage += "\n- etat";
    }
    if (ui->etat->text().isEmpty()) {
        errorMessage += "\n- categorie";
    }

    if (errorMessage != "The following field(s) is/are empty:") {
        QMessageBox::information(this, "Error", errorMessage, QMessageBox::Ok);
        return;
    }

    Connexion c;
    materiel m(ui->idmat->text().toInt(), ui->nom->text().toStdString(), ui->categorie->text().toStdString(), ui->etat->text().toStdString());
    c.updateMateriel(m);
}

void MainWindow::on_pushButton_42_clicked()
{
    Connexion c;
    c.displayWMAterieltInListView(ui->listView_27);
}

void MainWindow::on_pushButton_59_clicked()
{
    Connexion c;
    c.displayWMAterieltInListView(ui->listView_4);

    // Obtenir les statistiques par catégorie
    QMap<QString, int> materialStatisticsByCategory = c.getMaterialStatisticsByCategory();

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
    if (ui->widget_22->layout()) {
        QLayoutItem *child;
        while ((child = ui->widget_22->layout()->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    }

    // Créer un nouveau layout si nécessaire
    if (!ui->widget_22->layout()) {
        QVBoxLayout *mainLayout = new QVBoxLayout(ui->widget_22);
        ui->widget_22->setLayout(mainLayout);
    }

    // Afficher le graphique
    QChartView *chartView = new QChartView(chart);
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(ui->widget_22->layout());
    if (mainLayout) {
        mainLayout->addWidget(chartView);
    }
    ui->widget_22->show();
}

void MainWindow::on_pushButton_23_clicked()
{
    Connexion c;
    int idMat = ui->lineEdit->text().toInt(); // Supposons que vous avez un LineEdit nommé "lineEdit_id_mat"

        // Appeler la fonction pour afficher les résultats de la recherche dans le QListView
        c.displayMaterielInListViewRecherche(ui->listView_4, idMat);
}

void MainWindow::on_pushButton_41_clicked()

    {
    Connexion connexion;

       // Déterminer l'ordre de tri sélectionné
       QString sortOrder;
       if (ui->radioButton->isChecked()) {
           sortOrder = "ASC"; // Tri croissant
       } else if (ui->radioButton_2->isChecked()) {
           sortOrder = "DESC"; // Tri décroissant
       } else {
           qDebug() << "Error: No radio button selected.";
           return; // Sortir de la fonction si aucun bouton radio n'est sélectionné
       }

       // Appeler la fonction displayMaterielInListViewTri pour trier et afficher les données
       connexion.displayMaterielInListViewTri(ui->listView_4, sortOrder);
}


void MainWindow::on_pushButton_60_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/MSI/Desktop/SmartCare - Copie/materiels.pdf");
    QPainter painter;

    if (!painter.begin(&printer)) {
        qWarning("failed to open file, is it writable?");
    }

    QSqlQuery query;
    qDebug() << query.prepare("SELECT sysdate FROM dual");
    if (query.exec()) {
        if (query.next()) {
            QDateTime dateTime = query.value(0).toDateTime();
            QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
            painter.drawText(850, 50, dateTimeString);

            QImage image("C:/Users/MSI/Desktop/SmartCare/image2.png");
            QRectF imageRect(50, 90, 200, 120);
            painter.drawImage(imageRect, image);

            QImage image1("C:/Users/MSI/Desktop/SmartCare/logo.jpg");
            QRectF image1Rect(700, 90, 200, 120);
            painter.drawImage(image1Rect, image1);

            QFont fontRdvText("Arial", 30, QFont::Bold);
            painter.setFont(fontRdvText);
            QPen penRdvText(Qt::red);
            penRdvText.setWidth(1);
            painter.setPen(penRdvText);

            QRectF textRect(350, 90, 300, 120);
            painter.drawText(textRect, Qt::AlignCenter, "MATERIEL");

            QRectF enlargedRect = textRect.adjusted(-10, -10, 10, 10);
            QPen penFrame(Qt::black);
            penFrame.setWidth(2);
            painter.setPen(penFrame);
            painter.drawRect(enlargedRect);

            QRectF outerRect = enlargedRect.adjusted(-20, -20, 20, 20);
            painter.drawRect(outerRect);
        }
    }

    int i = 220; // Vertical starting position of the table
    int k = 0;
    int tableWidth = 559;
    int tableHeight = 80;
    int pageWidth = 595;
    int pageHeight = 842;
    int tableStartY = (pageHeight - (k / 13 + 1) * tableHeight) / 2;
    int tableStartX = (pageWidth - tableWidth) / 2 + 200;

    QSqlQuery qry;
    if (qry.exec("SELECT * FROM materiel")) {
        while (qry.next()) {
            if (k % 13 == 0) {
                i = tableStartY;
                painter.setFont(QFont("Arial", 10));
                QPen penblack(Qt::black);
                painter.setPen(penblack);
                painter.drawText(tableStartX, i - 50, "ID");
                painter.drawText(tableStartX + 170, i - 50, "Nom");
                painter.drawText(tableStartX + 405, i - 50, "Etat");
                painter.drawText(tableStartX + 660, i - 50, "Catégorie");
            }

            painter.setFont(QFont("Arial", 10));
            QPen penblack(Qt::black);
            painter.setPen(penblack);
            int j = 0;
            QString id_mat = qry.value(0).toString();
            painter.drawText(tableStartX + j * 90, i, id_mat);
            j++;
            QString nom_mat = qry.value(1).toString();
            painter.drawText(tableStartX + j * 90 + 90, i, nom_mat); // Adjusting the x position
            j++;
            QString etat = qry.value(2).toString();
            painter.drawText(tableStartX + j * 90 + 230, i, etat); // Adjusting the x position
            j++;
            QString categorie = qry.value(3).toString();
            painter.drawText(tableStartX + j * 90 + 420, i, categorie); // Adjusting the x position
            j++;
            i += tableHeight;
            k++;
        }
    }

    painter.end();
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/MSI/Desktop/SmartCare/materiels.pdf"));
}
