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

private:
    MySet a;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
