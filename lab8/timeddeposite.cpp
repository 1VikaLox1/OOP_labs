#include "timeddeposite.h"

TimedDeposite::TimedDeposite()
{

}

double TimedDeposite::takeMoneyNow(int daysFromStart)
{
    if(daysFromStart >= months)
    {
        income = calculateIncome(months);
    }
    else
    {
        income = 0;
    }
    return income;
}

