Inventory Management System

This project implements an Inventory Management System for a bookstore. The system allows interaction between three user roles: Customer, Cashier, and Store Manager,
each with specific functionality. It is built in C++ using an object-oriented approach and includes features for inventory management, sales, and restocking.

Features

User Roles
1. Customer:
View available items in the inventory.
Request and purchase books.

2. Cashier:
Handle sales transactions.
View total sales and costs.

4. Store Manager:
Restock items in the inventory.
---

Functionalities
1. Inventory Management:
Add new items to the inventory.
Display inventory details.

2. Sales Transactions:
Sell items to customers based on availability.
Track total sales.

3. Restocking:
Update inventory with additional stock.
Track restocking costs.
---

Classes Overview

1. Item (Base Class):
Represents a general inventory item with attributes like title, author, price, cost, and stock.

3. Book and Magazine (Derived Classes):
Extend the Item class to represent specific types of inventory items.

3. Inventory:
Manages the list of items in the inventory.
Provides methods to add, search, and update items.

4. User Roles:
User: Abstract base class for Customer, Cashier, and StoreManager.
Customer: Views and requests books.
Cashier: Handles sales and tracks financial transactions.
StoreManager: Restocks inventory items.

---

How to Run

1. Compile the code:

g++ -o inventory inventory.cpp

2. Execute the program:

./inventory

3. Follow the menu prompts to interact with the system.
---
Dependencies

C++ Standard Library

iostream, vector, string, and iomanip for data manipulation and display.
---

Future Improvements

Implement data persistence (e.g., save and load inventory to/from a file).
Add support for more item types.
Include authentication for user roles.

---

This system provides a robust starting point for managing a bookstore's inventory, ensuring smooth interaction between customers, cashiers, and managers.

