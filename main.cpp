// main.cpp
// A basic Tic Tac Toe Game Written in C++ Language
// compile this three files at the same time "main.cpp", "TicTacToeClasses.cpp", "TicTacToeFunctions.cpp"
#include "TicTacToeClasses.cpp"
#include "TicTacToeFunctions.cpp"

int main()
{
    Board gameBoard;
    string nameX;
    string nameO;
    
    int tieGame = 0;
    char gameWinner = 'z';
    int numTurns = 0;
    
    //get the names of the players
    getUserNames(nameX, nameO);
    
    //the game is played for 8 turns maximum
    while(numTurns < 16) // Correction to match 4x4 board's max turn count
    {
        //print a board that has the postions numbered
        printTheBoard(gameBoard);
        //ask player x where they want to put an 'x'
        printUserPrompt(nameX, 'x');
        //check that the input is a valid position and that
        //it has not already been taken
        checkResponse(gameBoard, 'x');
        //check to see if player 'x' has four in a row somewhere on the board
        gameWinner = gameBoard.determineWinner();
        
        //if player 'x' has won, end the game
        if(gameWinner != 'z')
        {
            printTheBoard(gameBoard);
            writeTheBoard(gameBoard);
            printGameWinner(gameBoard, nameX, nameO);
            break;
        }
        //Now do the same for player 'o'
        //print a board that has the postions numbered
        printTheBoard(gameBoard);
        writeTheBoard(gameBoard);
        //ask player o where they want to put an 'o'
        printUserPrompt(nameO, 'o');
        //check that the input is a valid position and that
        //it has not already been taken
        checkResponse(gameBoard, 'o');

        printTheBoard(gameBoard);
        writeTheBoard(gameBoard);
        //check to see if player 'o' has four in a row somewhere on the board
        gameWinner = gameBoard.determineWinner();
        //if player 'o' has won, end the game
        if(gameWinner != 'z')
        {
            printTheBoard(gameBoard);
            writeTheBoard(gameBoard);
            printGameWinner(gameBoard, nameX, nameO);
            break;
        }
        numTurns++;
    }
    //if there is no winner at this point, the game is a tie
    if(numTurns >= 16)
        cout<<"Tie game.\n\n";
    return 0;
}
