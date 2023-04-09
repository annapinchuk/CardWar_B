#pragma once
#include <vector>
#include <string>
#include "card.hpp"
using namespace std;
namespace ariel
{
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
    Player(std::string p_name);
    // Default Constructor
    Player();
    // copy constructor
    Player(const Player &other);
    // Getters
    int stacksize();
    int getNumWin();
    Card removecard();
    int getDraw();
    int getNumGames();
    std::string getName();
    int cardesTaken();
    void addCard(Card card);
    bool isPlaying();
    int getCardsWon();
    // Setters
    void addCardsWon(int num);
    void setPlaying();
    void addCardsTaken(int num);
    void addWin();
    void addDraw();
    void addGame();
  };
}