#include "comulativedeposite.h"
#include "math.h"

double ComulativeDeposite::calculateIncome(double time)
{
    return money * pow( (1 + percent), time);
}

double ComulativeDeposite::takeMoneyNow(int daysFromStart)
{
    income = calculateIncome(daysFromStart / 30); //number of months
    return income;
}

ComulativeDeposite::ComulativeDeposite()
{

}
