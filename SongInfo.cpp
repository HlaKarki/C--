//
//  SongInfo.cpp
//  MiniAssignment3
//
//  Hla Htun
//  April 21st 2021
//  This method contains all the constructors and methods required for the main class to work

#include "SongInfo.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//default constructor
//it sets the song name to Unknwon and the year and duration to zero.
SongInfo::SongInfo(){
    songName = "Unknown";
    songYear = 0000;
    songDuration = 00.00;
    
}
//this is a constructor with only one peremeter, songname
//it sets the name of the song to the user defined name but sets the other two variables as 0

SongInfo::SongInfo(string name){
    songName = name;
    songYear = 0000;
    songDuration = 00.00;
}

//This constructor has two parameter, songname and the year
//Now the songname and the year are set as the input values however, the duration is still 0
SongInfo::SongInfo(string name, int year){
    songName = name;
    songYear = year;
    songDuration = 00.00;
}

//This constructor consists of all the data for the song class
SongInfo::SongInfo(string name, int year, double time){
    songName = name;
    songYear = year;
    songDuration = time;
}

//this method returns the duration of a song
//it first checks if the duration of a song is in negative
//if it is, then it just returns 0
double SongInfo::getTime(){
    if(songDuration <0){
        return 0;
    }
    else
        return songDuration;
}

//this method prints the details of a song in a particular format
//while doing so, it also checks if there are any invalid data present in the song class data.
//if there is, it deals with it by not prininting that invalid data out
void SongInfo::printSong(){
    cout << fixed << setprecision(2);
    
    if(songYear <= 0 && songDuration >0){
        cout << "Song - " << left << setw(30) << songName
        << setw(5) << ": length - " << songDuration << " minutes" << endl;
    }
    else if(songDuration <= 0 && songYear >0){
        cout << "Song - " << left << setw(30) << songName
        << ": recorded in the year " << setw(10)  << songYear << endl;
        
    }
    else if(songYear <=0 && songDuration <= 0){
        cout << "Song - " << left << setw(30) << songName << endl;
    }
    else{
        cout << "Song - " << left << setw(30) << songName
        << ": recorded in the year "  << songYear << setw(5) << ": "  << "length - "
        << songDuration << " minutes" << endl;
    }
    
}
