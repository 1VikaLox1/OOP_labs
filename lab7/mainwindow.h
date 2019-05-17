#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "myset.h"

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
    void on_clearGrid_clicked();

    void on_enterElemsBtn_clicked();
    //void Print(int Size, int array[]);

    void on_ShowElemsBtn_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_ShowMEMOBtn_clicked();

    void on_EnterMEMOBtn_clicked();

    void on_ClearSetBtn_clicked();

    void on_findMaxBtn_clicked();

    void on_findMinBtn_clicked();

    void on_findPBtn_clicked();

    void on_plusBtn_clicked();

    void on_minusBtn_clicked();

    void on_dvideBtn_clicked();

    void PrintOnGrid(MySet);

    void EnterFromTextEdit(MySet &obj);

private:
    MySet setA;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
