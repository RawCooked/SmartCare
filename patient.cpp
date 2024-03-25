#include "patient.h"

Patient::Patient(int id,int ag,QString nom,QString prenom,QString eta,QString sexe)
{
    id_p=id;
    age=ag;
    nom_p=nom;
    prenom_p=prenom;
    etat=eta;
    sexe_p=sexe;
}
Patient::~Patient()
{

}

int Patient:: idpGet()
{
    return id_p;
}
int Patient::agepGet()
{
    return age;
}
QString Patient::nompGet()
{
    return nom_p;
}
QString Patient::prenompGet()
{
    return prenom_p;
}
QString Patient::etatpGet()
{
    return etat;
}
QString Patient::sexepGet()
{
    return sexe_p;
}

void Patient::idpSet(int newIdp)
{
    id_p = newIdp;
}
void Patient::agepSet(int newAgep)
{
    age = newAgep;
}
void Patient::nompSet(const QString& newNomp)
{
    nom_p = newNomp;
}
void Patient::prenompSet(const QString& newPrenomp)
{
    prenom_p = newPrenomp;
}
void Patient::etatpSet(const QString& newEtatp)
{
    etat = newEtatp;
}
void Patient::sexepSet(const QString& newSexep)
{
    sexe_p = newSexep;
}






