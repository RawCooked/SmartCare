#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QtSql>
#include<iostream>
#include <QStringListModel>
#include <QListView>
#include "traitement.h"
#include "materiel.h"

const QString databaseName = "projetcpp";


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
    //materiel


    bool addmateriel(materiel m);
    QVector<QStringList> selectAllMateriel();
    void displayMatlnListView(QListView *listView);
    bool deletemateriel(int id_mat);
    bool updateMateriel(materiel m);
    void displayMaterielslnListView(QListView* listView);
    void displayWMAterieltInListView(QListView *listView);
};
#endif // CONNEXION_H
