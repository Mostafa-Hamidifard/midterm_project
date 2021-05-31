#include "maze.h"
#include<stack>
#include<QDebug>
#include<iostream>
#include <QThread>
#include<windows.h>
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
    matrix[0][0]->left_rec->setBrush(Qt::red);
    matrix[0][0]->center_rec->setPen(Qt::NoPen);
    // change [m-1][n-1] as exit
    matrix[m-1][n-1]->right_rec->setPen(Qt::NoPen);
    matrix[m-1][n-1]->right_rec->setBrush(Qt::red);
    matrix[m-1][n-1]->center_rec->setPen(Qt::NoPen);
    // algorithm to create a maze:
    create_maze();
    // [0][0] will be in path:
    path.push_back(matrix[0][0]);
    matrix[0][0]->set_passed(true);
    std::cout<<"end of maze constructor\n";
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

void Maze::clear_path()
{
    for(auto row: matrix)
        for(auto item: row)
            item->set_passed(false);
    path.clear();
    path.push_back(matrix[0][0]);
    matrix[0][0]->set_passed(true);
}

void Maze::change_head(Maze::direction d)
{   RectNode* ohead = path.back();
    //  std::cout<<"in change head\n";
    auto negh{ohead->neighbours.find(d)};
    if(negh == ohead->neighbours.end() || negh->second==nullptr)
        return;
    qDebug()<<"x: "<<ohead->x<<" y: "<<ohead->y;
    RectNode* rec_negh{negh->second};
    if(is_in_path(rec_negh->x,rec_negh->y,path)){
        ohead->set_passed(false);
        path.pop_back();
    }else{
        path.push_back(rec_negh);
        rec_negh->set_passed(true);
    }

}

void Maze::solveBFS()
{
    path.clear();
    if(m==1&&n==1){
        return;
    }else{
        qDebug()<<"BFS begins:";
        path.push_back(matrix[0][0]);
        for(auto val :matrix[0][0]->real_neighbours()){
            val->parent = matrix[0][0];
            if(val == matrix[m-1][n-1]){
                path.push_back(val);
                val->set_passed(true);
                return;
            }
        }
        Maze::Breadth_first_search(matrix[0][0]->real_neighbours());
    }
    for(auto item:path){
        item->set_passed(true);
    }
}
RectNode* Maze::Breadth_first_search(std::vector<RectNode*> parentList) // it needs to change//1,2 should work!
{
    qDebug()<<"breadth_first_search CALLED";
    for(auto parent :parentList){
        qDebug()<<"parent: x,y="<<parent->x<<", "<<parent->y;
        for(auto child:parent->real_neighbours()){
            qDebug()<<"     child: x,y="<<child->x<<", "<<child->y;
        }
    }
    if(parentList.empty()){
        qDebug()<<"parentList was empty";
        return nullptr;
    }
    for(auto parent: parentList){
        qDebug()<<"first loop with parent: x="<<parent->x<<" y="<<parent->y;
        for(auto child : parent->real_neighbours()){
            if(child == parent->parent){
                continue;
            }
            qDebug()<<"child: x: "<<child->x<<" y: "<<child->y;
            child->parent = parent;
            if(child == matrix[m-1][n-1]){
                path.push_back(child->parent);
                path.push_back(child);
                return child->parent;
            }
        }
    }
    qDebug()<<"first for ended";
    std::vector<RectNode*> temp_par{};
    for(auto parent: parentList){
        for(auto child:parent->real_neighbours()){
            if(child == parent->parent)
                continue;
            std::vector<RectNode*> real_neghs{child->real_neighbours()};
            for(auto iter{real_neghs.begin()};iter<real_neghs.end();iter++){
                if(*(iter) == parent){
                    real_neghs.erase(iter);
                    qDebug()<<"parent erased x,y:"<<parent->x<<" "<<parent->y;
                }
            }
            temp_par.insert(temp_par.end(),real_neghs.begin(),real_neghs.end());
        }
    }
    RectNode* result{Breadth_first_search(temp_par)};
    if(result==nullptr){
        qDebug()<<"didnt found anything!";
        return nullptr; // didnt found anything(impossible)
    }
    path.push_back(result->parent);
    return result->parent;
}

void Maze::create_maze()
{
    srand (time(NULL));
    // std::stack<RectNode*> stack{}; // used for tracking
    matrix[0][0]->set_passed(true);
    //  stack.push(matrix[0][0]); // first one is [0][0]
    path.push_back(matrix[0][0]);
    std::vector<int> negh_avai{neighbour_available(path.back())};
    int nn{};
    while (is_any_rect_notpassed()) {
        while(negh_avai.empty()){             //////////////////////need to get changed

            //    stack.pop();
            path.pop_back();
            negh_avai = neighbour_available(path.back());
        }
        while(!negh_avai.empty()){
            auto curr_rect = path.back();
            RectNode* new_negh;
            nn = rand() % negh_avai.size();
            if(negh_avai[nn] == RectNode::others::down){
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
            //            stack.push(new_negh);
            path.push_back(new_negh);
            negh_avai = neighbour_available(path.back());
        }
        path.pop_back();
        path.pop_back();
        //        std::cout<<"top of stack is: "<<path.back()->x <<" " <<path.back()->y<<"and top of path is: "<<path.back()->x<<" "<<path.back()->y<<"\n";
        neighbour_available(path.back());
    }
    // setting all passed vars to false
    for(auto row: matrix)
        for(auto item: row)
            item->set_passed(false);
    path.clear();
}
void Maze::solveDFS(){
    path.clear();
    if(m==1&&n==1){
        return;
    }else{
        qDebug()<<"DFS begins:";
        Maze::Depth_first_search(matrix[0][0]);
    }
    for(auto item:path){
        item->set_passed(true);
    }
}
bool Maze::Depth_first_search(RectNode* head){
    path.push_back(head);
    if(head == matrix[m-1][n-1]){
        return true;
    }
    if(head->real_neighbours().empty()==true){
        path.pop_back();
        return false;
    }
    for(auto  value: head->real_neighbours()){
        if(head != matrix[0][0]){ //to avoid error loop
            if(value == *(path.end()-2)){
                continue;
            }
        }
        bool result =  Depth_first_search(value);
        if(result){
            qDebug()<<"I am :"<<head->x<<" "<<head->y;
            return true;
        }
    }//searching that head completed without any success
    path.pop_back();
    return false;
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
bool Maze::is_passed(const int& x,const int& y){
    //    std::cout <<"checking passed : x is: " <<x<<" y is: "<<y<<std::endl;
    return matrix[x][y]->get_passed();
}
std::vector<int> Maze::neighbour_available(RectNode* rec)
{
    //    std::cout <<"starting point-> rec : x is: " <<rec->x<<" y is: "<<rec->y<<std::endl;
    std::vector<int> negh{};
    for(auto [key,value] : rec->neighbours){
        if(value ==nullptr){
            if(key== RectNode::others::up && !is_in_path(rec->x,rec->y-1,path) && !is_passed(rec->x,rec->y-1)){
                negh.push_back(key);
            }else if(key== RectNode::others::right && !is_in_path(rec->x+1,rec->y,path)&& !is_passed(rec->x+1,rec->y)){
                negh.push_back(key);
            }else if(key== RectNode::others::down && !is_in_path(rec->x,rec->y+1,path)&& !is_passed(rec->x,rec->y+1)){
                negh.push_back(key);
            }else if(key== RectNode::others::left && !is_in_path(rec->x-1,rec->y,path)&& !is_passed(rec->x-1,rec->y)){
                negh.push_back(key);
            }
        }
    }
    return negh;
}

