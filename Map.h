//header file for class Map
#ifndef MAP_H
#define MAP_H
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>
using namespace std;

class Map
{
private:
  char player;
  char damage;

public:
//**************************** CONSTRUCTORS ********************************
  Map();
  Map(char user);


// Precondition: Player will have chosen to play thermonuclear war
// Postcondition: Will display map of USA and USSR in neutral color.
  void displayBoard();

  // ********************************************************
  // Summary: User will select which country they want to pick
  // Postcondition: Will display map of USA and USSR in red or white according to user selection.
  // ********************************************************
  void displayCountry(char player);

  // Precondition: Game will be initialized.
  // Postcondition: Energy bar for the US will be displayed and will decrease according to damage received.
  // ********************************************************
  void displayDamageUS(int damage);

  // Precondition: Game will be initialized.
  // Postcondition: Energy bar for USSR will be displayed and will decrease according to damage received.
  // ********************************************************
  void displayDamageUSSR(int damage);

//**************************** MUTATORS ********************************
  char getPlayer(){return player;}
  void setPlayer(int player){this->player = player;}

};
#endif //MAP_H
