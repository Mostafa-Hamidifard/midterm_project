#include "maze_page.h"
#include "ui_maze_page.h"
#include <QtGui>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QGraphicsLineItem>
#include "rectnode.h"
#include "maze.h"
maze_page::maze_page(QWidget *parent,int m,int n) :
    QDialog(parent),
    ui(new Ui::maze_page)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene(ui->gv);
    scene->setBackgroundBrush(Qt::white);
    ui->gv->setScene(scene);
    ui->gv->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    Maze * maze = new Maze(m,n);
    maze->add_maze(scene);
    this->showMaximized();
}

maze_page::~maze_page()
{
    delete ui;
}
