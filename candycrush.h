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
#define SIDE 7

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
    void move(int,int);
    void update();
    void down();
    void fill();
    int numboard[SIDE*SIDE];
    void newboard(int*);
    void sleep(int t);
    bool kill(int*);
    std::set<int> tokill;
    QPushButton* board[SIDE*SIDE];
};

#endif // CANDYCRUSH_H
