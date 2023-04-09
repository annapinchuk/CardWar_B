#include "card.hpp"
#include "player.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace ariel;
using namespace std;
class Player
{        // The class
private: // Access specifier
    string name;
    vector<Card> cards;
    int cardes_Taken;
    bool is_playing;
    int id = 0;
    int cardsWon = 0;
    int numwingames = 0;
    int numdraw = 0;
    int numgames = 0;

public: // Access specifier
    // Constructor
    Player(string p_name)
    {
        name = p_name;
        cardes_Taken = 0;
        is_playing = false;
        id++;
        vector<Card> cards;
    }
    // Default Constructor
    Player()
    {
        id++;
        name = "stranger" + to_string(id); // unique name
        cardes_Taken = 0;
        is_playing = false;
        vector<Card> cards;
    }
    // destructor
    ~Player()
    {
        this->cardes_Taken = 0;
        this->cards.clear();
        cout << "Player " << name << " is out of the game" << endl;
    }
    // Getters
    Card removecard()
    {
        if (cards.size() == 0)
        {
            Card cardnull = Card(0, 0);

            return cardnull;
        }
        else
        {
            Card card = cards.back();
            cards.pop_back();
            return card;
        }
    }
    int getCardsWon()
    {
        return cardsWon;
    }
    int stacksize()
    {
        return cards.size();
    }
    int cardesTaken()
    {
        return cardes_Taken;
    }
    int getNumWin()
    {
        return numwingames;
    }
    int getDraw()
    {
        return numdraw;
    }
    int getNumGames()
    {
        return numgames;
    }
    string getName()
    {
        return name;
    }
    bool isPlaying()
    {
        return is_playing;
    }
    // Setters
    void addCardsWon(int num)
    {
        cardsWon += num;
    }
    void addCardsTaken(int num)
    {
        cardes_Taken += num;
    }
    void addCard(Card card)
    {
        cards.push_back(card);
    }
    void setPlaying()
    {
        is_playing = !is_playing;
    }
    void addWin()
    {
        numwingames++;
    }
    void addDraw()
    {
        numdraw++;
    }
    void addGame()
    {
        numgames++;
    }
};