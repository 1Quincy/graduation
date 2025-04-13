/********************************************************************************
** Form generated from reading UI file 'dialogleavelog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLEAVELOG_H
#define UI_DIALOGLEAVELOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogLeaveLog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *DialogLeaveLog)
    {
        if (DialogLeaveLog->objectName().isEmpty())
            DialogLeaveLog->setObjectName("DialogLeaveLog");
        DialogLeaveLog->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogLeaveLog);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(DialogLeaveLog);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);


        retranslateUi(DialogLeaveLog);

        QMetaObject::connectSlotsByName(DialogLeaveLog);
    } // setupUi

    void retranslateUi(QDialog *DialogLeaveLog)
    {
        DialogLeaveLog->setWindowTitle(QCoreApplication::translate("DialogLeaveLog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLeaveLog: public Ui_DialogLeaveLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLEAVELOG_H
