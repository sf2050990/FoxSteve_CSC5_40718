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

int main() 
{
    //Initialize Variables
    unsigned int acre= 43560;                //Square feet
    float total= 389767;                     //Square feet
    float numAcre;
    
    //Calculate the total number of acres
    numAcre= total/acre;
    
    //Output the total number of acres
    cout<<"An acre is "<<acre<<" square feet. There is a total of "<<total<<endl;
    cout<<"square feet  which means there is "<<numAcre<<" acres all together.";
    
    //Exit Program
    return 0;
}