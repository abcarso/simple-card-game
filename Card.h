#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    public:
        enum Color {purple, orange};
    
        Card() = default;
        Card(int rank, Color color) : rank{rank}, color{color} {

            if (color == orange) {
                value = rank*2;
            }
            else {
                value = rank;
            }
        }

        std::string printCard();
        int getRank();
        Color getColor();
        int getValue();
    
    private:
        int rank{0};
        Color color{purple};
        int value{0};
};

#endif