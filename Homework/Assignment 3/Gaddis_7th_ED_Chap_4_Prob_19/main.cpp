/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 6, 2015, 6:05 PM
 * Purpose: Gaddis 7th Ed Chap 4 Prob 19
 *          Rate of sound
 */
// System Libraries
#include <iostream>
using namespace std;

//Global variables 
 const float carbDio=258.0;                   //Constant rate of sound through carbon dioxide in 1 meters pers second
 const float air= 331.5;                      //Constant rate of sound through air in 1 meters pers second
 const float helium=972.0;                    //Constant rate of sound through helium in 1 meters pers second
 const float hydrgen=1270.0;                  //Constant rate of sound through hydrogen in 1 meters pers second

//Execution begins here
int main()
{ 
    //Initialize variables
    unsigned short choice;                 //Holds menu choice for type of gas
    unsigned short secs;                   //Number of seconds
    float answer;                          //Conditionally calculates answer pending on menu choice
    
    //Prompt user to enter a selection from the menu
    cout<<"Please select a gas"<<endl;
    cout<<"1:Carbon Dioxide"<<endl;
    cout<<"2:Air"<<endl;
    cout<<"3:Helium"<<endl;
    cout<<"4:Hydrogen"<<endl;
    cin>>choice;
    
     //Validates whether the menu selection is between 1 and 4 
    if(choice<1||choice>4)
        cout<<"ERROR! Your choice must be between 1-4.";
    else{    
    
    //Prompts user to enter thee number of seconds elapsed until the sound is heard
    cout<<"Please enter the number of seconds"<<endl;
    cin>>secs;
        
    //Validates whether the amount of seconds is between 1 and 30
    if  (secs<1||secs>=30)
        cout<<"ERROR! The seconds must be between 1-30.";
    else{
    //Conditionally executes statements based on menu selection    
    switch(choice)
    {
        case 1:cout<<"You have chosen carbon dioxide"<<endl;
                 cout<<"You have entered "<<secs<<" second."<<endl;
                 answer=carbDio*secs;
                 cout<<"The source of the sound was "<<answer<<" meters away.";
                       break;
        case 2:cout<<"You have chosen air"<<endl;
                 cout<<"You have entered "<<secs<<" second."<<endl;
                 answer=air*secs;
                 cout<<"The source of the sound was "<<answer<<" meters away.";
                       break;
        case 3:cout<<"You have chosen helium"<<endl;
                 cout<<"You have entered "<<secs<<" second."<<endl;
                 answer=helium*secs;
                 cout<<"The source of the sound was "<<answer<<" meters away.";
                       break;
        case 4:cout<<"You have chosen hydrogen;"<<endl;
                 cout<<"You have entered "<<secs<< " second."<<endl;
                 answer=hydrgen*secs;
                 cout<<"The source of the sound was "<<answer<<" meters away.";
                        break;
    }
    }
    }
    //Exit program
    return 0;
}