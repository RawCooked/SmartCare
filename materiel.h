#ifndef MATERIEL_H
#define MATERIEL_H
#include <iostream>
#include <QString>
#include <QDate>
#include <QStringListModel>
#include<QString>
#include<string>
#include <QSqlQueryModel>
#include <QtSql>
using namespace std;
class materiel
{
private:
    int id_mat ;
    std::string nom_mat ;
     std::string etat ;
    std::string categorie ;

public:

    materiel();
    materiel(int,std::string,std::string,std::string);
     materiel(std::string,std::string,std::string);
    ~materiel();
    int id_matGet();
    std::string nom_matGet();
    std::string categorieGet();
    std::string etatGet();
    void id_matSet(int id);
    void nom_matSet(std::string& newname);
    void categorieSet(std::string& newcat);
    void etatSet(std::string& newetat);

};

#endif // MATERIEL_H