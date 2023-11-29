#include <iostream>
#include <ctime>
#include "Card.h"
#include "Pile.h"
#include <windows.h>

using namespace std;

int getTotal(Pile);

void blackJack();
bool playAgain();
///main run loop only
int main()
{
    do
    {
        blackJack();

    } while(playAgain());

    return 0;
}




bool playAgain()
{
    char key = ' ';
    while( key!='y'&&key!='n' )
    {
        cout << ">> Play again? (y/n) : ";
        cin >> key;
    }
    return key=='y';
}


///convert cards in the pile to sum
int getTotal(Pile a) {
    int sum = 0;
    for (int i = 0; i < static_cast<int>(a.PileSize()); i++) {
        //if have K Q J card in the pile set it to 10, else get its number
        sum += ((a.getNo(i) > 10) ? 10 : a.getNo(i));
    }
    return sum;
}

void blackJack() {
    system("cls");
    cout << "BLACKJACK C11 0.01 " << endl << endl;

    //declare obj and initialized
    Pile deck(52);
    Pile player(0);
    Pile bot(0);

    //shuffle deck
    deck.shufflePile();

    ///each player draw 2 card from deck
    //player draw
    deck.drawAndInsertTo(player);
    deck.drawAndInsertTo(player);

    //bot draw
    deck.drawAndInsertTo(bot);
    deck.drawAndInsertTo(bot);

    ///show player cards and total
    cout << "player :" << endl;
    player.showPile();
    cout << "player total :" << getTotal(player) << endl;
    cout << endl;

    ///show bot cards and total
    cout << "bot :" << endl;
    bot.showPile();
    cout << "bot total :" << getTotal(bot) << endl;
    cout << endl;

    ///check the default turn (is anyone get 21(win) or get more than 21(lose) at first turn)

    //player win
    if (getTotal(player) == 21) {
        cout << "$$$ BLACKJACK Player win $$$" << endl;
        return;
    }

    //bot win
    else if (getTotal(bot) == 21) {
        cout << "--- Bruh BLACKJACK bot win ---" << endl;
        return;
    }

    //player lose
    else if (getTotal(player) > 21) {
        cout << "--- unlucky player more than 21 ---" << endl;
        return;
    }

    //bot lose
    else if (getTotal(bot) > 21) {
        cout << "$$$ bot more than 21 Player win $$$" << endl;
        return;
    }


    //begin turn
    char key;

    //player's turn
    cout << "player's turn" << endl;

    ///player want to hit(draw) or not
    while (true) {
        cout << ">> wanna hit? (y/n): ";
        cin >> key;

        ///player hit
        //player draw a card then show and total
        if (key == 'y' || key == 'Y') {
            cout << "player HIT!" << endl << endl;
            deck.drawAndInsertTo(player);
            player.showPile();
            cout << "player total :" << getTotal(player) << endl;

            ///if total is more than 21
            //player lose
            if (getTotal(player) > 21) {
                cout << "--- unlucky player more than 21 ---" << endl;
                return;
            }
        }

        ///player stand
        else {
            cout << "player stand" << endl << endl;
            break;
        }
    }
    ///end player turn


    ///bot's turn
    cout << "bot's turn" << endl;
    int bot_choice;

    while (true) {
        cout << "bot is thinking ";

        /// Just a gimmick (=^._.^=) sleep for delay the program in millisec use windows.h
        for (int i = 0; i < 3; ++i) {
            Sleep(1000);
            cout << ". ";
        }
        cout << endl << endl;

        srand(time(NULL));

        ///set bot's choice ; 0 = bot stand , 1 = bot hit (draw)
        //if bot's total is less than player's total always draw a card
        if (getTotal(bot) < getTotal(player))
            bot_choice = 1;

        //if bot's total is = player's total and bot's total is less than 17, rng to draw or not
        else if (getTotal(bot) == getTotal(player) && getTotal(bot) < 17)
            bot_choice = rand() % 2;

        else
            bot_choice = 0;

        ///run bot choice (hit/stand)
        //bot_choice = 1 draw a card then show cards in bot pile and total
        if (bot_choice == 1) {
            cout << "bot HIT!" << endl << endl;
            Sleep(1000);
            deck.drawAndInsertTo(bot);
            bot.showPile();
            cout << "bot total :" << getTotal(bot) << endl;

            //check is total more than 21? (bot lose)
            if (getTotal(bot) > 21) {
                cout << "$$$ Lucky bot more than 21 $$$" << endl;
                return;
            }

        // bot_choice = 0 stand do nothing
        } else {
            cout << "bot stand" << endl;
            break;
        }
    }


    ///check for winner when everyone end turn
    //equal
    if (getTotal(player) == getTotal(bot))
        cout << "??? Nah... PUSH ???" << endl;

    //bot win
    else if (getTotal(player) < getTotal(bot))
        cout << "--- Nah... bot win ---" << endl;

    //player win
    else if (getTotal(player) > getTotal(bot))
        cout << "$$$ player win $$$" << endl;

    //end game
}

