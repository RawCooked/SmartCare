#include "traitement.h"



Traitement::Traitement(int id,QString t,QDate d,QString de,float p){
    id_trait=id;
    type=t;
    date=d;
    desc=de;
    prix=p;
}

Traitement::~Traitement()
{

}


int Traitement::idGet() {
    return id_trait;
}

QString Traitement::typeGet() {
    return type;
}

QString Traitement::dateGet() {
    return date.toString("yyyy-MM-dd HH:mm:ss");
}

QString Traitement::descGet() {
    return desc;
}

float Traitement::prixGet() {
    return prix;
}

void Traitement::idSet(int newId) {
    id_trait = newId;
}

void Traitement::typeSet(const QString& newType) {
    type = newType;
}

void Traitement::dateSet(const QDate& newDate) {
    date = newDate;
}

void Traitement::descSet(const QString& newDesc) {
    desc = newDesc;
}

void Traitement::prixSet(float newPrix) {
    prix = newPrix;
}

