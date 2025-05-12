#include "FileExpenseStorage.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileExpenseStorage::FileExpenseStorage(const std::string& filename)
    : filename(filename) {}

void FileExpenseStorage::save(const std::vector<Expense>& expenses) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for saving.\n";
        return;
    }
    for (const auto& expense : expenses) {
        outFile << expense.getCategory() << ","
            << expense.getAmount() << ","
            << expense.getDate() << "\n";
    }
    outFile.close();
}

std::vector<Expense> FileExpenseStorage::load() {
    std::vector<Expense> expenses;
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for loading.\n";
        return expenses;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string category, amountStr, date;

        if (std::getline(ss, category, ',') &&
            std::getline(ss, amountStr, ',') &&
            std::getline(ss, date)) {

            double amount = std::stod(amountStr);
            expenses.emplace_back(category, amount, date);
        }
    }
    inFile.close();
    return expenses;
}