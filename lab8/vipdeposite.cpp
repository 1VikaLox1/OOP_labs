#include "vipdeposite.h"

VIPDeposite::VIPDeposite()
{

}

VIPDeposite::~VIPDeposite()
{

}

double VIPDeposite::addMoney(double amount)
{
    if(percent < 20)
    {
        this->percent += amount / money;
    }

    this->money += amount;

    return money;
}
