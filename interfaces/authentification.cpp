#include "authentification.h"
#include "ui_authentification.h"
#include "Admin.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

#include <QMessageBox>
#include <QColor>
#include <QPalette>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidget>
#include <QPixmap>
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

void authentification::on_btn_modC_clicked()
{
    int id=ui->id_ex_c->text().toInt();

    QString nom= ui->nv_nomC->text();
     QString prenom= ui->nv_prenomC->text();
      QString username= ui->nv_usernameC->text();
       QString password= ui->nv_passwordC->text();


     Admin p(id,nom,prenom,username,password);
      bool test=p.modifier(id,nom,prenom,username,password);
      if(test)
    {
          ui->tabCompte->setModel(tmpa.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier un Compte"),
                      QObject::tr("Compte modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un Compte"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void authentification::on_btn_supprimerC_clicked()
{
    QSqlQuery query;

        int id = ui->c_a_supp->text().toInt();

        query.prepare("delete from compte where id=:id");
        query.bindValue(":id", id);
        bool v =query.exec();
        if(v)
        {ui->tabCompte->setModel(tmpa.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un Compte"),
                        QObject::tr("Compte supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un Compte"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void authentification::on_btn_searchC_clicked()
{
    QString nomc = ui->compte_a_chercher->text();
        if(tmpa.verifierExnoms(nomc)==false)
        {QMessageBox::warning(this,"ERREUR","Compte n'existe pas");}
        else
        ui->tabCompte->setModel(tmpa.recherche_nom(nomc));
}

void authentification::on_btn_refreshC_clicked()
{
  ui->tabCompte->setModel(tmpa.afficher());
}

void authentification::on_btn_pdfC_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
           printer->setOutputFormat(QPrinter::NativeFormat);
           printer->setPageSize(QPrinter::A4);
           printer->setOrientation(QPrinter::Portrait);
           printer->setFullPage(true);


       QPrintDialog *printDialog = new QPrintDialog(printer,this);
       printDialog->setWindowTitle("Impression PDF");
       if(printDialog->exec())
       {
          QPainter painter;
          if(painter.begin(printer))
          {
              double xscale = double(ui->tabCompte->width() / 65);
              double yscale = double(ui->tabCompte->height() / 65);
              painter.scale(xscale, yscale);
              ui->tabCompte->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }
}
