#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bankdeposite.h"

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
    void on_StartBtn_clicked();

    void on_calculateBtn_clicked();

    void on_takeMoneyBtn_clicked();

    void on_addMoneyBtn_clicked();

private:
    Ui::MainWindow *ui;
    BankDeposite *deposite;
};

#endif // MAINWINDOW_H
