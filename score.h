#ifndef SCORE_H
#define SCORE_H

#include "stone.h"

class Score
{
public:
    Score();
    ~Score();
    void operator+=(bool *);
    int getStar();
    int getScore();
    void setScore(int);
private:
    int score;
};

#endif // SCORE_H
