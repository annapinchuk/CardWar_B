#include "card.hpp"
namespace ariel
{
    Card::Card(int newval, int newtype)
    {
        value = newval;
        type = newtype;
        is_faceUp = false;
    }
    // copy constructor
    Card::Card(const Card &other)
    {
        value = other.value;
        type = other.type;
        is_faceUp = other.is_faceUp;
    }
    // Getters
    int Card::getValue()
    {
        return value;
    }
    string Card::getType()
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
    string Card::getValueString()
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
    bool Card::getIsFaceUp()
    {
        return is_faceUp;
    }
    // Setters
    void Card::flip()
    {
        is_faceUp = !is_faceUp;
    }
}
