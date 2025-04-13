#ifndef MYSQL_H
#define MYSQL_H

#include "QSqlDatabase"

class MySql
{
public:
    MySql();
    ~MySql();

    static MySql* instance();
    bool MySql_Link();  //连接数据库
    QSqlDatabase getDatabase();

private:
    QSqlDatabase db;
};

#endif // MYSQL_H
