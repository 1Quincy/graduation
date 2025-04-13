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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogPersonInfo
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *leftWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelPhoto;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *labelNo;
    QLabel *labelName;
    QLabel *labelDepartment;
    QLabel *labelPosition;
    QLabel *labelRole;
    QListWidget *employeeList;
    QTabWidget *rightWidget;

    void setupUi(QDialog *DialogPersonInfo)
    {
        if (DialogPersonInfo->objectName().isEmpty())
            DialogPersonInfo->setObjectName("DialogPersonInfo");
        DialogPersonInfo->resize(758, 426);
        DialogPersonInfo->setMinimumSize(QSize(0, 0));
        DialogPersonInfo->setMaximumSize(QSize(1666666, 166666));
        horizontalLayout_2 = new QHBoxLayout(DialogPersonInfo);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leftWidget = new QWidget(DialogPersonInfo);
        leftWidget->setObjectName("leftWidget");
        leftWidget->setMinimumSize(QSize(135, 0));
        leftWidget->setMaximumSize(QSize(135, 16777215));
        layoutWidget = new QWidget(leftWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 10, 132, 467));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        infoWidget = new QWidget(layoutWidget);
        infoWidget->setObjectName("infoWidget");
        infoWidget->setMinimumSize(QSize(130, 0));
        infoWidget->setMaximumSize(QSize(130, 16777215));
        verticalLayout_3 = new QVBoxLayout(infoWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, -1, 2, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(8, 10, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelPhoto = new QLabel(infoWidget);
        labelPhoto->setObjectName("labelPhoto");
        labelPhoto->setMinimumSize(QSize(100, 100));
        labelPhoto->setMaximumSize(QSize(100, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font.setPointSize(14);
        font.setBold(true);
        labelPhoto->setFont(font);

        horizontalLayout->addWidget(labelPhoto);

        horizontalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, -1, -1, -1);
        labelNo = new QLabel(infoWidget);
        labelNo->setObjectName("labelNo");
        labelNo->setFont(font);

        verticalLayout->addWidget(labelNo);

        labelName = new QLabel(infoWidget);
        labelName->setObjectName("labelName");
        labelName->setFont(font);

        verticalLayout->addWidget(labelName);

        labelDepartment = new QLabel(infoWidget);
        labelDepartment->setObjectName("labelDepartment");
        labelDepartment->setFont(font);

        verticalLayout->addWidget(labelDepartment);

        labelPosition = new QLabel(infoWidget);
        labelPosition->setObjectName("labelPosition");
        labelPosition->setFont(font);

        verticalLayout->addWidget(labelPosition);

        labelRole = new QLabel(infoWidget);
        labelRole->setObjectName("labelRole");
        labelRole->setFont(font);

        verticalLayout->addWidget(labelRole);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(infoWidget);

        employeeList = new QListWidget(layoutWidget);
        employeeList->setObjectName("employeeList");
        employeeList->setMinimumSize(QSize(130, 240));
        employeeList->setMaximumSize(QSize(130, 240));
        employeeList->setFrameShape(QFrame::Shape::StyledPanel);

        verticalLayout_4->addWidget(employeeList);


        horizontalLayout_2->addWidget(leftWidget);

        rightWidget = new QTabWidget(DialogPersonInfo);
        rightWidget->setObjectName("rightWidget");
        rightWidget->setTabBarAutoHide(true);

        horizontalLayout_2->addWidget(rightWidget);


        retranslateUi(DialogPersonInfo);

        rightWidget->setCurrentIndex(-1);


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
