#include "connexion.h"
#include "materiel.h"
#include<QString>
#include <string>

bool Connexion::addmateriel(int id,QString nom,int nb,QString cat,QString et)
{
    // Prepare the SQL query
    QString queryString = "INSERT INTO MATERIEL (ID_MAT, NOM_MAT, NB_MAT, CATEGORIE, ETAT) VALUES ("
                + QString::number(id) + ", '" + QString::fromStdString(nom) + "', '"
                + QString::number(nb) + "', '" + QString::fromStdString(cat) + "', '"
                + QString::fromStdString(et) + "')";

    QSqlQuery query;
    query.prepare(queryString);

    // Execute the query
    if (query.exec()) {
        std::cout << "Traitement added successfully." << std::endl;
        return true;
    } else {
        std::cout << "Error adding Traitement: " << query.lastError().text().toStdString() << std::endl;
        return false;
    }
}



