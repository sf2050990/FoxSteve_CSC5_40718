/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 2:45 PM
 * Purpose:Gaddis_Tony_7th_Ed_Chapter_3_Question_21
 *         Stocks
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Variable
const char CONPERC=100;                //Global conversion of percents and decimals
int main()
{
    //Initialize variables
    unsigned int numStok=1000;          //Number of Stocks
    float cost=32.87;                   //Cost per stock
    float sell=33.92;                   //Selling price of stock
    float rate= 2;                      //Brokers commission rate
    float paid;                         //Amount originally paid for stock
    float broker1;                      //First set of broker fees
    float broker2;                      //Second set of borker fees
    float sold;                         //Amount stocks were sold for
    float profit;                       //Total profit
    
    //Calculates Amount paid for stock
    paid=cost*numStok;
    
    //Calculates the amount paid to broker after purchase
    broker1=paid*(rate/CONPERC);
    
    //Calculates how much the stock was sold for
    sold=numStok*sell;
    
    //Calculates the second amount paid to broker
    broker2=sold*(rate/CONPERC);
    
    //Calculates the amount of profit if any accumulated
    profit=(paid+broker1)-(sold+broker2);
    
    //Output of amount paid, first broker fee, amount sold, second broker fee, and profit
    cout<<setprecision(2)<<fixed;
    cout<<"Joe bought "<<numStok<<" stocks at "<<cost<<" dollars per stock which equals "<<paid<< " dollars."<<endl;
    cout<<"His Broker charges a 2% commission on this total which equates to "<<broker1<<" dollars profit."<<endl;
    cout<<"Joe sold his stock for $33.92 per share which equals "<< sold<< " dollars. He then had to pay his"<<endl;
    cout<<"broker 2% off this total which equals "<<broker2<<" dollars. All and all, Joe lost "<<profit<<endl;
    cout<<"dollars after sale and broker fees, Better Luck next time Joe!!";
    
    //Exit Program
    return 0;
}

