/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 7, 2015, 6:05 PM
 * Purpose: Gaddis_7th_ED_Chap_two_Prob_18
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
 //Global Constants
const int CONPERC=100;                   //Constant to convert percent into decimal
//Execution Begins Here!

int main()
{ 
    //Initialize Variables
    int survey= 12467;                   //Number of people surveyed
    float drinks=14;                     //Percent of energy drinkers
    float citrus=64;                     //Percent of energy drink drinkers who prefer citrus
    float ToDrink;                       //Total energy drink drinkers
    float ToCitrus;                      //Total energy drink drinkers who prefer citrus 
    
    //Calculation of Total Energy Drinkers in survey
    ToDrink=survey*(drinks/CONPERC);
    
    //Output For Total Energy Drinkers
    cout<<setprecision(0)<<fixed;
    cout<< "The number of people who drink energy drinks"<<endl;
    cout<<"at least once a week is "<<ToDrink<<" people out of 12467 people "<<endl;
    cout<<"that were surveyed."<<endl<<endl;
    
    //Calculation of the number of energy drinkers that prefer citrus flavor
    ToCitrus=(survey*(drinks/CONPERC))*(citrus/CONPERC);
    
    //Output for the number of individuals that prefer citrus flavor energy drinks
    cout<<"The number of energy drink consumers who preferred citrus is "<<endl;
    cout<<ToCitrus<<" people.";
    

return 0;
}