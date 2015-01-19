/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 13, 2015, 1:20 PM
 * Purpose: Gaddis_7th_ED_Chap_4_Prob_14
 *          Runners in ascending order
 */
// System Libraries
#include <iostream>
#include <string>
using namespace std;
//Execution begins here
int main()
{
    string name1;                      //Holds name of first runner
    string name2;                      //Holds name of second runner
    string name3;                      //Holds name of third runner
    float time1;                       //Holds time for runner 1
    float time2;                       //Holds time for runner 2
    float time3;                       //Holds time for runner 1
    
    //Prompts user to enter the names of three runners
    cout<<"Please enter three runners names";
    getline(cin,name1);
    getline(cin,name2);
    getline(cin,name3);
    
    //Prompts user to enter the times of the three  runners
    cout<<"Please enter their running times in format 00.00(minutes.seconds)";
    cin>>time1>>time2>>time3;
    
    //Conditionally executes an error message if time 1,2, or 3 is a negative number
    if(time1<0||time2<0||time3<0)
        cout<<"ERROR: Running times must be positive";
    
    //Conditionally executes if the runner 1 is the lowest time followed by runner3
    else if(time1<time2&&time1<time3&&time2<time3)
    {   
        cout<<name1<<":  "<<time1<<endl;
        cout<<name2<<":  "<<time2<<endl;
        cout<<name3<<":  "<<time3<<endl;
    }
         //Conditionally executes if the runner 1 is the lowest time followed by runner 3
         else if(time1<time2&&time1<time3&&time2>time3)
         {
            cout<<name1<<":  "<<time1<<endl;
            cout<<name3<<":  "<<time3<<endl;
            cout<<name2<<":  "<<time2<<endl;
         }   
         //Conditionally executes if the runner 2 is the lowest time followed by runner 1 
        else if(time2<time1&&time2<time3&&time1<time3)
         {
            cout<<name2<<":  "<<time2<<endl;
            cout<<name1<<":  "<<time1<<endl;
            cout<<name3<<":  "<<time3<<endl;
         }
        //Conditionally executes if the runner 2 is the lowest time followed by runner 3
        else if(time2<time1&&time2<time3&&time1>time3)
         {
            cout<<name2<<":  "<<time2<<endl;
            cout<<name3<<":  "<<time1<<endl;
            cout<<name1<<":  "<<time1<<endl;
         }
         //Conditionally executes if the runner 3 is the lowest time followed by runner 1 
        else if(time3<time1&&time3<time2&&time1<time2)
         {
            cout<<name3<<":  "<<time3<<endl;
            cout<<name1<<":  "<<time1<<endl;
            cout<<name2<<":  "<<time2<<endl;
         }
         //Conditionally executes if the runner 3 is the lowest time followed by runner 2
        else 
         {
            cout<<name3<<":  "<<time3<<endl;
            cout<<name2<<":  "<<time2<<endl;
            cout<<name1<<":  "<<time1<<endl;
         }
    
    //exit program
    return 0;
}