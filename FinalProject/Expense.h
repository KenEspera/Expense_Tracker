#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
public:
    Expense(std::string category, double amount, std::string date)
        : category(std::move(category)), amount(amount), date(std::move(date)) {}

    std::string getCategory() const { return category; }
    double getAmount() const { return amount; }
    std::string getDate() const { return date; }

private:
    std::string category;
    double amount;
    std::string date;
};

#endif