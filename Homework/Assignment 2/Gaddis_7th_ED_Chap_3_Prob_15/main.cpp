/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 10, 2015, 3:00 PM
 * Purpose: Gaddis_7th_ED_Chap_3_Prob_15
 * 
 */
// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std;

int main() 
{
    //Initialize variable
    unsigned num1;                         //Hold first random variable
    unsigned num2;                         //Holds second random variable
    unsigned seed=time(0);                 //seeds random number generator    
    int answer;                            //Input of answer from user
    int corAnsr;                           //Output of the correct answer
    
    //seeding random number generator
    srand(seed); 
    
    //Assigns a random number between one and one thousand 
    num1=rand()%1000+1;
  
    //Assigns second random number between one and one thousand
    num2=rand()%1000+1;
    
    //Calculates the correct answer of the two random generated number
    corAnsr=num1+num2;
    
    //Output the random numbers in an addition problem 
    cout<<"  "<<num1<<endl;
    cout<<"+ "<<num2<<endl;
    cout<<"_____"<<endl;
    
    //Input of users answer
    cin>>answer;
    cin.ignore();
   
    //Outputs the correct answer in the form of an addition problem
    cout<<right<<"  "<<num1<<endl;
    cout<<right<<"+ "<<num2<<endl;
    cout<<"_____"<<endl;
    cout<<setw(5)<<corAnsr<<endl;
    
    //Conditionally Outputs a statement pending on whether the answer is correct
    if(answer==corAnsr)
        cout<<"Congrats thats the correct answer!!!";
    else
        cout<<"Sorry that is not the correct answer.";

    //Exit program
    return 0;
}
