#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Item {
    int id;
    string name;
    double price;
    int quantity;
};

void addItem(vector<Item>& store) {
    Item itm;
    cout << "\n--- Add Product to Inventory ---" << endl;
    cout << "Enter Product ID: ";
    cin >> itm.id;
    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, itm.name);
    cout << "Enter Price per Unit: $";
    cin >> itm.price;
    cout << "Enter Stock Quantity: ";
    cin >> itm.quantity;
    
    store.push_back(itm);
    cout << "\nProduct successfully added to inventory!" << endl;
}

void displayInventory(const vector<Item>& store) {
    if (store.empty()) {
        cout << "\nInventory is empty!" << endl;
        return;
    }
    cout << "\n--- Current Store Inventory ---" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << setw(10) << "Item ID" << setw(20) << "Product Name" << setw(12) << "Price" << setw(10) << "Stock" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (const auto& itm : store) {
        cout << setw(10) << itm.id 
             << setw(20) << itm.name 
             << setw(12) << fixed << setprecision(2) << itm.price 
             << setw(10) << itm.quantity << endl;
    }
}

void generateBill(vector<Item>& store) {
    int searchId, buyQty;
    cout << "\n--- Generate Customer Bill ---" << endl;
    cout << "Enter Product ID to purchase: ";
    cin >> searchId;
    
    for (auto& itm : store) {
        if (itm.id == searchId) {
            cout << "Product Found: " << itm.name << " | Available Stock: " << itm.quantity << endl;
            cout << "Enter Quantity to buy: ";
            cin >> buyQty;
            
            if (buyQty > itm.quantity) {
                cout << "\nError: Not enough stock available!" << endl;
            } else if (buyQty <= 0) {
                cout << "\nInvalid quantity!" << endl;
            } else {
                itm.quantity -= buyQty; 
                double totalBill = buyQty * itm.price;
                cout << "\n=================================" << endl;
                cout << "         CUSTOMER INVOICE        " << endl;
                cout << "=================================" << endl;
                cout << "Item: " << itm.name << endl;
                cout << "Quantity: " << buyQty << endl;
                cout << "Price per Unit: $" << itm.price << endl;
                cout << "---------------------------------" << endl;
                cout << "Total Amount Due: $" << fixed << setprecision(2) << totalBill << endl;
                cout << "=================================" << endl;
            }
            return;
        }
    }
    cout << "\nProduct not found in inventory!" << endl;
}

int main() {
    vector<Item> store;
    int choice;
    do {
        cout << "\n=================================" << endl;
        cout << "   DEPARTMENTAL STORE UTILITY   " << endl;
        cout << "=================================" << endl;
        cout << "1. Add New Product\n2. View Stock Inventory\n3. Sell Product (Bill Generate)\n4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        // ভুল ইনপুট হ্যান্ডলিং (অক্ষর টাইপ করলে ক্র্যাশ রোধ করবে)
        if (!(cin >> choice)) {
            cout << "\nInvalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        switch(choice) {
            case 1: addItem(store); break;
            case 2: displayInventory(store); break;
            case 3: generateBill(store); break;
            case 4: cout << "\nClosing Store Utility... Temporary inventory wiped!" << endl; break;
            default: cout << "\nInvalid choice! Choose between 1 and 4." << endl;
        }
    } while (choice != 4);
    return 0;
}
