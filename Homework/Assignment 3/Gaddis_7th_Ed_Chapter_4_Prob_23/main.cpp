/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 11, 2015, 2:51 PM
 * Purpose: Gaddis_7th_ED_Chap_4_23
 * 
 */
// System Libraries
#include <iostream>
using namespace std;

//Global Constants


int main()
{
    char choice;                  //Holds users package choice
    int numHour;                  //Number of hours used on internet
    float hourCas;                //Additional fees for over usage
    float cost;                   //Original cost of package
    float totCost;                //Total cost of product with additional hourly fees
    
    //Prompt user to enter the internet package that they have purchased
    cout<<"Please enter the package that you wish to purchase"<<endl;
    cout<<"A: Package A"<<endl;
    cout<<"B: Package B"<<endl;
    cout<<"C: Package C"<<endl;
    cin>>choice;
    
    //Prompt user for the number of hours used in a given month
    cout<<"Please enter the number of hours that were used"<<endl;
    cin>>numHour;
    
    //Conditionally executes an error message if number of hours is less than 0 and greater
    //than 744
    if(numHour>=1&&numHour<=744)
    {
    
   //Menu conditionally executes commands pending on users product choice
    switch(choice)
    {
           //Executes if the users choice was A
            case 'A':
            case'a':   //Output details of the package
                       cout<<"You have enter Package A at $9.95 per month with"<<endl;
                       cout<<"10 hours of service provide and an additional charge of "<<endl;
                       cout<<"$2.00 for each hour used after service provided."<<endl<<endl; 
                       
                       //Conditionally executes if hours is greater than 10
                       if(numHour>10)
                           
                       //Calculates additional hourly fees    
                       hourCas=(numHour-10)*2.00;
                       
                       //Conditionally executes when hours is less then 10 then
                       //number of hours is set to 0
                       else numHour=0;
                       
                       //Initial cost
                       cost=9.95;
                       
                       //Total cost
                       totCost=hourCas+cost;
                       
                       //Output total monthly bill
                       cout<<"Your total bill for this month is $"<<totCost;
                       break;
                       
            case 'B':
            case'b':   
                        //Executes if the users choice was B
                       cout<<"You have enter Package B at $14.95 per month with"<<endl;
                       cout<<"20 hours of service provide and an additional charge of "<<endl;
                       cout<<"$1.00 for each hour used after service provided."<<endl<<endl; 
                       
                       //Conditionally executes if hours is greater than 20
                       if(numHour>20)
                           
                       //Calculates additional hourly fees    
                       hourCas=(numHour-20)*1.00;
                       
                       //Conditionally executes when hours is less then 20 then
                       //number of hours is set to 0
                       else numHour=0;
                       
                       //Initial Cost
                       cost=14.95;
                       
                       //Total monthly bill
                       totCost=hourCas+cost;
                       cout<<"Your total bill for this month is $"<<totCost;
                       break;
            case 'C':
            case'c':   
                       //Executes if the users choice was C
                       cout<<"You have enter Package C at $19.95 per month with"<<endl;
                       cout<<"unlimited access"<<endl<<endl;
                        
                       //Total bill 
                       totCost=19.95;
                       
                       cout<<"Your total bill for this month is $"<<totCost;
                       break; 
                      
                       //Executes if a,b,or c was not chosen
           default:    cout<< "ERROR: Enter a menu choice a,b,c.. Run program again";
    }
    }
    //Conditionally executer if hours was less than 0 or greater than 744-ERROR
    else cout<<"Error: You must enter a number between 1-744. Run program again";
                      

            
   //Exit Program         
   return 0;
}

