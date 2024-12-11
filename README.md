# Inventory Management System

This project implements an *Inventory Management System* for a bookstore, designed to streamline inventory management, sales, and restocking. The system supports interaction among three user roles: *Customer, **Cashier, and **Store Manager*, each with specific functionalities. Built using C++ with an object-oriented approach, this system serves as a foundational tool for managing bookstore operations efficiently.

---

## Features

### *User Roles*

1. *Customer*

   - View available items in the inventory.
   - Request and purchase books.

2. *Cashier*

   - Handle sales transactions.
   - View total sales and costs.

3. *Store Manager*
   - Restock items in the inventory.

---

### *Core Functionalities*

1. *Inventory Management*

   - Add new items to the inventory.
   - Display detailed inventory information.

2. *Sales Transactions*

   - Sell items to customers based on availability.
   - Track and display total sales revenue.

3. *Restocking*
   - Update the inventory with additional stock.
   - Track restocking costs to maintain profitability.

---

## System Architecture

### *Class Design*

1. *Item* (Base Class)

   - Represents a generic inventory item with attributes:
     - title, author, price, cost, and stock.

2. *Book* and *Magazine* (Derived Classes)

   - Extend the Item class to represent specific types of inventory items.

3. *Inventory*

   - Maintains a list of items.
   - Provides methods to:
     - Add new items.
     - Search for specific items.
     - Update stock levels.

4. *User Roles*
   - *User* (Abstract Base Class):  
     Defines shared functionality for all roles.
   - *Customer*:
     - Views and requests books.
   - *Cashier*:
     - Manages sales transactions and financial records.
   - *Store Manager*:
     - Handles inventory restocking.

---

## How to Use

### *Compilation and Execution*

1. Compile the code using the following command:

   bash
   g++ -o inventory inventory.cpp
   

2. Execute the program:
   bash
   ./inventory
   
3. Follow the on-screen menu prompts to interact with the system.

---

## Dependencies

- *C++ Standard Library*
  - Utilized for core functionalities, including data manipulation and display.
  - Libraries used:
    - iostream
    - vector
    - string
    - iomanip

---

## Future Enhancements

1. *Data Persistence*

   - Enable saving and loading inventory data to/from files for seamless continuity.

2. *Additional Item Types*

   - Expand support for a wider range of items, such as stationery or digital content.

3. *User Authentication*

   - Implement login functionality to ensure secure access for different user roles.

4. *Graphical Interface*

   - Develop a user-friendly graphical interface for enhanced usability.

5. *Advanced Reporting*
   - Include detailed sales and restocking reports for better decision-making.

---

This project provides a robust foundation for managing a bookstore's operations. Its modular and extensible design makes it easy to adapt and enhance for more complex requirements.

Feel free to contribute or suggest improvements to make this system even better!
