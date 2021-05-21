#include "widget.h"
#include "ui_widget.h"
#include <ctype.h>
#include<string>
#include<QMessageBox>
#include"maze_page.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
void Widget::on_btn_lets_go_clicked()
{
    std::string x_dim =  ui->edttxt_xdim->text().toStdString();
    std::string y_dim =  ui->edttxt_ydim->text().toStdString();
    if(is_number(x_dim)&&is_number(y_dim)){
       maze_page m;
     //  m.setWhatsThis("Awesome Maze");
       m.setWindowFlag(Qt::WindowContextHelpButtonHint,false);
       m.setModal(true);
       m.exec();


    }else{
        QMessageBox msgBox;
        msgBox.information(this, "Error","Incorrect dimensions");
    }

}

