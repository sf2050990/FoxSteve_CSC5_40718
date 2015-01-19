/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 15, 2015, 11:25 AM
 * Purpose: Gaddis_7th_ED_Chap_5_Prob_21
 *          Random number generator guessing game
 */
// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    unsigned seed=time(0);                  //Seed random seed generator with time function
    int guess;                              //Holds users input of guess
    int random;                             //Stores random number
    int count=0;                            //Counter to calculate the amount of turns
    
    //Seed random number generator
    srand(seed);
    //Establish range between 1-500
    random=1+rand()%500;
    //Loops while guess does not equal random number generator
    while(guess!=random)
    {//Records number of turns
        count++;
        
        //Prompts user for guess
        cout<<"Please guess a number between 1-500";
        cin>>guess;
        //Conditionally executes if users guess is too low
        if(guess<random)
            cout<<"Too low. Try again"<<endl;
        //Conditionally executes if users guess is too high
        if(guess>random)
            cout<<"Too high. Try again"<<endl;
        //Conditionally executes if user guess the random number and stops program.
        if(guess==random)
        {
            cout<<"Congratulations. You guessed the number!!"<<endl;
            cout<<"The number of attempts is "<<count;
            break;        
        }
    }
    

    //Exit Program
    return 0;
}