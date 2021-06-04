#include "paintthread.h"
#include<QMutex>
paintThread::paintThread()
{

}
void paintThread::run(){
    QMutex mutex;
    mutex.lock();





    mutex.unlock();

}
