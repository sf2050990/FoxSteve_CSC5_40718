/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 7, 2015, 6:05 PM
 * Purpose: Gaddis_Tony_7th_ED_Chapter_two_Question_18
 */
// System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here!

int main()
{ 
    //Initialize Variables
    int survey= 12467;
    float drinks=.14;
    float citrus=.64;
    float ToDrink;
    float ToCitrus;
    
    //Calculation of Total Energy Drinkers in survey
    ToDrink=survey*drinks;
    
    //Output For Total Energy Drinkers
    cout<< "The number of people who drink energy drinks"<<endl;
    cout<<"at least once a week is "<<ToDrink<<" people out of 12467 people "<<endl;
    cout<<"that were surveyed."<<endl<<endl;
    
    //Calculation of the number of energy drinkers that prefer citrus flavor
    ToCitrus=(survey*drinks)*citrus;
    
    //Output for the number of individuals that prefer citrus flavor energy drinks
    cout<<"The number of energy drink consumers who preferred citrus is "<<endl;
    cout<<ToCitrus<<" people.";
    

return 0;
}