//header file of ThermonuclearWar

#include "country.h"
#include "Map.h"
#ifndef THERMONUCLEARWAR_H
#define THERMONUCLEARWAR_H

class ThermonuclearWar{

    private:
        Country userCountry;
        Country cpuCountry;
        Map map1;

    public:
    //**************************** CONSTRUCTORS ********************************
        ThermonuclearWar();
    //**************************** METHODS *************************************
        //******************* game functionality *******************************
        // Precondition: Takes in no parameters
        // Postcondition: Asks the user whether they want to be the US or Soviet
        //      Union, and assigns the userCountry and cpuCountry based on that
        void newGame();

        // Precondition: Takes in no parameters
        // Postcondition: So long as the user has not won or lost and the cpu has
        //      not won or last, a series of options are printed that the user may
        //      choose from to take his/her turn. Then a random number will be
        //      generated to decide what action the cpu will take
        void runGame();

        // Precondition: Takes in no parameters
        // Postcondition: If the user manages to get the CPU's defenses to 0,
        //      then the user has won, didWin will return true if the user
        //      wins and false otherwise
        bool didWin() const {return (cpuCountry.getDefenses() == 0);}

        // Precondition: Takes in no parameters
        // Postcondition: Checks for whether the User's country's defenses has
        //      reached 0 or if the User's country has decided to surrender.
        //      If either of these are true, then the CPU has won and didLose
        //      will return true
        bool didLose();

        // Precondition: Takes in no parameters
        // Postcondition: This function calls both didWin and didLose in different
        //      if statements. Depending on which one is true, a congratulating
        //      message is printed or an option to play again is prompted
        void checkEndGame();

        // Precondition: Takes in a boolean that represents whether or not the
        //      cpu was what called the function
        // Postcondition: Depending on whether it is true that the cpu chose it
        //      or not, there are two different routes the function may take.
        //
        //      If the user chose it, then the user is prompted to enter an int
        //      in an attempt to decypher a message. There is a total of 5 tries
        //      and if the user does not guess the correct key then they have
        //      failed at obtaining a nuke. A hint is printed every time to signal
        //      if the guess made was too high or too low to help narrow the range.
        //
        //      If the cpu chose it, then a random number is generated within the
        //      range of 1 to 100 and everytime the guess is incorrect, it will
        //      generate a number at a more narrowed range.
        bool getNuke(bool cpuChoseThis);

        // Precondition: Takes in the decrypted message string, the encrypted
        //      message string (which should be an empty string initially), and
        //      the key that will be used to encrypt the message
        // Postcondition: Uses an algorithm to generate new characters to
        //      represent the actual characters that were there, and since the
        //      encrypted message was pass by reference, the changes made in the
        //      the function will also be applied after the function is done.
        void encryptMessage(string decryptedMessage, string &encryptedMessage, int key);

        // Precondition: Takes in the decrypted message string (which should be
        //      an empty string initially), the encrypted message, and the guess
        //      which represents the user or cpu's guess at the key that was used
        // Postcondition: Uses the reverse algorithm of the one that was used to
        //      encrypt the message using the guess as the potential key. Adds the
        //      new characters to the decrypted message and since it is pass by
        //      reference, the changes applied are permanent.
        void decryptMessage(string &decryptedMessage, string encryptedMessage, int guess);

        //***************************** user options ***************************
        // Precondition: Takes in a sentence that should contain the name of the
        //      game the user wants to play
        // Postcondition: Keeps checking to see if the string contains the name
        //      of a game it is programmed to play, which in this case, the only
        //      other game it knows is Tic Tac Toe.
        void switchGame(string userSentence);

        // Precondition: Takes in no parameters
        // Postcondition: Prints out the entire inventory of that specific country
        //      it takes up a turn from the user if they choose to view what they
        //      have.
        void checkSupply();

        void displayNuke();
        void displayMissile();
        void displayAirStrike();
};
//**************************** HELPER METHODS **********************************
// Precondition: Takes in a string that will likely contain spaces and or capital
//      letters.
// Postcondition: It traverses through the entire array and if it finds a space
//      or a capital letter, it will delete space or replace the uppercase letter
//      with a lower case letter. This way, we can easily use the .find() method
//      for finding certain words in a sentence.
void removeSpacesAndCapitals(string &sentence);

// Precondition: Takes in no parameters
// Postcondition: Couts a series of endls to avoid the screen from getting too
//      cluttered.
void clearScreen();

#endif
