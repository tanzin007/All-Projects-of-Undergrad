#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Account {
    int accountNumber;
    string name;
    double balance;
};

// Function Prototype
void createAccount();
void depositMoney();
void withdrawMoney();
void searchAccount();
void displayAllAccounts();

int main() {
    int choice;
    do {
        cout << "\n=================================" << endl;
        cout << "    ROBUST BANKING SYSTEM        " << endl;
        cout << "=================================" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Search/Retrieve Account" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Enter your choice (1-6): ";
        
        if (!(cin >> choice)) {
            cout << "\nInvalid input! Numbers only." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: searchAccount(); break;
            case 5: displayAllAccounts(); break;
            case 6: cout << "\nThank you for using our Banking System!" << endl; break;
            default: cout << "\nInvalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

// 1. Create New Account
void createAccount() {
    Account acc;
    cout << "\n--- Create New Account ---" << endl;
    cout << "Enter Account Number: ";
    cin >> acc.accountNumber;
    cin.ignore();
    cout << "Enter Account Holder Name: ";
    getline(cin, acc.name);
    cout << "Enter Initial Deposit Amount: $";
    cin >> acc.balance;

    // ios::app ব্যবহার করায় আগের ডেটা মুছবে না, নিচে নতুন ডেটা যোগ হবে
    ofstream outFile("bank_database.txt", ios::app);
    if (outFile.is_open()) {
        outFile << acc.accountNumber << endl;
        outFile << acc.name << endl;
        outFile << acc.balance << endl;
        outFile.close();
        cout << "\nAccount created and securely saved to database!" << endl;
    } else {
        cout << "\nDatabase Error: Could not save data!" << endl;
    }
}

// 2. Search Account
void searchAccount() {
    int searchNum;
    cout << "\n--- Retrieve Account Details ---" << endl;
    cout << "Enter Account Number to Search: ";
    cin >> searchNum;

    ifstream inFile("bank_database.txt");
    Account acc;
    bool found = false;

    if (inFile.is_open()) {
        // untill the file is completely searched
        while (inFile >> acc.accountNumber) {
            inFile.ignore();
            getline(inFile, acc.name);
            inFile >> acc.balance;

            if (acc.accountNumber == searchNum) {
                cout << "\n[Account Found]" << endl;
                cout << "Account Number : " << acc.accountNumber << endl;
                cout << "Holder Name    : " << acc.name << endl;
                cout << "Current Balance: $" << fixed << setprecision(2) << acc.balance << endl;
                found = true;
                break;
            }
        }
        inFile.close();
        if (!found) cout << "\nError: Account number " << searchNum << " not found!" << endl;
    } else {
        cout << "\nNo database found. Create an account first." << endl;
    }
}

// 3. Deposite Money
void depositMoney() {
    int searchNum;
    double amount;
    cout << "\n--- Deposit Money ---" << endl;
    cout << "Enter Account Number: ";
    cin >> searchNum;

    ifstream inFile("bank_database.txt");
    vector<Account> accountList;
    Account acc;
    bool found = false;

    if (inFile.is_open()) {
        while (inFile >> acc.accountNumber) {
            inFile.ignore();
            getline(inFile, acc.name);
            inFile >> acc.balance;

            if (acc.accountNumber == searchNum) {
                cout << "Enter amount to deposit: $";
                cin >> amount;
                if (amount > 0) {
                    acc.balance += amount;
                    found = true;
                    cout << "\n$" << amount << " deposited successfully!" << endl;
                } else {
                    cout << "\nInvalid amount!" << endl;
                }
            }
            accountList.push_back(acc);
        }
        inFile.close();

        // data update and modify
        if (found) {
            ofstream outFile("bank_database.txt");
            for (const auto& a : accountList) {
                outFile << a.accountNumber << endl;
                outFile << a.name << endl;
                outFile << a.balance << endl;
            }
            outFile.close();
        } else {
            cout << "\nAccount not found!" << endl;
        }
    }
}

// 4. Withdraw Money
void withdrawMoney() {
    int searchNum;
    double amount;
    cout << "\n--- Withdraw Money ---" << endl;
    cout << "Enter Account Number: ";
    cin >> searchNum;

    ifstream inFile("bank_database.txt");
    vector<Account> accountList;
    Account acc;
    bool found = false;

    if (inFile.is_open()) {
        while (inFile >> acc.accountNumber) {
            inFile.ignore();
            getline(inFile, acc.name);
            inFile >> acc.balance;

            if (acc.accountNumber == searchNum) {
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (amount > acc.balance) {
                    cout << "\nError: Insufficient balance!" << endl;
                } else if (amount > 0) {
                    acc.balance -= amount;
                    found = true;
                    cout << "\n$" << amount << " withdrawn successfully!" << endl;
                }
            }
            accountList.push_back(acc);
        }
        inFile.close();

        if (found) {
            ofstream outFile("bank_database.txt");
            for (const auto& a : accountList) {
                outFile << a.accountNumber << endl;
                outFile << a.name << endl;
                outFile << a.balance << endl;
            }
            outFile.close();
        } else {
            cout << "\nAccount not found!" << endl;
        }
    }
}

// 5. List of all accounts
void displayAllAccounts() {
    ifstream inFile("bank_database.txt");
    Account acc;
    cout << "\n--- All Bank Accounts ---" << endl;
    cout << "-----------------------------------------" << endl;
    cout << setw(10) << "Acc No" << setw(20) << "Name" << setw(12) << "Balance" << endl;
    cout << "-----------------------------------------" << endl;

    if (inFile.is_open()) {
        while (inFile >> acc.accountNumber) {
            inFile.ignore();
            getline(inFile, acc.name);
            inFile >> acc.balance;
            cout << setw(10) << acc.accountNumber 
                 << setw(20) << acc.name 
                 << setw(12) << fixed << setprecision(2) << acc.balance << endl;
        }
        inFile.close();
    } else {
        cout << "No accounts registered yet." << endl;
    }
}
