#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
QImage img(400, 400, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float dx, dy, l;
    float xinc, yinc;
    float x, y;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy)){
        l = abs(dx);
    }else{
        l = abs(dy);
    }
    xinc = dx/l;
    yinc = dy/l;
    x = x1;
    y = y1;
    for(int i=0; i<l; i++){
        img.setPixel(x,y,qRgb(255, 255, 255));
        x += xinc;
        y += yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda2(float x1, float y1, float x2, float y2)
{
    float dx, dy, l;
    float xinc, yinc;
    float x, y;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy)){
        l = abs(dx);
    }else{
        l = abs(dy);
    }
    xinc = dx/l;
    yinc = dy/l;
    x = x1;
    y = y1;
    for(int i=0; i<l; i++){
        img.setPixel(x,y,qRgb(0, 255, 0));
        x += xinc;
        y += yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::Window()
{
    dda(200, 0, 200, 400);
    dda(0, 200, 400, 200);
}

void MainWindow::Rhombus(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    dda2(x1+200, y1+200, x2+200, y2+200);
    dda2(x2+200, y2+200, x3+200, y3+200);
    dda2(x3+200, y3+200, x4+200, y4+200);
    dda2(x4+200, y4+200, x1+200, y1+200);
}

void MainWindow::on_pushButton_clicked()
{
    float tx, ty;
    tx = ui->textEdit->toPlainText().toFloat();
    ty = ui->textEdit_2->toPlainText().toFloat();

    X1 = X1+tx;
    Y1 = Y1-ty;
    X2 = X2+tx;
    Y2 = Y2-ty;
    X3 = X3+tx;
    Y3 = Y3-ty;
    X4 = X4+tx;
    Y4 = Y4-ty;
    Rhombus(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
}

void MainWindow::on_pushButton_4_clicked()
{
    Window();

    X1 = ui->textEdit_6->toPlainText().toFloat();
    Y1 = ui->textEdit_9->toPlainText().toFloat();
    X2 = ui->textEdit_7->toPlainText().toFloat();
    Y2 = ui->textEdit_10->toPlainText().toFloat();
    X3 = ui->textEdit_8->toPlainText().toFloat();
    Y3 = ui->textEdit_11->toPlainText().toFloat();
    X4 = ui->textEdit_12->toPlainText().toFloat();
    Y4 = ui->textEdit_13->toPlainText().toFloat();

    Rhombus(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
}

void MainWindow::on_pushButton_3_clicked()
{
    float sx, sy;
    sx = ui->textEdit_4->toPlainText().toFloat();
    sy = ui->textEdit_5->toPlainText().toFloat();

    X1 = X1*sx;
    Y1 = Y1*sy;
    X2 = X2*sx;
    Y2 = Y2*sy;
    X3 = X3*sx;
    Y3 = Y3*sy;
    X4 = X4*sx;
    Y4 = Y4*sy;
    Rhombus(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
}

void MainWindow::on_pushButton_2_clicked()
{
    float angle, requiredAngle;
    angle = ui->textEdit_3->toPlainText().toFloat();
    requiredAngle = (0.0174533*angle);

    float x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = -Y1*sin(requiredAngle)+X1*cos(requiredAngle);
    y1 = X1*sin(requiredAngle)+Y1*cos(requiredAngle);
    x2 = -Y2*sin(requiredAngle)+X2*cos(requiredAngle);
    y2 = X2*sin(requiredAngle)+Y2*cos(requiredAngle);
    x3 = -Y3*sin(requiredAngle)+X3*cos(requiredAngle);
    y3 = X3*sin(requiredAngle)+Y3*cos(requiredAngle);
    x4 = -Y4*sin(requiredAngle)+X4*cos(requiredAngle);
    y4 = X4*sin(requiredAngle)+Y4*cos(requiredAngle);

    X1 = x1;
    X2 = x2;
    X3 = x3;
    Y1 = y1;
    Y2 = y2;
    Y3 = y3;
    X4 = x4;
    Y4 = y4;

    Rhombus(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
}
