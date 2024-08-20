// TicTacToeClasses.cpp
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Board {
private:
    vector<char> positions;

public:
    Board() : positions(16, ' ') {}

    vector<char> getPositions() {
        return positions;
    }

    int setPosition(int position, char input) {
        if (positions[position] == ' ') {
            positions[position] = input;
            return 0;
        }
        return -1;
    }

    char determineWinner() {
        // Check rows
        for (int i = 0; i < 16; i += 4) {
            if (positions[i] != ' ' && positions[i] == positions[i + 1] && positions[i] == positions[i + 2] && positions[i] == positions[i + 3])
                return positions[i];
        }

        // Check columns
        for (int i = 0; i < 4; ++i) {
            if (positions[i] != ' ' && positions[i] == positions[i + 4] && positions[i] == positions[i + 8] && positions[i] == positions[i + 12])
                return positions[i];
        }

        // Check diagonals
        if (positions[0] != ' ' && positions[0] == positions[5] && positions[0] == positions[10] && positions[0] == positions[15])
            return positions[0];
        if (positions[3] != ' ' && positions[3] == positions[6] && positions[3] == positions[9] && positions[3] == positions[12])
            return positions[3];

        return 'z';
    }
};
