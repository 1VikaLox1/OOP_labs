#ifndef COMULATIVEDEPOSITE_H
#define COMULATIVEDEPOSITE_H

#include "bankdeposite.h"

class ComulativeDeposite : public BankDeposite
{
public:
    ComulativeDeposite();
    virtual ~ComulativeDeposite();
    double calculateIncome(double days);
    double takeMoneyNow(int daysFromStart);
};

#endif // COMULATIVEDEPOSITE_H
