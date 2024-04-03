#include "rendez_vous.h"
#include <QDateEdit>
#include<string>
#include <QSqlQueryModel>
#include <QSqlQuery>
Rdv:: Rdv(int ID,QDate d ,int pr,QString t,QString h)
{    type_r = t ;
     date_r = d;
      idr=ID ;
       prix_r = pr;
        heure_r=h;
}
bool Rdv::ajouterR ()
{
    QSqlQuery query ;
    QString var2 = QString :: number (prix_r);
    // prepare() : prend la requete en parametre pour la preparer a l'execution
    query.prepare("insert into rdvv (TYPE_R,DATE_R,PRIX_R,HEURE_R)""values (:type,:date,:prix,:heure)");
    //creation des variables liées
    query.bindValue(":type",type_r);
    query.bindValue(":date",date_r);
    query.bindValue(":prix",var2);
    query.bindValue(":heure",heure_r);

    return query.exec(); //exec() : envoie la requete pour l'executer

}
QMap<QString, int> Rdv::getRdvlStatisticsByType() {
    QMap<QString, int> statistics;

    // Récupérer tous les rdv de la base de données
    QVector<QStringList> r = selectAllRdvByType();

    // Parcourir les données pour compter le nombre de matériaux dans chaque catégorie
    for (const QStringList& rdv : r) {
        QString type = rdv.at(1); // L'indice 1 contient le type du rdv
        if (statistics.contains(type)) {
            statistics[type]++;
        } else {
            statistics[type] = 1;
        }
    }

    return statistics;
}
QVector<QStringList> Rdv::selectAllRdvByType()
{
    QVector<QStringList> result;


    // Execute the query
    QSqlQuery query("SELECT * FROM RDVV ORDER BY type_r");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}
QVector<QStringList> Rdv::selectAllRdv()
{
    QVector<QStringList> result;

    // Execute the query
    QSqlQuery query("SELECT * FROM RDVV");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}

void Rdv::displayRdvInListView(QListView* listView)
{
    // Assuming listView is a valid pointer to your QListView

    // Fetch the data from the database
    QVector<QStringList> data = selectAllRdv();

    // Prepare a QStringListModel to hold the data
    QStringListModel* model = new QStringListModel();

    // Iterate through the data and add it to the model
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", ")); // You can customize the separator as needed
    }

    // Set the model for the QListView
    listView->setModel(model);

    // Optionally, set the view mode (e.g., ListMode)
    listView->setViewMode(QListView::ListMode);

    // Optionally, set other properties or customize the appearance

    // Show the QListView
    listView->show();
}


bool Rdv::supprimerR (int idre)
{
   /* QSqlQuery query;
    query.prepare("Delete from rdv where IDR = :idr ");
    query.bindValue(":idr", idr);
    return    query.exec();
        if (query.exec()) {
            qDebug() << "WorkShop deleted successfully.";
            return true;
        } else {
            qDebug() << "Error deleting WorkShop: " << query.lastError().text();
            return false;
            }*/


    QSqlQuery query;
      //QString ID_C=QString::number(ID_C);// conversion

     query.prepare("Delete from RDVV where idr = :id_r ");
      query.bindValue(":id_r",idre);
      return query.exec();

}




bool Rdv::modifierR(int idr,QDate date_r, int prix_r, QString type_r,QString heure_r)
{

    QSqlQuery query;
    query.prepare("UPDATE rdvv SET TYPE_R=:type_r, DATE_R=:date_r,PRIX_R=:prix_r,HEURE_R=:heure_r WHERE IDR=:idr");

    query.bindValue(":idr", idr);
    query.bindValue(":type_r", type_r);
    query.bindValue(":date_r", date_r);
    query.bindValue(":prix_r", prix_r);
    query.bindValue(":heure_r", heure_r);

    return query.exec();
}

///


QVector<QStringList> Rdv::selectAllRdvTri()
{
    QVector<QStringList> result;

    // Execute the query
    QSqlQuery query("SELECT * FROM rdvv ORDER BY PRIX_R DESC");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}

void Rdv::displayRdvInListViewTri(QListView* listView)
{

    QVector<QStringList> data = selectAllRdvTri();


    QStringListModel* model = new QStringListModel();

    // Iterate through the data and add it to the model
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", ")); // You can customize the separator as needed
    }

    // Set the model for the QListView
    listView->setModel(model);

    // Optionally, set the view mode (e.g., ListMode)
    listView->setViewMode(QListView::ListMode);

    // Optionally, set other properties or customize the appearance

    // Show the QListView
    listView->show();
}
bool Rdv::displayRdvListViewUpdated(QListView* listView, QVector<QStringList> data)
{
    // Vérifie si listView est un pointeur valide vers votre QListView
    if (!listView)
        return false;

    // Prépare un QStringListModel pour contenir les données
    QStringListModel* model = new QStringListModel();

    // Itérer à travers les données et les ajouter au modèle
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", ")); // Vous pouvez personnaliser le séparateur au besoin
    }

    // Définir le modèle pour le QListView
    listView->setModel(model);

    // Facultativement, définir le mode d'affichage (par exemple, ListMode)
    listView->setViewMode(QListView::ListMode);

    // Facultativement, définir d'autres propriétés ou personnaliser l'apparence

    // Afficher le QListView
    listView->show();

    return true;
}

