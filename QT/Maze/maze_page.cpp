#include "maze_page.h"
#include "ui_maze_page.h"

maze_page::maze_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maze_page)
{

    ui->setupUi(this);
}

maze_page::~maze_page()
{
    delete ui;
}
