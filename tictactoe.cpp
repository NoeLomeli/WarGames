#include "tictactoe.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <ctime>
#include <cstdlib>


#include <cstdlib>

using namespace std;

TicTacToe::TicTacToe()
{
    //moves = 0;
    int num;
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    isTaken = false;
    blockSquare = true;
    cout << "HOW MANY PLAYERS? (1 OR 2) ";
    cin >> num;
    setNumPlayers(num);
    if(getNumPlayers() == 2)
    	playGame();
    else
    	playGame1();
}
// Two player game
void TicTacToe::playGame()
{
    int player = 1;

	do
	{

		board();
		player=(player%2)?1:2; // Each player will take a turn

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();

		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	return;
}

void TicTacToe::board()
{
    clearScreen();

	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

void TicTacToe::newGame()
{

    i = -1;
    //moves = 0;
    int num;
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    isTaken = false;
    blockSquare = true;
    cout << "HOW MANY PLAYERS? (1 OR 2) ";
    cin >> num;
    setNumPlayers(num);
    if(getNumPlayers() == 2)
    	playGame();
    else
    	playGame1();
}

int TicTacToe::checkwin()
{
    // This checks to see if anyone connected three in a row
    if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'  //This will result in a draw
			&& square[4] != '4' && square[5] != '5' && square[6] != '6'
			&& square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}





void TicTacToe::clearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );

}
// Two player game
void TicTacToe::playGame1()
{
	cin.ignore();
	std::this_thread::sleep_for(std::chrono::milliseconds(550));
	player = 1;
	moves = 0;
	int randSquare = 0;
	do
	{

		board();
		if(player%2)
  			player=1;
		else
  			player=2;

		cout << "ENTER NUMBER 1-9 TO MAKE A MOVE:  ";
		cin >> choice;

		mark= 'X';

		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
    system("bash -c \". cross.sh\"");
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
		board();
		i=checkwin();
		if(i==1)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
	        cout << "CONGRATULATIONS!" << endl;
	        std::this_thread::sleep_for(std::chrono::milliseconds(150));
	        cout << "PLAY AGAIN? (Y/N)" << endl;
	        cin >> userChoice;
	        if (toupper(userChoice) == 'Y')
	        {
	        	newGame();
	        }
	        else if(toupper(userChoice) == 'N')
	            return;
	        else
     		cout << "INVALID INPUT" << endl;
		}
		if(i == 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
			cout<<"==>\aWE HAVE TIED\n";
	        std::this_thread::sleep_for(std::chrono::milliseconds(150));
	        cout << "PLAY AGAIN? (Y/N)" << endl;
	        cin >> userChoice;
	        if (toupper(userChoice) == 'Y')
	        {
	            newGame();

	        }
	        else if (toupper(userChoice) == 'N')
	          cout << "GOODBYE PROFESSOR FALKEN" << endl;
	       else
     		cout << "INVALID INPUT" << endl;
		}

		player++;
		moves++;

		if(moves == 1)
		{
			if(square[1] == 'X' || square[3] == 'X' || square[7] == 'X' || square[9] == 'X') // if player chooses a corner square
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE CENTER SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[5] = 'O';
				moves++;
			}
			else if(square[5] == 'X')
			{

    		do
    		{
    			srand(time(0));
    			randSquare = (rand() % 9) + 1;
    		}while(randSquare%2 == 0);  // while loop will run until an odd number is created

    		if (randSquare == 1)
    		{
    			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			    cout << "I PICK THE TOP LEFT SQUARE" << endl;
			    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			    square[1] = 'O';
			    moves++;
    		}
    		if (randSquare == 3)
    		{
    			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
					cout << "I PICK THE TOP RIGHT SQUARE" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(1500));
					square[3] = 'O';
					moves++;
    		}
    		if (randSquare == 7)
    		{
    			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
					cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(1500));
					square[7] = 'O';
					moves++;
    		}
    		if (randSquare == 9)
    		{
    			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
					cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(1500));
					square[9] = 'O';
					moves++;
    		}

			}
			else
			{    // the following conditions will check to see if user selected an edge on the board
				if(square[2] == 'X')
				{
					do
	        		{
	        			srand(time(0));
	        			randSquare = (rand() % 3) + 1;
	        		}while(randSquare%2 == 0);
	        		if (randSquare == 1)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE TOP LEFT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[1] = 'O';
						moves++;
	        		}
	        		if (randSquare == 3)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE TOP RIGHT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[3] = 'O';
						moves++;
	        		}
				}
	        	else if(square[4] == 'X')
	        	{
	        		do
	        		{
	        			srand(time(0));
	        			randSquare = (rand() % 7) + 1;
	        		}while((randSquare != 1) && (randSquare != 7));
	        		if (randSquare == 1)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE TOP LEFT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[1] = 'O';
						moves++;
	        		}
	        		if (randSquare == 7)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[7] = 'O';
						moves++;
	        		}
	        	}
	        	else if(square[6] == 'X')
				{
					do
	        		{
	        			srand(time(0));
	        			randSquare = (rand() % 9) + 1;
	        		}while(randSquare != 3 && randSquare != 9);
	        		if (randSquare == 3)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE TOP RIGHT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[3] = 'O';
						moves++;
	        		}
	        		if (randSquare == 9)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[9] = 'O';
						moves++;
	        		}
				}
				else if(square[8] == 'X')
				{
					do
					{
						srand(time(0));
	        			randSquare = (rand() % 7) + 1;
	        		}while(randSquare != 7 && randSquare != 9);
	        		if (randSquare == 7)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[7] = 'O';
						moves++;
	        		}
	        		if (randSquare == 9)
	        		{
	        			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						square[9] = 'O';
						moves++;
	        		}
				}
			}
		}
		if(moves == 3 && player == 2)
		{
			if(square[5] != '5')
			{
				twoInRow();
				moves--;
			}

			else if(square[5] == '5')
			{

				square[5] = 'O';
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE CENTER SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				moves--;

			}



				// when these squares are taken the computer needs to create a new random number that has not been taken
			else if((square[1] != '1' && square[5] != '5' && square[9] != '9') || (square[3] != '3' && square[5] != '5' && square[7] != '7'))
			{

				square[newNum()] = 'O';

			}
			else
				square[newNum()] = 'O';



		}
		if(moves > 3 && player == 2)
		{


			if(square[1] == 'O' && square[2] == 'O' && square[3] == '3')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE TOP RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[3] = 'O';
				moves++;

			}
			else if(square[2] == 'O' && square[3] == 'O' && square[1] == '1')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE TOP LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[1] = 'O';
				moves++;
			}
			else if(square[1] == 'O' && square[4] == 'O' && square[7] == '7')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[7] = 'O';
				moves++;

			}
			else if(square[4] == 'O' && square[7] == 'O' && square[1] == '1')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE TOP LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[1] = 'O';
				moves++;
			}
			else if(square[7] == 'O' && square[8] == 'O' && square[9] == '9')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[9] = 'O';
				moves++;
			}
			else if(square[8] == 'O' && square[9] == 'O' && square[7] == '7')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[7] = 'O';
				moves++;

			}
			else if(square[3] == 'O' && square[6] == 'O' && square[9] == '9')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[9] = 'O';
				moves++;

			}
			else if(square[6] == 'O' && square[9] == 'O' && square[3] == '3')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE TOP RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[3] = 'O';
				moves++;
			}
			else if(square[1] == 'O' && square[5] == 'O' && square[9] == '9')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[9] = 'O';
				moves++;
			}
			else if(square[5] == 'O' && square[9] == 'O' && square[1] == '1')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE TOP LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[1] = 'O';
				moves++;
			}
			else if(square[3] == 'O' && square[5] == 'O' && square[7] == '7')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[7] = 'O';
				moves++;
			}
			if(square[5] == 'O' && square[7] == 'O' && square[3] == '3')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE TOP RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[3] = 'O';

				moves++;
			}
			else if(square[2] == 'O' && square[5] == 'O' && square[8] == '8')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MID BOTTOM SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[8] = 'O';
				moves++;
			}
			else if(square[5] == 'O' && square[8] == 'O' && square[2] == '2')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MID TOP SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[2] = 'O';

				moves++;


			}
			else if(square[4] == 'O' && square[5] == 'O' && square[6] == '6')
			{

				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MID RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[6] = 'O';

				moves++;


			}
			else if(square[5] == 'O' && square[6] == 'O' && square[4] == '4')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MIDDLE LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[4] = 'O';

				moves++;
			}
			else if(square[1] == 'O' && square[3] == 'O' && square[2] == '2')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MID TOP SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[2] = 'O';

				moves++;

			}
			else if(square[1] == 'O' && square[7] == 'O' && square[4] == '4')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MIDDLE LEFT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[4] = 'O';
				moves++;
			}
			else if(square[7] == 'O' && square[9] == 'O' && square[8] == '8')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MID BOTTOM SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[8] = 'O';

				moves++;
			}
			else if(square[3] == 'O' && square[9] == 'O' && square[6] == '6')
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE MID RIGHT SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				square[6] = 'O';

				moves++;

			}

			else if(square[5] != '5')
			{
				twoInRow();
				moves--;
			}
			else if(square[5] != '5')
				{
					twoInRow();
					moves++;
					//break;

				}
			else if((square[1] != '1' && square[5] != '5' && square[9] != '9') || (square[3] != '3' && square[5] != '5' && square[7] != '7'))
					square[newNum()] = 'O';
			else
			{
				square[5] = 'O';
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "I PICK THE CENTER SQUARE" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				moves++;
			}
		//	else
		//		square[newNum()] = 'O';






		}
		i=checkwin();
		player++;
    system("bash -c \". circle.sh\"");
	}while(i==-1);

  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  board();

	if(i==1)
	{
		if(player == 1)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
	        cout << "CONGRATULATIONS" << endl;
	        std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
	        cout << "I WIN" << endl;
	        std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
        cout << "PLAY AGAIN? (Y/N)" << endl;
        cin >> userChoice;
        if (toupper(userChoice) == 'Y')
        {
            newGame();

        }
        else if (toupper(userChoice) == 'N')
          cout << "GOODBYE PROFESSOR FALKEN" << endl;
        else
     		cout << "INVALID INPUT" << endl;
	}
	if(i == 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		cout<<"==>\aWE HAVE TIED\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
         cout << "PLAY AGAIN? (Y/N)" << endl;
        cin >> userChoice;
        if (toupper(userChoice) == 'Y')
        {
            newGame();

        }
        else if (toupper(userChoice) == 'N')
          cout << "GOODBYE PROFESSOR FALKEN" << endl;
     	else
     		cout << "INVALID INPUT" << endl;


		//return;
	}
	cin.ignore();
	cin.get();
	return;
}

