#ifndef DIALOGMODIFYINFO_H
#define DIALOGMODIFYINFO_H

#include <QDialog>

namespace Ui {
class DialogModifyInfo;
}

class DialogModifyInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifyInfo(QWidget *parent = nullptr);
    ~DialogModifyInfo();

    void mousePressEvent(QMouseEvent *event) override; // 重写鼠标按下事件

signals:
    void photoClicked();    //照片label被点击了

private slots:
    void on_BtnOK_clicked();

    void on_BtnCancel_clicked();

    void onPhotoLabelClicked();


private:
    Ui::DialogModifyInfo *ui;

    void init();
    bool isPixmapEqual(const QPixmap& pixmap1, const QPixmap& pixmap2);

    QString telephone;
    QString email;
    QString photoPath;
    QPixmap photo;

};

#endif // DIALOGMODIFYINFO_H
