#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QCoreApplication>
#include <QMainWindow>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QFileInfoList>
#include <QGraphicsEffect>
#include <QGraphicsBlurEffect>
#include <QGraphicsItem>
#include <QMovie>
#include <QPixmap>
#define WAITTIME 6000
//#define count 0

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void first_pic();

private slots:



    void on_slotAutoplay_triggerd();
void on_slotFade_on_fade_out_triggered();



private:
    Ui::MainWindow *ui;
    QImage *image;
    QTimer *auto_timer;
    QTimer *timer;
    QGraphicsBlurEffect *effect;

    int i=1;
    float blur=0.0;

   // QList<QString>::Iterator it,itend;

};

#endif // MAINWINDOW_H
