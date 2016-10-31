//header file of TicTacToe class
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe{
    private:

        int player,
            i,
            choice,
            moves,
            newNumber,
            numPlayers;

        bool isTaken,
            blockSquare;
        char userChoice;
	    char mark;
	    char square[];

    public:
//**************************** CONSTRUCTORS ********************************
        TicTacToe();

// Precondition: Player will have chosen to play tic tac toe
// Postcondition: Will start 2 player game with board set to default values
  // ********************************************************
        void playGame();
// Precondition: Tic tac toe game will have been initialized
// Postcondition: Board will be updated every time someone makes a move
  // ********************************************************
        void board();
// Precondition: Tic tac toe game will be in progress
// Postcondition: Will check every time someone makes a move to see if somebody has won.
  // ********************************************************
        int checkwin();
// Precondition: Tic tac toe game will be in progress
// Postcondition: Will check every time someone tries to makes a move to see if the square selected has already been taken.
  // ********************************************************
        bool checkTaken(int num);
// Precondition: Computer will have attempted to take a square that is already taken
// Postcondition: Will create a new number that has not been take already
  // ********************************************************
        int newNum();
// Precondition: User will request to play against computer
// Postcondition: Will initialize a 1 player game against the computer
  // ********************************************************
        void playGame1();
// Precondition: Computer will check if opponent has two squares taken next to each other
// Postcondition: Computer will block opponent from connecting a third square.
  // ********************************************************
        void twoInRow();
// Precondition: No parameters taken
// Postcondition: Function will clear the screen
  // ********************************************************
        void clearScreen();
// Precondition: Will will have ended in win or draw
// Postcondition: Game will be re-initialized if the player wishes to play again
  // ********************************************************
        void newGame();

//**************************** MUTATORS ********************************
        int getNumPlayers(){return numPlayers;}
        void setNumPlayers(int numPlayers){this->numPlayers = numPlayers;}



};

#endif
