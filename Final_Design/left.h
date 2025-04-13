#ifndef LEFT_H
#define LEFT_H

#include <QWidget>

namespace Ui {
class left;
}

class left : public QWidget
{
    Q_OBJECT

public:
    explicit left(QWidget *parent = nullptr);
    ~left();
    void setUsername(const QString& name);
    void setPhoto(const QPixmap& photo);
    void setMsg(const QString& msg);

private:
    Ui::left *ui;
};

#endif // LEFT_H
