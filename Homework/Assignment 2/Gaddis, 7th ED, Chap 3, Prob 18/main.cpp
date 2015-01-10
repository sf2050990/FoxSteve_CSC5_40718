/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 9, 2015, 4:57 PM
 * Purpose: Our first program
 * I am at github
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Initialize Variables
    float slice=14.125;                  //Area of a slice in inches
    float dMeter;                        //Diameter in inches
    float tSlice;                        //Total slices
    float area;                          //Area of a circle
    
    //Prompt the user to enter the diameter of a pizza
    cout<<"What is the diameter of the pizza?";
    cin>>dMeter;
    
    //Calculates the area of a circle 
    area=3.14159*dMeter;
    
    //Ouput the area of pizza
    cout<<"The area of this pizza is "<<area<<" inches"<<endl;
    
    //Calculates total slice
    tSlice=area/slice;
    
    //Output the number of slices in a given pizza
    cout<<setprecision(0)<<fixed;
    cout<<"The number of slices in this pizza is "<<tSlice;
    
    return 0;    
}


