#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "salles.h"
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


    void on_ajouter_salle_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_modifier_clicked();

    void on_refresh_clicked();

    void on_refresh_3_clicked();

    void on_btn_nom_trier_clicked();

    void on_btn_id_trier_clicked();

    void on_btn_pdf_clicked();

    void on_btn_chercher_clicked();

private:
    Ui::MainWindow *ui;
     Salles tmpsalle;
};
#endif // MAINWINDOW_H
