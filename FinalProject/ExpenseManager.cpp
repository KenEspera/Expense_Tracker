#include "ExpenseManager.h"
#include <algorithm>

void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

std::vector<Expense> ExpenseManager::getAllExpenses() const {
    return expenses;
}

std::vector<Expense> ExpenseManager::getExpensesByCategory(const std::string& category) const {
    std::vector<Expense> result;
    for (const auto& expense : expenses) {
        if (expense.getCategory() == category) {
            result.push_back(expense);
        }
    }
    return result;
}

std::vector<Expense> ExpenseManager::getExpensesByDate(const std::string& date) const {
    std::vector<Expense> result;
    for (const auto& expense : expenses) {
        if (expense.getDate() == date) {
            result.push_back(expense);
        }
    }
    return result;
}

double ExpenseManager::getTotalExpenses() const {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.getAmount();
    }
    return total;
}