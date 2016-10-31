//implemetation of ThermonuclearWar


#include "thermonuclearWar.h"
#include "Map.h"
#include "tictactoe.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

ThermonuclearWar :: ThermonuclearWar(){
    newGame();
}
//**************************** METHODS *************************************
void ThermonuclearWar :: newGame(){

    // Setting the two countries depending on who the user wants to be
    char userChoice;


    system("bash -c \". defcon1.sh\"");
    std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("bash -c \". screenRender.sh\"");

    clearScreen();
    map1.displayBoard();
    system("bash -c \". screenRender.sh\"");
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    system("bash -c \". side.sh\"");
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\nWHICH SIDE DO YOU WANT?" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\n\t1. UNITED STATES" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\t2. SOVIET UNION" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\n PLEASE CHOOSE ONE: ";

    cin >> userChoice;


    // ERROR CHECK
    while (userChoice != '1' && userChoice != '2'){

      system("bash -c \". alarm.sh\"");
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Invalid input, enter \'1\' or \'2\': ";
        cin >> userChoice;
    }

    if (userChoice == '1'){

        userCountry.setAll("United States");
        cpuCountry.setAll("Soviet Union");
        clearScreen();
    }
    else if (userChoice == '2'){

        userCountry.setAll("Soviet Union");
        cpuCountry.setAll("United States");
        clearScreen();
    }


}
void ThermonuclearWar :: runGame(){
    string userSentence;
    int randDamage;
    int nukeDamage;
    int cpuChoice;

    // as long as the user has not won nor lost, keep the game running
    char userChoice;
    while (!didWin() && !didLose()){

        // Displaying the damage for each of the countries
        if (userCountry.getCountryName() == "United States"){
            clearScreen();
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
            system("bash -c \". screenRender.sh\"");

            map1.displayCountry('1');

            map1.displayDamageUS(userCountry.getDefenses());
            map1.displayDamageUSSR(cpuCountry.getDefenses());
        }
        else{
            clearScreen();
            system("bash -c \". screenRender.sh\"");

            map1.displayCountry('2');
            map1.displayDamageUS(cpuCountry.getDefenses());
            map1.displayDamageUSSR(userCountry.getDefenses());
        }

        // the damage of the missile/air strike is a random # from 100-200
        srand(time(0));
        randDamage = (rand() % 100) + 100;

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        cout << "\n*************** ATTACK OPTIONS **************\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        cout << "Q - Send Air Strike\tW - Send Missile\nE - Try to get Nuke\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        cout << "\n*************** SUPPLY OPTIONS **************\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        cout << "1 - Check Supply\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));

        cout << "\n*************** GAME OPTIONS **************\n";
        cout << "X - Surrender/Exit\tS - Switch Game\n\nENTER: ";
        cin >> userChoice;
        userChoice = toupper(userChoice);

    // ------- THESE ARE THE USER'S MOVES ----------
        while (userChoice == '1'){
            checkSupply();
            cout << "\nNext Move: ";
            cin >> userChoice;
            userChoice = toupper(userChoice);
        }
        while (userChoice != 'Q' && userChoice != 'W' && userChoice != 'E' &&
               userChoice != '1' && userChoice != 'X' && userChoice != 'S'){
            clearScreen();
            system("bash -c \". alarm.sh\"");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            cout << "Invalid! Enter Q, W, E, 1, X, or S: ";
            cin >> userChoice;
            userChoice = toupper(userChoice);\

        }

        switch (userChoice){
            case 'Q':

                clearScreen();
                userCountry.decreaseAirStrikes();
                cpuCountry.gotAttacked(randDamage);
                system("bash -c \". bombers.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(6000));
                cout << "\nYOU SENT OUT AN AIR STRIKE. YOU DEALT " << randDamage;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                cout << " DAMAGE.\nMY DEFENSES ARE: " << cpuCountry.getDefenses() << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));

                displayAirStrike();

                break;

            case 'W':

                clearScreen();
                userCountry.decreaseMissiles();
                cpuCountry.gotAttacked(randDamage);
                system("bash -c \". authentication.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                cout << "\nYOU SENT OUT A MISSILE. YOU DEALT " << randDamage;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                cout << " DAMAGE.\nMY DEFENSES ARE NOW " << cpuCountry.getDefenses() << endl;

                displayMissile();

                break;

            case 'E':

                clearScreen();
                std::this_thread::sleep_for(std::chrono::milliseconds(150));

                nukeDamage = (rand() % 100) + 300; // between 300 - 400

                userCountry.setHasGottenNuke(getNuke(false));

                if (userCountry.getHasGottenNuke()){
                    clearScreen();
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

                    cout << "\nYOU SENT OUT A NUKE! YOU DEALT " << nukeDamage << endl;
                    cpuCountry.gotAttacked(nukeDamage);
                    std::this_thread::sleep_for(std::chrono::milliseconds(150));
                    cout << " DAMAGE.\nMY DEFENSES ARE: " << cpuCountry.getDefenses() << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

                    displayNuke();
                }
                else
                    cout << "YOU FAILED AT OBTAINING A NUKE.\n\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                break;

            case 'X':

                userCountry.setHasSurrendered(true);
                break;

            case 'S':

                cout << "WHAT GAME WOULD YOU LIKE TO PLAY?" << endl;
                cin.ignore();
                getline(cin, userSentence);
                switchGame(userSentence);
                break;

            default:
                system("bash -c \". alarm.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
                cout << "INVALID INPUT!" << endl;
                break;
        }// end user switch


        // check to see if the user won, because if they did then the cpu doesn't get a turn
        if (didWin() || didLose())
            break;


    // ------- THESE ARE THE CPU'S MOVES ------ //
        randDamage = (rand() % 100) + 100;
        cpuChoice = (rand() % 3) + 1;

        switch (cpuChoice){
            case 1:

                cpuCountry.decreaseAirStrikes();
                userCountry.gotAttacked(randDamage);
                system("bash -c \". alarm.sh\"");

                cout << "\nI SENT OUT AN AIR STRIKE. I DEALT " << randDamage;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                cout << " DAMAGE.\nYOUR DEFENSES ARE: " << userCountry.getDefenses() << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(8000));

                displayAirStrike();
                break;

            case 2:

                cpuCountry.decreaseMissiles();
                userCountry.gotAttacked(randDamage);
                system("bash -c \". alarm.sh\"");

                cout << "\nI SENT OUT A MISSILE. I DEALT " << randDamage;
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
                cout << " DAMAGE.\nYOUR DEFENSES ARE: " << userCountry.getDefenses() << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(8000));

                displayMissile();

                break;

            case 3:
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                system("bash -c \". alarm.sh\"");
                cout << "\n\nI ATTEMPTED TO GET A NUKE!" << endl;
                nukeDamage = (rand() % 100) + 300; // between 300 - 400
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                cpuCountry.setHasGottenNuke(getNuke(true));

                if (cpuCountry.getHasGottenNuke()){

                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    system("bash -c \". alarm.sh\"");
                    cout << "\nI SENT OUT A NUKE! I DEALT " << nukeDamage;
                    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                    userCountry.gotAttacked(nukeDamage);
                    std::this_thread::sleep_for(std::chrono::milliseconds(150));
                    cout << " DAMAGE.\nYOUR DEFENSES ARE: " << userCountry.getDefenses() << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(6000));

                    displayNuke();
                }
                else{
                    cout << "I FAILED AT OBTAINING THE NUKE.\n\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                }
                break;

        }//end cpu switch
    }
    checkEndGame();
}
bool ThermonuclearWar :: didLose(){
    return (userCountry.getDefenses() == 0 ||
            userCountry.getHasSurrendered() == true);
}
void ThermonuclearWar :: checkEndGame(){

    char choice;

    if (didWin())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        cout << "CONGRATULATIONS!\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("bash -c \". winning.sh\"");
        cout << "            ***                  ***           " << endl
             << "           *****                *****          " << endl
             << "           *****                *****          " << endl
             << "            ***                  ***           " << endl
             << " ***                                        ***" << endl
             << "  ***                                      *** " << endl
             << "   ***                                    ***  " << endl
             << "    ***                                  ***   " << endl
             << "      ***                              ***     " << endl
             << "        ***                          ***       " << endl
             << "          ***                      ***         " << endl
             << "             **********************            " << endl
             << "                 ****************              " << endl;

    }
    else if (didLose())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        cout << "YOU LOSE!" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("bash -c \". winning.sh\"");

        cout << "            ***                  ***           " << endl
             << "           *****                *****          " << endl
             << "           *****                *****          " << endl
             << "            ***                  ***           " << endl
             << "                                               " << endl
             << "                ****************               " << endl
             << "             **********************            " << endl
             << "          ***                      ***         " << endl
             << "        ***                          ***       " << endl
             << "      ***                              ***     " << endl
             << "    ***                                  ***   " << endl
             << "   ***                                    ***  " << endl
             << "  ***                                      *** " << endl
             << " ***                                        ***" << endl;

    }
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
        cout << "\n\nPLAY AGAIN? (Y/N)" << endl;
        cin >> choice;
        //ERROR CHECK
        while (toupper(choice) != 'N' && toupper(choice) != 'Y'){
                system("bash -c \". alarm.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                cout << "Invalid! Enter Y or N : ";
                cin >> choice;
        }
        if (toupper(choice) == 'Y'){
            newGame();
            runGame();
        }
        else if (toupper(choice) == 'N')
            return;
    return;
}

