#include "maze.h"

Maze::Maze(QGraphicsView* _g,QGraphicsScene* _s,int _m,int _n):m{_m},n{_n}
{
    scene = _s;
    gview = _g;
    for(int i{0};i<m;i++){
        std::vector<RectNode*> nodes{};
        for(int j{0};j<n;j++){
            RectNode* nod = new RectNode(i,j,false);
            std::map<int,RectNode*>* negh{&nod->neighbours};
            if(i == 0){
                negh->erase(negh->find(RectNode::direction::left));
            }if(i == m-1){
                negh->erase(negh->find(RectNode::direction::right));
            }if(j == 0){
                negh->erase(negh->find(RectNode::direction::up));
            }if(j == n-1){
                negh->erase(negh->find(RectNode::direction::down));
            }
            nodes.push_back(nod);
            nodes[j]->update_rect_nei_colors(m,n); // to make borders at first
        }
        matrix.push_back(nodes);
    }
    // algorithm to create a maze:
    create_maze();
    matrix[0][0]->rect_container[RectNode::left_rec]->setBrush(Qt::red);
    matrix[m-1][n-1]->rect_container[RectNode::right_rec]->setBrush(Qt::red);
    path.push_back(matrix[0][0]);
    matrix[0][0]->set_passed(true);
}
Maze::~Maze(){
    qDebug()<<"destruction started";
    for(int i{0};i<m;i++){
        for(int j{0};j<n;j++){
            delete matrix[i][j];
        }
    }
    qDebug()<<"destruction ended";
}
void Maze::add_maze(){
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
{
    RectNode* ohead = path.back();
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

std::deque<RectNode*> Maze::get_children(RectNode* node){
    std::vector<RectNode*> temp_neigh{node->real_neighbours()};
    std::deque<RectNode*> result{};
    for(auto it{temp_neigh.begin()};it != temp_neigh.end();it++){
        if((*it)==node->parent)
            continue;
        else
            result.push_back((*it));
    }
    return result;
}
void Maze::solveBFS()
{
    path.clear();
    if(m==1&&n==1)
        return;
    bool target_found{false};
    std::deque<RectNode*>   children{ get_children(matrix[0][0])};
    for(RectNode* child:children)
        child->parent = matrix[0][0];
    while(target_found == 0){
        for(RectNode* child: children){
            qDebug()<<"checking child x="<<child->x<<" y="<<child->y;
            if(child == matrix[m-1][n-1]){
                target_found=true;
                break;
            }
        }
        std::deque<RectNode*>  temp_children{};
        for(RectNode* item:children){
            std::deque<RectNode*> temp2{get_children(item)};
            for(RectNode* item2:temp2){
                item2->parent=item;
                temp_children.push_back(item2);
            }
        }
        children.swap(temp_children);
    }
    path.push_back(matrix[m-1][n-1]);
    RectNode* parent_node = matrix[m-1][n-1]->parent;
    while(parent_node->parent!= nullptr){
        path.push_back(parent_node);
        parent_node=parent_node->parent;
    }
    for(auto item:path)
        item->set_passed(true);

}
void Maze::create_maze()
{
    srand (time(NULL));
    matrix[0][0]->set_passed(true);
    path.push_back(matrix[0][0]);
    std::vector<int> negh_avai{neighbour_available(path.back())};
    int nn{};
    while (is_any_rect_notpassed()) {
        while(negh_avai.empty()){
            path.pop_back();
            //            if(path.empty()==0){
            //                path.push_back(matrix[0][0]);
            //            }

            negh_avai = neighbour_available(path.back());
        }
        ///////where you should change your Maze creation method////////////////////////////////////////////////////////
        while(!negh_avai.empty()){

            auto curr_rect = path.back();
            RectNode* new_negh;
            nn = rand() % negh_avai.size();
            if(negh_avai[nn] == RectNode::direction::down){
                new_negh = matrix[curr_rect->x][curr_rect->y+1];
            }else if(negh_avai[nn] == RectNode::direction::left){
                new_negh = matrix[curr_rect->x-1][curr_rect->y];
            }else if(negh_avai[nn] == RectNode::direction::up){
                new_negh = matrix[curr_rect->x][curr_rect->y-1];
            }else {
                new_negh = matrix[curr_rect->x+1][curr_rect->y];
            }
            RectNode::make_neighbour(curr_rect,new_negh,m,n);
            new_negh->set_passed(true);
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
//    for(auto item:path){
//        item->set_passed(true);
//    }
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
    return matrix[x][y]->get_passed();
}
std::vector<int> Maze::neighbour_available(RectNode* rec)
{
    std::vector<int> negh{};
    for(auto [key,value] : rec->neighbours){
        if(value ==nullptr){
            if(key== RectNode::direction::up && !is_in_path(rec->x,rec->y-1,path) && !is_passed(rec->x,rec->y-1)){
                negh.push_back(key);
            }else if(key== RectNode::direction::right && !is_in_path(rec->x+1,rec->y,path)&& !is_passed(rec->x+1,rec->y)){
                negh.push_back(key);
            }else if(key== RectNode::direction::down && !is_in_path(rec->x,rec->y+1,path)&& !is_passed(rec->x,rec->y+1)){
                negh.push_back(key);
            }else if(key== RectNode::direction::left && !is_in_path(rec->x-1,rec->y,path)&& !is_passed(rec->x-1,rec->y)){
                negh.push_back(key);
            }
        }
    }
    return negh;
}

