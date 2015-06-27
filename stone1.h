#ifndef STONE1_H
#define STONE1_H

#include <QObject>
#include "stone.h"

class Stone1
{
public:
    explicit Stone1(QWidget *parent = 0, int loc=0);
    virtual ~Stone1();
    virtual void loadpic();
    virtual int type();
    virtual bool isChecked();
    virtual void setChecked(bool);
    int location;
    Stone* but;
};

#endif // STONE1_H
