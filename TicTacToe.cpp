#include <iostream>
using namespace std;

// Array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// Variable Declaration
int choice;
int row, column;
char currentPlayer = 'X';
bool draw = false;

// Function to display the current state of the board
void displayBoard() {
    cout << "TIC-TAC-TOE GAME\n\n";
    cout << "Player 1 [X] - Player 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n";
}

// Function to get player input and update the board
void playerTurn() {
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    // Validate input
    while (choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O') {
        cout << "Invalid move. Please choose an available position (1-9): ";
        cin >> choice;
    }

    row = (choice - 1) / 3;
    column = (choice - 1) % 3;

    board[row][column] = currentPlayer;

    // Switch to the other player
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // If there is an empty space, the game is not a draw
            }
        }
    }
    return true; // All spaces are filled, indicating a draw
}

// Function to reset the game board
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + i * 3 + j; // Fill the board with initial values
        }
    }
    currentPlayer = 'X';
    draw = false;
}

int main() {
    char playAgain;

    do {
        resetBoard();

        while (!checkWin() && !checkDraw()) {
            displayBoard();
            playerTurn();
        }

        displayBoard();

        if (checkWin()) {
            cout << "\nPlayer " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!\n";
        } else {
            cout << "\nThe game is a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}