bool TicTacToe::checkTaken(int num)
{
	if(square[num]  == '1' || square[num]  == '2' || square[num]  == '3' ||
	   square[num]  == '4' || square[num]  == '5' ||square[num]  == '6' ||
	   square[num]  == '7' ||square[num]  == '8' ||square[num]  == '9')
	{
		isTaken = false;
	}
	else
		isTaken = true;
	return isTaken;
}

int TicTacToe::newNum()
{


		if(moves == 3)
		{
			cout << "I AM THINKING...PROFESSOR" << endl;
			srand(time(0));
			do
			{


				newNumber = (rand() % 9) + 1;
			}while((newNumber % 2) != 0 && moves < 4);
			//return newNumber; // computer needs to pick an edge
				//player = 2;
		}
		else
		{
			do
			{
				srand(time(0));
				newNumber = (rand() % 9) + 1;
			}while(checkTaken(newNumber));
			//player = 2;
		}

	return newNumber;

}

void TicTacToe::twoInRow()
{

	if(square[1] == 'X' && square[2] == 'X' && square[3] == '3')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE TOP RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[3] = 'O';
		moves++;
	}
	else if(square[2] == 'X' && square[3] == 'X' && square[1] == '1')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE TOP LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[1] = 'O';
		moves++;
	}
	else if(square[1] == 'X' && square[3] == 'X' && square[2] == '2')
   {

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MID TOP SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[2] = 'O';
		moves++;
	}
	else if(square[3] == 'X' && square[6] == 'X' && square[9] == '9')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[9] = 'O';
		moves++;
	}
	else if(square[9] == 'X' && square[6] == 'X' && square[3] == '3')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE TOP RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[3] = 'O';
		moves++;
	}
	else if(square[9] == 'X' && square[3] == 'X' && square[6] == '6')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MID RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[6] = 'O';
		moves++;
	}
	else if(square[7] == 'X' && square[8] == 'X' && square[9] == '9')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[9] = 'O';
		moves++;
	}
	else if(square[9] == 'X' && square[8] == 'X' && square[7] == '7')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[7] = 'O';
		moves++;
	}
	else if(square[7] == 'X' && square[9] == 'X' && square[8] == '8')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MID BOTTOM SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[8] = 'O';
		moves++;
	}
	else if(square[1] == 'X' && square[4] == 'X' && square[7] == '7')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[7] = 'O';
		moves++;
	}
	else if(square[7] == 'X' && square[4] == 'X' && square[1] == '1')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE TOP LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[1] = 'O';
		moves++;
	}
	else if(square[1] == 'X' && square[7] == 'X' && square[4] == '4')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MIDDLE LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[4] = 'O';
		moves++;
	}
	else if(square[1] == 'X' && square[5] == 'X' && square[9] == '9')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE BOTTOM RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[9] = 'O';
		moves++;
	}
	else if(square[9] == 'X' && square[5] == 'X' && square[1] == '1')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE TOP LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[1] = 'O';
		moves++;
	}
	else if(square[1] == 'X' && square[9] == 'X' && square[5] == '5')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE CENTER SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[5] = 'O';
		moves++;
	}
	else if(square[3] == 'X' && square[5] == 'X' && square[7] == '7')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE BOTTOM LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[7] = 'O';
		moves++;
	}
	else if(square[7] == 'X' && square[5] == 'X' && square[3] == '3')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE TOP RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[3] = 'O';
		moves++;
	}
	else if(square[7] == 'X' && square[3] == 'X' && square[5] == '5')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE CENTER SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[5] = 'O';
		moves++;
	}
	else if(square[2] == 'X' && square[5] == 'X' && square[8] == '8')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MID BOTTOM SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[8] = 'O';
		moves++;
	}

	else if(square[8] == 'X' && square[5] == 'X' && square[2] == '2')
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MID TOP SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[2] = 'O';
	}
	else if(square[2] == 'X' && square[8] == 'X' && square[5] == '5')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE CENTER SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[5] = 'O';
	}
	else if(square[4] == 'X' && square[5] == 'X' && square[6] == '6')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MID RIGHT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[6] = 'O';
		moves++;
	}

	else if(square[5] == 'X' && square[6] == 'X' && square[4] == '4')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE MIDDLE LEFT SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[4] = 'O';
		moves++;
	}
	else if(square[4] == 'X' && square[6] == 'X' && square[5] == '5')
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "I PICK THE CENTER SQUARE" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		square[5] = 'O';
		moves++;
	}
	else
		square[newNum()] = 'O';

	return;
}
