/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 19, 2015, 3:05 PM
 * Purpose: Gaddis_7ED_Chap_6_Prob_23
 *          Rock, Paper, Scissors
 */
// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototype
void hand(int);
void hand2(int);
int result(int,int);

//Execution Begins Here!
int main()
{   //Declare Variables
    unsigned short oppHand;                  //Holds opponents move
    unsigned short choice;                   //Holds menu choice
    unsigned short num;                      //Sentinel to continue loop 
  //Loops if the user and computer use the same moves  
  do  
  { 
    int seed=time(0);                       //Seeds random number generators
    srand(seed);                            //Random number generator
    oppHand=1+rand()%3;                     //Range of opponents move between 1-3
    
    //Prompt user for a menu choice
    cout<<"Please enter a choice:"<<endl;
    cout<<"1: Rock"<<endl;
    cout<<"2: Paper"<<endl;
    cout<<"3: Scissors"<<endl;
    cin>>choice;
    //Sends choice to hand function
    hand(choice);
    //Sends opponents move to hand2 function
    hand2(oppHand);
    //Sentinel to continue loop if the same moves are selected
    num=result(choice,oppHand);
  }while(num==1);
   //Exit program  
    return 0;
}
    //Hand function
    void hand(int choice)
    {
        //Conditionally executes pending on menu selection
        switch(choice)
        {
            //Conditionally executes if 1 was chosen
            case 1: cout<<"You have chosen Rock"<<endl;
                    break;
            //Conditionally executes if 2 was chosen
            case 2: cout<<"You have chosen Paper"<<endl;
                    break;
            //Conditionally executes if 3 was chosen        
            case 3: cout<<"You have chosen Scissors"<<endl;
                    break;
        }
    }
    //hand2 Function
    void hand2(int oppHand)
    {   //Conditionally executes depending opponents move
        switch(oppHand)
        {   //Conditionally executes if 1 was chosen
            case 1: cout<<"Your opponent has chosen Rock"<<endl;
                    break;
            //Conditionally executes if 2 was chosen        
            case 2: cout<<"Your opponent has chosen Paper"<<endl;
                    break;
            //Conditionally executes if 3 was chosen
            case 3: cout<<"Your opponent has chosen Scissors"<<endl;
                    break;
        }
    }
    //Result Function
   int result(int choice,int oppHand)
    {   //Conditionally executes if users choice equals opponents hand and sends sentinel to continue loop
        if (choice==oppHand)
        {
          cout<<"You tied. Go again"<<endl;
          int num=1;
          return num;
        }
        //Conditionally executes if users choice is 1 and opponents move 3
        else if(choice==1&&oppHand==3)
          cout<<"Rock beats scissors. You Win";
        //Conditionally executes if users choice is 2 and opponents move 1
        else if(choice==2&&oppHand==1)
          cout<<"Paper beats rock. You Win";
        //Conditionally executes if users choice is 3 and opponents move 2
        else if(choice==3&&oppHand==2)
           cout<<"Scissors beats paper. You Win";
        //Conditionally executes if users choice is 1 and opponents move 2
        else if(choice==1&&oppHand==2)
           cout<<"Paper beats rock. You Lose";
        //Conditionally executes if users choice is 2 and opponents move 3
        else if(choice==2&&oppHand==3)
           cout<<"Scissors beats paper. You Lose";   
        //Conditionally executes if users choice is 3 and opponents move 1
        else
           cout<<"Rock beats scissors. You Lose";        
    }