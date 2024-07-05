#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"

class Hand {
    private:
        std::vector<Card> hand;
        int N{0};

    public:
        Hand() = default;
        Hand(Deck &deck, int N) : N{N} {

            for (int i = 0; i < N; i++) {

                hand.push_back(deck.drawCard());

            };
        }
        
        std::string printHand();
        Card dealCard(int num);
        int getHandSize();
};

#endif