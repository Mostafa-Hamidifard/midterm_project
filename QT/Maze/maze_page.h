#ifndef MAZE_PAGE_H
#define MAZE_PAGE_H

#include <QDialog>

namespace Ui {
class maze_page;
}

class maze_page : public QDialog
{
    Q_OBJECT

public:
    explicit maze_page(QWidget *parent = nullptr);
    ~maze_page();

private:
    Ui::maze_page *ui;
};

#endif // MAZE_PAGE_H
