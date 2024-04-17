#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QtSql>
#include<iostream>
#include <QStringListModel>
#include <QListView>
#include <QLabel>
#include <QWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QApplication>
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
    QVector<QStringList> selectAllMatById();
    QMap<QString, int> getMaterialStatisticsByCategory();
   QSqlQueryModel* displaySortedMaterielInListView(const QString& critere, const QString& mode);
    QSqlQueryModel * rechercherParId(const QString &id);

    void displayWMAterieltInListView1(QListView *listView, QSqlQueryModel *model);



    QVector<QStringList> selectAllMaterielTri(const QString& sortOrder);
    void displayMaterielInListViewTri(QListView* listView, const QString& sortOrder);

    QVector<QStringList> selectAllMatRecherche(int id_mat);
    void displayMaterielInListViewRecherche(QListView* listView, int id_mat);

   bool deletePatientsEtatNormalAndWriteToFile();
};
#endif // CONNEXION_H
