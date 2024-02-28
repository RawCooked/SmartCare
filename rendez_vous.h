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
    QString type_r;
    int idr=0,prix_r;
    QDate date_r;
public:
    //constructeurs
    Rdv() {};
    Rdv(int,QDate,int,QString );
    ~Rdv() {};
    // getters
    int GetIdr (){return idr;}
    QString GetType (){return type_r;}
    QDate Getdate(){return date_r;}
    int Getprix (){return prix_r;}
    // setters
    void SetIdr (int d){ idr=d;}
    void SetType (QString t){type_r =t;}
    void Setdate(QDate d){date_r =d;}
    void Setprix (int p){ prix_r=p;}
    //methodes
    bool ajouterR ();
    QVector<QStringList> selectAllRdv();
    void displayRdvInListView(QListView* listView);
    bool supprimerR (int);
    QSqlQueryModel * rechercherR(const QString &);
    QSqlQueryModel * trierR(const QString &critere, const QString &mode );
    bool modifierR(int ,QDate, int , QString);
};
#endif // RENDEZ_VOUS_H
