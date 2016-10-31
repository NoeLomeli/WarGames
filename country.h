// header file of Country
#include <iostream>
#include <string>
using namespace std;

#ifndef COUNTRY_H
#define COUNTRY_H

class Country{
    private:
        string countryName;
        unsigned int defenses;
        int numAirStrikes,
            numMissiles;
        bool hasGottenNuke;
        bool hasSurrendered;

    public:
    //**************************** CONSTRUCTORS ********************************
        Country();
    //**************************** MUTATORS ************************************
        // Precondition: takes in a string for the country's name
        // Postcondition: Assigns blank values to all except name
        void setAll(string countryName);

        // Precondition: Takes in an integer that represents the amount of damage
        //      that the country is being dealt
        // Postcondition: Subtracts that damage from the defenses of the country
        //      and if damage exceeds the country's defenses, defenses gets 0
        void gotAttacked(int damage);

        // Precondition: Takes in no parameters
        // Postcondition: Decreases the amount of missiles by 1
        void decreaseMissiles();

        // Precondition: Takes in no parameters
        // Postcondition: Decreases the amount of air strikes by 1
        void decreaseAirStrikes();

        // Precondition: Takes in a boolean that represents whether the country
        //      has chosen to surrender
        // Postcondition: Depending on whether the boolean is true or not, it sets
        //      the country's hasSurrendered (which is one of the things that
        //      determines whether the user loses or not)
        void setHasSurrendered(bool hasSurrendered);

        // Precondition: Takes in a boolean that represents whether or not the
        //      country has been able to obtain a nuke
        // Postcondition: Depending on whether the boolean is true or not, it sets
        //      the country's hsGottenNuke
        void setHasGottenNuke(bool hasGottenNuke);
    //*************************** ACCESSORS ************************************
        // All of these methods just return the values
        string getCountryName() const {return countryName;}
        bool getHasSurrendered() const {return hasSurrendered;}
        bool getHasGottenNuke() const {return hasGottenNuke;}
        unsigned int getDefenses() const {return defenses;}
        int getNumAirStrikes() const {return numAirStrikes;}
        int getNumMissiles() const {return numMissiles;}

};
#endif
