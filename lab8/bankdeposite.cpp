#include "bankdeposite.h"

double BankDeposite::calculateIncome(double days) //TODO check formula
{
    return money + (money * (percent / 100) * (days / 30));
}

double BankDeposite::addMoney(double amount)
{

}

double BankDeposite::getMoney() const
{
    return money;
}

int BankDeposite::getMonths() const
{
    return months;
}

double BankDeposite::getPercent() const
{
    return percent;
}

double BankDeposite::getIncome() const
{
    return income;
}

BankDeposite::BankDeposite()
{
    money = 0;
    months = 0;
    percent = 0;
    income = 0;
}

BankDeposite::~BankDeposite()
{

}

void BankDeposite::startDeposite(double _money, int _months, double _percent)
{
    //це все можна робити і через this
    money = _money;
    months = _months;
    percent = _percent;
}

double BankDeposite::takeMoneyNow(int daysFromStart)
{
    income = calculateIncome(daysFromStart);
    return income;
}

double BankDeposite::endDeposite()
{
    income = calculateIncome(months);
    return income;
}
