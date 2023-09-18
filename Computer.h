//
// Created by Round on 9/13/2023.
//

#ifndef M1OEP_CFOOT_COMPUTER_H
#define M1OEP_CFOOT_COMPUTER_H

#endif //M1OEP_CFOOT_COMPUTER_H
#ifndef M1OEP_CFOOT_HAND_H
#define M1OEP_CFOOT_HAND_H

#endif //M1OEP_CFOOT_HAND_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Computer{
private:
    int card1, card2;
public:

    //Default constructor
    Computer(){
        card1 = 0;
        card2 = 0;
    }
    //Alternate constructor
    Computer(int card1, int card2){
        this->card1 = card1;
        this->card2 = card2;
    }

    /*
    * Gets card1 value
    * Requires: nothing
    * Modifies: nothing
    * Effects: Returns card1 value
    */
    int getCard1() const{
        return card1;
    };
    /*
    * Gets card2 value
    * Requires: nothing
    * Modifies: nothing
    * Effects: Returns card2 value
    */
    int getCard2() const{
        return card2;
    };

    /*
    * Set User Card1
    * Requires: int card value
    * Modifies: int card value
    * Effects: Sets int user card1 value
    */
    void setCard1(int card){
        card = card1;
    }

    /*
    * Set User Card2
    * Requires: int card value
    * Modifies: int card value
    * Effects: Sets int user card1 value
    */
    void setCard2(int card){
        card = card2;
    }

    /*
    * Card Total
    * Requires: nothing
    * Modifies: total card value
    * Effects: adds together both card numbers
    */
    int cardTotal(){
        int total = card1 + card2;
        return total;
    }

    /*
    * Hit function
    * Requires: int total value
    * Modifies: total value
    * Effects: adds a random number 1-11 to the total value
    */
    int hit(int total) {
        while (total < 17) {
            int rand_num = (1 + rand() % 11);
            total = total + rand_num;
            cout << "The dealer drew the card " << rand_num << " The dealer's new total is " << total << endl;
        }
        return total;
    }





};
