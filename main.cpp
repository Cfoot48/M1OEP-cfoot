//
// Kincaid Foot OEP 1
//
using namespace std;
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "User.h"
#include "Computer.h"

int main(){
    //declare variables
    int learn;
    bool validate1 = true;
    srand(time(0));
    int money;
    cout << "Welcome to Blackjack! Press 1 to learn or press 2 to play, and at any point press 3 to end your game." << endl;
    while (validate1){
        cin >> learn;
        if (learn == 1){
            cout << "Blackjack is a simple game: You and the dealer will be given two cards." << endl;
            cout << "You will be able to see both of your cards but one of the dealers will be hidden." << endl;
            cout << "You will have the option to hit or stand. If you hit you will be given a 3rd card." << endl;
            cout << "If you stand the dealer's other card will be revealed and the dealer will hit." << endl;
            cout << "The dealer will hit until they reach 17 or go over 21." << endl;
            cout << "Your goal is to get as close to 21 as you can without going over, but you must also be higher than the dealer." << endl;
            cout << "Have fun!" << endl;
            cout << endl;
            validate1 = false;
        }
        else if (learn == 2)
            validate1 = false;
        else {
            cout << "Please only enter a 1 or a 2" << endl;
            cin.clear();
            string junk;
            getline(cin, junk);
        }
    }
    //initialize the hands that are being dealt
    User user((1 + (rand() % 11)),(1 + (rand() % 11)));
    Computer dealer((1 + (rand() % 11)),(1 + (rand() % 11)));
    cout << "The game is now beginning. You have been deal the cards: " << user.getCard1() << " and " << user.getCard2() << endl;
    cout << "You have a total of " << user.cardTotal() << endl;
    cout << "The dealer was dealt: " << dealer.getCard1() << endl;
    switch(user.cardTotal())
    {
        case 21:
            cout << "Congrats, you got blackjack! You win!" << endl;
        default:
            int decision1;
            int decision2;
            cout << "Would you like to hit or stand? Enter 1 for hit 2 for stand" << endl;
            cin >> decision1;
            if (decision1 == 1){
                int hit1 = user.hit(user.cardTotal());
                if (hit1 > 21)
                    cout << " Unfortunately you bust, you went over 21 with a total of " << hit1 << endl;
                else if (hit1 == 21)
                    cout << " You win! You have 21!" << endl;
                else{
                    cout << " Would you like to hit or stand? Enter 1 for hit 2 for stand " << endl;
                    cin >> decision2;
                        if (decision2 == 1){
                            int hit2 = user.hit(user.cardTotal());
                            if (hit2 > 21)
                                cout << "Unfortunately you bust, you went over 21 with a total of " << hit1 << endl;
                            else if (hit2 == 21)
                                cout << "You win! You have 21!" << endl;
                            else
                                cout << "UH OH" << endl;

                        }
                }
            }





    }



    return 0;
};