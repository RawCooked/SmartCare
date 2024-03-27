#include "users.h"
#include <QCryptographicHash>
users::users()
{

}
users::users(int d,QString a,QString b,QString c)
{
    id_u=d;
    user_name=a;
    mdp=b;
    etat=c;
}
users::~users()
{

}
bool users::ajouter()
{
    QByteArray hashedPassword = QCryptographicHash::hash(mdp.toUtf8(), QCryptographicHash::Sha256);
    QString hashedPasswordHex = QString(hashedPassword.toHex());
    QSqlQuery query;
          query.prepare("INSERT INTO users (id_u,user_name,mdp,etat) "
                        "VALUES ( :id_u, :user_name, :mdp, :etat)");
          query.bindValue(":id_u", id_u);
          query.bindValue(":user_name", user_name);
          query.bindValue(":mdp", hashedPasswordHex);
          query.bindValue(":etat", etat);

          return query.exec();
}
//QSqlQueryModel* afficher();
bool users::supprimer(int id)
{
    QSqlQuery query;

   query.prepare("Delete from users where id_u = :id_u ");
    query.bindValue(":id_u",id);
    return query.exec();
}
bool users::update_mdp(QString UN,QString motp)
{
    QSqlQuery query;
        query.prepare( "UPDATE users SET mdp=:mdp WHERE user_name=:user_name;");
        query.bindValue(":user_name", UN);
        query.bindValue(":mdp", motp);
     return query.exec();
}
QString generateRandomString(int length) {
    static const char charset[] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"; // Characters to choose from
    const int max_index = sizeof(charset) - 1;
    QString random_string;
    for (int i = 0; i < length; ++i) {
        random_string += charset[std::rand() % max_index];
    }
    return random_string;
}
