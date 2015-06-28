#include "stone1.h"

Stone1::Stone1(QWidget *parent,int loc)
{
    but=new Stone(parent);
//    check=false;
    location=loc;
    special=0;
    but->setScaledContents(true);
}

Stone1::~Stone1()
{
    delete but;
}

void Stone1::loadpic(){
    QPixmap icon;
    if(special!=0){
        char tmp[25];
        std::sprintf(tmp,":/icon/stone1-%d.png",special);
        icon.load(tmp);
    }else{
        icon.load(":/icon/stone1.png");
    }
    but->setPixmap(icon);
    but->setGeometry(MARGIN+(location%SIDE)*SIZE,MARGIN+(location/SIDE)*SIZE,SIZE,SIZE);
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
