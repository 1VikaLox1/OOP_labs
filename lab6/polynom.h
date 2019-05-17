#ifndef POLYNOM_H
#define POLYNOM_H
#include <cmath>
#include <string>
#include<QMainWindow>

namespace Ui {
class MainWindow;
}


class Polynom
{
private:
    double a, b, c, x1, x2;
    std::string polyName;
    static int objNum;
public:
    Polynom();
    Polynom(std::string str);
    Polynom(double a, double b, double c);
    ~Polynom();
    double getA() const;
    void setA(double value);
    double getB() const;
    void setB(double value);
    double getC() const;
    void setC(double value);
    double getX1() const;
    void setX1(double value);
    double getX2() const;
    void setX2(double value);
    double curriedFunc();
    bool calculate();
    double integral(double up, double down);
    Polynom operator +(Polynom B);
    Polynom operator -(Polynom B);
    Polynom* operator !();
    bool operator ()();
    double operator[](int n);
    friend Polynom operator *(Polynom A, double k);
    friend bool operator ==(Polynom A, Polynom B);
    friend void operator<<(Ui::MainWindow* ui, Polynom const &a);
    friend void operator>>(Ui::MainWindow* ui, Polynom &a);
    static void incrObjNum();
    static void decrObjNum();
    static int getObjNum();
};


#endif // POLYNOM_H

