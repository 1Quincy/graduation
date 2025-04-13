/********************************************************************************
** Form generated from reading UI file 'dialogpermit.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPERMIT_H
#define UI_DIALOGPERMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogPermit
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *DialogPermit)
    {
        if (DialogPermit->objectName().isEmpty())
            DialogPermit->setObjectName("DialogPermit");
        DialogPermit->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogPermit);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(DialogPermit);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);


        retranslateUi(DialogPermit);

        QMetaObject::connectSlotsByName(DialogPermit);
    } // setupUi

    void retranslateUi(QDialog *DialogPermit)
    {
        DialogPermit->setWindowTitle(QCoreApplication::translate("DialogPermit", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPermit: public Ui_DialogPermit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPERMIT_H
