#ifndef RIGHT_H
#define RIGHT_H

#include <QWidget>

namespace Ui {
class Right;
}

class Right : public QWidget
{
    Q_OBJECT

public:
    explicit Right(QWidget *parent = nullptr);
    ~Right();

    void setUsername(const QString& name);
    void setPhoto(const QPixmap& photo);
    void setMsg(const QString& msg);

private:
    Ui::Right *ui;
};

#endif // RIGHT_H
