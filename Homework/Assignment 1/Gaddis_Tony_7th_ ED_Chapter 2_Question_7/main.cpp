/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 11:38 AM
 * Purpose: Gaddis_Tony_7th_ED_Chapter_2_Question_7
 */
// System Libraries
#include <iostream>
using namespace std;

//Global Constants
 const float rise=1.5;     //millimeters
 
int main() 
{
    //Initialize Variables     
    float year5;
    float year7;
    float year10;
    
    //Calculate the rise of the ocean in five, seven, and ten years
    year5=rise*5;
    year7=rise*7;
    year10=rise*10;
    
    //Output the rise of the ocean in five, seven, and ten years
    cout<<"In five years the ocean will rise "<<year5<<" millimeters."<<endl;
    cout<<"In seven years the ocean will rise "<<year7<<" millimeters."<<endl;
    cout<<"In ten years the ocean will rise "<<year10<<" millimeters."<<endl;
    
    //Exit Program
    return 0;
}