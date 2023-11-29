#include <vector>
#include <algorithm>
#include <ctime>
#include "Pile.h"

/*
    some function use unsigned to prevent
        warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<Card>::size_type'
*/

Pile::Pile() {}

Pile::Pile(unsigned numberOfCard) {
    for (unsigned i = 0; i < numberOfCard; i++) {
        cards.insert(cards.begin(), Card((i % 13) + 1, i / 13));
        /// insert( iterator position , data );
        // insert at position and push back

        /// begin() ---> return iterator (position) of first element

        /// Card((i % 13)+ 1 , i / 13) -----> Card( no (1-13) , suit (0-3) )
        //set card's no and suit

        /* no and suit is set form i it must be modified

         no's argument can be 0-52 must set to be in range 1-13
         suit's argument can be 0-52 must set to be in range 0-3
        */
    }
}

void Pile::insertFirst(Card c) {
    cards.insert(cards.begin(), c);
    /// insert( iterator position , data );
    /// begin() ---> return iterator (position) of first element
    // insert at position and push back

    /*
    EX: insert(vec.begin() , 0 )
        1 2 3 4 5 ----------> 0 1 2 3 4 5
        insert(vec.begin() , 99 )
        0 1 2 3 4 5 ----------> 99 0 1 2 3 4 5

    */
}

void Pile::insertAt(unsigned position, Card c) {
    cards.insert(cards.begin() + position, c);
    ///insert at behind position(array) as parameter
    /// same as insertFirst() just +position from the beginning position
}

Card Pile::drawFirst() {
    Card c = cards.front();
    cards.erase(cards.begin());
    return c;
    ///just return card data at front(first) position of the pile
    ///and delete it ; card in next position will move -1 autometically
}

Card Pile::drawAt(unsigned position) {
    Card c = cards.at(position);
    cards.erase(cards.begin() + position);
    return c;
    ///draw at given position of the pile
    ///and delete it ; card in next position will move -1pos autometically
}

void Pile::drawAndInsertTo(Pile &targetPile) {
    Card c = cards.front();
    cards.erase(cards.begin());
    ///draw and delete

    targetPile.insertFirst(c);
    ///put drawed card to target pile (first position)
}

void Pile::local_moveCardTo(unsigned ini, unsigned target) {
    ///use rotate to move element (move middle to first)

    ///void rotate(first, middle, last)
    ///first, last : Forward Iterators to the initial and final positions of the sequence to be rotated
    ///middle : Forward Iterator pointing to the element within the range [first, last] >>> that is moved to the first position in the range. <<<<

    if (ini > target)
        ///rotate right

        ///     (-------first-----) (-----middle------)(-------last------)
        rotate(cards.rend() - ini - 1, cards.rend() - ini, cards.rend() - target);
        /*
        Example:
                        rend() ; (returns a reverse iterator pointing to the theoretical element right before the first element in the array container.)
                         |
                         V
           position        <0>   <1>  <2>      <3>       <4>      <5>  <6>
           move 4 to 1:     3   [ 5    6        7        [4]  ]    8    9
                            ^                   ^         ^
                            |                   |         |
                           last               middle    first
                                                          |

                            3   [-------------shift right----->]    8    9

                result:     3   [ [4]   5        6         7   ]    8    9
                            ^      ^                        ^
                            |      |                        |
                           last  first                    middle
                                                          ^ move middle to the first
        */

    else
        ///rotate left
        ///   (-------first-----)(-----middle------)   (-------last------)
        rotate(cards.begin() + ini, cards.begin() + ini + 1, cards.begin() + target + 1);
    /*
    Example:
        position     <0>  <1>   <2>      <3>  <4>  <5>   <6>
        move 2 to 5:  3    4 [  [5]       6    7    8   ] 9
                                 ^        ^               ^
                                 |        |               |
                               first    middle           last

                                 |
                                 |
                                 |
                      3    4 [<-----shift left----------]  9
             result:  3    4  [  6        7    8    [5] ]  9
                                 ^                   ^     ^
                                 |                   |     |
                               middle              first  last
                                 ^ move middle to the first
    */


}

void Pile::shufflePile() {
    unsigned x;
    srand(time(NULL));

    ///swap card randomly
    for (unsigned i = 0; i < cards.size(); i++) {
        x = rand() % cards.size();
        swap(cards.at(x), cards.at(i));
        //swap card from random position to i position
    }
}

void Pile::moveCardTo_thatPile(unsigned ini_position, Pile &target_pile, unsigned target_position) {
    ///if pile is empty insert at first position
    if (target_pile.isEmpty())
        target_pile.insertFirst(cards.at(ini_position));

    ///if given position more than size of pile just insert to last position
    else if (target_position > target_pile.PileSize())
        target_pile.insertAt(target_pile.PileSize(), cards.at(ini_position));

    ///condition is ok ; insert it at argument position
    else
        target_pile.insertAt(target_position, cards.at(ini_position));

    ///delete card from initial pile
    cards.erase(cards.begin() + ini_position);

}

///print function
void Pile::showPile() {
    for (unsigned i = 0; i < cards.size(); i++) {
        (cards.at(i)).showCard();
    }
}


///function to check status and accessors

bool Pile::isEmpty() {
    ///empty() - returns True is the size of the list container is zero otherwise it returns False.
    return cards.empty();
}

unsigned Pile::PileSize() {
    ///size() - return the size of the set container or the number of elements in the set container.
    return cards.size();
}

int Pile::getNo(unsigned pos) {
    ///at(pos) – Returns a reference to the element at position ‘pos’ in the vector
    return cards.at(pos).getNo();
}

int Pile::getSuit(unsigned pos) {
    return cards.at(pos).getSuit();
}
