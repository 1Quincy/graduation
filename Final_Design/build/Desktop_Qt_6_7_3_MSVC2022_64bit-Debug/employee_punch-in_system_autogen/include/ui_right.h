/********************************************************************************
** Form generated from reading UI file 'right.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGHT_H
#define UI_RIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Right
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLabel *photoLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *msgLabel;
    QLabel *label;

    void setupUi(QWidget *Right)
    {
        if (Right->objectName().isEmpty())
            Right->setObjectName("Right");
        Right->resize(260, 87);
        verticalLayout = new QVBoxLayout(Right);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        nameLabel = new QLabel(Right);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setMinimumSize(QSize(0, 30));
        nameLabel->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(nameLabel);

        photoLabel = new QLabel(Right);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setMinimumSize(QSize(25, 25));
        photoLabel->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(photoLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        msgLabel = new QLabel(Right);
        msgLabel->setObjectName("msgLabel");
        msgLabel->setWordWrap(true);

        horizontalLayout_2->addWidget(msgLabel);

        label = new QLabel(Right);
        label->setObjectName("label");
        label->setMinimumSize(QSize(25, 0));
        label->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_2->addWidget(label);

        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 1);

        retranslateUi(Right);

        QMetaObject::connectSlotsByName(Right);
    } // setupUi

    void retranslateUi(QWidget *Right)
    {
        Right->setWindowTitle(QCoreApplication::translate("Right", "Form", nullptr));
        nameLabel->setText(QString());
        photoLabel->setText(QString());
        msgLabel->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Right: public Ui_Right {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGHT_H
