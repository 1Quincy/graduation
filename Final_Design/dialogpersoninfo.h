#ifndef DIALOGPERSONINFO_H
#define DIALOGPERSONINFO_H

#include <QDialog>
#include "QListWidgetItem"
#include <map>
#include "talkwindow.h"

namespace Ui {
class DialogPersonInfo;
}

class DialogPersonInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPersonInfo(QWidget *parent = nullptr);
    ~DialogPersonInfo();

    void mousePressEvent(QMouseEvent *event) override; // 重写鼠标按下事件

signals:
    void photoClicked();    //照片label被点击了

private slots:
    void onListItemDoubleClicked(QListWidgetItem *item);

    void onPhotoLabelClicked();

private:
    Ui::DialogPersonInfo *ui;
    void Init();
    void InitChat();

    QWidget* findWindowMap(const QString& id);
    void addNewTalkWindow(const QString& id);
    void loadMessage(TalkWindow& talkWindow, const QString& sendID, const QString& receiveID);

    std::map<QString,QWidget*> talkWindowMap;
   // MySql *mysql = NULL;
};

#endif // DIALOGPERSONINFO_H
