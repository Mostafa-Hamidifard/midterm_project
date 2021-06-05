#include "rectnode.h"
#include <QThread>
RectNode::RectNode(int _x,int _y,bool _passed):
    x{_x},y{_y}
{   int length{corner_scale+center_scale};
    passed = _passed;
    _x *= length;
    _y *= length;
   rect_container[top_left_rec] = new QGraphicsRectItem(_x,_y,corner_scale,corner_scale);
   rect_container[buttom_left_rec] = new QGraphicsRectItem(_x,_y+center_scale+corner_scale,corner_scale,corner_scale);
   rect_container[top_right_rec] = new QGraphicsRectItem(_x+center_scale+corner_scale,_y,corner_scale,corner_scale);
   rect_container[buttom_right_rec] = new QGraphicsRectItem(_x+center_scale+corner_scale-1,_y+center_scale+corner_scale,corner_scale,corner_scale);

   rect_container[center_rec] = new QGraphicsRectItem(_x+corner_scale,_y+corner_scale,center_scale,center_scale);

   rect_container[left_rec] = new QGraphicsRectItem(_x,_y+corner_scale,corner_scale,center_scale);
   rect_container[up_rec] = new QGraphicsRectItem(_x+corner_scale,_y,center_scale,corner_scale);
   rect_container[right_rec] = new QGraphicsRectItem(_x+center_scale+corner_scale,_y+corner_scale,corner_scale,center_scale);
   rect_container[down_rec] = new QGraphicsRectItem(_x+corner_scale,_y+corner_scale+center_scale,center_scale,corner_scale);
   for(auto [key,item]:rect_container){
       item->setPen(Qt::PenStyle::NoPen);
   }
}
RectNode::~RectNode()
{
    for(auto item:rect_container){
        delete item.second;
    }
}
void RectNode::add_node(QGraphicsScene* scene){
    for(auto item:rect_container){
        scene->addItem(item.second);
    }
}

void RectNode::make_neighbour(RectNode* r1,RectNode* r2,int m ,int n){
    int dx = r1->x - r2->x;
    int dy = r1->y - r2->y;
    switch(dx){
    case -1:
        r1->neighbours[direction::right] = r2;
        r2->neighbours[direction::left] = r1;
        break;
    case 1:
        r1->neighbours[direction::left] = r2;
        r2->neighbours[direction::right] = r1;
        break;
    default:
        switch (dy) {
        case -1:
            r1->neighbours[direction::down] = r2;
            r2->neighbours[direction::up] = r1;
            break;
        case 1:
             r1->neighbours[direction::up] = r2;
             r2->neighbours[direction::down] = r1;
            break;
        default:
             throw std::logic_error(std::string("error in make_neighbour dx: ") + std::to_string(dx) +std::string(", dy: "+std::to_string(dy)));
        }
    }
    r1->update_rect_nei_colors(m,n);
    r2->update_rect_nei_colors(m,n);
}
void RectNode::update_rect_nei_colors(int m,int n)
{

    for(const auto [key,value] : this->neighbours){
        if(value == nullptr){
           if(key == this->left){
                this->rect_container[left_rec]->setBrush(block_color);
                this->rect_container[top_left_rec]->setBrush(block_color);
                this->rect_container[buttom_left_rec]->setBrush(block_color);
           }else if(key == this->right){
               this->rect_container[right_rec]->setBrush(block_color);
               this->rect_container[top_right_rec]->setBrush(block_color);
               this->rect_container[buttom_right_rec]->setBrush(block_color);
           }else if(key == this->up){
               this->rect_container[up_rec]->setBrush(block_color);
               this->rect_container[top_left_rec]->setBrush(block_color);
               this->rect_container[top_right_rec]->setBrush(block_color);
           }else if(key == this->down){
               this->rect_container[down_rec]->setBrush(block_color);
               this->rect_container[buttom_left_rec]->setBrush(block_color);
               this->rect_container[buttom_right_rec]->setBrush(block_color);
             }
        }else{
            if(key == this->left){
                 this->rect_container[left_rec]->setBrush(no_block_color);
            }else if(key == this->right){
                this->rect_container[right_rec]->setBrush(no_block_color);
            }else if(key == this->up){
                this->rect_container[up_rec]->setBrush(no_block_color);
            }else if(key == this->down){
                this->rect_container[down_rec]->setBrush(no_block_color);
              }
        }
    }
    if(this->x == 0){
       this->rect_container[left_rec]->setBrush(block_color);
    }else if(this->x == m-1){
       this->rect_container[right_rec]->setBrush(block_color);
    }
    if(this->y == 0){
        this->rect_container[up_rec]->setBrush(block_color);
    }else if(this->y == n-1){
        this->rect_container[down_rec]->setBrush(block_color);
    }
}

void RectNode::set_passed(bool _passed)
{
    passed = _passed;
    if(passed){
        this->rect_container[center_rec]->setBrush(passed_color);
    }else{
        this->rect_container[center_rec]->setBrush(not_passed_color);
    }
}

bool RectNode::get_passed()
{
    return passed;
}

std::vector< RectNode *> RectNode::real_neighbours()
{
    std::vector<RectNode*> temp{};
    for(auto [key ,value] : neighbours){
        if(value != nullptr){
            temp.push_back(value);
        }
    }
    return temp;
}


