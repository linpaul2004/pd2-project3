#include "candycrush.h"
#include "ui_candycrush.h"

CandyCrush::CandyCrush(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CandyCrush),selected(false)
{
    ui->setupUi(this);
    newboard(numboard);
    std::srand(std::time(NULL));
    for(int i=0;i<SIDE*SIDE;i++){
        board[i]=new QPushButton(this);
        board[i]->setGeometry(10+(i%SIDE)*50,10+(i/SIDE)*50,50,50);
        char tmp[10];
        std::sprintf(tmp,"%d",numboard[i]);
        board[i]->setText(tmp);
        board[i]->setCheckable(true);
        board[i]->setFont(QFont("Arial",15));
        connect(board[i],SIGNAL(clicked()),this,SLOT(select()));
    }
}

void CandyCrush::move(int from,int to){
    static QPropertyAnimation move[2];
    move[0].setPropertyName("geometry");
    move[0].setTargetObject(board[from]);
    move[0].setDuration(200);
    move[0].setStartValue(QRect(10+(from%SIDE)*50,10+(from/SIDE)*50,50,50));
    move[0].setEndValue(QRect(10+(to%SIDE)*50,10+(to/SIDE)*50,50,50));
    move[0].start();
    move[1].setPropertyName("geometry");
    move[1].setTargetObject(board[to]);
    move[1].setDuration(200);
    move[1].setStartValue(QRect(10+(to%SIDE)*50,10+(to/SIDE)*50,50,50));
    move[1].setEndValue(QRect(10+(from%SIDE)*50,10+(from/SIDE)*50,50,50));
    move[1].start();
}

void CandyCrush::sleep(int t){
    QElapsedTimer st;
    st.start();
    while(st.elapsed()<t)
        QCoreApplication::processEvents();
}

void CandyCrush::down(){
    for(int row=SIDE-2;row>=0;row--){
        for(int col=0;col<SIDE;col++){
            for(int i=row;i<SIDE-1;i++){
                if(numboard[(i+1)*SIDE+col]==0){
                    numboard[(i+1)*SIDE+col]=numboard[i*SIDE+col];
                    numboard[i*SIDE+col]=0;
                }else{
                    break;
                }
            }
        }
    }
}

void CandyCrush::select(){
    static int record;
    if(selected){
        for(int i=0;i<SIDE*SIDE;i++){
            if(board[i]->isChecked() && record!=i){
                if(record-i==1 || record-i==-1 || record-i==SIDE || record-i==-SIDE){
                    move(record,i);
                    selected=false;
                    board[i]->setChecked(false);
                    board[record]->setChecked(false);
                    QPushButton *tmp;
                    tmp=board[i];
                    board[i]=board[record];
                    board[record]=tmp;
                    int itmp;
                    itmp=numboard[i];
                    numboard[i]=numboard[record];
                    numboard[record]=itmp;
                    if(kill(numboard)){
                        update();
                        sleep(2000);
                        down();
                        update();
                        sleep(2000);
                        fill();
                        update();
                        sleep(2000);
                        while(kill(numboard)){
                            update();
                            sleep(2000);
                            down();
                            update();
                            sleep(2000);
                            fill();
                            update();
                            sleep(2000);
                        }
                        update();
                    }else{
                        sleep(250);
                        move(record,i);
                        tmp=board[i];
                        board[i]=board[record];
                        board[record]=tmp;
                        itmp=numboard[i];
                        numboard[i]=numboard[record];
                        numboard[record]=itmp;
                    }
                }else{
                    board[record]->setChecked(false);
                    record=i;
                }
                return;
            }
        }
    }else{
        selected=true;
        for(int i=0;i<SIDE*SIDE;i++){
            if(board[i]->isChecked()){
                record=i;
            }
        }
    }
}

void CandyCrush::fill(){
    for(int i=0;i<SIDE*SIDE;i++){
        if(numboard[i]==0){
            numboard[i]=std::rand()%4+1;
        }
    }
}

void CandyCrush::newboard(int *a){
    for(int i=0;i<SIDE*SIDE;i++){
        a[i]=std::rand()%7+1;
    }
    while(kill(a)){
        fill();
    }
}

bool CandyCrush::kill(int *a){
    tokill.clear();
    for(int i=0;i<SIDE-2;i++){
        for(int j=0;j<SIDE;j++){
            if(a[i*SIDE+j]==a[(i+1)*SIDE+j] && a[i*SIDE+j]==a[(i+2)*SIDE+j]){
                tokill.insert(i*SIDE+j);
                tokill.insert((i+1)*SIDE+j);
                tokill.insert((i+2)*SIDE+j);
            }
        }
    }
    for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE-2;j++){
            if(a[i*SIDE+j]==a[i*SIDE+j+1] && a[i*SIDE+j]==a[i*SIDE+j+2]){
                tokill.insert(i*SIDE+j);
                tokill.insert(i*SIDE+j+1);
                tokill.insert(i*SIDE+j+2);
            }
        }
    }
    if(tokill.empty()){
        return false;
    }else{
        for(std::set<int>::iterator it=tokill.begin();it!=tokill.end();it++){
            a[*it]=0;
        }
        return true;
    }
}

CandyCrush::~CandyCrush()
{
    delete ui;
}

void CandyCrush::update(){
    for(int i=0;i<SIDE*SIDE;i++){
        char tmp[10];
        std::sprintf(tmp,"%d",numboard[i]);
        board[i]->setText(tmp);
        board[i]->setCheckable(true);
    }
    for(int i=0;i<SIDE*SIDE;i++){
        std::printf("%d ",numboard[i]);
        if(i==SIDE*SIDE-1){
            std::puts("");
        }
        if((i+1)%SIDE==0){
            std::puts("");
        }
    }
}

void CandyCrush::on_pushButton_clicked()
{
    newboard(numboard);
    update();
}
