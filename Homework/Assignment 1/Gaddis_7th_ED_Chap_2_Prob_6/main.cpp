/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 8:47 AM
 * Purpose: Gaddis_7th_ED_Chap_2_Prob_6
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const char payPeriods=26;    //Biweekly Payments in a year

int main() 
{
    
    float payAmount=1700.00;         //Amount paid biweekly
    float annualPay;                 //Amount paid in a year 
    
    //Calculate amount paid in a year
    annualPay=payAmount*payPeriods;
    
    //Output total amount generated in a given year
    cout<<setprecision(2)<<fixed<<"An individual who in a two week period grosses "<<payAmount<< " dollars"<<endl;
    cout<<"will make a total of "<<annualPay<<" dollars in a given year.";
    
    return 0;
    
}
     
