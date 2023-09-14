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

int main(){
    srand(time(0));
    User user((1 + (rand() % 11)),(1 + (rand() % 11)));
    cout << "Welcome to Blackjack! Press 1 to learn or press 2 to play " << endl;
    cout << user.userTotal();
    return 0;
};