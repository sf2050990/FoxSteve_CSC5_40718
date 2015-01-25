/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 19, 2015, 11:45 PM
 * Purpose: Gaddis_7thh_ED_Chap_5_Prob_9
 *          Room occupancy in a hotel
 */
// System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CONPERC=100;               //Global Constant to convert decimals and percents
//Execution Begins Here!
int main()
{
    int numStory=0;                     //Number of stories
    int rooms=0;                        //Rooms on a given floor
    int occupy=0;                       //Rooms occupied on that floor
    int totOcc;                         //Total rooms occupied
    int notOcc=0;                       //Total not occupied
    float totRoom;                      //Total rooms
    float rateOcc;                      //Rate of occupancy
    
    //Prompt user for the number of stories in the hotel
    cout<<"How many stories does the hotel contain?"<<endl;
    cin>>numStory;
    
    //Loops for every floor in the hotel
    for(int count=1;count<=numStory;count++)
    {   //Prompt user for number of rooms on the floor and the number that are occupied
        cout<<"How many rooms are on floor# "<<count<<endl;
        cin>>rooms;
        
        cout<<"How many rooms are occupied on floor# "<<count<<endl;
        cin>>occupy;
        //Input validation
        while(rooms<occupy)
        {
            cout<<"ERROR. The number of occupants cannot be greater than the number of rooms"<<endl;
            //Prompt user for number of rooms on the floor and the number that are occupied
            cout<<"How many rooms are on floor# "<<count<<endl;
            cin>>rooms;

            cout<<"How many rooms are occupied on floor# "<<count<<endl;
            cin>>occupy;
        }
        //Accumulates the total number of rooms
        totRoom+=rooms;
        //Accumulates the total amount of rooms occupied
        totOcc+=occupy;
    }
    //Calculate the number of rooms that are not occupied
    notOcc=totRoom-totOcc;
    //Calculates the rate of rooms that are occupied
    rateOcc=(totOcc/totRoom)*CONPERC;
    
    //Output total rooms, total rooms that are occupied, number of rooms that are not occupied,
    //and the percentage of rooms that are occupied
    cout<<"The total amount of rooms is "<<totRoom<<" rooms."<<endl;
    cout<<"The number of these rooms that are occupied is "<<totOcc<<" rooms"<<endl;
    cout<<"The number of these rooms that are unoccupied is "<<notOcc<<" rooms"<<endl;
    cout<<"The percentage of rooms that are occupied is "<<rateOcc<<"%"<<endl;
    
    //Exit Program
    return 0;
}