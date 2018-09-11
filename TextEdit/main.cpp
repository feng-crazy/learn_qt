#include <QtGui/QApplication>
#include "textedit.h"
#include <QTextCodec>
#include <QSplashScreen>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/images/yafeilinux.gif");
    QSplashScreen splash(pixmap);//������������
    for(qint64 i=5555555*6;i>0;i--)
        splash.show();
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//֧��������ʾ
    TextEdit w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
