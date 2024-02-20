#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QtSql>
#include<iostream>
#include <QStringListModel>
#include <QListView>
#include "traitement.h"

const QString databaseName = "IDRISS";


class Connexion
{
private:
    QSqlDatabase db;

public:

    //connexion
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

    //Traitement
    bool addTrait(Traitement);
    QVector<QStringList> selectAllTrait();
    void displayTraitInListView(QListView *listView);
    bool updateTrait(const QString &oldUsername, const QString &newUsername, const QString &newPassword);
    bool deleteTrait(int);


};


#endif // CONNEXION_H
