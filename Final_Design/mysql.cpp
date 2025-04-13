#include "mysql.h"
#include "QDebug"
#include "QSqlQuery"
#include "QSqlRecord"

Q_GLOBAL_STATIC(MySql,theInstance);

MySql::MySql() {

    MySql_Link();   //链接数据库
   // MySql_Delete("delete from user_test where no = '4'");
}

MySql::~MySql()
{

}

MySql *MySql::instance()
{
    return theInstance();
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

bool MySql::MySql_Update(QString update)
{
    QSqlQuery query(db);
    bool re = query.exec(update);

    if(!re){
        qDebug() << "操作数据库失败！" ;
        return false;
    }else{
        qDebug() << "操作数据库成功！" ;
        return true;
    }
}

bool MySql::MySql_Insert(QString insert)
{
    QSqlQuery query(db);
    bool re = query.exec(insert);
        //"INSERT INTO table_name (col1, col2, col3) VALUES (1, 1, 2)");
    //bool re = query.exec("insert into table_name values(3, 1, 2)");

    if(!re){
        qDebug() << "操作数据库失败！" ;
        return false;
    }else{
        qDebug() << "操作数据库成功！" ;
        return true;
    }


}

QStringList MySql::MySql_Select(QString select)
{
    QSqlQuery query(db);
    query.exec(select);
    QStringList list;
    if(query.size() == -1){     //size查询结果行数
        qDebug() << QString("数据表 <table_name> 操作异常，请检查... ");
        return list;
    }else if(query.size() == 0){
        qDebug() << QString("数据表 <table_name> 没有数据，请检查... ");
        return list;
    }else{

        while(query.next()){
            QString str = "";
            QSqlRecord rec = query.record();        //查询结果列数
            for(int i = 0 ;i<rec.count();i++){
                str+=query.value(i).toString();
                str+="|";
            }
           // qDebug()<<str;
            list<<str;
        /*     qDebug()<<query.value(0).toString()<<" "<<query.value(1).toString()<<" "<<query.value(2).toString()
                     <<" "<<query.value(3).toString()
                     <<" "<<query.value(4).toString()
                     <<" "<<query.value(5).toString()
                     <<" "<<query.value(6).toString();
        */
        }
        return list;
    }
}

bool MySql::MySql_Delete(QString Delete)
{
    QSqlQuery query(db);
    bool re = query.exec(Delete);

    if(!re){
        qDebug() << "操作数据库失败！" ;
        return false;
    }else{
        qDebug() << "操作数据库成功！" ;
        return true;
    }
}

bool MySql::MySql_DisLink()
{
    if (db.isOpen()) {
        // 关闭数据库连接
        db.close();
        qDebug() << "Database connection closed.";
        return true;
    } else {
        qDebug() << "Database connection is not open.";
        return false;
    }

}

QSqlDatabase MySql::getDatabase()
{
    return db;
}
