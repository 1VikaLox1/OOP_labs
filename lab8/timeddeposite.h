#ifndef TIMEDDEPOSITE_H
#define TIMEDDEPOSITE_H

#include "bankdeposite.h"

class TimedDeposite : public BankDeposite
{
public:
    TimedDeposite();

    double takeMoneyNow(int daysFromStart);
};

#endif // TIMEDDEPOSITE_H
