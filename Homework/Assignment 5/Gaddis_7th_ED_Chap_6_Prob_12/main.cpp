/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 21, 2015, 11:05 AM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_12
 *          Calculate employees days off
 */
// System Libraries
#include <iostream>
using namespace std;


//Function Prototype
int numEmp();                    //Function prototype for number of employees
int dayMiss(int);                //Function prototype for number of days missed
double avDayMs(int,int);         //Function prototype for calculating average amount of days missed

//Execution Begins Here!
int main() 
{
    //Declare variables
    int numEmpl;                 //Holds number of employees 
    int totDays;                 //Holds total amount of days missed
   
   //Calls numEmp function and stores result in numEmpl variable 
   numEmpl=numEmp();
   //Calls dayMiss function and stores result in totDays variable
   totDays=dayMiss(numEmpl);
   
   //Outputs average days with a call to avDaysMs function
   cout<<"The average days missed is "<< avDayMs(numEmpl,totDays)<<" days";
   
    //Exit program
    return 0;
}
//numEmp function
int numEmp()
{
    //Declare variables
    int numEmp;
    //Prompt user for the number of employees 
    cout<<"What is the number of employees at the company?"<<endl;
    cin>>numEmp;
    //Returns the number of employees as an integer
    return numEmp;
}
//dayMiss Function
int dayMiss(int num1)
{       //Declare variables
        int days;                     //holds day missed by one employee
        int totDays=0;                //Accumulates total days missed
        
    //Conditionally executes as long as counter is less then or equal to the number of employees    
    for(int count=1;count<=num1;count++)
    {
        //Prompts user for days missed per employee
        cout<<"How many days did employee#"<<count<<" miss in a year"<<endl;
        cin>>days;
        totDays+=days;
    }    
        //Returns the total number of days missed as integer
        return totDays;
}
//avDayMs function
double avDayMs(int num1,int num2)
{
    //Calculates average number of days missed by employees
    double average=num2/static_cast<double>(num1);
    
    //Returns average number of days missed as a double
    return average;
}