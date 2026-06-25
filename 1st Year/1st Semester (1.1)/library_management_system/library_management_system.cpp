#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

void addBook(vector<Book>& library) {
    Book b;
    cout << "\n--- Add New Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, b.title);
    cout << "Enter Author Name: ";
    getline(cin, b.author);
    b.isIssued = false;
    
    library.push_back(b);
    cout << "\nBook added successfully!" << endl;
}

void searchBook(const vector<Book>& library) {
    int searchId;
    cout << "\n--- Search Book ---" << endl;
    cout << "Enter Book ID to search: ";
    cin >> searchId;
    
    for (const auto& b : library) {
        if (b.id == searchId) {
            cout << "\nBook Found!" << endl;
            cout << "ID: " << b.id << "\nTitle: " << b.title << "\nAuthor: " << b.author << endl;
            cout << "Status: " << (b.isIssued ? "Issued (Not Available)" : "Available") << endl;
            return;
        }
    }
    cout << "\nBook not found in the library." << endl;
}

void issueBook(vector<Book>& library) {
    int id;
    cout << "\n--- Issue Book ---" << endl;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    
    for (auto& b : library) {
        if (b.id == id) {
            if (b.isIssued) {
                cout << "\nThis book is already issued to someone else!" << endl;
            } else {
                b.isIssued = true;
                cout << "\nBook \"" << b.title << "\" has been issued successfully!" << endl;
            }
            return;
        }
    }
    cout << "\nBook not found!" << endl;
}

void returnBook(vector<Book>& library) {
    int id;
    cout << "\n--- Return Book ---" << endl;
    cout << "Enter Book ID to return: ";
    cin >> id;
    
    for (auto& b : library) {
        if (b.id == id) {
            if (!b.isIssued) {
                cout << "\nThis book was not issued!" << endl;
            } else {
                b.isIssued = false;
                cout << "\nBook \"" << b.title << "\" returned successfully!" << endl;
            }
            return;
        }
    }
    cout << "\nBook not found!" << endl;
}

void displayBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "\nNo books available in the library." << endl;
        return;
    }
    cout << "\n--- Library Inventory ---" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << setw(10) << "Book ID" << setw(20) << "Title" << setw(15) << "Author" << setw(10) << "Status" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (const auto& b : library) {
        cout << setw(10) << b.id 
             << setw(20) << b.title 
             << setw(15) << b.author 
             << setw(10) << (b.isIssued ? "Issued" : "Available") << endl;
    }
}

int main() {
    vector<Book> library;
    int choice;
    do {
        cout << "\n===============================" << endl;
        cout << "   LIBRARY MANAGEMENT SYSTEM   " << endl;
        cout << "===============================" << endl;
        cout << "1. Add New Book\n2. Search Book\n3. Issue Book\n4. Return Book\n5. Display All Books\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addBook(library); break;
            case 2: searchBook(library); break;
            case 3: issueBook(library); break;
            case 4: returnBook(library); break;
            case 5: displayBooks(library); break;
            case 6: cout << "\nExiting... All temporary library data cleared!" << endl; break;
            default: cout << "\nInvalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}