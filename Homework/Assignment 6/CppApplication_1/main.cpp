/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 6, 2015, 6:05 PM
 * Purpose: Our first program
 * I am at github
 */
// System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype

//Execution Begins Here!

int main(int argc, char** argv) 
{
    string prop[40];
    int rent[40][6];
    int count=0;
    
    ifstream inputFile;
    inputFile.open("C:\\Users\\Invictus1\\Desktop\\sf2050990\\FoxSteve_CSC5_40718\\Project1\\Properties.txt");
    while(count<40&&inputFile>>prop[count])
    count++;
    inputFile.close();
    for(int count=0; count<40;count++)
    cout<< "The properties are "<<prop[count]<<endl;
    
    ifstream inputfile;
    inputfile.open("C:\\Users\\Invictus1\\Desktop\\sf2050990\\FoxSteve_CSC5_40718\\Project1\\rent.txt");
    for(int row=0;row<40;row++)   
    {
        for(int cols=0;cols<6;cols++)
            inputfile>>rent[row][cols];
    }
    
      for(int row=0;row<40;row++)   
    {
        for(int cols=0;cols<6;cols++)
        {cout<<rent[row][cols]<<" ";}
        cout<<endl;
    }
    return 0;
}