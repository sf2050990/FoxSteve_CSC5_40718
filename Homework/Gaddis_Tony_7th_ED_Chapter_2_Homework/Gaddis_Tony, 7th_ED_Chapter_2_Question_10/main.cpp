/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 10:21 AM
 * Purpose: Gaddis_Tony_7th_ED_Chapter_2_Question_10
 */
// System Libraries
#include <iostream>
using namespace std;



int main() 
{
    //Initialize Variables
    unsigned int gallons=12;
    float miles=350;
    float total;
    
    //Calculate miles per gallon
    total=miles/gallons;
    
    //Output miles per gallon
    cout<<"A car that gets "<<miles<<" miles of gas per "<<gallons<<" gallon tank"<<endl;
    cout<<"receives "<<total<<" miles per gallon.";

    //Exit Program
    return 0;
}
