#ifndef BANKDEPOSITE_H
#define BANKDEPOSITE_H


class BankDeposite
{
protected:
    double money;
    int months;
    double percent;
    double income;
public:
    BankDeposite();
    virtual ~BankDeposite();
    void startDeposite(double _money, int _months, double percent);
    virtual double takeMoneyNow(int daysFromStart);
    virtual double endDeposite();
    virtual double calculateIncome(double days);
    virtual double addMoney(double amount);
    double getMoney() const;
    int getMonths() const;
    double getPercent() const;
    double getIncome() const;
};

#endif // BANKDEPOSITE_H
