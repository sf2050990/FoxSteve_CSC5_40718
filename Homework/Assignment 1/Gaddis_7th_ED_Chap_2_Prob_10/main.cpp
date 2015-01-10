/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 10:21 AM
 * Purpose: Gaddis_7th_ED_Chap_2_Prob_10
 */
// System Libraries
#include <iostream>
using namespace std;



int main() 
{
    //Initialize Variables
    unsigned int gallons=12;                   //Number of gallons
    float miles=350;                           //Miles per tank
    float total;                               //Miles per gallon
    
    //Calculate miles per gallon
    total=miles/gallons;
    
    //Output miles per gallon
    cout<<"A car that gets "<<miles<<" miles of gas per "<<gallons<<" gallon tank"<<endl;
    cout<<"receives "<<total<<" miles per gallon.";

    //Exit Program
    return 0;
}
