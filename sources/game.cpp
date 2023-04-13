// Author: Anna Pinchuk
// Date: 13/04/2023
// Description: This file contains the war game.
// In test driven development, we write the tests first, and then we write the code.
// credit to: course staff for the demo file, and the functions' descriptions.To copilot for helping with the comments.

#pragma ONCE
#include <string>
#include <iostream>
#include "game.hpp"
using namespace std;
namespace ariel
{
    // Constructor
    Game::Game(Player &pl1, Player &pl2) : player1(pl1), player2(pl2)
    {
        this->log = "";
        this->lasturn = "";
        this->player1.addGame();
        this->player2.addGame();
        this->player1.setPlaying();
        this->player2.setPlaying();
        // initialize number of cards taken by each player in unuque game
        int temp = this->player1.cardesTaken();
        this->player1.addCardsTaken(-temp);
        temp = this->player2.cardesTaken();
        this->player2.addCardsTaken(-temp);

        vector<Card> all;
        // create cards
        for (int i = 1; i < 14; i++)
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

    void Game::playTurn()
    {
        if (!this->player1.isPlaying() || !this->player2.isPlaying())
        {
            throw std::invalid_argument("One of the players is out of the game");
        }
        int cardscounter = 0; // count the number of cards in the war
        Card v1 = this->player1.removecard();
        Card v2 = this->player2.removecard();
        cardscounter++;
        // template: Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
        this->lasturn = this->player1.getName() + " played " + v1.getValueString() + " of " + v1.getType() + " " + this->player2.getName() + " played " + v2.getValueString() + " of " + v2.getType() + ". ";
        // check if one of the players has no cards
        if (v1.getValue() == 0 || v2.getValue() == 0)
        {
            this->printWiner();
            return;
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
                v1 = this->player1.removecard();
                v2 = this->player2.removecard();
                cardscounter++;
                // check if one of the players has no cards
                if (v1.getValue() == 0 || v2.getValue() == 0)
                {
                    this->player1.addCardsTaken(cardscounter);
                    this->player2.addCardsTaken(cardscounter);
                    this->printWiner();
                    break;
                }
                else
                {
                    v1 = this->player1.removecard();
                    v2 = this->player2.removecard();
                    cardscounter++;
                    this->lasturn += this->player1.getName() + " played " + v1.getValueString() + " of " + v1.getType() + " " + this->player2.getName() + " played " + v2.getValueString() + " of " + v2.getType() + ". ";
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
    }
    // print last turn
    void Game::printLastTurn()
    {
        cout << this->lasturn << endl;
    }
    // play all turns
    void Game::playAll()
    {
        while (this->player1.isPlaying() || this->player2.isPlaying())
        {
            this->playTurn();
        }
    }
    // print the winner
    void Game::printWiner()
    {
        this->player1.addCardsWon(this->player1.cardesTaken());
        this->player2.addCardsWon(this->player2.cardesTaken());
        if (this->player1.cardesTaken() > this->player2.cardesTaken())
        {
            this->player1.addWin();
            cout << this->player1.getName() << endl;
        }
        else if (this->player1.cardesTaken() < this->player2.cardesTaken())
        {
            this->player2.addWin();
            cout << this->player2.getName() << endl;
        }
        else
        {
            cout << "Tie!" << endl;
        }
        this->player1.setPlaying();
        this->player2.setPlaying();
    }
    // print the log
    void Game::printLog()
    {
        cout << this->log << endl;
    }
    void Game::printStats()
    {
        cout << this->player1.getName() << " has " << (this->player1.getNumWin() / this->player1.getNumGames()) << " win rate, " << this->player1.getCardsWon() << " cards won, " << this->player1.getDraw() << " number of draws, " << (this->player1.getDraw() / (26 * this->player1.getNumGames())) << " drew rate" << endl;
        cout << this->player2.getName() << " has " << (this->player2.getNumWin() / this->player2.getNumGames()) << " win rate, " << this->player2.getCardsWon() << " cards won, " << this->player2.getDraw() << " number of draws, " << (this->player2.getDraw() / (26 * this->player2.getNumGames())) << " drew rate" << endl;
    }
}