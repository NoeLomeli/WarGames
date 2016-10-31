// Names: Noe Lomeli, Nancy Gomez
// Date: April - May 2016
// Project: Thermonuclear War (WarGames inspired)


#include "Map.h"
#include "thermonuclearWar.h"
#include "country.h"
#include "tictactoe.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
//#include <windows.h>
using namespace std;

void simulatingHack();

int main(){


    bool choseGame = false;
    string userSentence;
    string games[] = {"thermonuclearwar", "tictactoe", "chess"};
    clearScreen();
    system("bash -c \". line-ringing.sh\"");
    std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    cout << "LOGON: ";

    getline(cin, userSentence);
    removeSpacesAndCapitals(userSentence);


    if (userSentence == "joshua"){
        clearScreen();
        simulatingHack();
        system("bash -c \". test.sh\"");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "\nGREETINGS PROFFESSOR FALKEN. HOW ARE YOU DOING TODAY?" << endl;
        getline(cin, userSentence);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("bash -c \". playGame.sh\"");
    cout << "\nSHALL WE PLAY A GAME?" << endl;
    getline(cin, userSentence);
    removeSpacesAndCapitals(userSentence);

    while (!choseGame){
        // find the keyword "thermonuclearwar", "tictactoe", or "chess"
        if (userSentence.find(games[0]) != -1){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            system("bash -c \". excellent.sh\"");
            cout << "EXCELLENT." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            cout << "LAUNCHING THERMONUCLEAR WAR" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            choseGame = true;
            ThermonuclearWar game1;
            game1.runGame();
        }
        else if (userSentence.find(games[1]) != -1){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            system("bash -c \". excellent.sh\"");
            cout << "EXCELLENT." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            cout << "LAUNCHING TIC TAC TOE" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            choseGame = true;
            TicTacToe game2;
            game2.playGame();
        }
        else if (userSentence.find(games[2]) != -1){
            cout << "Launch CHESS" << endl;
            choseGame = true;
            //Chess game3;
            //game3.runGame();
        }
        else{
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            cout << "We should play a game I know. Like ThermonuclearWar, Tic Tac Toe, or Chess.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            getline(cin, userSentence);
            removeSpacesAndCapitals(userSentence);
        }
    }



    return 0;
}
void simulatingHack(){
    // I need to adjust how it prints in the terminal, also need to add the other screens that are printed


    clearScreen();
    std::this_thread::sleep_for(std::chrono::milliseconds(550));
    system("bash -c \". hack1sound.sh\"");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("bash -c \". hack1.sh\"");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    clearScreen();
    system("bash -c \". hack2.sh\"");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    clearScreen();
    system("bash -c \". hack3.sh\"");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    clearScreen();
    system("bash -c \". hack4.sh\"");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    clearScreen();
    system("bash -c \". hack5.sh\"");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    clearScreen();
    system("bash -c \". hack6.sh\"");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";

    clearScreen();






    // first screen (at top)
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "045    11456          11809       11893       11972        11315\n" << flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "PRT CON. 3.4.5. SECTION 9.4.3                 PORT STAT: SD-345 \n" << flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\n(311) 835-7385\n" << flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    // cout short highlighted block

    cout << '\r';
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "NEW!" << flush;
    clearScreen();
    // second screen (at bottom)
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    cout << "(311) 938-3582\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    cout << string(45, '\n');
    clearScreen();

    // third screen (middle) (type in increments)

    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "(311) 757-8739\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "(311) 936-2364\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-      PRT. STRT.                                      CRT. DEF.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "      ==========================================================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "F91150: SUSDKJ: SDF JSL:                           DKSJL: SKFJJ: SDKFJLJ:  \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "SYSPROC FUNCT READY                            ALT NET READY\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "CPU AUTH RY-345-AX3        SYSCOMP STATUS:  ALL PORTS ACTIVE\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "22/34534.90/3209                                       11CVB-3904-39490\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "(311) 936-2364\n";
    // cout << long highlited block
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "(311) 938-3582\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "EE/74534.90/3289                                       11CVB-3904-39490\n";

    clearScreen();

    // fourth screen

    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "12354-40-49KJ: CONTR PAK\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "(311) 787-1183\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "   FLB: 33.34.543   HPBS: 34/56/67/83/  STATUS FLT  034/384\n";
    clearScreen();

    //fifth screen
    //cout << short highlighted block
    //cout << ""




    // I want to have this appear very briefly

    cout << "H   H EEEEE L     L      OOO       W   W  OOO  RRRR  L     DDDD   !!\n"
         << "H   H E     L     L     O   O      W W W O   O R   R L     D   D  !!\n"
         << "HHHHH EEEEE L     L     O   O      W W W O   O RRRR  L     D   D  !!\n"
         << "H   H E     L     L     O   O  ,,   W W  O   O R   R L     D   D    \n"
         << "H   H EEEEE LLLLL LLLLL  OOO  ,,    W W   OOO  R   R LLLLL DDDD   !!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    clearScreen();

}



//************ copy this line below to run the program in the terminal **************
//  g++ -std=c++11 country.h country.cpp thermonuclearWar.h thermonuclearWar.cpp
// Map.h Map.cpp tictactoe.h tictactoe.cpp driver.cpp
