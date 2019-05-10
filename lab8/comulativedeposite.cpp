#include "comulativedeposite.h"
#include "math.h"

double ComulativeDeposite::calculateIncome(double days)//TODO check formula for show incom per day
{
    int monthsFromStart = static_cast<int>(floor(days / 30));
    return money * pow( (1 + percent / 100), monthsFromStart);
}

double ComulativeDeposite::takeMoneyNow(int daysFromStart)
{
    income = calculateIncome(daysFromStart); //number of months
    return income;
}

ComulativeDeposite::ComulativeDeposite()
{

}

ComulativeDeposite::~ComulativeDeposite()
{

}
