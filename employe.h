#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QListView>
using namespace std;
class Employe
{
private:
    int id_emp;
    QString nom,prenom,etat,sexe;
    double salaire;
public:
    Employe();
    Employe(int,QString,QString,QString,QString,double);
    ~Employe();
    void set_id_emp(int id){this->id_emp=id;}
    void set_nom(QString nom){this->nom=nom;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_etat(QString etat){this->etat=etat;}
    void set_salaire(double salaire){this->salaire=salaire;}
    void set_sexe(QString sexe){this->sexe=sexe;}
    int get_id_emp(){return id_emp;}
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_etat(){return etat;}
    double get_salaire(){return salaire;}
    QString get_sexe(){return sexe;}
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int ID_C);
    bool modifier(int ide,QString nom,QString prenom,QString etat,QString sexe,double salaire);
    QSqlQueryModel * rechercher (QString aux);
    QSqlQueryModel *  trier(QString critere, QString mode );
    int NbreEmploye();
    QMap<QString, int> getEmployeStatisticsByCategory();
};
QVector<QStringList> selectAllEmp();
void displayEmployesInListView(QListView* listView);
#endif // EMPLOYE_H
