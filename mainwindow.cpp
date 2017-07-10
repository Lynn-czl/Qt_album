#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->image=new QImage();
    this->effect=new QGraphicsBlurEffect();
    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(on_slotFade_on_fade_out_triggered()));
    this->first_pic();
    auto_timer = new QTimer();
    connect(auto_timer, SIGNAL(timeout()), this, SLOT(on_slotAutoplay_triggerd()));
    auto_timer->start(WAITTIME);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->mainToolBar->setHidden(true);
    ui->menuBar->setHidden(true);
    ui->statusBar->setHidden(true);

}

MainWindow::~MainWindow()
{
    delete image;
    delete effect;
    delete ui;
}

void MainWindow::on_slotFade_on_fade_out_triggered()
{
    {
        effect->setBlurRadius(blur);
        ui->label->setGraphicsEffect(effect);

    }
    blur+=1;
}



void MainWindow::first_pic()
{
    QStringList filter;
    filter<<"*.jpg"<<"*.png"<<"*.jpeg"<<"*.gif"<<"*.bmp";
    QFileInfoList infolist;
    QDir dir("/home/czl/图片/");
    infolist=dir.entryInfoList(filter);
    if(infolist.count()==0)
    {
        ui->label->setText("NO PICTURE TO SHOW !");
        ui->label->setAlignment(Qt::AlignCenter);
        return;
    }
    QFileInfo info= infolist.at(0);
    if(info.isFile())
    {

         QString absolute_file_path=info.absoluteFilePath();
         if(absolute_file_path!="")
                {

                        if(image->load(absolute_file_path))
                    {
                            if(absolute_file_path.endsWith(".gif"))
                            {
                                  QMovie *movie=new QMovie(absolute_file_path);
                                  ui->label->setMovie(movie);
                                  movie->start();
                            }
                            else
                            {
                                QPixmap pix;
                                pix.load(absolute_file_path);
                                pix=pix.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
                                ui->label->setPixmap(pix);//QPixmap(absolute_file_path)
                                ui->label->setAlignment(Qt::AlignCenter);
                            }

//                          ui->label->setAttribute(Qt::WA_TranslucentBackground,true);
//                          ui->label->resize(image->width()+10,image->height()+10);

                    }
                }

            }
}


void MainWindow::on_slotAutoplay_triggerd()
{

    blur=0.0;
    timer->start(800);
    QStringList filter;
    filter<<"*.jpg"<<"*.png"<<"*.jpeg"<<"*.gif"<<"*.bmp";
    QFileInfoList infolist;
    QDir dir("/home/czl/图片/");
    infolist=dir.entryInfoList(filter);
    if(infolist.count()==0)
    {
        ui->label->setText("NO PICTURE TO SHOW !");
        ui->label->setAlignment(Qt::AlignCenter);
        return;
    }
    if(i<infolist.count())
    {

        QFileInfo info= infolist.at(i);
        if(info.isFile())
        {

                QString absolute_file_path=info.absoluteFilePath();
                if(absolute_file_path!="")
                {
                        if(image->load(absolute_file_path))
                    {

                            if(absolute_file_path.endsWith(".gif"))
                            {
                                  QMovie *movie=new QMovie(absolute_file_path);
                                  ui->label->setMovie(movie);
                                  movie->start();
                            }
                            else
                            {
                                QPixmap pix;
                                pix.load(absolute_file_path);
                                pix=pix.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
                                ui->label->setPixmap(pix);//QPixmap(absolute_file_path)
                                ui->label->setAlignment(Qt::AlignCenter);
                            }

                    }
                }

            }
            i++;

    }
    else if(i>=infolist.count()-1)
    {
        i=0;
    }



}




