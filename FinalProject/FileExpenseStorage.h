#ifndef FILE_EXPENSE_STORAGE_H
#define FILE_EXPENSE_STORAGE_H

#include "IExpenseStorage.h"
#include <string>

class FileExpenseStorage : public IExpenseStorage {
public:
    FileExpenseStorage(const std::string& filename);
    void save(const std::vector<Expense>& expenses) override;
    std::vector<Expense> load() override;

private:
    std::string filename;
};

#endif