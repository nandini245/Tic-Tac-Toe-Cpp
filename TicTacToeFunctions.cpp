// TicTacToeFunctions.cpp
#include <iostream>
#include <limits>
using namespace std;

void getUserNames(string &userX, string &userO) {
    cout << "Name of user to be 'x': ";
    cin >> userX;
    cout << "Name of user to be 'o': ";
    cin >> userO;
}

void printBlankBoard() {
    for (int i = 0; i < 16; i++) {
        cout << "|" << i << ":";
        if (i <= 9)
            cout << " ";
        if (i % 4 == 3)
            cout << "|\n";
    }
    cout << "\n\n\n";
}

void printTheBoard(Board boardIn) {
    for (int i = 0; i < 16; i++) {
        cout << "|" << boardIn.getPositions()[i];
        if (i % 4 == 3)
            cout << "|\n";
    }
    cout << "\n\n\n";
}

void writeTheBoard(Board boardIn) {
    for (int i = 0; i < 16; i++) {
        cout << "|" << boardIn.getPositions()[i];
        if (i % 4 == 3)
            cout << "|\n";
    }
    cout << "\n\n\n";
}

void printUserPrompt(string nameIn, char letter) {
    cout << nameIn << ", where would you like to place an " << letter << "?: ";
}

void printGameWinner(Board boardIn, string nameX, string nameO) {
    char winner = boardIn.determineWinner();
    if (winner == 'x') {
        cout << "Congrats " << nameX << ", you won!\n\n";
    } else if (winner == 'o') {
        cout << "Congrats " << nameO << ", you won!\n\n";
    } else {
        cout << "It's a tie!\n\n";
    }
}

int getUserResponse() {
    int position = -1;
    cout << "Enter an integer between 0 and 15: ";
    cin >> position;
    
    while (position > 15 || position < 0 || !cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That is not a valid position. Enter an integer between 0 and 15: ";
        cin >> position;
    }
    return position;
}

void checkResponse(Board &boardIn, char input) {
    int position;
    int userInput;
    do {
        position = getUserResponse();
        userInput = boardIn.setPosition(position, input);
        if (userInput == -1) {
            cout << "That position is taken.\n";
        }
    } while (userInput == -1);
}
