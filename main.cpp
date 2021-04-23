//
//  Hla Htun
//  14/04/2021
//  MiniAssignment 2
//
//  This program will create a small struct that will hold data related to soccer and will display those data making use of
//  arrays of struck and functions
//

#include <iostream>


using namespace std;

//creating the struct with player name, number and goals scored
struct data{
    string playerName;
    int playerNumber;
    int goalsScored;
};

//prototypes declared below struct so it "knows" what "data" is by this point
void displayData(data);
int displayTotalGoals(data[]);

int main(){
    
    //creating an array of struct and putting values in them
    data setData[5];
    setData[0] = {"Pele", 5, 16};
    setData[1] = {"Lionel", 53, 14};
    setData[2] = {"Diego", 25, 25};
    setData[3] = {"Johan", 12, 2};
    setData[4] = {"Zinedine", 88, 32};
    
    //calling the displayData function to display all the data in setData
    for(int i=0; i<5; i++){
        displayData(setData[i]);
    }
    
    //calling the displayTotalGoal function to display total number of goals scored
    cout << "The total number of goals scored this season is: " << displayTotalGoals(setData) << endl;
    
    return 0;
}


//this function will display the data inside a struct in a neat format
void displayData(data display){
    cout << "Player Name  :  " << display.playerName << endl;
    cout << "Number  :  "<<display.playerNumber << endl;
    cout << "Number of goals this season  :  " << display.goalsScored << endl << endl << endl;
}

//this function will record the total number of goasl scored this season
int displayTotalGoals(data display[]){
    int totGoals = 0;
    for(int i=0; i<5; i++){
        totGoals+= display[i].goalsScored;
    }
    
    return totGoals;
}
