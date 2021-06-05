#include "bfssolverthread.h"

bfsSolverThread::bfsSolverThread(std::deque<RectNode *> &_path,
                                 std::vector<std::vector<RectNode *> > &_matrix,
                                 int _m, int _n):
    path{_path},matrix{_matrix},m{_m},n{_n}
{}

void bfsSolverThread::run()
{
    QMutex mutex;
    mutex.lock();
    bool target_found{false};
    std::deque<RectNode*>   children{ get_children(matrix[0][0])};
    update_scene(matrix[0][0],true);
    for(RectNode* child:children)
        child->parent = matrix[0][0];
    while(target_found == 0){
        for(RectNode* child: children){
            update_scene(child,true);
            this->msleep(delay);
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
    path.push_front(matrix[0][0]);
    for(auto row:matrix)
        for(auto item:row)
            update_scene(item,false);
    this->msleep(400);
    for(auto item:path)
        update_scene(item,true);
    this->msleep(400);
    for(auto item:path)
        update_scene(item,false);
    this->msleep(400);
    for(auto item:path)
        update_scene(item,true);
    this->msleep(400);
    for(auto item:path)
        update_scene(item,false);
    this->msleep(400);
    for(auto item:path)
        update_scene(item,true);
    mutex.unlock();
}



std::deque<RectNode*> bfsSolverThread::get_children(RectNode* node){
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
