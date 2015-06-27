#include "stone2.h"

Stone2::Stone2(QWidget *parent,int loc)
{
    but=new Stone(parent);
//    check=false;
    location=loc;
}

Stone2::~Stone2()
{

}

void Stone2::loadpic(){
    QPixmap icon(":/icon/stone2.png");
    but->setPixmap(icon);
    but->setScaledContents(true);
    but->setGeometry(10+(location%SIDE)*50,10+(location/SIDE)*50,50,50);
    but->show();
}

int Stone2::type(){
    return 2;
}

bool Stone2::isChecked(){
    return but->isChecked();
}

void Stone2::setChecked(bool b){
    but->setChecked(b);
}
