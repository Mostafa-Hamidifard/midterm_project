#include "rectnode.h"

RectNode::RectNode(int _x,int _y,bool _passed):
    x{_x},y{_y}
{   int length{corner_scale+center_scale};
    passed = _passed;
    _x *= length;
    _y *= length;
   top_left_rec = new QGraphicsRectItem(_x,_y,corner_scale,corner_scale);
   buttom_left_rec = new QGraphicsRectItem(_x,_y+center_scale+corner_scale,corner_scale,corner_scale);
   top_right_rec = new QGraphicsRectItem(_x+center_scale+corner_scale,_y,corner_scale,corner_scale);
   buttom_right_rec = new QGraphicsRectItem(_x+center_scale+corner_scale,_y+center_scale+corner_scale,corner_scale,corner_scale);

   center_rec = new QGraphicsRectItem(_x+corner_scale,_y+corner_scale,center_scale,center_scale);

   left_rec = new QGraphicsRectItem(_x,_y+corner_scale,corner_scale,center_scale);
   up_rec = new QGraphicsRectItem(_x+corner_scale,_y,center_scale,corner_scale);
   right_rec = new QGraphicsRectItem(_x+center_scale+corner_scale,_y+corner_scale,corner_scale,center_scale);
   down_rec = new QGraphicsRectItem(_x+corner_scale,_y+corner_scale+center_scale,center_scale,corner_scale);
}
RectNode::~RectNode()
{

   delete top_left_rec;
   delete buttom_left_rec;
   delete top_right_rec;
   delete buttom_right_rec;
   delete center_rec;
   delete left_rec;
   delete up_rec;
   delete right_rec;
   delete down_rec;
}
void RectNode::add_node(QGraphicsScene* scene){
    scene->addItem(top_left_rec);
    scene->addItem(buttom_left_rec);
    scene->addItem(top_right_rec);
    scene->addItem(buttom_right_rec);
    scene->addItem(center_rec);
    scene->addItem(left_rec);
    scene->addItem(up_rec);
    scene->addItem(right_rec);
    scene->addItem(down_rec);

}

void RectNode::make_neighbour(RectNode* r1,RectNode* r2){
    int dx = r1->x - r2->x;
    int dy = r1->y - r2->y;
    switch(dx){
    case -1:
        r1->neighbours[others::right] = r2;
        r2->neighbours[others::left] = r1;
        break;
    case 1:
        r1->neighbours[others::left] = r2;
        r2->neighbours[others::right] = r1;
        break;
    default:
        switch (dy) {
        case -1:
            r1->neighbours[others::down] = r2;
            r2->neighbours[others::up] = r1;
            break;
        case 1:
             r1->neighbours[others::up] = r2;
             r2->neighbours[others::down] = r1;
            break;
        default:
             throw std::logic_error(std::string("error in make_neighbour dx: ") + std::to_string(dx) +std::string(", dy: "+std::to_string(dy)));
        }
    }
    update_rect_nei_colors(r1);
    update_rect_nei_colors(r2);
}
void RectNode::update_rect_nei_colors(RectNode *node)
{
    auto block_color = Qt::black;
    auto no_block_color = Qt::white;
    for(const auto [key,value] : node->neighbours){
        if(value == nullptr){
           if(key == node->left){
                node->left_rec->setBrush(block_color);
                node->top_left_rec->setBrush(block_color);
                node->buttom_left_rec->setBrush(block_color);
           }else if(key == node->right){
               node->right_rec->setBrush(block_color);
               node->top_right_rec->setBrush(block_color);
               node->buttom_right_rec->setBrush(block_color);
           }else if(key == node->up){
               node->up_rec->setBrush(block_color);
               node->top_left_rec->setBrush(block_color);
               node->top_right_rec->setBrush(block_color);
           }else if(key == node->down){
               node->down_rec->setBrush(block_color);
               node->buttom_left_rec->setBrush(block_color);
               node->buttom_right_rec->setBrush(block_color);
             }
        }else{
            if(key == node->left){
                 node->left_rec->setBrush(no_block_color);
                 node->left_rec->setPen(Qt::NoPen);;
                // node->top_left_rec->setBrush(no_block_color);
               //  node->buttom_left_rec->setBrush(no_block_color);
            }else if(key == node->right){
                node->right_rec->setBrush(no_block_color);
                  //  node->top_right_rec->setBrush(no_block_color);
                //node->buttom_right_rec->setBrush(no_block_color);
                node->right_rec->setPen(Qt::NoPen);

            }else if(key == node->up){
                node->up_rec->setBrush(no_block_color);
                //node->top_left_rec->setBrush(no_block_color);
                //node->top_right_rec->setBrush(no_block_color);
                node->up_rec->setPen(Qt::NoPen);
            }else if(key == node->down){
                node->down_rec->setBrush(no_block_color);
                //node->buttom_left_rec->setBrush(no_block_color);
                //node->buttom_right_rec->setBrush(no_block_color);

                node->down_rec->setPen(Qt::NoPen);

              }
           node->center_rec->setPen(Qt::NoPen);
        }
    }
}

void RectNode::set_passed(bool _passed)
{
    passed = _passed;
    if(passed){
        this->center_rec->setBrush(Qt::green);
    }else{
        this->center_rec->setBrush(Qt::white);
    }
}

bool RectNode::get_passed()
{
    return passed;
}


