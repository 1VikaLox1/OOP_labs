#ifndef COMULATIVEDEPOSITE_H
#define COMULATIVEDEPOSITE_H

#include "bankdeposite.h"

class ComulativeDeposite : public BankDeposite
{
public:
    ComulativeDeposite();
    double calculateIncome(double time);
    double takeMoneyNow(int daysFromStart);
};

#endif // COMULATIVEDEPOSITE_H
