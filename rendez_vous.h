#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H
#include <iostream>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlDatabase>
#include <QtSql>
#include <QStringListModel>
#include <QListView>

using namespace std;
class Rdv
{
    QString type_r,heure_r;
    int idr=0,prix_r;
    QDate date_r;
public:
    //constructeurs
    Rdv() {};
    Rdv(int,QDate,int,QString,QString );
    ~Rdv() {};
    // getters
    int GetIdr (){return idr;}
    QString GetType (){return type_r;}
    QDate Getdate(){return date_r;}
    int Getprix (){return prix_r;}
    QString Getheure(){return heure_r;}
    // setters
    void SetIdr (int d){ idr=d;}
    void SetType (QString t){type_r =t;}
    void Setdate(QDate d){date_r =d;}
    void Setprix (int p){ prix_r=p;}
    void Setheure(QString h){ heure_r =h;}
    //methodes
    bool ajouterR ();
    QVector<QStringList> selectAllRdv();
    void displayRdvInListView(QListView* listView);
    bool supprimerR (int);
    bool modifierR(int idr,QDate date_r, int prix_r, QString type_r,QString heure_r);
    QVector<QStringList> selectAllRdvTri();
    void displayRdvInListViewTri(QListView* listView);
    QVector<QStringList> selectAllRdvByType();
    QMap<QString, int> getRdvlStatisticsByType();
    bool displayRdvListViewUpdated(QListView* listView, QVector<QStringList> data);

};
#endif // RENDEZ_VOUS_H
