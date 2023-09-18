//
// Kincaid Foot OEP 1
//
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "User.h"
#include "Computer.h"

int main(){
    //declare variables
    int learn;
    bool validate1 = true;
    bool validate2 = true;
    bool validate3 = true;
    srand(time(0));
    int money = 5000;
    int bet;
    int replay;
    bool re = true;
    cout << "Welcome to Blackjack! Press 1 to learn or press 2 to play" << endl;
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

    while (re) {

        //initialize the hands that are being dealt
        User user((1 + (rand() % 11)), (1 + (rand() % 11)));
        Computer dealer((1 + (rand() % 11)), (1 + (rand() % 11)));
        cout << "You have $" << money << endl;
        while(validate2) {
            cout << "How much would you like to bet?" << endl;
            cin >> bet;
            if (cin.fail()){
                cout << "Please input a numerical value:" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (bet > money || bet < 0){
                cout << "You can only bet between 1 and " << money << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                validate2 = false;

        }
        cout << endl;
        cout << "The game is now beginning. You have been dealt the cards: " << user.getCard1() << " and "
             << user.getCard2() << endl;
        cout << "You have a total of " << user.cardTotal() << endl;
        cout << "The dealer is showing: " << dealer.getCard1() << endl;
        int userTotal = user.cardTotal();
        int dealerTotal = dealer.cardTotal();
        switch (userTotal) {
            case 21:
                cout << "Congrats, you got blackjack! You win!" << endl;
                break;
            default:
                //gets weather the player would like to hit or stand and runs through a loop until they choose to stand
                int decision1;
                cout << "Would you like to hit or stand? Enter 1 for hit 2 for stand" << endl;
                bool loop = true;
                while (loop) {
                    cin >> decision1;
                    if (decision1 == 1) {
                        int hit = user.hit(userTotal);
                        userTotal = userTotal + hit;
                        if (userTotal > 21) {
                            cout << " Unfortunately you bust, you went over 21 with a total of " << userTotal << endl;
                            userTotal = 0;
                            loop = false;
                        } else if (userTotal == 21) {
                            cout << " You win! You have 21!" << endl;
                            loop = false;
                        } else {
                            cout << " Would you like to hit or stand? Enter 1 for hit 2 for stand " << endl;
                        }
                    } else if (decision1 == 2){
                        //after standing this runs through the dealer's hits until they are at or over 21
                        cout << "The dealer's second card is " << dealer.getCard2()
                             << " This gives the dealer a total of " << dealerTotal << endl;
                        dealerTotal = dealer.hit(dealerTotal);
                        if (dealerTotal > 21) {
                            cout << "The dealer bust!" << endl;
                            dealerTotal = 0;
                        }
                        loop = false;
                    }else{
                        cout << "Please only enter 1 or 2" << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }

                }
                //displays win message and adjusts money based on the bet size
                if (userTotal > dealerTotal) {
                    cout << "You win!" << endl;
                    money = money + bet;
                }
                else if (userTotal == dealerTotal) {
                    cout << "Its a draw" << endl;
                }
                else if (userTotal < dealerTotal) {
                    cout << "You lose :(" << endl;
                    money = money - bet;
                }
        }
        //Validated input to determine if the user would like to play again
        cout << "You now have $" << money << " Would you like to play again? 1 to replay 2 to quit" << endl;
        while (validate3) {
            cin >> replay;
            if (replay == 2) {
                re = false;
                validate3 = false;
                validate2 = true;
            }
            else if (replay == 1) {
                re = true;
                validate3 = false;
                validate2 = true;
            }
            else if (cin.fail()) {
                cout << "Please only enter 1 or 2" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                cout << "Please only enter 1 or 2" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        if (money == 0){
            re = false;
            cout << "Unfortunately you are out of money and cannot play again" << endl;
        }
        validate3 = true;
    }
    return 0;
};