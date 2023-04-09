#pragma ONCE
#include <iostream>
#include <string>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace ariel;
using namespace std;
class Card
{
private:            // Access specifier
    int value;      // 1-13 (1=Ace, 11=Jack, 12=Queen, 13=King)
    int type;       // 1-4 (1=spades, 2=hearts, 3=diamonds, 4=clubs)
    bool is_faceUp; // true if the card is face up, false otherwise

public: // Access specifier
    // Constructor
    Card(int xy, int pl)
    {
        value = xy;
        type = pl;
        is_faceUp = false;
    }
    //  destructor
    ~Card()
    {
        cout << "Card is destroyed" << endl;
    }
    // Getters
    int getValue()
    {
        return value;
    }
    string getType()
    {
        if (type == 1)
        {
            return "spades";
        }
        else if (type == 2)
        {
            return "hearts";
        }
        else if (type == 3)
        {
            return "diamonds";
        }
        else if (type == 4)
        {
            return "clubs";
        }
        else
        {
            return "null";
        }
    }
    string getValueString()
    {
        if (value == 1)
        {
            return "Ace";
        }
        else if (value == 11)
        {
            return "Jack";
        }
        else if (value == 12)
        {
            return "Queen";
        }
        else if (value == 13)
        {
            return "King";
        }
        else
        {
            return to_string(value);
        }
    }
    bool getIsFaceUp()
    {
        return is_faceUp;
    }
    // Setters
    void flip()
    {
        is_faceUp = !is_faceUp;
    }
};
