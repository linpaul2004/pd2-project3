#include "stone4.h"

Stone4::Stone4(QWidget *parent,int loc):Stone1(parent,loc)
{
//    but=new Stone(parent);
//    check=false;
//    location=loc;
    but->setScaledContents(true);
}

Stone4::~Stone4()
{

}

void Stone4::loadpic(){
    QPixmap icon;
    icon.load(":/icon/stone4.png");
    but->setPixmap(icon);
    but->setGeometry(MARGIN+(location%SIDE)*SIZE,MARGIN+(location/SIDE)*SIZE,SIZE,SIZE);
    but->show();
}

int Stone4::type(){
    return 4;
}

bool Stone4::isChecked(){
    return but->isChecked();
}

void Stone4::setChecked(bool b){
    but->setChecked(b);
}
