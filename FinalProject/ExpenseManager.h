#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include "Expense.h"
#include <vector>

class ExpenseManager {
public:
    void addExpense(const Expense& expense);
    std::vector<Expense> getAllExpenses() const;
    std::vector<Expense> getExpensesByCategory(const std::string& category) const;
    std::vector<Expense> getExpensesByDate(const std::string& date) const;
    double getTotalExpenses() const;

private:
    std::vector<Expense> expenses;
};

#endif