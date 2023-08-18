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


void MainWindow::on_btn_ok_clicked()
{
    QString txt="";
    txt += ui->Edit->toPlainText()+",add:";
    if(ui->cb_option_1->isChecked()==1){
        txt+="Trân châu";
    }
    if(ui->cb_option_2->isChecked())
        txt+="Thạch phô mai";
    ui->lb_food->setText(txt);
}


