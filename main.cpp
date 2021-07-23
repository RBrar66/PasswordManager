#include <iostream>
using namespace std;
#include "PasswordGenerator.h"
#include "PasswordStorage.h"

int main(){
    int x = 0;
    while (x != 1 && x != 2) {
        cout << "Enter 1 to generate passwords. \nEnter 2 to access password storage." << endl;
        cin >> x;
    }
    if (x == 1) {
        password1(); //calls password generator

    }
    else {
        password2(); //calls password storage

    }
}