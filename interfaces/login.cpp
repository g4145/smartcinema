#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include"mainwindow.h"
#include "authentification.h"
#include "Admin.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_btn_chercher_clicked()
{
    /*admin a;
        bool test=a.login(ui->username_label->text(),ui->password_label->text());
        if(test){

            MainWindow *w=new MainWindow();
            w->show();
            this->hide();
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Login"),
                        QObject::tr("Username ou mot de passe invalide!\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }*/
}

void login::on_btn_creer_clicked()
{
   authentification s;
       s.exec();
}

void login::on_btn_connecter_clicked()
{QString username = ui->username_label->text();
    QString password = ui->password_label->text();

    if(username ==  "yassine20" && password == "esprit") {
        QMessageBox::information(this, "Login", "Username and password is correct");

        MainWindow *w=new MainWindow();
        w->show();
        this->hide();

    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}
