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
private:
    void create_maze(int m,int n);
    bool is_any_rect_notpassed();
    bool is_in_path(const int& x,const int& y,const std::deque<RectNode*>& path) const;
};

#endif // MAZE_H
