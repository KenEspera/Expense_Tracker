//#include <gtest/gtest.h>
//#include "ExpenseManager.h"
//#include "Expense.h"
//
//TEST(ExpenseTest, ConstructorAndGetters) {
//    Expense e("Food", 12.5, "2025-05-01");
//    EXPECT_EQ(e.getCategory(), "Food");
//    EXPECT_DOUBLE_EQ(e.getAmount(), 12.5);
//    EXPECT_EQ(e.getDate(), "2025-05-01");
//}
//
//TEST(ExpenseManagerTest, AddAndGetAllExpenses) {
//    ExpenseManager manager;
//    manager.addExpense(Expense("Transport", 20.0, "2025-04-30"));
//
//    auto all = manager.getAllExpenses();
//    ASSERT_EQ(all.size(), 1);
//    EXPECT_EQ(all[0].getCategory(), "Transport");
//    EXPECT_DOUBLE_EQ(all[0].getAmount(), 20.0);
//}
//
//TEST(ExpenseManagerTest, FilterByCategory) {
//    ExpenseManager manager;
//    manager.addExpense(Expense("Food", 10, "2025-04-01"));
//    manager.addExpense(Expense("Transport", 15, "2025-04-02"));
//
//    auto filtered = manager.getExpensesByCategory("Food");
//    ASSERT_EQ(filtered.size(), 1);
//    EXPECT_EQ(filtered[0].getCategory(), "Food");
//}
//
//TEST(ExpenseManagerTest, TotalCalculation) {
//    ExpenseManager manager;
//    manager.addExpense(Expense("Food", 10, "2025-04-01"));
//    manager.addExpense(Expense("Transport", 15, "2025-04-02"));
//
//    EXPECT_DOUBLE_EQ(manager.getTotalExpenses(), 25.0);
//}
