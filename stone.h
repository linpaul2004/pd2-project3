#ifndef STONE_H
#define STONE_H

#include <QWidget>

class Stone : public QWidget
{
    Q_OBJECT
public:
    explicit Stone(QWidget *parent = 0);
    virtual void loadpicture() =0;
    ~Stone();

signals:

public slots:
};

#endif // STONE_H
