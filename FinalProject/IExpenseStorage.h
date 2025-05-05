#ifndef IEXPENSE_STORAGE_H
#define IEXPENSE_STORAGE_H

#include <vector>
#include "Expense.h"

class IExpenseStorage {
public:
    virtual void save(const std::vector<Expense>& expenses) = 0;
    virtual std::vector<Expense> load() = 0;
    virtual ~IExpenseStorage() = default;
};

#endif