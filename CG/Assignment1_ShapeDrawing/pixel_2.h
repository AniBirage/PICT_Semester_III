#ifndef PIXEL_2_H
#define PIXEL_2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class pixel_2; }
QT_END_NAMESPACE

class pixel_2 : public QMainWindow
{
    Q_OBJECT

public:
    pixel_2(QWidget *parent = nullptr);
    ~pixel_2();

private slots:
    void on_pushButton_clicked();

    void on_x1_input_copyAvailable(bool b);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::pixel_2 *ui;
};
#endif // PIXEL_2_H
