#include "function.h"
#include "QFont"
#include "QHeaderView"
#include "qcryptographichash.h"
#include "qmessagebox.h"

Q_GLOBAL_STATIC(Function,theInstance);

Function::Function() {}

Function *Function::instance()
{
    return theInstance();
}

bool Function::createTable(const QStringList &list , QTableWidget *tableWidget)
{
    //清除表中内容
    tableWidget->setRowCount(0);   // 将行数设置为0
    tableWidget->setColumnCount(0); // 将列数设置为0

    QStringList headStr = list;
    tableWidget->setColumnCount(headStr.count());   //设置列数
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
        tableWidget->setHorizontalHeaderItem(i,item);

    }
    //调整列宽的调整模式
    auto *headView = tableWidget->horizontalHeader();

    headView->setSectionResizeMode(QHeaderView::Stretch);   //自动伸展
    //headView->setSectionResizeMode(QHeaderView::ResizeToContents);   //自动调整列宽

    return true;
}

QString Function::encrypt(const QString &str)
{

    // MD5加密
    QByteArray array;
    array.append(str.toUtf8());
    QCryptographicHash hash(QCryptographicHash::Md5); // 设置hash的加密算法
    hash.addData(array);

    QByteArray resultArray = hash.result();
    QString md5 = resultArray.toHex(); // 转成16进制字符串
    return md5;

}

void Function::exportToExcel(QTableWidget *table)
{
    // 获取保存路径
    QString fileName = QFileDialog::getSaveFileName(nullptr,
                                                    "保存Excel文件",
                                                    "",
                                                    "Excel文件 (*.xlsx)"
                                                    );
    if (fileName.isEmpty()) return;

    // 创建 Excel 文档
    QXlsx::Document xlsx;
    QXlsx::Format headerFormat;
    headerFormat.setFontBold(true);
    headerFormat.setFontSize(12);
    headerFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

    // 写入表头
    for (int col = 0; col < table->columnCount(); ++col) {
        QTableWidgetItem *headerItem = table->horizontalHeaderItem(col);
        xlsx.write(1, col + 1, headerItem->text(), headerFormat);
    }

    // 写入数据
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            QTableWidgetItem *item = table->item(row, col);
            if (item) {
                // 处理不同类型的数据（数字、文本等）
                bool ok;
                double value = item->text().toDouble(&ok);
                if (ok) {
                    xlsx.write(row + 2, col + 1, value);
                } else {
                    xlsx.write(row + 2, col + 1, item->text());
                }
            }
        }
    }

    // 自动调整列宽
    for (int col = 0; col < table->columnCount(); ++col) {
        xlsx.setColumnWidth(col + 1, 20); // 设置列宽为20字符
    }

    // 保存文件
    if (xlsx.saveAs(fileName)) {
        QMessageBox::information(nullptr, "成功", "Excel文件已保存！");
    } else {
        QMessageBox::critical(nullptr, "错误", "保存失败，请检查路径权限！");
    }

}

bool Function::checkWidgetType(QWidget *widget)
{
    if (qobject_cast<QTableWidget*>(widget)) {
        qDebug() << "这个 widget 是 QTableWidget。";
        return true;
    } else {
        qDebug() << "这个 widget 不是 QTableWidget。";
        return false;
    }
}
