/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 9, 2015, 5:25 PM
 * Purpose: Gaddis, 7th ED, Chap 3, Prob 20
 * 
 */
// System Libraries
#include <iostream>
#include <cmath>
using namespace std;


//Beginning of execution
int main()
{ 
    //Intialize Variables 
    float radian;                      //Number of radians
    float sin1;                       //Sin variable
    float logarim;                    //Log variable
    float cosine;                     //Cosine variable 
    
    //Prompt user to enter the number of radians
    cout<<"Please enter an angles radians ";
    cin>>radian;
    
    //Calculate cosine
    cosine=cos(radian);
    
    //Calculate sin
    sin1=sin(radian);
    
    //Calculate log
    logarim=log10(radian);
    
    //Output of cosine, sin, log
    cout<<"The cosine of "<<radian<<" radians is "<<cosine<<endl;
    cout<<"The sin of "<<radian<<" radians is "<<sin1<<endl;
    cout<<"The log of "<<radian<<" radians is "<<logarim;
    
    //Exit program
    return 0;
}