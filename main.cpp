// Hla Htun
// April 3, 2021
//
//
// This program reads in a file and calculates the income tax of the poeple listed in it and then write a new file with income tax as an
// additional data.

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int calculateTaxes(double Income);

int main(){
    
    //cout << "Hello" << endl;
    
    //opening the file and checking if the file exists
    ifstream data;
    data.open("Families.txt");
    
    if(!data){
        cout << "There was an error in opening the file, exiting the program." << endl;
        exit(-1);
        
    }
    
    //if it does exists, then put the name into a vector and the salary into another vector
    string lines;
    int limiter = 0;
    int counter = 0;
    
    vector<string> nameV;
    vector<string> salV;
    
    
    
    while(data>>lines){
        //cout << lines << endl;
        
        if(limiter == 0){
            nameV.push_back(lines);
            
            
        }
        if(limiter == 1){
            salV.push_back(lines);
            counter++;
            
        }
        
        limiter++;
        if(limiter>1){
            limiter = 0;
        }
    }
    
    data.close();
    
    //now the only thing left is to create array for the income tax
    double* incomeTax;
    incomeTax = new double[counter];
    int ArrayLoc = 0;
    
    //cout << "************" << endl;
    
    //go through the salary of each person and call the method for the income tax to be calculated
    //the returned value will be put into the created array for the income tax
    for(int i=0; i<salV.size(); i++){
        //cout << salV[i] << endl;
        
        double income =0.0;
        //changing the string to a double so that the method can be called
        income = atof(salV[i].c_str());
        incomeTax[ArrayLoc] = calculateTaxes(income);
        ArrayLoc++;
        
        
    }
    
    //since everything is ready, it is time to write the processed data into a new file
    //opening new file and checking that it does exists.
    ofstream processedData;
    processedData.open("Data.txt");
    
    if(!processedData){
        cout << "There was an error in opening the file, exiting the program." << endl;
        exit(-1);
    }
    //writing into the file
    for(int i=0 ; i<nameV.size(); i++){
        processedData << setprecision(10);
        
        processedData << nameV[i] << "\t\t\t";
        if(i==1){
            processedData << "- " << salV[i] << setw(5)<< "\t\t";
        }
        else{
            processedData << "- " << salV[i] << setw(5)<< "\t\t\t";
        }
        
        processedData << "- " << "$" << incomeTax[i] << endl;
        
        
    }

    processedData.close();
    
    return 0;
}

//This method will in take the salary and calculate and return the income tax depending on its amount
int calculateTaxes(double Income){
    
    cout << setprecision(10);
    
    if(Income>100000){
        double tax1 = (Income-100000)*0.40;
        double tax2 = 70000*0.25;
        double tax3 = 20000*0.10;
        return tax1+tax2+tax3;
        
    }
    
    else if(Income < 100000 && Income >30000){
        double tax1 = (Income-30000)*0.25;
        double tax2 = 20000*0.10;
        return tax1+tax2;
    }
    
    else if(Income < 30000 && Income > 10000){
        //cout << "correct?" << Income;
        double tax1 = (Income - 10000)*0.10;
        return tax1;
    }
    
    else{
        return 0.0;
    }
    
}
