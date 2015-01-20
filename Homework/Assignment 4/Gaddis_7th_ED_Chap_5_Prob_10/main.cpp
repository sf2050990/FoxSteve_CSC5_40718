/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 19, 2015, 10:25 AM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_10
 *          Average rainfall
 */
// System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int ANNUAL=12;            //Global constant for the number of months in a yeat
//Execution Begins Here!

int main()
{
    int years;                  //Number of years
    float rain=0;               //rain in inches for one month
    float average;              //Average rainfall in given period
    float totRain;              //Total amount of rain in a given period
    int month;                  //Accumulates months
    int totMonth;               //Total number of months
    
    //Prompt user for number of years
    cout<<"Please enter the number of years in question?"<<endl;
    cin>>years;
    
    //Loops for given number of years
    for(int count=1;count<=years;count++)
    {
        //Loops through a 12 month cycle and prompts user for rainfall in a given month
        for(int month=1;month<=12; month++)
        {
            cout<<"Please enter the amount of rainfall  in inches for year #"<<count<<" month #"<< month;
            cin>>rain;
            //Accumulates total amount of rain in inches
            totRain+=rain;
            
        }
        //Accumulates number of months
        totMonth+=ANNUAL;
    }
    //Outputs total months, rainfall, and average rainfall
    cout<<"The number of months is "<<totMonth<<endl;
    cout<<"The total amount of rain fall in inches is "<<totRain<<" inches."<<endl;
    //Calculates Average rainfall
    average=totRain/totMonth;
    cout<<"The average rainfall for the given period is "<<average<<" inches."<<endl;
    
    //End Program
    return 0;
}