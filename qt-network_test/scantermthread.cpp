#include "scantermthread.h"
#include <QDebug>
#include <QByteArray>
#include <QtNetwork/QUdpSocket>

ScanTermThread::ScanTermThread(QObject *parent)
    : QThread(parent)
{
    stopped = false;
    udp_socket = new QUdpSocket(this);
}


void ScanTermThread::stop()
{
    stopped = true;
}

void ScanTermThread::run()
{
    qreal i = 0;
    while (!stopped) {
        qDebug() << QString("in MyThread: %1").arg(i);
        msleep(1000);
        i++;

        QByteArray datagram = "hello world!";
        udp_socket->writeDatagram(datagram.data(), datagram.size(),
                              QHostAddress::Broadcast, 1500);

        // 拥有等待的数据报
        while(udp_socket->hasPendingDatagrams())
        {
            QByteArray datagram;

            // 让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
            datagram.resize(udp_socket->pendingDatagramSize());

            QHostAddress host_addr;
            quint16 port;
            // 接收数据报，将其存放到datagram中
            udp_socket->readDatagram(datagram.data(), datagram.size(),&host_addr,&port);
            qDebug()<<"udp receiver :"<<datagram;
            qDebug()<<"udp receiver addr:"<<host_addr<< host_addr.toString();
            qDebug()<<"udp receiver port:"<<port;
        }
    }
    stopped = false;
}



