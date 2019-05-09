#include "mainwindow.h"
#include "ui_mainwindow.h"

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

Ui::MainWindow *operator<<(Ui::MainWindow *ui, MySet const &a)
{
    QString str;
    if(ui->tableWidget->rowCount() <= 0)
    {
        ui->tableWidget->insertRow(0);
    }
    for (int i = 0; i < a.findP(); i++)
    {
        if(ui->tableWidget->columnCount() <= i)
        {
            ui->tableWidget->insertColumn(i);
        }
        str = QString::number(a.getElems()[i]);
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(str));
    }

    return ui;
}

Ui::MainWindow *operator>>(Ui::MainWindow *ui, MySet &a)
{
    for (int i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(0, i);
        if(item)
        {
            a.addElem(item->text().toInt());
        }
    }
    return ui;
}


void MainWindow::on_clearGrid_clicked()
{
    ui->tableWidget->clear();
    for(int i = ui->tableWidget->columnCount(); i > 0; i--)
    {
        ui->tableWidget->removeColumn(i);
    }
}

void MainWindow::on_enterElemsBtn_clicked()
{
    ui>>a;

}

void MainWindow::on_ShowElemsBtn_clicked()
{
    ui<<a;

}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(column == ui->tableWidget->columnCount() - 1)
    {
        ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
    }
}
