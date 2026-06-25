#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Base Class representing a general Vehicle
class Vehicle {
private:
    string registrationNumber;
    string model;
    double baseRatePerDay;

public:
    Vehicle(string reg, string mdl, double rate) 
        : registrationNumber(reg), model(mdl), baseRatePerDay(rate) {}

    string getModel() const { return model; }
    string getRegNum() const { return registrationNumber; }
    double getBaseRate() const { return baseRatePerDay; }

    // Virtual function to calculate dynamic rent price based on vehicle type
    virtual double calculateRent(int days) const {
        return baseRatePerDay * days;
    }

    virtual void displayDetails() const {
        cout << "Reg: " << registrationNumber << " | Model: " << model << " | Base Rate: $" << baseRatePerDay << "/day";
    }

    virtual ~Vehicle() {}
};

// Derived class for Car (Adds extra luxury tax)
class Car : public Vehicle {
public:
    Car(string reg, string mdl, double rate) : Vehicle(reg, mdl, rate) {}

    double calculateRent(int days) const override {
        // Cars have a flat $10 service fee included
        return (getBaseRate() * days) + 10.0;
    }

    void displayDetails() const override {
        cout << "[Car] ";
        Vehicle::displayDetails();
        cout << " (+$10 Service Fee)";
    }
};

// Derived class for Bike (Cheaper long term discount)
class Bike : public Vehicle {
public:
    Bike(string reg, string mdl, double rate) : Vehicle(reg, mdl, rate) {}

    double calculateRent(int days) const override {
        // 10% Discount if rented for more than 3 days
        double total = getBaseRate() * days;
        if (days > 3) {
            total *= 0.90;
        }
        return total;
    }

    void displayDetails() const override {
        cout << "[Bike] ";
        Vehicle::displayDetails();
        cout << " (10% off if > 3 days)";
    }
};

// Derived class for Truck (Heavy vehicle cargo tax)
class Truck : public Vehicle {
public:
    Truck(string reg, string mdl, double rate) : Vehicle(reg, mdl, rate) {}

    double calculateRent(int days) const override {
        // Trucks have an extra weight/cargo tax of $30 per day
        return (getBaseRate() + 30.0) * days;
    }

    void displayDetails() const override {
        cout << "[Truck] ";
        Vehicle::displayDetails();
        cout << " (+$30/day Cargo Tax)";
    }
};

int main() {
    // Creating an inventory of different vehicles using Base Class Pointers
    vector<Vehicle*> fleet;
    fleet.push_back(new Car("CAR-101", "Tesla Model 3", 50.0));
    fleet.push_back(new Bike("BIKE-202", "Yamaha R1", 25.0));
    fleet.push_back(new Truck("TRUCK-303", "Volvo FH16", 120.0));

    cout << "=======================================\n";
    cout << "     VEHICLE RENTAL SYSTEM (OOP)       \n";
    cout << "=======================================\n";
    
    cout << "Available Fleet in our Garage:\n";
    for (size_t i = 0; i < fleet.size(); ++i) {
        cout << i + 1 << ". ";
        fleet[i]->displayDetails();
        cout << "\n";
    }

    int choice, days;
    cout << "\nSelect a vehicle to rent (1-3): ";
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "❌ Invalid choice! Select between 1 and 3: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter number of days for rent: ";
    while (!(cin >> days) || days <= 0) {
        cout << "❌ Invalid days! Enter a positive number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Dynamic binding/Polymorphism in action
    Vehicle* selectedVehicle = fleet[choice - 1];
    double totalCost = selectedVehicle->calculateRent(days);

    cout << "\n=======================================\n";
    cout << "             RENTAL INVOICE            \n";
    cout << "=======================================\n";
    cout << "Vehicle Model : " << selectedVehicle->getModel() << "\n";
    cout << "Reg Number    : " << selectedVehicle->getRegNum() << "\n";
    cout << "Rental Period : " << days << " Days\n";
    cout << "---------------------------------------\n";
    cout << "Total Amount  : $" << fixed << setprecision(2) << totalCost << "\n";
    cout << "=======================================\n";

    // Clean up dynamic allocations
    for (auto v : fleet) {
        delete v;
    }

    return 0;
}
