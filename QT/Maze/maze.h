#ifndef MAZE_H
#define MAZE_H
#include<vector>
#include "rectnode.h"
#include<QGraphicsScene>
#include <stdlib.h>     /* srand, rand */
#include<deque>
#include "dfssolverthread.h"
#include "bfssolverthread.h"
class Maze :  public QObject
{
public:
    Maze(QGraphicsScene* scene,int m,int n);
    ~Maze();
    int m{},n{};
    std::vector<std::vector<RectNode*>> matrix;
    void add_maze();
    void clear_path();
    enum direction{left=0,right=1,up=2,down=3};
    void change_head(direction d);
    void solveBFS();
    void solveDFS();
public slots:
    void do_update_scene(RectNode* node,bool state);
private:
    std::vector<QThread*> thread_list{};
    QGraphicsScene* scene;
    std::vector<int> neighbour_available(RectNode* rec);
    void create_maze();
    bool is_any_rect_notpassed();
    bool is_in_path(const int& x,const int& y,const std::deque<RectNode*>& path) const;
    std::deque<RectNode*> path{};
    bool is_passed(const int& x,const int& y);
};

#endif // MAZE_H
