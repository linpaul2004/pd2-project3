#include "stone5.h"

Stone5::Stone5(QWidget *parent,int loc):Stone1(parent,loc)
{
//    but=new Stone(parent);
//    check=false;
//    location=loc;
}

Stone5::~Stone5()
{

}

void Stone5::loadpic(){
    QPixmap icon(":/icon/stone5.png");
    but->setPixmap(icon);
    but->setScaledContents(true);
    but->setGeometry(MARGIN+(location%SIDE)*SIZE,MARGIN+(location/SIDE)*SIZE,SIZE,SIZE);
    but->show();
}

int Stone5::type(){
    return 5;
}

bool Stone5::isChecked(){
    return but->isChecked();
}

void Stone5::setChecked(bool b){
    but->setChecked(b);
}
