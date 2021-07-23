#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;


void generate(int len, bool checksc, int i) {
    string password = "";
    srand((unsigned)time(0) + i);
    if (checksc) {
        string possibleChar = "/!@#$%^&*()_+-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; //list of possible password characters including special characters
        for (int i = 0; i < len; ++i) {
            password.push_back(possibleChar[rand() % possibleChar.size()]);
            }
        }

    if (not checksc) {
        string possibleChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; //list of possible password characters without special characters
        for (int i = 0; i < len; ++i) {
            password.push_back(possibleChar[rand() % possibleChar.size()]);
            }
        }
    cout << password << endl;
};


void password1(){
    cout << "Enter password length:";
    int len;
    cin >> len;

    cout << "Enter number of passwords to generate:";
    int n;
    cin >> n;

    string specialChar;
    while (specialChar != "y" && specialChar != "Y" && specialChar != "n" && specialChar != "N") {
        cout << "Use special characters? (y/n): ";
        cin >> specialChar;
        }
    bool checkSpecialChar;
    checkSpecialChar = specialChar == "y" || specialChar == "Y";

    cout << "\nPasswords: \n" << endl;
    for (int i = 0; i < n; ++i) {
        generate(len, checkSpecialChar, i);
        }
};


