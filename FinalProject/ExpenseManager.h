#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include "Expense.h"
#include <vector>
#include <string>

class ExpenseManager {
public:
    void addExpense(const Expense& expense);
    std::vector<Expense> getAllExpenses() const;
    std::vector<Expense> getExpensesByCategory(const std::string& category) const;
    std::vector<Expense> getExpensesByYear(const std::string& year) const;
    std::vector<Expense> getExpensesByMonth(const std::string& yearMonth) const;
    std::vector<Expense> getExpensesByExactDate(const std::string& fullDate) const;
    double getTotalExpenses() const;

private:
    std::vector<Expense> expenses;
};

#endif