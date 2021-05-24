#ifndef MAZE_PAGE_H
#define MAZE_PAGE_H

#include <QDialog>
#include"maze.h"
#include "rectnode.h"
namespace Ui {
class maze_page;
}

class maze_page : public QDialog
{
    Q_OBJECT

public:
    Maze *maze;
    explicit maze_page(QWidget *parent = nullptr,int m=10,int n=20);
    ~maze_page();

private slots:
    void on_pushButton_5_clicked();

    void on_pad_up_clicked();

    void on_pad_right_clicked();

    void on_pad_down_clicked();

    void on_pad_left_clicked();

private:
    Ui::maze_page *ui;
};

#endif // MAZE_PAGE_H
