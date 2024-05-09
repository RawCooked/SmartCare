#include "traitement.h"
#include "connexion.h"
#include "QZXing.h"
#include <QImage>



Traitement::Traitement(int id,string t,QDate d,string de,float p){
    id_trait=id;
    type=t;
    date=d;
    desc=de;
    prix=p;
}

Traitement::Traitement()
{

}


Traitement::~Traitement()
{

}


int Traitement::idGet() {
    return id_trait;
}

string Traitement::typeGet() {
    return type;
}

QDate Traitement::dateGet() {
    return date;
}

string Traitement::descGet() {
    return desc;
}

float Traitement::prixGet() {
    return prix;
}

void Traitement::idSet(int newId) {
    id_trait = newId;
}

void Traitement::typeSet(const string& newType) {
    type = newType;
}

void Traitement::dateSet(const QDate& newDate) {
    date = newDate;
}

void Traitement::descSet(const string& newDesc) {
    desc = newDesc;
}

void Traitement::prixSet(float newPrix) {
    prix = newPrix;
}

bool Traitement::ajouterTraitement(Traitement T){
    Connexion c;

    QString format = "dd-MM-yyyy";

      // Convert QDate to QString using string arguments
      QString dateString = QString("%3-%2-%1")
          .arg(T.date.year())
          .arg(T.date.month(), 2, 10, QChar('0')) // Pad month with zeros
          .arg(T.date.day(), 2, 10, QChar('0'));

    return c.addTrait(T.idGet(),T.typeGet(),dateString.toStdString(),T.descGet(),T.prixGet());
}

bool Traitement::supprimerTraitement(Traitement T){
    Connexion c;
    return c.deleteTrait(T.id_trait);
}

void Traitement::QrCode(QString textToEncode){
    QZXing decoder;
    QImage qrCodeImage = decoder.encodeData(textToEncode);
    qrCodeImage.save("C:/Users/pc/Desktop/qrcode.png");
}

