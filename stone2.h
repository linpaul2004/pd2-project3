#ifndef STONE2_H
#define STONE2_H

#include "stone1.h"

class Stone2: public Stone1
{
public:
    explicit Stone2(QWidget *parent = 0, int loc=0);
    virtual ~Stone2();
    virtual void loadpic();
    virtual int type();
    virtual bool isChecked();
    virtual void setChecked(bool);
};

#endif // STONE2_H
