/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 10, 2015, 6:10 PM
 * Purpose: Gaddis_7th_ED_Chap_3_Prob_13
 *          Taxes and assessment value
 * 
 */
// System Libraries
#include <iostream>
#include <iomanip>  
using namespace std;

//Global Constants
const char CONPERC= 100;                  //Constant to convert percent to decimal


int main()
{
    //Initialize variables
    float propTax= 60;                    //Property tax in percent
    float assesTax=.64;                   //Property tax for assessment value per 100 dollars
    float price;                          //Input price of the property
    float assesVal;                       //assessment value
    float tax;                            //Amount of tax on assessment property
    
    //Prompt the user for the price of the property
    cout<<"What is the actual price of the property?"<<endl;
    cin>>price;
    
    //Calculate the assessment value
    assesVal=(propTax/CONPERC)*price;
    
    //Calculate the assesment tax
    tax=assesVal*(assesTax/CONPERC);
    
    //Output assessment value and property tax
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Assessment value of the property is $"<<assesVal<<endl;
    cout<<"The taxes of the assesment value is $"<<tax;
    
    //Exit program
    return 0;
}

