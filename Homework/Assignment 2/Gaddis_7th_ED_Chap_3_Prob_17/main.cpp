
/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 9, 2015, 9:35 AM
 * Purpose: Gaddis_7th_ED_Chap_3_Prob 17
 * 
 */
// System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


//Global Constants
const char ANNUAL=12;           //constant number of monthly payments in a year
const char CONPERC=100;         //Global conversion of percents and decimals

//Execution Begins Here!
int main()
{
    float numPay=0;                //Number of payments
    float loan=0;                  //Loan amount
    float monRate=0;               //Monthly interest rate
    float anlRate=0;               //Annual interest rate
    double monPay=0;               //Monthly payment
    float amtPay=0;                //Amount of interest paid
    float totPaid=0;               //Total amount paid
    
  
    //Prompts for loan amount, annual interest, and number of payments 
    cout<<"What is the loan amount?";
    cin>>loan;
     
    cout<<"What is the annual interest rate?";
    cin>>anlRate;
      
    cout<<"How many payments are designated in the loan?";
    cin>>numPay;
    
    //Calculate monthly interest rate
    monRate=(anlRate/CONPERC)/ANNUAL;

    
    //Calculate monthly payments
    monPay= (monRate*pow(1+monRate,numPay)/(pow(1+monRate,numPay)-1))*loan;
    
    //Calculate amount paid 
    totPaid=monPay*numPay;
    
    //Calculates the amount of interest paid 
    amtPay= totPaid-loan;
    
    //Output loan amount, monthly interest rate, number of payments, monthly payment
    //amount paid back, Interest paid
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Loan Amount:"<<setw(16)<<"$ "<<setw(9)<<loan<<endl;
    cout<<"Monthly Interest Rate:"<<setw(14)<<right<<monRate*CONPERC<<"%"<<endl;
    cout<<"Number of Payments:"<<setw(9)<<"$ "<<setw(9)<<numPay<<endl;
    cout<<"Monthly Payment:"<<setw(12)<<"$ "<<setw(9)<<monPay<<endl;
    cout<<"Amount Paid Back:"<<setw(11)<<"$ "<<setw(9)<<totPaid<<endl;
    cout<<"Interest Paid:"<<setw(14)<<"$ "<<setw(9)<<amtPay<<endl;
    
        
    
    //Exit Program
    return 0;
}