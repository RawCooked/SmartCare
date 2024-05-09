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
    db.setPassword("ghaith");

    if (db.open()) return true;
    return true;
}

void Connexion::fermerConnexion()
{
    db.close();
}

bool Connexion::addTrait(int id, std::string type, std::string date, std::string desc, float prix)
{

    // Prepare the SQL query
    int index;
    auto a=selectAllTraitById();
    if (!a.empty()) index=a[a.length()-1].first().toUInt() + 1 ;
    else index=0;



    QString queryString = "INSERT INTO TRAITEMENT (ID_TRAIT, TYPE_TRAIT, DATE_TRAIT, DESC_TRAIT, PRIX) VALUES ("
            + QString::number(index) + ", '" + QString::fromStdString(type) + "', '"
            + QString::fromStdString(date) + "', '" + QString::fromStdString(desc) + "', "
            + QString::number(prix) + ")";

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

bool Connexion::updateTrait(int id, std::string type, std::string date, std::string desc, float prix)
{
    // Prepare the SQL query for updating the treatment
    QString queryString = "UPDATE TRAITEMENT SET TYPE_TRAIT = '" + QString::fromStdString(type)
            + "', DATE_TRAIT = '" + QString::fromStdString(date)
            + "', DESC_TRAIT = '" + QString::fromStdString(desc)
            + "', PRIX = " + QString::number(prix)
            + " WHERE ID_TRAIT = " + QString::number(id);

    QSqlQuery query;
    query.prepare(queryString);

    // Execute the query
    if (query.exec()) {
        std::cout << "Traitement updated successfully." << std::endl;
        return true;
    } else {
        std::cout << "Error updating Traitement: " << query.lastError().text().toStdString() << std::endl;
        return false;
    }
}

QVector<QStringList> Connexion::selectAllTrait()
{
    QVector<QStringList> result;


    // Execute the query
    QSqlQuery query("SELECT * FROM TRAITEMENT");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}




QVector<QStringList> Connexion::selectAllTraitTri()
{
    QVector<QStringList> result;
    // Execute the query
    QSqlQuery query("SELECT * FROM traitement ORDER BY TYPE_TRAIT");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}




void Connexion::displayTraitmentsInListView(QListView* listView)
{
    // Assuming listView is a valid pointer to your QListView

    // Fetch the data from the database
    QVector<QStringList> data = selectAllTrait();

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



bool Connexion::displayTraitmentsInListViewUpdated(QListView* listView, QVector<QStringList> data)
{
    // Assuming listView is a valid pointer to your QListView

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


QVector<QStringList> Connexion::selectAllTraitById()
{
    QVector<QStringList> result;


    // Execute the query
    QSqlQuery query("SELECT * FROM traitement ORDER BY ID_TRAIT");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}

QStringList Connexion::selectTraitById(int id){
    auto a=selectAllTrait();
    foreach (auto T, a) {
       if (T[1].toInt() == id)
           return T;
    }
}



bool Connexion::addPat(int id_p, int age, std::string nom_p, std::string prenom_p, std::string etat, std::string sexe_p)
{

    int index;
    auto a=selectAllPatById();
    if (!a.empty()) index=a[a.length()-1].first().toUInt() + 1 ;
    else index=0;
    // Prepare the SQL query
    QString queryString = "INSERT INTO PATIENT (ID_P, AGE, NOM_P, PRENOM_P, ETAT, SEXE_P) VALUES ("
            + QString::number(index) + ", " + QString::number(age) + ", '" + QString::fromStdString(nom_p) + "', '"
            + QString::fromStdString(prenom_p) + "', '" + QString::fromStdString(etat) + "', '" + QString::fromStdString(sexe_p) + "')";

    QSqlQuery query;
    query.prepare(queryString);

    // Execute the query
    if (query.exec()) {
        std::cout << "Patient added successfully." << std::endl;
        return true;
    } else {
        std::cout << "Error adding Patient: " << query.lastError().text().toStdString() << std::endl;
        return false;
    }


}
bool Connexion::updatePat(int id_p, int age, std::string nom_p, std::string prenom_p, std::string etat, std::string sexe_p)
{
    // Prepare the SQL query for updating Patient
    QString queryString = "UPDATE PATIENT SET ETAT = '" + QString::fromStdString(etat)
            + "', NOM_P = '" + QString::fromStdString(nom_p)
            + "', PRENOM_P = '" + QString::fromStdString(prenom_p)
            + "', SEXE_P = '" + QString::fromStdString(sexe_p)
            + "', AGE = " + QString::number(age)
            + " WHERE ID_P = " + QString::number(id_p);

    QSqlQuery query;
    query.prepare(queryString);

    // Execute the query
    if (query.exec()) {
        std::cout << "Patient updated successfully." << std::endl;
        return true;
    } else {
        std::cout << "Error updating Patient: " << query.lastError().text().toStdString() << std::endl;
        return false;
    }
}

QVector<QStringList> Connexion::selectAllPatById()
{
    QVector<QStringList> result;


    // Execute the query
    QSqlQuery query("SELECT * FROM PATIENT ORDER BY ID_P");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}


QVector<QStringList> Connexion::selectAllPat()
{
    QVector<QStringList> result;


    // Execute the query
    QSqlQuery query("SELECT * FROM PATIENT");

    while (query.next()) {
        QStringList record;
        for (int i = 0; i < query.record().count(); ++i) {
            record << query.value(i).toString();
        }
        result << record;
    }

    return result;
}

bool Connexion::deletePat(int id)
{
    QString queryString = QString("DELETE FROM PATIENT WHERE id_p='%1'").arg(id);

    QSqlQuery query;
    if (query.exec(queryString)) {
        qDebug() << "User deleted successfully.";
        return true;
    } else {
        qDebug() << "Error deleting user: " << query.lastError().text();
        return false;
    }
}

void Connexion::displayPatInListViewUpdate(QListView* listView, QVector<QStringList> data)
{
    // Assuming listView is a valid pointer to your QListView

    // Fetch the data from the database

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

QVector<QStringList> Connexion::selectAllPatTri(const QString& sortOrder)
{
    QVector<QStringList> result;

        // Construire la requête SQL en fonction de l'ordre de tri
        QString queryString = "SELECT * FROM PATIENT ORDER BY SEXE_P " + sortOrder;

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

void Connexion::displayPatInListView(QListView* listView)
{
    // Assuming listView is a valid pointer to your QListView

    // Fetch the data from the database
    QVector<QStringList> data = selectAllPat();

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

void Connexion::displayNotificationsInListWidget(QListWidget* listWidget) {

    // Iterate through the stored notification data and add it to the listWidget
    for (const QStringList& record : notificationData) {
        QString itemText = record.join(", "); // You can customize the separator as needed
        listWidget->addItem(itemText);
    }

    // Optionally, set other properties or customize the appearance of the listWidget
    listWidget->setViewMode(QListView::ListMode);

    // Show the listWidget
    listWidget->show();
}




