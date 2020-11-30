#include "authentification.h"
#include "ui_authentification.h"
#include "Admin.h"
#include <QMessageBox>
authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_btn_creer_compte_clicked()
{
    int id=ui->id_labelc->text().toInt();
    QString nom= ui->nomsalle_labelc->text();
     QString prenom= ui->prenom_labelc->text();
      QString username= ui->username_labelc->text();
       QString password= ui->password_labelc->text();

  Admin p(id,nom,prenom,username,password);
  bool test=p.ajouter();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter un compte"),
                  QObject::tr("Compte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
