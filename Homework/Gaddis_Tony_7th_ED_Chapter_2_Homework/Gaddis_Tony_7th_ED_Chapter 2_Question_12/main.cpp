/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 10:10 AM
 * Purpose: Gaddis_Tony_7th_ED_Chapter_2_Question_12
 */
// System Libraries
#include <iostream>
using namespace std;

//Global Variable
const unsigned int ACRE=43560;         //square feet
int main() 
{
    //Initialize Variables
   
    float total= 389767;                     //Square feet
    float numAcre;
    
    //Calculate the total number of acres
    numAcre= total/ACRE;
    
    //Output the total number of acres
    cout<<"An acre is "<<ACRE<<" square feet. There is a total of "<<total<<endl;
    cout<<"square feet  which means there is "<<numAcre<<" acres all together.";
    
    //Exit Program
    return 0;
}