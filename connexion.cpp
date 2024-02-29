#include "connexion.h"
#include "traitement.h"
#include "materiel.h"
#include<QString>

#include<string>

Connexion::Connexion()
{
}

bool Connexion::ouvrirConnexion()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("SYSTEM");
    db.setPassword("hedi");

    if (db.open()) {
        qDebug() << "Connected to database";
        return true;
    } else {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
        return false;
    }
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
bool Connexion::addmateriel(materiel m)
{
    // Préparez la requête SQL
    QString queryString = "INSERT INTO MATERIEL(ID_MAT,NOM_MAT,CATEGORIE,ETAT) VALUES (:id_mat,:nom_mat,:categorie,:etat);";


    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":id_mat",QString::fromStdString (m.id_matGet()));
    query.bindValue(":nom_mat", QString::fromStdString(m.nom_matGet()));
    query.bindValue(":categorie", QString::fromStdString(m.categorieGet()));
    query.bindValue(":etat", QString::fromStdString(m.etatGet()));



    // Exécutez la requête
        qDebug() << "Requête SQL : " << queryString;
        if (query.exec()) {
            qDebug() << "Materiel ajouté avec succès.";
            return true;
        } else {
            qDebug() << "Erreur lors de l'ajout du materiel : " << query.lastError().text();
            return false;
        }

}

bool Connexion::deletemateriel(std::string id_mat)
{
    QString queryString = "DELETE FROM MATERIEL WHERE id_mat = :id_mat;";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":id_mat", QString::fromStdString(id_mat));


    if (query.exec()) {
        qDebug() << "WorkShop deleted successfully.";
        return true;
    } else {
        qDebug() << "Error deleting WorkShop: " << query.lastError().text();
        return false;
    }
}

bool Connexion::updateMateriel(materiel m)
{
    QSqlQuery query;
    query.prepare("UPDATE MATERIEL SET nom_mat = :nom_mat, etat = :etat, categorie = :categorie WHERE id_mat = :id_mat");
    query.bindValue(":nom_mat", QString::fromStdString(m.nom_matGet()));
    query.bindValue(":categorie", QString::fromStdString(m.categorieGet()));
    query.bindValue(":etat", QString::fromStdString(m.etatGet()));
     query.bindValue(":id_mat",QString::fromStdString (m.id_matGet()));

    if (query.exec()) {
        qDebug() << "WorkShop updated successfully.";
        return true;
    } else {
        qDebug() << "Error updating WorkShop: " << query.lastError().text();
        return false;
    }
}

QVector<QStringList> Connexion::selectAllMateriel()
{
    QVector<QStringList> result;
    // Execute the query
    QSqlQuery query("SELECT * FROM MATERIEL");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}

void Connexion::displayWMAterieltInListView(QListView *listView)
{
    // Assuming listView is a valid pointer to your QListView

    // Fetch the data from the database
    QVector<QStringList> data = selectAllMateriel();

    // Prepare a QStringListModel to hold the data
    QStringListModel* model = new QStringListModel();

    // Iterate through the data and add it to the model
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", ")); // You can customize the separator as needed
    }
    // Set the model for the QListView
    listView->setModel(model);
    // Optionally, set the view mode (e.g., ListMode)
    listView->setViewMode(QListView::ListMode);
    // Optionally, set other properties or customize the appearance
    // Show the QListView
    listView->show();
}
