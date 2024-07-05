// This program lets the user play a card game against the computer
// Alaina Carson

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

int main() {

    int numOfCards = 5;
    int gameEnd = 0;
    int humanWins = 0;
    int computerWins = 0;
    int numOfGames = 0;
    int valid = 0;
    vector<int> points;

//==================================================================================== Start of Game
//------------------------------------------------------------------------------------
    while (gameEnd == 0) {
        Deck theDeck;
        theDeck.shuffle();

//------------------------------------------------------------------------------------ get user input for how many cards to draw/rounds to play
        valid = 0;
        while (valid == 0) {
            numOfGames++; // increment the number of games played

            cout << "How many cards would you like to draw? (1-10)" << endl;
            cin >> numOfCards;

            if ((numOfCards > 0)&&(numOfCards <= 10)) {
                cout << "This game will consist of " << numOfCards << " rounds." << endl;
                valid = 1;
            }
            else {
                cout << "Invalid input. Please try again." << endl;
            }
        }

//------------------------------------------------------------------------------------ create a hand for both players
        Player human(theDeck, numOfCards);
        Player computer(theDeck, numOfCards);
    

//==================================================================================== Start of Round
        for (int i = 0; i < numOfCards; i++) {

            int computerValue;
            int humanValue;

//------------------------------------------------------------------------------------ print text
            cout << endl;
            cout << "Round " << i+1 << endl;
            cout << "----------" << endl;
            cout << "Computer plays: " << endl;

            computerValue = computer.hand.dealCard(1).getValue(); //play card for computer. The hand is already shuffled, so which card it is does not matter

            cout << endl;
            cout << "Human hand:\n" << human.hand.printHand() << endl;
        
//------------------------------------------------------------------------------------ get user input for which card to play       
            valid = 0;
            int input = 0;
            while (valid == 0) {
                cout << "Which card do you want to play?" << endl;
                cin >> input;

                if ((input <= human.hand.getHandSize()&&(input > 0))) {
                    valid = 1;
                }
                else {
                    cout << "Not a valid input. Please enter the number of the card you want to play." << endl;
                }
            }

//------------------------------------------------------------------------------------ print text
            cout << "You played: " << endl;
            humanValue = human.hand.dealCard(input).getValue();
            cout << endl;


//------------------------------------------------------------------------------------ check the winner of the round and print text
            if (humanValue > computerValue) {
                human.score = human.score + humanValue + computerValue;
                cout << "You won this round!" << endl;
            }
            else if (computerValue > humanValue) {
                computer.score = computer.score + humanValue + computerValue;
                cout << "The computer wins this round!" << endl;
            }
            else {
                cout << "There was a tie." << endl;
            }

//------------------------------------------------------------------------------------ print text
            cout << endl;
            cout << "Current scores: " << endl;
            cout << "Human: " << human.score << endl;
            cout << "Computer: " << computer.score << endl;
        }

//------------------------------------------------------------------------------------ print text for final summary of the ame        
        cout << endl;
        cout << "FINAL SCORE" << endl;
        cout << "Human: " << human.score << endl;
        cout << "Computer: " << computer.score << endl;

//------------------------------------------------------------------------------------ add the final number of points to the points vector
        points.push_back(human.score);

//------------------------------------------------------------------------------------ calculate who won the game, and print text
        if (human.score > computer.score) {
            cout << "You Won!" << endl;
            humanWins++;
        }
        else if (computer.score > human.score) {
            cout << "The computer won!" << endl;
            computerWins++;
        }
        else {
            cout << "There was a tie." << endl;
        }

//------------------------------------------------------------------------------------ get user input for whether or not to play more games
        int answer = 0;
        int valid = 0;
        while (valid == 0) {
            cout << endl;
            cout << "Would you like to play again?" << endl;
            cout << "[1] yes  [2] no" << endl;
            cin >> answer;

            if (answer == 1) {
                valid = 1;
            }
            else if (answer == 2) {
                gameEnd = 1;
                valid = 1;
            }
            else {

                cout << "Invalid input. Please try again." << endl;
            }
        }
    }

//------------------------------------------------------------------------------------ print text for total summary of all games
    cout << endl;
    cout << "SUMMARY" << endl;
    cout << "----------" << endl;
    cout << "Games played: " << numOfGames << endl;
    cout << "Wins: " << humanWins << endl;
    cout << "Losses: " << computerWins << endl;
    cout << endl;

//------------------------------------------------------------------------------------ print out the points won in each round
    int max = points.size();
    int total = 0;
    for (int i = 0; i < max; i++) {
        cout << "Points won Round " << i+1 << ": ";
        cout << points[i] << endl;
        total = total + points[i];
    }
    cout << "Total points: " << total << endl;
    cout << endl;
    cout << "Thank you for playing!" << endl;

    return 0;
}