/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 11, 2015, 4:25 PM
 * Purpose: Gaddis_7th_ED_Chap_4_Prob_16
 *          Calories from fat
 */
// System Libraries
#include <iostream>
using namespace std;

//Global Constants
const char CONPERC=100;                //Global constant converts decimal into a percent
//Execution begins here
int main()
{
    unsigned int cal;                  //Number of calories
    unsigned int fat;                  //Grams of fat
    float calfat;                      //Calories from fat
    float calPerc;                     //Percentage of calories from fat
    
    //Prompt user to enter the number of calories
    cout<<"Please enter the number of calories"<<endl;
    cin>>cal;
    
   //Prompt user to enter the amount of fat in grams
    cout<<"Please enter the amount of fat in grams"<<endl;
    cin>>fat;
    
    //Calculate calories from fat
    calfat=fat*9;
    
    //Calculate perntage of calories from fat
    calPerc=(calfat/cal)*100;
    
    //Conditionally executes when fat and calories are above 0
    if(fat>=0&&cal>=0)
        
        //Conditionally executes if calories from fat is less than total calories
        { if(calfat<cal)
            { 
              //Coditionally executes if pertentage of calories from fat is less than 
              if (calPerc<30)
              //Output percentage of calories from fat and indicate this food is low in fat    
              {cout<<"Percentage of calories from fat is "<<calPerc <<"%"<<endl;
               cout<<"This food is low in fat!!!";
              }
              //Conditionally executes if all requirements are met but the food is not low in fat
              else
                //Output percentage of calories from fat  
                cout<<"Percentage of calories from fat is "<<calPerc <<"%"<<endl;
             }
        //Conditionally executes if calories from fat is greater than total calories
        else
        {cout<<"Invalid entry. calories from fat can not be greater than total calories"<<endl;
             cout<<"Run program again";
        }
    }
    //Conditionally executes if calories or fat is not greater than 0
    else
    {cout<<"ERROR: Fat and calorie count must be more than 0."<<endl;
         cout<<"Please run program again"<<endl;
    }

    //Exit program
    return 0;
}