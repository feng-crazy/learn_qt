#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QWheelEvent>
#include <QDebug>

#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QListWidget>
#include <QStandardItemModel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QListWidget *listWidget = new QListWidget(this);

    QCheckBox *ckBox1 = new QCheckBox(this);
    ckBox1->setText("CheckBox1");
    ckBox1->setChecked(true);

    QListWidgetItem *tem = new QListWidgetItem(listWidget);
    tem->setText("top");
    listWidget->setItemWidget(tem,ckBox1);

    ckBox2 = new QCheckBox(this);
    ckBox2->setText("CheckBox2");
    ckBox2->setChecked(true);

    connect(ckBox2,SIGNAL(stateChanged(int)),this,SLOT(checkBoxStateChange(int)));

    QListWidgetItem *item = new QListWidgetItem(listWidget);
    tem->setText("bom");
    listWidget->setItemWidget(item,ckBox2);                //设置ckBox为item的第二列

    QCheckBox *cpy = (QCheckBox*)listWidget->itemWidget(item);
    QMessageBox::information(NULL,"title",cpy->text());     //获取item中Checkbox的文本值


    listWidget->show();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setWindow(-50,50,100,-100);
    painter.drawLine(QPoint(0, 0), QPoint(50, 50));


}

void Widget::wheelEvent(QWheelEvent *event)
{
    int dalte = event->delta();
    qDebug("dalte = %d",dalte);
    if(dalte > 0){
        ui->textEdit->zoomIn();//放大
    }else{
        ui->textEdit->zoomOut();//缩小
    }

    QPoint numPixels = event->pixelDelta();
    QPoint numDegrees = event->angleDelta() / 8;
    qDebug() << numPixels.x()<<numPixels.y();
    qDebug() << numDegrees.x()<<numDegrees.y();

    QPoint postion = event->pos();
    qDebug() << postion.x()<<postion.y();

}

void Widget::checkBoxStateChange(int state)
{
    qDebug()<<state;
}
