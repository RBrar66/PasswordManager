#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//encrypts the word
string encrypt(string word, string masterpass){
    for(int i = 0, j = 0; i < word.size(); ++i, ++j){
        if(j == masterpass.size()) j = 0;
        word[i] = word[i] - masterpass[j] + 62; //encryption algorithm
    }
    return word;
};

//decrypts the word
string decrypt(string word, string masterpass){
    for(int i = 0, j = 0; i < word.size(); ++i, ++j){
        if(j == masterpass.size()) j = 0;
        word[i] = word[i] + masterpass[j] - 62; //decryption algorithm
    }
    return word;
};

//views passwords in storage
void view(string masterpass){
    fstream myFile;
    myFile.open("password.txt", ios::in);
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            cout << decrypt(line, masterpass) << endl; //decrypts each line in password.txt and prints it out
        }
        myFile.close();
    }
};

//adds password
void add(string masterpass){
    string website, username, password;
    cout << "Enter website:";
    cin >> website;
    cout << "Enter username:";
    cin >> username;
    cout << "Enter password:";
    cin >> password;

    string line;
    line = website + "    " + username + "    " + password;
    line = encrypt(line, masterpass); //encrypts website + username + password

    fstream myFile;
    myFile.open("password.txt", ios::app); //adds data to password.txt file
    if(myFile.is_open()){
        myFile << line << endl;
        myFile.close();
    }

};


void password2(){
    cout << "Enter Master Password:";
    string masterpass;
    cin >> masterpass;
    string viewadd;
    while(viewadd != "view" && viewadd != "add"){
        cout << "Do you want to view your passwords or add a new password (view, add)?";
        cin >> viewadd;
    }
    if(viewadd == "add"){
        add(masterpass);
    }
    else{
        view(masterpass);
    }
};
