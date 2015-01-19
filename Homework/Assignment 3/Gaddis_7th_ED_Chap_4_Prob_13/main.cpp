/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 13, 2015, 6:05 PM
 * Purpose:Gaddis_7th_ED_Chap_4_Prob_3
 *         Calculate shipping cost
 * 
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Execution begins here
int main()
{
    float kg2less=1.10;                    //Shipping rate of a package between 0-2 kilograms
    float kg6less=2.20;                    //Shipping rate of a package between 2.1-6 kilograms
    float kg10less=3.70;                   //Shipping rate of a package between 6.1-10 kilograms
    float kg20less=4.80;                   //Shipping rate of a package between 10.1-20 kilograms
    float weight;                          //Holds users input for the weight of the package
    float distance;                        //Holds users input for the distance the package will travel
    float ratedis;                         //Holds accumulates fees per 500 miles
    float total;                           //Holds the total bill
    
    //Prompt user for the weight of the package
    cout<<"What is the weight of the package in kilograms? (between 0-20 kg)"<<endl;
    cin>>weight;
   
    //Prompt user for the distance the package will travel
    cout<<"How far is the package traveling? (between 10-3000 miles)"<<endl;
    cin>>distance;
    
    //Conditionally executes if the weight of the package is less than 0 and more than 20 kilograms
    if(weight<0||weight>20)
        cout<<"ERROR: Please enter a weight between 0-20";
     //Conditionally executes if the distance of the package is less than 10 and more than 3000 miles
    else if(distance<10||distance>3000)
        cout<<"ERROR: Please enter a distance between 10 and 3000 miles";
            
    //Conditionally executes is weight of the package is between 10-20 kilograms
    else if(weight<=20&&weight>10)
    {
        //Conditionally executes if distance is equal to 3000 miles
        if (distance==3000)
            //Calculates the associated rate for this distance
           ratedis=kg20less*6;
        //Conditionally executes if distance is between 2500-2999 miles
        else if(distance>=2500)
           //Calculates the associated rate for this distance
           ratedis=kg20less*5;
        //Conditionally executes if distance is between 2000-2499 miles
        else if(distance>=2000)
           //Calculates the associated rate for this distance
           ratedis=kg20less*4;
        //Conditionally executes if distance is between 1500-1999 miles
        else if(distance>=1500)
           //Calculates the associated rate for this distance
           ratedis=kg20less*3;
        //Conditionally executes if distance is between 1000-1499 miles
        else if(distance>=1000)
           //Calculates the associated rate for this distance
           ratedis=kg20less*2;
        //Conditionally executes if distance is between 10-999 miles
        else
            //Calculates the associated rate for this distance
            ratedis=kg20less;
        //Assumes value of  calculated rate depending on distance 
        total=ratedis;
        
     //Output result
     cout<<setprecision(2)<<fixed<<showpoint;
     cout<<"The total bill for this package $ "<<total;
    } 
     //Conditionally executes is weight of the package is between 6-10 kilograms
    else  if(weight<=10&&weight>6)
    {
        //Conditionally executes if distance is equal to 3000 miles
        if (distance==3000)
           //Calculates the associated rate for this distance
           ratedis=kg10less*6;
        //Conditionally executes if distance is between 2500-2999 miles
        else if(distance>=2500)
           //Calculates the associated rate for this distance
           ratedis=kg10less*5;
        //Conditionally executes if distance is between 2000-2499 miles
        else if(distance>=2000)
           //Calculates the associated rate for this distance
           ratedis=kg10less*4;
        //Conditionally executes if distance is between 1500-1999 miles
        else if(distance>=1500)
           //Calculates the associated rate for this distance
           ratedis=kg10less*3;
        //Conditionally executes if distance is between 1000-1499 miles
        else if(distance>=1000)
           //Calculates the associated rate for this distance
           ratedis=kg10less*2;
        //Conditionally executes if distance is between 10-999 miles
        else
            //Calculates the associated rate for this distance
            ratedis=kg10less;
            //Assumes value of  calculated rate depending on distance 
            total=ratedis;
     //Output result       
     cout<<setprecision(2)<<fixed<<showpoint;
     cout<<"The total bill for this package $ "<<total;
    } 
     //Conditionally executes is weight of the package is between 2-6 kilograms
    else  if(weight<=6&&weight>2)
    {
        //Conditionally executes if distance is equal to 3000 miles
         if (distance==3000)
           //Calculates the associated rate for this distance
           ratedis=kg6less*6;
         //Conditionally executes if distance is between 2500-2999 miles
        else if(distance>2500)
           //Calculates the associated rate for this distance
           ratedis=kg6less*5;
         //Conditionally executes if distance is between 2000-2499 miles
        else if(distance>=2000)
           //Calculates the associated rate for this distance
           ratedis=kg6less*4;
        //Conditionally executes if distance is between 1500-1999 miles
        else if(distance>=1500)
           //Calculates the associated rate for this distance
           ratedis=kg6less*3;
        //Conditionally executes if distance is between 1000-1499 miles
        else if(distance>=1000)
           //Calculates the associated rate for this distance
           ratedis=kg6less*2;
        //Conditionally executes if distance is between 10-999 miles
        else
            //Calculates the associated rate for this distance
            ratedis=kg6less;
            //Assumes value of  calculated rate depending on distance 
            total=ratedis;
     //Output result       
     cout<<setprecision(2)<<fixed<<showpoint;
     cout<<"The total bill for this package $ "<<total;
    } 
     //Conditionally executes is weight of the package is between 0-2 kilograms
    else  
    {
        //Conditionally executes if distance is equal to 3000 miles
        if (distance==3000)
           //Calculates the associated rate for this distance
           ratedis=kg2less*6;
        //Conditionally executes if distance is between 2500-2999 miles
        else if(distance>=2500)
           //Calculates the associated rate for this distance
           ratedis=kg2less*5;
        //Conditionally executes if distance is between 2000-2499 miles
        else if(distance>=2000)
           //Calculates the associated rate for this distance
           ratedis=kg2less*4;
        //Conditionally executes if distance is between 1500-1999 miles
        else if(distance>=1500)
           //Calculates the associated rate for this distance
           ratedis=kg2less*3;
        //Conditionally executes if distance is between 1000-1499 miles
        else if(distance>=1000)
           //Calculates the associated rate for this distance
           ratedis=kg2less*2;
        //Conditionally executes if distance is between 10-999 miles
        else
            //Calculates the associated rate for this distance
            ratedis=kg2less;
           //Assumes value of  calculated rate depending on distance 
            total=ratedis;
     //Output result        
     cout<<setprecision(2)<<fixed<<showpoint;
     cout<<"The total bill for this package $ "<<total;
    } 
    //Exit Program    
    return 0;
}