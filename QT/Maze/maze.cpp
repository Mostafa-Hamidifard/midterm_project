#include "maze.h"

Maze::Maze(int _m,int _n):m{_m},n{_n}
{
    for(int i{0};i<m;i++){
       std::vector<RectNode*> *nodes = new std::vector<RectNode*>();

       for(int j{0};j<n;j++){
            nodes->push_back(new RectNode(i,j,false));
            RectNode::update_rect_nei_colors(nodes->operator[](j)); // to make borders at first
       }
       matrix.push_back(*nodes);
    }
    // change [0][0] as enterance
    matrix[0][0]->left_rec->setPen(Qt::NoPen);
    matrix[0][0]->left_rec->setBrush(Qt::white);
    matrix[0][0]->center_rec->setPen(Qt::NoPen);
    // change [m-1][n-1] as exit
    matrix[m-1][n-1]->right_rec->setPen(Qt::NoPen);
    matrix[m-1][n-1]->right_rec->setBrush(Qt::white);
    matrix[m-1][n-1]->center_rec->setPen(Qt::NoPen);
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


