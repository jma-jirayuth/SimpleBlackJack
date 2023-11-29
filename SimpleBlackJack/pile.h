#ifndef PILE_H
#define PILE_H

#include "Card.h"
#include <vector>

/*
    some function use unsigned to prevent
    warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<Card>::size_type'

*/
class Pile {
public:
    //create pile with 0 card
    Pile();

    //create pile with cards equal to number in argument
    //card in the pile that create from this constructor is already sort (default deck)
    //if argument is 52 it will create full default deck
    Pile(unsigned);

    //insert card at first of the pile
    void insertFirst(Card);

    //insert card at givern position
    void insertAt(unsigned, Card);

    // return the first card in the pile and delete from its pile
    Card drawFirst();

    // return card at given position and delete from its pile
    Card drawAt(unsigned);

    // move card in pile and insert to first position of argument pile
    void drawAndInsertTo(Pile &);

    //randomly move card inside the pile
    void shufflePile();


    //move card from initial position to another position in the same pile
    void local_moveCardTo(unsigned, unsigned);

    //move card at given position(this pile) to given position in other pile
    ///moveCardTo_thatPile( initial_POS_of_ini_pile , targetPile, POS_in_targetPile);
    void moveCardTo_thatPile(unsigned, Pile &, unsigned);

    //checking function and accessors
    void showPile();

    unsigned PileSize();

    bool isEmpty();

    int getNo(unsigned);

    int getSuit(unsigned);


private:
    vector<Card> cards;
};

#endif
