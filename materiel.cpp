#include "materiel.h"

materiel::materiel(int id,std::string n,std::string c,std::string e)
{
    id_mat=id ;
    nom_mat=n ;

    categorie=c ;
    etat=e ;
}
materiel::materiel(std::string n,std::string c,std::string e)
{

    nom_mat=n ;

    categorie=c ;
    etat=e ;
}

materiel::~materiel()
{

}
int materiel::id_matGet()
{
    return id_mat ;
}
std::string materiel::nom_matGet()
{
    return nom_mat ;
}

std::string materiel::categorieGet()
{
    return categorie ;
}
std::string materiel::etatGet()
{
    return etat ;
}
void materiel::id_matSet(int id)
{
    id_mat=id ;
}
void materiel::nom_matSet(std::string& newname)
{
    nom_mat=newname ;
}

void materiel::categorieSet(std::string& newcat)
{
    categorie=newcat ;
}
void materiel::etatSet(std::string& newetat)
{
    etat = newetat ;
}
