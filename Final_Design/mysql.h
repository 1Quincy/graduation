#ifndef MYSQL_H
#define MYSQL_H
#include <QSqlDatabase>
#include "QStringList"

class MySql
{
public:
    MySql();
    ~MySql();

    static MySql* instance();

    bool MySql_Link();  //连接数据库
    bool MySql_Update(QString update);  //更新数据库
    bool MySql_Insert(QString insert);  //插入数据
    QStringList MySql_Select(QString select);  //查询数据
    bool MySql_Delete(QString Delete);  //删除数据
    bool MySql_DisLink();  //断开链接
    QSqlDatabase getDatabase();
private:
    QSqlDatabase db;
};

#endif // MYSQL_H
