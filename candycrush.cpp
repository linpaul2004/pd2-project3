#include "candycrush.h"
#include "ui_candycrush.h"

CandyCrush::CandyCrush(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CandyCrush),selected(false)
{
    ui->setupUi(this);
    std::srand(std::time(NULL));
    for(int i=0;i<SIDE*SIDE;i++){
//        printf("%d\n",i);
        board[i]=genStone(i,this);
//        board[i]->loadpic();
//        char tmp[10];
//        std::sprintf(tmp,"%d",numboard[i]);
//        board[i]->setText(tmp);
//        board[i]->setCheckable(true);
//        board[i]->setFont(QFont("Arial",15));
        connect(board[i]->but,SIGNAL(clicked()),this,SLOT(select()));
    }
    while(kill()){
        down();
        fill();
    }
    for(int i=0;i<SIDE*SIDE;i++){
        printf("%d->%d\n",i,board[i]);
    }
    update();
}


void CandyCrush::move(int from,int to){
    static QPropertyAnimation move[2];
    move[0].setPropertyName("geometry");
    move[0].setTargetObject(board[from]->but);
    move[0].setDuration(200);
    move[0].setStartValue(QRect(10+(from%SIDE)*50,10+(from/SIDE)*50,50,50));
    move[0].setEndValue(QRect(10+(to%SIDE)*50,10+(to/SIDE)*50,50,50));
    move[1].setPropertyName("geometry");
    move[1].setTargetObject(board[to]->but);
    move[1].setDuration(200);
    move[1].setStartValue(QRect(10+(to%SIDE)*50,10+(to/SIDE)*50,50,50));
    move[1].setEndValue(QRect(10+(from%SIDE)*50,10+(from/SIDE)*50,50,50));
    move[1].start();
    move[0].start();
    sleep(250);
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
                if(board[(i+1)*SIDE+col]==NULL && board[i*SIDE+col]!=NULL){
                    board[(i+1)*SIDE+col]=board[i*SIDE+col];
                    board[(i+1)*SIDE+col]->location=(i+1)*SIDE+col;
                    board[i*SIDE+col]=NULL;
                }else{
                    break;
                }
            }
        }
    }
}

void CandyCrush::swap(Stone1 *&a,Stone1 *&b){
    Stone1* tmp;
    int tmpa,tmpb;
    tmp=a;
    tmpa=a->location;
    tmpb=b->location;
    a=b;
    a->location=tmpa;
    b=tmp;
    b->location=tmpb;
}

void CandyCrush::select(){
    static int record;
    if(selected){
        for(int i=0;i<SIDE*SIDE;i++){
            if(board[i]->isChecked() && record!=i){
                if(record-i==1 || record-i==-1 || record-i==SIDE || record-i==-SIDE){
                    move(record,i);
                    swap(board[i],board[record]);
                    printf("i=%d,loc=%d<->record=%d,loc%d\n",i,board[i]->location,record,board[record]->location);
                    selected=false;
                    board[i]->setChecked(false);
                    board[record]->setChecked(false);
//                    int itmp;
//                    itmp=numboard[i];
//                    numboard[i]=numboard[record];
//                    numboard[record]=itmp;
                    if(kill()){
//                        sleep(2000);
                        down();
                        fill();
//                        sleep(2000);
                        while(kill()){
//                            sleep(2000);
                            down();
//                            sleep(2000);
                            fill();
//                            sleep(2000);
                            update();
                        }
                    }else{
                        sleep(20);
                        move(record,i);
                        swap(board[i],board[record]);
//                        itmp=numboard[i];
//                        numboard[i]=numboard[record];
//                        numboard[record]=itmp;
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
    update();
}

void CandyCrush::fill(){
    for(int i=0;i<SIDE*SIDE;i++){
        if(board[i]==NULL){
            board[i]=genStone(i,this);
            connect(board[i]->but,SIGNAL(clicked()),this,SLOT(select()));
            printf("%d==NULL->%d\n",i,board[i]);
        }
    }
    update();
}

void CandyCrush::newboard(){
    for(int i=0;i<SIDE*SIDE;i++){
        board[i]->but->disconnect();
        delete board[i];
        board[i]=genStone(i,this);
        connect(board[i]->but,SIGNAL(clicked()),this,SLOT(select()));
    }
    while(kill()){
        fill();
    }
}

bool CandyCrush::kill(){
    bool tokill[SIDE*SIDE]={false};
    bool need=false;
    for(int i=0;i<SIDE-2;i++){
        for(int j=0;j<SIDE;j++){
            if(board[i*SIDE+j]->type()==board[(i+1)*SIDE+j]->type() && board[i*SIDE+j]->type()==board[(i+2)*SIDE+j]->type()){
                tokill[i*SIDE+j]=true;
                tokill[(i+1)*SIDE+j]=true;
                tokill[(i+2)*SIDE+j]=true;
                need=true;
            }
        }
    }
    for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE-2;j++){
            if(board[i*SIDE+j]->type()==board[i*SIDE+j+1]->type() && board[i*SIDE+j]->type()==board[i*SIDE+j+2]->type()){
                tokill[i*SIDE+j]=true;
                tokill[i*SIDE+j+1]=true;
                tokill[i*SIDE+j+2]=true;
                need=true;
            }
        }
    }
    for(int i=0;i<SIDE*SIDE;i++){
        if(tokill[i]){
            board[i]->but->disconnect();
            delete board[i];
            board[i]=NULL;
        }
    }
    update();
    return need;
}

CandyCrush::~CandyCrush()
{
    delete ui;
}

void CandyCrush::update(){
    for(int i=0;i<SIDE*SIDE;i++){
        if(board[i]!=NULL){
            board[i]->loadpic();
        }
//        std::printf("%d\n",i);
//        char tmp[10];
//        std::sprintf(tmp,"%d",numboard[i]);
//        board[i]->setText(tmp);
//        board[i]->setCheckable(true);
    }
//    for(int i=0;i<SIDE*SIDE;i++){
//        std::printf("%02d ",board[i]->type());
//        if(i==SIDE*SIDE-1){
//            std::puts("");
//        }
//        if((i+1)%SIDE==0){
//            std::puts("");
//        }
//    }
}

void CandyCrush::on_pushButton_clicked()
{
    newboard();
    update();
}
