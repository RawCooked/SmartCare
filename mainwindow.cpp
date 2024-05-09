#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QDate>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QApplication>
#include "patient.h"
#include "traitement.h"
#include <QMessageBox>

#include <QCoreApplication>
#include <QPrinter>
#include <QPainter>
#include <QDateTime> // Pour la manipulation de la date et de l'heure
#include <QSqlQuery> // Pour exécuter des requêtes SQL
#include <QDebug> // Pour le débogage
#include "dialog.h"

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
    Connexion c;
    c.displayTraitmentsInListView(ui->listView);
    c.displayTraitmentsInListView(ui->listView_9);
    c.displayTraitmentsInListView(ui->listView_11);

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

void MainWindow::on_DashboardButton_clicked()
{
    changeWidget(1);
    Connexion c;
    auto listTrait = c.selectAllTrait();
    for (auto Trait : listTrait) {
        cout<< "this is the information" << Trait.front().toStdString() << "/";
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    changeWidget(2);
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
    c.displayTraitmentsInListView(ui->listView);

    ui->Nb_trait->setText(QString::number(c.selectAllTrait().length()));

    //charts

    QLineSeries *series = new QLineSeries(ui->chartWidget);
    QVector<QStringList> a = c.selectAllTraitById();
    for (QStringList Trait : a) {
        series->append(Trait[0].toInt(), Trait[4].toInt());
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    // Check if ui->chartWidget already has a layout
    if (ui->chartWidget->layout()) {
        QLayoutItem *child;
        while ((child = ui->chartWidget->layout()->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    }
    // Create a new layout only if needed
    if (!ui->chartWidget->layout()) {
        QVBoxLayout *mainLayout = new QVBoxLayout(ui->chartWidget);
        ui->chartWidget->setLayout(mainLayout);
    }
    QChartView *chartView = new QChartView(chart);
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(ui->chartWidget->layout());
    if (mainLayout) {
        mainLayout->addWidget(chartView);
    }
    ui->chartWidget->show();
}


void MainWindow::on_pushButton_14_clicked()
{

    QDate selectedDate = ui->DateTrait->date();
    QString format = "dd-MM-yyyy";

      // Convert QDate to QString using string arguments
      QString dateString = QString("%3-%2-%1")
          .arg(selectedDate.year())
          .arg(selectedDate.month(), 2, 10, QChar('0')) // Pad month with zeros
          .arg(selectedDate.day(), 2, 10, QChar('0'));

    Connexion c;
    c.addTrait(0,ui->TypeTrait->text().toStdString(),dateString.toStdString(),ui->DescriptionTrait->text().toStdString(),ui->PrixTrait->value());
}


void MainWindow::on_pushButton_24_clicked()
{

}

void MainWindow::on_pushButton_25_clicked()
{
    Connexion c;
    c.displayTraitmentsInListView(ui->listView_9);
}

void MainWindow::on_pushButton_26_clicked()
{
    Connexion c;
}

void MainWindow::on_pushButton_30_clicked()
{
    Connexion c;
    c.displayTraitmentsInListView(ui->listView_11);
}

void MainWindow::on_pushButton_29_clicked()
{
    QDate currentDate = QDate::currentDate();
    Connexion c;
    c.updateTrait(ui->idTraitUpdate->value(),ui->typeTraitUpdate->text().toStdString(),currentDate.toString("yyyy-MM-dd").toStdString(),ui->descriptionTraitUpdate->text().toStdString(),ui->prixTraitUpdate->value());
}



void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    if (ui->radioDelete->isChecked()){
        Connexion c;
        auto allTrait = c.selectAllTrait();
        c.deleteTrait(allTrait[index.row()].first().toInt());
        c.displayTraitmentsInListView(ui->listView);
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Connexion c;
    QVector<QStringList> a= c.selectAllTrait(),finalList;
    if (ui->radioTri->isChecked())
    a= c.selectAllTraitTri();

    QStringList b;
    for (QStringList Trait : a) {
        if (Trait[1].contains(arg1)){
            b.append(Trait);
            finalList.append(b);
            b.clear();
        }
    }
    c.displayTraitmentsInListViewUpdated(ui->listView,finalList);
    if (arg1==""){
        c.displayTraitmentsInListView(ui->listView);
    }

}




void MainWindow::on_radioTri_toggled(bool checked)
{
    Connexion c;
    if(checked){
    c.displayTraitmentsInListViewUpdated(ui->listView,c.selectAllTraitTri());
    }else{
    c.displayTraitmentsInListView(ui->listView);
    }
}




void MainWindow::on_listView_11_clicked(const QModelIndex &index)
{
    Connexion c;
    auto a=c.selectAllTrait()[index.row()];
    QString dateString = a[2];
    QDate date = QDate::fromString(dateString, "dd-MM-yyyy");

    ui->idTraitUpdate->setValue(a.first().toInt());
    ui->typeTraitUpdate->setText(a[1]);
    ui->dateTraitUpdate->setDate(date);
    ui->descriptionTraitUpdate->setText(a[3]);
    ui->prixTraitUpdate->setValue(a.last().toFloat());
}

void MainWindow::on_pushButton_12_clicked()
{
    Traitement t;
    t.QrCode("le message eli nhebbouh ywali Qr Code");
}

void MainWindow::on_pushButton_15_clicked()
{
    Connexion c;
    QVector<QStringList> TraitVec= c.selectAllTraitById();
    float prixtot=0;



    QtRPT *Report= new QtRPT();
    Report->loadReport("C:/Users/Administrateur/Documents/unt2/pdffile.xml");



    int NumberOfRecords = TraitVec.length();
    QVector<QString> Data_1,Data_2,Data_3,Data_4,Data_5;


    connect(Report,&QtRPT::setDSInfo,[&](DataSetInfo &dsinfo){
        dsinfo.recordCount= NumberOfRecords;
    });

    for (QStringList t : TraitVec) {
        Data_1.append(t[0]);
        Data_2.append(t[1]);
        Data_3.append(t[2]);
        Data_4.append(t[3]);
        Data_5.append(t[4] + "dts");
        prixtot+=t[4].toFloat();

    }

    connect(Report, &QtRPT::setValue, [&](const int recno, const QString paramname, QVariant &paramValue, const int reportpage)
    {
        Q_UNUSED(reportpage);

        if (paramname == "id")
        {
            paramValue = Data_1[recno];
        }
        if (paramname == "type")
        {
            paramValue = Data_2[recno];
        }
        if (paramname == "date")
        {
            paramValue = Data_3[recno];
        }
        if (paramname == "description")
        {
            paramValue = Data_4[recno];
        }
        if (paramname == "prix")
        {
            paramValue = Data_5[recno];
        }
    });




    connect(Report, &QtRPT::setValue, [&](const int recno, const QString paramname, QVariant &paramValue, const int reportpage)
    {
        Q_UNUSED(reportpage);

        if (paramname == "prixtot")
        {
            paramValue = QString::number(prixtot) + "dts";
        }
    });


    Report->printExec();




}



void MainWindow::on_pushButton_18_clicked()
{
    Connexion c;

    c.displayPatInListViewUpdate(ui->listViewGeneral,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewUpdate,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewDelete,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewAdd,c.selectAllPat());


    // Création du graphique circulaire
    QPieSeries *pieSeries = new QPieSeries();

    // Récupération des données
    QVector<QStringList> data = c.selectAllPatById();

    // Définition des couleurs personnalisées
    QColor colors[] = {QColor("#ff5733"), QColor("#ffc300"), QColor("#ff33a3"), QColor("#33ff57"), QColor("#3377ff"), QColor("#ff3333"), QColor("#ffaabb"), QColor("#aabbcc"), QColor("#ffeecc"), QColor("#ffeeaa"), QColor("#cc99ff"), QColor("#99ff99"), QColor("#99ccff"), QColor("#ff99cc"), QColor("#ccccff"), QColor("#ffcc99"), QColor("#99ffff"), QColor("#ffccff"), QColor("#ffff66"), QColor("#ccffff")};

    int colorIndex = 0;

    // Ajout des données au graphique circulaire
    for (const QStringList &Pat : data) {
        QString label = Pat[0] + "("+Pat[5] + " ans)";
        qreal value = Pat[5].toInt();

        // Création de la tranche avec une couleur personnalisée
        QPieSlice *slice = pieSeries->append(label, value);
        slice->setBrush(colors[colorIndex % (sizeof(colors) / sizeof(colors[0]))]);
        colorIndex++;
    }

    // Affichage des valeurs dans le cercle
    pieSeries->setLabelsVisible();

    // Création du graphique et ajout des séries
    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Statistiques des patients");

    // Création de la vue du graphique
    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);

    // Supprimer l'ancien layout s'il existe
    QLayout *existingLayout = ui->chartWidgetPat->layout();
    if (existingLayout) {
        delete existingLayout;
    }

    // Affichage du graphique dans la fenêtre principale
    QVBoxLayout *mainLayout = new QVBoxLayout(ui->chartWidgetPat);
    mainLayout->addWidget(pieChartView);
    ui->chartWidgetPat->setLayout(mainLayout);
    ui->chartWidgetPat->show();









}

void MainWindow::on_pushButton_37_clicked()
{
    Connexion c;

    if (ui->nomPatAdd->text().isEmpty() or ui->pnomPatAdd->text().isEmpty() or ui->maladePatAdd->text().isEmpty() or ui->hommeAddPat->text().isEmpty() or ui->femmeAddPat->text().isEmpty()){
            QMessageBox::information(this, "Error ", "Nom or Prenom oe Etat or Sexe is empty.", QMessageBox::Ok);
            return;
        }

    string etat,sexe;
    if (ui->maladePatAdd->isChecked())
    etat="malade";
    else etat="sain";

    if (ui->hommeAddPat->isChecked()) sexe = "Homme";
    else sexe ="Femme";


    if(c.addPat(9,ui->agePatAdd->value(),ui->nomPatAdd->text().toStdString(),ui->pnomPatAdd->text().toStdString(),etat,sexe))
    {
        ui->listViewHistorique->addItem("Patient ajouté : " + ui->nomPatAdd->text() + " " + ui->pnomPatAdd->text());
        saveHistoriqueToFile("C:/Users/pc/Desktop/unt2/historique.txt");


    }

    QMessageBox::information(this, "Confirmation ", "Patient ajouté.", QMessageBox::Ok);

}

void MainWindow::on_pushButton_47_clicked()
{
    Connexion c;
    if(c.deletePat(ui->idPatDelete->value()))
    {
    ui->listViewHistorique->addItem("Patient supprimé avec ID : " + QString::number(ui->idPatDelete->value()));
    saveHistoriqueToFile("C:/Users/pc/Desktop/unt2/historique.txt");

    }
}

void MainWindow::on_UpdatePat_clicked()
{
    if (ui->nomPatAdd_2->text().isEmpty() or ui->pnomPatAdd_2->text().isEmpty() or ui->maladePatAdd_2->text().isEmpty() or ui->hommeAddPat_2->text().isEmpty() or ui->femmeAddPat_2->text().isEmpty()){
            QMessageBox::information(this, "Error ", "Nom or Prenom oe Etat or Sexe is empty.", QMessageBox::Ok);
            return;
        }

    string etat,sexe;
    if (ui->maladePatAdd_2->isChecked())
    etat="malade";
    else etat="sain";

    if (ui->hommeAddPat_2->isChecked()) sexe = "Homme";
    else sexe ="Femme";

    Connexion c;
    if(c.updatePat(ui->idPatUpdate->value(),ui->agePatAdd_2->value(),ui->nomPatAdd_2->text().toStdString(),ui->pnomPatAdd_2->text().toStdString(),etat,sexe))
    {
        ui->listViewHistorique->addItem("Patient modifié avec ID : " + QString::number(ui->idPatUpdate->value()));
        saveHistoriqueToFile("C:/Users/pc/Desktop/unt2/historique.txt");


    }

    QMessageBox::information(this, "Confirmation ", "Patient modifié.", QMessageBox::Ok);


}



void MainWindow::on_pushButton_48_clicked()
{
    Connexion c;

    c.displayPatInListViewUpdate(ui->listViewGeneral,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewUpdate,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewDelete,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewAdd,c.selectAllPat());
}

void MainWindow::on_pushButton_56_clicked()
{
    Connexion c;

    c.displayPatInListViewUpdate(ui->listViewGeneral,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewUpdate,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewDelete,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewAdd,c.selectAllPat());
}

void MainWindow::on_pushButton_38_clicked()
{
    Connexion c;

    c.displayPatInListViewUpdate(ui->listViewGeneral,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewUpdate,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewDelete,c.selectAllPat());
    c.displayPatInListViewUpdate(ui->listViewAdd,c.selectAllPat());
}

void MainWindow::on_qr_clicked()
{
    Traitement T;
    T.QrCode("text eli hachti bih");
}








void MainWindow::on_pushButton_22_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/pc/Desktop/unt2/patient.pdf");

    // Créer un objet QPainter associé à l'imprimante
    QPainter painter;
    if (!painter.begin(&printer)) {
        qWarning("Failed to open file for writing, is it writable?");
        return;
    }

    // Définir le style de texte
    QFont font("Arial", 12); // Choisir la police et la taille
    font.setBold(true); // Texte en gras
    painter.setFont(font);

    // Définir la couleur du texte
    QPen penText(Qt::darkBlue); // Couleur du texte
    painter.setPen(penText);

    // Dessiner le texte de la date
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    painter.drawText(50, 50, "Date: " + dateTimeString);

    // Dessiner les images avec une ombre portée
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    QImage image("C:/Users/pc/Desktop/unt2/image2.jpg");
    painter.drawImage(50, 100, image);

    QImage image1("C:/Users/pc/Desktop/unt2/logo.jpg");
    painter.drawImage(400, 100, image1);

    // Dessiner un rectangle autour du titre
    painter.setBrush(Qt::NoBrush); // Pas de remplissage
    painter.setPen(Qt::darkGreen); // Couleur du contour
    painter.drawRect(50, 250, 500, 50); // Rectangle autour du titre

    // Dessiner le titre du tableau
    painter.drawText(50, 280, "Liste des patients");
    painter.drawLine(50, 295, 550, 295); // Ligne sous le titre

    // Définir la couleur du texte pour le tableau
    painter.setPen(Qt::black);

    // Dessiner les en-têtes de colonne
    painter.drawText(50, 320, "ID_P");
    painter.drawText(150, 320, "NOM_P");
    painter.drawText(300, 320, "PRENOM_P");
    painter.drawText(450, 320, "ETAT");
    painter.drawText(550, 320, "SEXE_P");
    painter.drawText(650, 320, "AGE");

    // Dessiner les données du tableau
    QSqlQuery qry;
    if (!qry.exec("SELECT * FROM PATIENT")) {
        qWarning() << "Query execution failed:" << qry.lastError().text();
        painter.end();
        return;
    }

    int yPos = 350; // Position verticale initiale
    while (qry.next()) {
        QString id_p = qry.value(0).toString();
        QString nom_p = qry.value(1).toString();
        QString prenom_p = qry.value(2).toString();
        QString etat = qry.value(3).toString();
        QString sexe_p = qry.value(4).toString();
        QString age = qry.value(5).toString();

        // Dessiner les données dans les colonnes correspondantes
        painter.drawText(50, yPos, id_p);
        painter.drawText(150, yPos, nom_p);
        painter.drawText(300, yPos, prenom_p);
        painter.drawText(450, yPos, etat);
        painter.drawText(550, yPos, sexe_p);
        painter.drawText(650, yPos, age);

        yPos += 30; // Augmenter la position verticale pour la prochaine ligne
    }

    // Terminer le dessin
    painter.end();
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/pc/Desktop/unt2/patient.pdf"));


}



void MainWindow::on_lineEdit_2_textChanged(const QString &arg2)
{
    Connexion c;

    QVector<QStringList> a = c.selectAllPat();
    QVector<QStringList> finalList;

    // Déclaration de sortOrder et obtention de l'ordre de tri en fonction de l'état du bouton radio
    QString sortOrder = ui->radioTri_2->isChecked() ? "ASC" : "DESC";

    // Si le bouton de tri est activé, utiliser selectAllPatTri avec l'ordre de tri spécifié
    if (ui->radioTri_2->isChecked())
        a = c.selectAllPatTri(sortOrder);

    QStringList b;
    for (QStringList Pat : a) {
        if (Pat[1].contains(arg2)){
            b.append(Pat);
            finalList.append(b);
            b.clear();
        }
    }

    // Afficher les données filtrées dans listViewGeneral
    c.displayPatInListViewUpdate(ui->listViewGeneral, finalList);

    // Si la barre de recherche est vide, afficher toutes les données
    if (arg2.isEmpty()) {
        c.displayPatInListView(ui->listViewGeneral);
    }
}

void MainWindow::on_radioTri_2_toggled(bool checked1)
{
    Connexion c;
    if (checked1) {
        QString sortOrder = ui->radioTri_2->isChecked() ? "ASC" : "DESC"; // Déterminer l'ordre de tri en fonction du bouton radio
        c.displayPatInListViewUpdate(ui->listViewGeneral, c.selectAllPatTri(sortOrder));
    } else {
        c.displayPatInListView(ui->listViewGeneral);
    }
}


void MainWindow::on_pushButton_23_clicked()
{
    Dialog d;
    d.show();
    d.exec();
}
void MainWindow::saveHistoriqueToFile(const QString& filename)
{
    // Ouvrir le fichier en mode écriture
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Impossible d'ouvrir le fichier pour sauvegarder l'historique.";
        return;
    }

    // Créer un flux texte pour écrire dans le fichier
    QTextStream out(&file);

    // Parcourir tous les éléments de l'historique et les écrire dans le fichier
    for (int i = 0; i < ui->listViewHistorique->count(); ++i)
    {
        out << ui->listViewHistorique->item(i)->text() << "\n";
    }

    // Fermer le fichier
    file.close();
}

void MainWindow::loadHistoriqueFromFile(const QString& filename)
{
    // Ouvrir le fichier en mode lecture
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Impossible d'ouvrir le fichier pour charger l'historique.";
        return;
    }

    // Créer un flux texte pour lire depuis le fichier
    QTextStream in(&file);

    // Effacer les éléments actuels de la QListWidget
    ui->listViewHistorique->clear();

    // Lire chaque ligne du fichier et ajouter son contenu à la QListWidget
    while (!in.atEnd())
    {
        QString line = in.readLine();
        ui->listViewHistorique->addItem(line);
    }

    // Fermer le fichier
    file.close();
}

void MainWindow::on_pushButton_63_clicked()
{
    // Charger les données depuis le fichier avant d'afficher

    loadHistoriqueFromFile("C:/Users/pc/Desktop/unt2/historique.txt");

    // Afficher les notifications dans la QListWidget
    Connexion c;
    c.displayNotificationsInListWidget(ui->listViewHistorique);
}


