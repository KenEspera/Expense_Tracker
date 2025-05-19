#include "ExpenseManager.h"
#include <algorithm>
#include <cctype>

void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

std::vector<Expense> ExpenseManager::getAllExpenses() const {
    return expenses;
}

std::string toLower(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lower;
}

std::vector<Expense> ExpenseManager::getExpensesByCategory(const std::string& input) const {
    std::vector<Expense> result;
    std::string inputLower = toLower(input);

    for (const auto& e : expenses) {
        std::string categoryLower = toLower(e.getCategory());
        if (categoryLower.find(inputLower) != std::string::npos) {
            result.push_back(e);
        }
    }
    return result;
}

std::vector<Expense> ExpenseManager::getExpensesByDate(const std::string& date) const {
    std::vector<Expense> result;

    for (const auto& e : expenses) {
        if (e.getDate().rfind(date, 0) == 0) {
            result.push_back(e);
        }
    }
    std::sort(result.begin(), result.end(), [](const Expense& a, const Expense& b) {
        return a.getDate() < b.getDate();
        });
    return result;
}

double ExpenseManager::getTotalExpenses() const {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.getAmount();
    }
    return total;
}