#ifndef EXPENSE_UI_H
#define EXPENSE_UI_H

#include "ExpenseManager.h"
#include "IExpenseStorage.h"

class ExpenseUI {
public:
    ExpenseUI(ExpenseManager& manager, IExpenseStorage& storage);
    void showMenu();

private:
    ExpenseManager& manager;
    IExpenseStorage& storage;

    void addExpense();
    void listExpenses();
    void listByCategory();
    void listByDate();
    void showTotal();
    void saveExpenses();
    void loadExpenses();
};

#endif