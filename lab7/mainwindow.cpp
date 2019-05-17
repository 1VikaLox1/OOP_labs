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

Ui::MainWindow *operator<<(Ui::MainWindow *ui, MySet const &set)
{
    QString str;

    for (int i = 0; i < set.findP(); i++)
    {
        str = QString::number(set.getElems()[i]);
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(str));
    }

    return ui;
}

Ui::MainWindow *operator>>(Ui::MainWindow *ui, MySet &set)
{
    for (int i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(0, i);
        if(item)
        {
            set.addElem(item->text().toInt());
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

    for(int i = ui->tableWidget->rowCount(); i > 0; i--)
    {
        ui->tableWidget->removeRow(i);
    }
}

void MainWindow::on_enterElemsBtn_clicked()
{
    ui>>setA;

}

void MainWindow::on_ShowElemsBtn_clicked()
{
    on_clearGrid_clicked();
    ui<<setA;

}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(column == ui->tableWidget->columnCount() - 1)
    {
        ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
    }
}

void MainWindow::on_ShowMEMOBtn_clicked()
{
    QString str;
    for(int i = 0; i < setA.findP(); i++)
    {
        str += QString::number(setA.getElems()[i]) + ", ";
    }
    ui->plainTextEdit->setPlainText(str);
}

void MainWindow::on_EnterMEMOBtn_clicked()
{
    QString str = ui->plainTextEdit->toPlainText();
    QStringList elemsList = str.split(",");
    for(int i = 0; i < elemsList.length(); i++)
    {
        if(elemsList[i] != ' ' && elemsList[i] != "")
        {
            setA.addElem(elemsList[i].toInt());
        }
    }
}

void MainWindow::on_ClearSetBtn_clicked()
{
    setA.clear();
}

void MainWindow::on_findMaxBtn_clicked()
{
    on_clearGrid_clicked();
    QString str;
    str = QString::number(setA.findMax());
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(str));
}

void MainWindow::on_findMinBtn_clicked()
{
    on_clearGrid_clicked();
    QString str;
    str = QString::number(setA.findMin());
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(str));
}

void MainWindow::on_findPBtn_clicked()
{
    on_clearGrid_clicked();
    QString str;
    str = QString::number(setA.findP());
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(str));
}


void MainWindow::on_plusBtn_clicked()
{
    MySet setB;
    ui >> setB;
    on_EnterMEMOBtn_clicked();
    MySet c = (setA + setB);

    QString str;
    ui->tableWidget->insertRow(1);
    for (int i = 0; i < c.findP(); i++)
    {
        str = QString::number(c.getElems()[i]);
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(str));
    }
}

void MainWindow::on_minusBtn_clicked()
{
    MySet setB;
    ui >> setB;
    on_EnterMEMOBtn_clicked();
    MySet c = (setA - setB);

    QString str;
    ui->tableWidget->insertRow(1);
    for (int i = 0; i < c.findP(); i++)
    {
        str = QString::number(c.getElems()[i]);
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(str));
    }
}

void MainWindow::on_dvideBtn_clicked()
{
    MySet setB;
    ui >> setB;
    on_EnterMEMOBtn_clicked();
    MySet c = (setA / setB);

    QString str;
    ui->tableWidget->insertRow(1);
    for (int i = 0; i < c.findP(); i++)
    {
        str = QString::number(c.getElems()[i]);
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(str));
    }
}
