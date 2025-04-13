/********************************************************************************
** Form generated from reading UI file 'left.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFT_H
#define UI_LEFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_left
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *photoLabel;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *msgLabel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *left)
    {
        if (left->objectName().isEmpty())
            left->setObjectName("left");
        left->resize(300, 131);
        left->setMinimumSize(QSize(300, 0));
        left->setMaximumSize(QSize(600, 16777215));
        verticalLayout = new QVBoxLayout(left);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        photoLabel = new QLabel(left);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setMinimumSize(QSize(25, 25));
        photoLabel->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(photoLabel);

        nameLabel = new QLabel(left);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setMinimumSize(QSize(0, 30));
        nameLabel->setMaximumSize(QSize(166666, 30));

        horizontalLayout->addWidget(nameLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(left);
        label->setObjectName("label");
        label->setMinimumSize(QSize(25, 0));
        label->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_2->addWidget(label);

        msgLabel = new QLabel(left);
        msgLabel->setObjectName("msgLabel");
        msgLabel->setWordWrap(true);

        horizontalLayout_2->addWidget(msgLabel);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 1);

        retranslateUi(left);

        QMetaObject::connectSlotsByName(left);
    } // setupUi

    void retranslateUi(QWidget *left)
    {
        left->setWindowTitle(QCoreApplication::translate("left", "Form", nullptr));
        photoLabel->setText(QString());
        nameLabel->setText(QString());
        label->setText(QString());
        msgLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class left: public Ui_left {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFT_H
