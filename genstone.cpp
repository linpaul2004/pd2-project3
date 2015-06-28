#include "genstone.h"

Stone1* genStone(int l, QWidget *parent){
    int type=std::rand()%TOTAL+1;
    Stone1* ptr=NULL;
    switch(type){
    case 1:
        ptr=new Stone1(parent,l);
        break;
    case 2:
        ptr=new Stone2(parent,l);
        break;
    case 3:
        ptr=new Stone3(parent,l);
        break;
    case 4:
        ptr=new Stone4(parent,l);
        break;
    case 5:
        ptr=new Stone5(parent,l);
        break;
    }
    return ptr;
}

