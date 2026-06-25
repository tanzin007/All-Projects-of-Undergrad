# OOP Tic-Tac-Toe Game (C++)

A console-based 3x3 Tic-Tac-Toe game built in C++ that showcases the power of Object-Oriented Programming (OOP) by creating a Human vs. AI match.

## 🚀 OOP Concepts Used

1. **Abstraction**: The complex layout of the 3x3 grid, row/column boundaries, and win-checking logic are hidden inside the `Board` class methods, offering a clean interface to players.
2. **Encapsulation**: The game grid is stored as a private vector. It cannot be modified directly from outside, ensuring data integrity through the `makeMove()` method.
3. **Inheritance**: A generic `Player` base class handles common details like name and symbol. The specific player types (`HumanPlayer` and `AIPlayer`) inherit from this base class.
4. **Polymorphism**: The `getMove()` function is a pure virtual function in the base class. It is overridden differently by `HumanPlayer` (takes manual input) and `AIPlayer` (calculates a random move dynamically at runtime).

## 🎮 Features
* **Human vs AI Gameplay**: Play against a fully automated computer bot.
* **Input Protection**: Prevents entering duplicate positions or letters.
* **Smart Turn Switching**: Uses runtime polymorphic pointers to swap players smoothly.
