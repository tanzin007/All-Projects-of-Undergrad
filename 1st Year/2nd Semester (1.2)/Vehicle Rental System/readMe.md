# OOP Vehicle Rental System (C++)

A real-world commercial simulation of a garage rental system built in C++ that automates vehicle tracking and custom invoice billing based on different vehicle categories.

## 🚀 OOP Concepts Used

1. **Abstraction**: Hides core financial calculations and technical registration details from the `main()` interface, exposing only `calculateRent()` and `displayDetails()`.
2. **Encapsulation**: Variables like `registrationNumber` and `baseRatePerDay` are locked as private data fields. They can only be read through controlled public getter methods.
3. **Inheritance**: A main `Vehicle` class acts as the parent. Specialized child classes like `Car`, `Bike`, and `Truck` reuse this structure while adding custom pricing multipliers.
4. **Polymorphism**: Demonstrates **Runtime Polymorphism** via Virtual Functions. The `calculateRent()` function changes behavior dynamically based on whether a Car pointer, Bike pointer, or Truck pointer is invoked.

## 📊 Features & Custom Pricing Rules
* **Car Class**: Adds a flat **$10 Luxury Service Fee** to the final bill.
* **Bike Class**: Includes a long-term budget discount of **10% off** if rented for more than 3 days.
* **Truck Class**: Adds a heavy-duty **$30 per day Cargo Tax** due to weight management.
* **Memory Management**: Uses an array of base pointers and carefully cleans up dynamic heap memories at the end using `delete` loops to maintain zero leaks.
