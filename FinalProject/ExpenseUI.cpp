#include "ExpenseUI.h"
#include "Color.h"
#include <iostream>

ExpenseUI::ExpenseUI(ExpenseManager& manager, IExpenseStorage& storage)
    : manager(manager), storage(storage) {}

void ExpenseUI::showMenu() {
    int choice;

    while (true) {
        bool stop = false;

        std::cout << COLOR_CYAN << "\n===== Expense Tracker =====\n" << COLOR_RESET;
        std::cout << COLOR_GREEN << "1." << COLOR_YELLOW << " Add Expense\n";
        std::cout << COLOR_GREEN << "2." << COLOR_YELLOW << " List All Expenses\n";
        std::cout << COLOR_GREEN << "3." << COLOR_YELLOW << " List Expenses by Category\n";
        std::cout << COLOR_GREEN << "4." << COLOR_YELLOW << " List Expenses by Date\n";
        std::cout << COLOR_GREEN << "5." << COLOR_YELLOW << " Show Total Expenses\n";
        std::cout << COLOR_GREEN << "6." << COLOR_YELLOW << " Save Expenses to File\n";
        std::cout << COLOR_GREEN << "7." << COLOR_YELLOW << " Load Expenses from File\n";
        std::cout << COLOR_GREEN << "0." << COLOR_YELLOW << " Exit\n" << COLOR_RESET;
        std::cout << COLOR_BOLD << "Select an option: " << COLOR_RESET;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << COLOR_RED << "Invalid Input" << COLOR_RESET << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: addExpense(); break;
        case 2: listExpenses(); break;
        case 3: listByCategory(); break;
        case 4: listByDate(); break;
        case 5: showTotal(); break;
        case 6: saveExpenses(); break;
        case 7: loadExpenses(); break;
        case 0: std::cout << COLOR_GREEN << "Goodbye!\n" << COLOR_RESET; stop = true; break;
        default: std::cout << COLOR_RED << "Invalid choice.\n" << COLOR_RESET;
        }

        if (stop) { break; }
    }
}

void ExpenseUI::addExpense() {
    std::string category, date;
    double amount;

    std::cin.ignore();
    std::cout << "Enter category: ";
    std::getline(std::cin, category);

    while (true) {
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (std::cin.fail()) {
            std::cout << COLOR_RED << "Invalid Input" << COLOR_RESET << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    std::cin.ignore();
    std::cout << "Enter date (DD-MM-YYYY): ";
    std::getline(std::cin, date);

    manager.addExpense(Expense(category, amount, date));
    std::cout << COLOR_GREEN << "Expense added successfully.\n" << COLOR_RESET;
}

void ExpenseUI::listExpenses() {
    const auto& expenses = manager.getAllExpenses();
    std::cout << COLOR_BOLD << "All Expenses:\n" << COLOR_RESET;
    for (const auto& e : expenses) {
        std::cout << COLOR_YELLOW << e.getDate() << COLOR_RESET
            << " | " << COLOR_BLUE << e.getCategory() << COLOR_RESET
            << " | " << COLOR_GREEN << "$" << e.getAmount() << COLOR_RESET << '\n';
    }
}

void ExpenseUI::listByCategory() {
    std::string category;

    std::cin.ignore();
    std::cout << "Enter category: ";
    std::getline(std::cin, category);

    auto filtered = manager.getExpensesByCategory(category);
    std::cout << COLOR_BOLD << "Expenses in category: " << category << "\n" << COLOR_RESET;
    for (const auto& e : filtered) {
        std::cout << COLOR_YELLOW << e.getDate() << COLOR_RESET
            << " | " << COLOR_BLUE << e.getCategory() << COLOR_RESET
            << " | " << COLOR_GREEN << "$" << e.getAmount() << COLOR_RESET << '\n';
    }
}

void ExpenseUI::listByDate() {
    std::string date;

    std::cin.ignore();
    std::cout << "Enter date (DD-MM-YYYY): ";
    std::getline(std::cin, date);

    auto filtered = manager.getExpensesByDate(date);
    std::cout << COLOR_BOLD << "Expenses on: " << date << "\n" << COLOR_RESET;
    for (const auto& e : filtered) {
        std::cout << COLOR_YELLOW << e.getDate() << COLOR_RESET
            << " | " << COLOR_BLUE << e.getCategory() << COLOR_RESET
            << " | " << COLOR_GREEN << "$" << e.getAmount() << COLOR_RESET << '\n';
    }
}

void ExpenseUI::showTotal() {
    double total = manager.getTotalExpenses();
    std::cout << COLOR_BOLD << "Total Expenses: " << COLOR_GREEN
        << "$" << total << COLOR_RESET << '\n';
}

void ExpenseUI::saveExpenses() {
    storage.save(manager.getAllExpenses());
    std::cout << COLOR_GREEN << "Expenses saved to file.\n" << COLOR_RESET;
}

void ExpenseUI::loadExpenses() {
    auto loaded = storage.load();
    for (const auto& e : loaded) {
        manager.addExpense(e);
    }
    std::cout << COLOR_GREEN << "Expenses loaded from file.\n" << COLOR_RESET;
}