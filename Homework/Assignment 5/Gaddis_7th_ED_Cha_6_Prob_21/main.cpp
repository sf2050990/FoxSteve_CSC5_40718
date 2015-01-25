/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 19, 2015, 6:17 PM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_21
 *         prime numbers
 */
// System Libraries
#include <iostream>
using namespace std;

//Function Prototype
bool isPrime(int);                   //Prototype to see if a number is prime
//Execution begins here
int main()
{
    int number;                   //Holds users selection for a number
                       
    //Prompt user for a number
    cout<<"Please enter a number to see if that number is prime.";
    cin>>number;
    
    //sends number to isPrime function and conditionally executes whether the value 
    //returned is true or false
    if (isPrime(number))
        cout<<number<<"  is a prime number.";
    else
        cout<<number<<" not a prime number.";
   //Exit program
    return 0;
}
//isPrime Function
bool isPrime(int num)
{   
    //Boolean variable
    bool status;
    
    //Conditionally executes if num is divisible by 2 and is not 2
    if(num%2==0&&num!=2)
    {  cout<<"The number is divisible by 2."<<endl;
       status=false;
       //Returns 0 to main function
       return status;
    }
    //Conditionally executes if num is divisible by 3 and is not 3
    else if(num%3==0&&num!=3)
    {  cout<<"The number is divisible by 3."<<endl;
       status=false;
       //Returns 0 to main function
       return status;
    }
    //Conditionally executes if num is divisible by 5 and is not 5
    else if(num%5==0&&num!=5)
    {  cout<<"The number is divisible by 5." <<endl; 
       status=false;
       //Returns 0 to main function
       return status;}
    //Conditionally executes if num is divisible by 7 and is not 7
    else if(num%7==0&&num!=7)
    {  cout<<"The number is divisible by seven."<<endl;
       status=false;
       //Returns 0 to main function
       return status;}
    //Conditionally executes if num is not divisible these base numbers
     else
    { 
       status=true;
       //Returns 1 to main function
       return status;}
}