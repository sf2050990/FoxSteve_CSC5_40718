/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 12, 2015, 9:05 PM
 * Purpose: Gaddis_7th_ED_Chap_4_Prob_22
 * 
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float rate1=.12;                      //Rate of a call between 0 and 6.59 minutes
    float rate2=.55;                      //Rate of a call between 7 and 19 minutes
    float rate3=.35;                      //Rate of a  call between 19.01 and 23.59
    float time;                           //Time when call began 
    float mins;                           //Number of minutes the call lasted
    float secs1;                          //Holds the seconds value for time;
    float secs2;                           //Holds the second value for minutes
    float total;                          //Total bill
    
    //Prompt for when the call took place
    cout<<"At what time the phone call begin (please enter in 00.00 format)"<<endl;
    cin>>time;
    
    //Prompt for how many minutes the call lasted
    cout<<"How many minutes did this phone call last? (please enter in 00.00 format)"<<endl;
    cin>>mins;
  
    //converts the number of minutes from float to int and subtracts itself from its float value for time variable
    secs1=time-static_cast<int>(time);
    
    //converts the number of minutes from float to int and subtracts itself from its float value for mins variables
    secs2=mins-static_cast<int>(mins);
    
            //Conditionally executes an error message if seconds value is greater than .59
            if(secs1>.59||secs2>.59)
                    cout<<"Error:  Minutes must be less than 59";
   
                   //Conditionally executes if time is less than 24 minutes in addition 
                   //To minutes being between 0 and 6.59 minutes
                    else if(time<23.95&&mins>=0&&mins<=06.59)                                   
                      {
                       cout<<setprecision(2)<<fixed<<showpoint;
                       total=rate1*mins;
                       cout<<"Your total bill for this phone call is $"<<total;
                      }
                   //Conditionally executes if time is less than 24 minutes in addition 
                   //To minutes being between 7 and 19 minutes
                  else if(time<23.95&&mins>=07.00&&mins<=19.00)
                      {  cout<<setprecision(2)<<fixed<<showpoint;
                        total=rate2*mins;
                        cout<<"Your total bill for this phone call is $"<<total;
                      }   
                   //Conditionally executes if time is less than 24 minutes in addition 
                   //To minutes being between 19 and 23.59 minutes
                  else if(time<23.95&&mins>=19.01&&mins<=23.59)
                      {  
                       cout<<setprecision(2)<<fixed<<showpoint;
                       total=rate3*mins;
                       cout<<"Your total bill for this phone call is $"<<total;
                      } 
                    //Conditionally executes if user enters a invalid time 
                   else
                    { cout<<"ERROR: You must enter a valid time between 00.01-23.59"<<endl;
                     cout<<"Please run the program again";
                    }
    
    //Exit program
    return 0;
}