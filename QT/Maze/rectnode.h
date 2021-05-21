#ifndef RECTNODE_H
#define RECTNODE_H

#include<QGraphicsRectItem>
#include<QtGui>
#include<QGraphicsScene>
#include<map>
class RectNode
{
public:
    RectNode(int x,int y,bool enabled);
    ~RectNode();
    void add_node(QGraphicsScene* scene);
    enum others{left,right,up,down};
    std::map<others,RectNode*> neighbours{{right,nullptr},{left,nullptr},{up,nullptr},{down,nullptr}};
    static void make_neighbour(RectNode* r1,RectNode* r2);
    static void change_colors(RectNode* r1);
private:
    int x{};
    int y{};
    int center_scale{20};
    int corner_scale{2};
    QGraphicsRectItem * top_left_rec;
    QGraphicsRectItem * buttom_left_rec;
    QGraphicsRectItem * top_right_rec;
    QGraphicsRectItem * buttom_right_rec;
    QGraphicsRectItem * center_rec;
    QGraphicsRectItem * left_rec;
    QGraphicsRectItem * up_rec;
    QGraphicsRectItem * right_rec;
    QGraphicsRectItem * down_rec;
};

#endif // RECTNODE_H
