/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 25, 2015, 6:05 PM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_13
 *          Lottery with arrays
 */
// System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main(int argc, char** argv)
{
    unsigned short seed=time(0);                       //Initializes seed with time function
    unsigned short count=0;                            //Counter
    unsigned short num;                                //Holds the user number input
    srand(seed);                                       //Seed is randomozied
    unsigned short lotto[5]={rand()%9,rand()%9,rand()%9,rand()%9,rand()%9};    //Lottery arrays
    unsigned short user[5];                            //User arrays
    
    //Loops so user can input five numbers
    for(int count=0;count<5;count++)
    {
        //Prompts user for number between 1-9
        cout<<"Please select a number between 0-9. Five numbers shall be selected";
        cin>>num;
        //Input validation so numbers are between 0-9
        while(num<0||num>9)
        {cout<<"ERROR: number must be between 0-9"<<endl;
        cout<<"Please select a number between 0-9. Five numbers shall be selected";
        cin>>num;
        }
        //Inputs each numeric entry into user array subscripts
        user[count]=num;
       
     }
    //Loops to display contents of lottery array
    for(int count=0;count<5;count++)
    {
        cout<<lotto[count];
    }
     cout<<endl;
     //loops To display users array content
     for(int count=0;count<5;count++)
    {
        cout<<user[count];
    }
    cout<<endl;
         
         //Accumulates the number of matches between corresponding elements in both arrays
         int match=0;
         //These statements conditionally executes depending if corresponding elements match
         //in arrays and then output the number that match
         if(user[0]==lotto[0])
         { cout<<"You matched "<<user[0]<<endl;
         match++;}
         if(user[1]==lotto[1])
         {   cout<<"You matched "<<user[1]<<endl;
             match++;}
         if(user[2]==lotto[2])
         { cout<<"You matched "<<user[2]<<endl;
         match++;}
         if(user[3]==lotto[3])
         { cout<<"You matched "<<user[3]<<endl;
         match++;}
         if(user[4]==lotto[4])
         {cout<<"You matched "<<user[4]<<endl;
         match++;}
         //If all elements match then the user is congratulated
         if(match==5)
             cout<<"Congratulations you have one won the lottery"<<endl;
         //Outputs the number of elements that match
         cout<<"The numbers you have matched to the corresponding array's elements is "<<match;
    
    //Exit program
    return 0;
}