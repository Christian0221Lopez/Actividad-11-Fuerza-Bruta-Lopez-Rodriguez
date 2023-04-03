#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "neurona.h"
#include "clista.h"
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
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_Open_File_clicked();

    void on_Open_File_2_clicked();

    void on_EliminarInicioB_clicked();

    void on_EliminarFinalB_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
