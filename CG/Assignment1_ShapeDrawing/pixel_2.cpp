#include "pixel_2.h"
#include "ui_pixel_2.h"
#include <QImage>
#include <cstdlib>
#include<math.h>
QImage img(400,400,QImage::Format_RGB888);

void DDA_func(float x1_ , float y1_ , float x2_ , float y2_){
    img.setPixel(x1_,y1_,qRgb(255,255,255));
    float dx ,dy , x ,y  ;
    float steps,xinc, yinc ;
    dx = x2_ - x1_ ;
    dy = y2_ - y1_ ;
    if (abs(dx)>abs(dy)){
        steps = abs(dx);
    }
    else {
        steps = abs(dy);
    }
    xinc = dx / steps ;
    yinc = dy / steps ;
    x = x1_;
    y = y1_;
    for ( int i = 0 ; i < steps ; i ++){
        x += xinc;
        y += yinc;
        img.setPixel(x,y,qRgb(255,255,255));

    }

}

void bress_circle(float cx,float cy,float r){
    float x,y,d;
    x = 0;
    y = r ;
    d = 3-(2*r);
    while(y>=x){
        img.setPixel(cx + x,cy + y,qRgb(255,255,255));
        img.setPixel(cx - x,cy + y,qRgb(255,255,255));
        img.setPixel(cx + x,cy - y,qRgb(255,255,255));
        img.setPixel(cx - x,cy - y,qRgb(255,255,255));
        img.setPixel(cx + y,cy + x,qRgb(255,255,255));
        img.setPixel(cx - y,cy + x,qRgb(255,255,255));
        img.setPixel(cx + y,cy - x,qRgb(255,255,255));
        img.setPixel(cx - y,cy - x,qRgb(255,255,255));

        x += 1;
        if (d<0){
            d += 4 * x + 6;
        }
        else {
            y -= 1;
            d += 4 *( x - y ) + 6;
        }
    }
}

void midpoint_circle(float cx,float cy,float r){
    float x,y,d;
    x = 0;
    y = r;
    d = 1.25-r;
    while (y>=x){
        img.setPixel(cx + x, cy + y,qRgb(255,255,255));
        img.setPixel(cx - x, cy + y,qRgb(255,255,255));
        img.setPixel(cx + x, cy - y,qRgb(255,255,255));
        img.setPixel(cx - x, cy - y,qRgb(255,255,255));
        img.setPixel(cx + y, cy + x,qRgb(255,255,255));
        img.setPixel(cx + y, cy - x,qRgb(255,255,255));
        img.setPixel(cx - y, cy + x,qRgb(255,255,255));
        img.setPixel(cx - y, cy - x,qRgb(255,255,255));
        if (d<0){
            d += (2*x) + 1;
            x += 1;

        }
        else{
            x += 1;
            y -= 1;
            d += (2*x) - (2*y) + 1;
        }
    }
}


pixel_2::pixel_2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pixel_2)
{
    ui->setupUi(this);
}

pixel_2::~pixel_2()
{
    delete ui;
}


void pixel_2::on_x1_input_copyAvailable(bool b)
{

}


void pixel_2::on_pushButton_clicked()
{
    float x1 , y1, l ,b ;
    x1 = ui->x1_input->toPlainText().toFloat();
    y1 = ui->y1_input->toPlainText().toFloat();
    l = ui->x2_input->toPlainText().toFloat();
    b = ui->y2_input->toPlainText().toFloat();
    DDA_func(x1,y1,x1 + b,y1);
    DDA_func(x1,y1,x1,y1+l);
    DDA_func(x1+ b,y1,x1+b,y1+l);
    DDA_func(x1,y1+l,x1+b,y1+l);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void pixel_2::on_pushButton_2_clicked()
{
    float x1 , y1, l ,b ;
    x1 = ui->x1_input->toPlainText().toFloat();
    y1 = ui->y1_input->toPlainText().toFloat();
    l = ui->x2_input->toPlainText().toFloat();
    b = ui->y2_input->toPlainText().toFloat();
    DDA_func(x1,y1 + (l/2),x1+(b/2),y1);
    DDA_func(x1,y1+(l/2),x1+(b/2),y1+l);
    DDA_func(x1+(b/2),y1,x1+b,y1+(l/2));
    DDA_func(x1+(b/2),y1+l,x1+b,y1+(l/2));
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void pixel_2::on_pushButton_3_clicked()
{
    float x1 , y1, l ,b ;
    x1 = ui->x1_input->toPlainText().toFloat();
    y1 = ui->y1_input->toPlainText().toFloat();
    l = ui->x2_input->toPlainText().toFloat();
    b = ui->y2_input->toPlainText().toFloat();
    float cx_ , cy_, r_ ;
    cx_ = x1 + (b/2);
    cy_ = y1 + (l/2);
    r_ = sqrt((l*l) + (b*b))/4;
    midpoint_circle(cx_ ,cy_ ,r_);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
