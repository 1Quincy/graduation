/********************************************************************************
** Form generated from reading UI file 'dialogworktime.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGWORKTIME_H
#define UI_DIALOGWORKTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogWorkTime
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNo;
    QLineEdit *lineEditNo;
    QLabel *labelDate;
    QDateEdit *dateEdit;
    QPushButton *BtnFind;
    QPushButton *BtnSelectAll;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelWorkHours;
    QPushButton *BtnLateNum;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelDays;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelOverHours;
    QPushButton *BtnEarlyNum;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DialogWorkTime)
    {
        if (DialogWorkTime->objectName().isEmpty())
            DialogWorkTime->setObjectName("DialogWorkTime");
        DialogWorkTime->resize(560, 309);
        gridLayout = new QGridLayout(DialogWorkTime);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelNo = new QLabel(DialogWorkTime);
        labelNo->setObjectName("labelNo");

        horizontalLayout->addWidget(labelNo);

        lineEditNo = new QLineEdit(DialogWorkTime);
        lineEditNo->setObjectName("lineEditNo");

        horizontalLayout->addWidget(lineEditNo);

        labelDate = new QLabel(DialogWorkTime);
        labelDate->setObjectName("labelDate");

        horizontalLayout->addWidget(labelDate);

        dateEdit = new QDateEdit(DialogWorkTime);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout->addWidget(dateEdit);

        BtnFind = new QPushButton(DialogWorkTime);
        BtnFind->setObjectName("BtnFind");

        horizontalLayout->addWidget(BtnFind);

        BtnSelectAll = new QPushButton(DialogWorkTime);
        BtnSelectAll->setObjectName("BtnSelectAll");

        horizontalLayout->addWidget(BtnSelectAll);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(DialogWorkTime);
        tableWidget->setObjectName("tableWidget");

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelWorkHours = new QLabel(DialogWorkTime);
        labelWorkHours->setObjectName("labelWorkHours");

        horizontalLayout_2->addWidget(labelWorkHours);

        BtnLateNum = new QPushButton(DialogWorkTime);
        BtnLateNum->setObjectName("BtnLateNum");

        horizontalLayout_2->addWidget(BtnLateNum);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        labelDays = new QLabel(DialogWorkTime);
        labelDays->setObjectName("labelDays");

        horizontalLayout_2->addWidget(labelDays);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        labelOverHours = new QLabel(DialogWorkTime);
        labelOverHours->setObjectName("labelOverHours");

        horizontalLayout_2->addWidget(labelOverHours);

        BtnEarlyNum = new QPushButton(DialogWorkTime);
        BtnEarlyNum->setObjectName("BtnEarlyNum");

        horizontalLayout_2->addWidget(BtnEarlyNum);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(DialogWorkTime);

        QMetaObject::connectSlotsByName(DialogWorkTime);
    } // setupUi

    void retranslateUi(QDialog *DialogWorkTime)
    {
        DialogWorkTime->setWindowTitle(QCoreApplication::translate("DialogWorkTime", "Dialog", nullptr));
        labelNo->setText(QCoreApplication::translate("DialogWorkTime", "\345\267\245\345\217\267\357\274\232", nullptr));
        labelDate->setText(QCoreApplication::translate("DialogWorkTime", "\346\227\245\346\234\237\357\274\232", nullptr));
        BtnFind->setText(QCoreApplication::translate("DialogWorkTime", "\346\237\245\350\257\242", nullptr));
        BtnSelectAll->setText(QCoreApplication::translate("DialogWorkTime", "\346\237\245\350\257\242\345\205\250\351\203\250", nullptr));
        labelWorkHours->setText(QCoreApplication::translate("DialogWorkTime", "\346\234\254\346\234\210\345\267\245\344\275\234\346\227\266\351\225\277\357\274\232", nullptr));
        BtnLateNum->setText(QCoreApplication::translate("DialogWorkTime", "\346\237\245\347\234\213\350\277\237\345\210\260\345\210\227\350\241\250", nullptr));
        labelDays->setText(QCoreApplication::translate("DialogWorkTime", "\346\234\254\346\234\210\345\267\245\344\275\234\345\244\251\346\225\260\357\274\232", nullptr));
        labelOverHours->setText(QCoreApplication::translate("DialogWorkTime", "\346\234\254\346\234\210\345\212\240\347\217\255\346\227\266\351\225\277\357\274\232", nullptr));
        BtnEarlyNum->setText(QCoreApplication::translate("DialogWorkTime", "\346\237\245\347\234\213\346\227\251\351\200\200\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogWorkTime: public Ui_DialogWorkTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGWORKTIME_H
