// Author : Mohammed Hisham Moizuddin | CS-141 SUMMER 2020
// Prog5Battleship.cpp
// Play a simplified version of battleship board game.
// Program: #5, Battleship using classes

#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//###################################################################################

class Board    //Class "Board" to encapsulate board data
{          
    public:                            //public member function declarations
        void setEmptyPiecesInBoards();
        void readAndSetShipCoordinates(int &totalShips);
        void displayPlayerView();
        void displayOriginalView();
        void doAttack(int row, int column, int totalShips, int &numShipsHit, int &numRemainingTurns);
    private:                           //private data members
        char playerView[10][10];
        char originalView[10][10];
};

//###################################################################################

void Board::setEmptyPiecesInBoards(){ //member function for setting empty pieces
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){  //loops through rows and columns to set it to 'o'
            playerView[i][j] = 'o';
            originalView[i][j] = 'o';
        }
    }
}

//###################################################################################

void Board::displayPlayerView(){       //member function to view Player board
    cout << endl;
    cout << "        Player view" << endl;
    cout << "    0 1 2 3 4 5 6 7 8 9   " << endl;
    cout << "  |---------------------| " << endl;
    cout << "A | " << playerView[0][0] << " " << playerView[0][1] << " " << playerView[0][2] << " " << playerView[0][3] << " " << playerView[0][4] << " " << playerView[0][5] << " " << playerView[0][6] << " " << playerView[0][7] << " " << playerView[0][8] << " " << playerView[0][9] << " |" << endl;
    cout << "B | " << playerView[1][0] << " " << playerView[1][1] << " " << playerView[1][2] << " " << playerView[1][3] << " " << playerView[1][4] << " " << playerView[1][5] << " " << playerView[1][6] << " " << playerView[1][7] << " " << playerView[1][8] << " " << playerView[1][9] << " |" << endl;
    cout << "C | " << playerView[2][0] << " " << playerView[2][1] << " " << playerView[2][2] << " " << playerView[2][3] << " " << playerView[2][4] << " " << playerView[2][5] << " " << playerView[2][6] << " " << playerView[2][7] << " " << playerView[2][8] << " " << playerView[2][9] << " |" << endl;
    cout << "D | " << playerView[3][0] << " " << playerView[3][1] << " " << playerView[3][2] << " " << playerView[3][3] << " " << playerView[3][4] << " " << playerView[3][5] << " " << playerView[3][6] << " " << playerView[3][7] << " " << playerView[3][8] << " " << playerView[3][9] << " |" << endl;
    cout << "E | " << playerView[4][0] << " " << playerView[4][1] << " " << playerView[4][2] << " " << playerView[4][3] << " " << playerView[4][4] << " " << playerView[4][5] << " " << playerView[4][6] << " " << playerView[4][7] << " " << playerView[4][8] << " " << playerView[4][9] << " |" << endl;
    cout << "F | " << playerView[5][0] << " " << playerView[5][1] << " " << playerView[5][2] << " " << playerView[5][3] << " " << playerView[5][4] << " " << playerView[5][5] << " " << playerView[5][6] << " " << playerView[5][7] << " " << playerView[5][8] << " " << playerView[5][9] << " |" << endl;
    cout << "G | " << playerView[6][0] << " " << playerView[6][1] << " " << playerView[6][2] << " " << playerView[6][3] << " " << playerView[6][4] << " " << playerView[6][5] << " " << playerView[6][6] << " " << playerView[6][7] << " " << playerView[6][8] << " " << playerView[6][9] << " |" << endl;
    cout << "H | " << playerView[7][0] << " " << playerView[7][1] << " " << playerView[7][2] << " " << playerView[7][3] << " " << playerView[7][4] << " " << playerView[7][5] << " " << playerView[7][6] << " " << playerView[7][7] << " " << playerView[7][8] << " " << playerView[7][9] << " |" << endl;
    cout << "I | " << playerView[8][0] << " " << playerView[8][1] << " " << playerView[8][2] << " " << playerView[8][3] << " " << playerView[8][4] << " " << playerView[8][5] << " " << playerView[8][6] << " " << playerView[8][7] << " " << playerView[8][8] << " " << playerView[8][9] << " |" << endl;
    cout << "J | " << playerView[9][0] << " " << playerView[9][1] << " " << playerView[9][2] << " " << playerView[9][3] << " " << playerView[9][4] << " " << playerView[9][5] << " " << playerView[9][6] << " " << playerView[9][7] << " " << playerView[9][8] << " " << playerView[9][9] << " |" << endl;
    cout << "  |---------------------| " << endl;
}

//###################################################################################

