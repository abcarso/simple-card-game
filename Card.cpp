#include "Card.h"

#include <iostream>
#include <string>

//============================================== create and return a string that combines the enum of a card with the rank of a card
std::string Card::printCard() {
    std::string print;

    if (color == purple) {
        print.append("purple");
    }
    else {
        print.append("orange");
    }

    print.append(":");
    print.append(std::to_string(rank));

    return print;
}

//============================================== return an int the rank of the card
int Card::getRank() {
    return rank;
}
        
//============================================== return an enum the color of the card
Card::Color Card::getColor() {
    return color;
}

//============================================== return an int of the value of the card
int Card::getValue() {
    return value;
}
    