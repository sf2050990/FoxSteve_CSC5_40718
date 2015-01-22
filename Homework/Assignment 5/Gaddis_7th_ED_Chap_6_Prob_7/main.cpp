/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 21, 2015, 6:05 PM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_7
 *          Fahrenheit to Celsius
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototype
float celsius(int);                       //Function prototype to convert Fahrenheit  to Celsius  
//Execution Begins Here!
int main()
{
    //Declare variables 
    int degree;                           //Holds degrees Fahrenheit
    float cels;                           //Holds degrees Celsius
    
    //Prompt user for a degree in Farenheit 
    cout<<"Please enter a temperature in fahrenheit and it will be converted to celsius."<<endl;
    cin>>degree;
    //Function call to convert Fahrenheit degree to celsius
    cels= celsius(degree);
    
    //Output degree conversion
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<degree <<" Fahrenheit is equal to "<<cels<<" degrees celsius."<<endl;
    
    //Loops to display table of degrees Fahrenheit from 1-20 and there conversions to Celsius
    for(int count=0;count<=20;count++)
    {
        cout<<"Fahranheit=  "<<setw(3)<<count<<setw(20)<<"   Celsius=    "<<celsius(count)<<endl;
    }
    return 0;
    
    
}
//Function celsius
float celsius(int degree)
{ 
    //Declare variables
    float cels;
    //Convert Fahrenheit to Celsius
    cels=(5/9.0)*(degree-32);
    //Return Value
    return cels;
}
