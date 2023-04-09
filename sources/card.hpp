#pragma ONCE
#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <iostream>
using namespace std;
namespace ariel
{
    class Card
    {
    private:            // Access specifier
        int value;      // 1-13 (1=Ace, 11=Jack, 12=Queen, 13=King)
        int type;       // 1-4 (1=spades, 2=hearts, 3=diamonds, 4=clubs)
        bool is_faceUp; // true if the card is face up, false otherwise

    public: // Access specifier
        // Constructor
        Card(int newval, int newtype);
        // copy constructor
        Card(const Card &other);
        // Getters
        int getValue();
        std::string getValueString();
        std::string getType();
        bool getIsFaceUp();
        // Setters
        void flip();
    };
}

#endif