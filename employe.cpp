#include "employe.h"

Employe::Employe()
{

}
Employe::Employe(string nom,string prenom,string etat,string sexe,float salaire)
{
    this->nom=nom;
    this->prenom=prenom;
    this->etat=etat;
    this->sexe=sexe;
    this->salaire=salaire;
}
Employe::~Employe()
{

}
