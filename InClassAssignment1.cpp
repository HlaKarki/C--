/*  CS132 Mini - programming Assignment
 *  cStrings
 *
 *  Complete the following program by writing the code
 *  for the 4 neccessary methods that are prototyped below.
 *  Do not make any changes to the main or the prototypes.
 *
 *  For this assignment you may not use the string data type.
 *
 *  Hint,  you might want write the last method first so that you
 *  can use it in the 3rd method.
 *
 *  Good luck.
 */

//--------------------------------------------------------------------------
// Hla Htun
// April 10 2020
//
// This program will manipulate cstrings without using any string tools

#include <iostream>

using namespace std;


void upperCase_cString(char[]);
void lowerCase_cString(char[]);
void reverse_cString(char[]);
int find_len_cString(char[]);


int main()
{
    char a[] = "Hello World";
    char b[] = {'M','i','c','k','y',' ','M','o','u','s','e','\0'};
    char c[] = "abcdefghijklmnopqrstuvwxyz";
    char d[] = "ABCDE...VWXYZ";
    char e[] = "This is a test \0 OF THE END OF STRING CHARACTER";

    cout << "BEFORE" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << endl << "AFTER" << endl<< endl<< endl;

    upperCase_cString(a);
    cout << a << endl;

    lowerCase_cString(b);
    cout << b << endl;

    reverse_cString(c);
    cout << c << endl;
    
    reverse_cString(d);
    cout << d << endl;
    
    reverse_cString(e);
    cout << e << endl;

    cout << find_len_cString(d) << endl;
    cout << find_len_cString(e) << endl;

}
//This method takes in the cstring and change every character to upper case even if some of them were already in uppercase form
void upperCase_cString(char str[]){
    int wSize = find_len_cString(str);
    for(int i =0 ; i<wSize; i++){
        str[i] = toupper(str[i]);
        
    }
}

//This method takes in the cstring and change every character to lower case even if some of them were already in lowercase form
void lowerCase_cString(char str[]){
    int wSize = find_len_cString(str);
    for(int i =0 ; i<wSize; i++){
        str[i] = tolower(str[i]);
        
    }
}

//This method will reverse the cstring
void reverse_cString(char str[]){
    
    //this method will only reverse the number of characters that the fin_len_cString returns so that way
    //i dont have to check for '\0' here again
    int dSize = find_len_cString(str);
    int counter = dSize;
    char dupli[dSize];
    
    for(int i=0; i<dSize; i++){
        dupli[counter-1]=str[i];
        counter--;
    }
    
    for(int i = 0; i<dSize; i++){
        str[i]=dupli[i];
    }
}


//this method finds the length of the cstring
int find_len_cString(char str[]){
    int len = 0;
    int i = 0;
    
    //as long as i is not at '\0' keep looping
    while (str[i]!='\0'){
        
        len++;
        i++;
    }
    return len;

}
