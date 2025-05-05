#include "Expense.h"
#include "ExpenseManager.h"
#include "FileExpenseStorage.h"
#include "ExpenseUI.h"

#include <iostream>

int main() {
    FileExpenseStorage storage("expenses.txt");

    std::cout << "Hi";

    ExpenseManager manager;
    ExpenseUI ui(manager, storage);

    ui.showMenu();

    return 0;
}