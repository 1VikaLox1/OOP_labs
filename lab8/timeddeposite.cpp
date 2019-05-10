#include "timeddeposite.h"

TimedDeposite::TimedDeposite():BankDeposite ()
{
    money = 0;
    months = 0;
    percent = 0;
    income = 0;
}

TimedDeposite::~TimedDeposite()
{

}

double TimedDeposite::takeMoneyNow(int daysFromStart)
{
    if(daysFromStart >= months * 30)
    {
        income = calculateIncome(months * 30);
    }
    else
    {
        income = money;
    }
    return income;
}

