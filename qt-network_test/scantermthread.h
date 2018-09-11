#ifndef SCANTERMTHREAD_H
#define SCANTERMTHREAD_H

#include <QObject>
#include <QThread>

class QUdpSocket;

class ScanTermThread : public QThread
{
    Q_OBJECT
public:
    explicit ScanTermThread(QObject *parent = 0);
    void stop();
protected:
    void run();
private:
    volatile bool stopped;
    QUdpSocket *udp_socket;
};

#endif // SCANTERMTHREAD_H
