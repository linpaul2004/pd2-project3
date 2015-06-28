#include "candycrush.h"
#include "ui_candycrush.h"

CandyCrush::CandyCrush(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CandyCrush),selected(false)
{
    ui->setupUi(this);
    ui->STAR->setScaledContents(true);
    over= new Over(this);
    connect(this,SIGNAL(toOver(bool,int,int)),over,SLOT(construct(bool,int,int)));
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
//    for(int i=0;i<SIDE*SIDE;i++){
//        printf("%d->%d\n",i,board[i]);
//    }
    score.setScore(0);
    update();
}

void CandyCrush::move(int from,int to){
    static QPropertyAnimation move[2];
    move[0].setPropertyName("geometry");
    move[0].setTargetObject(board[from]->but);
    move[0].setDuration(200);
    move[0].setStartValue(QRect(MARGIN+(from%SIDE)*SIZE,MARGIN+(from/SIDE)*SIZE,SIZE,SIZE));
    move[0].setEndValue(QRect(MARGIN+(to%SIDE)*SIZE,MARGIN+(to/SIDE)*SIZE,SIZE,SIZE));
    move[1].setPropertyName("geometry");
    move[1].setTargetObject(board[to]->but);
    move[1].setDuration(200);
    move[1].setStartValue(QRect(MARGIN+(to%SIDE)*SIZE,MARGIN+(to/SIDE)*SIZE,SIZE,SIZE));
    move[1].setEndValue(QRect(MARGIN+(from%SIDE)*SIZE,MARGIN+(from/SIDE)*SIZE,SIZE,SIZE));
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
                    ui->step->display(ui->step->intValue()-1);
                    move(record,i);
                    swap(board[i],board[record]);
//                    printf("i=%d,loc=%d<->record=%d,loc%d\n",i,board[i]->location,record,board[record]->location);
                    selected=false;
                    board[i]->setChecked(false);
                    board[record]->setChecked(false);
//                    int itmp;
//                    itmp=numboard[i];
//                    numboard[i]=numboard[record];
//                    numboard[record]=itmp;
                    if(kill()){
                        sleep(300);
                        down();
                        fill();
                        sleep(300);
                        while(kill()){
                            sleep(300);
                            down();
                            sleep(300);
                            fill();
                            sleep(300);
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
//    update();
}

void CandyCrush::fill(){
    for(int i=0;i<SIDE*SIDE;i++){
        if(board[i]==NULL){
            board[i]=genStone(i,this);
            connect(board[i]->but,SIGNAL(clicked()),this,SLOT(select()));
//            printf("%d==NULL->%d\n",i,board[i]);
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
    score.setScore(0);
}

//void CandyCrush::specreat(bool *m){
//    fill();
//    bool my[SIDE*SIDE];
//    for(int i=0;i<SIDE*SIDE;i++){
//        my[i]=m[i];
//    }
//    int kill=0;
//    for(int i=0;i<SIDE*SIDE-SIDE*3;i++){
//        kill=0;
//        if(my[i]){
//            my[i]=false;
//            kill++;
//            while(1){
//                if(my[i+SIDE]){
//                    my[i+SIDE]=false;
//                    kill++;
//                }else{
//                    if(kill>=4){
//                        int type=board[i]->type();
//                        if(board[i]!=NULL){
//                            delete board[i];
//                        }
//                        board[i]=genStone(i,this,type);
//                        connect(board[i]->but,SIGNAL(clicked()),this,SLOT(select()));
//                        board[i]->special=VER;
//                        m[i]=false;
//                    }
//                    break;
//                }
//                if(i+SIDE>=SIDE*SIDE){
//                    break;
//                }else{
//                    i+=SIDE;
//                }
//            }
//        }
//    }
//}

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
//    specreat(tokill);
    for(int i=0;i<SIDE*SIDE;i++){
        if(tokill[i]){
            board[i]->but->disconnect();
            delete board[i];
            board[i]=NULL;
        }
    }
    score+=tokill;
//    update();
    return need;
}

//void CandyCrush::killver(int j){
//    for(int i=0;i<SIDE;i++){
//        if(board[i*SIDE+j%SIDE]!=NULL){
//            printf("%d->type=%d\n",i*SIDE+j%SIDE,board[i*SIDE]->type());
//            board[i*SIDE+j%SIDE]->but->disconnect();
//            delete board[i*SIDE+j%SIDE];
//            board[i*SIDE+j%SIDE]=NULL;
//        }
//    }
//}

CandyCrush::~CandyCrush()
{
    delete ui;
    for(int i=0;i<SIDE*SIDE;i++){
        if(board[i]!=NULL){
            delete board[i];
        }
    }
    delete over;
    emit quit(score.getStar(),score.getScore());
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
    ui->num->display(score.getScore());
    char tmp[25];
    std::sprintf(tmp,":/icon/star%d.png",score.getStar());
    QPixmap b(tmp);
    ui->STAR->setPixmap(b);
    if(ui->step->intValue()==0){
        if(ui->num->intValue()<200){
            emit toOver(false,score.getStar(),score.getScore());
            emit quit(score.getStar(),score.getScore());
        }else{
            emit toOver(true,score.getStar(),score.getScore());
            emit quit(score.getStar(),score.getScore());
        }
        over->setModal(true);
        over->exec();
        on_pushButton_clicked();
    }
}

void CandyCrush::on_pushButton_clicked()
{
    ui->step->display(20);
    score.setScore(0);
    newboard();
    update();
}
