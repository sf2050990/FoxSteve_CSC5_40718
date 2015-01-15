/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 13, 2015, 12:00 PM
 * Purpose: Gaddis_7th_ED_Chap_4_Prob_17
 * 
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float radio=1.0e-2;                      //Global constant for electromagnetic wave per meter representing
                                               //The lowest value for radio waves
const float micro=1.0e-3;                      //Global constant for electromagnetic wave per meter representing
                                               //The lowest value for micro waves
const float infared=7.0e-7;                    //Global constant for electromagnetic wave per meter representing
                                               //The lowest value for infared waves
const float visible=4.0e-7;                    //Global constant for electromagnetic wave per meter representing
                                               //The lowest value for visible light waves
const float ultra=1.0e-8;                      //Global constant for electromagnetic wave per meter representing
                                               //The lowest value for ultra violet waves
const float xray=1.0e-11;                      //Global constant for electromagnetic wave per meter representing
                                               //The lowest value for xray waves



//Execution Begins Here!

int main()
{   
    float wave;                                 //Holds users input for wave
    
    //Prompts user enter electromagnetic wave length to figure out what type of radiation it is
    cout<<"Please enter a electromagnetic wave in meters in scientific notation or decimal";
    cin>>wave;
   
    //Conditionally executes if wave entered is greater than the smallest value that indicates a radio wave
    if(wave>=radio)
     cout<<"The electromagnetic wave is a radio wave";
    //Conditionally executes if wave entered is greater than the smallest value that indicates a micro wave
    else if(wave>=micro)
        cout<<"The electromagnetic wave is a micro wave";
    //Conditionally executes if wave entered is greater than the smallest value that indicates a infrared wave
    else if(wave>=infared)
        cout<<"The electromagnetic wave is infrared";
    //Conditionally executes if wave entered is greater than the smallest value that indicates a visible light wave
    else if(wave>=visible)
        cout<<"The electromagnetic wave is visible light";
    //Conditionally executes if wave entered is greater than the smallest value that indicates a ultra violet wave
    else if(wave>=ultra)
        cout<<"The electromagnetic wave is ultralight light";
    //Conditionally executes if wave entered is greater than the smallest value that indicates a xray wave
    else if(wave>=xray)
        cout<<"The electromagnetic wave is an x-ray";
    //Conditionally executes if the wave is smaller then the smallest value for infrared
    else 
        cout<<"The electromagnetic wave is a gamma ray";
    
    
    return 0;
}