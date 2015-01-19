/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 15, 2015, 10:05 AM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_15
 *          Display payroll report
 */
// System Libraries
#include <iostream>
using namespace std;


int main()
{
   //Initialize variables
   unsigned int empID;                //Employee identification number
   float grsPay;                      //Gross pay
   float staTax;                      //Total state tax withheld
   float fedTax;                      //Total federal tax withheld
   float fica;                        //Total FICA Withheld
   float total;                       //Net pay
   
    //Loops while employee ID number is not 0.
    while(empID!=0)
   {//Prompts for employee ID number
    cout<<"What is the employees ID number?"<<endl;
    cin>>empID;
    //Conditionally ends program when 0 is entered in employee ID number
    if(empID==0)
    {
        cout<<"End of Program";
        break;
    }
    //Prompts user for gross pay of employee    
    cout<<"What is the employees gross pay?"<<endl;
    cin>>grsPay;
    //Conditionally loops an error message if gross pay is negative
    while(grsPay<0)
    {   cout<<"ERROR: Gross Pay Cannot Be negative.";
        cout<<"What is the employees gross pay?"<<endl;
        cin>>grsPay;
    }
    
    cout<<"What is the state tax withholding?"<<endl;
    cin>>staTax;
    //Conditionally loops an error message if state tax withheld is negative
    while(staTax<0)
    {    cout<<"ERROR: state tax Cannot Be negative.";
         cout<<"What is the state tax withholding?"<<endl;
         cin>>staTax;
    }
    //Conditionally loops an error message if state tax is greater than gross pay;
    while(staTax>grsPay)
    {
        cout<<"ERROR: State Tax cannot be greater than gross pay.";
        cout<<"What is the state tax withholding?"<<endl;
        cin>>staTax;
    }
    cout<<"What is the federal tax withholding?"<<endl;
    cin>>fedTax;
    //Conditionally loops an error message if Federal tax withheld is negative
    while(fedTax<0)
    {   cout<<"ERROR: Federal Tax Cannot Be negative.";
        cout<<"What is the federal tax withholding?"<<endl;
        cin>>fedTax;
    }
     //Conditionally loops an error message if federal tax is greater than gross pay;
    while(fedTax>grsPay)
     {
        cout<<"ERROR: Federal Tax cannot be greater than gross pay.";
        cout<<"What is the federal tax withholding?"<<endl;
        cin>>fedTax;
     }

    cout<<"What is the FICA withholding?"<<endl;
    cin>>fica;
    //Conditionally loops an error message if FICA withheld is negative
   while(fica<0)
    {   cout<<"ERROR: FICA Withholding Cannot Be negative.";
        cout<<"What is the FICA withholding?"<<endl;
        cin>>fica;
    }
     //Conditionally loops an error message if FICA withholding is greater than gross pay;
    while(fica>grsPay)
    {
         cout<<"ERROR: Federal Tax cannot be greater than gross pay.";
         cout<<"What is the FICA withholding?"<<endl;
         cin>>fica;   
    }
   
    //Calculates total net pay
    total=grsPay-staTax-fedTax-fica;
     //Conditionally ends program if the sum of withholdings is greater than gross pay;
    if(staTax+fedTax+fica>grsPay)
    {  cout<<"ERROR: Total withholdings cannot be greater than gross pay. Run program again";
     break;
    }
    //Output gross pay, state tax, federal tax, FICA withholdings, and net pay
    cout<<"Total Gross Pay:         $"<<grsPay<<endl;
    cout<<"Total State Tax:         $"<<staTax<<endl;
    cout<<"Total Federal Tax:       $"<<fedTax<<endl;
    cout<<"Total FICA Withholding:  $"<<fica<<endl;
    cout<<"Total Net Pay:           $"<<total<<endl;
   }
   //Exit program
    return 0;
}