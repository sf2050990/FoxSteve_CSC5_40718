/* 
 * File:   main.cpp
 * Author: Steve Fox
 * Created on January 10, 2015, 11:25 AM
 * Purpose: Gaddis_7th_Ed_Chap_3_Prob_14
 *          property tax
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//Execulion Begins here
int main()
{
    //Initialize variables
    float prop;                       //Assessed Property Value 
    float tax;                        //Tax in dollars per 100
    float annTax;                     //Annual tax bill
    float qrtBill;                    //Quarterly bill statement
    
    
    //Prompt user for the assessed property value
    cout<<"Please enter the assessed value of the piece of property.";
    cin>>prop;
    
    
    //Prompt user for tax in dollars per hundred
    cout<<"Please enter the amount of tax in dollars on this property";
    cin>>tax;
    
    //Calculate the amount of annual taxes on assessed property
    annTax=(prop-5000)/100*tax;
    
    //Calculate the quarterly bill for an assessed property
    qrtBill=annTax/4;
    
    //Output annual tax bill and quarterly taxes
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"The amount of annual tax on this piece is $"<<annTax<<endl;
    cout<<"The quarterly bill for this property is $"<<qrtBill;
 
    //Exit Program
    return 0;   
}
