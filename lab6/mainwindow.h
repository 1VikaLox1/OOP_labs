#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "polynom.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateBtn_clicked();

    void on_enterBtn_clicked();

    void on_curriedFuncBtn_clicked();

    void on_enterBtn_2_clicked();

    void on_calcOtherBtn_clicked();

    void on_multPolyBtn_clicked();

    void on_inversePolyBtn_clicked();

    void on_calcRootsBtn_clicked();

    void on_calcIntegralBtn_clicked();

    void on_showPolyA_clicked();

    void on_showPolyB_clicked();

private:
    Ui::MainWindow *ui;
    Polynom a = Polynom("a");
    Polynom b = Polynom("b");
    friend void operator<<(Ui::MainWindow* ui, Polynom const &a);
};

#endif // MAINWINDOW_H
