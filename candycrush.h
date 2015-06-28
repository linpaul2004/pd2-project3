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
#include "score.h"
#include "over.h"

namespace Ui {
class CandyCrush;
}

class CandyCrush : public QMainWindow
{
    Q_OBJECT

public:
    explicit CandyCrush(QWidget *parent = 0);
    ~CandyCrush();

signals:
    void quit(int star,int score);
    void toOver(bool,int,int);

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
    Score score;
//    std::set<int> tokill;
    Stone1* board[SIDE*SIDE];
    Over* over;
};

#endif // CANDYCRUSH_H
