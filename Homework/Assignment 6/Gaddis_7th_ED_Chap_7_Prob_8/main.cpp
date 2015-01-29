/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 27, 2015, 11:30 AM
 * Purpose: Gaddis_7th_ED_Chap_7_Prob_8
 *          Payroll
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
float grosPay(int,double);                             //Function prototype for calculating gross wages
//Execution Begins Here!

int main()
{
    //Declare variables
    //Array that holds employee id numbers
    int empId[7]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[7];                                     //Array that holds number of hours worked
    double payRate[7];                                //Array that holds pay rate
    double wages[7];                                  //Array that holds wages
    
    //Loops through the number of employees
    for(int count=0;count<7;count++)
    {
        //Prompts user for hours worked and pay rate
        cout<<"For employee ID "<<empId[count]<<" How many hours were worked?"<<endl;
        cin>>hours[count];
        //Input validation so hours can only be positive
        while(hours[count]<0)
        {
            cout<<"ERROR: The number of hours cannot be negative"<<endl;
            cout<<"For employee ID "<<empId[count]<<" How many hours were worked?"<<endl;
            cin>>hours[count];
        }
        
        cout<<"What is the pay rate?"<<endl;
        cin>>payRate[count];
        //Input validation so pay rate cannot be less than 6
        while(payRate[count]<6)
        {
            cout<< "ERROR: Pay rate cannot be less than 6"<<endl;
            cout<<"What is the pay rate?"<<endl;
            cin>>payRate[count];
        
        }
   
    }
    //Function call that send hours[] and pay rate[] values to grosPay function to calculate gross pay
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Employee #"<<empId[0]<< " gross wages are "<<grosPay(hours[0],payRate[0])<<endl;
    cout<<"Employee #"<<empId[1]<< " gross wages are "<<grosPay(hours[1],payRate[1])<<endl;
    cout<<"Employee #"<<empId[2]<< " gross wages are "<<grosPay(hours[2],payRate[2])<<endl;
    cout<<"Employee #"<<empId[3]<< " gross wages are "<<grosPay(hours[3],payRate[3])<<endl;
    cout<<"Employee #"<<empId[4]<< " gross wages are "<<grosPay(hours[4],payRate[4])<<endl;
    cout<<"Employee #"<<empId[5]<< " gross wages are "<<grosPay(hours[5],payRate[5])<<endl;
    cout<<"Employee #"<<empId[6]<< " gross wages are "<<grosPay(hours[6],payRate[6])<<endl;
    return 0;
}
//Function grosPay
float grosPay(int hour, double rate)
{
    //returns hours multiplied by rate
    return hour*rate;
}