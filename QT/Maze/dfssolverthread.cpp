#include "dfssolverthread.h"
#include<qmutex.h>

DFSsolverThread::DFSsolverThread(std::deque<RectNode*> &_path,
std::vector<std::vector<RectNode*>> &_matrix,int _m,int _n):
    path{_path},matrix{_matrix},m{_m},n{_n}
{
}
void DFSsolverThread::run(){
    Depth_first_search(matrix[0][0]);
}
bool DFSsolverThread::Depth_first_search(RectNode* head){
    QMutex mutex;
    mutex.lock();
    path.push_back(head);
    head->set_passed(true);
    emit update_scene(head,true);
    this->msleep(delay);
    if(head == matrix[m-1][n-1]){
        return true;
    }
    if(head->real_neighbours().empty()==true){
        path.pop_back();
        return false;
    }
    for(auto  value: head->real_neighbours()){
        if(head != matrix[0][0]){ //to avoid error loop
            if(value == *(path.end()-2)){ // parent checking
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
    emit update_scene(head,false);
    this->msleep(delay);
    mutex.unlock();
    return false;

}
