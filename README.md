# FinalProject
📄 Description
This is a simple, modular C++ console application to manage personal expenses. It allows users to add, view, categorize, and persist expenses. Designed using clean architecture principles and the SOLID design philosophy, the app separates business logic, data models, and UI for better maintainability and scalability.


✨ Features


•  Add new expenses (amount, category, date)

•  View all recorded expenses

•  Filter expenses by category (supports partial/case-insensitive search)

•  View total expense amount

•  Save and load expenses to/from a file

•  Colored console output for better user experience


⚙️ Functionality


Feature	Description

Add Expense:              Prompts user for amount, category, and date; adds to memory list

List All Expenses:	      Displays all stored expenses with color formatting

List by Category:         Accepts partial input and lists matching categories case-insensitively

Show Total Expense:       Sums and displays the total of all recorded expenses

Save Expenses to File:    Writes current expense list to a file (e.g. expenses.txt)

Load Expenses from File:	Loads expenses from a previously saved file

Exit:                    	Ends the program gracefully


🧱 Design Pattern


MVC (Model-View-Controller)-like separation:


Expense:                  Data model (represents each record)

ExpenseManager:           Acts as the controller and logic handler

ExpenseUI:                Handles all user interaction and I/O

FileExpenseStorage:       Responsible for reading/writing to file (optional for no-file version)


📐 SOLID Principles Applied


Principle:              	Application

Single Responsibility:	  Each class has one responsibility (UI, data, logic, storage)

Open/Closed:            	New storage types or filters can be added without modifying core logic

Liskov Substitution:     	If interfaces were added, components like storage could be swapped easily

Interface Segregation:  	UI and storage logic are decoupled to avoid forcing unnecessary methods

Dependency Inversion: 	  High-level modules (ExpenseManager) depend on abstractions, not storage

