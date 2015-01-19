/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 10, 2015, 7:28 PM
 * Purpose:  Gaddis_7th_ED_Chap_4_Prob_18
 *         Time it takes sound to hit an object through different mediums
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;


//Global Constants
const unsigned int air=1100;            //Global constant:the rate in meters per second sound can
                                        //travel in air
const unsigned int water=4900;          //Global constant:the rate in meters per second sound can
                                        //travel in water
const unsigned int steel=16400;         //Global constant:the rate in meters per second sound can
                                        //travel in steel   
//Execution begins here
int main()
{
    //Declare variables
    unsigned short choice;             //Holds the users input for menu selection
    float dis;                         //Holds distance the user inputs of object of interest 
    float totSecs;                     //Holds total number of seconds 
    
    //Prompt user to select from the menu the element they would like to work with
    cout<<"We will be calculating the speed of sound through different mediums"<<endl;
    cout<<"Please select one of the following:"<<endl;
    cout<<"1: Air"<<endl;
    cout<<"2: Water"<<endl;
    cout<<"3: Steel"<<endl;
    cin>>choice;

    //Prompt user to enter the distance in meters from the object of interest
    cout<<"Enter the distance in meters the sound wave will travel to a given object"<<endl;
    cin>>dis;
  
    
    
    //Conditionally executes if distance entered is less than 0
    if(dis<=0)
      cout<<endl<<"ERROR:Distance must be greater than 0. Run the program again";
    //Conditionally executes if requirements for distance have been met
    else
        
        //Conditionally executes pending of the users menu selection
        switch(choice)
        {   //Conditionally executes if air (1) is selected)
            case 1: totSecs=dis/air;
                    cout<<setprecision(4)<<fixed<<showpoint;
                    cout<<"The amount of time it will take for the sound to reach the point of interest in air is "<<endl;
                    cout<<totSecs<< " second.";
                    break;
            case 2: //Conditionally executes if water (2) is selected)    
                    totSecs=dis/water;
                    cout<<setprecision(4)<<fixed<<showpoint;
                    cout<<"The amount of time it will take for the sound to reach the point of interest  water is "<<endl;
                    cout<<totSecs<< " seconds.";
                    break;
           case 3: //Conditionally executes if steel (3) is selected) 
                    totSecs=dis/steel;
                    cout<<setprecision(4)<<fixed<<showpoint;
                    cout<<"The amount of time it will take for the sound to reach the point of interest in steel is"<<endl;
                    cout<<totSecs<< " seconds.";
                    break;
                    //Conditionally executes if menu selection is not 1,2,or 3
        default:cout<<endl<<"ERROR: Please Enter a menu selection 1-3. Run program again";
    }
    
   //Exit program         
    return 0;
}
