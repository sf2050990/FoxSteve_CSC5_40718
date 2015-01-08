/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 12:24 AM
 * Purpose:Gaddis_Tony_7th_ED_Chapter_2_Question_4
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float taxRate=.0675;

//Execution Begins Here!

int main()
{
    //Initialization of variables
    float meal=44.50;
    float tipRate=.15;
    float tax;
    float tip;
    float total;
    
    //Calculate the amount of tax, tip, and the grand total of the bill
    tax=meal*taxRate;
    tip=(meal+tax)*tipRate;
    total=meal+tax+tip;
    
    //Output the amount of original price, tax,tip, and the grand total of the bill
    
    cout<<setprecision(2)<<fixed<<"The initial price of the meal is "<<meal<<" dollars. The amount"<<endl;
    cout<<"of tax on this price is "<<tax<<" dollars. The expected tip to the"<<endl;
    cout<<"server is "<<tip<<" dollars. The grand total of the bill is "<<total<<" dollars."<<endl;
    
    //Exit Program
    return 0;
}
