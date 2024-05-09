#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtrpt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_7_clicked();


    void changeWidget(int);


    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();



    void on_pushButton_24_clicked();


    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_DashboardButton_clicked();




    void on_listView_doubleClicked(const QModelIndex &index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_radioTri_toggled(bool checked);

    void on_listView_11_clicked(const QModelIndex &index);

    void on_pushButton_12_clicked();

    void on_pushButton_15_clicked();



    void on_pushButton_18_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_47_clicked();

    void on_UpdatePat_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_38_clicked();

    void on_qr_clicked();





    void on_pushButton_22_clicked();



    void on_lineEdit_2_textChanged(const QString &arg2);

    void on_radioTri_2_toggled(bool checked1);

    void on_pushButton_23_clicked();



    void on_pushButton_63_clicked();
    void saveHistoriqueToFile(const QString& filename);
    void loadHistoriqueFromFile(const QString& filename);






private:
    Ui::MainWindow *ui;




};
#endif // MAINWINDOW_H
