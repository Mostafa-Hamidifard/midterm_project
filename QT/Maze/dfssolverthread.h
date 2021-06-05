#ifndef DFSSOLVERTHREAD_H
#define DFSSOLVERTHREAD_H
#include <QThread>
#include "rectnode.h"
#include <deque>
class DFSsolverThread : public QThread
{
    Q_OBJECT
signals:
    void update_scene(RectNode*,bool);
public:
    DFSsolverThread(std::deque<RectNode*>& _path,
                    std::vector<std::vector<RectNode*>> &_matrix,int _m,int _n);
    void solveDFS();
    void run() override;
    bool Depth_first_search(RectNode *head);
    std::deque<RectNode*> path{};
    std::vector<std::vector<RectNode*>> matrix;
    int m;
    int n;
    unsigned long delay = 50;
    bool stop = false;
};

#endif // DFSSOLVERTHREAD_H
