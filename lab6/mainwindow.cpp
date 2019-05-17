
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label_8->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateBtn_clicked()
{
    if(a())
    {
        ui << a;
    }
    else
    {
        ui->X2->setText("Розвязків немає");
    }
    //ui->X1->setText(QString::number(a.))
}

void MainWindow::on_enterBtn_clicked()
{
    ui >> a;
}

void MainWindow::on_curriedFuncBtn_clicked()
{
    ui->curriedFunc->setText(QString::number(2 * a.getA()));
    ui->label_8->setVisible(true);
    ui->label_9->setText(QString::number(a.getB()));
}

void MainWindow::on_enterBtn_2_clicked()
{
    b.setA(ui->dASpin_2->value());
    b.setB(ui->dBSpin_2->value());
    b.setC(ui->dCSpin_2->value());
}

void operator<<(Ui::MainWindow* ui, Polynom const &obj)//todo
{
    if(obj.polyName == "a")
    {
        ui->showPolyA->click();
    }
    if(obj.polyName == "b")
    {
        ui->showPolyB->click();
    }
}

void operator>>(Ui::MainWindow* ui, Polynom &a)
{
        a.setA(ui->dASpin->value());
        a.setB(ui->dBSpin->value());
        a.setC(ui->dCSpin->value());
}

void MainWindow::on_calcOtherBtn_clicked()
{
    if(a == b)
    {
        ui->equality_label->setText("Equal");
    }
    else
    {
        ui->equality_label->setText("Not Equal");
    }

    Polynom c = a + b;
    ui->polySum_label->setText(QString::number(c.getA()) + "x<sup>2</sup> + " + QString::number(c.getB()) + "x + " + QString::number(c.getC()));
    c = a - b;
    ui->polyMinus_label->setText(QString::number(c.getA()) + "x<sup>2</sup> + " + QString::number(c.getB()) + "x + " + QString::number(c.getC()));
}

void MainWindow::on_multPolyBtn_clicked()
{
    a = a * ui->doubleSpinBox_3->value();
    ui << a;
}

void MainWindow::on_inversePolyBtn_clicked()
{
    !a;
    ui << a;
}

void MainWindow::on_calcRootsBtn_clicked()
{
    if(a.calculate())
    {
        ui->X1->setText(QString::number(a.getX1()));
        ui->X2->setText(QString::number(a.getX2()));
    }
    else
    {
        ui->X1->setText("No roots");
        ui->X2->setText("No roots");
    }
}

void MainWindow::on_calcIntegralBtn_clicked()
{
    double integr = a.integral(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
    ui->integr->setText(QString::number(integr));
}

void MainWindow::on_showPolyA_clicked()
{
    ui->PolyA_label->setText(QString::number(a.getA()) + "x<sup>2</sup> + " + QString::number(a.getB()) + "x + " + QString::number(a.getC()));
}

void MainWindow::on_showPolyB_clicked()
{
    ui->PolyB_label->setText(QString::number(b.getA()) + "x<sup>2</sup> + " + QString::number(b.getB()) + "x + " + QString::number(b.getC()));
}
