#include "stone3.h"

Stone3::Stone3(QWidget *parent,int loc)
{
    but=new Stone(parent);
//    check=false;
    location=loc;
}

Stone3::~Stone3()
{

}

void Stone3::loadpic(){
    QPixmap icon(":/icon/stone3.png");
    but->setPixmap(icon);
    but->setScaledContents(true);
    but->setGeometry(MARGIN+(location%SIDE)*SIZE,MARGIN+(location/SIDE)*SIZE,SIZE,SIZE);
    but->show();
}

int Stone3::type(){
    return 3;
}

bool Stone3::isChecked(){
    return but->isChecked();
}

void Stone3::setChecked(bool b){
    but->setChecked(b);
}
