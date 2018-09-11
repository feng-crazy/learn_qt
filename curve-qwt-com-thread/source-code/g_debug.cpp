/**
*********************************************************************************************************
*
*	@ProjectName : curve-qwt-com-thread
*	@Description :
*	@Version     : V1.0
*	@Description :
*
*	....................Update....................
*	@Version  @Date      @Design   @Description
*    V1.0    2016.11.23  Aslm       demo
*
* @ME:sillyman2008@outlook.com
*********************************************************************************************************/

#include "g_debug.h"
#include <QDir>
#include <QMUtex>

#define _TIME_ qPrintable (QDateTime::currentDateTime().toString ("hh-mm-ss"))

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
       mutex.lock();

       QString text;
       switch(type)
       {
        case QtInfoMsg:
           text = QString("Info:");
           break;
       case QtDebugMsg:
           text = QString("Debug:");
           break;

       case QtWarningMsg:
           text = QString("Warning:");
           break;

       case QtCriticalMsg:
           text = QString("Critical:");
           break;

       case QtFatalMsg:
           text = QString("Fatal:");
           exit(-1);
       }

       QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
       QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
       QString current_date = QString("(%1)").arg(current_date_time);
//       QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);
       QString message = QString("%1 %2 %3 %4").arg(text,context_info,msg,current_date);

       QFile file("log.txt");
       file.open(QIODevice::WriteOnly | QIODevice::Append);
       QTextStream text_stream(&file);
       text_stream << message << "\r\n";
       file.flush();
       file.close();

       mutex.unlock();
}
