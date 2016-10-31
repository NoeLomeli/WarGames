//implementation of Country
// ANY OF THE NUMBERS CAN CHANGE
#include "country.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//**************************** CONSTRUCTORS ********************************
Country :: Country(){
    setAll("");
}
//**************************** MUTATORS ************************************
void Country :: setAll(string countryName){
    srand(time(0));
    this->countryName = countryName;
    hasSurrendered = false;
    hasGottenNuke = false;
    defenses = 1000;
    // make number of weapons random from 5 - 15
    numAirStrikes = (rand() % 10) + 5;
    numMissiles = (rand() % 10) + 5;
}
void Country :: gotAttacked(int damage){
    if (defenses > damage)
        defenses-= damage;
    else
        defenses = 0;
    return;
}
void Country :: decreaseMissiles(){
    if (numMissiles > 0)
        numMissiles--;
    return;
}
void Country :: decreaseAirStrikes(){
    if (numAirStrikes > 0)
        numAirStrikes--;
    return;

}
void Country :: setHasSurrendered(bool hasSurrendered){
    this-> hasSurrendered = hasSurrendered;
}
void Country :: setHasGottenNuke(bool hasGottenNuke){
    this -> hasGottenNuke = hasGottenNuke;
}
