/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 6, 2015, 6:05 PM
 * Purpose: Gaddis, 7th ED, Chap 3, Prob 16
 *          Savings account
 */
// System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const char CONPERC=100;                     //Percent Conversion
//Function Prototype

//Execution Begins Here!

int main()
{
    //Initialization of variables
    float accSave;                      //Amount in savings account
    float rate;                         //Interest charged on account
    unsigned short cmpound;                      //Times compounded in a given year
    float intCash;                      //Total Balance in savings account
    float intRate;                      //Total interest accrued
    
    //prompt user for account balance, interest rate, and times compounded
    cout<<"What is the principle of the savings account? "<<endl;
    cin>>accSave;
    
    
    cout<<" What is the interest rate of this account?"<<endl;
    cin>>rate;
    
   
    cout<<"How many times is the interest compounded in a given year?"<<endl;
    cin>>cmpound;
    //Convert interest percent rate into decimal 
    rate=rate/CONPERC;
    
    //Total amount in savings
    intCash=accSave*pow(1+(rate/cmpound),cmpound);
   //Calculate the amount of interest generated on the account
    intRate=intCash-accSave;
    //Output interest rate, times compunded, principle, interest, and total balance
    cout<<setprecision(2)<<fixed<<"Interest Rate:"<<setw(15)<<rate*CONPERC<<"%"<<endl;
    cout<<"Times Compounded:"<<setw(13)<<cmpound<<endl;
    cout<<"Principle:"<<setw(13)<<"$"<<setw(7)<<accSave<<endl;
    cout<<"Interest:"<<setw(14)<<"$"<<setw(7)<<intRate<<endl;
    cout<<"Amount in Savings;"<<setw(5)<<"$"<<setw(7)<<intCash;
    
    //Exit program
    return 0;
}