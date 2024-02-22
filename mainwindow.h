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

    void on_pushButton_15_clicked();


    void on_pushButton_21_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