bool ThermonuclearWar :: getNuke(bool cpuChoseThis){

    // this will be the random key that is generated
    srand(time(0));
    int randKey = (rand() % 100) + 1;
    char newChar;

    // this is the list of random messages that can be encrypted
    string decrypted[9] = {"One minute and thirty seconds to impact.",
                           "Launch order confirmed.",
                           "People sometimes make mistakes.",
                           "DEFCON 1.",
                           "This corn is raw!",
                           "Hey, I don't believe that any system is totally secure.",
                           "Get the ICBMs in the bullpen warmed up and ready to fly.",
                           "What you see on these screens up here is a fantasy; a computer enhanced hallucination!",
                           "Have you ever heard of the word \"tumulus?\""};

    // this will choose a random message from the array
    int randMessage = (rand() % 9);

    // Here we will store the decrypted/ encrypted messages
    string encryptedMessage = "",
           decryptedMessage = "";


    // This is for user interface
    if (!cpuChoseThis){
        int numOfTries = 0,
            guess;
            system("bash -c \". launchCodes.sh\"");
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
         cout << "=============================================================" << endl
              << "YOU MUST DECRYPT A MESSAGE IN ORDER TO GAIN ACCESS TO A NUKE.\n\n";

        // encrypt the randomly chosen messages with the random key
        encryptMessage(decrypted[randMessage], encryptedMessage, randKey);

        // HERE WE ASK THE USER TO DECRYPT THE MESSAGE
        cout << "GUESS A NUMBER BETWEEN 1 AND 100 TO DECRYPT:\n";
        cout << "\033[1;31m" << encryptedMessage << "\033[0m" << endl;  //makes it red

        while (numOfTries < 5){
            cout << "GUESS: ";
            cin >> guess;

            //decrypt the encrypted message based on the guess
            decryptMessage(decryptedMessage, encryptedMessage, guess);

            cout << "DECRYPTED MESSAGE BASED ON YOUR GUESS:\n";
            cout << "\033[1;34m" <<  decryptedMessage << "\033[0m" << endl;  //makes it blue

            // resetting the decrypted message
            decryptedMessage = "";

            if (guess > randKey){
              system("bash -c \". keypad.sh\"");
              std::this_thread::sleep_for(std::chrono::milliseconds(4000));
              cout << "YOUR GUESS IS TOO HIGH!\n\n";
              std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }

            else if (guess < randKey){
              system("bash -c \". keypad.sh\"");
              std::this_thread::sleep_for(std::chrono::milliseconds(4000));
              cout << "YOUR GUESS IS TOO LOW!\n\n";
              std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }

            if (guess == randKey){
                system("bash -c \". target.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                cout << "YOU HACKED THE MESSAGE!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(4000));
                return true;
            }

            numOfTries++;
        }
        system("bash -c \". target.sh\"");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "THE KEY WAS: " << randKey << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(8000));
        return false;
    }


    // This is for the computer's choice
    else{

        encryptMessage(decrypted[randMessage], encryptedMessage, randKey);
        cout << "THE ENCRYPTED MESSAGE I'M TRYING TO DECRYPT:\n";
        cout << "\033[1;31m" << encryptedMessage << "\033[0m\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        // the cpu guesses a random num between 1 and 100 first
        int tries = 0,
            maxValue = 100,
            minValue = 1,
            cpuGuess;

        while (tries < 4){
            if (tries == 0)
                cpuGuess = (rand() % maxValue) + minValue;

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            cout << "\n\nI GUESSED: " << cpuGuess << endl;

            decryptMessage(decryptedMessage, encryptedMessage, cpuGuess);

            system("bash -c \". humming.sh\"");
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            cout << "DECRYPTED MESSAGE BASED ON MY GUESS: \n"
                 << "\033[1;34m" << decryptedMessage << "\033[0m" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            // resetting the decrypted message
            decryptedMessage = "";

            if (cpuGuess > randKey){
                system("bash -c \". humming.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << "MY GUESS WAS TOO HIGH!\n";
                maxValue = cpuGuess;
                cpuGuess = (rand() % (maxValue - minValue)) + minValue;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }

            else if (cpuGuess < randKey){
                system("bash -c \". humming.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << "MY GUESS WAS TOO LOW!\n";
                minValue = cpuGuess;
                cpuGuess = (rand() % (maxValue - minValue)) + minValue;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }

            if (cpuGuess == randKey){
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                system("bash -c \". target.sh\"");
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                cout << "\nI HACKED THE MESSAGE! BY GUESSING " << cpuGuess << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                return true;
            }

            tries++;
        }
        return false;
    }
}

void ThermonuclearWar :: switchGame(string userSentence){
    bool choseGame = false;

    while (!choseGame){
        removeSpacesAndCapitals(userSentence);
        if (userSentence.find("tictactoe") != -1){
            cout << "LAUNCHING TIC TAC TOE" << endl;
            choseGame = true;
            TicTacToe game1;
            game1.playGame();
        }
        else{

            cout << "I DON'T KNOW THAT GAME. THE ONLY OTHER GAME IS TICTACTOE\n";
            getline(cin, userSentence);
            removeSpacesAndCapitals(userSentence);
        }

    }

}

void ThermonuclearWar :: checkSupply(){

    system("bash -c \". ratios.sh\"");
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\nYOUR SUPPLIES:\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "Air Strikes: " << userCountry.getNumAirStrikes() << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "Missiles: " << userCountry.getNumMissiles() << endl;

}
void ThermonuclearWar :: encryptMessage(string decryptedMessage, string &encryptedMessage, int key){

    char newChar;

    for (int i = 0; i < decryptedMessage.length(); i++){

        if (decryptedMessage[i] + key > 126){
            newChar = char(32 + decryptedMessage[i] + key - 127);
            encryptedMessage+= newChar;
        }

        else{
            newChar = char(decryptedMessage[i] + key);
            encryptedMessage+= newChar;
        }
    }

}
void ThermonuclearWar :: decryptMessage(string &decryptedMessage, string encryptedMessage, int guess){

    char newChar;

    for (int i = 0; i < encryptedMessage.length(); i++){

        if (encryptedMessage[i] - guess < 32){
            newChar = encryptedMessage[i] + 127 - guess - 32;
            decryptedMessage += newChar;
        }

        else{
            newChar = encryptedMessage[i] - guess;
            decryptedMessage += newChar;
        }
    }
}
void ThermonuclearWar :: displayNuke(){
  system("bash -c \". explosion.sh\"");


    cout << "\033[0;37m"
         << "                     ________________               " << endl
         << "                ____/ (  (    )   )  \\___           " << endl
         << "               /( (  (  )   _    ))  )   )\\         " << endl
         << "             ((     (   )(    )  )   (   )  )       " << endl
         << "            ((/  ( _(   )   (   _) ) (  () )  )     " << endl
         << "           ( (  ( (_)   ((    (   )  .((_ ) .  )_   " << endl
         << "          ( (  )    (      (  )    )   ) . ) (   )  " << endl
         << "         (  (   (  (   ) (  _  ( _) ).  ) . ) ) ( ) " << endl
         << "        ( (  (   ) (  )   (  ))     ) _)(   )  )  ) " << endl
         << "        ( (  ( \\ ) (    (_  ( ) ( )  )   ) )  )) ( )" << endl
         << "       (  (   (  (   (_ ( ) ( _    )  ) (  )  )   ) " << endl
         << "         ( (  ( (  (  )     (_  )  ) )  _)   ) _( ( )" << endl
         << "         ((  (   )(    (     _    )   _) _(_ (  (_ ) " << endl
         << "         (_((__(_(__(( ( ( |  ) ) ) )_))__))_)___)   " << endl
         << "          ((__)        \\\\||lll|l||///          \\_))  " << endl
         << "                    (   /(/ (  )  ) )\\   )           " << endl
         << "                  (    ( ( ( | | ) ) )\\   )          " << endl
         << "                  (   /(| / ( )) ) ) )) )            " << endl
         << "                (     ( ((((_(|)_)))))     )         " << endl
         << "                 (      ||\\(|(|)|/||     )           " << endl
         << "               (        |(||(||)||||        )        " << endl
         << "                  (     //|/l|||)|\\\\ \\     )         " << endl
         << "                  (/ / //  /|//||||\\\\  \\ \\  \\ _)     " << endl
         << "\033[0m";
         std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}
void ThermonuclearWar :: displayMissile(){
      system("bash -c \". missile.sh\"");
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
     cout << "\033[1;32m"
          << "                                          ,:       \n"
          << "                                        ,' |       \n"
          << "                                       /   :       \n"
          << "                                    --'   /        \n"
          << "                                    \\/ />/         \n"
          << "                                    / <//_\\        \n"
          << "                                 __/   /           \n"
          << "                                 )'-. /            \n"
          << "                                 ./  :\\            \n"
          << "                                  /.' '            \n"
          << "                                '/'                \n"

          << "\033[0m";

    cout  << "\033[1;33m"

          << "                                +                  \n"
          << "                               '                   \n"
          << "                             `.                    \n"

          << "\033[0m";

     cout << "\033[0;37m"

          << "                          .-\"-                     \n"
          << "                        (    |                     \n"
          << "                     . .-'  '.                     \n"
          << "                   ( (.   )8:                      \n"
          << "                .'    / (_  )                      \n"
          << "               _. :(.   )8P  `                     \n"

          << "\033[0m";

}
void ThermonuclearWar :: displayAirStrike(){
        system("bash -c \". bomberPlane.sh\"");
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;36m"
         << "   _____         ______                     \n"
         << "   | : \\         |    \\                     \n"
         << "   | :  `\\______|______\\_______             \n"
         << "   \\'______              \\_____\\_____       \n"
         << "   \\____/-)_,---------,_____________>--     \n"
         << "                \\       /                   \n"
         << "                 |     /                    \n"
         << "                 |____/__                   \n"
         << "                                           \n"

         << "\033[0m";

    cout << "       |\\**/|                              \n"
         << "       \\ == /                              \n"
         << "        |  |                               \n"
         << "        |  |                               \n"
         << "        \\  /                               \n"
         << "         \\/                                \n";
}
void removeSpacesAndCapitals(string &sentence){
  for (int i = 0; i < sentence.length(); i++){
    if (isspace(sentence[i])){
      sentence.erase(i,1);
      i--;
    }
    else if (isupper(sentence[i]))
      sentence[i] = tolower(sentence[i]);
    }
}
void clearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );

}
