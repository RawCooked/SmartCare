#ifndef PATIENT_H
#define PATIENT_H


#include <iostream>
#include <QString>
#include <QDate>
using namespace std;


class Patient
{
private :
    int id_p,age;
    QString nom_p,prenom_p,etat,sexe_p;


public:

    //Constructor & Destructor

    Patient();
    Patient(int,int,QString,QString,QString,QString);
    ~Patient();

    //Getters

    int idpGet();
    int agepGet();
    QString nompGet();
    QString prenompGet();
    QString etatpGet();
    QString sexepGet();

    //Setters

    void idpSet(int newIdp);
    void agepSet(int newAgep);
    void nompSet(const QString& newNomp);
    void prenompSet(const QString& newPrenomp);
    void etatpSet(const QString& newEtatp);
    void sexepSet(const QString& newSexep);
};


#endif // PATIENT_H
