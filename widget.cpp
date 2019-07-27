#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbcoffee1->setEnabled(false);
    ui->pbtee2->setEnabled(false);
    ui->pbgongha3->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));

    if(money < 100 ){
        ui->pbcoffee1->setEnabled(false);
    }else {
        ui->pbcoffee1->setEnabled(true);
    }if(money < 150 ) {
        ui->pbtee2->setEnabled(false);
    }else {
        ui->pbtee2->setEnabled(true);
    }if(money < 200 ) {
        ui->pbgongha3->setEnabled(false);
    }else{
        ui->pbgongha3->setEnabled(true);
    }
    //ui->pbcoffee1->setEnabled(false);
    //QMessageBox msg;
    //msg.information(nullptr, "title", "10");

}

void Widget::on_pb10_clicked()
{

    changeMoney(10);

}

void Widget::on_pb50_clicked()
{
    changeMoney(50);

}


void Widget::on_pb100_clicked()
{
    changeMoney(100);

}


void Widget::on_pb500_clicked()
{
    changeMoney(500);

}

void Widget::on_pbcoffee1_clicked()
{

    changeMoney(-100);

}

void Widget::on_pbtee2_clicked()
{
    changeMoney(-150);

}

void Widget::on_pbgongha3_clicked()
{
    changeMoney(-200);
}

void Widget::on_rtnBtn_clicked()
{

    int pb4 = money/500;
    int pb3 = (money%500)/100;
    int pb2 = ((money%500)%100)/50;
    int pb1 = (((money%500)%100)%50)/10;
    //%1~ 문자열치환
    QString rtnwon = QString("return\n 500 : %1 \n 100 : %2 \n 50 : %3 \n 10 : %4").arg(pb4).arg(pb3).arg(pb2).arg(pb1);
    QMessageBox msg;
    msg.information(nullptr, "kyeDrink!", rtnwon);
    money = 0;
    ui->lcdNumber->display(QString::number(money));
    ui->pbcoffee1->setEnabled(false);
    ui->pbtee2->setEnabled(false);
    ui->pbgongha3->setEnabled(false);

}
