/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 10, 2015, 7:40 PM
 * Purpose: Gaddis_7th_ED_Chap_3_Prob_12
 *          Sales Report
 */
// System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const int CONPERC=100;                  //global constant for converting percent

//Function Prototype

//Execution Begins Here!

int main() 
{
    
    float cntyTax;                       //County tax
    float cntyRat=2;                     //County Rate
    float stateTax;                      //State tax 
    float stateRat=4;                    //State tax rate
    float totTax;                        //Total tax
    float totAmt;                        //Total amount recieved at cash register
    float totSale;                       //Total sales
    string month;                        //Month
    string year;                         //Year
    
    //Prompts user for the month, year, and total cash recieved at register
    cout<<"What month is it?";
    getline(cin,month);
    
    cout<<"What year is it?";
    getline(cin,year);
    
    cout<<"What is the amount collected at the cash register?";
    cin>>totAmt;
    //Calculates total sale
    totSale=totAmt/1.06;
    //Calculates county tax
    cntyTax=totSale*(cntyRat/CONPERC);
    //Calculate state tax
    stateTax=totSale*(stateRat/CONPERC);
    //Calculate total tax
    totTax=stateTax+cntyTax;
    
    
    //Output month, year, total collected from register, total sales, county tax, state tax, and total tax
    cout<<"Month:  "<<month<<" "<<year<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Total Collected:      $"<<setw(9)<<totAmt<<endl;
    cout<<"Sales:                $"<<setw(9)<<totSale<<endl;
    cout<<"County Sales Tax:     $"<<setw(9)<<cntyTax<<endl;
    cout<<"State Sales Tax:      $"<<setw(9)<<stateTax<<endl;
    cout<<"Total Sales Tax:      $"<<setw(9)<<totTax<<endl;
            
//End Program
    return 0;
}