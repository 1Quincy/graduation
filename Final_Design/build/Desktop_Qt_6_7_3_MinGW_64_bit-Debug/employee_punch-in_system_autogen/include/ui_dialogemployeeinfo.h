/********************************************************************************
** Form generated from reading UI file 'dialogemployeeinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEMPLOYEEINFO_H
#define UI_DIALOGEMPLOYEEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEmployeeInfo
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *DialogEmployeeInfo)
    {
        if (DialogEmployeeInfo->objectName().isEmpty())
            DialogEmployeeInfo->setObjectName("DialogEmployeeInfo");
        DialogEmployeeInfo->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogEmployeeInfo);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(DialogEmployeeInfo);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);


        retranslateUi(DialogEmployeeInfo);

        QMetaObject::connectSlotsByName(DialogEmployeeInfo);
    } // setupUi

    void retranslateUi(QDialog *DialogEmployeeInfo)
    {
        DialogEmployeeInfo->setWindowTitle(QCoreApplication::translate("DialogEmployeeInfo", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEmployeeInfo: public Ui_DialogEmployeeInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEMPLOYEEINFO_H
