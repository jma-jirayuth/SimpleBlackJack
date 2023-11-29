#include "Card.h"
/*
    some function use unsigned to prevent
        warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<Card>::size_type'
*/
Card::Card() {
    no = 0;
    suit = 0;
}

Card::Card(unsigned n,unsigned s) {
    no = n;
    suit = s;
}

void Card::setNo(unsigned n) {
    no = n;
}

void Card::setSuit(unsigned s) {
    suit = s;
}

int Card::getNo() {
    return no;
}

int Card::getSuit() {
    return suit;
}

//show card ; convert number to text
void Card::showCard() {
    switch(getNo())
    {
        case 1 : cout << "A"; break;
        case 11: cout << "J"; break;
        case 12: cout << "Q"; break;
        case 13: cout << "K"; break;
        default: cout << getNo();
    }
    cout << ' ';
    switch (getSuit()) {
        case  0: cout << "Club";    break;
        case  1: cout << "Diamond"; break;
        case  2: cout << "Heart";   break;
        case  3: cout << "Spade";   break;
        default: cout << "Error";
    }
    cout << endl;
}
