/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 20, 2015, 1:35 PM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_15
 *          Population Rate
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float CONPERC=100.0;             //Global Constant for converting percents and decimals

//Function Prototype
int popSize(int,int,int);              //Population to discover population rates

//Execution Begins Here!
int main()
{
    unsigned int pop;                  //Initial population
    unsigned short birth;              //Birth Rate
    unsigned short death;              //Death rate
    int years;                         //Number of years
    int newPop=0;                      //Hold population after birth and death rates are applied
    int totPop;                        //Accumulates increase in population
    
    //Prompt for beginning population, birth rate, death rate, and number of years
    cout<<"What is the starting size of the population?"<<endl;
    cin>>pop;
    
    cout<<"What is the annual birth Rate?"<<endl;
    cin>>birth;
    
    cout<<"What is the annual death rate?"<<endl;
    cin>>death;
    
    cout<<"How many years would you like to display"<<endl;
    cin>>years;
    
    //function call to find first year of increase or decrease of populations
    newPop+=popSize(pop,birth,death);
    //Stores first year value to initialize total population variable
    totPop+=newPop;
    
    //loops for number the number of years
    for(int count=1;count<=years;count++)
    {
     //Output given year and population size
     cout<<"Year#"<<count<<" Population="<<totPop<<endl;
     //accumulates the rate of increase or decrease and stores it for next loop iteration
     totPop+=(popSize(totPop,birth,death)-totPop);
    }
    //Exit program
    return 0;
}
//Function popSize
int popSize(int pop,int birth,int death)
{ 
    //Declare variables
    int newPop;                //holds population
    //Calculates new population size
    newPop=pop+(pop*(birth/CONPERC))-(pop*(death/CONPERC));
    //Return int value to main
    return newPop;
}
