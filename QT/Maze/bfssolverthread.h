#ifndef BFSSOLVERTHREAD_H
#define BFSSOLVERTHREAD_H

#include <QThread>
#include "rectnode.h"
#include "deque"
class bfsSolverThread : public QThread
{
    Q_OBJECT
signals:
    void update_scene(RectNode*,bool);
public:
    bfsSolverThread(std::deque<RectNode*>& _path,
                    std::vector<std::vector<RectNode*>> &_matrix,int _m,int _n);
    void run() override;
    std::deque<RectNode*> path{};
    std::vector<std::vector<RectNode*>> matrix;
    int m;
    int n;
    unsigned long delay = 50;
    std::deque<RectNode*> get_children(RectNode* node);
    bool stop =false;
};

#endif // BFSSOLVERTHREAD_H
