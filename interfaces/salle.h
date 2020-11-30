#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQueryModel>
class Salle
{


    int id;
    QString nomsalle;
    int numbloc;
    int capacite;
    public:
    Salle();
       Salle(int,QString,int,int);
       ~Salle();

       int getId();
       void setId(int);
       QString getnomsalle();
       void setnomsalle(QString);
       int getnumbloc();
       void setnumbloc(int);
       int getcapacite();
       void setcapacite(int);

       bool ajouter();
       bool supprimer(int);
       bool modifier(int);
       QSqlQueryModel* afficher();
       Salle recherche_Id(int);
       Salle recherche_mail(QString);
       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();
       QSqlQueryModel * chercher_Salle_par_nom(QString m);
       QSqlQueryModel * chercher_Salle_par_capacite(QString m);

       QSqlQueryModel * chercher_Salle_par_id(QString idd);
        QSqlQueryModel* Filter(int);
       //QSqlQueryModel* rechercher(QString str,QString str1,int i); ///const QString & QString
       QStringList listeSalle();
       QStringList listSalle1();
       int calcul_Salle(int,int);



};

#endif // SALLE_H
