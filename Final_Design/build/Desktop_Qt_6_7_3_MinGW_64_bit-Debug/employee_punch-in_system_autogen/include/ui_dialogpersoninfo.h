/********************************************************************************
** Form generated from reading UI file 'dialogpersoninfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPERSONINFO_H
#define UI_DIALOGPERSONINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogPersonInfo
{
public:
    QGridLayout *gridLayout;
    QLabel *labelPhoto;
    QVBoxLayout *verticalLayout;
    QLabel *labelNo;
    QLabel *labelName;
    QLabel *labelDepartment;
    QLabel *labelPosition;
    QLabel *labelRole;

    void setupUi(QDialog *DialogPersonInfo)
    {
        if (DialogPersonInfo->objectName().isEmpty())
            DialogPersonInfo->setObjectName("DialogPersonInfo");
        DialogPersonInfo->resize(758, 426);
        DialogPersonInfo->setMinimumSize(QSize(758, 426));
        DialogPersonInfo->setMaximumSize(QSize(758, 426));
        gridLayout = new QGridLayout(DialogPersonInfo);
        gridLayout->setObjectName("gridLayout");
        labelPhoto = new QLabel(DialogPersonInfo);
        labelPhoto->setObjectName("labelPhoto");
        labelPhoto->setMinimumSize(QSize(150, 120));
        labelPhoto->setMaximumSize(QSize(150, 120));
        QFont font;
        font.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font.setPointSize(14);
        font.setBold(true);
        labelPhoto->setFont(font);

        gridLayout->addWidget(labelPhoto, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelNo = new QLabel(DialogPersonInfo);
        labelNo->setObjectName("labelNo");
        labelNo->setFont(font);

        verticalLayout->addWidget(labelNo);

        labelName = new QLabel(DialogPersonInfo);
        labelName->setObjectName("labelName");
        labelName->setFont(font);

        verticalLayout->addWidget(labelName);

        labelDepartment = new QLabel(DialogPersonInfo);
        labelDepartment->setObjectName("labelDepartment");
        labelDepartment->setFont(font);

        verticalLayout->addWidget(labelDepartment);

        labelPosition = new QLabel(DialogPersonInfo);
        labelPosition->setObjectName("labelPosition");
        labelPosition->setFont(font);

        verticalLayout->addWidget(labelPosition);

        labelRole = new QLabel(DialogPersonInfo);
        labelRole->setObjectName("labelRole");
        labelRole->setFont(font);

        verticalLayout->addWidget(labelRole);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(DialogPersonInfo);

        QMetaObject::connectSlotsByName(DialogPersonInfo);
    } // setupUi

    void retranslateUi(QDialog *DialogPersonInfo)
    {
        DialogPersonInfo->setWindowTitle(QCoreApplication::translate("DialogPersonInfo", "Dialog", nullptr));
        labelPhoto->setText(QString());
        labelNo->setText(QCoreApplication::translate("DialogPersonInfo", "\345\267\245\345\217\267\357\274\232", nullptr));
        labelName->setText(QCoreApplication::translate("DialogPersonInfo", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelDepartment->setText(QCoreApplication::translate("DialogPersonInfo", "\351\203\250\351\227\250\357\274\232", nullptr));
        labelPosition->setText(QCoreApplication::translate("DialogPersonInfo", "\350\201\214\344\275\215\357\274\232", nullptr));
        labelRole->setText(QCoreApplication::translate("DialogPersonInfo", "\350\247\222\350\211\262\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPersonInfo: public Ui_DialogPersonInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPERSONINFO_H
