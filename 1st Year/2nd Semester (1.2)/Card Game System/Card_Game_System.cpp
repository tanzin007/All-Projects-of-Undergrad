#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Structure representing a single playing card
struct Card {
    string suit;
    string rank;
    int value;
};

// Class to manage a deck of 52 cards
class Deck {
private:
    vector<Card> cards;

public:
    Deck() {
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

        for (const auto& suit : suits) {
            for (int i = 0; i < 13; ++i) {
                cards.push_back({suit, ranks[i], values[i]});
            }
        }
    }

    void shuffleDeck() {
        random_shuffle(cards.begin(), cards.end());
    }

    Card dealCard() {
        Card topCard = cards.back();
        cards.pop_back();
        return topCard;
    }
};

// Base class for any Card Game (Abstraction & Inheritance)
class CardGame {
protected:
    Deck deck;
    string gameName;

public:
    CardGame(string name) : gameName(name) {
        deck.shuffleDeck();
    }
    virtual void play() = 0; // Pure virtual function
    virtual ~CardGame() {}
};

// Derived class specifically for Blackjack Game
class Blackjack : public CardGame {
private:
    int calculateHand(const vector<Card>& hand) {
        int total = 0;
        int aces = 0;
        for (const auto& card : hand) {
            total += card.value;
            if (card.rank == "Ace") aces++;
        }
        // Adjust Ace value from 11 to 1 if total busts 21
        while (total > 21 && aces > 0) {
            total -= 10;
            aces--;
        }
        return total;
    }

public:
    Blackjack() : CardGame("Blackjack") {}

    void play() override {
        cout << "\n--- Starting a game of " << gameName << " ---\n";
        vector<Card> playerHand, dealerHand;

        // Deal initial cards
        playerHand.push_back(deck.dealCard());
        playerHand.push_back(deck.dealCard());
        dealerHand.push_back(deck.dealCard());
        dealerHand.push_back(deck.dealCard());

        // Player's turn
        while (true) {
            int playerTotal = calculateHand(playerHand);
            cout << "\nYour cards total: " << playerTotal << "\n";
            if (playerTotal > 21) {
                cout << "💀 You Busted! Dealer wins.\n";
                return;
            }

            cout << "1. Hit (Take Card)\n2. Stand (Stop)\nEnter choice: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                playerHand.push_back(deck.dealCard());
            } else {
                break;
            }
        }

        // Dealer's turn
        int dealerTotal = calculateHand(dealerHand);
        while (dealerTotal < 17) {
            dealerHand.push_back(deck.dealCard());
            dealerTotal = calculateHand(dealerHand);
        }

        int playerFinal = calculateHand(playerHand);
        cout << "\n--- Final Results ---\n";
        cout << "Your Total: " << playerFinal << "\n";
        cout << "Dealer Total: " << dealerTotal << "\n";

        if (dealerTotal > 21 || playerFinal > dealerTotal) {
            cout << "🎉 VICTORY! You won against the dealer.\n";
        } else if (playerFinal < dealerTotal) {
            cout << "❌ Dealer wins!\n";
        } else {
            cout << "🤝 It's a Tie (Push)!\n";
        }
    }
};

int main() {
    srand(time(0));
    cout << "=======================================\n";
    cout << "      WELCOME TO THE OOP CASINO        \n";
    cout << "=======================================\n";

    CardGame* game = new Blackjack();
    game->play();

    delete game;
    return 0;
}