void Board::displayOriginalView()  ////member function to view original board
{
    cout << endl;
    cout << "        Original view" << endl;
    cout << "    0 1 2 3 4 5 6 7 8 9   " << endl;
    cout << "  |---------------------| " << endl;
    cout << "A | " << originalView[0][0] << " " << originalView[0][1] << " " << originalView[0][2] << " " << originalView[0][3] << " " << originalView[0][4] << " " << originalView[0][5] << " " << originalView[0][6] << " " << originalView[0][7] << " " << originalView[0][8] << " " << originalView[0][9] << " |" << endl;
    cout << "B | " << originalView[1][0] << " " << originalView[1][1] << " " << originalView[1][2] << " " << originalView[1][3] << " " << originalView[1][4] << " " << originalView[1][5] << " " << originalView[1][6] << " " << originalView[1][7] << " " << originalView[1][8] << " " << originalView[1][9] << " |" << endl;
    cout << "C | " << originalView[2][0] << " " << originalView[2][1] << " " << originalView[2][2] << " " << originalView[2][3] << " " << originalView[2][4] << " " << originalView[2][5] << " " << originalView[2][6] << " " << originalView[2][7] << " " << originalView[2][8] << " " << originalView[2][9] << " |" << endl;
    cout << "D | " << originalView[3][0] << " " << originalView[3][1] << " " << originalView[3][2] << " " << originalView[3][3] << " " << originalView[3][4] << " " << originalView[3][5] << " " << originalView[3][6] << " " << originalView[3][7] << " " << originalView[3][8] << " " << originalView[3][9] << " |" << endl;
    cout << "E | " << originalView[4][0] << " " << originalView[4][1] << " " << originalView[4][2] << " " << originalView[4][3] << " " << originalView[4][4] << " " << originalView[4][5] << " " << originalView[4][6] << " " << originalView[4][7] << " " << originalView[4][8] << " " << originalView[4][9] << " |" << endl;
    cout << "F | " << originalView[5][0] << " " << originalView[5][1] << " " << originalView[5][2] << " " << originalView[5][3] << " " << originalView[5][4] << " " << originalView[5][5] << " " << originalView[5][6] << " " << originalView[5][7] << " " << originalView[5][8] << " " << originalView[5][9] << " |" << endl;
    cout << "G | " << originalView[6][0] << " " << originalView[6][1] << " " << originalView[6][2] << " " << originalView[6][3] << " " << originalView[6][4] << " " << originalView[6][5] << " " << originalView[6][6] << " " << originalView[6][7] << " " << originalView[6][8] << " " << originalView[6][9] << " |" << endl;
    cout << "H | " << originalView[7][0] << " " << originalView[7][1] << " " << originalView[7][2] << " " << originalView[7][3] << " " << originalView[7][4] << " " << originalView[7][5] << " " << originalView[7][6] << " " << originalView[7][7] << " " << originalView[7][8] << " " << originalView[7][9] << " |" << endl;
    cout << "I | " << originalView[8][0] << " " << originalView[8][1] << " " << originalView[8][2] << " " << originalView[8][3] << " " << originalView[8][4] << " " << originalView[8][5] << " " << originalView[8][6] << " " << originalView[8][7] << " " << originalView[8][8] << " " << originalView[8][9] << " |" << endl;
    cout << "J | " << originalView[9][0] << " " << originalView[9][1] << " " << originalView[9][2] << " " << originalView[9][3] << " " << originalView[9][4] << " " << originalView[9][5] << " " << originalView[9][6] << " " << originalView[9][7] << " " << originalView[9][8] << " " << originalView[9][9] << " |" << endl;
    cout << "  |---------------------| " << endl;
}

//###################################################################################
 
void Board::readAndSetShipCoordinates(int &totalShips){   //member function to read data from text file and set ship coordinates 
    cout << "Reading ships and coordinates" << endl; 
    cout << "you can't place more than 8 ships on a board" << endl;
    cout << "Reading each ship coordinates:" << endl;

    char row;
    int column;
    ifstream inputStream;   //declaring file input stream to store data from shipData.txt
    inputStream.open("shipData.txt");
    inputStream >> totalShips;  
    while (inputStream >> row >> column){
        originalView[row - 'A'][column] = 'S';
    }

    inputStream.close();
}

//###################################################################################

