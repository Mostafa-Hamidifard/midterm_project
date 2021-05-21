#include "rectnode.h"

RectNode::RectNode(int _x,int _y,bool enabled):
    x{_x},y{_y}
{   int length{corner_scale+center_scale};
    x *= length;
    y *= length;
   top_left_rec = new QGraphicsRectItem(x,y,corner_scale,corner_scale);
   buttom_left_rec = new QGraphicsRectItem(x,y+center_scale+corner_scale,corner_scale,corner_scale);
   top_right_rec = new QGraphicsRectItem(x+center_scale+corner_scale,y,corner_scale,corner_scale);
   buttom_right_rec = new QGraphicsRectItem(x+center_scale+corner_scale,y+center_scale+corner_scale,corner_scale,corner_scale);

   center_rec = new QGraphicsRectItem(x+corner_scale,y+corner_scale,center_scale,center_scale);

   left_rec = new QGraphicsRectItem(x,y+corner_scale,corner_scale,center_scale);
   up_rec = new QGraphicsRectItem(x+corner_scale,y,center_scale,corner_scale);
   right_rec = new QGraphicsRectItem(x+center_scale+corner_scale,y+corner_scale,corner_scale,center_scale);
   down_rec = new QGraphicsRectItem(x+corner_scale,y+corner_scale+center_scale,center_scale,corner_scale);

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
             throw std::logic_error("error in make_neighbour");
        }
    }
    change_colors(r1);
    change_colors(r2);
}
void RectNode::change_colors(RectNode* r1){

}
