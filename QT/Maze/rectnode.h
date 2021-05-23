#ifndef RECTNODE_H
#define RECTNODE_H

#include<QGraphicsRectItem>
#include<QtGui>
#include<QGraphicsScene>
#include<map>
#include<vector>
class RectNode
{
public:
    RectNode(int x,int y,bool passed);
    ~RectNode();
    void add_node(QGraphicsScene* scene);
    enum others{left=0,right=1,up=2,down=3};
    std::map<int,RectNode*> neighbours{{right,nullptr},{left,nullptr},{up,nullptr},{down,nullptr}};
    static void make_neighbour(RectNode* r1,RectNode* r2);
    static void update_rect_nei_colors(RectNode *node);
    void set_passed(bool passed);
    bool get_passed();
    std::vector<int> neighbour_available();
    int x{};
    int y{};
    QGraphicsRectItem * top_left_rec;
    QGraphicsRectItem * buttom_left_rec;
    QGraphicsRectItem * top_right_rec;
    QGraphicsRectItem * buttom_right_rec;
    QGraphicsRectItem * center_rec;
    QGraphicsRectItem * left_rec;
    QGraphicsRectItem * up_rec;
    QGraphicsRectItem * right_rec;
    QGraphicsRectItem * down_rec;
private:
    bool passed{false};
    int center_scale{24};
    int corner_scale{4};

};

#endif // RECTNODE_H
