/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 21, 2015, 8:45 AM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_15
 *          Doctor Bill using overloaded functions
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototype
float patient(int,float,float,float);          //Overloaded function prototype for patient bill 
float patient(float,float);                    //Overloaded function prototype for patient bill


//Execution Begins Here!

int main()
{
    //Declare variables
    char choice;                             //Holds the users choice
    unsigned short days;                     //Holds number of days patient stayed in hospital
    float rate;                              //Holds hospital's daily rate charge
    float medChar;                           //Holds medication cost
    float hospSer;                           //Holds hospital service charge
    
    //Prompt user to declare whether they were and in-patient or out-patient
    cout<<"Were you admitted to the hospital as an in-patient or an out-patient?"<<endl;
    cout<<"Press I for in-patient or O for outpatient."<<endl;
    cin>>choice;
    
    //Input validation for menu choice
    while(choice!='i'&&choice!='I'&&choice!='o'&&choice!='O')
    {
        cout<<"Error. You must enter  I or O"<<endl;
        cout<<"Were you admitted to the hospital as an in-patient or an out-patient?"<<endl;
        cout<<"Press I for in-patient or O for outpatient."<<endl;
        cin>>choice;
        
    }
    //Conditionally executes is the user enters i or I indicating they are inpatient
    if(choice=='I'||choice=='i')
         {
        cout<<"How many days did you stay in the hospital?"<<endl;
        cin>>days;
        //Input validation to not accept negative numbers
        while(days<0)
        {
            cout<<"ERROR. The value cannot be negative"<<endl;
            cout<<"How many days did you stay in the hospital?"<<endl;
            cin>>days;
        }
        
        cout<<"What is the daily rate for the hospital stay?"<<endl;
        cin>>rate;
        //Input validation to not accept negative numbers
        while(rate<0)
        {
            cout<<"ERROR. The value cannot be negative"<<endl;
            cout<<"What is the daily rate for the hospital stay?"<<endl;
            cin>>rate;
        }
        cout<<"What is the hospital medication charges?"<<endl;
        cin>>medChar;
         //Input validation to not accept negative numbers
        while(medChar<0)
        {
            cout<<"ERROR. The value cannot be negative"<<endl;
            cout<<"What is the hospital medication charges?"<<endl;
            cin>>medChar;
        }
        
        cout<<"What are the charges for the hospital services?"<<endl;
        cin>>hospSer;
        //Input validation to not accept negative numbers
        while(hospSer<0)
        {
            cout<<"ERROR. The value cannot be negative"<<endl;
            cout<<"What are the charges for the hospital services?"<<endl;
            cin>>hospSer;
        } 
        
        //Sends input to patient function and Outputs total charges 
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<"The total charges for your hospital stay is $"<<patient(days,rate,medChar,hospSer);
        }
    //Conditionally executes if O was selected
    else
    {  
        cout<<"What are the charges for the hospital services?"<<endl;
        cin>>hospSer;
        //Input validation to not accept negative numbers
        while(hospSer<0)
        {
            cout<<"ERROR. The value cannot be negative"<<endl;
            cout<<"What are the charges for the hospital services?"<<endl;
            cin>>hospSer;
        }
        cout<<"What is the hospital medication charges?"<<endl;
        cin>>medChar;
         //Input validation to not accept negative numbers
        while(medChar<0)
        {
        cout<<"ERROR. The value cannot be negative"<<endl;
        cout<<"What is the hospital medication charges?"<<endl;
        cin>>medChar;
        }
        //Sends input to patient function and Outputs total charges 
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<"Your total charges for your hospital visit is $"<<patient(hospSer,medChar);        
    }
    //Execute program
    return 0;
}
//Patient function for in-patient cost
float patient(int days,float rate, float medChar,float hospSer)
{
    //Declare variables
    float dayChar;                //Holds total daily charge
    float totChar;                //Holds total charge
    
    //Calculates total daily charges
    dayChar=days*rate;
    //Calculates total charges
    totChar=dayChar+medChar+hospSer;
    //Returns total charge for in-patient to main
    return totChar;
}
//Patient function for out-patient cost
float patient(float hospSer,float medChar)
{
    //Returns total charge for out-patient to main
    return hospSer+medChar;
}