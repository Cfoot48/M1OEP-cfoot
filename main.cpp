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
    srand(time(0));
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
            cout << "Would you like to hit or stand?" << endl;
    }



    return 0;
};