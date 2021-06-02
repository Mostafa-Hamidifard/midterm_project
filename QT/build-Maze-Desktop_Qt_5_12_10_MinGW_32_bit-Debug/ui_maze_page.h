/********************************************************************************
** Form generated from reading UI file 'maze_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZE_PAGE_H
#define UI_MAZE_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_maze_page
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *maze_view_lay;
    QGraphicsView *gv;
    QHBoxLayout *horizontalLayout;
    QGridLayout *pad_lay;
    QPushButton *pad_left;
    QPushButton *pad_up;
    QPushButton *pad_down;
    QPushButton *pad_right;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *new_reset_lay;
    QPushButton *btn_dfs;
    QPushButton *btn_bfs;
    QVBoxLayout *new_reset_lay_3;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *maze_page)
    {
        if (maze_page->objectName().isEmpty())
            maze_page->setObjectName(QString::fromUtf8("maze_page"));
        maze_page->resize(800, 800);
        verticalLayout_2 = new QVBoxLayout(maze_page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        maze_view_lay = new QVBoxLayout();
        maze_view_lay->setObjectName(QString::fromUtf8("maze_view_lay"));
        gv = new QGraphicsView(maze_page);
        gv->setObjectName(QString::fromUtf8("gv"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gv->sizePolicy().hasHeightForWidth());
        gv->setSizePolicy(sizePolicy);
        gv->setMinimumSize(QSize(0, 0));

        maze_view_lay->addWidget(gv);


        verticalLayout_2->addLayout(maze_view_lay);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pad_lay = new QGridLayout();
        pad_lay->setSpacing(0);
        pad_lay->setObjectName(QString::fromUtf8("pad_lay"));
        pad_left = new QPushButton(maze_page);
        pad_left->setObjectName(QString::fromUtf8("pad_left"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pad_left->sizePolicy().hasHeightForWidth());
        pad_left->setSizePolicy(sizePolicy1);
        pad_left->setMaximumSize(QSize(30, 50));

        pad_lay->addWidget(pad_left, 1, 0, 1, 1);

        pad_up = new QPushButton(maze_page);
        pad_up->setObjectName(QString::fromUtf8("pad_up"));
        sizePolicy1.setHeightForWidth(pad_up->sizePolicy().hasHeightForWidth());
        pad_up->setSizePolicy(sizePolicy1);
        pad_up->setMaximumSize(QSize(30, 50));

        pad_lay->addWidget(pad_up, 0, 1, 1, 1);

        pad_down = new QPushButton(maze_page);
        pad_down->setObjectName(QString::fromUtf8("pad_down"));
        sizePolicy1.setHeightForWidth(pad_down->sizePolicy().hasHeightForWidth());
        pad_down->setSizePolicy(sizePolicy1);
        pad_down->setMaximumSize(QSize(30, 50));

        pad_lay->addWidget(pad_down, 2, 1, 1, 1);

        pad_right = new QPushButton(maze_page);
        pad_right->setObjectName(QString::fromUtf8("pad_right"));
        sizePolicy1.setHeightForWidth(pad_right->sizePolicy().hasHeightForWidth());
        pad_right->setSizePolicy(sizePolicy1);
        pad_right->setMaximumSize(QSize(30, 50));

        pad_lay->addWidget(pad_right, 1, 2, 1, 1);


        horizontalLayout->addLayout(pad_lay);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        new_reset_lay = new QVBoxLayout();
        new_reset_lay->setObjectName(QString::fromUtf8("new_reset_lay"));
        btn_dfs = new QPushButton(maze_page);
        btn_dfs->setObjectName(QString::fromUtf8("btn_dfs"));
        btn_dfs->setMinimumSize(QSize(70, 40));
        btn_dfs->setMaximumSize(QSize(70, 40));

        new_reset_lay->addWidget(btn_dfs);

        btn_bfs = new QPushButton(maze_page);
        btn_bfs->setObjectName(QString::fromUtf8("btn_bfs"));
        btn_bfs->setMinimumSize(QSize(70, 40));
        btn_bfs->setMaximumSize(QSize(70, 40));

        new_reset_lay->addWidget(btn_bfs);


        horizontalLayout_2->addLayout(new_reset_lay);


        horizontalLayout->addLayout(horizontalLayout_2);

        new_reset_lay_3 = new QVBoxLayout();
        new_reset_lay_3->setObjectName(QString::fromUtf8("new_reset_lay_3"));
        pushButton_5 = new QPushButton(maze_page);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(70, 40));
        pushButton_5->setMaximumSize(QSize(70, 40));

        new_reset_lay_3->addWidget(pushButton_5);


        horizontalLayout->addLayout(new_reset_lay_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(maze_page);

        QMetaObject::connectSlotsByName(maze_page);
    } // setupUi

    void retranslateUi(QDialog *maze_page)
    {
        maze_page->setWindowTitle(QApplication::translate("maze_page", "Maze is created!", nullptr));
        pad_left->setText(QApplication::translate("maze_page", "L", nullptr));
        pad_up->setText(QApplication::translate("maze_page", "U", nullptr));
        pad_down->setText(QApplication::translate("maze_page", "D", nullptr));
        pad_right->setText(QApplication::translate("maze_page", "R", nullptr));
        btn_dfs->setText(QApplication::translate("maze_page", "DFS", nullptr));
        btn_bfs->setText(QApplication::translate("maze_page", "BFS", nullptr));
        pushButton_5->setText(QApplication::translate("maze_page", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class maze_page: public Ui_maze_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZE_PAGE_H
