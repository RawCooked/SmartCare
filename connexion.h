#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QtSql>
#include<iostream>
#include <QStringListModel>
#include <QListView>
#include "traitement.h"

const QString databaseName = "test-bd";


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
    bool addTrait(int id, string type, string date, string desc, float prix);
    QVector<QStringList> selectAllTrait();
    QVector<QStringList> selectAllTraitTri();
    void displayTraitInListView(QListView *listView);
    bool updateTrait(const QString &oldUsername, const QString &newUsername, const QString &newPassword);
    bool deleteTrait(int);
    void displayTraitmentsInListView(QListView* listView);
    bool updateTrait(int id, std::string type, std::string date, std::string desc, float prix);
    bool displayTraitmentsInListViewUpdated(QListView *listView,QVector<QStringList>);
    QVector<QStringList> selectAllTraitById();
    void Bash();
    QStringList selectTraitById(int);
    QVector<QStringList> selectAllPat();
    bool updatePat(int id_p, int age, std::string nom_p, std::string prenom_p, std::string etat, std::string sexe_p);
    bool addPat(int id_p, int age, std::string nom_p, std::string prenom_p, std::string etat, std::string sexe_p);
    bool deletePat(int id);
    void displayPatInListViewUpdate(QListView*, QVector<QStringList>);
    QVector<QStringList> selectAllPatById();
    QVector<QStringList> selectAllPatTri(const QString& sortOrder);
    void displayPatInListView(QListView* listView);


};


#endif // CONNEXION_H
