#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>

namespace Ui {
class ClockWidget;
}

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClockWidget(QWidget *parent = nullptr);
    ~ClockWidget();

private slots:
    void updateTime();

private:
    Ui::ClockWidget *ui;
};

#endif // CLOCKWIDGET_H
