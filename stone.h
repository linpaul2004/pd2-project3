#ifndef STONE_H
#define STONE_H

#include <QLabel>
#define SIDE 7

class Stone: public QLabel
{
    Q_OBJECT
public:
    explicit Stone(QWidget*parent=0);
    bool isChecked();
    void setChecked(bool);
    virtual ~Stone();

signals:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent*);
    bool check;

private:

public slots:
};

#endif // STONE_H
