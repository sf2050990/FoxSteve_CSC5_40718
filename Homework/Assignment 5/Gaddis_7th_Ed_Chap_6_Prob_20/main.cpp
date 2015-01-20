/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 20, 2015, 10:05 AM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_20
 *          Stock Program
 */
// System Libraries
#include <iostream>
using namespace std;


//Function Prototype
float stokCalc(int,float,float,float, float);     //Function prototype for stock profit calculator

//Execution Begins Here!
int main()
{
    int numShare;                       //Number of shares purchased
    float salPric;                      //Sales price per share
    float comPaid;                      //Commission paid on sale price
    float purShar;                      //Purchase price per share
    float purCom;                       //Purchased commission paid
    float profit;                       //Holds profit for given loop iteration
    float totProf=0;                    //Accumulates total profit
    char choice;                        //holds users choice to continue program
    
    //Posttest loop the continues as long as the user enters y of Y
   do
    {
    //Sets profit to zero every loop iteration   
    profit=0;
    
    //Prompt user for number of shares, shares sales price, sales commission paid,
    //purchase price per share, and purchase commission paid
    cout<<"How many shares were purchased?(Input Integer Format)"<<endl;
    cin>>numShare;
    
    cout<<"What is the sale price per share?(Input Decimal Format)"<<endl;
    cin>>salPric;
    
    cout<<"How much sale commission was paid?(Input Decimal Format)"<<endl;
    cin>>comPaid;
    
    cout<<"What is the purchase price per share?(Input Decimal Format)"<<endl;
    cin>>purShar;
    
    cout<<"What is the purchase commission paid?(Input Decimal Format)"<<endl;
    cin>>purCom;
    
    //Inputs are sent to stokCalc function and the return value is stored in variable profit
    profit=stokCalc(numShare, salPric, comPaid, purShar, purCom);
    
    //Accumulates total profit for how ever many loop iterations
    totProf+=profit;
    
    //Conditionally executes if there was a negative gain
    if(profit<0)
        cout<<"There was no profit. You lost $"<<profit<<endl;
    //Conditionally executes if there was a positive profit
    else
        cout<<"Your profit is $"<<profit<<endl;
    //Output current total profit
    cout<<"Your current balance is $"<<totProf<<endl;
    //Prompts user if they wish to continue another loop iteration
    cout<<"Do you wish to continue? Enter Y or N";
    cin>>choice;
    //Conditionally reiterates loop if the user chooses Y or y
    }while(choice=='Y'||choice=='y');
    //Exit program
    return 0;
}
//stokCalc function that calculates profit
float stokCalc(int num1,float num2,float num3, float num4, float num5)
{
    //Declare profit variable
    float profit;
    //Calculate total profit
    profit=((num1*num2)-num3)-((num1*num4)+num5);
    //Returns variable to be stored in variable profit in main
    return profit;
    
}