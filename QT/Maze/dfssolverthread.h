#ifndef DFSSOLVERTHREAD_H
#define DFSSOLVERTHREAD_H
#include <QThread>

class DFSsolverThread : public QThread
{
    Q_OBJECT
    public slots:
    void slot(int x);
signals:
    void one_search_iterated();
public:
    DFSsolverThread();
    void solveDFS();
    void run() override;

};

#endif // DFSSOLVERTHREAD_H
