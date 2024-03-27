#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <cstdlib>
using namespace std;
class users
{
private:
    int id_u;
    QString user_name,mdp,etat;
public:
    users();
    users(int,QString,QString,QString);
    ~users();
    int getid_u(){return id_u;}
    QString getuser_name(){return user_name;}
    QString getmdp(){return mdp;}
    QString getetat(){return etat;}
    void setid_u(int id){id_u=id;}
    void setuser_name(QString u){user_name=u;}
    void setmdp(QString m){mdp=m;}
    void setetat(QString e){etat=e;}
    bool ajouter();
 //   QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool update_mdp(QString UN,QString motp);
};
QString generateRandomString(int length);
#endif // USERS_H
