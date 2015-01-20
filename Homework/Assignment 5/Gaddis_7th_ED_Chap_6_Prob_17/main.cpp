/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 20, 2015, 11:31 AM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_17
 *          Cost of paint rooms
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
int gallons(float);                  //Function prototype for calculating number of gallons
float costGal(int,float);            //Function prototype for calculating the cost of paint
int labor(float);                    //Function prototype for calculating the hours of labor
float costLab(int);                  //Function prototype for calculating the cost of labor
float total(float,float);            //Function prototype for calculating the total cost of the job

//Execution Begins Here!
int main()
{
   //Declare variables
    unsigned short rooms;            //Holds users input for number of rooms   
    float patGal;                    //Holds users input for price per gallon
    float sqFt;                      //Holds users input for Square feet of a room
    float totSqFt;                   //Accumulates Total square feet
    float costHour;                  //Total cost of labor
    float totPaint;                  //Total cost for x gallons of paint needed
    int totHours;                    //Total number of hours
    int numGal;                      //Total gallons
    
    //Prompts user for number of rooms, price per gallon of paint, and total square feet per room
    cout<<"Please enter the number of rooms as a whole number."<<endl;
    cin>>rooms;
    
    cout<<"What is the price per gallon of paint?"<<endl;
    cin>>patGal;
    //Loops for the number of rooms inputed
    for(int count=1;count<=rooms;count++)
    {
        cout<<"How many square feet is room #"<<count<<endl;
        cin>>sqFt;
        //Accumulates total square feet
        totSqFt+=sqFt;
        
    }
    //Function call to calculate number of gallons and stores return value in variable
    numGal=gallons(totSqFt);
    //Function call to calculate number of hours and stores return value in variable
    totHours=labor(totSqFt);
    //Function call to calculate the cost of paint for x number of gallons 
    //and store return value in variable
    totPaint=costGal(numGal,patGal);
    //Function call to calculate cost of labor for x number of hours and stores return value in variable
    costHour=costLab(totHours);
    
    //Output number of gallons needed, the hours of labor required, the cost of paint;
    //the cost of labor, and the total cost of job
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"The total gallons of paint needed is "<<numGal<<endl;
    cout<<"The hours of labor required for this job is "<<totHours<<endl;
    cout<<"The cost of the paint is $"<<totPaint<<endl;
    cout<<"The cost of labor is $"<<costHour<<endl;
    //Output contains function call to calculate total cost of job
    cout<<"The total cost of the job is $"<<total(totPaint,costHour);
    //Exit program
    return 0;
}
    //Function  to calculate number of gallons
    int gallons(float num1)
    {  
    //Declare variables
    float totGal;                       //Holds total gallons
    const int feet=115;                 //Number of square feet per gallon of paint
    //Calculates total gallons rounded up to the next hour
    totGal=(num1/feet)+.99;
    //Return value 
    return static_cast<int>(totGal);
    }
    //Function to calculate the number of hours
    int labor(float num1)
    {
    //Declare variable    
    const int feet=115;               //Number of square feet per 8 hour shift
    unsigned short hour=8;            //hours per gallon of paint
    int totHours;                     //Holds total hours
    //Calculate total hours rounded up to the next hour
    totHours=((num1/feet)*8)+.99;
    //Return total hours
    return totHours;

    }
    //Function for calculating the cost of x amount of gallons of paint
    float costGal(int num1,float num2)
    {  //Return number of gallons multiplied by cost per gallon
       return num1*num2; 
    }
    //Function that calculates the cost of labor
    float costLab(int num1)
    {
        //Declare variables
        float money=18.00;           //Labor rate per hour
        
        //Return hourly rate multiplied by total hours
        return money*num1;
    }
    //Function to calculate the total cost of the job
    float total(float num1,float num2)
    { 
        //Returns cost of paint plus cost of labor
        return num1+num2;
    }