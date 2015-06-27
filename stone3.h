#ifndef STONE3_H
#define STONE3_H

#include "stone1.h"

class Stone3: public Stone1
{
public:
    explicit Stone3(QWidget *parent = 0, int loc=0);
    virtual ~Stone3();
    virtual void loadpic();
    virtual int type();
    virtual bool isChecked();
    virtual void setChecked(bool);
};

#endif // STONE3_H
