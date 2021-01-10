#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>
#include "Admin.h"
namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();

private slots:
    void on_btn_creer_compte_clicked();

    void on_btn_modC_clicked();

    void on_btn_supprimerC_clicked();

    void on_btn_searchC_clicked();

    void on_btn_refreshC_clicked();

    void on_btn_pdfC_clicked();

private:
    Ui::authentification *ui;
    Admin tmpa;
};

#endif // AUTHENTIFICATION_H
