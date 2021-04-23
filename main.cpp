/**
 *    This is the main/driver program for the student created
 *    "SongInfo" class.   Your class should implement the necessary
 *    methods and fields to make the following code work without issues.
 *
 *    You should not change this program in anyway, your class should
 *    adjust to make this work.
 */
#include <iostream>
#include <iomanip>
#include "SongInfo.hpp"

using namespace std;

int main()
{
    SongInfo myPlayList[10];
    // These five work like normal.
    myPlayList[0] = SongInfo("16 Tons", 1987, 2.75);
    myPlayList[1] = SongInfo("Beautiful Day", 2000, 4.1215);
    myPlayList[2] = SongInfo("Axel F", 1984, 4.65);
    myPlayList[3] = SongInfo("Christmas in Sarajevo", 1996, 3.41);
    myPlayList[4] = SongInfo("Bring Me to Life", 2003,3.95);

    // This one has an invalid year
    myPlayList[5] = SongInfo("The Gambler", 1981, -4.5);

    // Invalid time
    myPlayList[6] = SongInfo("What a wonderful World", -1947, 2.26);

    // 2 parameter Constructor
    myPlayList[7] = SongInfo("If I could turn back time",1989);

    // 1 parameter Constructor
    myPlayList[8] = SongInfo("In the Air Tonight");

    // 0 parameter Constructor
    myPlayList[9] = SongInfo();


    // Print out the song data.
    // Note that it only prints out data that is valid.
    for(int i = 0; i < 10 ; i++)
    {
        myPlayList[i].printSong();
    }

    // Find the total time.
    double totalTime = 0;
    for(SongInfo x : myPlayList)
    {
        totalTime += x.getTime();
    }

    cout << endl << endl
         << "The total known time of the play list is "  << setprecision(1)
         << fixed << totalTime << " minutes." << endl;
}
