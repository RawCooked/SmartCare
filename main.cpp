#include "mainwindow.h"
#include "loginwindow.h"
#include "connexion.h"
#include "users.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    LoginWindow Lw;
    Connexion c;
    //w.show();
    Lw.show();
    if (c.ouvrirConnexion()){
        Lw.show();
    }
    else QMessageBox::information(nullptr, QObject::tr("Erreur"),QObject::tr("Echec de la connexion.\n") );
    return a.exec();
}
