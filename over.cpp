#include "over.h"
#include "ui_over.h"

Over::Over(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Over)
{
    ui->setupUi(this);
}

Over::~Over()
{
    delete ui;
}

void Over::construct(bool result, int star, int score){
    if(result){
        ui->winLose->setText("You Win!!");
    }else{
        ui->winLose->setText("You Lose!!");
    }
    ui->score->display(score);
    char tmp[25];
    std::sprintf(tmp,":/icon/star%d.png",star);
    QPixmap b(tmp);
    ui->star->setPixmap(b);
}

void Over::on_pushButton_clicked()
{
    this->close();
}
