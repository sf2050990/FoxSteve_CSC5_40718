/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 27, 2015, 10:05 AM
 * Purpose: Gaddis_7th_ED_Chap_7_Prob_9
 *          Drivers license exam
 */
// System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here!

int main() 
{
    //Declare variables
    //Array that holds correct answers to the test
    char corAnsw[20]={'b','d','a','a','c','a','b','a','c','d','b','c','d','a','d','c','c','b','d','a'};
    char stuAnsw[20];                       //Array that holds students answer
    int incAns[20];                         //Array that holds the questions that were incorrectly answered
    int correct=0;                          //Accumulates correct answer
    int notcor=0;                           //Accumulates incorrect answer
    int inc=0;                              //Stores incorrect question number in incAns Array
    
    //Loops through the students 20 answers and compares them to the correct answers
    for(int count=0;count<20;count++)
    {
        //Prompts user to enter students answer to question
        cout<<"Enter students answer for question #"<<count+1<<" please input answer in lower case."<<endl;
        cin>>stuAnsw[count];
        //Input validation for a,b,c,and d
        while(stuAnsw[count]!='a'&&stuAnsw[count]!='b'&&stuAnsw[count]!='c'&&stuAnsw[count]!='d')
        {
            cout<<"ERROR: The answer must be a, b, c, d"<<endl;
            cout<<"Enter students answer for question #"<<count+1<<" please input answer in lower case."<<endl;
            cin>>stuAnsw[count];
        }
        //Conditionally executes if the student answer was correct
        if(corAnsw[count]==stuAnsw[count])
            correct+=1;
       //Conditionally executes if the student answer was incorrect and the question is stored in incAnsw array
        else
        {
            notcor+=1;
            incAns[inc]=count+1;
            inc++;
        }
         
    }
    //Conditionally executes if the number of correct answers is above 15 and outputs that the user has passed the test
    if(correct>=15)
        cout<<"Congratulations the student has passed the test"<<endl;
    //Conditionally executes if the number of correct answers is less than 15 and outputs that the user failed the test
    else
        cout<<"The student did not pass the test."<<endl;
    
    //Outputs the correct number of answers, the number of incorrect answers, and the questions that were missed
    cout<<"The number of correct answers is "<<correct<<endl;
    cout<<"The number of incorrect answers is "<<notcor<<endl;
    cout<<"The questions that the student missed are ";
    //Loops through contents of the array
    for(int count=0;count<inc;count++)
    cout<<incAns[count]<<", ";
    
    //Exit program
    return 0;
}