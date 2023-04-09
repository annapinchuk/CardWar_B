
#include "player.hpp"

namespace ariel
{
    // Constructor
    Player::Player(string p_name)
    {
        name = p_name;
        cardes_Taken = 0;
        is_playing = false;
        id++;
        vector<Card> cards;
    }
    // Default Constructor
    Player::Player()
    {
        id++;
        name = "stranger" + to_string(id); // unique name
        cardes_Taken = 0;
        is_playing = false;
        vector<Card> cards;
    }
    // copy constructor
    Player::Player(const Player &other)
    {
        name = other.name;
        cards = other.cards;
        cardes_Taken = other.cardes_Taken;
        is_playing = other.is_playing;
        id = other.id;
        cardsWon = other.cardsWon;
        numwingames = other.numwingames;
        numdraw = other.numdraw;
        numgames = other.numgames;
    }
    // destructor
    Player::~Player()
    {
        this->cardes_Taken = 0;
        this->cards.clear();
        cout << "Player " << name << " is out of the game" << endl;
    }
    // Getters
    Card Player::removecard()
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
    int Player::getCardsWon()
    {
        return cardsWon;
    }
    int Player::stacksize()
    {
        return cards.size();
    }
    int Player::cardesTaken()
    {
        return cardes_Taken;
    }
    int Player::getNumWin()
    {
        return numwingames;
    }
    int Player::getDraw()
    {
        return numdraw;
    }
    int Player::getNumGames()
    {
        return numgames;
    }
    string Player::getName()
    {
        return name;
    }
    bool Player::isPlaying()
    {
        return is_playing;
    }
    // Setters
    void Player::addCardsWon(int num)
    {
        cardsWon += num;
    }
    void Player::addCardsTaken(int num)
    {
        cardes_Taken += num;
    }
    void Player::addCard(Card card)
    {
        cards.push_back(card);
    }
    void Player::setPlaying()
    {
        is_playing = !is_playing;
    }
    void Player::addWin()
    {
        numwingames++;
    }
    void Player::addDraw()
    {
        numdraw++;
    }
    void Player::addGame()
    {
        numgames++;
    }
}