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
};

#endif // MAZE_H
