#include "stone5.h"

Stone5::Stone5(QWidget *parent,int loc)
{
    but=new Stone(parent);
//    check=false;
    location=loc;
}

Stone5::~Stone5()
{

}

void Stone5::loadpic(){
    QPixmap icon(":/icon/stone5.png");
    but->setPixmap(icon);
    but->setScaledContents(true);
    but->setGeometry(10+(location%SIDE)*50,10+(location/SIDE)*50,50,50);
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
