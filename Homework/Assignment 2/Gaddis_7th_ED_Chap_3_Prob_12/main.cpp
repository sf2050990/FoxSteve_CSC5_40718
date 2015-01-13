/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 10, 2015, 7:40 PM
 * Purpose: Gaddis_7th_ED_Chap_3_Prob_12
 * I am at github
 */
// System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const int CONPERC=100;

//Function Prototype

//Execution Begins Here!

int main() 
{
    
    float cntyTax;
    float cntyRat=2;
    float stateTax;
    float stateRat=4;
    float totTax;
    float totAmt;
    float totSale;
    string month;
    string year;
    float prdSale;
    float finlSal;
    
    cout<<"What month is it?";
    getline(cin,month);
    
    cout<<"What year is it?";
    getline(cin,year);
    
    cout<<"What is the amount collected at the cash register?";
    cin>>totAmt;
    
    cntyTax=totAmt*(cntyRat/CONPERC);
    
    stateTax=totAmt*(stateRat/CONPERC);
    
    totTax=stateTax+cntyTax;
    
    totSale=totAmt/1.06;
    
    cout<<"Month:  "<<month<<" "<<year<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Total Collected:"<<totAmt<<endl;
    cout<<"Sales:"<<totSale<<endl;
    cout<<"County Sales Tax:"<<cntyTax<<endl;
    cout<<"State Sales Tax:"<<stateTax<<endl;
    cout<<"Total Sales Tax:"<<totTax<<endl;
            
    
    
    
    
            

    
            
    
    

    return 0;
}