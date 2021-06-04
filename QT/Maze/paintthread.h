#ifndef PAINTTHREAD_H
#define PAINTTHREAD_H

#include <QThread>

class paintThread : public QThread
{
    Q_OBJECT
public:
    paintThread();
    void run() override;
};

#endif // PAINTTHREAD_H
