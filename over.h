#ifndef OVER_H
#define OVER_H

#include <QDialog>
#include <cstdio>

namespace Ui {
class Over;
}

class Over : public QDialog
{
    Q_OBJECT

public:
    explicit Over(QWidget *parent = 0);
    ~Over();

private:
    Ui::Over *ui;
private slots:
    void construct(bool result,int star,int score);
    void on_pushButton_clicked();
};

#endif // OVER_H
