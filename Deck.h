#ifndef DECK_H
#define DECK_H

#include <vector>

#include "Card.h"

class Deck {
    private:
        std::vector<Card> deck;

    public:
        Deck() {
            for (int i = 1; i <= 10; i++) {

                Card card(i, Card::purple);
                deck.push_back(card);

            }
            for (int i = 1; i <= 10; i++) {

                Card card(i, Card::orange);
                deck.push_back(card);

            }
        };
        
        void shuffle();
        Card drawCard();
        int getDeckSize();
};

#endif