#include "rendez_vous.h"
#include <QDateEdit>
#include<string>
Rdv:: Rdv(int ID,QDate d ,int pr,QString t)
{    type_r = t ;
     date_r = d;
      idr=ID ;
       prix_r = pr;
}
bool Rdv::ajouterR ()
{
    QSqlQuery query ;
    QString var2 = QString :: number (prix_r);
    // prepare() : prend la requete en parametre pour la preparer a l'execution
    query.prepare("insert into RDV (TYPE_R,DATE_R,PRIX_R)""values (:type,:date,:prix)");
    //creation des variables liées
    query.bindValue(":type",type_r);
    query.bindValue(":date",date_r);
    query.bindValue(":prix",var2);

    return query.exec(); //exec() : envoie la requete pour l'executer

}
QVector<QStringList> Rdv::selectAllRdv()
{
    QVector<QStringList> result;

    // Execute the query
    QSqlQuery query("SELECT * FROM RDV");

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

     query.prepare("Delete from RDV where idr = :id_r ");
      query.bindValue(":id_r",idre);
      return query.exec();

}
QSqlQueryModel * Rdv::rechercherR(const QString &x)
{
    QSqlQueryModel * model = new QSqlQueryModel();

        model->setQuery("select * from rdv where ((ids || type || dates || prix ) LIKE '%"+x+"%')");
 return model;

}
QSqlQueryModel * Rdv::trierR(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv order by "+critere+" "+mode+"");

    return model;

}
bool Rdv::modifierR(int idr,QDate date_r, int prix_r, QString type_r)
{

    QSqlQuery query;
    query.prepare("UPDATE rdv SET TYPE_R=:type_r, DATE_R=:date_r,PRIX_R=:prix_r WHERE IDR=:idr");

    query.bindValue(":idr", idr);
    query.bindValue(":type_r", type_r);
    query.bindValue(":date_r", date_r);
    query.bindValue(":prix_r", prix_r);

    return query.exec();
}
