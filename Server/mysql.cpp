#include "mysql.h"
#include "qdebug.h"

Q_GLOBAL_STATIC(MySql,theInstance);

MySql::MySql() {
    MySql_Link();
}

bool MySql::MySql_Link()
{
    //链接数据库
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("employee_punch-in_system");
    if(!db.open()){
        qDebug() << "未成功链接到数据库";
        return false;
    }else{
        qDebug() << "成功链接到数据库";
        return true;
    }
}

MySql *MySql::instance()
{
    return theInstance();
}

MySql::~MySql()
{
    if (db.isOpen()) {
        // 关闭数据库连接
        db.close();
    }
}

QSqlDatabase MySql::getDatabase()
{
    return db;
}

