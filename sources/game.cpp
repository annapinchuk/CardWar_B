// Author: Anna Pinchuk
// Date: 13/04/2023
// Description: This file contains the war game.
// In test driven development, we write the tests first, and then we write the code.
// credit to: course staff for the demo file, and the functions' descriptions.To copilot for helping with the comments.

#pragma ONCE
#include <string>
#include <iostream>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace ariel;
using namespace std;
class Game
{
private: // Access specifier
    Player player1;
    Player player2;
    string log;
    string lasturn;

    // The class
public: // Access specifier
    // Constructor
    Game(Player p1, Player p2)
    {
        log = "";
        lasturn = "";
        player1 = p1;
        player2 = p2;
        this->player1.addGame();
        this->player2.addGame();
        this->player1.setPlaying();
        this->player2.setPlaying();
        // initialize number of cards taken by each player in unuque game
        int temp  = this->player1.cardesTaken();
        this->player1.addCardsTaken(-temp);
        temp  = this->player2.cardesTaken();
        this->player2.addCardsTaken(-temp);

        vector<Card> all;
        // create cards
        for (int i = 0; i < 14; i++)
        {
            all.push_back(Card(i, 1));
            all.push_back(Card(i, 2));
            all.push_back(Card(i, 3));
            all.push_back(Card(i, 4));
        }
        // shuffle cards
        srand(time(NULL)); // seed random number generator
        for (int i = 0; i < 52; i++)
        {
            int j = rand() % 52;              // random index
            Card temp = all[(unsigned int)i]; // cast to unsigned int to avoid warning
            all[(unsigned int)i] = all[(unsigned int)j];
            all[(unsigned int)j] = temp;
        }
        // give cards to players
        for (int i = 0; i < 26; i++)
        {
            player1.addCard(all[(unsigned int)i]);
            player2.addCard(all[(unsigned int)i + 26]);
        }
    }
    // destructor
    ~Game()
    {
        this->player1.setPlaying();
        this->player2.setPlaying();
        cout << "Game is over" << endl;
    }
    void playTurn()
    {
        int cardscounter = 0; // count the number of cards in the war
        Card v1 = this->player1.removecard();
        Card v2 = this->player2.removecard();
        cardscounter++;
        // template: Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
        this->lasturn = this->player1.getName() + " played " + v1.getValueString() + " of " + v1.getType() + " " + this->player1.getName() + " played " + v2.getValueString() + " of " + v2.getType() + ". ";
        // check if one of the players has no cards
        if (v1.getValue() == 0 || v2.getValue() == 0)
        {
            return this->printWiner();
        }
        else
        {
            // check if the cards are equal
            // war
            while (v1.getValue() == v2.getValue())
            {
                this->lasturn += "Draw. ";
                this->player1.addDraw();
                this->player2.addDraw();
                // war
                // one card is faced down
                Card v1 = this->player1.removecard();
                Card v2 = this->player2.removecard();
                cardscounter++;
                // check if one of the players has no cards
                if (v1.getValue() == 0 || v2.getValue() == 0)
                {
                    this->player1.addCardsTaken(cardscounter);
                    this->player2.addCardsTaken(cardscounter);
                    return this->printWiner();
                }
                else
                {
                    Card v1 = this->player1.removecard();
                    Card v2 = this->player2.removecard();
                }
            }
            // check if the card is ace
            if (v1.getValue() == 1 && v2.getValue() != 2)
            {

                this->lasturn += this->player1.getName() + " wins.";
                this->player1.addCardsTaken(cardscounter * 2); // add the cards to the player
            }
            else if (v1.getValue() != 2 && v2.getValue() == 1)
            {
                this->lasturn += this->player2.getName() + " wins.";
                this->player2.addCardsTaken(cardscounter * 2); // add the cards to the player
            }
            else if (v1.getValue() > v2.getValue())
            {
                this->lasturn += this->player1.getName() + " wins.";
                this->player1.addCardsTaken(cardscounter * 2); // add the cards to the player
            }
            // v1 < v2
            else
            {
                this->lasturn += this->player2.getName() + " wins.";
                this->player2.addCardsTaken(cardscounter * 2); // add the cards to the player
            }
        }
        this->log += this->lasturn + '\n';
        cout << "EndOfTurn" << endl;
    }
    // print last turn
    void printLastTurn()
    {
        cout << this->lasturn << endl;
    }
    // play all turns
    void playAll()
    {
        for (int i = 0; i < 5; i++)
        {
            this->playTurn();
        }
    }
    // print the winner
    void printWiner()
    {
        this->player1.addCardsWon(this->player1.cardesTaken());
        this->player2.addCardsWon(this->player2.cardesTaken());
        if (this->player1.cardesTaken() > this->player2.cardesTaken())
        {
            this->player1.addWin();
            cout << this->player1.getName()<< endl;
        }
        else if (this->player1.cardesTaken() < this->player2.cardesTaken())
        {
            this->player2.addWin();
            cout << this->player2.getName()<< endl;
        }
        else
        {
            cout << "Tie!" << endl;
        }
    }
    // print the log
    void printLog()
    {
        cout << this->log << endl;
    }
    void printStats()
    {
        cout << this->player1.getName() << " has " << (this->player1.getNumWin() / this->player1.getNumGames()) << " win rate, " << this->player1.getCardsWon() << " cards won, " << this->player1.getDraw() << " number of draws, " << (this->player1.getDraw() / (26 * this->player1.getNumGames())) << " drew rate" << endl;
        cout << this->player2.getName() << " has " << (this->player2.getNumWin() / this->player2.getNumGames()) << " win rate, " << this->player2.getCardsWon() << " cards won, " << this->player2.getDraw() << " number of draws, " << (this->player2.getDraw() / (26 * this->player2.getNumGames())) << " drew rate" << endl;
    }
};