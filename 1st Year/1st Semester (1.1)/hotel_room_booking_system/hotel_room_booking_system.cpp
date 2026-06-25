#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Room {
    int roomNumber;
    string guestName;
    bool isBooked;
};

void checkAvailability(const vector<Room>& rooms) {
    cout << "\n--- Room Availability Status ---" << endl;
    cout << "---------------------------------" << endl;
    cout << setw(10) << "Room No" << setw(15) << "Status" << setw(15) << "Guest Name" << endl;
    cout << "---------------------------------" << endl;
    for (const auto& r : rooms) {
        cout << setw(10) << r.roomNumber 
             << setw(15) << (r.isBooked ? "Booked" : "Available") 
             << setw(15) << (r.isBooked ? r.guestName : "---") << endl;
    }
}

void bookRoom(vector<Room>& rooms) {
    int roomNum;
    cout << "\n--- Book a Room ---" << endl;
    cout << "Enter Room Number (1-10): ";
    cin >> roomNum;
    
    if (roomNum < 1 || roomNum > 10) {
        cout << "\nInvalid Room Number! We only have rooms 1 to 10." << endl;
        return;
    }
    
    if (rooms[roomNum - 1].isBooked) {
        cout << "\nSorry, Room " << roomNum << " is already occupied by " << rooms[roomNum - 1].guestName << "!" << endl;
    } else {
        cin.ignore();
        cout << "Enter Guest Name: ";
        getline(cin, rooms[roomNum - 1].guestName);
        rooms[roomNum - 1].isBooked = true;
        cout << "\nRoom " << roomNum << " successfully booked for " << rooms[roomNum - 1].guestName << "!" << endl;
    }
}

void checkOutRoom(vector<Room>& rooms) {
    int roomNum;
    cout << "\n--- Checkout Room ---" << endl;
    cout << "Enter Room Number to Checkout: ";
    cin >> roomNum;
    
    if (roomNum < 1 || roomNum > 10) {
        cout << "\nInvalid Room Number!" << endl;
        return;
    }
    
    if (!rooms[roomNum - 1].isBooked) {
        cout << "\nRoom " << roomNum << " is already vacant/empty." << endl;
    } else {
        cout << "\nGuest " << rooms[roomNum - 1].guestName << " successfully checked out of Room " << roomNum << "!" << endl;
        rooms[roomNum - 1].guestName = "";
        rooms[roomNum - 1].isBooked = false;
    }
}

int main() {
    // 10 empty rooms
    vector<Room> rooms(10);
    for (int i = 0; i < 10; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].guestName = "";
        rooms[i].isBooked = false;
    }
    
    int choice;
    do {
        cout << "\n=================================" << endl;
        cout << "    HOTEL ROOM BOOKING SYSTEM    " << endl;
        cout << "=================================" << endl;
        cout << "1. Check Room Availability\n2. Book a Room\n3. Checkout / Vacate Room\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: checkAvailability(rooms); break;
            case 2: bookRoom(rooms); break;
            case 3: checkOutRoom(rooms); break;
            case 4: cout << "\nExiting System... All booking records reset!" << endl; break;
            default: cout << "\nInvalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}
