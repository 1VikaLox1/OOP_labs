#include "polynom.h"
#include "mainwindow.h"

int Polynom::objNum = 0;

double Polynom::getX2() const
{
    return x2;
}

void Polynom::setX2(double value)
{
    x2 = value;
}

Polynom::Polynom()
{
    a = 0;
    b = 0;
    c = 0;
    x1 = 0;
    x2 = 0;
}

Polynom::Polynom(std::string str)
{
    a = 0;
    b = 0;
    c = 0;
    x1 = 0;
    x2 = 0;
    polyName = str;
}

Polynom::Polynom(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

Polynom::~Polynom()
{

}

double Polynom::getX1() const
{
    return x1;
}

void Polynom::setX1(double value)
{
    x1 = value;
}

double Polynom::curriedFunc()
{
    return 2;
}

bool Polynom::calculate()
{
    bool flag = true;
    double d = b * b - 4 * a * c;
    if(d > 0)
    {
       x1 = (-b + sqrt(d))/(2 * a);
       x2 = (-b - sqrt(d))/(2 * a);
    }
    else if (d == 0.)
    {
        x1 = -b / (2 * a);
        x2 = x1;
    }
    else
    {
        //"V YAKIYS' LABEL VIVESTi >> ROZVYAZKIV NEMAE";
        flag = false;
    }
    return flag;
}

double Polynom::integral(double up, double down)
{
    return ((a * up*up*up)/3 + (b * up*up)/2 + c * up) - ((a * down*down*down)/3 + (b * down*down)/2 + c * down);
}


double Polynom::getC() const
{
    return c;
}

void Polynom::setC(double value)
{
    c = value;
}

double Polynom::getB() const
{
    return b;
}

void Polynom::setB(double value)
{
    b = value;
}

double Polynom::getA() const
{
    return a;
}

void Polynom::setA(double value)
{
    a = value;
}


Polynom operator *(Polynom A, double k)
{
    A.a *= k;
    A.b *= k;
    A.c *= k;
    return A;
}

bool operator ==(Polynom A, Polynom B)
{
    bool flag = false;
    if(A.a == B.a && A.b == B.b && A.c == B.c)
    {
        flag = true;
    }
    return flag;
}



double Polynom::operator[](int n)
{
    if (n == 1)
    {
        return this->a;
    }
    else if (n == 2)
    {
        return this->b;
    }
    else if(n == 3)
    {
        return this->c;
    }
    else
        return 0;
}

Polynom* Polynom::operator !()
{
    this->a *= (-1);
    this->b *= (-1);
    this->c *= (-1);
    return this;
}

bool Polynom::operator ()()
{
    bool flag = true;
    double d = b * b - 4 * a * c;
    if(d > 0)
    {
       x1 = (-b + sqrt(d))/(2 * a);
       x2 = (-b - sqrt(d))/(2 * a);
    }
    else if (d == 0.)
    {
        x1 = -b / (2 * a);
        x2 = x1;
    }
    else
    {
        flag = false;
    }
    return flag;
}

void Polynom::incrObjNum()
{
    Polynom::objNum++;
}

void Polynom::decrObjNum()
{
    Polynom::objNum--;
}

int Polynom::getObjNum()
{
    return objNum;
}

Polynom Polynom::operator +(Polynom B)
{
    return Polynom(a + B.a, b + B.b, c + B.c);
}

Polynom Polynom::operator -(Polynom B)
{
    return Polynom(a - B.a, b - B.b, c - B.c);
}

