#ifndef VIPDEPOSITE_H
#define VIPDEPOSITE_H

#include "comulativedeposite.h"

class VIPDeposite : public ComulativeDeposite
{
public:
    VIPDeposite();
    double addMoney(double amount);
};

#endif // VIPDEPOSITE_H
