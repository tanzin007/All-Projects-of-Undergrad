# OOP Casino - Blackjack Simulator (C++)

A terminal-based Casino Card Game System implemented in C++ focusing on a fully functional, automated dealer Blackjack game.

## 🚀 OOP Concepts Used

1. **Abstraction**: The mechanics of a 52-card standard deck, shuffling processes, and shifting Ace values (11 or 1) are handled internally by the classes.
2. **Encapsulation**: The card structures and the vector holding the remaining cards are kept secure inside the `Deck` class, accessible only through the public `dealCard()` function.
3. **Inheritance**: Features a generic `CardGame` base class which serves as a blueprint for casino games. The `Blackjack` class inherits from it, allowing scalable expansions for other games like Poker or Baccarat in the future.
4. **Polymorphism**: The `play()` function is declared as a pure virtual function inside the base class and overridden with specific Blackjack rules in the child class.

## 🎮 Features
* **Standard 52-Card Deck**: Built with proper suits, ranks, and values.
* **True Shuffling**: Implements `random_shuffle` to ensure fair and unrepeatable card sequences every round.
* **Dynamic Hand Calculation**: Automatically decreases the value of an Ace from 11 to 1 if the player or dealer is about to bust (go over 21).
