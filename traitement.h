#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <iostream>
#include <QString>
#include <QDate>

using namespace std;


class Traitement
{
private :
    int id_trait;
    string type,desc;
    QDate date;
    float prix;


public:

    //Constructor & Destructor

    Traitement();
    Traitement(int,string,QDate,string,float);
    ~Traitement();

    //Getters

    int idGet();
    string typeGet();
    QDate dateGet();
    string descGet();
    float prixGet();

    //Setters

    void idSet(int newId);
    void typeSet(const string& newType);
    void dateSet(const QDate& newDate);
    void descSet(const string& newDesc);
    void prixSet(float newPrix);

    //database

    bool ajouterTraitement(Traitement);
    bool supprimerTraitement(Traitement);

    //metier
    void QrCode(QString);

};

#endif // TRAITEMENT_H
