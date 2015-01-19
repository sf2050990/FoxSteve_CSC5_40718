/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 16, 2015, 9:25 AM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_13
 * 
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype

//Execution Begins Here!

int main()
{

    int choice;                //Holds users choice of integers
    int minValue;              //Holds minimum value
    int maxValue;              //Holds maximum value
    
    //Prompt user to enter an integer
    cout<<"Please enter an integer. Use 99 to quit."<<endl;
    cin>>choice;
    //Stores first choice in minValue
    minValue=choice;
   
    //Loops while sentinel 99 is not selected
    while(choice!=99)
    {
    //Prompts user to enter another integer    
    cout<<"Please enter an integer. Use 99 to quit."<<endl;
    cin>>choice;
   
    //Conditionally stores integer in minimum value if choice is less than the original number
    if(choice<minValue)
        minValue=choice;
    //Conditionally stores integer in maximum value if choice is more than the original number
    if(choice>maxValue)
        maxValue=choice;
    }
    
    //Output minimum and maximum values
    cout<<"The minimum value is "<<minValue<<endl;
    cout<<"The maximum value is "<<maxValue<<endl;
    
    //Exit program
    return 0;
}