#ifndef MATERIEL_H
#define MATERIEL_H
#include <iostream>
#include <QString>
#include <QDate>
using namespace std;
class materiel
{
private:
    std::string id_mat ;
    std::string nom_mat ;
    std::string categorie ;
    std::string etat ;
public:

    materiel();
    materiel(std::string,std::string,std::string,std::string);
    ~materiel();
    std::string id_matGet();
    std::string nom_matGet();
    std::string categorieGet();
    std::string etatGet();
    void id_matSet(std::string& id);
    void nom_matSet(std::string& newname);
    void categorieSet(std::string& newcat);
    void etatSet(std::string& newetat);
};

#endif // MATERIEL_H
