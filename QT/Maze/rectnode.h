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
    enum direction{left=0,right=1,up=2,down=3};
    std::map<int,RectNode*> neighbours{{right,nullptr},{left,nullptr},{up,nullptr},{down,nullptr}};
    static void make_neighbour(RectNode* r1,RectNode* r2,int m, int n);
    void update_rect_nei_colors(int m ,int n);
    void set_passed(bool passed);
    bool get_passed();
    std::vector<RectNode*> real_neighbours();
    RectNode* parent{nullptr};
    int x{};
    int y{};
    enum rect_N {top_left_rec=0,buttom_left_rec=1,top_right_rec=2,buttom_right_rec=3,center_rec=4,
               left_rec=5  ,up_rec,right_rec=6,down_rec=7};
    std::map<int,QGraphicsRectItem*> rect_container{{top_left_rec,nullptr},
                                                   {buttom_left_rec,nullptr},
                                                   {top_right_rec,nullptr},
                                                   {buttom_right_rec,nullptr},
                                                   {center_rec,nullptr},
                                                   {left_rec,nullptr},
                                                   {up_rec,nullptr},
                                                   {right_rec,nullptr},
                                                   {down_rec,nullptr}};
    const QColor passed_color{241, 196, 15};
    const  QColor not_passed_color{0xff,0xff,0xff};
    const  QColor block_color {40, 116, 166};
    const  QColor no_block_color{0xff,0xff,0xff};
private:
    bool passed{false};
    int center_scale{25};
    int corner_scale{4};
};

#endif // RECTNODE_H
