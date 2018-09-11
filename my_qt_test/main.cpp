#include "mainwindow.h"
#include "widget.h"
#include <QApplication>
#include <QDebug>

#include <string>
#include <QTextCodec>


using namespace std;



QString str2qstr(const string str)
{
    qDebug() <<"str.data"<< str.data();
    return QString::fromLocal8Bit(str.data());
}

string qstr2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    qDebug() <<"cdata"<< cdata;

    char * ch = cdata.data();
    printf("ch:%s\n",ch);

    string std_str = qstr.toStdString();
    printf("std_str:%s\n",std_str.c_str());

    return string(cdata);
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Widget widget;
    widget.show();
    return app.exec();

//    QApplication app(argc, argv);
//    QSplitter *splitter = new QSplitter;

//    QFileSystemModel *model = new QFileSystemModel;
//    model->setRootPath(QDir::currentPath());

//    QTreeView *tree = new QTreeView(splitter);
//    tree->setModel(model);
//    tree->setRootIndex(model->index(QDir::currentPath()));

//    QListView *list = new QListView(splitter);
//    list->setModel(model);
//    list->setRootIndex(model->index(QDir::currentPath()));

//    splitter->setWindowTitle("Two views onto the same file system model");
//    splitter->show();
//    return app.exec();



//    QString str;
//    QString csv = "forename,middlename,surname,phone";
//    QString path = "/usr/local/bin/myapp"; // First field is empty
//    QString::SectionFlag flag = QString::SectionSkipEmpty;

//    str = csv.section(',', 2, 2);   // str == "surname"
//    qDebug() << str;
//    str = path.section('/', 3, 4);  // str == "bin/myapp"
//    qDebug() << str;
//    str = path.section('/', 3, 3, flag); // str == "myapp"
//    qDebug() << str;

//    str = path.section("/", -3, -2); // str == "local/bin"
//    qDebug() << str;

//    str = csv.section(',', 0, 0);   // str == "surname"
//    qDebug() << str;



//    return 0;
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
//    printf("您好！\n");
//    QString start("开始");
//    string std_msg = qstr2str(start);
//    start = str2qstr(std_msg);
//    qDebug() << start;

//    QString haha = QString::fromLocal8Bit("哈哈");
//    qDebug() << QString::fromLocal8Bit("哈哈");


//    QApplication a(argc, argv);
////    MainWindow w;
////    w.show();

//    Widget w;
//    w.show();

//    return a.exec();
}
