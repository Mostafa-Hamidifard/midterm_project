#ifndef MAZE_H
#define MAZE_H
#include<vector>
#include "rectnode.h"
#include<QGraphicsScene>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include<deque>
class Maze
{
public:
    Maze(int m,int n);
    ~Maze();
    int m{},n{};
    std::vector<std::vector<RectNode*>> matrix;
    void add_maze(QGraphicsScene* scene);
    static void update_rect_colors(RectNode* node);
    void clear_path();
    enum direction{left=0,right=1,up=2,down=3};
    void change_head(direction d);
private:
    std::vector<int> neighbour_available(RectNode* rec);
    void create_maze();
    bool is_any_rect_notpassed();
    bool is_in_path(const int& x,const int& y,const std::deque<RectNode*>& path) const;
    std::deque<RectNode*> path{};
    bool is_passed(const int& x,const int& y);

};

#endif // MAZE_H
