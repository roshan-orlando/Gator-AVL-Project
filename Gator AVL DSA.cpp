// Gator AVL DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include "AVL.h"

using namespace std;

/* Note:
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope.
*/

//Data Validation Functions
bool isValidId(string id) { //Checking for a valid gator id
    if (id.size() != 8) { // UFID should be 8 digits long
        return false;
    }
    for (char c : id) {
        if (!isdigit(c)) { // All characters must be digits if not it is not a valid id
            return false;
        }
    }
    return true;
};

bool isValidName(string name) { //Checking for a valid name entry
    for (char c : name) { //Iterating through every character in the name we must check whether we have a letter
        // or if its a space. If it's neither it is a invalid name
        if (!isalpha(c) && !isspace(c)) { 
            return false;
        }
    }
    return true;
};


int main()  //https://www.digitalocean.com/community/tutorials/getline-in-c-plus-plus used for help regarding getline and sstream
{
    AVLTree dsa; //Creating our AVLTree object using a empty object
    int numOfCommands = 0;
    cin >> numOfCommands; //Getting the number of commands 

    string input; //Whole line input, which is then split up into the command, input, and id
    
  
    //getLine will move the input to the newline.
    getline(cin, input); 

    for (int i = 0; i < numOfCommands; i++) { //Looping through the number of commands
        string iFunction; //These strings will hold information about the input 
        string iName;
        string iId;
        getline(cin, input);
        istringstream iss(input);
        iss >> iFunction;  //Using stringstream to get the command input
        if (iFunction == "insert") {
            getline(iss >> ws, iName, '\"');
            getline(iss, iName, '\"');
            iss >> iId;
            if (isValidName(iName) && isValidId(iId)) {
                dsa.insert(iName, iId);
            }
            else {
                cout << "unsuccessful" << endl;
            }
        }
        else if (iFunction == "search") {
            string temp; //We are going to check whether the search is a name or id using temp
            getline(iss >> std::ws, temp, '\"');
            getline(iss, temp, '\"');

            if (isValidId(temp)) {
                dsa.searchID(temp);
            }
            else if (isValidName(temp)) {
                dsa.searchName(temp);
            }
            else { //We have reached a invalid search input thats neither a id or valid name
                cout << "unsuccessful" << endl;
            }
        }
        else if (iFunction == "remove") { 
            iss >> iId;
            if (!isValidId(iId)) { //Checking if the id in the input line is a valid ID
                cout << "unsuccessful" << endl;
            }
            else { //If it is we attempt to remove it 
                dsa.remove(iId);
            }
        }
        else if (iFunction == "removeInorder") {
            int n;
            iss >> n;

            dsa.removeInorder(n);
        }
        else if (iFunction == "printLevelCount") {
            dsa.printLevelCount();
        }
        else if (iFunction == "printInorder") {
            dsa.printInorder();
        }
        else if (iFunction == "printPreorder") {
            dsa.printPreorder();
        }
        else if (iFunction == "printPostorder") {
            dsa.printPostorder();
        }
        else { //Invalid command is entered
            cout << "unsuccessful" << endl;
        }

    }
}

