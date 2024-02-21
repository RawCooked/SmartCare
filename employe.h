#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
using namespace std;
class Employe
{
private:
    string nom,prenom,etat,sexe;
    float salaire;
public:
    Employe();
    Employe(string,string,string,string,float);
    ~Employe();
    void set_nom(string nom){this->nom=nom;}
    void set_prenom(string prenom){this->prenom=prenom;}
    void set_etat(string etat){this->etat=etat;}
    void set_salaire(float salaire){this->salaire=salaire;}
    void set_sexe(string sexe){this->sexe=sexe;}
    string get_nom(){return nom;}
    string get_prenom(){return prenom;}
    string get_etat(){return etat;}
    float get_salaire(){return salaire;}
    string get_sexe(){return sexe;}
};

#endif // EMPLOYE_H
