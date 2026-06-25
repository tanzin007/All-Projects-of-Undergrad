#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Class to manage the 3x3 game board
class Board {
private:
    vector<vector<char>> grid;

public:
    Board() {
        grid = vector<vector<char>>(3, vector<char>(3, ' '));
    }

    void display() const {
        cout << "\n  0   1   2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << grid[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "  ---------\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col, char symbol) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
            grid[row][col] = symbol;
            return true;
        }
        return false;
    }

    bool checkWin(char symbol) const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
                (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol))
                return true;
        }
        // Check diagonals
        if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
            (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol))
            return true;

        return false;
    }

    bool isFull() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == ' ') return false;
            }
        }
        return true;
    }

    const vector<vector<char>>& getGrid() const { return grid; }
};

// Base class for a Player (Demonstrating Inheritance & Polymorphism)
class Player {
protected:
    string name;
    char symbol;

public:
    Player(string n, char s) : name(n), symbol(s) {}
    string getName() const { return name; }
    char getSymbol() const { return symbol; }

    // Pure virtual function for Polymorphism
    virtual void getMove(const Board& board, int& row, int& col) = 0;
    virtual ~Player() {}
};

// Derived class for a Human Player
class HumanPlayer : public Player {
public:
    HumanPlayer(string n, char s) : Player(n, s) {}

    void getMove(const Board& board, int& row, int& col) override {
        cout << name << " (" << symbol << "), enter your move (row and column 0-2): ";
        while (!(cin >> row >> col) || row < 0 || row > 2 || col < 0 || col > 2 || board.getGrid()[row][col] != ' ') {
            cout << "❌ Invalid move! Try again (row and col 0-2): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
};

// Derived class for an AI Player (Simple Random Bot)
class AIPlayer : public Player {
public:
    AIPlayer(string n, char s) : Player(n, s) {}

    void getMove(const Board& board, int& row, int& col) override {
        cout << name << " (" << symbol << ") is thinking...\n";
        while (true) {
            row = rand() % 3;
            col = rand() % 3;
            if (board.getGrid()[row][col] == ' ') {
                break; // Found a valid random move
            }
        }
        cout << name << " placed on row " << row << ", column " << col << ".\n";
    }
};

int main() {
    srand(time(0));
    cout << "=======================================\n";
    cout << "        OOP TIC-TAC-TOE GAME           \n";
    cout << "=======================================\n";

    string humanName;
    cout << "Enter your Name: ";
    cin >> humanName;

    Board board;
    Player* p1 = new HumanPlayer(humanName, 'X');
    Player* p2 = new AIPlayer("Smart Bot", 'O');

    Player* currentPlayer = p1;
    board.display();

    while (true) {
        int row, col;
        currentPlayer->getMove(board, row, col);
        board.makeMove(row, col, currentPlayer->getSymbol());
        board.display();

        if (board.checkWin(currentPlayer->getSymbol())) {
            cout << "🎉 " << currentPlayer->getName() << " wins the game!\n";
            break;
        }
        if (board.isFull()) {
            cout << "🤝 It's a draw game!\n";
            break;
        }

        // Switch turn using Polymorphic pointers
        currentPlayer = (currentPlayer == p1) ? p2 : p1;
    }

    delete p1;
    delete p2;
    return 0;
}
