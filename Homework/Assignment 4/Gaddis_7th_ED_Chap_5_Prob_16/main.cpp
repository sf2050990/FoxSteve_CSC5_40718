/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 14, 2015, 4:38 PM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_16
 *          Calculate total savings account balance
 *
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global constant
const short CONPERC=100;                 //Convert percent into decimal

int main()  
{
    float accRate;                       //Annual interest rate
    float intBal;                        //Initial balance at start of savings account
    float deposit;                       //Monthly deposits
    short numMon;                        //Number of months the account has been active
    float monInt;                        //Monthly interest rate
    float withdraw;                      //Monthly withdraws
    float numDep;                        //Total amount of deposits
    float numWith;                       //Total amount of withdraws
    float totBal;                        //Totsl account balance
    
    //Prompts user for the annual interest rate, beginning balance, and the number of months
    //The account has been establishes
    cout<<"What is the annual interest rate on the bank account?"<<endl;
    cin>>accRate;
    
    cout<<"What is the starting balance of the savings account?"<<endl;
    cin>>intBal;
    
    cout<<"How many months has it been since the account was first established?"<<endl;
    cin>>numMon;
    
    //Assigns the beginning balance as the starting point to calculate total balance.
    totBal=intBal;
    
    //Calculates monthly interest
    monInt=(accRate/CONPERC)/12;
    
    //Loops for how many months is inputed or until a negative balance occurs
    for (int count=1;count<=numMon;count++)
    {
       //Conditionally executes if the balance ever becomes negative and notifies the
       //The user that the account has been closed 
       if(totBal<0)    
        { 
           cout<<"You have a negative balance. Your account has been closed"<<endl;
           break;
        }
       //Executes as long as the account is positive
       else
       {     
           //Prompts user for the amount deposited in a given month     
           cout<<"How much was deposited into the account in month #"<<count<<endl;
           cin>>deposit;
        
           //Prompts user for the amount withdrawn in a given month
           cout<<"How much money was withdrawn from the account in month #"<<count<<endl;
           cin>>withdraw;
        
           //Accumulates the total amount deposited
           numDep+=deposit;
           //Accumulates the total amount withdrawn
           numWith+=withdraw;
           //Balance accumulates the amount of deposits in a given month
           totBal+=deposit;
           //Balance subtracts the amount of withdraws in a given month
           totBal-=withdraw;
           //Balance accumulates the amount of interest on the account in a given month
           totBal+=(totBal*monInt);
       }
      
    }
    
    //Outputs total deposits, withdraws, and the ending balance
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Total Deposits:   $"<<numDep<<endl;
    cout<<"Total Withdraws:  $"<<numWith<<endl;
    cout<<"Total Balance:    $"<<totBal<<endl;
    
    //Exit program
    return 0;
}
