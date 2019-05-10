#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "comulativedeposite.h"
#include "timeddeposite.h"
#include "vipdeposite.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartBtn_clicked()
{
    switch (ui->depositeSelect->currentIndex())
    {
    case 0:
        deposite = new TimedDeposite;
        break;
    case 1:
        deposite = new ComulativeDeposite;
        break;
    case 2:
        deposite = new VIPDeposite;
        break;
    }

    deposite->startDeposite(ui->dSpinMoney->value(), ui->spinMonths->value(), ui->dSpinPercents->value());
}

void MainWindow::on_calculateBtn_clicked()
{
    double income = deposite->calculateIncome(ui->spinDays->value());
    ui->incomeLabel->setText(QString::number(income));
}

void MainWindow::on_takeMoneyBtn_clicked()
{
    double money = deposite->takeMoneyNow(ui->spinDays->value());
    ui->incomeLabel->setText(QString::number(money));
}

void MainWindow::on_addMoneyBtn_clicked()
{
    deposite->addMoney(ui->dSpinMoneyToAdd->value());
}
