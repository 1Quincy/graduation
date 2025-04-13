#include "dialogemployeeinfo.h"
#include "ui_dialogemployeeinfo.h"

DialogEmployeeInfo::DialogEmployeeInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogEmployeeInfo)
{
    ui->setupUi(this);
    mysql = new MySql;//链接数据库

    Init();
}

DialogEmployeeInfo::~DialogEmployeeInfo()
{
    delete ui;
}

void DialogEmployeeInfo::exportExcel()
{
    Function::instance()->exportToExcel(ui->tableWidget);
}

void DialogEmployeeInfo::Init()
{
    /*QTableWidget *tableWidget = new QTableWidget(this);
    ui->tabWidget->set*/
    //ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);        //表头居中显示
    //ui->tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);

    //创建table
    QStringList headStr = {"工号","姓名","性别","入职时间","部门","职位","电话","邮件"};
    Function::instance()->createTable(headStr,ui->tableWidget);
    ui->tableWidget->setColumnWidth(1,100); //设置第一列宽度

    QStringList list = mysql->MySql_Select("select * from employeeinfo");   //查询结果

    // 设置表格行数
    //ui->tableWidget->setRowCount(list.count());     //设置行数
    for(int i = 0 ;i<list.count();i++){
        QStringList list2 = list.at(i).split("|");    //分割查询结果
        int rowCount = ui->tableWidget->rowCount(); //记录当前行号
        ui->tableWidget->insertRow(rowCount);   //插入一空白行

        // 获取数据并填充到表格中
        for(int j = 0;j<list2.count();j++){
            QTableWidgetItem *item = new QTableWidgetItem(list2.at(j));
            // 设置单元格文本居中对齐
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(rowCount , j, item);
        }
    }
}
