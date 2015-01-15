/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 14, 2015, 1:05 PM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_22
 * 
 */
// System Libraries
#include <iostream>
using namespace std;

//Program executes
int main()
{
    //initialize variables
    unsigned short num;                  //Holds users input for a number between 1-15
    unsigned short count;                //Counter that increments outer for loop
    unsigned short time;                 //Counter that increments inner loop
   
    
    //Prompts user to enter a number between 1-15
    cout<<"Please enter an integer that is no greater then 15";
    cin>>num;
    
   //Repeats for every full rotation of the program equal to the users input 
   for(time=0;time<num;time++)
   {
    //repeatedly outputs X on one line depending on users input   
    for(count=0;count<num;count++)
    {  
       cout<<'X';
       //if counter count equals the users input the program breaks to the next line
       if(count==num)
           break;
    }
    //Ends line and ends one repetition of outer for loop
    cout<<endl;
   }
    //Exit Program
    return 0;
}

