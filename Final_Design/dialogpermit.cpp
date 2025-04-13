#include "dialogpermit.h"
#include "ui_dialogpermit.h"
#include "QComboBox"
#include "QMessageBox"

DialogPermit::DialogPermit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPermit)
{
    ui->setupUi(this);

    mysql = new MySql;
    Init();
}

DialogPermit::~DialogPermit()
{
    delete ui;
}

void DialogPermit::on_comboBox_changed(int index)
{

    // 获取触发信号的 QComboBox
    QComboBox *comboBox = qobject_cast<QComboBox*>(sender());//qobject_cast的作用是将一个 QObject* 类型的指针转换为目标类型（这里是 QComboBox*）。
                                                             // 如果转换成功，返回一个有效的 QComboBox* 指针；如果转换失败（即对象不是 QComboBox 类型），返回 nullptr。
    if (!comboBox) return;

    // 获取当前选中的值
    QString selectedValue = comboBox->currentText();

    bool res = false; //记录是否批准
    // 如果选中的值改为了是，弹出提示框询问管理员是否确认批假
    if(selectedValue == "是"){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "批假", "确定同意批假吗？",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            res = true;
            QMessageBox::information(this, "批假", "批准成功！");
        } else {
            // 根据文本设置选中项
            int find = comboBox->findText("否"); // 查找文本为否的项
            if (find != -1) {
                comboBox->setCurrentIndex(find); // 选中该项
            }
        }
    }

    //如果批准了请假，找到要修改的请假记录，并修改
    QString no = "";
    if(res){
        // 如果需要知道是哪个单元格的 QComboBox 触发了信号，可以通过 QTableWidget 查找
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                if (ui->tableWidget->cellWidget(row, col) == comboBox) {
                    QTableWidgetItem *item = ui->tableWidget->item(row, 0);
                    no = item->text();
                    //qDebug() << "ComboBox at row:" << row << "col:" << col<<"   "<<no;
                    mysql->MySql_Update(QString("update qingjiainfo set permit = '是' where `index` = %1").arg(no)); //  index 因为是MySQL里的关键字，作为字段名引用时要用反引号括起来``
                    Init();
                    break;
                }
            }
        }
    }




}

void DialogPermit::Init()
{
    //创建table
    QStringList headStr = {"序号","工号","姓名","部门","职位","开始时间","结束时间","天数","原因","是否批准"};
    Function::instance()->createTable(headStr,ui->tableWidget);

    QStringList list = mysql->MySql_Select("select * from qingjiainfo where permit = '否'");   //查询结果

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
            if(j!=list2.count()-1){ // 除了最后一列，其他列不可编辑
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
            }
            ui->tableWidget->setItem(rowCount , j, item);
        }
    }

    // 设置某一列只能选择“是”或“否”
    int num = ui->tableWidget->columnCount()-1;//记录最后一列的索引
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QComboBox *comboBox = new QComboBox();
        comboBox->addItem("否","否");//文本，数据
        comboBox->addItem("是","是");
        // 连接信号到槽函数
        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),  //当 QComboBox 的当前选项发生变化时，它会发出 currentIndexChanged 信号。
               /* QComboBox::currentIndexChanged 是一个重载信号，有两种形式：
                    currentIndexChanged(int index)：带有当前索引的参数。
                    currentIndexChanged(const QString &text)：带有当前文本的参数。
                    由于信号是重载的，直接使用 &QComboBox::currentIndexChanged 会导致编译器无法确定使用哪个重载版本。
                    QOverload<int>::of 是 Qt 提供的一个辅助函数，用于明确选择 currentIndexChanged(int index) 这个重载版本。*/
                this, &DialogPermit::on_comboBox_changed);
        ui->tableWidget->setCellWidget(row, num, comboBox); // 最后一列（索引为tableWidget->rowCount()-1）设置为可选择的列
    }
}
