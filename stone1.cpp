#include "stone1.h"

Stone1::Stone1(QWidget *parent,int loc)
{
    but=new Stone(parent);
//    check=false;
    location=loc;
}

Stone1::~Stone1()
{
    delete but;
}

void Stone1::loadpic(){
    QPixmap icon(":/icon/stone1.png");
    but->setPixmap(icon);
    but->setScaledContents(true);
    but->setGeometry(10+(location%SIDE)*50,10+(location/SIDE)*50,50,50);
    but->show();
}

int Stone1::type(){
    return 1;
}

bool Stone1::isChecked(){
    return but->isChecked();
}

void Stone1::setChecked(bool b){
    but->setChecked(b);
}
