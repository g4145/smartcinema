#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_salle_clicked()
{
   /* notifier = new QSystemTrayIcon(this);
            notifier->setIcon(QIcon("notification.png"));
            notifier->show();
            notifier->showMessage("Mriguel","Playlist ajouté",QSystemTrayIcon::Warning,10000);*/

        int id=ui->id_label->text().toInt();
        QString nomsalle= ui->nomsalle_label->text();
        int capacite = ui->capacite_label->text().toInt();
        int numbloc = ui->numbloc_label->text().toInt();

      Salles p(id,nomsalle,capacite,numbloc);
      bool test=p.ajouter();
      if(test)
    {ui->tab_salle->setModel(tmpsalle.afficher()); //refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une Salle"),
                      QObject::tr("Salle ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une Salle"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_btn_supprimer_clicked()
{
    QSqlQuery query;

        int id = ui->id_a_supprimer->text().toInt();

        query.prepare("delete from salle where id=:id");
        query.bindValue(":id", id);
        bool v =query.exec();
        if(v)
        {ui->tab_salle->setModel(tmpsalle.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer une salle"),
                        QObject::tr("Salle supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_btn_modifier_clicked()
{
    int id=ui->ex_id->text().toInt();

        QString nomsalle= ui->nv_nomsalle->text();
        int capacite= ui->nv_capacite->text().toInt();
        int numbloc= ui->nv_numbloc->text().toInt();


       Salles p(id,nomsalle,capacite,numbloc);
      bool test=p.modifier(id,nomsalle,capacite,numbloc);
      if(test)
    {
          ui->tab_salle->setModel(tmpsalle.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier une Salle"),
                      QObject::tr("Salle modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier une Salle"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_refresh_clicked()
{
     ui->tab_salle->setModel(tmpsalle.afficher());
}



void MainWindow::on_btn_nom_trier_clicked()
{
     ui->tab_salle->setModel(tmpsalle.trier());
}

void MainWindow::on_btn_id_trier_clicked()
{
   ui->tab_salle->setModel(tmpsalle.trier1());
}

void MainWindow::on_btn_pdf_clicked()
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
              double xscale = double(ui->tab_salle->width() / 65);
              double yscale = double(ui->tab_salle->height() / 65);
              painter.scale(xscale, yscale);
              ui->tab_salle->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }
}

void MainWindow::on_btn_chercher_clicked()
{  QString nomsalle = ui->nom_a_chercher->text();
    if(tmpsalle.verifierExnoms(nomsalle)==false)
    {QMessageBox::warning(this,"ERREUR","Salle n'existe pas");}
    else
    ui->tab_salle->setModel(tmpsalle.recherche_nom(nomsalle));
}
