#include "score.h"

Score::Score()
{
    score=0;
}

Score::~Score()
{

}

void Score::operator +=(bool *a){
    int b=0;
    for(int i=0;i<SIDE*SIDE;i++){
        if(a[i]){
            b++;
        }
    }
    score+=(b*b);
}

int Score::getScore(){
    return score;
}

int Score::getStar(){
    if(score>=200){
        return 3;
    }else if(score>=150){
        return 2;
    }else if(score>=100){
        return 1;
    }else{
        return 0;
    }
}

void Score::setScore(int s){
    score=s;
}
