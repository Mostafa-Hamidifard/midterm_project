#ifndef MAZE_H
#define MAZE_H
#include<vector>
#include "rectnode.h"
#include<QGraphicsScene>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
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
};

#endif // MAZE_H
