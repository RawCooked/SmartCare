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

    QString queryString = "INSERT INTO MATERIEL(ID_MAT,NOM_MAT,CATEGORIE,ETAT) VALUES (:id_mat,:nom_mat,:categorie,:etat);";


    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":id_mat", m.id_matGet());
    query.bindValue(":nom_mat", QString::fromStdString(m.nom_matGet()));
    query.bindValue(":etat", QString::fromStdString(m.etatGet()));
    query.bindValue(":categorie", QString::fromStdString(m.categorieGet()));




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

bool Connexion::deletemateriel(int id_mat)
{
    QString queryString = "DELETE FROM MATERIEL WHERE id_mat = :id_mat;";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":id_mat",id_mat);


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
    query.bindValue(":id_mat",m.id_matGet());
    query.bindValue(":nom_mat", QString::fromStdString(m.nom_matGet()));
     query.bindValue(":etat", QString::fromStdString(m.etatGet()));
    query.bindValue(":categorie", QString::fromStdString(m.categorieGet()));



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
    //stocker les resultat de la requete
    QVector<QStringList> result;

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
    QVector<QStringList> data = selectAllMateriel();
    QStringListModel* model = new QStringListModel();
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", "));
    }
    listView->setModel(model);
    listView->setViewMode(QListView::ListMode);
    listView->show();
}
QVector<QStringList> Connexion::selectAllMatById()
{
    QVector<QStringList> result;


    // Execute the query
    QSqlQuery query("SELECT * FROM MATERIEL ORDER BY ID_MAT");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}

QMap<QString, int> Connexion::getMaterialStatisticsByCategory() {
    QMap<QString, int> statistics;

    // Récupérer tous les matériaux de la base de données
    QVector<QStringList> materials = selectAllMateriel();

    // Parcourir les données pour compter le nombre de matériaux dans chaque catégorie
    for (const QStringList& material : materials) {
        QString category = material.at(2); // L'indice 2 contient la catégorie du matériel
        if (statistics.contains(category)) {
            statistics[category]++;
        } else {
            statistics[category] = 1;
        }
    }

    return statistics;
}

QVector<QStringList> Connexion::selectAllMaterielTri(const QString& sortOrder)
{
    QVector<QStringList> result;

    // Construire la requête SQL en fonction de l'ordre de tri
    QString queryString = "SELECT * FROM materiel ORDER BY categorie " + sortOrder;

    // Exécuter la requête
    QSqlQuery query(queryString);

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}
void Connexion::displayMaterielInListViewTri(QListView* listView, const QString& sortOrder)
{
    QVector<QStringList> data = selectAllMaterielTri(sortOrder);

    QStringListModel* model = new QStringListModel();

    // Itérer à travers les données et les ajouter au modèle
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", ")); // Vous pouvez personnaliser le séparateur au besoin
    }

    // Définir le modèle pour le QListView
    listView->setModel(model);

    // Optionnellement, définir le mode d'affichage (par exemple, ListMode)
    listView->setViewMode(QListView::ListMode);

    // Optionnellement, définir d'autres propriétés ou personnaliser l'apparence

    // Afficher le QListView
    listView->show();
}

QVector<QStringList> Connexion::selectAllMatRecherche(int id_mat)
{
    QVector<QStringList> result;

    // Construire la requête SQL avec un paramètre lié
    QSqlQuery query;
    query.prepare("SELECT * FROM MATERIEL WHERE id_mat = :id_mat");
    query.bindValue(":id_mat", id_mat);

    // Exécuter la requête
    if (query.exec()) {
        while (query.next()) {
            QStringList record;
            for (int i = 0; i < query.record().count(); ++i) {
                record << query.value(i).toString();
            }
            result << record;
        }
    } else {
        // Gérer les erreurs si la requête échoue
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    return result;
}

void Connexion::displayMaterielInListViewRecherche(QListView* listView, int id_mat)
{
    QVector<QStringList> data = selectAllMatRecherche(id_mat);

    QStringListModel* model = new QStringListModel();

    // Itérer à travers les données et les ajouter au modèle
    for (const QStringList& record : data) {
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        model->setData(index, record.join(", ")); // Vous pouvez personnaliser le séparateur au besoin
    }

    // Définir le modèle pour le QListView
    listView->setModel(model);

    // Optionnellement, définir le mode d'affichage (par exemple, ListMode)
    listView->setViewMode(QListView::ListMode);

    // Optionnellement, définir d'autres propriétés ou personnaliser l'apparence

    // Afficher le QListView
    listView->show();
}
