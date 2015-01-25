/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 19, 2015, 2:59 PM
 * Purpose: Gaddis_7th_ED_Chap_3_Prob_17
 *          Display sales figures
 */
// System Libraries
#include <iostream>
using namespace std;


int main() 
{
    //Initialize variables
    char bar='*';                        //Character output per 100$ increment
    float store1;                        //Total for store number 1
    float store2;                        //Total for store number 2
    float store3;                        //Total for store number 3
    float store4;                        //Total for store number 4
    float store5;                        //Total for store number 5
    
    //Prompt for total amounts of store 1, store 2,store 3, store 4,
    cout<<"Please enter the total sales for store #1 ";
    cin>>store1;
    cout<<"Please enter the total sales for store #2 ";
    cin>>store2;
    cout<<"Please enter the total sales for store #3 ";
    cin>>store3;
    cout<<"Please enter the total sales for store #4 ";
    cin>>store4;
    cout<<"Please enter the total sales for store #5 ";
    cin>>store5;

    //Output title of the bar chart
    cout<<"SALES BAR CHART"<<endl;
    
        //Label for store 1 
       cout<<"Store #1 ";
        //loops until the total of store ones amount is less than 99$
        while(99<store1)
        {
            //Decrements store 1 total by 100$
            store1-=100;
            //Ouputs '*' per 100$
            cout<<bar;
        }
     //Label for store 2 
     cout<<endl<<"Store #2 ";
        //loops until the total of store twos amount is less than 99$
        while(99<store2)
        {
            //Decrements store 2 total by 100$
            store2-=100;
            //Ouputs '*' per 100$
            cout<<bar;
        }
     //Label for store 3
     cout<<endl<<"Store #3 ";
       //loops until the total of store threes amount is less than 99$
        while(99<store3)
        {
            //Decrements store 3 total by 100$
            store3-=100;
            //Ouputs '*' per 100$
            cout<<bar;
        }
    //Label for store 4
    cout<<endl<<"Store #4 ";     
        //loops until the total of store fours amount is less than 99$
        while(99<store4)
        {
             //Decrements store 4 total by 100$
            store4-=100;
            //Ouputs '*' per 100$
            cout<<bar;
        }
     //Label for store 5
     cout<<endl<<"Store #5 ";
        while(99<store5)
        {     
            //Decrements store 1 total by 100$
            store5-=100;
            //Ouputs '*' per 100$
            cout<<bar;
            //Conditionally ends program is store 5s total is less than 99$
            if(99>store5)
                break;
        }
    //Exit Program   
    return 0;
}


