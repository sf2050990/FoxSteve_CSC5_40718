/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 16, 2015, 12:25 PM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_11
 *          Number of organisms
 */
// System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int CONPERC=100;                       //Global constant to convert percent into decimal

int main()
{
    //Initialize Variables
    float numOrgsm;                          //number of organism
    int numDays;                             //number of days
    int count=1;                             //Counter for loop
    float rateInc;                           //Rate of increase in percent
    float totRate;                           //Rate of increase in decimal
    
    //Prompt user for number of organisms, the rate of increase, and number of days
    cout<<"How many organism are there?"<<endl;
    cin>>numOrgsm;
    
    cout<<"What is their average daily increase as a percent?"<<endl;
    cin>>rateInc;
    
    cout<<"What is the number of days they will muliply?"<<endl;
    cin>>numDays;
   
    //Output of day one
    cout<<"Day 1:  "<<numOrgsm<<" Organisms"<<endl;
    //Loops until the number of days equals loop rotation
    while(count<numDays)
    { 
      //Counter increments with every loop rotation  
      count++;  
      //Calculates total rate
      totRate=(rateInc/CONPERC);
      //Calculates number of organisms on a given day
      numOrgsm+=totRate*numOrgsm;
      //Outputs day and the number of organisms
      
      cout<<"Day "<<count<<":  "<<static_cast<int>(numOrgsm)<<" Organisms"<<endl; 
       
   
    }
        //Exit program    
        return 0;
}