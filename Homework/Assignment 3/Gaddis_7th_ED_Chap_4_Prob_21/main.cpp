/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 13, 2015, 9:51 AM
 * Purpose: Gaddis_7th_ED_Chap_4_Prob_21
 * 
 */
// System Libraries
#include <iostream>
using namespace std;

//Function Prototype
const float PI=3.14159;                      //Global constant of the value of pie

int main() 
{

short choice;                               //Holds user choice
float area;                                 //Holds area depending on users menus choice

//Prompt user to select a menu choice for the area of a shape
cout<<"Please enter the shape for which you would like to calculate the area of"<<endl;
cout<<"1: Calculate the area of a circle"<<endl;
cout<<"2: Calculate the area of a rectangle"<<endl;
cout<<"3: Calculate the area of a triangle"<<endl;
cout<<"4: Quit"<<endl<<"Enter a choice between 1-4"<<endl;

//Holds users menu choice
cin>>choice;

//Conditionally executes a statement depending on menu choice
switch(choice)
{ 
    //Conditionally executes if users choice is 1
    case 1: 
            
            float radius;                       //Holds value for radius
            
            //Prompt user for the radius of a circle
            cout<<"What is the radius of the circle?";
            
             //Holds users entry for the radius of a circle
            cin>>radius;
            
            //Conditionally executes an error message if radius is less than 0
            if(radius<0)
               cout<<"ERROR: radius cannot be a negative value"; 
            
            //Conditionally executes is all requirements are met
            else
            {
                //Calculates the area of a circle
                area=PI*(radius*radius);
                
                //Outputs the area of a circle
                cout<<"The area of the circle is "<<area;
            }
            
            break;
            
    //Conditionally executes if users choice is 2
    case 2:
            float height1;                    //Height of the rectangle
            float width;                      //Width of the rectangle
            
            //Prompt the user for the height and width of a rectangle
            cout<<"What is the height of the rectangle?"<<endl;
            cin>>height1;
            cout<<"What is the width of the rectangle?"<<endl;
            cin>>width;
            
            //Conditionally executes an error message if height and width is less that 0
            if(height1<0||width<0)
               cout<<"ERROR: The rectangles height and width cannot be negative values";
            
            //Conditionally executes if all requirements are met
            else
            { 
                //Calculates the area of a rectangle
                area=width*height1;                 
                
                //Output the area of the rectangle
                cout<<"The area of the rectangle is "<<area<<endl;
            }
            
            break;
            
   //Conditionally executes if users choice is 3
    case 3:
            float base;                      //Base of triangle
            float height2;                   //height of rectangle
         
            //Prompt user for the base and height of the triangle
            cout<<"What is the base of the triangle?"<<endl;
            cin>>base;
            cout<<"What is the height of the triangle?"<<endl;
            cin>>height2;
              
              //Conditionally executes an Error if the base or height of the triangle is less than 0
              if(base<0||height2<0)
              cout<<"ERROR: The base and height cannot be negative values";
              
              //Conditionally executes if all requirements are met
              else
              {
                //Calculates area of a triangle
                area=(base*height2)*.5;
                
                //Outputs the area of a triangle
                cout<<"The area of the the triangle is "<<area<<endl; 
              }           
            break;
            
    //Conditionally executes if users choice is 4
    case 4:
           //Outputs a message when user decides to quit
           cout<<"You have selected quit have a nice day";
           break;
    
    //Conditionally executes if a valid menu selection was not used       
    default:cout<<"ERROR: Please select a number between 1-4";
}

//Exits program
return 0;
}