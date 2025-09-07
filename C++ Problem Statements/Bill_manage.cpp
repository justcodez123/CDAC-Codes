/*
    "Smart Billing System for a Tech Store"
🎯 Objective:
Design a C++ program to manage customer purchases in a tech store, including item management, billing, and persistent record-keeping.

📌 Requirements:
1. OOP Design
Create a class Item with attributes:

itemID, itemName, price, stockQuantity

Create a class Bill with:

billID, customerName, list of purchased items

2. Operator Overloading
Overload + to add an item to the bill

Overload << to display the bill details

3. Exception Handling
Throw exceptions for:

Negative price or quantity

Attempt to purchase more than available stock

Empty bill generation

4. File Handling
Save all bills to bills.txt

Load previous bills at startup

Append new bills without overwriting
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>

using namespace std;

class Item {
    int itemID;
    string itemName;
    double price;
    int stockQuantity;

    friend class Bill;
    public:
    Item(int id, string name, double p, int qty){
        if(p < 0 || qty < 0) 
            throw invalid_argument("Price and quantity must be non-negative.");
        itemID = id;
        itemName = name;
        price = p;
        stockQuantity = qty;
    }
};

class Bill {
    int billID;
    string customerName;
    string* purchasedItems = new string[100]; // assuming max 100 items
    int itemCount = 0;
    double totalAmount = 0.0;
    
    public:
    Bill(int id, string name) {
        billID = id;
        customerName = name;
        if(name.empty()) 
            throw invalid_argument("Customer name cannot be empty.");
        if(id <= 0) 
            throw invalid_argument("Bill ID must be positive.");
    }

    Bill& operator+(const Item& item) {
        if(itemCount >= 100) 
            throw overflow_error("Cannot add more items to the bill.");
        purchasedItems[itemCount++] = item.itemName;
        totalAmount += item.price;
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const Bill& bill){
        os << "Bill ID: " << bill.billID << "\n";
        os << "Customer Name: " << bill.customerName << "\n";
        os << "Purchased Items:\n";
        for(int i = 0; i < bill.itemCount; ++i) {
            os << " - " << bill.purchasedItems[i] << "\n";
        }
        os << "Total Amount: " << bill.totalAmount << "\n";
        return os;
    }

    void saveToFile(const string& filename) {
        if(itemCount == 0) 
            throw runtime_error("Cannot save an empty bill.");
        ofstream file;
        file.open(filename, ios::app);
        if(!file) 
            throw runtime_error("Could not open file for writing.");
        file << *this;
        file.close();
    }

    void loadPreviousBills(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "No previous bills file found. A new one will be created." << endl;
            return;
        }

        cout << "--- Loading All Previous Bills ---" << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        cout << "--- End of Previous Bills ---\n" << endl;
        file.close();
    }

    void purchaseItem(Bill& bill, Item& item) {
        if (item.stockQuantity <= 0) {
            throw runtime_error("Purchase failed: " + item.itemName + " is out of stock.");
        }
        bill = bill + item; // Use the existing operator+
        item.stockQuantity--; // Update stock after a successful purchase
        cout << "Added " << item.itemName << " to the bill." << endl;
    }

};

int main() {
    try {
        Bill bill(1, "John Doe");
        bill.loadPreviousBills("bills.txt");

        Item laptop(101, "Laptop", 999.99, 10);
        Item smartphone(102, "Smartphone", 499.99, 5);
        Item tablet(103, "Tablet", 299.99, 0); // Out of stock

        bill.purchaseItem(bill, laptop);
        bill.purchaseItem(bill, smartphone);
        bill.purchaseItem(bill, tablet);
        
        // Attempt to purchase an out-of-stock item
        try {
            bill.purchaseItem(bill, tablet);
        } catch (const exception& e) {
            cerr << e.what() << endl;
        }

        cout << bill;

        bill.saveToFile("bills.txt");
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}