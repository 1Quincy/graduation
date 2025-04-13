#ifndef FUNCTION_H
#define FUNCTION_H
#include "QStringList"
#include "QTableWidget"

#include <QFileDialog>
#include <QTableWidget>
#include "xlsxdocument.h"
#include "xlsxformat.h"


class Function
{
public:
    Function();

    static Function* instance();

    bool createTable(const QStringList &list , QTableWidget *tableWidget);

    QString encrypt(const QString &str);

    void exportToExcel(QTableWidget *table);

    bool checkWidgetType(QWidget* widget);

};

#endif // FUNCTION_H
