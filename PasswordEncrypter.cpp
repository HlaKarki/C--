/* This is the primary initial file for
 * CS 132 Assignment #2.  The purpose of this file
 * is to create a simplistic encryption tool to store and
 * reload user names and passwords.   In doing so
 * the user will use stings and string manipulation.
 *
 * version 4.0 - Modified for new version of assignment.
 * version 3.1 - Fixed the cin error
 * version 3.0 - updated to new assignment.
 * version 2.0 - updated to new assignment.
*/

//Hla Htun
//April 17th 20201
//
//This program will ask you to either add a password or check if a password is already recorded in the file
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void addToFile(string fname);
void checkFile(string fname);

//helper functions
bool isPassPossible(string);
string toUpperCase(string);
string stringToMorse(string, vector<string>, vector<string>);

 int main()
 {
     string userPassword;
     int option;

     cout << "***************************************************************" << endl;
     cout << "Hello and welcome to the CS132 Ultra Secure Password Checker   " << endl;
     cout << "***************************************************************" << endl;

     while (true)
     {
        const string fileName = "masterFile.txt";
        string input;
        do
        {
            cout << "Would you like to test a password, or add a password?" << endl;
            cout << "  1 : for test a password"<< endl;
            cout << "  2 : for add a password" << endl;
            cout << "  3 : to quit" << endl;
            cout << "  >>> ";

            getline(cin,input);
            option = stoi("0"+input);
        } while (option < 1 || option > 3);
        
         
        if (option == 1)
        {
            checkFile(fileName);
        }
        else if (option == 2)
        {
            addToFile(fileName);
        }
        else if (option == 3)
        {
            cout << endl << "Thank you, have a good day." << endl << endl;
            return 0;
        }
        else
        {
         // This is an error state, this should never happen.
         cerr << "ERROR invalid option" << endl;
         return 99;

        }

     } // End of the while(true);

     // The program did not leave correctly.
     //cerr << "ERROR illegal loop exit." << endl;
     //return 100;

 }
//This method will add a password to the masterFile.txt by first checknig if the input password
//follows the specified rules for a password
//if it is, then it will turn the password into morse code one character at a time and then add it to the file
void addToFile(string fname){
    
    ifstream forVec;
    string lines;
    int divider = 0;
    vector<string> characters;
    vector<string> morseCode;
    
    forVec.open("MorseCode.txt");
    if(!forVec) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    //putting the characters into one vector and the corresponding morse code in another vector
    while(forVec >> lines){
        if(divider==0) characters.push_back(lines);
        
        if(divider==1) morseCode.push_back(lines);
        
        divider++;
        if(divider>1){
            divider=0;
        }
        //cout << lines << endl; //debug
    }
    
    forVec.close();
    
    string userPass;
    
    cout << endl;
    cout << "Type in the password you would like to test: " << endl;
    getline(cin, userPass);
    
    //call the helper function to check if the entered password follows the rules
    string userPassnowMorse = "";
    if(isPassPossible(userPass)){
        //if the password is legit, firstly change it to all uppercase since the letters are upper case in the morse code file
        //then take each character and call another helper funciton stringToMorse to turn it into morse code
        
        userPass = toUpperCase(userPass);
        for(char x: userPass){
            if(isspace(x)){
                userPassnowMorse+= " / ";
            }
            else{
                string y;
                y.push_back(x); //a little trick I recently found online to turn a char to a string
                userPassnowMorse+=stringToMorse(y, characters, morseCode)+ " ";
                
            }
            
        }
        cout << endl << "Your password has been recorded into the database!" << endl << endl;
        
        //now that the password is turned into a morse code, it just needs to be written into the file
        ifstream readfile;
        readfile.open(fname); // opens the file
        if(!readfile) { // file couldn't be opened
            cout << "Error: file could not be opened" << endl;
            exit(1);
        }
        
        string lines;
        string fromfile = "";
        //before we write into the file, first put everything that is inside the file into a single string
        while(getline(readfile, lines)){
            //cout << lines;
            fromfile+=lines+"\n";
        }
        //cout << endl;
        //cout << fromfile << " EMpty?" << endl;
        readfile.close();
        
        
        //now open the file to write into it and put in the passwords already present in the file (now in fromfile string)
        //and then add the password the user put it just now
        //and then close the file
        ofstream outfile;
        outfile.open(fname); // opens the file
        if(!outfile) { // file couldn't be opened
            cout << "Error: file could not be opened" << endl;
            exit(1);
        }
    
        outfile << fromfile;
        outfile << userPassnowMorse << endl;
        
        outfile.close();
        
    }
    //if the password didnt follow the rules, it is specified to the user again
    else{
        cout << endl << "Your password is not acceptable, please make sure it is follwing the rules shown below." << endl;
        cout << "It must be at least 14 characters long." << endl
             << "It must contain at least 8 letters." << endl
             << "It must contain at least 3 numbers" << endl
             << "It must contain at least 1 valid symbol" << endl << endl;
    }
    
   
}

