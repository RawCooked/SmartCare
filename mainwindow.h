#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QUrl>


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

    void on_pushButton_16_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_64_clicked();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
