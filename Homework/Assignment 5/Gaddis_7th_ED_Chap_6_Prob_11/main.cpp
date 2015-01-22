/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 21, 2015, 2:05 PM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_11
 *          Judges Score
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
void getJudgeData(float &);                             //Function prototype that changes reference variables
void calcScore(float,float,float,float,float);          //Function prototype that calculates the average judges score
float findLowest(float,float,float,float,float);        //Function prototype that finds the lowest value
float findHighest(float,float,float,float,float);       //Function prototype that finds the highest value
//Execution Begins Here!

int main() 
{
    //Declare variables
    float judge1;                        //Judge 1 score
    float judge2;                        //Judge 2 score
    float judge3;                        //Judge 3 score
    float judge4;                        //Judge 4 score
    float judge5;                        //Judge 5 score
    
        //Function call to getJudgeDate to find judge 1,2,3,4,5 score and use reference
        //Variable to change value
        getJudgeData(judge1);
        getJudgeData(judge2);
        getJudgeData(judge3);
        getJudgeData(judge4);
        getJudgeData(judge5);
       
        //Function call to send judge's values to function calcScore;
        calcScore(judge1,judge2,judge3,judge4,judge5);
}
//getJudgeData Function
void getJudgeData(float &num1)
{
    //Prompt user for judges score
    cout<<"What is the  judge's  score? Value should be between one and ten"<<endl;
    cin>>num1;
   
    //Validates input to be in the range 1-10
    while(num1<0||num1>10)
    {
    cout<<"ERROR:Not a valid test score"<<endl;
    cout<<"What is the judges score? Value should be between one and ten"<<endl;
    cin>>num1;
    }
            
}
//calcScore Function to calculate average
void calcScore(float num1,float num2, float num3, float num4,float num5)
{
    //Holds lowest score through a function call to findLowest
    float lowest=findLowest(num1,num2,num3,num4,num5);
    //Holds highest score through a function call to findHighest
    float highest=findHighest(num1,num2,num3,num4,num5);
    //Calculates average of three of these test scores
    float average=(num1+num2+num3+num4+num5-lowest-highest)/3;
    
    //Output the average score
    cout<<"The average score from the  judges is "<<average;
  
    
}
//findLowest function to find lowest score of the five values
float findLowest(float num1, float num2, float num3, float num4, float num5)
{
    float lowest=num1;                    //Initialize lowest with first value
    
    //Conditionally executes if there is a number lower that the initial value of lowest variable
     if(lowest>num2)
       lowest=num2;
        if(lowest>num3)
          lowest=num3;
            if(lowest>num4)
                  lowest=num4;
                    if(lowest>num5)
                    lowest=num5;
       //Returns the value stored in lowest        
       return lowest;
    
}
//findhighest function to find the highest value
float findHighest(float num1, float num2, float num3, float num4, float num5)
{   
    float highest=num1;                   //Initialized with first value
    
    //Conditionally executes if there is a number higher that the initial value of highest variable
    if(highest<num2)
        highest=num2;
        if(highest<num3)
           highest=num3;
            if(highest<num4)
                  highest=num4;
                    if(highest<num5)
                      highest=num5;

    //returns highest variable value
    return highest;
}