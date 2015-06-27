#include "stone.h"

Stone::Stone(QWidget *parent):QLabel(parent)
{
    check=false;
}

Stone::~Stone()
{
//    delete this;
}

void Stone::mouseReleaseEvent(QMouseEvent *){
    check=(check ? false:true);
    emit clicked();
}

bool Stone::isChecked(){
    return check;
}

void Stone::setChecked(bool t){
    check=t;
}
