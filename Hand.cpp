#include "Hand.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <string>

//============================================== create a string that can be used to show the cards in a player's hand
std::string Hand::printHand() {
    std::string print;
    int N = hand.size();

//---------------------------------------------- append all the cards into 1 string. Label them each with a number
    for (int i = 0; i < N; i++) {
        print.append("[");
        print.append(std::to_string(i+1));
        print.append("] ");
        print.append(hand[i].printCard());
        print.append(" ");
    }
    return print;
}

//============================================== return the chosen card from the hand, and delete it from the hand after printing the choice
Card Hand::dealCard(int num) {
    Card deal = hand[num-1];
    std::cout << hand[num-1].printCard() << std::endl;
    hand.erase(hand.begin()+ num-1);
    return deal;
}

//============================================== return an int of the size of the vector called hand
int Hand::getHandSize() {
    //std::cout << "The hand size: " << std::to_string(hand.size()) << std::endl;
    return hand.size();
}
        