//this method will check if the password entered by the user matches any of those from the masterFile.txt
void checkFile(string fname){
    ifstream forVec;
    string lines;
    int divider = 0;
    vector<string> characters;
    vector<string> morseCode;
    
    forVec.open("MorseCode.txt");
    if(!forVec) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    //again, prepare two vectors to store the morse code and cooresponding letters/characters
    while(forVec >> lines){
        if(divider==0) characters.push_back(lines);
        
        if(divider==1) morseCode.push_back(lines);
        
        divider++;
        if(divider>1){
            divider=0;
        }
        //cout << lines << endl;
    }
    
    forVec.close();
    //now ask the user for the password
    string enteredPass;
    string passFromFile;
    string userPassnowMorse = "";
    
    cout << "Please enter the password: ";
    getline(cin, enteredPass);
    //change it to uppercase using another helper function
    enteredPass = toUpperCase(enteredPass);
    //makeitTrim(enteredPass);
    for(char x: enteredPass){
        //cout << x << endl;
        if(isspace(x)){
            userPassnowMorse+= " / ";
        }
        else{
            string y;
            y.push_back(x);
            userPassnowMorse+=stringToMorse(y, characters, morseCode)+ " ";
            
        }
        
    }
    //now that the user-entered password is turned into morse code,
    //check with the masterFile.txt to see if there is any match
    ifstream readfile;
    readfile.open(fname); // opens the file
    bool matchOrNoMatch = false;
    
    if(!readfile) { // file couldn't be opened
        cout << "Error: file could not be opened" << endl;
        exit(1);
    }
    //if there is a match, make the boolean value true
    while(getline(readfile, passFromFile)){
        
        if(passFromFile==userPassnowMorse){
            matchOrNoMatch = true;
        }
        
    }
    //matched or not matched, let the user know
    if(matchOrNoMatch)  cout << endl << "Your password matched the one from our databse and your access has been allowed." << endl << endl;
    
    else    cout << endl << "Your password did not match the ones from our databaes.\nYour access has been denied."  << endl << endl;
    
    readfile.close();
    
    
}

//helper function which takes in two string vectors and a string and turns the string into a morse code and returns it
string stringToMorse(string x, vector<string> characters, vector<string> morseCode){
    
    //find the string x and checking against the characters vector
    //if matched, use the index i and call the morse code at that index to get the coresponding morse code for that character
    for(int i=0; i<characters.size(); i++){
        //cout << x << endl;
        if(x==characters[i]){
            return morseCode[i];
        }
    }
    //***********//
    //if the user entered any symbol which was not specified in the morse code file, then return that string as it is
    //basically saying dont do anything to that character
    return x;
}

//helper function which checks if the password entered follows all the rule, returns a bool value
bool isPassPossible(string pass){
    
    //bool yesorno;
    int countLetter = 0;
    int countNumber = 0;
    int countSymbol = 0;
    
    if(pass.size()>=14){
        
        for(char x: pass){
            
            if(isalpha(x)){
                countLetter++;
            }
            
            else if(isnumber(x)){
                countNumber++;
            }
            
            else{
                if(x=='.' || x=='?' || x=='!' || x==' ' || x==','){
                    countSymbol++;
                    //cout << x << " is a symbol or space" << endl;
                }
            }
        
        }
        
        if(countLetter>=8 && countNumber>=3 && countSymbol>=1){
            return true;
        }
        else
            return false;
    }
    else
        return false;
    
}

//helper function which turns a sting into upper case one and returns it
string toUpperCase(string pass){
    string newPass = "";
    for(char x: pass){
        x = toupper(x);
        newPass+=x;
    }
    
    return newPass;
}

