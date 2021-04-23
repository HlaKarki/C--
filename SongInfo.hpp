//
//  SongInfo.hpp
//  MiniAssignment3
//
//  Hla Htun
//  April 21st 2021
//  This .hpp file contains all the prototypes for the constructors and methods requried for the main class to work
//  It also consists of private variables

#ifndef SongInfo_hpp
#define SongInfo_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


class SongInfo
{
public:
    SongInfo();
    SongInfo(string);
    SongInfo(string, int);
    SongInfo(string, int, double);
    
    double getTime();
    void printSong();
    
private:
    string songName;
    int songYear;
    double songDuration;
};



#endif /* SongInfo_hpp */
