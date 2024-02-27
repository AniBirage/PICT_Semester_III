#ifndef PIXEL_H
#define PIXEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Pixel; }
QT_END_NAMESPACE

class Pixel : public QMainWindow
{
    Q_OBJECT

public:
    Pixel(QWidget *parent = nullptr);
    ~Pixel();

private slots:
    void on_pushButton_clicked();
    void DDA(int,int,int,int);
    void window(int,int,int,int,int,int,int,int);
    void clear();
    void DDA2(int,int,int,int);
    void clipping(float,float,float,float,float,float,float,float);
    void on_pushButton_3_clicked();
    void DDA3(float,float,float,float);

private:
    Ui::Pixel *ui;
};
#endif // PIXEL_H
