#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>
#include <QSqlQueryModel>
#include <QStringListModel>
#include <QSqlRecord>
Employe::Employe()
{

}
Employe::Employe(int id,QString nom,QString prenom,QString etat,QString sexe,double salaire)
{
    this->id_emp=id;
    this->nom=nom;
    this->prenom=prenom;
    this->etat=etat;
    this->sexe=sexe;
    this->salaire=salaire;
}
Employe::~Employe()
{

}
bool Employe ::ajouter()
{
    QSqlQuery query;
    QString ID_C_QString=QString::number(id_emp);
          query.prepare("INSERT INTO Employe (nom_e,prenom_e,Etat,sexe_emp,salaire) "
                        "VALUES ( :nom_e, :prenom_e, :Etat, :sexe_emp, :salaire)");
          //query.bindValue(":id_emp", ID_C_QString);
          query.bindValue(":nom_e", nom);
          query.bindValue(":prenom_e", prenom);
          query.bindValue(":Etat", etat);
          query.bindValue(":sexe_emp",sexe);
          query.bindValue(":salaire",salaire);

          return query.exec();
}
QSqlQueryModel* Employe ::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM Employe");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_emp"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("etat"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("sexe"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaire"));

    return  model ;
}
QVector<QStringList> selectAllEmp()
{
    QVector<QStringList> result;

    QSqlQuery query("SELECT * FROM Employe");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }
    return result;
}

void displayEmployesInListView(QListView* listView)
{
    QVector<QStringList> data = selectAllEmp();
    QStringListModel* model = new QStringListModel();
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", "));
    }
    listView->setModel(model);
    listView->setViewMode(QListView::ListMode);
    listView->show();
}
bool Employe::supprimer(int ID_E)     //
{
   QSqlQuery query;
   //QString ID_C=QString::number(ID_C);// conversion

  query.prepare("Delete from Employe where id_emp = :id_emp ");
   query.bindValue(":id_emp",ID_E);
   return query.exec();
}
bool Employe::modifier(int ide,QString nom,QString prenom,QString etat,QString sexe,double salaire)
{   QSqlQuery query;
    query.prepare( "UPDATE Employe SET nom_e=:nom_e,prenom_e=:prenom_e,Etat=:Etat,sexe_emp=:sexe_emp,salaire=:salaire WHERE id_emp=:id_emp;");
    query.bindValue(":id_emp", ide);
    query.bindValue(":nom_e", nom);
    query.bindValue(":prenom_e", prenom);
    query.bindValue(":Etat", etat);
    query.bindValue(":sexe_emp",sexe);
    query.bindValue(":salaire",salaire);
 return query.exec();
}
