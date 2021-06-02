#include "maze_page.h"
#include "ui_maze_page.h"
#include <QtGui>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QGraphicsLineItem>
#include<iostream>
maze_page::maze_page(QWidget *parent,int m,int n) :
    QDialog(parent),
    ui(new Ui::maze_page)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene(ui->gv);
    scene->setBackgroundBrush(Qt::white);
    ui->gv->setScene(scene);

    scene->setBackgroundBrush(QColor{40, 116, 166});
    ui->gv->setAlignment(Qt::AlignTop|Qt::AlignCenter);
    maze = new Maze(m,n);
    maze->add_maze(scene);
   // this->showMaximized();
}

maze_page::~maze_page()
{  if(maze!= nullptr)
        delete maze;
    delete ui;
}

void maze_page::on_pushButton_5_clicked()
{
    maze->clear_path();
}

void maze_page::on_pad_up_clicked()
{
    maze->change_head(Maze::up);

}

void maze_page::on_pad_right_clicked()
{
     maze->change_head(Maze::right);

}

void maze_page::on_pad_down_clicked()
{

    maze->change_head(Maze::down);
}

void maze_page::on_pad_left_clicked()
{
    maze->change_head(Maze::left);

}


void maze_page::on_btn_bfs_clicked()
{
    maze->solveBFS();
}

void maze_page::on_btn_dfs_clicked()
{
    maze->solveDFS();
}
