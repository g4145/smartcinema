#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

class Connection
{
public:
    Connection();
    bool createConnect();
};

#endif // CONNECTION_H
