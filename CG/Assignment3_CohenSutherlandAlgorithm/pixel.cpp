#include "pixel.h"
#include "ui_pixel.h"
#include <bits/stdc++.h>
QImage img(500,500,QImage::Format_RGB888); // 0 to 255
Pixel::Pixel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pixel)
{
    ui->setupUi(this);
}

Pixel::~Pixel()
{
    delete ui;
}


void Pixel::on_pushButton_clicked()
{
    int xbottom,ybottom,xtop,ytop,x1,y1,x2,y2;
    xbottom=ui->textEdit->toPlainText().toInt();
    ybottom=ui->textEdit_2->toPlainText().toInt();
    xtop=ui->textEdit_3->toPlainText().toInt();
    ytop=ui->textEdit_4->toPlainText().toInt();
    x1=ui->textEdit_5->toPlainText().toInt();
    y1=ui->textEdit_6->toPlainText().toInt();
    x2=ui->textEdit_7->toPlainText().toInt();
    y2=ui->textEdit_8->toPlainText().toInt();
    window(xbottom,ybottom,xtop,ytop,x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void Pixel::DDA(int x1, int y1, int x2, int y2)
{
    float dx,dy,length,xinc,yinc,x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>=abs(dy))
        length = abs(dx);
    else
        length = abs(dy);
    xinc = dx/length;
    yinc = dy/length;
    int i=0;
    x=x1,y=y1;
    while(i<length){
        img.setPixel(int(x),int(y),qRgb(0,255,0));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void Pixel::window(int xbottom,int ybottom,int xtop,int ytop,int x1,int y1,int x2,int y2)
{
    DDA(xbottom,ybottom,xtop,ybottom);
    DDA(xtop,ybottom,xtop,ytop);
    DDA(xtop,ytop,xbottom,ytop);
    DDA(xbottom,ytop,xbottom,ybottom);
    DDA(x1,y1,x2,y2);
}


void Pixel::clear()
{
    for(int i=0;i<500;i++){
        DDA2(0,i,500,i);
    }
}

void Pixel::DDA2(int x1, int y1, int x2, int y2)
{
    float dx,dy,length,xinc,yinc,x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>=abs(dy))
        length = abs(dx);
    else
        length = abs(dy);
    xinc = dx/length;
    yinc = dy/length;
    int i=0;
    x=x1,y=y1;
    while(i<length){
        img.setPixel(int(x),int(y),qRgb(0,0,0));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void Pixel::clipping(float xbottom, float ybottom, float xtop, float ytop, float x1, float y1, float x2, float y2)
{
    int a[4]; // for x1 and y1
    int b[4]; // for x2 and y2

    a[0] = (y1>ytop) ? 0 : 1;
    a[1] = (y1<ybottom) ? 1 : 0;
    a[2] = (x1>xtop) ? 0 : 1;
    a[3] = (x1<xbottom) ? 1 : 0;

    b[0] = (y2>ytop) ? 1 : 0;
    b[1] = (y2<ybottom) ? 0 : 1;
    b[2] = (x2>xtop) ? 1 : 0;
    b[3] = (x2<xbottom) ? 0 : 1;

    int flag = 0;
    if((a[0]&b[0])&&(a[1]&b[1])&&(a[2]&b[2])&&(a[3]&b[3])){
        flag = 1;
    }
    DDA3(xbottom,ybottom,xtop,ybottom);
    DDA3(xtop,ybottom,xtop,ytop);
    DDA3(xtop,ytop,xbottom,ytop);
    DDA3(xbottom,ytop,xbottom,ybottom);
    float slope = (y2-y1)/(x2-x1);
    if(x1>=xbottom&&x1<=xtop){
        if(y1<ybottom){
            float temp = y1;
            y1 = ybottom;
            // y = mx + c
            // y1 = mx1 + c
            // c = y1 - mx1
            // y = mx + y1 - mx1
            // y2 = mx2 + y1 - m x1
            // x2 = y2 - y1 + mx1/m
            x1 = (y1 - temp + (slope*x1))/slope;
        }
        else if(y1>=ybottom&&y1<=ytop){

        }
        else{
            x1 = 0;
            y1 = 0;
            x2 = 0;
            y2 = 0;
        }
    }
    if(x2>=xbottom&&x1<=xtop){
        if(y2<ybottom){
            x1 = 0;
            y1 = 0;
            x2 = 0;
            y2 = 0;
        }
        else if(y2>=ybottom&&y2<=ytop){

        }
        else{
            float temp = y2;
            y2 = ytop;
            // y = mx + c
            // y1 = mx1 + c
            // c = y1 - mx1
            // y = mx + y1 - mx1
            // y2 = mx2 + y1 - m x1
            // x2 = y2 - y1 + mx1/m
            x2 = (y2 - temp + (slope*x2))/slope;
        }
    }
    if(x1>xtop){
        x1=0;
        y1=0;
        x2=0;
        y2=0;
    }
    if(x1<xbottom){
        if(y1>ytop){
            x1=0;
            y1=0;
            x2=0;
            y2=0;
        }
        else if(y1>=ybottom&&y1<=ytop){
            // y = mx+c
            // y1 = mx1 + c
            // c = y1-mx1
            // y = mx + y1-mx1
            // y2 = mx2 + y1 - mx1
            float temp = x1;
            x1 = xbottom;
            y1 = (slope*x1) + y1 - (slope*temp);
        }
        else if(y1<ybottom){
            float temp = y1;
            y1 = ybottom;
            x1 = (y1 - temp + (slope*x1))/slope;
        }
    }
    if(x2<xbottom){
        x1=0;
        y1=0;
        x2=0;
        y2=0;
    }
    if(x2>xtop){
        if(y2<ybottom){
            x1 = 0;
            x2 = 0;
            y1 = 0;
            y2 = 0;
        }
        else if(y2>=ybottom&&y2<=ytop){
            // y = mx+c
            // y1 = mx1 + c
            // c = y1-mx1
            // y = mx + y1-mx1
            // y2 = mx2 + y1 - mx1
            float temp = x2;
            x2 = xtop;
            y2 = (slope*x2) + y2 - (slope*temp);
        }
        else if(y2>ytop){
            float temp = y2;
            y2 = ytop;
            x2 = (y2 - temp + (slope*x2))/slope;
        }
    }
    if(x1==x2&&y1<ytop&&y2>y1){
        if(y2>ytop) y2 = ytop;
        if(y1<ybottom) y1 = ybottom;
    }
    if(y1==y2&&x1<=xbottom){
        if(x2>=xtop){
            x1 = xbottom;
            x2 = xtop;
        }
    }
    if(flag==1){
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
    }
    DDA3(x1,y1,x2,y2);
    ui->label_11->setPixmap(QPixmap::fromImage(img));
}

void Pixel::on_pushButton_3_clicked()
{
    int xbottom,ybottom,xtop,ytop,x1,y1,x2,y2;
    xbottom=ui->textEdit->toPlainText().toInt();
    ybottom=ui->textEdit_2->toPlainText().toInt();
    xtop=ui->textEdit_3->toPlainText().toInt();
    ytop=ui->textEdit_4->toPlainText().toInt();
    x1=ui->textEdit_5->toPlainText().toInt();
    y1=ui->textEdit_6->toPlainText().toInt();
    x2=ui->textEdit_7->toPlainText().toInt();
    y2=ui->textEdit_8->toPlainText().toInt();
    clear();
    clipping(xbottom,ybottom,xtop,ytop,x1,y1,x2,y2);
    ui->label_11->setPixmap(QPixmap::fromImage(img));
}

void Pixel::DDA3(float x1, float y1, float x2, float y2)
{

    float dx,dy,length,xinc,yinc,x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>=abs(dy))
        length = abs(dx);
    else
        length = abs(dy);
    xinc = dx/length;
    yinc = dy/length;
    int i=0;
    x=x1,y=y1;
    while(i<length){
        img.setPixel(x,y,qRgb(255,0,0));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}
