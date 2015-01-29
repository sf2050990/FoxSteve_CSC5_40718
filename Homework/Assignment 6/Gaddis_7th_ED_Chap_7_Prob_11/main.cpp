/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 27, 2015, 9:05 AM
 * Purpose: Gaddis_7th_ED_Chap_7_Prob_11
 *          Students grades
 */
// System Libraries
#include <iostream>
#include <string>
using namespace std;


//Function Prototype
double average(double[]);                         //Function prototype to calculate grade average
//Execution Begins Here!

int main() 
{
    string names[5];                             //Array that holds students name
     char grade[5]={'A','B','C','D','F'};        //Array that holds letter grades
    double stud1[4];                             //Array that holds student 1's test scores
    double stud2[4];                             //Array that holds student 2's test scores
    double stud3[4];                             //Array that holds student 3's test scores
    double stud4[4];                             //Array that holds student 4's test scores
    double stud5[4];                             //Array that holds student 5's test scores
    
    //Loops so user can enter five students names
    for(int count=0; count<5;count++)
    {
        cout<<"Please enter student #"<<count+1<<" name"<<endl;
        getline(cin,names[count]);
      
    }
      //Loops for student 1's test scores
      for(int test=0;test<4;test++)
        {  
           cout<<"Please enter test score #"<<test+1<<" for "<<names[0];
           cin>>stud1[test];
        } 
     //Loops for student 2's test scores
     for(int test=0;test<4;test++)
        {  
           cout<<"Please enter test score #"<<test+1<<" for "<<names[1];
           cin>>stud2[test];
        } 
      //Loops for student 3's test scores
      for(int test=0;test<4;test++)
        {  
           cout<<"Please enter test score #"<<test+1<<" for "<<names[2];
           cin>>stud3[test];
        } 
     //Loops for student 4's test scores
      for(int test=0;test<4;test++)
        {  
           cout<<"Please enter test score #"<<test+1<<" for "<<names[3];
           cin>>stud4[test];
        } 
      //Loops for student 5's test scores
      for(int test=0;test<4;test++)
        {  
           cout<<"Please enter test score #"<<test+1<<" for "<<names[4];
           cin>>stud5[test];
        } 
    //Function call and output of average then conditionally outputs letter grade
    //Depending on the average score for student 1
    cout<<"The average test score for "<<names[0]<<" is "<<average(stud1)<<endl;
    if(average(stud1)>90)
        cout<<names[0]<<" Class grade average is "<<grade[0]<<endl;
    else if(average(stud1)>80)
        cout<<names[0]<<" Class grade average is "<<grade[1]<<endl;
    else if(average(stud1)>70)
        cout<<names[0]<<" Class grade average is "<<grade[2]<<endl;
    else if(average(stud1)>60)
        cout<<names[0]<<" Class grade average is "<<grade[3]<<endl;
    else
        cout<<names[0]<<" Class grade average is "<<grade[4]<<endl;
  
     //Function call and output of average then conditionally outputs letter grade
    //Depending on the average score for student 2
    cout<<"The average test score for "<<names[1]<<" is "<<average(stud2)<<endl;
     if(average(stud2)>90)
        cout<<names[1]<<" Class grade average is "<<grade[0]<<endl;
    else if(average(stud2)>80)
        cout<<names[1]<<" Class grade average is "<<grade[1]<<endl;
    else if(average(stud2)>70)
        cout<<names[1]<<" Class grade average is "<<grade[2]<<endl;
    else if(average(stud2)>60)
        cout<<names[1]<<" Class grade average is "<<grade[3]<<endl;
    else
        cout<<names[1]<<" Class grade average is "<<grade[4]<<endl;
    
    //Function call and output of average then conditionally outputs letter grade
    //Depending on the average score for student 3
    cout<<"The average test score for "<<names[2]<<" is "<<average(stud3)<<endl;
     if(average(stud3)>90)
        cout<<names[2]<<" Class grade average is "<<grade[0]<<endl;
    else if(average(stud3)>80)
        cout<<names[2]<<" Class grade average is "<<grade[1]<<endl;
    else if(average(stud3)>70)
        cout<<names[2]<<" Class grade average is "<<grade[2]<<endl;
    else if(average(stud3)>60)
        cout<<names[2]<<" Class grade average is "<<grade[3]<<endl;
    else
        cout<<names[2]<<" Class grade average is "<<grade[4]<<endl;
    
    //Function call and output of average then conditionally outputs letter grade
    //Depending on the average score for student 4
    cout<<"The average test score for "<<names[3]<<" is "<<average(stud4)<<endl;
     if(average(stud4)>90)
        cout<<names[3]<<" Class grade average is "<<grade[0]<<endl;
    else if(average(stud4)>80)
        cout<<names[3]<<" Class grade average is "<<grade[1]<<endl;
    else if(average(stud4)>70)
        cout<<names[3]<<" Class grade average is "<<grade[2]<<endl;
    else if(average(stud4)>60)
        cout<<names[3]<<" Class grade average is "<<grade[3]<<endl;
    else
        cout<<names[3]<<" Class grade average is "<<grade[4]<<endl;
    
     //Function call and output of average then conditionally outputs letter grade
    //Depending on the average score for student 5
    cout<<"The average test score for "<<names[4]<<" is "<<average(stud5)<<endl;
     if(average(stud5)>90)
        cout<<names[4]<<" Class grade average is "<<grade[0]<<endl;
    else if(average(stud5)>80)
        cout<<names[4]<<" Class grade average is "<<grade[1]<<endl;
    else if(average(stud5)>70)
        cout<<names[4]<<" Class grade average is "<<grade[2]<<endl;
    else if(average(stud5)>60)
        cout<<names[4]<<" Class grade average is "<<grade[3]<<endl;
    else
        cout<<names[4]<<" Class grade average is "<<grade[4]<<endl;
    
    //Exit Program
    return 0;
}
//Function average
double average(double num1[])
{
    //declare variables
    double average;                                  //Stores average
    
    //Calculates average test scores
    average=(num1[0]+num1[1]+num1[2]+num1[3])/4;   
    
    //Returns value average to function main
    return average;
}