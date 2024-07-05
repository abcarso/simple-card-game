#include "Deck.h"
#include "Card.h"

#include <ctime>
#include <cstdlib>
#include <algorithm>

#include <iostream>

//============================================== randomly rearranges the elements in the vector deck
void Deck::shuffle() {
    srand(unsigned(time(0)));
    std::random_shuffle(deck.begin(), deck.end());

    std::cout << "Shuffling..." << std::endl;
}

//============================================== returns the first element of the vector deck, then deletes the first element of the vector deck
/*
                                                 *** It was unclear whether the "first card" was the first element in the vector, or the last ***
*/

Card Deck::drawCard(){

    Card draw = deck.front();
    deck.erase(deck.begin(), deck.begin()+1);

    return draw;
}

//============================================== return an int of the size of the vector called deck
int Deck::getDeckSize() {
    return deck.size();
}