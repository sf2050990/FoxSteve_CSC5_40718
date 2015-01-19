/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 10, 2015, 12:15 PM
 * Purpose: Gaddis_7th_ED_Chap_3_Prob_22
 *          Word Game
 */
// System Libraries
#include <iostream>
#include <string>
using namespace std;

//Execution begins here
int main()
{  
    //Initialize string variables
    string age;                         //Holds age input
    string name;                        //Holds name input
    string city;                        //Holds city input
    string college;                     //Holds college input
    string job;                         //Holds job Input
    string animal;                      //Holds animal input
    string pet;                         //Holds pet input
    
    //Prompt for users name    
    cout<<"Please enter your name.";
    getline(cin,name);                             //Hold full string
   
    //Prompt for users age
    cout<<"Please enter your age";
    getline(cin,age);
    
    //Prompt for users city
    cout<<"Please enter the city you live in.";
    getline(cin,city);
    
    //Prompt for users college
    cout<<"Please enter the college that you have attended.";
    getline(cin,college);
    
    //Prompt for users occupation
    cout<<"Please enter your occupation";
    getline(cin,job);
    
    //Prompt for users favorite animal
    cout<<"Please enter your favorite animal.";
    getline(cin,animal);
    
    //Prompt for users favorite pets name
    cout<<"What is the name of your favorite pet";
    getline(cin,pet);
    
    //Output name, age, city, college, occupation, animal, and pets name
    cout<<"There once was a person named "<<name<< " who lived in "<<city<<". at the age"<<endl;
    cout<<age<<" "<<name<<" went to college at "<<college<<". "<<name<<" graduated and went to work"<<endl;
    cout<<"as a "<<job<<". Then, "<<name<<" adopted a(n) "<<animal<<" named "<<pet<<". They"<<endl;
    cout<<"both lived happy ever after.";
            
    //Exit Program
    return 0;
}