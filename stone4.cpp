#include "stone4.h"

Stone4::Stone4(QWidget *parent,int loc)
{
    but=new Stone(parent);
//    check=false;
    location=loc;
}

Stone4::~Stone4()
{

}

void Stone4::loadpic(){
    QPixmap icon(":/icon/stone4.png");
    but->setPixmap(icon);
    but->setScaledContents(true);
    but->setGeometry(10+(location%SIDE)*50,10+(location/SIDE)*50,50,50);
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
