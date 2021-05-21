#include "maze.h"

Maze::Maze(int _m,int _n):m{_m},n{_n}
{
    for(int i{0};i<m;i++){
       std::vector<RectNode*> *nodes = new std::vector<RectNode*>();

       for(int j{0};j<n;j++){
            nodes->push_back(new RectNode(i,j,false));
       }
       matrix.push_back(*nodes);
    }
    // algorithm to create a maze:
       srand (time(NULL));
      int nn = rand() % 4 + 1;


}
Maze::~Maze(){
    for(int i{0};i<m;i++){
       for(int j{0};j<n;j++){
            delete matrix[i][j];
       }
       delete &matrix[i];
    }
}


void Maze::add_maze(QGraphicsScene* scene){
    for(int i{0};i<m;i++)
       for(int j{0};j<n;j++)
          matrix[i][j]->add_node(scene);
}
