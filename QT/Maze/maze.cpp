#include "maze.h"
#include<stack>
#include<QDebug>
Maze::Maze(int _m,int _n):m{_m},n{_n}
{
    for(int i{0};i<m;i++){
       std::vector<RectNode*> *nodes = new std::vector<RectNode*>();
       for(int j{0};j<n;j++){
            RectNode* nod = new RectNode(i,j,false);
            std::map<int,RectNode*>* negh{&nod->neighbours};
            if(i == 0)
                negh->erase(negh->find(RectNode::others::left));
            if(i == m-1)
                negh->erase(negh->find(RectNode::others::right));
            if(j == 0)
                negh->erase(negh->find(RectNode::others::up));
            if(j == n-1)
                negh->erase(negh->find(RectNode::others::down));
            nodes->push_back(nod);
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
    create_maze(m,n);



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

void Maze::create_maze(int _m,int _n)
{
    srand (time(NULL));
    std::stack<RectNode*> stack{}; // used for tracking
    std::deque<RectNode*> path{};
    matrix[0][0]->set_passed(true);
    stack.push(matrix[0][0]); // first one is [0][0]
    path.push_back(matrix[0][0]);
    std::vector<int> negh_avai{stack.top()->neighbour_available()};
    int nn{};
    while (is_any_rect_notpassed()) {
           while(!negh_avai.empty()){
               auto curr_rect = stack.top();
               RectNode* new_negh;
               nn = rand() % negh_avai.size();
               if(negh_avai[nn] == RectNode::others::down && !is_in_path(curr_rect->x,curr_rect->y+1,path)){
                    new_negh = matrix[curr_rect->x][curr_rect->y+1];
               }else if(negh_avai[nn] == RectNode::others::left){
                    new_negh = matrix[curr_rect->x-1][curr_rect->y];
               }else if(negh_avai[nn] == RectNode::others::up){
                    new_negh = matrix[curr_rect->x][curr_rect->y-1];
               }else {
                    new_negh = matrix[curr_rect->x+1][curr_rect->y];
               }
               RectNode::make_neighbour(curr_rect,new_negh);
               new_negh->set_passed(true);
               stack.push(new_negh);
               negh_avai = stack.top()->neighbour_available();
             }
          stack.pop();
          negh_avai = stack.top()->neighbour_available();
          bool flag = true;
          while(negh_avai.empty() || flag){             //////////////////////need to get changed
              stack.pop();
              negh_avai = stack.top()->neighbour_available();
          }
    }
}

bool Maze::is_any_rect_notpassed()
{
    for(int i{0};i<m;i++){
       for(int j{0};j<n;j++){
           if(!matrix[i][j]->get_passed())
               return true;
       }
    }
    return false;
}

bool Maze::is_in_path(const int& x,const int& y, const std::deque<RectNode *> &path) const
{  if(x<0 || x >= m || y<0 || y>=n)
        throw std::out_of_range("out of maze");
    RectNode* rec{matrix[x][y]};
   auto it{ std::find(path.cbegin(),path.cend(),rec)};
   if(it==path.cend())
       return false;
   return true;

}



