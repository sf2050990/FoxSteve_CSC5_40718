/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 23, 2015, 11:05 AM
 * Purpose: Gaddis_7th_ED_Chap_7_Prob_15
 *          Tic,tac, toes
 */
// System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants

//Function Prototype
void player1(int, int,char [][3]);          //Function prototype for player 1
void player2(int, int, char [][3]);         //Function prototype for player 2

//Execution Begins Here!
int main()
{
    //Declare variables
    char game[3][3]={{'*','*','*'},        //2 Dimensional array for game board
                     {'*','*','*'},
                     {'*','*','*'}};
    
    int rows;                              //Holds the row of interest
    int cols;                              //Holds the column of interest
    int count=0;                           //Counter for keeping track of turns
    bool win=false;                        //Boolean set to false
    //Loops as long as boolean is false
    do{
    //Loops to display rows 
    for(int row=0;row<3;row++)
    {   //Loops to display column
        for(int col=0;col<3;col++)
        { 
        //Displays game board    
        cout<<game[row][col];}
        cout<<endl;   
    } 
      
      //Conditionally executes if its player 1 turn
      if(win==false)
      {   //Counter incremented
          count++;
       //Function call to player1 function   
       player1(rows,cols,game);
     
       //Conditionally executes if a winning move for player one is realized and the bool value is changed to true
        if(game[0][0]=='X'&&game[0][1]=='X'&&game[0][2]=='X')
          { cout<<"Player One wins with three in a row on row 1"<<endl;
            win=true;}
        if(game[1][0]=='X'&&game[1][1]=='X'&&game[1][2]=='X')
          {cout<<"Player One wins with three in a row on row 2"<<endl;
           win=true;}
        if(game[2][0]=='X'&&game[2][1]=='X'&&game[2][2]=='X')
          {cout<<"Player One wins with three in a row on row 3"<<endl;
             win=true;}
        if(game[0][0]=='X'&&game[1][0]=='X'&&game[2][0]=='X')
            {cout<<"Player One wins with three in a row on column 1"<<endl;
             win=true;}
        if(game[0][1]=='X'&&game[1][1]=='X'&&game[2][1]=='X')
            {cout<<"Player One wins with three in a row on column 2"<<endl;
             win=true;}
        if(game[0][2]=='X'&&game[1][2]=='X'&&game[2][2]=='X')
           { cout<<"Player One wins with three in a row on column 3"<<endl;
             win=true;}
        if(game[0][0]=='X'&&game[1][1]=='X'&&game[2][2]=='X')
            {cout<<"Player One wins with three in a row diagonally"<<endl;
             win=true;}
        if(game[0][3]=='X'&&game[1][1]=='X'&&game[2][0]=='X')
             {cout<<"Player One wins with three in a row diagonally"<<endl;
             win=true;}
         
    }
    //Conditionally executes if bool is false so player 2 can view the board
    if(win==false)
        {
            //Display game board
            for(int row=0;row<3;row++)
            { 
               for(int col=0;col<3;col++)
                 { 
                 cout<<game[row][col];
                 }
                cout<<endl;
            }
        }
     //Condionally signals a tie if the nine turns have passed and the boolean is still false
      if(count>=9&&win==false)
        {cout<<"Its a tie. Better luck next time"<<endl;
            win=true;
        } 
      //Counter incremented before player 2's turn
      count++;
        //Conditionally executes if boolean is false
        if(win==false)
        {   //Function call to player 2
            player2(rows,cols,game);
       //Conditionally executes if a winning move is realized then boolean is  switched to true     
      if(game[0][0]=='O'&&game[0][1]=='O'&&game[0][2]=='O')
          { cout<<"Player Two wins with three in a row on row 1"<<endl;
            win=true;}
        if(game[1][0]=='O'&&game[1][1]=='O'&&game[1][2]=='O')
          {cout<<"Player Two wins with three in a row on row 2"<<endl;
           win=true;}
        if(game[2][0]=='O'&&game[2][1]=='O'&&game[2][2]=='O')
          {cout<<"Player Two wins with three in a row on row 2"<<endl;
             win=true;}
        if(game[0][0]=='O'&&game[1][0]=='O'&&game[2][0]=='O')
            {cout<<"Player Two wins with three in a row on column 1"<<endl;
             win=true;}
        if(game[0][1]=='O'&&game[1][1]=='O'&&game[2][1]=='O')
            {cout<<"Player Two wins with three in a row on column 2"<<endl;
             win=true;}
        if(game[0][2]=='O'&&game[1][2]=='O'&&game[2][2]=='O')
           { cout<<"Player Two wins with three in a row on column 3"<<endl;
             win=true;}
        if(game[0][0]=='O'&&game[1][1]=='O'&&game[2][2]=='O')
            {cout<<"Player Two wins with three in a row diagonally"<<endl;
             win=true;}
        if(game[0][3]=='O'&&game[1][1]=='O'&&game[2][0]=='O')
             {cout<<"Player Two wins with three in a row diagonally"<<endl;
             win=true;}
        
        
        }
     //Loop keeps going if boolean is false
    }while(win==false);
    
    //Displays final view of the board
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        { 
        cout<<game[row][col];
        }
        cout<<endl;   
    }
    
    //Exit program
    return 0;
}
//player1 Function
void player1(int rows, int cols,char game[][3])
{
    //Declare variables
    bool pos=false;                    //Boolean set to false
    //Loops while boolean is set to false
     do
     {       
         //Prompts that player 1 is x and accepts row and column choice
      cout<<"Player 1 you are X. Please select where your next move will be."<<endl;
        cout<<"Rows and columns are 1-3. Please enter row then the column."<<endl;
        cin>>rows>>cols;
        //Input validation so rows and columns are between 1-3
        while(rows<1||rows>3||cols<1||cols>3)
        {cout<<"ERROR: Rows and columns must be between 1 and 3"<<endl;
        cout<<"Player 1 you are X. Please select where your next move will be."<<endl;
        cout<<"Rows and columns are 1-3. Please enter row then the column."<<endl;
        cin>>rows>>cols;}
     //Places players row and column choice as array subscripts   
     char array[rows][cols];
  
    //Conditionally executes depending on row and column selection of player one and places an X there and
    //if verified Switches boolean to true 
    if (array[rows-1][cols-1]==array[0][0]&&game[0][0]!='O'&&game[0][0]!='X')
    {game[0][0]='X';
       pos=true;}
    else if(array[rows-1][cols-1]==array[0][1]&&array[1][0]!=array[0][1]&&game[0][1]!='O'&&game[0][1]!='X')
    { game[0][1]='X';
       pos=true;}
    else if(array[rows-1][cols-1]==array[0][2]&&array[0][2]!=array[2][0]&&game[0][2]!='O'&&game[0][2]!='X')
    { game[0][2]='X';
      pos=true;}
    else if(array[rows-1][cols-1]==array[1][0]&&game[1][0]!='O'&&game[1][0]!='X')
    {game[1][0]='X';
    pos=true;}
    else if(array[rows-1][cols-1]==array[1][1]&&array[1][1]!=array[2][0]&&game[1][1]!='O'&&game[1][1]!='X')
    { game[1][1]='X';
      pos=true;}
    else if(array[rows-1][cols-1]==array[1][2]&&game[1][2]!='O'&&game[1][2]!='X')
    { game[1][2]='X';
    pos=true;}
    else if(array[rows-1][cols-1]==array[2][0]&&array[2][0]!=array[1][2]&&game[2][0]!='O'&&game[2][0]!='X' )
    {game[2][0]='X';
    pos=true;}
    else if(array[rows-1][cols-1]==array[2][1]&&game[2][1]!='O'&&game[2][1]!='X')
    {  game[2][1]='X';
    pos=true;}
    else if(array[rows-1][cols-1]==array[2][2]&&game[2][2]!='O'&&game[2][2]!='X')
    {game[2][2]='X';
    pos=true;}
    //Output if that space is already taken 
    else
        cout<<"not valid. That space is taken. Try again"<<endl;
    }while(pos==false);
   
}
//player2 Function
void player2(int rows, int cols,char game[][3])
{
   //Declare variables
    bool pos=false;                        //Boolean is set to false
    //Loops as long as bool is set to false
     do{   
      cout<<"Player 2 you are O. Please select where your next move will be."<<endl;
        cout<<"Rows and columns are 1-3. Please enter row then the column."<<endl;
        cin>>rows>>cols;
        //Validates that input of rows and columns are between 1-3
        while(rows<1||rows>3||cols<1||cols>3)
        {cout<<"ERROR: Rows and columns must be between 1 and 3"<<endl;
        cout<<"Player 1 you are X. Please select where your next move will be."<<endl;
        cout<<"Rows and columns are 1-3. Please enter row then the column."<<endl;
        cin>>rows>>cols;}
    //Stores row and column input as array subscripts   
    char array[rows][cols];
    //Conditionally executes depending on row and column input and places an 0 in desired spot
    //and if verified the boolean is switch to true
    if (array[rows-1][cols-1]==array[0][0]&&game[0][0]!='X'&&game[0][0]!='O')
    {game[0][0]='O';
       pos=true;}
    else if(array[rows-1][cols-1]==array[0][1]&&array[1][0]!=array[0][1]&&game[0][1]!='X'&&game[0][1]!='O')
    { game[0][1]='O';
       pos=true;}
    else if(array[rows-1][cols-1]==array[0][2]&&array[0][2]!=array[2][0]&&game[0][2]!='X'&&game[0][2]!='O')
    { game[0][2]='O';
      pos=true;}
    else if(array[rows-1][cols-1]==array[1][0]&&game[1][0]!='X'&&game[1][0]!='O')
    {game[1][0]='O';
    pos=true;}
    else if(array[rows-1][cols-1]==array[1][1]&&array[1][1]!=array[2][0]&&game[1][1]!='X'&&game[1][1]!='O')
    { game[1][1]='O';
      pos=true;}
    else if(array[rows-1][cols-1]==array[1][2]&&game[1][2]!='X'&&game[1][2]!='O')
    { game[1][2]='O';
    pos=true;}
    else if(array[rows-1][cols-1]==array[2][0]&&array[2][0]!=array[1][2]&&game[2][0]!='X'&&game[2][0]!='O' )
    {game[2][0]='O';
    pos=true;}
    else if(array[rows-1][cols-1]==array[2][1]&&game[2][1]!='X'&&game[2][1]!='O')
    {  game[2][1]='O';
    pos=true;}
    else if(array[rows-1][cols-1]==array[2][2]&&game[2][2]!='X'&&game[2][2]!='O')
    {game[2][2]='O';
    pos=true;}
    //Conditionally executes if that space is already taken
    else
        cout<<"not valid. That space is taken. Try again"<<endl;
    //Loops as long as boolean is false
    }while(pos==false);
}