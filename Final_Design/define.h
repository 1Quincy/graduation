#ifndef DEFINE_H
#define DEFINE_H

#define QRC_QSS(x) ":/Resources/QSS/" + x + ".css"
#define INI_PATH(f) QApplication::applicationDirPath() + "/ini/" + f
#define APP_ICON(i) ":/Resources/MainWindow/app/" + i + ".png"
#define IMG_PATH(p) ":/Resources/MainWindow/emotion/" + p + ".png"
#define HTML_PATH(h) ":/Resources/MainWindow/MsgHtml/" + h + ".html"

#define GROUP_ID_LENGTH 4

#define IMG_SRC "<img src='%1'/>"
#define IMG_QRC "qrc:/Resources/MainWindow/emotion/"
#define IMG_PNG ".png"

#define MSG_LENGTH 2048

#define IMG "img"
#define TXT "txt"
#define BR "<br>"

#define MYSELF "0"

#define TYPE "type"
#define TYPE_GROUP "0"
#define TYPE_SINGLE "1"

#define SEND "send"
#define RECV "recv"

#define WHAT "what"
#define WHAT_MSG "msg"
#define WHAT_FILE "file"

#define FILE_NAME "name"
#define FILE_LENGTH "len"
#define FILE_CONTENT "content"

#endif // DEFINE_H
