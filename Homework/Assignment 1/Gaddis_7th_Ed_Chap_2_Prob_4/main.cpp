/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 12:24 AM
 * Purpose:Gaddis_7th_ED_Chap_2_Prob_4
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const char CONPERC=100;                //Constant to convert percent into decimal

//Execution Begins Here!

int main()
{
    //Initialization of variables
    float meal=44.50;                  //Price of meal
    float tipRate=15;                  //Expected tip in percent
     float taxRate=6.75;               //Tax rate
    float tax;                         //Total Tax
    float tip;                         //Total Tip
    float total;                       //Total bill
    
    //Calculate the amount of tax, tip, and the grand total of the bill
    tax=meal*(taxRate/CONPERC);
    tip=(meal+tax)*(tipRate/CONPERC);
    total=meal+tax+tip;
    
    //Output the amount of original price, tax,tip, and the grand total of the bill
    cout<<setprecision(2)<<fixed<<"The initial price of the meal is "<<meal<<" dollars. The amount"<<endl;
    cout<<"of tax on this price is "<<tax<<" dollars. The expected tip to the"<<endl;
    cout<<"server is "<<tip<<" dollars. The grand total of the bill is "<<total<<" dollars."<<endl;
    
    //Exit Program
    return 0;
}
