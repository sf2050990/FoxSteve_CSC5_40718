/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 2:45 PM
 * Purpose:Gaddis_Tony_7th_Ed_Chapter_3_Question_21
 * 
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Initialize variables
    unsigned int numStok=1000;
    float cost=32.87;
    float sell=33.92;
    float rate= .02;
    float paid;
    float broker1;
    float broker2;
    float sold;
    float profit;
    
    //Calculates Amount paid for stock
    paid=cost*numStok;
    
    //Calculates the amount paid to broker after purchase
    broker1=paid*rate;
    
    //Calculates how much the stock was sold for
    sold=numStok*sell;
    
    //Calculates the second amount paid to broker
    broker2=sold*rate;
    
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

