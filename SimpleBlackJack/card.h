#ifndef CRAD_H
#define CRAD_H

#include <iostream>

using namespace std;

class Card {
public:
    //create card with no data
    Card();

    //create card with no and suit
    Card(unsigned, unsigned);

    //accessors & mutators
    void setNo(unsigned);

    void setSuit(unsigned);

    int getNo();

    int getSuit();

    void showCard();

private:
    int no;
    int suit;
};

#endif
