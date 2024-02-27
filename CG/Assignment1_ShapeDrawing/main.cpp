#include "pixel_2.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pixel_2 w;
    w.show();
    QLabel *label = new QLabel("<h1><i><font color = red>hello !!</i></h1>");
    label->show();

    return a.exec();
}
