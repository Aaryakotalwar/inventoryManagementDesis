#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Base class 
class Item {
protected:
    string title;
    string author;
    double price;// selling price
    double cost; //how much store paid for it
    int stock;

public:
    //constructor
    Item(string title, string author, double price, int stock, double cost){
        this->title=title;
        this->author=author;
        this->price=price;
        this->stock=stock;
        this->cost=cost;
    }

    virtual void display() const {
        cout << setw(20) << title << setw(15) << author
             << setw(10) << price <<setw(10)<< cost << setw(10) << stock << endl;
    }

    string getTitle() const { return title; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }
    double getCost() const { return cost; }

    void updateStock(int quantity) { stock += quantity; }
};

// Derived class for Books
class Book : public Item {
public:
    Book(string title, string author, double price, int stock, double cost)
        : Item(title, author, price, stock, cost) {}

    void display() const {
        cout << setw(10)<< "Book";
        Item::display();
    }
};

// Derived class for Magazines
class Magazine : public Item {
public:
    Magazine(string title, string author, double price, int stock, double cost)
        : Item(title, author, price, stock, cost) {}

    void display() const{
        cout << "Magazine";
        Item::display();
    }
};

// Inventory Management
class Inventory {
private:
    vector<Item*> items;

public:
    void addItem(Item* item) {
        items.push_back(item);
    }

    void displayInventory() const {
        cout << setw(10) << "Type" << setw(20) << "Title" << setw(15) << "Author"
             << setw(10) << "Price" << setw(10) <<"cost"<<setw(10) << "Stock" << endl;
        cout << string(70, '-') << endl;
        for (const auto& item : items) {
            item->display();
        }
    }

    Item* findItem(const string& title) {
        for (auto& item : items) {
            if (item->getTitle() == title) return item;
        }
        return nullptr;
    }

    void updateInventory(string title, int quantity, int cost) {
        Item* item = findItem(title);
        if (item) {
            item->updateStock(quantity);
        } else {
            cout << "Item not found. Adding new book to inventory.\n";

        // Create a new book (assuming it's a Book for now)
            string author;
            double price, cost;

            cout << "Enter the author of the book: ";
            cin.ignore(); 
            getline(cin, author);

            cout << "Enter the price of the book: ";
            cin >> price;
            // cout << "Enter the cost of the book: ";
            // cin >> cost;

        // Create a new Book and add it to the inventory
            Book* newBook = new Book(title, author, price, quantity, cost);
            addItem(newBook);  // Add the new book to the inventory

            cout << "New book added: " << title << " by " << author << ".\n";
        }
    }

    double sellItem(string title, int quantity) {
        Item* item = findItem(title);
        if (item && item->getStock() >= quantity) {
            item->updateStock(-quantity);
            return item->getPrice() * quantity;
        } else {
            cout << "Item not found or insufficient stock.\n";
            return 0.0;
        }
    }
};

// User Roles
class User {
protected:
    string name;

public:
    User(string name) {this->name=name;}
    virtual void role() const = 0;
    string getName() const { return name; }
};


// handle sales
class Cashier : public User {
private:
    double totalSales = 0.0;
    double totalCosts = 0.0;

public:
    Cashier(string name):User(name){}

    void role() const {
        cout << "Role: Cashier\n";
    }

    void sell(Inventory& inventory, const vector <pair<string, int> >& bookRequests) {
        double totalSale = 0.0;
        for (const auto& book : bookRequests) {
            const string& title = book.first;
            int quantity = book.second;

            double sale = inventory.sellItem(title, quantity);
            if (sale > 0) {
                totalSale += sale;
                cout << "Sold " << quantity << " units of " << title << " for rupee " << sale << ".\n";
            }
        }

        if (totalSale > 0) {
            totalSales += totalSale;
            cout << "Total sale for this transaction: rupee " << totalSale << ".\n";
        }
    }
    void buy(double cost){totalCosts+=cost;}
    void showTotalSales() const {
        cout << "Total sales: rupee " << totalSales << endl;
    }
    void showTotalCosts() const {
        cout << "Total costs: rupee " << totalCosts << endl;
    }
};


//handles stock
class StoreManager : public User {
public:
    StoreManager(string name):User(name){}

    void role() const {
        cout << "Role: Store Manager\n";
    }
    //restock one item at a time
    void restock(Inventory& inventory, Cashier& cashier) {
        string title;
        int quantity;
        double cost;
        cout << "Enter the title of the item to restock: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the quantity to add: ";
        cin >> quantity;
        cout<<"Enter the cost: ";
        cin>>cost;
        cashier.buy(cost*quantity);
        inventory.updateInventory(title, quantity,cost);
        cout << "Restocked " << quantity << " units of " << title << ".\n";
    }
};

class Customer : public User {
public:
    Customer(string name):User(name){}

    void role() const {
        cout << "Role: Customer\n";
    }

    void viewItems(const Inventory& inventory) {
        inventory.displayInventory();
    }

    vector<pair<string, int>> requestBooks() {
        vector<pair<string, int>> bookRequests;
        int numRequests;

        cout << "How many different books would you like to purchase? ";
        cin >> numRequests;

        cin.ignore();  // To ignore the newline character 

        for (int i = 0; i < numRequests; ++i) {
            string title;
            int quantity;

            cout << "Enter the title of the book you want to buy: ";
            getline(cin, title);
            cout << "Enter the quantity of " << title << ": ";
            cin >> quantity;
            cin.ignore();  

            bookRequests.push_back(make_pair(title, quantity));
        }
        return bookRequests;
    }
};

// Main Function
int main() {
    Inventory inventory;

    // Adding initial items to inventory
    inventory.addItem(new Book("C++", "Biscuit", 50.0, 10, 30.0));
    inventory.addItem(new Magazine("Tech Monthly", "Various", 10.0, 20, 5.0));
    inventory.addItem(new Book("Data Structures", "lollipop", 40.0, 5, 25.0));

    StoreManager manager("A");
    Cashier cashier("B");
    Customer customer("C");

    int choice;

    while (true) {
        cout << "\n=== Bookstore Menu ===\n";
        cout << "1. View Inventory (Customer)\n";
        cout << "2. Buy Item (Cashier)\n";
        cout << "3. Restock Item (Manager)\n";
        cout << "4. View Total Sales (Cashier)\n";
        cout << "5. View Total Costs (Cashier)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                customer.viewItems(inventory);
                break;
            case 2:{
                vector<pair<string, int>> bookRequests = customer.requestBooks();
                cashier.sell(inventory, bookRequests);
                }
                break;
            case 3:
                manager.restock(inventory,cashier);
                break;
            case 4:
                cashier.showTotalSales();
                break;
            case 5:
                cashier.showTotalCosts();
                break;
            case 6:
                cout << "Exiting \n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
