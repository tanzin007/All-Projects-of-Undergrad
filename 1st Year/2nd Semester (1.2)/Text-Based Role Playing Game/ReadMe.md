# OOP Text-Based RPG Game (C++)

A lightweight, console-based Role-Playing Game (RPG) built in C++ that demonstrates the core concepts of Object-Oriented Programming (OOP). The game features a turn-based battle system between a customizable Hero and a Dragon Boss, complete with randomized combat mechanics and strict input validation.

## 🚀 OOP Concepts Demonstrated

This project serves as a practical implementation of the four pillars of Object-Oriented Programming:

1. **Abstraction**: Internal combat logic, formula-driven damage calculations, and memory management are abstracted away inside class methods, exposing only simple interfaces like `attack()` and `specialSkill()`.
2. **Encapsulation**: Critical character data such as `health`, `name`, and `attackPower` are kept `private` within the `Character` class. Access and modifications are safely routed through public getters and setters (e.g., `reduceHealth()`).
3. **Inheritance**: The `Hero` and `Enemy` classes inherit core attributes and lifecycles from the base `Character` class, reusing code efficiently while allowing specific extensions (like `specialEnergy` for the Hero).
4. **Polymorphism**: 
   * **Method Overriding**: The `attack()` function is declared `virtual` in the base class and overridden in `Hero` and `Enemy` to output custom prefixes (`[Warrior]` / `😈 [Dragon Boss]`).
   * **Runtime Polymorphism**: The boss object is managed dynamically via a base class pointer (`Character* bossEnemy = new Enemy(...)`), resolving function calls dynamically at runtime.

---

## 🎮 Game Features

* **Turn-Based Combat**: Choose between a standard attack or a devastating special skill on your turn.
* **Randomized Damage System**: Attacks are not fixed. Normal attacks fluctuate between **80% to 120%** of base power, while Special Skills generate critical damage between **90% to 130%** of double base power.
* **Resource Management**: The Hero utilizes a `specialEnergy` system. Special moves cost **20 Energy**, preventing spamming.
* **Robust Input Validation**: The game handles improper menu selections (e.g., typing letters or out-of-bounds numbers) gracefully without crashing or entering infinite loops.
* **Memory Safe**: Implements a `virtual destructor` in the base class to guarantee clean object destruction and zero memory leaks.

---

## 🛠️ How to Compile and Run

Make sure you have a C++ compiler installed (GCC/G++, Clang, or MSVC).

### Using Terminal/Command Prompt:

1. **Clone or download** the source code into a file named `main.cpp`.
2. Open your terminal and compile the program:
   ```bash
   g++ -std=c++11 main.cpp -o RpgGame
   ```
3. Run the compiled executable:
   * **Windows**: `RpgGame.exe`
   * **Mac/Linux**: `./RpgGame`

---

## 📂 Code Structure Overview

* **`Character` (Base Class)**: Manages properties like health, name, attack power, and default attacking logic.
* **`Hero` (Derived Class)**: Adds class types, a custom status UI, and the resource-restricted `specialSkill()`.
* **`Enemy` (Derived Class)**: Implements custom threat indicators and overrides basic enemy behaviors.
* **`main()`**: Sets up the randomization seed, handles the core battle gameplay loop, validates player inputs, and displays the game outcome.
