/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 12, 2015, 12:35 PM
 * Purpose: Gaddis_7th_ED_Chap_4_Prob_20
 *          Boiling and Freezing points
 */
// System Libraries
#include <iostream>
using namespace std;



//Global Constants
   const short BOILALC=172;       //Global constant of boiling temperature of Ethyl Alcohol
   const short BOILMER=676;       //Global constant of boiling temperature of mercury
   const short BOILOXY=-306;      //Global constant of boiling temperature of oxygen
   const short BOILWAT=212;       //Global constant of boiling temperature of water
   const short FRZALC=-173;       //Global constant of freezing temperature of alcohol
   const short FRZMER=-38;        //Global constant of freezing temperature of mercury
   const short FRZOXY=-362;       //Global constant of freezing temperature of oxygen
   const short FRZWAT=32;         //Global constant of freezing temperature of water

//Execution Begins Here!

int main() 
{  
    //Declare variables
    short temp;                       //Holds users temperature

    //Prompt user for a temperature
    cout<<"Please enter a temperature"<<endl;
    cin>>temp;
     
     //Conditionally executes if temperature is less than freezing point of oxygen
     if(temp<=FRZOXY)
        cout<<"Oxygen will freeze at this temperature"<<endl;
    //Conditionally executes if temperature is more than boiling point of oxygen 
     if (temp>=BOILOXY)
        cout<<"Oxygen will boil at this temperature"<<endl;
    //Conditionally executes if temperature is less than freezing point of Ethyl Alcohol 
     if (temp<=FRZALC)
        cout<<"Ethyl Alcohol will freeze at this temperature"<<endl;
    //Conditionally executes if temperature is less than freezing point of mercury 
     if (temp<=FRZMER)
         cout<<"Mercury will freeze at this temperature"<<endl;
    //Conditionally executes if temperature is less than freezing point of water
     if (temp<=FRZWAT)
        cout<<"Water will freeze at this temperature"<<endl;
      //Conditionally executes if temperature is more than boiling point of Ethyl Alcohol
     if (temp>=BOILALC)
        cout<<"Ethyl Alcohol will boil at this temperature"<<endl;
      //Conditionally executes if temperature is more than boiling point of water
     if (temp>=BOILWAT)
         cout<<"Water will boil at this temperature"<<endl;
      //Conditionally executes if temperature is more than boiling point of mercury 
     if (temp>=BOILMER)
         cout<<"Mercury will boil at this temperature"<<endl;
        

   //Exit prrogram
    return 0;
}

