#include "salle.h"
#include <QSqlQuery>

Salle::Salle(int id,QString nomsalle,int capacite,int numbloc )
{
    this->id=id;
    this->nomsalle=nomsalle;
     this->capacite=capacite;
    this->numbloc=numbloc;
}
Salle::~Salle()
{

}


QString Salle::getnomsalle(){
    return nomsalle;
}
void Salle::setnomsalle(QString nomsalle){
    this->nomsalle=nomsalle;
}

int Salle::getId(){
    return id;
}
void Salle::setId(int id){
    this->id=id;
}
int Salle::getnumbloc(){
    return numbloc;
}
void Salle::setnumbloc(int numbloc){
    this->numbloc=numbloc;
}
int Salle::getcapacite(){
    return capacite;
}
void Salle::setcapacite(int capacite){
    this->capacite=capacite;
}





bool Salle::ajouter(){
    QSqlQuery query;
    query.prepare("insert into salle (id,nom,prenom,date_naissance,salaire,email) values (:id,:nomsalle,:numbloc,:capacite)");
    query.bindValue(":id",id);
    query.bindValue(":nomsalle",nomsalle);
    query.bindValue(":numbloc",numbloc);
    query.bindValue(":capacite",capacite);

    return query.exec();
}

bool Salle::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from salle where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from salle where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Salle::modifier(int idc){
    QSqlQuery query;
    query.prepare("update salle set id=:id,nomsalle=:nomsalle,numbloc=:numbloc,capacite=:capacite where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":nomsalle",nomsalle);
    query.bindValue(":numbloc",numbloc);
    query.bindValue(":capacite",capacite);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Salle::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from salle");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));


    return model;
}


QSqlQueryModel * Salle::chercher_Salle_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE NOMSALLE like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }

 }

QSqlQueryModel *Salle::chercher_Salle_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }
}
QSqlQueryModel * Salle::chercher_Salle_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE capacite like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }

 }

QSqlQueryModel* Salle:: trier()
{
 //order by extract (year from date_naissance)
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by (date_naissance)DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}

QSqlQueryModel* Salle:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by nomsalle ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}
QSqlQueryModel* Salle:: trier2()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by capacite ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}

/*Salle Salle::recherche_Id(int id){
    QSqlQuery query;
    query.prepare("select *from Salle where id=:id");
    query.bindValue(":id",id);
    query.exec();
    Salle e;
    while(query.next()){
        e.setId(query.value(0).toInt());
        e.setnomsalle(query.value(1).toString());
        e.setcapacite(query.value(2).toInt());
        e.setnumbloc(query.value(3).toInt());

    }

    return e;
}*/

/*Salle Salle::recherche_mail(QString mail){
    QSqlQuery query;
    query.prepare("select *from Salle where email like '"+mail+"' ");
    query.bindValue(":email",email);
    query.exec();
    employe e;
    while(query.next()){
        e.setId(query.value(0).toInt());
        e.setNom(query.value(1).toString());
        e.setPrenom(query.value(2).toString());
        e.setDate_naissance(query.value(3).toDate());
        e.setSalaire(query.value(4).toDouble());
        e.setEmail(query.value(5).toString());
    }

    return e;
}*/
/*
QSqlQueryModel* Salle::Filter(int){
    QSqlQueryModel* model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from citoyen where sexe='"+res+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE N"));

    return model;
}*/

QStringList Salle::listeSalle(){
    QSqlQuery query;
    query.prepare("select * from Salle");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QStringList Salle::listSalle1(){
    QSqlQuery query;
    query.prepare("select * from Salle");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(5).toString());
    }

    return list;

}

/*
int Salle::calcul_Salle(int min, int max){
    QSqlQuery query;
    query.prepare("select *from Salle where capacite between :min and :max");
    query.bindValue(":min",min);
    query.bindValue(":max",max);
    query.exec();

    int total=0;
    while(query.next()){
        total++;
    }

    return total;
}*/
