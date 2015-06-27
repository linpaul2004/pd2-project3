#ifndef STONE4_H
#define STONE4_H

#include "stone1.h"

class Stone4: public Stone1
{
public:
    explicit Stone4(QWidget *parent = 0, int loc=0);
    virtual ~Stone4();
    virtual void loadpic();
    virtual int type();
    virtual bool isChecked();
    virtual void setChecked(bool);
};

#endif // STONE4_H
