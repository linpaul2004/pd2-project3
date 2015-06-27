#ifndef STONE5_H
#define STONE5_H

#include "stone1.h"

class Stone5: public Stone1
{
public:
    explicit Stone5(QWidget *parent = 0, int loc=0);
    virtual ~Stone5();
    virtual void loadpic();
    virtual int type();
    virtual bool isChecked();
    virtual void setChecked(bool);
};

#endif // STONE5_H
