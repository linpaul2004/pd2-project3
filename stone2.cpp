#include "stone2.h"

Stone2::Stone2(QWidget *parent,int loc):Stone1(parent,loc)
{
//    but=new Stone(parent);
//    check=false;
//    location=loc;
    but->setScaledContents(true);
}

Stone2::~Stone2()
{

}

void Stone2::loadpic(){
    QPixmap icon;
    if(special!=0){
        char tmp[25];
        std::sprintf(tmp,":/icon/stone2-%d.png",special);
        icon.load(tmp);
    }else{
        icon.load(":/icon/stone2.png");
    }
    but->setPixmap(icon);
    but->setGeometry(MARGIN+(location%SIDE)*SIZE,MARGIN+(location/SIDE)*SIZE,SIZE,SIZE);
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
