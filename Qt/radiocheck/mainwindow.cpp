#include "mainwindow.h"
#include "./ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    QString txt="";
    if(ui->rd_boy->isChecked()==1){
        txt="Giới tính của bạn là nam";
    }
    else if(ui->rd_girl->isChecked()==1){
        txt="Giới tính của bạn là nữ";
    }
    ui->lb_gender->setText(txt);
}

