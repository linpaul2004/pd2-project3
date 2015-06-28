#include "stone3.h"

Stone3::Stone3(QWidget *parent,int loc):Stone1(parent,loc)
{
//    but=new Stone(parent);
//    check=false;
//    location=loc;
    but->setScaledContents(true);
}

Stone3::~Stone3()
{

}

void Stone3::loadpic(){
    QPixmap icon;
    if(special!=0){
        char tmp[25];
        std::sprintf(tmp,":/icon/stone3-%d.png",special);
        icon.load(tmp);
    }else{
        icon.load(":/icon/stone3.png");
    }
    but->setPixmap(icon);
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
