/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 16, 2015, 9:25 AM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_13
 *          min and max value
 */
// System Libraries
#include <iostream>
using namespace std;


//Execution Begins Here!

int main()
{

    int choice;               //Holds users choice of integers
    int minVal;              //Holds minimum value
    int maxVal;              //Holds maximum value
    
    //Prompt user to enter an integer
    cout<<"Please enter an integer. Use 99 to quit."<<endl;
    cin>>choice;
    //Stores first choice in minValue
    minVal=choice;
   
    //Loops while sentinel 99 is not selected
    while(choice!=99)
    {
    //Prompts user to enter another integer    
    cout<<"Please enter an integer. Use 99 to quit."<<endl;
    cin>>choice;
   
    //Conditionally stores integer in minimum value if choice is less than the original number
    if(choice<minVal&&choice!=99)
        minVal=choice;
    //Conditionally stores integer in maximum value if choice is more than the original number
    if(choice>maxVal&&choice!=99)
        maxVal=choice;
    }
    
    //Output minimum and maximum values
    cout<<"The minimum value is "<<minVal<<endl;
    cout<<"The maximum value is "<<maxVal<<endl;
    
    //Exit program
    return 0;
}