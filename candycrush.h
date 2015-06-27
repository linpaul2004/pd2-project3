#ifndef CANDYCRUSH_H
#define CANDYCRUSH_H

#include <QMainWindow>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QElapsedTimer>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <ctime>
#include "genstone.h"

namespace Ui {
class CandyCrush;
}

class CandyCrush : public QMainWindow
{
    Q_OBJECT

public:
    explicit CandyCrush(QWidget *parent = 0);
    ~CandyCrush();

private slots:
    void on_pushButton_clicked();
    void select();

private:
    Ui::CandyCrush *ui;
    bool selected;
    void swap(Stone1 *&a, Stone1 *&b);
//    bool selected;
    void move(int,int);
    void update();
    void down();
    void fill();
//    int numboard[SIDE*SIDE];
    void newboard();
    void sleep(int t);
    bool kill();
//    std::set<int> tokill;
    Stone1* board[SIDE*SIDE];
};

#endif // CANDYCRUSH_H
