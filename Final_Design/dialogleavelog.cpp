#include "dialogleavelog.h"
#include "ui_dialogleavelog.h"
#include "userinfo.h"
#include "function.h"

DialogLeaveLog::DialogLeaveLog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLeaveLog)
{
    ui->setupUi(this);

    mysql = new MySql;
    Init();
}

DialogLeaveLog::~DialogLeaveLog()
{
    delete ui;
}

void DialogLeaveLog::exportExcel()
{
    qDebug()<<"send";
    Function::instance()->exportToExcel(ui->tableWidget);
}

void DialogLeaveLog::Init()
{
    //清除表中内容
    ui->tableWidget->setRowCount(0);   // 将行数设置为0
    ui->tableWidget->setColumnCount(0); // 将列数设置为0

    QStringList headStr = {"请假记录号","工号","姓名","部门","职位","开始时间","结束时间","天数","原因","是否批准"};
    ui->tableWidget->setColumnCount(headStr.count());   //设置列数
    //概念 item
    for(int i = 0 ;i<headStr.count();i++){
        QTableWidgetItem * item = new QTableWidgetItem(headStr[i]);
        //设置字体
        QFont font = item->font();
        font.setBold(true);
        font.setPointSize(12);
        font.setFamily("微软雅黑");
        item->setFont(font);
        item->setForeground(Qt::blue);
        //设置为表头
        ui->tableWidget->setHorizontalHeaderItem(i,item);

    }
    //调整列宽的调整模式
    auto *headView = ui->tableWidget->horizontalHeader();

    //headView->setSectionResizeMode(QHeaderView::Stretch);   //自动伸展
    headView->setSectionResizeMode(QHeaderView::ResizeToContents);   //自动调整列宽
    headView->setSectionResizeMode(1,QHeaderView::Fixed);   //第一列，固定模式
    ui->tableWidget->setColumnWidth(1,100); //设置第一列宽度

    QStringList list;
    if(usr.getRole() == "管理员")
        list = mysql->MySql_Select(QString("select * from qingjiainfo"));   //查询结果
    else{
        list = mysql->MySql_Select(QString("select * from qingjiainfo where employeeNo = '%1'").arg(usr.getNo()));   //查询结果
    }
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
            item->setToolTip(item->text());//鼠标悬停显示文本
            item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
            ui->tableWidget->setItem(rowCount , j, item);
        }
    }

}