void Board::doAttack(int row, int column, int totalShips, int &numShipsHit, int &numRemainingTurns){  //member function to attack
    if (originalView[row][column] == 'S'){  // condition to check if ship is already hit
        cout << "You have hit a ship!" << endl;
        originalView[row][column] = 'H';
        playerView[row][column] = 'H';
        numShipsHit++;
        numRemainingTurns = (totalShips - numShipsHit) * 3;
    }
    else if (originalView[row][column] == 'H'){   // condition to check if ship is sunk
        cout << "You already sunk this ship, try again!" << endl;
        numRemainingTurns--;
    }
    else if (originalView[row][column] == 'M'){  // condition to check if location is missed
        cout << "You have already missed this location, try again!" << endl;
        numRemainingTurns--;
    }
    else{
        cout << "You have missed!" << endl;  
        originalView[row][column] = 'M';
        playerView[row][column] = 'M';
        numRemainingTurns--;
    }
}

//###################################################################################

int getRandomNumber(){   // function to generate random numbers
    int random = rand() % 10;
    return random;
}

void displayInstructions()  //function to display instructions
{
    cout << "\n"
         << "Welcome to the game of Battleship. \n"
         << "                                                                 \n"
         << "You can choose to play this game or let the computer play.       \n"
         << "You will have a 10 x 10 board and up to 8 ships in any round.    \n"
         << "You can request to view the original board containing ship       \n"
         << "coordinates up to 3 times.                                       \n"
         << "                                                                 \n"
         << "Choose coordinates and attack the ships. You have 3 guesses for  \n"
         << "each ship. Successfully destroy all ships to win the game.       \n"
         << "                                                                 \n"
         << "                                                                 \n"
         << "For each attack provide two inputs:                              \n"
         << "   row (A-J), column (0-9)                                       \n" << endl;
} // end displayInstructions()

//-------------------------------------------------------------------------------------
int main() {
    Board theBoard;            // Create the board as an instance of the Board class
    int column, totalShips, numShipsHit = 0, originalViewDisplayCount = 0, numRemainingTurns, rowDigit;
    char showOriginalView, userOrComputer, row;
    bool checkValidCoordinates = false;
    displayInstructions();     // Display game instructinos
    theBoard.setEmptyPiecesInBoards();
    theBoard.readAndSetShipCoordinates(totalShips);
    numRemainingTurns = (totalShips - numShipsHit) * 3;
    cout << "View the original board?";
    cin >> showOriginalView;
    cin.get();
    cout << endl;
    if (toupper(showOriginalView) == 'Y'){
        theBoard.displayOriginalView();
        originalViewDisplayCount++;
    }
    theBoard.displayPlayerView();

    cout << "Do you want to play?";
    cin >> userOrComputer;
    cin.get();
    cout << endl;

    switch(toupper(userOrComputer)){         
        case 'Y':
            while(true){
                if (numShipsHit == totalShips){
                    cout << "Congratulations! You won!" << endl;
                    cout << "Thanks for playing.  Exiting... " << endl;
                    exit(0);
                }
                if (numRemainingTurns <= 0){
                    break;
                }
                if (!checkValidCoordinates){
                    cout << "Enter the coordinate for attack" << endl;
                }

                cin >> row;
                if (toupper(row) != 'X'){
                    cin >> column;
                }
                else {
                    cout << "Exiting program..." << endl;
                    exit(0);
                }

                rowDigit = toupper(row) - 'A';

                if (column > 9 || column < 0 || rowDigit < 0 || rowDigit > 9){
                    cout << "Invalid coordinates. Please try again!" << endl;
                    checkValidCoordinates = true;
                    continue;
                }
                else{checkValidCoordinates = false;}

                theBoard.doAttack(rowDigit, column, totalShips, numShipsHit, numRemainingTurns);
                if(originalViewDisplayCount < 3){
                    cout << "View the original board?";
                    cin >> showOriginalView;
                    cin.get();
                    cout << endl;
                    if (toupper(showOriginalView) == 'Y'){
                        theBoard.displayOriginalView();
                        originalViewDisplayCount++;
                    }
                }
                theBoard.displayPlayerView();
                // numRemainingTurns--;
            }
            break;

        case 'N':
            srand(time(0));
            while(true){
                if (numShipsHit == totalShips){
                    cout << "Congratulations! You won!" << endl;
                    cout << "Thanks for playing.  Exiting... " << endl;
                    exit(-1);
                }
                if (numRemainingTurns <= 0){
                    break;
                }
                int randomRow = getRandomNumber();
                int randomColumn = getRandomNumber();
                theBoard.doAttack(randomRow, randomColumn, totalShips, numShipsHit, numRemainingTurns);
                theBoard.displayPlayerView();
                // numRemainingTurns--;
            }
            break;

        case 'X':
            cout << "Exiting program..." << endl;
            exit(0);
            break;
    }
    cout << "Sorry! You ran out of turns." << endl;
    cout << "Thanks for playing.  Exiting... " << endl;
    return 0;
} // end main()
