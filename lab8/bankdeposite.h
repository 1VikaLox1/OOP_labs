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

    void startDeposite(double _money, int _months, double percent);
    double takeMoneyNow(int daysFromStart);
    double endDeposite();
    double calculateIncome(double time, int daysInYear = 365);
    double getMoney() const;
    int getMonths() const;
    double getPercent() const;
    double getIncome() const;
};

#endif // BANKDEPOSITE_H
