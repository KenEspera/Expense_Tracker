#include "ExpenseUI.h"
#include "Color.h"
#include <iostream>
#include <string>
#include <algorithm> 

ExpenseUI::ExpenseUI(ExpenseManager& manager, IExpenseStorage& storage)
    : manager(manager), storage(storage) {}

void ExpenseUI::showMenu() {
    int choice;
    std::string input;

    while (true) {
        bool stop = false;

        std::cout << COLOR_CYAN << "\n====== Expense Tracker ======\n" << COLOR_RESET;
        std::cout << COLOR_GREEN << "1." << COLOR_YELLOW << " Add Expense\n";
        std::cout << COLOR_GREEN << "2." << COLOR_YELLOW << " List All Expenses\n";
        std::cout << COLOR_GREEN << "3." << COLOR_YELLOW << " List Expenses by Category\n";
        std::cout << COLOR_GREEN << "4." << COLOR_YELLOW << " List Expenses by Date\n";
        std::cout << COLOR_GREEN << "5." << COLOR_YELLOW << " Show Total Expenses\n";
        std::cout << COLOR_GREEN << "6." << COLOR_YELLOW << " Save Expenses to File\n";
        std::cout << COLOR_GREEN << "7." << COLOR_YELLOW << " Load Expenses from File\n";
        std::cout << COLOR_GREEN << "0." << COLOR_YELLOW << " Exit" << COLOR_RESET;
        std::cout << COLOR_CYAN << "\n=============================\n" << COLOR_RESET;
        std::cout << COLOR_BOLD << "Select an option: " << COLOR_RESET;

        std::getline(std::cin, input);

        if (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit)) {
            std::cout << COLOR_RED << "Invalid input\n" << COLOR_RESET;
            continue;
        }
        choice = std::stoi(input);

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

    std::cout << "Enter category (b to back): ";
    std::getline(std::cin, category);
    if (category == "b" || category == "B") {
		ExpenseUI::showMenu();
    }

    while (true) {
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (std::cin.fail() || amount <= 0) {
            std::cout << COLOR_RED << "Invalid Input" << COLOR_RESET << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    std::cin.ignore();
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    if (date.empty() || date.find(' ') != std::string::npos) {
        date = "No Date Added";
    }

    manager.addExpense(Expense(category, amount, date));
    std::cout << COLOR_GREEN << "Expense added successfully.\n" << COLOR_RESET;
}

void ExpenseUI::listExpenses() {
    const auto& expenses = manager.getAllExpenses();
    std::cout << COLOR_BOLD << "\nAll Expenses:" << COLOR_RESET;

    std::cout << COLOR_CYAN << "\n========== Expense ==========\n" << COLOR_RESET;
    for (const auto& e : expenses) {
        std::cout << COLOR_YELLOW << e.getDate() << COLOR_RESET
            << " | " << COLOR_BLUE << e.getCategory() << COLOR_RESET
            << " | " << COLOR_GREEN << "$" << e.getAmount() << COLOR_RESET << '\n';
    }
    std::cout << COLOR_CYAN << "=============================\n" << COLOR_RESET;
}

void ExpenseUI::listByCategory() {
    std::string category;

    std::cout << "Search for category (b to back): ";
    std::getline(std::cin, category);
    if (category == "b" || category == "B") {
        ExpenseUI::showMenu();
    }

    auto filtered = manager.getExpensesByCategory(category);
    std::cout << COLOR_BOLD << "\nExpenses in category: " << category << "\n" << COLOR_RESET;
    if (filtered.empty()) {
        std::cout << COLOR_RED << "No category found" << COLOR_RESET << '\n';
        ExpenseUI::showMenu();
    }
    std::cout << COLOR_CYAN << "========== Expense ==========\n" << COLOR_RESET;
    for (const auto& e : filtered) {
            std::cout << COLOR_YELLOW << e.getDate() << COLOR_RESET
                << " | " << COLOR_BLUE << e.getCategory() << COLOR_RESET
                << " | " << COLOR_GREEN << "$" << e.getAmount() << COLOR_RESET << '\n';
    }
    std::cout << COLOR_CYAN << "=============================\n" << COLOR_RESET;
}

void ExpenseUI::listByDate() {
    std::string date;

    std::cin.ignore();
    std::cout << "Enter date (YYYY-MM-DD or 'b' to back): ";
    std::getline(std::cin, date);
    if (date == "b" || date == "B") {
        ExpenseUI::showMenu();
    }

    auto filtered = manager.getExpensesByDate(date);
    if (filtered.empty()) {
        std::cout << COLOR_RED << "No expenses found." << COLOR_RESET << '\n';
        ExpenseUI::showMenu();
    }
    else {
        for (const auto& e : filtered) {
            std::cout << COLOR_YELLOW << e.getDate() << COLOR_RESET
                << " | " << COLOR_BLUE << e.getCategory() << COLOR_RESET
                << " | " << COLOR_GREEN << "$" << e.getAmount() << COLOR_RESET << '\n';
        }
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