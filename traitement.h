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
    QString type,desc;
    float prix;
    QDate date;

public:

    //Constructor & Destructor

    Traitement();
    Traitement(int,QString,QDate,QString,float);
    ~Traitement();

    //Getters

    int idGet();
    QString typeGet();
    QString dateGet();
    QString descGet();
    float prixGet();

    //Setters

    void idSet(int newId);
    void typeSet(const QString& newType);
    void dateSet(const QDate& newDate);
    void descSet(const QString& newDesc);
    void prixSet(float newPrix);

};

#endif // TRAITEMENT_H
