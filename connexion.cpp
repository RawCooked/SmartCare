#include "connexion.h"
#include "traitement.h"
#include<string>

Connexion::Connexion()
{
}

bool Connexion::ouvrirConnexion()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("system");
    db.setPassword("cscorner");

    if (db.open()) return true;
    return false;
}

void Connexion::fermerConnexion()
{
    db.close();
}

bool Connexion::addTrait(Traitement T)
{
    QString queryString = "INSERT INTO TRAITEMENT (id_trait, type_Trait, date_Trait, desc_Trait, prix) VALUES (:id, :type, :date, :desc, :prix)";
    QSqlQuery query;
    query.prepare(queryString);

    query.bindValue(":id", QString::number(T.idGet())); // Convert int to QString
    query.bindValue(":type", T.typeGet());
    query.bindValue(":date", T.dateGet()); // Convert QDate to QString with specific format
    query.bindValue(":desc", T.descGet());
    query.bindValue(":prix", T.prixGet()); // Assuming prix is already a QString

    if (query.exec()) {
        qDebug() << "User created successfully.";
        return true;
    } else {
        qDebug() << "Error creating user: " << query.lastError().text();
        return false;
    }
}



QVector<QStringList> Connexion::selectAllTrait()
{
    QVector<QStringList> result;

    // Execute the query
    QSqlQuery query("SELECT * FROM traitement");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}

bool Connexion::deleteTrait(int id)
{
    QString queryString = QString("DELETE FROM TRAITEMENT WHERE id_trait='%1'").arg(id);

    QSqlQuery query;
    if (query.exec(queryString)) {
        qDebug() << "User deleted successfully.";
        return true;
    } else {
        qDebug() << "Error deleting user: " << query.lastError().text();
        return false;
    }
}

