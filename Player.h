#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"

#include <iostream>

class Player {
    public:
        int score{0};
        Hand hand;

        Player() = default;
        Player(Deck &deck, int N) {
            hand = Hand(deck, N); 
        }
};


#endif