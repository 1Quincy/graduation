/********************************************************************************
** Form generated from reading UI file 'clockwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKWIDGET_H
#define UI_CLOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockWidget
{
public:
    QLabel *timeLabel;
    QLabel *dateLabel;
    QLabel *dayLabel;

    void setupUi(QWidget *ClockWidget)
    {
        if (ClockWidget->objectName().isEmpty())
            ClockWidget->setObjectName("ClockWidget");
        ClockWidget->resize(400, 300);
        timeLabel = new QLabel(ClockWidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(130, 40, 40, 12));
        dateLabel = new QLabel(ClockWidget);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setGeometry(QRect(130, 80, 101, 31));
        dayLabel = new QLabel(ClockWidget);
        dayLabel->setObjectName("dayLabel");
        dayLabel->setGeometry(QRect(130, 140, 91, 41));

        retranslateUi(ClockWidget);

        QMetaObject::connectSlotsByName(ClockWidget);
    } // setupUi

    void retranslateUi(QWidget *ClockWidget)
    {
        ClockWidget->setWindowTitle(QCoreApplication::translate("ClockWidget", "Form", nullptr));
        timeLabel->setText(QCoreApplication::translate("ClockWidget", "TextLabel", nullptr));
        dateLabel->setText(QCoreApplication::translate("ClockWidget", "TextLabel", nullptr));
        dayLabel->setText(QCoreApplication::translate("ClockWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockWidget: public Ui_ClockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKWIDGET_H
