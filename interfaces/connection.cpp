#include "Connection.h"

Connection::Connection()
{

}
bool Connection::createConnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("test_bd");
        db.setUserName("system");
        db.setPassword("esprit");

        if(db.open()) test = true;

        return test;
}
