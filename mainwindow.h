#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_Rdv_top_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_59_clicked();

    void on_PrixTrait_4_textChanged(const QString &arg1);

    void on_pushButton_24_clicked();

    void on_Ajouter_emp_clicked();

    void on_supprimer_emp_clicked();

    void on_modifier_emp_clicked();

    void on_refresh_emp0_clicked();

    void on_refresh_emp_clicked();

    void on_refresh_emp2_clicked();

    void on_refresh_emp3_clicked();

    void on_Exporter_pdf_emp_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
