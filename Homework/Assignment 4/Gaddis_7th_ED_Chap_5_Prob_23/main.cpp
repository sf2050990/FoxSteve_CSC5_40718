/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 16, 2015, 10:25 AM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_23
 *          pattern display
 */
// System Libraries
#include <iostream>

using namespace std;

int main()
{
    char symbol='+';                        //Symbol that is displayed
   
    //Loops ten iterations which marks the end of a line and accumulation of character
    for(int count=1;count<=10;count++) 
    {
        //Loops to display the number of characters in each line
        for( int row=0;row<count;row++)
        {
            //Outputs number of symbols per row
            cout<<symbol;
        }
        cout<<endl;
    }
    //Loops to signal the end of line and decrements the number of characters
    for(int count=10;count>0;count--)
    {
        //Loops display the number of characters per line
        for( int row=0;row<count;row++)
        {
            cout<<symbol;
        }
        cout<<endl;
    }
    //Exit Program
   return 0;
}