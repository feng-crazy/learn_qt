#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QListWidgetItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setViewMode(QListView::ListMode);
    ui->listWidget->setSortingEnabled(true);

    for(int i = 0;i<15;i++)
    {
        QString label = QString("%0").arg(i);
        ui->listWidget->addItem(label);
    }

    my_thread.start();
//    ui->listWidget->
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug()<<item->text()<<" is itemClicked";
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug()<<item->text()<<" is itemDoubleClicked";
}
