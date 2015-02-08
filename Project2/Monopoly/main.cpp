/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 28, 2015, 7:45 PM
 * Purpose: Project 1
 *          Monopoly
 */
// System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

const int COL=7;                                                               //Global constant for columns
//Function Prototype
int rollDie(string [], char [][7],int&,int&, int,int *);                        //Function prototype for rolling die
void purp1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);      //Function prototype for Mediterranean Avenue
void  purp2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for Baltic Avenue
void teal1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for Oriental_Ave
void  teal2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for Vermont_Ave
void  teal3(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for Conneticut Ave
void  pink1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for ST Charles Place
void  pink2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for States Ave
void  pink3(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for Virginia Ave
void  orange1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);     //Function prototype for St James Place
void  orange2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);     //Function prototype for Tennesse Ave
void  orange3(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);     //Function prototype for New York Ave
void red1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);        //Function prototype for Kentucky Ave
void red2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);        //Function prototype for Indiana Ave
void  red3(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);        //Function prototype for Illinois Ave
void yellow1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);     //Function prototype for Atlantic Ave
void yellow2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);     //Function prototype for Ventnor Ave
void  yellow3(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);     //Function prototype for Marvin Gardens Ave
void  green1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);      //Function prototype for Pacific Ave 
void  green2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);      //Function prototype for North Carolina Ave
void green3(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);      //Function prototype for Pennsylvania Ave
void  blue1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for Park Place Ave
void  blue2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);       //Function prototype for Boardwalk Ave
void  start();                                                                    //Function prototype Start
int chance(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool,int &,int &,int); //Function prototype for Chance
int comChest(string[], char[][7],char[][7], int&,int&,int);                     //Function prototype for Community Chest
int incTax(string[],int&,int&,bool);                                            //Function prototype for Income Tax
int luxTax(string[],  int&,int&,bool);                                          //Function prototype for Luxury tax
int jail(string[], char[][7],char[][7], int&,int&,int);                         //Function prototype for Jail
int goToJail(string[], char[][7],char[][7], int&,int&,int);                     //Function prototype for Go to Jail
void  rr1(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);         //Function prototype for Reading Railroad
void  rr2(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);         //Function prototype for Pennsylvania Railroad
void  rr3(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);         //Function prototype for B&O Railroad
void  rr4(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);         //Function prototype for Shortline Railroad
void  elecCom(string[], char[][COL],char[][COL], int&,int&,bool,int);             //Function prototype for Electric Company
void  watWork(string[], char[][COL], char[][COL],int&,int&,bool,int);             //Function prototype for Water works
int frePark(string[]);                                                          //Function prototype for Free parking
int menu(string[], int[][COL],char[][COL],char[][COL], int&,int&, bool);        //Function Protoptype for house menu.



//Execution Begins Here!

int main()
{
    //Declare variables
    const int row=40;                           //Defines row
    string prop[row];                           //Array that holds property names
   char playr1[row][COL];                       //2D Array for Player 1 property purchases
   char playr2[row][COL];                       //2D Array for Player 2 property purchases
    int bank1=2000;                             //Holds bank account balance for player 1
    int bank2=2000;                             //Holds bank account balance for player 2
    int player1=0;                              //Holds dice roll total for player1
    int player2=0;                              //Holds dice roll total for player2
    int rent[row][COL];                         //2D Array that holds properties various rent fees
    int count=0;                                //Counter
    char ch;
    
    //Prompt game time
    cout<<"Welcome to the game of Monopoly where fortunes are won....and Lost"<<endl;
    cout<<"How far will your bank roll take you."<<endl;
    
    //Writes from file property names to  array using while loop
    ifstream inputFile;
    inputFile.open("Properties.txt");
    while(count<40&&inputFile>>prop[count])
    count++;
    //Closes file
    inputFile.close();
    
    //Writes from file the rent rates to 2D Array and uses for loop to write values to each array element
     ifstream inputfile;
    inputfile.open("rent.txt");
    for(int row=0;row<40;row++)   
    {
        for(int cols=0;cols<6;cols++)
            inputfile>>rent[row][cols];
    }
    //Closes file
    inputfile.close();
    
    //Sets a ? char in each position of player 1's 2D dimensional array
    for(int row=0;row<39;row++)
    {
        for(int col=0; col<7;col++)
        { playr1[row][col]='?';}
    }
     //Sets a ? char in each position of player 2's 2D dimensional array
        for(int row=0;row<39;row++)
    {
        for(int col=0; col<7;col++)
        { playr2[row][col]='?';}
    }
       
    
    
    //Loops while bank accounts are not negative
    do
    {
        //Declare variables
        int totDie;                      //Total die roll
        bool turn=false;                //Bool false for player 1's turn
        //Player 1's turn
        if(turn==false)
        {  
          //Prompts player 1 to press any key
          cout<<"Player One it is turn. Press enter to continue."<<endl;
          cin.get(ch);
          //Function call to get dice roll and store it in player 1 dice total
          player1+=rollDie(prop, playr1, bank1,bank2, turn, &totDie);   
          //Outputs player 1's total dice roll
          cout<<"Player 1 "<<player1<<endl;
          
          //Outputs player 1's bank total
          cout<<"bank 1 "<<bank1<<endl;
        
          //Recalibrates player 1's dice roll if its greater than 40
          //Outputs the player has passed go and adds 200
          if(player1>39)
        { player1-=39;
          cout<<"Player 1 Passed Go!!Collect $200!!"<<endl;
          cout<<"Player 1  "<<player1<<endl;
         bank1+=200;}}
        
        //Conditionally executes depending of player 1' total dice roll and the makes 
        //a function call to corresponding property
           if (player1==0)
                  start();
           else if(player1==1)
                 purp1(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==2)
                  comChest(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==3)
                   purp2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==4)
                incTax(prop,bank1,bank2,turn);
            else if(player1==5)
                rr1(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==6)
                teal1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player1==7)
                chance(prop,rent,playr1,playr2,bank1,bank2,turn,player1,player2,totDie);
             else if(player1==8)
                teal2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==9)
                teal3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==10)
                jail(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==11)
                pink1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player1==12)
                elecCom(prop, playr1,playr2,bank1,bank2,turn,totDie);
            else if(player1==13)
                pink2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==14)
                pink3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==15)
                rr2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==16)
                orange1(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==17)
                comChest(prop,playr1,playr2,bank1,bank2,turn);
            else if(player1==18)
                orange2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==19)
                orange3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==20)
                frePark(prop);
            else if(player1==21)
                red1(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==22)
                chance(prop,rent,playr1,playr2,bank1,bank2,turn,player1,player2,totDie);
            else if(player1==23)
                red2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==24)
                red3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==25)
                rr3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==26)
                yellow1(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==27)
               yellow2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==28)
                watWork(prop, playr1,playr2,bank1,bank2,turn,totDie);
            else if(player1==29)
                yellow3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==30)
                goToJail(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==31)
                green1(prop, rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==32)
                green2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==33)
                comChest(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==34)
                green3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==35)
               rr4(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==36)
               chance(prop,rent,playr1,playr2,bank1,bank2,turn,player1,player2,totDie);
            else if(player1==37)
               blue1(prop,rent, playr1,playr2,bank1,bank2,turn);
           else if(player1==38)
                luxTax(prop,bank1,bank2,turn);
           else if(player1==39)
               blue2(prop,rent, playr1,playr2,bank1,bank2,turn);
           else
             cout<<"ERROR. Somthing Went Wrong!!!"<<endl;
        
           menu(prop,rent, playr1,playr2,bank1,bank2,turn);
           //Bool switch to true to indicate its player 2's turn
           turn=true;
    //Player 2
    if(turn=true)
        {   
            //Prompts Player 2 to press any key
            cout<<"Player Two it is your turn. Press Enter to continue"<<endl;
            cin.get(ch);
            //Function call to get dice total and store it in player 2 total
            //dice roll
            player2+=rollDie(prop, playr2,bank1,bank2, turn,&totDie);
           
            //Outputs player 2's total dice roll
            cout<<"Player 2 "<<player2<<endl;
          //Outpurs player 2's total bank
           cout<<"Bank 2 "<<bank2<<endl;
           
      //Recalibrates player 2's dice roll if its greater than 40
      //Outputs the player has passed go and adds 200     
      if(player2>39)
        {player2-=39;
        cout<<"Player 2 Passed Go!!Collect $200!!"<<endl;
         cout<<"Player 2  "<<player2<<endl; 
        bank2+=200;}}
            //Conditionally executes depending of player 2' total dice roll and the makes 
            //a function call to corresponding property
            if (player2==0)
                start();
            else if(player2==1)
                  purp1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==2)
                  comChest(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==3)
                  purp2(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==4)
                incTax(prop,bank1,bank2,turn);
            else if(player2==5)
                rr1(prop,rent,playr1, playr2,bank1,bank2,turn);
            else if(player2==6)
                teal1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==7)
                chance(prop,rent,playr1,playr2,bank1,bank2,turn,player1,player2,totDie);
            else if(player2==8)
                teal2(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==9)
                teal3(prop,rent,playr1, playr2,bank1,bank2,turn);
            else if(player2==10)
                jail(prop,playr1, playr2,bank1,bank2,turn);
            else if(player2==11)
                pink1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==12)
                elecCom(prop,playr1,playr2,bank1,bank2,turn,totDie);
            else if(player2==13)
                pink2(prop,rent,playr1, playr2,bank1,bank2,turn);
            else if(player2==14)
                pink3(prop,rent,playr1, playr2,bank1,bank2,turn);
            else if(player2==15)
                rr2(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==16)
                orange1(prop, rent, playr1,playr2,bank1,bank2,turn);
            else if(player2==17)
                comChest(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==18)
                orange2(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==19)
                orange3(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==20)
                frePark(prop);
            else if(player2==21)
                red1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==22)
                chance(prop,rent,playr1,playr2,bank1,bank2,turn,player1,player2,totDie);
            else if(player2==23)
                red2(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==24)
                red3(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==25)
                rr3(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==26)
                yellow1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==27)
               yellow2(prop,rent, playr1, playr2,bank1,bank2,turn);
            else if(player2==28)
                watWork(prop,playr1,playr2,bank1,bank2,turn,totDie);
            else if(player2==29)
                yellow3(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==30)
                goToJail(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==31)
                green1(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player2==32)
                green2(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==33)
                comChest(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==34)
                green3(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==35)
               rr4(prop,rent,playr1, playr2,bank1,bank2,turn);
            else if(player2==36)
               chance(prop,rent,playr1,playr2,bank1,bank2,turn,player1,player2,totDie);
            else if(player2==37)
               blue1(prop,rent,playr1,playr2,bank1,bank2,turn);
           else if(player2==38)
                luxTax(prop,bank1,bank2,turn);
           else if(player2==39)
               blue2(prop,rent,playr1, playr2,bank1,bank2,turn);
           else
               cout<<"ERROR. Somthing Went Wrong!!!"<<endl;
           menu(prop,rent, playr1,playr2,bank1,bank2,turn);
    }while(bank1>0||bank2>0);
    if(bank1<0)
        cout<<"Player 1 Loses. Player 2 Wins "<<endl;
    else
    cout<<"Player 2 Loses. Player 1 Wins "<<endl;
    return 0;
}
//RollDie Function
int rollDie(string prop [], char player[][7], int &bank1, int &bank2, int turn,int *totDie)
{
    //Declare variables
    int die1;                                //Holds dice one's value
    int die2;                                //Hold dice two's value
    int sum;                                 //Calculates sum
    int total;                               //Accumululates various dice rolls when doubles are thrown
    unsigned seed=static_cast<int>(time(0)); //seed for random number generator
    srand(seed);                             //Random number generator
   
    //Loops if the dice are the same
    do 
    {
       die1=rand()%6+1;                     //Die one
       die2=rand()%6+1;                     //Die two
       //Calculates sum
       sum=die1+die2;  
    //pointer to totDie   
    *totDie=sum;
    //Conditionally executes when both dies equal each other
    if(die1==die2)
       cout<<"You got doubles!! You get to go again!!"<<endl;
        cout<<"You rolled a "<<die1<<" and "<<die2<<" which equals "<<sum<<endl;
        //returns sum to players total dice roll
        return sum;
        total+=sum;
        
    
    }while(die1==die2);
    
    return total;
}
//Function purp1
void  purp1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                //Bool that indicates the property has not been purchased yet
    int rate=60;                          //Cost of property
    char choice;                          //Players choice to buy property

    //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[1]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[1][0]='b';
            cout<<"Player 1 Bought "<<prop[1]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[1][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b'&&playr2[1][3]=='b'&&playr2[1][4]=='b'&&playr2[1][5]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 1 is charged $60"<<endl;
    bank1-=rent[1][5];
    bank2+=rent[1][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b'&&playr2[1][3]=='b'&&playr2[1][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 1 is charged $60"<<endl;
    bank1-=rent[1][4];
    bank2+=rent[1][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b'&&playr2[1][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[1]<<" Player 1 is charged $90"<<endl;
    bank1-=rent[1][3];
    bank2+=rent[1][3];}
     //Player 2 has 2 house
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[1]<<" Player 1 is charged $30"<<endl;
    bank1-=rent[1][2];
    bank2+=rent[1][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[1]<<" Player 1 is charged $10"<<endl;
    bank1-=rent[1][1];
    bank2+=rent[1][1];}
    
    else if(turn==false&&buy==true&&playr2[1][0]=='b')
    { cout<<"Your opponent owns "<<prop[1]<< " Player 1 is charged $2"<<endl;
    bank1-=rent[1][0];
    bank2+=rent[1][0];}
    
    else
        cout<<""<<endl;
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[1][0]='b';
            cout<<"Player 2 Bought "<<prop[1]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[1][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b'&&playr1[1][3]=='b'&&playr1[1][4]=='b'&&playr1[1][5]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 2 is charged $60"<<endl;
    bank2-=rent[1][5];
    bank1+=rent[1][5];}
       //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b'&&playr1[1][3]=='b'&&playr1[1][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 2 is charged $60"<<endl;
    bank2-=rent[1][4];
    bank1+=rent[1][4];}
       //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b'&&playr1[1][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[1]<<" Player 2 is charged $90"<<endl;
    bank2-=rent[1][3];
    bank1+=rent[1][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[1]<<" Player 2 is charged $30"<<endl;
    bank2-=rent[1][2];
    bank1+=rent[1][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[1]<<" Player 2 is charged $10"<<endl;
    bank2-=rent[1][1];
    bank1+=rent[1][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[1][0]=='b')
    { cout<<"Your opponent owns "<<prop[1]<< " Player 2 is charged $2"<<endl;
    bank2-=rent[1][0];
    bank1+=rent[1][0];}
    else
        cout<<""<<endl;
}
void  purp2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{    static bool buy=false;                   //Bool that indicates the property has not been purchased yet
    int rate=60;                              //Cost of property
    char choice;                              //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[3]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[3][0];
            cout<<"Player 1 Bought "<<prop[3]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[3][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b'&&playr2[3][3]=='b'&&playr2[3][4]=='b'&&playr2[3][5]=='b')
    { cout<<"Your opponent has a hotel on this "<<prop[3]<<" Player 1 is charged $460"<<endl;
    bank1-=rent[3][5];
    bank2+=rent[3][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b'&&playr2[3][3]=='b'&&playr2[3][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[3]<<" Player 1 is charged $320"<<endl;
    bank1-=rent[3][4];
    bank2+=rent[3][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b'&&playr2[3][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[3]<<" Player 1 is charged $180"<<endl;
    bank1-=rent[3][3];
    bank2+=rent[3][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[3]<<" Player 1 is charged $60"<<endl;
    bank1-=rent[3][2];
    bank2+=rent[3][2];}
     //Player 2 has 4 house 1
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[3]<<" Player 1 is charged $20"<<endl;
    bank1-=rent[3][2];
    bank2+=rent[3][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[3][0]=='b')
    { cout<<"Your opponent owns "<<prop[3]<< " Player 1 is charged $2"<<endl;
    bank1-=rent[3][0];
    bank2+=rent[3][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[3][0]='b';
            cout<<"Player 2 Bought "<<prop[3]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[3][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel 
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b'&&playr1[3][3]=='b'&&playr1[3][4]=='b'&&playr1[3][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[3]<<" Player 2 is charged $450"<<endl;
    bank2-=rent[3][5];
    bank1+=rent[3][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b'&&playr1[3][3]=='b'&&playr1[3][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[3]<<" Player 2 is charged $320"<<endl;
    bank2-=rent[3][4];
    bank1+=rent[3][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b'&&playr1[3][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[3]<<" Player 2 is charged $180"<<endl;
    bank2-=rent[3][3];
    bank1+=rent[3][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[3]<<" Player 2 is charged $60"<<endl;
    bank2-=rent[3][2];
    bank1+=rent[3][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[3]<<" Player 2 is charged $20"<<endl;
    bank2-=rent[3][1];
    bank1+=rent[3][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[3][0]=='b')
    { cout<<"Your opponent owns "<<prop[3]<< " Player 2 is charged $2"<<endl;
    bank2-=rent[3][0];;
    bank1+=rent[3][0];;}
    else
        cout<<""<<endl;
    
}
void  teal1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{   static bool buy=false;                         //Bool that indicates the property has not been purchased yet
    int rate=100;                                  //Cost of property
    char choice;                                   //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[6]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
    
        bank1-=rate;
            playr1[6][0]='b';
            cout<<"Player 1 Bought "<<prop[6]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[6][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b'&&playr2[6][3]=='b'&&playr2[6][4]=='b'&&playr2[6][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[6]<<" Player 1 is charged $"<<rent[6][5]<<endl;
    bank1-=rent[6][5];
    bank2+=rent[6][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b'&&playr2[6][3]=='b'&&playr2[6][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[6]<<" Player 1 is charged "<<rent[6][4]<<endl;
    bank1-=rent[6][4];
    bank2+=rent[6][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b'&&playr2[6][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[6]<<" Player 1 is charged $"<<rent[6][3]<<endl;
    bank1-=rent[6][3];
    bank2+=rent[6][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[6]<<" Player 1 is charged $"<<rent[6][2]<<endl;
    bank1-=rent[6][2];
    bank2+=rent[6][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[6]<<" Player 1 is charged $"<<rent[6][1]<<endl;
    bank1-=rent[6][1];
    bank2+=rent[6][1];}
    //regulAR rent
    else if(turn==false&&buy==true&&playr2[3][0]=='b')
    { cout<<"Your opponent owns "<<prop[3]<< " Player 1 is charged $"<<rent[6][0]<<endl;
    bank1-=rent[6][0];
    bank2+=rent[6][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[6][0]='b';
            cout<<"Player 2 Bought "<<prop[6]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[6][0]=='b')      
        cout<<"You already own this property"<<endl;
      //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b'&&playr1[6][3]=='b'&&playr1[6][4]=='b'&&playr1[6][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][5]<<endl;
    bank2-=rent[6][5];
    bank1+=rent[6][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b'&&playr1[6][3]=='b'&&playr1[6][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][4]<<endl;
    bank2-=rent[6][4];
    bank1+=rent[6][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b'&&playr1[6][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][3]<<endl;
    bank2-=rent[6][3];
    bank1+=rent[6][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][2]<<endl;
    bank2-=rent[6][2];
    bank1+=rent[6][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][1]<<endl;
    bank2-=rent[6][1];
    bank1+=rent[6][1];}
    //regular rent
    
    else if(turn==true&&buy==true&&playr1[6][0]=='b')
    { cout<<"Your opponent owns "<<prop[6]<< " Player 2 is charged $"<<rent[6][0]<<endl;
    bank2-=rent[6][0];
    bank1+=rent[6][0];}
    else
        cout<<""<<endl;
}
void  teal2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                     //Bool that indicates the property has not been purchased yet
    int rate=100;                              //Cost of property
    char choice;                               //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[7]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[7][0]='b';
            cout<<"Player 1 Bought "<<prop[7]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[7][0]=='b')      
        cout<<"You already own this property"<<endl;
    
     //Player 2 has 4 house and hotel 
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b'&&playr2[7][3]=='b'&&playr2[7][4]=='b'&&playr2[7][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[7]<<" Player 1 is charged $"<<rent[7][5]<<endl;
    bank1-=rent[7][5];
    bank2+=rent[7][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b'&&playr2[7][3]=='b'&&playr2[7][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[7]<<" Player 1 is charged "<<rent[7][4]<<endl;
    bank1-=rent[7][4];
    bank2+=rent[7][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b'&&playr2[7][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[7]<<" Player 1 is charged $"<<rent[7][3]<<endl;
    bank1-=rent[7][3];
    bank2+=rent[7][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[7]<<" Player 1 is charged $"<<rent[7][2]<<endl;
    bank1-=rent[7][2];
    bank2+=rent[7][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[7]<<" Player 1 is charged $"<<rent[7][1]<<endl;
    bank1-=rent[7][1];
    bank2+=rent[7][1];}
    //regular rent
    else if(turn==false&&buy==true&&playr2[7][0]=='b')
    { cout<<"Your opponent owns "<<prop[7]<< " Player 1 is charged $"<<rent[7][0]<<endl;
    bank1-=rent[7][0];
    bank2+=rent[7][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[7][0]='b';
            cout<<"Player 2 Bought "<<prop[7]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[7][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b'&&playr1[7][3]=='b'&&playr1[7][4]=='b'&&playr1[7][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][5]<<endl;
    bank2-=rent[7][5];
    bank1+=rent[7][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b'&&playr1[7][3]=='b'&&playr1[7][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][4]<<endl;
    bank2-=rent[7][4];
    bank1+=rent[7][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b'&&playr1[7][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][3]<<endl;
    bank2-=rent[7][3];
    bank1+=rent[7][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][2]<<endl;
    bank2-=rent[7][2];
    bank1+=rent[7][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[7]<<" Player 2 is charged $"<<rent[6][1]<<endl;
    bank2-=rent[7][1];
    bank1+=rent[7][1];}
    //Regular rent
    
    else if(turn==true&&buy==true&&playr1[7][0]=='b')
    { cout<<"Your opponent owns "<<prop[7]<< " Player 2 is charged $"<<rent[7][0]<<endl;
    bank2-=rent[7][0];
    bank1+=rent[7][0];}
    
    else
        cout<<""<<endl;
   
}
void  teal3(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{    static bool buy=false;                                //Bool that indicates the property has not been purchased yet
    int rate=120;                                          //Cost of property
    char choice;                                           //Players choice to buy property
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[9]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[9][0]='b';
            cout<<"Player 1 Bought "<<prop[9]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[9][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b'&&playr2[9][3]=='b'&&playr2[9][4]=='b'&&playr2[9][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[9]<<" Player 1 is charged $"<<rent[9][5]<<endl;
    bank1-=rent[9][5];
    bank2+=rent[9][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b'&&playr2[9][3]=='b'&&playr2[9][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[9]<<" Player 1 is charged "<<rent[9][4]<<endl;
    bank1-=rent[9][4];
    bank2+=rent[9][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b'&&playr2[9][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][3]<<endl;
    bank1-=rent[9][3];
    bank2+=rent[9][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][2]<<endl;
    bank1-=rent[9][2];
    bank2+=rent[9][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][1]<<endl;
    bank1-=rent[9][1];
    bank2+=rent[9][1];}
    //regular rent
    else if(turn==false&&buy==true&&playr2[9][0]=='b')
    { cout<<"Your opponent owns "<<prop[9]<< " Player 1 is charged $"<<rent[9][0]<<endl;
    bank1-=rent[9][0];
    bank2+=rent[9][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[9][0]='b';
            cout<<"Player 2 Bought "<<prop[9]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[9][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel 
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b'&&playr1[9][3]=='b'&&playr1[9][4]=='b'&&playr1[9][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][5]<<endl;
    bank2-=rent[9][5];
    bank1+=rent[9][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b'&&playr1[9][3]=='b'&&playr1[9][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[9]<<" Player 2 is charged $"<<rent[7][9]<<endl;
    bank2-=rent[9][4];
    bank1+=rent[9][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b'&&playr1[9][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][3]<<endl;
    bank2-=rent[9][3];
    bank1+=rent[9][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][2]<<endl;
    bank2-=rent[9][2];
    bank1+=rent[9][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][1]<<endl;
    bank2-=rent[9][1];
    bank1+=rent[9][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[9][0]=='b')
    { cout<<"Your opponent owns "<<prop[9]<< " Player 2 is charged $"<<rent[9][0]<<endl;
    bank2-=rent[9][0];
    bank1+=rent[9][0];}
    
    else
        cout<<""<<endl;
 
}
void  pink1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                      //Bool that indicates the property has not been purchased yet
    int rate=140;                               //Cost of property
    char choice;                                //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[11]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[11][0]='b';
            cout<<"Player 1 Bought "<<prop[11]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[11][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b'&&playr2[11][3]=='b'&&playr2[11][4]=='b'&&playr2[11][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[11]<<" Player 1 is charged $"<<rent[11][5]<<endl;
    bank1-=rent[11][5];
    bank2+=rent[11][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b'&&playr2[11][3]=='b'&&playr2[11][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[11]<<" Player 1 is charged "<<rent[11][4]<<endl;
    bank1-=rent[11][4];
    bank2+=rent[11][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b'&&playr2[11][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[11]<<" Player 1 is charged $"<<rent[11][3]<<endl;
    bank1-=rent[11][3];
    bank2+=rent[11][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 1 is charged $"<<rent[11][2]<<endl;
    bank1-=rent[11][2];
    bank2+=rent[11][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][1]<<endl;
    bank1-=rent[11][1];
    bank2+=rent[11][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[9][0]=='b')
    { cout<<"Your opponent owns "<<prop[11]<< " Player 1 is charged $"<<rent[11][0]<<endl;
    bank1-=rent[11][0];
    bank2+=rent[11][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[11][0]='b';
            cout<<"Player 2 Bought "<<prop[11]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[11][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 1 has 4 house and hotel     
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b'&&playr1[11][3]=='b'&&playr1[11][4]=='b'&&playr1[11][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][5]<<endl;
    bank2-=rent[11][5];
    bank1+=rent[11][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b'&&playr1[11][3]=='b'&&playr1[11][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][9]<<endl;
    bank2-=rent[11][4];
    bank1+=rent[11][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b'&&playr1[11][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][3]<<endl;
    bank2-=rent[11][3];
    bank1+=rent[11][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][2]<<endl;
    bank2-=rent[11][2];
    bank1+=rent[11][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][1]<<endl;
    bank2-=rent[11][1];
    bank1+=rent[11][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[11][0]=='b')
    { cout<<"Your opponent owns "<<prop[11]<< " Player 2 is charged $"<<rent[11][0]<<endl;
    bank2-=rent[11][0];
    bank1+=rent[11][0];}
    
    else
        cout<<""<<endl;
    
}
void  pink2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                         //Bool that indicates the property has not been purchased yet
    int rate=140;                                  //Cost of property
    char choice;                                   //Players choice to buy property
  
    //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[13]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[13][0]='b';
            cout<<"Player 1 Bought "<<prop[13]<<endl;}}
            
     
    else if(turn==false&&buy==true&&playr1[13][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b'&&playr2[13][3]=='b'&&playr2[13][4]=='b'&&playr2[13][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[13]<<" Player 1 is charged $"<<rent[13][5]<<endl;
    bank1-=rent[13][5];
    bank2+=rent[13][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b'&&playr2[13][3]=='b'&&playr2[13][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[13]<<" Player 1 is charged "<<rent[13][4]<<endl;
    bank1-=rent[13][4];
    bank2+=rent[13][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b'&&playr2[13][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[13]<<" Player 1 is charged $"<<rent[13][3]<<endl;
    bank1-=rent[13][3];
    bank2+=rent[13][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 1 is charged $"<<rent[13][2]<<endl;
    bank1-=rent[13][2];
    bank2+=rent[13][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[13]<<" Player 1 is charged $"<<rent[13][1]<<endl;
    bank1-=rent[13][1];
    bank2+=rent[13][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[13][0]=='b')
    { cout<<"Your opponent owns "<<prop[13]<< " Player 1 is charged $"<<rent[11][0]<<endl;
    bank1-=rent[13][0];
    bank2+=rent[13][0];}
  else 
        cout<<""<<endl;
    
    //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[13][0]='b';
            cout<<"Player 2 Bought "<<prop[13]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[13][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b'&&playr1[13][3]=='b'&&playr1[13][4]=='b'&&playr1[13][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][5]<<endl;
    bank2-=rent[13][5];
    bank1+=rent[13][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b'&&playr1[13][3]=='b'&&playr1[13][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][9]<<endl;
    bank2-=rent[13][4];
    bank1+=rent[13][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b'&&playr1[13][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][3]<<endl;
    bank2-=rent[13][3];
    bank1+=rent[13][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][2]<<endl;
    bank2-=rent[13][2];
    bank1+=rent[13][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][1]<<endl;
    bank2-=rent[13][1];
    bank1+=rent[13][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[13][0]=='b')
    { cout<<"Your opponent owns "<<prop[13]<< " Player 2 is charged $"<<rent[13][0]<<endl;
    bank2-=rent[13][0];
    bank1+=rent[13][0];}
    
    else
        cout<<""<<endl;
    
}
void  pink3(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{    static bool buy=false;                                   //Bool that indicates the property has not been purchased yet
    int rate=160;                                             //Cost of property
    char choice;                                              //Players choice to buy property
   
    //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[14]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[14][0]='b';
            cout<<"Player 1 Bought "<<prop[14]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[14][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house  and hotel
    else if(turn==false&&buy==true&&playr2[14][0]=='b'&&playr2[14][1]=='b'&&playr2[14][2]=='b'&&playr2[14][3]=='b'&&playr2[14][4]=='b'&&playr2[14][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[14]<<" Player 1 is charged $"<<rent[14][5]<<endl;
    bank1-=rent[14][5];
    bank2+=rent[14][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[14][0]=='b'&&playr2[14][1]=='b'&&playr2[14][2]=='b'&&playr2[14][3]=='b'&&playr2[14][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[14]<<" Player 1 is charged "<<rent[14][4]<<endl;
    bank1-=rent[14][4];
    bank2+=rent[14][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[14][0]=='b'&&playr2[14][1]=='b'&&playr2[14][2]=='b'&&playr2[14][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[14]<<" Player 1 is charged $"<<rent[14][3]<<endl;
    bank1-=rent[14][3];
    bank2+=rent[14][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[14][0]=='b'&&playr2[14][1]=='b'&&playr2[14][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[14]<<" Player 1 is charged $"<<rent[14][2]<<endl;
    bank1-=rent[14][2];
    bank2+=rent[14][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[14][0]=='b'&&playr2[14][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[14]<<" Player 1 is charged $"<<rent[14][1]<<endl;
    bank1-=rent[14][1];
    bank2+=rent[14][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[14][0]=='b')
    { cout<<"Your opponent owns "<<prop[14]<< " Player 1 is charged $"<<rent[14][0]<<endl;
    bank1-=rent[14][0];
    bank2+=rent[14][0];}
  else 
        cout<<""<<endl;
    
    //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[14][0]='b';
            cout<<"Player 2 Bought "<<prop[14]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[14][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel 
    else if(turn==true&&buy==true&&playr1[14][0]=='b'&&playr1[14][1]=='b'&&playr1[14][2]=='b'&&playr1[14][3]=='b'&&playr1[14][4]=='b'&&playr1[14][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[14]<<" Player 2 is charged $"<<rent[14][5]<<endl;
    bank2-=rent[14][5];
    bank1+=rent[14][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[14][0]=='b'&&playr1[14][1]=='b'&&playr1[14][2]=='b'&&playr1[14][3]=='b'&&playr1[14][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[14]<<" Player 2 is charged $"<<rent[14][9]<<endl;
    bank2-=rent[14][4];
    bank1+=rent[14][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[14][0]=='b'&&playr1[14][1]=='b'&&playr1[14][2]=='b'&&playr1[14][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[14]<<" Player 2 is charged $"<<rent[14][3]<<endl;
    bank2-=rent[14][3];
    bank1+=rent[14][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[14][0]=='b'&&playr1[14][1]=='b'&&playr1[14][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 2 is charged $"<<rent[14][2]<<endl;
    bank2-=rent[14][2];
    bank1+=rent[14][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[14][0]=='b'&&playr1[14][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[14]<<" Player 2 is charged $"<<rent[14][1]<<endl;
    bank2-=rent[14][1];
    bank1+=rent[14][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[14][0]=='b')
    { cout<<"Your opponent owns "<<prop[14]<< " Player 2 is charged $"<<rent[14][0]<<endl;
    bank2-=rent[14][0];
    bank1+=rent[14][0];}
    
    else
        cout<<""<<endl;
    
}
void  orange1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{   static bool buy=false;                      //Bool that indicates the property has not been purchased yet
    int rate=180;                                //Cost of property
    char choice;                                 //Players choice to buy property
   
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[16]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[16][0]='b';
            cout<<"Player 1 Bought "<<prop[16]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[16][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[16][0]=='b'&&playr2[16][1]=='b'&&playr2[16][2]=='b'&&playr2[16][3]=='b'&&playr2[16][4]=='b'&&playr2[16][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[16]<<" Player 1 is charged $"<<rent[16][5]<<endl;
    bank1-=rent[16][5];
    bank2+=rent[16][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[16][0]=='b'&&playr2[16][1]=='b'&&playr2[16][2]=='b'&&playr2[16][3]=='b'&&playr2[16][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[16]<<" Player 1 is charged "<<rent[16][4]<<endl;
    bank1-=rent[16][4];
    bank2+=rent[16][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[16][0]=='b'&&playr2[16][1]=='b'&&playr2[16][2]=='b'&&playr2[16][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[16]<<" Player 1 is charged $"<<rent[16][3]<<endl;
    bank1-=rent[16][3];
    bank2+=rent[16][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[16][0]=='b'&&playr2[16][1]=='b'&&playr2[16][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[16]<<" Player 1 is charged $"<<rent[16][2]<<endl;
    bank1-=rent[16][2];
    bank2+=rent[16][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[16][0]=='b'&&playr2[16][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[16]<<" Player 1 is charged $"<<rent[16][1]<<endl;
    bank1-=rent[16][1];
    bank2+=rent[16][1];}
    //regular rent
    
    else if(turn==false&&buy==true&&playr2[14][0]=='b')
    { cout<<"Your opponent owns "<<prop[16]<< " Player 1 is charged $"<<rent[16][0]<<endl;
    bank1-=rent[16][0];
    bank2+=rent[16][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[16][0]='b';
            cout<<"Player 2 Bought "<<prop[16]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[16][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel 
    else if(turn==true&&buy==true&&playr1[16][0]=='b'&&playr1[16][1]=='b'&&playr1[16][2]=='b'&&playr1[16][3]=='b'&&playr1[16][4]=='b'&&playr1[16][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[16]<<" Player 2 is charged $"<<rent[16][5]<<endl;
    bank2-=rent[16][5];
    bank1+=rent[16][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[16][0]=='b'&&playr1[16][1]=='b'&&playr1[16][2]=='b'&&playr1[16][3]=='b'&&playr1[16][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[16]<<" Player 2 is charged $"<<rent[16][9]<<endl;
    bank2-=rent[16][4];
    bank1+=rent[16][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[16][0]=='b'&&playr1[16][1]=='b'&&playr1[16][2]=='b'&&playr1[16][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[16]<<" Player 2 is charged $"<<rent[16][3]<<endl;
    bank2-=rent[16][3];
    bank1+=rent[16][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[16][0]=='b'&&playr1[16][1]=='b'&&playr1[16][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[16]<<" Player 2 is charged $"<<rent[16][2]<<endl;
    bank2-=rent[16][2];
    bank1+=rent[16][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[16][0]=='b'&&playr1[16][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[16]<<" Player 2 is charged $"<<rent[16][1]<<endl;
    bank2-=rent[16][1];
    bank1+=rent[16][1];}
    //regular rent
  
    else if(turn==true&&buy==true&&playr1[16][0]=='b')
    { cout<<"Your opponent owns "<<prop[16]<< " Player 2 is charged $"<<rent[16][0]<<endl;
    bank2-=rent[16][0];
    bank1+=rent[16][0];}
    
    else
        cout<<""<<endl;
    
    
}
void  orange2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                        //Bool that indicates the property has not been purchased yet
    int rate=180;                                 //Cost of property
    char choice;                                  //Players choice to buy property    
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[18]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[18][0]='b';
            cout<<"Player 1 Bought "<<prop[18]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[18][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and Hotel
    else if(turn==false&&buy==true&&playr2[18][0]=='b'&&playr2[18][1]=='b'&&playr2[18][2]=='b'&&playr2[18][3]=='b'&&playr2[18][4]=='b'&&playr2[18][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[18]<<" Player 1 is charged $"<<rent[18][5]<<endl;
    bank1-=rent[18][5];
    bank2+=rent[18][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[18][0]=='b'&&playr2[18][1]=='b'&&playr2[18][2]=='b'&&playr2[18][3]=='b'&&playr2[18][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[18]<<" Player 1 is charged "<<rent[18][4]<<endl;
    bank1-=rent[18][4];
    bank2+=rent[18][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[18][0]=='b'&&playr2[18][1]=='b'&&playr2[18][2]=='b'&&playr2[18][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[18]<<" Player 1 is charged $"<<rent[18][3]<<endl;
    bank1-=rent[18][3];
    bank2+=rent[18][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[18][0]=='b'&&playr2[18][1]=='b'&&playr2[18][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[18]<<" Player 1 is charged $"<<rent[18][2]<<endl;
    bank1-=rent[18][2];
    bank2+=rent[18][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[18][0]=='b'&&playr2[18][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[16]<<" Player 1 is charged $"<<rent[18][1]<<endl;
    bank1-=rent[18][1];
    bank2+=rent[18][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[18][0]=='b')
    { cout<<"Your opponent owns "<<prop[18]<< " Player 1 is charged $"<<rent[18][0]<<endl;
    bank1-=rent[18][0];
    bank2+=rent[18][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[18][0]='b';
            cout<<"Player 2 Bought "<<prop[18]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[18][0]=='b')      
        cout<<"You already own this property"<<endl;
   //Player 1 has 4 house and hotel       
    else if(turn==true&&buy==true&&playr1[18][0]=='b'&&playr1[18][1]=='b'&&playr1[18][2]=='b'&&playr1[18][3]=='b'&&playr1[18][4]=='b'&&playr1[18][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[18]<<" Player 2 is charged $"<<rent[18][5]<<endl;
    bank2-=rent[18][5];
    bank1+=rent[18][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[18][0]=='b'&&playr1[18][1]=='b'&&playr1[18][2]=='b'&&playr1[18][3]=='b'&&playr1[18][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[18]<<" Player 2 is charged $"<<rent[18][9]<<endl;
    bank2-=rent[18][4];
    bank1+=rent[18][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[18][0]=='b'&&playr1[18][1]=='b'&&playr1[18][2]=='b'&&playr1[18][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[18]<<" Player 2 is charged $"<<rent[18][3]<<endl;
    bank2-=rent[18][3];
    bank1+=rent[18][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[18][0]=='b'&&playr1[18][1]=='b'&&playr1[18][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[18]<<" Player 2 is charged $"<<rent[18][2]<<endl;
    bank2-=rent[18][2];
    bank1+=rent[18][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[18][0]=='b'&&playr1[18][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[18]<<" Player 2 is charged $"<<rent[18][1]<<endl;
    bank2-=rent[18][1];
    bank1+=rent[18][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[18][0]=='b')
    { cout<<"Your opponent owns "<<prop[18]<< " Player 2 is charged $"<<rent[18][0]<<endl;
    bank2-=rent[18][0];
    bank1+=rent[18][0];}
    
    else
        cout<<""<<endl;
    
}
void  orange3(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{     static bool buy=false;                          //Bool that indicates the property has not been purchased yet
    int rate=200;                                     //Cost of property
    char choice;                                      //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[19]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[19][0]='b';
            cout<<"Player 1 Bought "<<prop[18]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[19][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[19][0]=='b'&&playr2[19][1]=='b'&&playr2[19][2]=='b'&&playr2[19][3]=='b'&&playr2[19][4]=='b'&&playr2[19][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[19]<<" Player 1 is charged $"<<rent[19][5]<<endl;
    bank1-=rent[19][5];
    bank2+=rent[19][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[19][0]=='b'&&playr2[19][1]=='b'&&playr2[19][2]=='b'&&playr2[19][3]=='b'&&playr2[19][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[19]<<" Player 1 is charged "<<rent[19][4]<<endl;
    bank1-=rent[19][4];
    bank2+=rent[19][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[19][0]=='b'&&playr2[19][1]=='b'&&playr2[19][2]=='b'&&playr2[19][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[19]<<" Player 1 is charged $"<<rent[19][3]<<endl;
    bank1-=rent[19][3];
    bank2+=rent[19][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[19][0]=='b'&&playr2[19][1]=='b'&&playr2[19][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[19]<<" Player 1 is charged $"<<rent[19][2]<<endl;
    bank1-=rent[19][2];
    bank2+=rent[19][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[19][0]=='b'&&playr2[19][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[16]<<" Player 1 is charged $"<<rent[18][1]<<endl;
    bank1-=rent[19][1];
    bank2+=rent[19][1];}
   //regular rent    
    else if(turn==false&&buy==true&&playr2[19][0]=='b')
    { cout<<"Your opponent owns "<<prop[19]<< " Player 1 is charged $"<<rent[19][0]<<endl;
    bank1-=rent[19][0];
    bank2+=rent[19][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[19][0]='b';
            cout<<"Player 2 Bought "<<prop[19]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[19][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[19][0]=='b'&&playr1[19][1]=='b'&&playr1[19][2]=='b'&&playr1[19][3]=='b'&&playr1[19][4]=='b'&&playr1[19][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[19]<<" Player 2 is charged $"<<rent[19][5]<<endl;
    bank2-=rent[19][5];
    bank1+=rent[19][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[19][0]=='b'&&playr1[19][1]=='b'&&playr1[19][2]=='b'&&playr1[19][3]=='b'&&playr1[19][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[19]<<" Player 2 is charged $"<<rent[19][9]<<endl;
    bank2-=rent[19][4];
    bank1+=rent[19][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[19][0]=='b'&&playr1[19][1]=='b'&&playr1[19][2]=='b'&&playr1[19][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[19]<<" Player 2 is charged $"<<rent[19][3]<<endl;
    bank2-=rent[19][3];
    bank1+=rent[19][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[19][0]=='b'&&playr1[19][1]=='b'&&playr1[19][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[19]<<" Player 2 is charged $"<<rent[19][2]<<endl;
    bank2-=rent[19][2];
    bank1+=rent[19][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[19][0]=='b'&&playr1[19][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[19]<<" Player 2 is charged $"<<rent[19][1]<<endl;
    bank2-=rent[19][1];
    bank1+=rent[19][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[19][0]=='b')
    { cout<<"Your opponent owns "<<prop[19]<< " Player 2 is charged $"<<rent[19][0]<<endl;
    bank2-=rent[19][0];
    bank1+=rent[19][0];}
    
    else
        cout<<""<<endl;
    
}
void  red1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
     static bool buy=false;                                 //Bool that indicates the property has not been purchased yet
    int rate=220;                                          //Cost of property
    char choice;                                            //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[21]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[21][0]='b';
            cout<<"Player 1 Bought "<<prop[21]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[21][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[21][0]=='b'&&playr2[21][1]=='b'&&playr2[21][2]=='b'&&playr2[21][3]=='b'&&playr2[21][4]=='b'&&playr2[21][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[21]<<" Player 1 is charged $"<<rent[21][5]<<endl;
    bank1-=rent[21][5];
    bank2+=rent[21][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[21][0]=='b'&&playr2[21][1]=='b'&&playr2[21][2]=='b'&&playr2[21][3]=='b'&&playr2[21][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[21]<<" Player 1 is charged "<<rent[21][4]<<endl;
    bank1-=rent[21][4];
    bank2+=rent[21][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[21][0]=='b'&&playr2[21][1]=='b'&&playr2[21][2]=='b'&&playr2[21][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[21]<<" Player 1 is charged $"<<rent[21][3]<<endl;
    bank1-=rent[21][3];
    bank2+=rent[21][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[21][0]=='b'&&playr2[21][1]=='b'&&playr2[21][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[21]<<" Player 1 is charged $"<<rent[21][2]<<endl;
    bank1-=rent[21][2];
    bank2+=rent[21][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[21][0]=='b'&&playr2[21][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[21]<<" Player 1 is charged $"<<rent[21][1]<<endl;
    bank1-=rent[21][1];
    bank2+=rent[21][1];}
    //regular rent
    else if(turn==false&&buy==true&&playr2[21][0]=='b')
    { cout<<"Your opponent owns "<<prop[21]<< " Player 1 is charged $"<<rent[21][0]<<endl;
    bank1-=rent[21][0];
    bank2+=rent[21][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for "<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[21][0]='b';
            cout<<"Player 2 Bought "<<prop[21]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[21][0]=='b')      
        cout<<"You already own this property"<<endl;
       //Player 1 has 4 house and hotel 
    else if(turn==true&&buy==true&&playr1[21][0]=='b'&&playr1[21][1]=='b'&&playr1[21][2]=='b'&&playr1[21][3]=='b'&&playr1[21][4]=='b'&&playr1[21][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[21]<<" Player 2 is charged $"<<rent[21][5]<<endl;
    bank2-=rent[21][5];
    bank1+=rent[21][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[21][0]=='b'&&playr1[21][1]=='b'&&playr1[21][2]=='b'&&playr1[21][3]=='b'&&playr1[21][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[21]<<" Player 2 is charged $"<<rent[21][9]<<endl;
    bank2-=rent[21][4];
    bank1+=rent[21][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[21][0]=='b'&&playr1[21][1]=='b'&&playr1[21][2]=='b'&&playr1[21][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[21]<<" Player 2 is charged $"<<rent[21][3]<<endl;
    bank2-=rent[21][3];
    bank1+=rent[21][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[21][0]=='b'&&playr1[21][1]=='b'&&playr1[21][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[21]<<" Player 2 is charged $"<<rent[21][2]<<endl;
    bank2-=rent[21][2];
    bank1+=rent[21][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[21][0]=='b'&&playr1[21][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[21]<<" Player 2 is charged $"<<rent[21][1]<<endl;
    bank2-=rent[21][1];
    bank1+=rent[19][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[21][0]=='b')
    { cout<<"Your opponent owns "<<prop[21]<< " Player 2 is charged $"<<rent[21][0]<<endl;
    bank2-=rent[21][0];
    bank1+=rent[21][0];}
    
    else
        cout<<""<<endl;
    
    
}
void  red2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                             //Bool that indicates the property has not been purchased yet
    int rate=220;                                      //Cost of property
    char choice;                                       //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[23]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[23][0]='b';
            cout<<"Player 1 Bought "<<prop[23]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[23][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house  and hotel
    else if(turn==false&&buy==true&&playr2[23][0]=='b'&&playr2[23][1]=='b'&&playr2[23][2]=='b'&&playr2[23][3]=='b'&&playr2[23][4]=='b'&&playr2[23][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[23]<<" Player 1 is charged $"<<rent[23][5]<<endl;
    bank1-=rent[23][5];
    bank2+=rent[23][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[23][0]=='b'&&playr2[23][1]=='b'&&playr2[21][2]=='b'&&playr2[21][3]=='b'&&playr2[21][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[23]<<" Player 1 is charged "<<rent[23][4]<<endl;
    bank1-=rent[23][4];
    bank2+=rent[23][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[23][0]=='b'&&playr2[23][1]=='b'&&playr2[23][2]=='b'&&playr2[23][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[23]<<" Player 1 is charged $"<<rent[23][3]<<endl;
    bank1-=rent[23][3];
    bank2+=rent[23][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[23][0]=='b'&&playr2[23][1]=='b'&&playr2[23][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[23]<<" Player 1 is charged $"<<rent[23][2]<<endl;
    bank1-=rent[23][2];
    bank2+=rent[23][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[23][0]=='b'&&playr2[23][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[23]<<" Player 1 is charged $"<<rent[23][1]<<endl;
    bank1-=rent[23][1];
    bank2+=rent[23][1];}
    //regular rent
    else if(turn==false&&buy==true&&playr2[23][0]=='b')
    { cout<<"Your opponent owns "<<prop[23]<< " Player 1 is charged $"<<rent[23][0]<<endl;
    bank1-=rent[23][0];
    bank2+=rent[23][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[23][0]='b';
            cout<<"Player 2 Bought "<<prop[23]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[23][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[23][0]=='b'&&playr1[23][1]=='b'&&playr1[23][2]=='b'&&playr1[23][3]=='b'&&playr1[23][4]=='b'&&playr1[23][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[23]<<" Player 2 is charged $"<<rent[23][5]<<endl;
    bank2-=rent[23][5];
    bank1+=rent[23][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[23][0]=='b'&&playr1[23][1]=='b'&&playr1[23][2]=='b'&&playr1[23][3]=='b'&&playr1[23][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[23]<<" Player 2 is charged $"<<rent[23][9]<<endl;
    bank2-=rent[23][4];
    bank1+=rent[23][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[23][0]=='b'&&playr1[23][1]=='b'&&playr1[23][2]=='b'&&playr1[23][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[23]<<" Player 2 is charged $"<<rent[23][3]<<endl;
    bank2-=rent[23][3];
    bank1+=rent[23][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[23][0]=='b'&&playr1[23][1]=='b'&&playr1[23][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[23]<<" Player 2 is charged $"<<rent[23][2]<<endl;
    bank2-=rent[23][2];
    bank1+=rent[23][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[23][0]=='b'&&playr1[23][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[23]<<" Player 2 is charged $"<<rent[23][1]<<endl;
    bank2-=rent[23][1];
    bank1+=rent[23][1];}
    //regular rent
    else if(turn==true&&buy==true&&playr1[23][0]=='b')
    { cout<<"Your opponent owns "<<prop[23]<< " Player 2 is charged $"<<rent[23][0]<<endl;
    bank2-=rent[23][0];
    bank1+=rent[23][0];}
    
    else
        cout<<""<<endl;
    
    
}
void red3(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                             //Bool that indicates the property has not been purchased yet
    int rate=240;                                      //Cost of property
    char choice;                                       //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[24]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[24][0]='b';
            cout<<"Player 1 Bought "<<prop[24]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[24][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[24][0]=='b'&&playr2[24][1]=='b'&&playr2[24][2]=='b'&&playr2[24][3]=='b'&&playr2[24][4]=='b'&&playr2[23][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[24]<<" Player 1 is charged $"<<rent[24][5]<<endl;
    bank1-=rent[24][5];
    bank2+=rent[24][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[24][0]=='b'&&playr2[24][1]=='b'&&playr2[24][2]=='b'&&playr2[24][3]=='b'&&playr2[24][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[24]<<" Player 1 is charged "<<rent[24][4]<<endl;
    bank1-=rent[24][4];
    bank2+=rent[24][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[24][0]=='b'&&playr2[24][1]=='b'&&playr2[24][2]=='b'&&playr2[24][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[24]<<" Player 1 is charged $"<<rent[24][3]<<endl;
    bank1-=rent[24][3];
    bank2+=rent[24][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[24][0]=='b'&&playr2[24][1]=='b'&&playr2[24][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[24]<<" Player 1 is charged $"<<rent[24][2]<<endl;
    bank1-=rent[24][2];
    bank2+=rent[24][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[24][0]=='b'&&playr2[24][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[24]<<" Player 1 is charged $"<<rent[24][1]<<endl;
    bank1-=rent[24][1];
    bank2+=rent[24][1];}
    //regular rent
    else if(turn==false&&buy==true&&playr2[24][0]=='b')
    { cout<<"Your opponent owns "<<prop[24]<< " Player 1 is charged $"<<rent[24][0]<<endl;
    bank1-=rent[24][0];
    bank2+=rent[24][0];}
  else 
        cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[24][0]='b';
            cout<<"Player 2 Bought "<<prop[24]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[24][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[24][0]=='b'&&playr1[24][1]=='b'&&playr1[24][2]=='b'&&playr1[24][3]=='b'&&playr1[24][4]=='b'&&playr1[24][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[24]<<" Player 2 is charged $"<<rent[24][5]<<endl;
    bank2-=rent[24][5];
    bank1+=rent[24][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[24][0]=='b'&&playr1[24][1]=='b'&&playr1[24][2]=='b'&&playr1[24][3]=='b'&&playr1[24][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[24]<<" Player 2 is charged $"<<rent[24][9]<<endl;
    bank2-=rent[24][4];
    bank1+=rent[24][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[24][0]=='b'&&playr1[24][1]=='b'&&playr1[24][2]=='b'&&playr1[24][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[23]<<" Player 2 is charged $"<<rent[23][3]<<endl;
    bank2-=rent[24][3];
    bank1+=rent[24][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[24][0]=='b'&&playr1[24][1]=='b'&&playr1[24][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[24]<<" Player 2 is charged $"<<rent[24][2]<<endl;
    bank2-=rent[24][2];
    bank1+=rent[24][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[24][0]=='b'&&playr1[24][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[24]<<" Player 2 is charged $"<<rent[24][1]<<endl;
    bank2-=rent[24][1];
    bank1+=rent[24][1];}
    //regular rent
    
    else if(turn==true&&buy==true&&playr1[24][0]=='b')
    { cout<<"Your opponent owns "<<prop[24]<< " Player 2 is charged $"<<rent[24][0]<<endl;
    bank2-=rent[24][0];
    bank1+=rent[24][0];}
    
    else
        cout<<""<<endl;
    
    
}
void yellow1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{   static bool buy=false;                               //Bool that indicates the property has not been purchased yet
    int rate=260;                                        //Cost of property
    char choice;                                         //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[26]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[26][0]='b';
            cout<<"Player 1 Bought "<<prop[26]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[26][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[26][0]=='b'&&playr2[26][1]=='b'&&playr2[26][2]=='b'&&playr2[26][3]=='b'&&playr2[26][4]=='b'&&playr2[26][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[26]<<" Player 1 is charged $"<<rent[26][5]<<endl;
    bank1-=rent[26][5];
    bank2+=rent[26][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[26][0]=='b'&&playr2[26][1]=='b'&&playr2[26][2]=='b'&&playr2[26][3]=='b'&&playr2[26][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[26]<<" Player 1 is charged "<<rent[26][4]<<endl;
    bank1-=rent[26][4];
    bank2+=rent[26][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[26][0]=='b'&&playr2[26][1]=='b'&&playr2[26][2]=='b'&&playr2[26][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[26]<<" Player 1 is charged $"<<rent[26][3]<<endl;
    bank1-=rent[26][3];
    bank2+=rent[26][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[26][0]=='b'&&playr2[26][1]=='b'&&playr2[26][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[26]<<" Player 1 is charged $"<<rent[26][2]<<endl;
    bank1-=rent[26][2];
    bank2+=rent[26][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[26][0]=='b'&&playr2[26][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[26]<<" Player 1 is charged $"<<rent[26][1]<<endl;
    bank1-=rent[26][1];
    bank2+=rent[26][1];}
    //regular rent
    
    else if(turn==false&&buy==true&&playr2[26][0]=='b')
    { cout<<"Your opponent owns "<<prop[26]<< " Player 1 is charged $"<<rent[26][0]<<endl;
    bank1-=rent[26][0];
    bank2+=rent[26][0];}
  else 
        cout<<""<<endl;
    
    
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<< "Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[26][0]='b';
            cout<<"Player 2 Bought "<<prop[26]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[26][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[26][0]=='b'&&playr1[26][1]=='b'&&playr1[26][2]=='b'&&playr1[26][3]=='b'&&playr1[26][4]=='b'&&playr1[26][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[26]<<" Player 2 is charged $"<<rent[26][5]<<endl;
    bank2-=rent[26][5];
    bank1+=rent[26][5];}
     //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[26][0]=='b'&&playr1[26][1]=='b'&&playr1[26][2]=='b'&&playr1[26][3]=='b'&&playr1[26][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[26]<<" Player 2 is charged $"<<rent[26][9]<<endl;
    bank2-=rent[26][4];
    bank1+=rent[26][4];}
     //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[26][0]=='b'&&playr1[26][1]=='b'&&playr1[26][2]=='b'&&playr1[26][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[26]<<" Player 2 is charged $"<<rent[26][3]<<endl;
    bank2-=rent[26][3];
    bank1+=rent[26][3];}
     //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[26][0]=='b'&&playr1[26][1]=='b'&&playr1[26][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[26]<<" Player 2 is charged $"<<rent[26][2]<<endl;
    bank2-=rent[26][2];
    bank1+=rent[26][2];}
     //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[26][0]=='b'&&playr1[26][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[26]<<" Player 2 is charged $"<<rent[26][1]<<endl;
    bank2-=rent[26][1];
    bank1+=rent[26][1];}
    //regular rent
    else if(turn==true&&buy==true&&playr1[26][0]=='b')
    { cout<<"Your opponent owns "<<prop[26]<< " Player 2 is charged $"<<rent[26][0]<<endl;
    bank2-=rent[26][0];
    bank1+=rent[26][0];}
    
    else
        cout<<""<<endl;
    
}

void yellow2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{   static bool buy=false;                    //Bool that indicates the property has not been purchased yet
    int rate=260;                             //Cost of property
    char choice;                              //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[27]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[27][0]='b';
            cout<<"Player 1 Bought "<<prop[27]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[27][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[27][0]=='b'&&playr2[27][1]=='b'&&playr2[27][2]=='b'&&playr2[27][3]=='b'&&playr2[27][4]=='b'&&playr2[27][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[27]<<" Player 1 is charged $"<<rent[27][5]<<endl;
    bank1-=rent[27][5];
    bank2+=rent[27][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[27][0]=='b'&&playr2[27][1]=='b'&&playr2[27][2]=='b'&&playr2[27][3]=='b'&&playr2[27][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[27]<<" Player 1 is charged "<<rent[27][4]<<endl;
    bank1-=rent[27][4];
    bank2+=rent[27][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[27][0]=='b'&&playr2[27][1]=='b'&&playr2[27][2]=='b'&&playr2[27][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[27]<<" Player 1 is charged $"<<rent[27][3]<<endl;
    bank1-=rent[27][3];
    bank2+=rent[27][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[27][0]=='b'&&playr2[27][1]=='b'&&playr2[27][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[27]<<" Player 1 is charged $"<<rent[27][2]<<endl;
    bank1-=rent[27][2];
    bank2+=rent[27][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[27][0]=='b'&&playr2[27][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[27]<<" Player 1 is charged $"<<rent[27][1]<<endl;
    bank1-=rent[27][1];
    bank2+=rent[27][1];}
    //regular rent
    else if(turn==false&&buy==true&&playr2[27][0]=='b')
    { cout<<"Your opponent owns "<<prop[27]<< " Player 1 is charged $"<<rent[27][0]<<endl;
    bank1-=rent[27][0];
    bank2+=rent[27][0];}
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[27][0]='b';
            cout<<"Player 2 Bought "<<prop[27]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[27][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[27][0]=='b'&&playr1[27][1]=='b'&&playr1[27][2]=='b'&&playr1[27][3]=='b'&&playr1[27][4]=='b'&&playr1[27][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[27]<<" Player 2 is charged $"<<rent[27][5]<<endl;
    bank2-=rent[27][5];
    bank1+=rent[27][5];}
   //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[27][0]=='b'&&playr1[27][1]=='b'&&playr1[27][2]=='b'&&playr1[27][3]=='b'&&playr1[27][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[27]<<" Player 2 is charged $"<<rent[27][9]<<endl;
    bank2-=rent[27][4];
    bank1+=rent[27][4];}
   //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[27][0]=='b'&&playr1[27][1]=='b'&&playr1[27][2]=='b'&&playr1[27][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[27]<<" Player 2 is charged $"<<rent[27][3]<<endl;
    bank2-=rent[27][3];
    bank1+=rent[27][3];}
   //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[27][0]=='b'&&playr1[27][1]=='b'&&playr1[27][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[27]<<" Player 2 is charged $"<<rent[27][2]<<endl;
    bank2-=rent[27][2];
    bank1+=rent[27][2];}
   //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[27][0]=='b'&&playr1[27][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[26]<<" Player 2 is charged $"<<rent[26][1]<<endl;
    bank2-=rent[27][1];
    bank1+=rent[27][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[27][0]=='b')
    { cout<<"Your opponent owns "<<prop[27]<< " Player 2 is charged $"<<rent[27][0]<<endl;
    bank2-=rent[27][0];
    bank1+=rent[27][0];}
    
    else
        cout<<""<<endl;}
    
}
void yellow3(string prop [],int rent[][COL], char playr1[][COL], char playr2[][COL],int &bank1,int &bank2,bool turn)
{
static bool buy=false;                         //Bool that indicates the property has not been purchased yet
    int rate=280;                              //Cost of property
    char choice;                               //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[29]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[29][0]='b';
            cout<<"Player 1 Bought "<<prop[29]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[29][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel 
    else if(turn==false&&buy==true&&playr2[29][0]=='b'&&playr2[29][1]=='b'&&playr2[29][2]=='b'&&playr2[29][3]=='b'&&playr2[29][4]=='b'&&playr2[29][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[29]<<" Player 1 is charged $"<<rent[29][5]<<endl;
    bank1-=rent[29][5];
    bank2+=rent[29][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[29][0]=='b'&&playr2[29][1]=='b'&&playr2[29][2]=='b'&&playr2[29][3]=='b'&&playr2[29][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[29]<<" Player 1 is charged "<<rent[29][4]<<endl;
    bank1-=rent[29][4];
    bank2+=rent[29][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[29][0]=='b'&&playr2[29][1]=='b'&&playr2[29][2]=='b'&&playr2[29][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[29]<<" Player 1 is charged $"<<rent[29][3]<<endl;
    bank1-=rent[29][3];
    bank2+=rent[29][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[29][0]=='b'&&playr2[29][1]=='b'&&playr2[29][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[29]<<" Player 1 is charged $"<<rent[29][2]<<endl;
    bank1-=rent[29][2];
    bank2+=rent[29][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[29][0]=='b'&&playr2[29][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[29]<<" Player 1 is charged $"<<rent[29][1]<<endl;
    bank1-=rent[29][1];
    bank2+=rent[29][1];}
    //regular rent
    
    else if(turn==false&&buy==true&&playr2[29][0]=='b')
    { cout<<"Your opponent owns "<<prop[29]<< " Player 1 is charged $"<<rent[29][0]<<endl;
    bank1-=rent[29][0];
    bank2+=rent[29][0];}
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[29][0]='b';
            cout<<"Player 2 Bought "<<prop[29]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[29][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hoter
    else if(turn==true&&buy==true&&playr1[29][0]=='b'&&playr1[29][1]=='b'&&playr1[29][2]=='b'&&playr1[29][3]=='b'&&playr1[29][4]=='b'&&playr1[29][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[29]<<" Player 2 is charged $"<<rent[29][5]<<endl;
    bank2-=rent[29][5];
    bank1+=rent[29][5];}
   //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[29][0]=='b'&&playr1[29][1]=='b'&&playr1[29][2]=='b'&&playr1[29][3]=='b'&&playr1[29][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[29]<<" Player 2 is charged $"<<rent[29][9]<<endl;
    bank2-=rent[29][4];
    bank1+=rent[29][4];}
   //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[29][0]=='b'&&playr1[29][1]=='b'&&playr1[29][2]=='b'&&playr1[29][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[29]<<" Player 2 is charged $"<<rent[29][3]<<endl;
    bank2-=rent[29][3];
    bank1+=rent[29][3];}
   //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[29][0]=='b'&&playr1[29][1]=='b'&&playr1[29][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[29]<<" Player 2 is charged $"<<rent[29][2]<<endl;
    bank2-=rent[29][2];
    bank1+=rent[29][2];}
     //Player 1 has 1 house }
    else if(turn==true&&buy==true&&playr1[29][0]=='b'&&playr1[29][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[29]<<" Player 2 is charged $"<<rent[29][1]<<endl;
    bank2-=rent[29][1];
    bank1+=rent[29][1];}
    //regular rent
    
    else if(turn==true&&buy==true&&playr1[29][0]=='b')
    { cout<<"Your opponent owns "<<prop[29]<< " Player 2 is charged $"<<rent[29][0]<<endl;
    bank2-=rent[29][0];
    bank1+=rent[29][0];}
    
    else
        cout<<""<<endl;}
        
}
void green1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                                   //Bool that indicates the property has not been purchased yet
    int rate=300;                                            //Cost of property
    char choice;                                             //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[31]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[31][0]='b';
            cout<<"Player 1 Bought "<<prop[31]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[31][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house  and hotel
    else if(turn==false&&buy==true&&playr2[31][0]=='b'&&playr2[31][1]=='b'&&playr2[31][2]=='b'&&playr2[31][3]=='b'&&playr2[31][4]=='b'&&playr2[31][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[31]<<" Player 1 is charged $"<<rent[31][5]<<endl;
    bank1-=rent[31][5];
    bank2+=rent[31][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[31][0]=='b'&&playr2[31][1]=='b'&&playr2[31][2]=='b'&&playr2[31][3]=='b'&&playr2[31][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[31]<<" Player 1 is charged "<<rent[31][4]<<endl;
    bank1-=rent[31][4];
    bank2+=rent[31][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[31][0]=='b'&&playr2[31][1]=='b'&&playr2[31][2]=='b'&&playr2[31][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[31]<<" Player 1 is charged $"<<rent[31][3]<<endl;
    bank1-=rent[31][3];
    bank2+=rent[31][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[31][0]=='b'&&playr2[31][1]=='b'&&playr2[31][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[31]<<" Player 1 is charged $"<<rent[31][2]<<endl;
    bank1-=rent[31][2];
    bank2+=rent[31][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[31][0]=='b'&&playr2[31][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[31]<<" Player 1 is charged $"<<rent[31][1]<<endl;
    bank1-=rent[31][1];
    bank2+=rent[31][1];}
    
    else if(turn==false&&buy==true&&playr2[31][0]=='b')
    { cout<<"Your opponent owns "<<prop[31]<< " Player 1 is charged $"<<rent[31][0]<<endl;
    bank1-=rent[31][0];
    bank2+=rent[31][0];}
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
                
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[31][0]='b';
            cout<<"Player 2 Bought "<<prop[31]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[31][0]=='b')      
        cout<<"You already own this property"<<endl;
      //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[31][0]=='b'&&playr1[31][1]=='b'&&playr1[31][2]=='b'&&playr1[31][3]=='b'&&playr1[31][4]=='b'&&playr1[31][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[31]<<" Player 2 is charged $"<<rent[31][5]<<endl;
    bank2-=rent[31][5];
    bank1+=rent[31][5];}
   //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[31][0]=='b'&&playr1[31][1]=='b'&&playr1[31][2]=='b'&&playr1[31][3]=='b'&&playr1[31][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[31]<<" Player 2 is charged $"<<rent[31][9]<<endl;
    bank2-=rent[31][4];
    bank1+=rent[31][4];}
   //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[31][0]=='b'&&playr1[31][1]=='b'&&playr1[31][2]=='b'&&playr1[31][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[31]<<" Player 2 is charged $"<<rent[31][3]<<endl;
    bank2-=rent[31][3];
    bank1+=rent[31][3];}
   //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[31][0]=='b'&&playr1[31][1]=='b'&&playr1[31][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[31]<<" Player 2 is charged $"<<rent[31][2]<<endl;
    bank2-=rent[31][2];
    bank1+=rent[31][2];}
   //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[31][0]=='b'&&playr1[31][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[31]<<" Player 2 is charged $"<<rent[31][1]<<endl;
    bank2-=rent[31][1];
    bank1+=rent[31][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[31][0]=='b')
    { cout<<"Your opponent owns "<<prop[31]<< " Player 2 is charged $"<<rent[31][0]<<endl;
    bank2-=rent[31][0];
    bank1+=rent[31][0];}
    
    else
        cout<<""<<endl;}
        
}
void green2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                          //Bool that indicates the property has not been purchased yet
    int rate=300;                                   //Cost of property
    char choice;                                    //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[32]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[32][0]='b';
            cout<<"Player 1 Bought "<<prop[32]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[32][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[32][0]=='b'&&playr2[32][1]=='b'&&playr2[32][2]=='b'&&playr2[32][3]=='b'&&playr2[32][4]=='b'&&playr2[32][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[32]<<" Player 1 is charged $"<<rent[32][5]<<endl;
    bank1-=rent[32][5];
    bank2+=rent[32][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[32][0]=='b'&&playr2[32][1]=='b'&&playr2[32][2]=='b'&&playr2[32][3]=='b'&&playr2[32][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[32]<<" Player 1 is charged "<<rent[32][4]<<endl;
    bank1-=rent[32][4];
    bank2+=rent[32][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[32][0]=='b'&&playr2[32][1]=='b'&&playr2[32][2]=='b'&&playr2[32][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[32]<<" Player 1 is charged $"<<rent[32][3]<<endl;
    bank1-=rent[32][3];
    bank2+=rent[32][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[32][0]=='b'&&playr2[32][1]=='b'&&playr2[32][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[32]<<" Player 1 is charged $"<<rent[32][2]<<endl;
    bank1-=rent[32][2];
    bank2+=rent[32][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[32][0]=='b'&&playr2[32][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[32]<<" Player 1 is charged $"<<rent[32][1]<<endl;
    bank1-=rent[32][1];
    bank2+=rent[32][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[32][0]=='b')
    { cout<<"Your opponent owns "<<prop[32]<< " Player 1 is charged $"<<rent[32][0]<<endl;
    bank1-=rent[32][0];
    bank2+=rent[32][0];}
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[32][0]='b';
            cout<<"Player 2 Bought "<<prop[32]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[32][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[32][0]=='b'&&playr1[32][1]=='b'&&playr1[32][2]=='b'&&playr1[32][3]=='b'&&playr1[32][4]=='b'&&playr1[32][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[32]<<" Player 2 is charged $"<<rent[32][5]<<endl;
    bank2-=rent[32][5];
    bank1+=rent[32][5];}
   //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[32][0]=='b'&&playr1[32][1]=='b'&&playr1[32][2]=='b'&&playr1[32][3]=='b'&&playr1[32][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[32]<<" Player 2 is charged $"<<rent[32][9]<<endl;
    bank2-=rent[32][4];
    bank1+=rent[32][4];}
   //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[32][0]=='b'&&playr1[32][1]=='b'&&playr1[32][2]=='b'&&playr1[32][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[32]<<" Player 2 is charged $"<<rent[32][3]<<endl;
    bank2-=rent[32][3];
    bank1+=rent[32][3];}
   //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[32][0]=='b'&&playr1[32][1]=='b'&&playr1[32][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[32]<<" Player 2 is charged $"<<rent[32][2]<<endl;
    bank2-=rent[32][2];
    bank1+=rent[32][2];}
   //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[32][0]=='b'&&playr1[32][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[32]<<" Player 2 is charged $"<<rent[32][1]<<endl;
    bank2-=rent[32][1];
    bank1+=rent[32][1];}
  //Regular rent
    
    else if(turn==true&&buy==true&&playr1[32][0]=='b')
    { cout<<"Your opponent owns "<<prop[32]<< " Player 2 is charged $"<<rent[32][0]<<endl;
    bank2-=rent[32][0];
    bank1+=rent[32][0];}
    
    else
        cout<<""<<endl;}   
}
void green3(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                               //Bool that indicates the property has not been purchased yet
    int rate=320;                                        //Cost of property
    char choice;                                         //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[34]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[34][0]='b';
            cout<<"Player 1 Bought "<<prop[34]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[34][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[34][0]=='b'&&playr2[34][1]=='b'&&playr2[34][2]=='b'&&playr2[34][3]=='b'&&playr2[34][4]=='b'&&playr2[34][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[34]<<" Player 1 is charged $"<<rent[34][5]<<endl;
    bank1-=rent[34][5];
    bank2+=rent[34][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[34][0]=='b'&&playr2[34][1]=='b'&&playr2[34][2]=='b'&&playr2[34][3]=='b'&&playr2[34][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[34]<<" Player 1 is charged "<<rent[34][4]<<endl;
    bank1-=rent[34][4];
    bank2+=rent[34][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[34][0]=='b'&&playr2[34][1]=='b'&&playr2[32][4]=='b'&&playr2[34][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[34]<<" Player 1 is charged $"<<rent[34][3]<<endl;
    bank1-=rent[34][3];
    bank2+=rent[34][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[34][0]=='b'&&playr2[34][1]=='b'&&playr2[34][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[34]<<" Player 1 is charged $"<<rent[34][2]<<endl;
    bank1-=rent[34][2];
    bank2+=rent[34][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[34][0]=='b'&&playr2[34][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[34]<<" Player 1 is charged $"<<rent[34][1]<<endl;
    bank1-=rent[34][1];
    bank2+=rent[34][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[34][0]=='b')
    { cout<<"Your opponent owns "<<prop[34]<< " Player 1 is charged $"<<rent[34][0]<<endl;
    bank1-=rent[34][0];
    bank2+=rent[34][0];}
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[34][0]='b';
            cout<<"Player 2 Bought "<<prop[34]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[34][0]=='b')      
        cout<<"You already own this property"<<endl;
         //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[34][0]=='b'&&playr1[34][1]=='b'&&playr1[34][2]=='b'&&playr1[34][3]=='b'&&playr1[34][4]=='b'&&playr1[34][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[34]<<" Player 2 is charged $"<<rent[34][5]<<endl;
    bank2-=rent[34][5];
    bank1+=rent[34][5];}
   //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[34][0]=='b'&&playr1[34][1]=='b'&&playr1[34][2]=='b'&&playr1[34][3]=='b'&&playr1[34][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[34]<<" Player 2 is charged $"<<rent[34][9]<<endl;
    bank2-=rent[34][4];
    bank1+=rent[34][4];}
   //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[34][0]=='b'&&playr1[34][1]=='b'&&playr1[34][2]=='b'&&playr1[34][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[34]<<" Player 2 is charged $"<<rent[34][3]<<endl;
    bank2-=rent[34][3];
    bank1+=rent[34][3];}
   //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[34][0]=='b'&&playr1[34][1]=='b'&&playr1[34][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[34]<<" Player 2 is charged $"<<rent[34][2]<<endl;
    bank2-=rent[34][2];
    bank1+=rent[34][2];}
   //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[34][0]=='b'&&playr1[34][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[34]<<" Player 2 is charged $"<<rent[34][1]<<endl;
    bank2-=rent[34][1];
    bank1+=rent[34][1];}
    //Regular rent
    else if(turn==true&&buy==true&&playr1[34][0]=='b')
    { cout<<"Your opponent owns "<<prop[34]<< " Player 2 is charged $"<<rent[34][0]<<endl;
    bank2-=rent[34][0];
    bank1+=rent[34][0];}
    
    else
        cout<<""<<endl;}     
}
void blue1(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                                //Bool that indicates the property has not been purchased yet
    int rate=350;                                         //Cost of property
    char choice;                                          //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[37]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[37][0]='b';
            cout<<"Player 1 Bought "<<prop[37]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[37][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[37][0]=='b'&&playr2[37][1]=='b'&&playr2[37][2]=='b'&&playr2[37][3]=='b'&&playr2[37][4]=='b'&&playr2[37][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[37]<<" Player 1 is charged $"<<rent[37][5]<<endl;
    bank1-=rent[37][5];
    bank2+=rent[37][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[37][0]=='b'&&playr2[37][1]=='b'&&playr2[37][2]=='b'&&playr2[37][3]=='b'&&playr2[37][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[37]<<" Player 1 is charged "<<rent[37][4]<<endl;
    bank1-=rent[37][4];
    bank2+=rent[37][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[37][0]=='b'&&playr2[37][1]=='b'&&playr2[37][4]=='b'&&playr2[37][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[37]<<" Player 1 is charged $"<<rent[37][3]<<endl;
    bank1-=rent[37][3];
    bank2+=rent[37][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[37][0]=='b'&&playr2[37][1]=='b'&&playr2[37][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[37]<<" Player 1 is charged $"<<rent[37][2]<<endl;
    bank1-=rent[37][2];
    bank2+=rent[37][2];}
     //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[37][0]=='b'&&playr2[37][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[37]<<" Player 1 is charged $"<<rent[37][1]<<endl;
    bank1-=rent[37][1];
    bank2+=rent[37][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[37][0]=='b')
    { cout<<"Your opponent owns "<<prop[37]<< " Player 1 is charged $"<<rent[37][0]<<endl;
    bank1-=rent[37][0];
    bank2+=rent[37][0];}
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[37][0]='b';
            cout<<"Player 2 Bought "<<prop[37]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[37][0]=='b')      
        cout<<"You already own this property"<<endl;
      //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[37][0]=='b'&&playr1[37][1]=='b'&&playr1[37][2]=='b'&&playr1[37][3]=='b'&&playr1[37][4]=='b'&&playr1[37][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[37]<<" Player 2 is charged $"<<rent[37][5]<<endl;
    bank2-=rent[37][5];
    bank1+=rent[37][5];}
   //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[37][0]=='b'&&playr1[37][1]=='b'&&playr1[37][2]=='b'&&playr1[37][3]=='b'&&playr1[37][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[37]<<" Player 2 is charged $"<<rent[37][9]<<endl;
    bank2-=rent[37][4];
    bank1+=rent[37][4];}
   //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[37][0]=='b'&&playr1[37][1]=='b'&&playr1[37][2]=='b'&&playr1[37][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[37]<<" Player 2 is charged $"<<rent[37][3]<<endl;
    bank2-=rent[37][3];
    bank1+=rent[37][3];}
   //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[37][0]=='b'&&playr1[37][1]=='b'&&playr1[37][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[37]<<" Player 2 is charged $"<<rent[37][2]<<endl;
    bank2-=rent[37][2];
    bank1+=rent[37][2];}
   //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[37][0]=='b'&&playr1[37][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[37]<<" Player 2 is charged $"<<rent[37][1]<<endl;
    bank2-=rent[37][1];
    bank1+=rent[37][1];}
   //Regular rent
    
    else if(turn==true&&buy==true&&playr1[37][0]=='b')
    { cout<<"Your opponent owns "<<prop[37]<< " Player 2 is charged $"<<rent[37][0]<<endl;
    bank2-=rent[37][0];
    bank1+=rent[37][0];}
    
    else
        cout<<""<<endl;}     
}
void blue2(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{     static bool buy=false;                          //Bool that indicates the property has not been purchased yet
    int rate=400;                                     //Cost of property
    char choice;                                      //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[39]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[39][0]='b';
            cout<<"Player 1 Bought "<<prop[39]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[39][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 2 has 4 house and hotel
    else if(turn==false&&buy==true&&playr2[39][0]=='b'&&playr2[39][1]=='b'&&playr2[39][2]=='b'&&playr2[39][3]=='b'&&playr2[39][4]=='b'&&playr2[39][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[39]<<" Player 1 is charged $"<<rent[39][5]<<endl;
    bank1-=rent[39][5];
    bank2+=rent[39][5];}
     //Player 2 has 4 house 
    else if(turn==false&&buy==true&&playr2[39][0]=='b'&&playr2[39][1]=='b'&&playr2[39][2]=='b'&&playr2[39][3]=='b'&&playr2[39][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[39]<<" Player 1 is charged "<<rent[39][4]<<endl;
    bank1-=rent[39][4];
    bank2+=rent[39][4];}
     //Player 2 has 3 house 
    else if(turn==false&&buy==true&&playr2[39][0]=='b'&&playr2[39][1]=='b'&&playr2[39][4]=='b'&&playr2[39][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[39]<<" Player 1 is charged $"<<rent[39][3]<<endl;
    bank1-=rent[39][3];
    bank2+=rent[39][3];}
     //Player 2 has 2 house 
    else if(turn==false&&buy==true&&playr2[39][0]=='b'&&playr2[39][1]=='b'&&playr2[39][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[39]<<" Player 1 is charged $"<<rent[39][2]<<endl;
    bank1-=rent[39][2];
    bank2+=rent[39][2];}
    // //Player 2 has 1 house 
    else if(turn==false&&buy==true&&playr2[39][0]=='b'&&playr2[39][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[39]<<" Player 1 is charged $"<<rent[39][1]<<endl;
    bank1-=rent[39][1];
    bank2+=rent[39][1];}
    //Regular rent
    else if(turn==false&&buy==true&&playr2[39][0]=='b')
    { cout<<"Your opponent owns "<<prop[39]<< " Player 1 is charged $"<<rent[39][0]<<endl;
    bank1-=rent[39][0];
    bank2+=rent[39][0];}
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[39][0]='b';
            cout<<"Player 2 Bought "<<prop[39]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[39][0]=='b')      
        cout<<"You already own this property"<<endl;
     //Player 1 has 4 house and hotel
    else if(turn==true&&buy==true&&playr1[39][0]=='b'&&playr1[39][1]=='b'&&playr1[39][2]=='b'&&playr1[39][3]=='b'&&playr1[39][4]=='b'&&playr1[39][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[39]<<" Player 2 is charged $"<<rent[39][5]<<endl;
    bank2-=rent[39][5];
    bank1+=rent[39][5];}
   //Player 1 has 4 house 
    else if(turn==true&&buy==true&&playr1[39][0]=='b'&&playr1[39][1]=='b'&&playr1[39][2]=='b'&&playr1[39][3]=='b'&&playr1[39][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[39]<<" Player 2 is charged $"<<rent[39][9]<<endl;
    bank2-=rent[39][4];
    bank1+=rent[39][4];}
   //Player 1 has 3 house 
    else if(turn==true&&buy==true&&playr1[39][0]=='b'&&playr1[39][1]=='b'&&playr1[39][2]=='b'&&playr1[39][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[39]<<" Player 2 is charged $"<<rent[39][3]<<endl;
    bank2-=rent[39][3];
    bank1+=rent[39][3];}
   //Player 1 has 2 house 
    else if(turn==true&&buy==true&&playr1[39][0]=='b'&&playr1[39][1]=='b'&&playr1[39][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[39]<<" Player 2 is charged $"<<rent[39][2]<<endl;
    bank2-=rent[39][2];
    bank1+=rent[39][2];}
   //Player 1 has 1 house 
    else if(turn==true&&buy==true&&playr1[39][0]=='b'&&playr1[39][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[39]<<" Player 2 is charged $"<<rent[39][1]<<endl;
    bank2-=rent[39][1];
    bank1+=rent[39][1];}
  //Regular rent
    
    else if(turn==true&&buy==true&&playr1[39][0]=='b')
    { cout<<"Your opponent owns "<<prop[39]<< " Player 2 is charged $"<<rent[37][0]<<endl;
    bank2-=rent[39][0];
    bank1+=rent[39][0];}
    
    else
        cout<<""<<endl;}
}
int chance(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], 
          int &bank1,int &bank2,bool turn,int &player1,int &player2,int totDie)
{   
    //Declare variables
    unsigned seed=static_cast<int>(time(0));
    srand(seed);                               //Random number generator
    int chance;                                //Holds random number
    chance=rand()%15+1;                        //Limits range to 1-15 and stores number
    //Prompts location
    cout<<"Welcome to Chance"<<endl;
    
    //Conditionally executes if its player 1's turn
    if(turn==false)
    {
   //Conditionally executes depending on random number generated. All choices
   //are based on the real chance cards from the game and if the card sends
   //Player one to a location a function call to that property is enabled and total
   // dice count reflects this position 
    switch(chance)
    {
        case 1:cout<<"Advance to Go (Collect $200"<<endl;
              player1=0;
              bank1+=200;
              start();
              break;
        case 2:cout<<"Advance to Illinois Ave"<<endl;
               if(player1>25)
               { bank1+=100;
                 player1=24;
                 red3(prop,rent, playr1,playr2,bank1,bank2,turn);}
               else
               { player1=24;
                 red3(prop,rent, playr1,playr2,bank1,bank2,turn);}
                   break;
        case 3:cout<<"Advance token to nearest Utility. If unowned, you may buy it from the Bank"<<endl;
               cout<<"If owned, throw dice and pay owner a total ten times the amount thrown."<<endl;
               if(player1<12)
               {player1=12;
               elecCom(prop, playr1,playr2,bank1,bank2,turn,totDie);}
               else if(player1>12&&player1<=28)
               {   player1=28;
                   watWork(prop, playr1,playr2,bank1,bank2,turn,totDie);}
               else
               { player1=12;
               elecCom(prop, playr1,playr2,bank1,bank2,turn,totDie);}
               break;
        case 4:cout<<"Advance token to the nearest Railroad and pay owner twice the rental to which he/she {he} is otherwise entitled."<<endl; 
               cout<<"If Railroad is unowned, you may buy it from the Bank"<<endl;
               if(player1<=5)
               {player1=5;
                rr1(prop,rent, playr1,playr2,bank1,bank2,turn);}
               else if(player1>5&&player1<=15)
               {player1=15;
                rr2(prop,rent,playr1,playr2,bank1,bank2,turn);}
               else if(player1>15&&player1<=25)
               { player1=25;
                rr3(prop,rent,playr1,playr2,bank1,bank2,turn);}
               else if(player1>25&&player1<=35)
               {player1=35;
                rr4(prop,rent,playr1,playr2,bank1,bank2,turn);}
               else
               {player1=5;
                rr1(prop,rent, playr1,playr2,bank1,bank2,turn);}
               break;
        case 5:cout<<"Bank pays you dividend of $50"<<endl;
               bank1+=50;
               break;
        case 6:cout<<"Get out of Jail Free"<<endl;
               playr1[10][1]='f';
               break;
        case 7:cout<<"Go Back 3 Spaces"<<endl;
              if(player1==7)
              {player1=4;
               incTax(prop,bank1,bank2,turn);}
              else if(player1==21)
              {   player1=18;
              orange2(prop,rent,playr1,playr2,bank1,bank2,turn);}
              else
              { player1=30;
              green3(prop,rent, playr1,playr2,bank1,bank2,turn);}
              break;
        case 8:cout<<"Go to Jail – Go directly to Jail – Do not pass Go, do not collect $200"<<endl;
               player1=10;
               break;
        case 9:cout<<"Make general repairs on all your property – For each house pay $25 – For each hotel $100"<<endl;
               break;
        case 10:cout<<"Pay poor tax of $15"<<endl;
                bank1-=15;
                break;
        case 11:cout<<"Take a trip to Reading Railroad {Take a ride on the Reading} – If you pass Go, collect $200"<<endl;
                if(player1>5)
                {bank1+=200;
                  player1=5;
                 rr1(prop,rent,playr1, playr2,bank1,bank2,turn);}
                  else
                  {player1=5;
                   rr1(prop,rent,playr1, playr2,bank1,bank2,turn);}
                  break;
        case 12:cout<<"Take a walk on the Boardwalk – Advance token to Boardwalk"<<endl;
                player1=139;
                 blue2(prop,rent,playr1, playr2,bank1,bank2,turn);
                break;
        case 13:cout<<"You have been elected Chairman of the Board – Pay each player $50"<<endl;
        case 14:cout<<"Your building loan matures – Collect $150"<<endl;
                bank1+=150;
                break;
        case 15:cout<<"You have won a crossword competition - Collect $100"<<endl;
                bank1+=100;
                break;
    }
    }   
    //Conditionally executes if player 2's turn
     if(turn==true)
     {
    //Conditionally executes depending on random number generated. All choices
   //are based on the real chance cards from the game and if the card sends
   //Player one to a location a function call to that property is enabled and total
   // dice count reflects this position 
    switch(chance)
    {
        case 1:cout<<"Advance to Go (Collect $200"<<endl;
              player2=0;
              bank2+=200;
              start();
              break;
        case 2:cout<<"Advance to Illinois Ave"<<endl;
               if(player1>25)
               { bank2+=100;
                 player2=24;
                 red3(prop,rent, playr1,playr2,bank1,bank2,turn);}
               else
               { player2=24;
                 red3(prop,rent, playr1,playr2,bank1,bank2,turn);}
                   break;
        case 3:cout<<"Advance token to nearest Utility. If unowned, you may buy it from the Bank"<<endl;
               cout<<"If owned, throw dice and pay owner a total ten times the amount thrown."<<endl;
               if(player2<12)
               {player2=12;
               elecCom(prop, playr1,playr2,bank1,bank2,turn,totDie);}
               else if(player2>12&&player2<=28)
               {   player2=28;
                   watWork(prop, playr1,playr2,bank1,bank2,turn,totDie);}
               else
               { player2=12;
               elecCom(prop, playr1,playr2,bank1,bank2,turn,totDie);}
               break;
        case 4:cout<<"Advance token to the nearest Railroad and pay owner twice the rental to which he/she {he} is otherwise entitled."<<endl; 
               cout<<"If Railroad is unowned, you may buy it from the Bank"<<endl;
               if(player2<=5)
               {player2=5;
                rr1(prop,rent, playr1,playr2,bank1,bank2,turn);}
               else if(player2>5&&player2<=15)
               {player2=15;
                rr2(prop,rent,playr1,playr2,bank1,bank2,turn);}
               else if(player2>15&&player2<=25)
               { player2=25;
                rr3(prop,rent,playr1,playr2,bank1,bank2,turn);}
               else if(player2>25&&player2<=35)
               {player2=35;
                rr4(prop,rent,playr1,playr2,bank1,bank2,turn);}
               else
               {player2=5;
                rr1(prop,rent, playr1,playr2,bank1,bank2,turn);}
               break;
        case 5:cout<<"Bank pays you dividend of $50"<<endl;
               bank2+=50; 
               break;
        case 6:cout<<"Get out of Jail Free"<<endl;
                playr2[10][1]=='f';
                break;
        case 7:cout<<"Go Back 3 Spaces"<<endl;
              if(player2==7)
              {player2=4;
               incTax(prop,bank1,bank2,turn);}
              else if(player2==21)
              {   player2=18;
              orange2(prop,rent,playr1,playr2,bank1,bank2,turn);}
              else
              {  player2=33;
              green3(prop,rent, playr1,playr2,bank1,bank2,turn);}
              break;
        case 8:cout<<"Go to Jail – Go directly to Jail – Do not pass Go, do not collect $200"<<endl;
               player2=10;
               break;
        case 9:cout<<"Make general repairs on all your property – For each house pay $25 – For each hotel $100"<<endl;
        case 10:cout<<"Pay poor tax of $15"<<endl;
                bank2-=15;
                break;
        case 11:cout<<"Take a trip to Reading Railroad {Take a ride on the Reading} – If you pass Go, collect $200"<<endl;
                if(player2>5)
                {bank1+=200;
                  player2=5;
                 rr1(prop,rent,playr1, playr2,bank1,bank2,turn);}
                  else
                  {player2=5;
                   rr1(prop,rent,playr1, playr2,bank1,bank2,turn);}
                  break;
        case 12:cout<<"Take a walk on the Boardwalk – Advance token to Boardwalk"<<endl;
                player2=139;
                 blue2(prop,rent,playr1, playr2,bank1,bank2,turn);
                break;
        case 13:cout<<"You have been elected Chairman of the Board – Pay each player $50"<<endl;
        break;
        case 14:cout<<"Your building loan matures – Collect $150"<<endl;
                bank2+=150;
                break;
        case 15:cout<<"You have won a crossword competition - Collect $100"<<endl;
                bank2+=100;
                break;
    }
    }   
}
int comChest(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
void rr1(string prop [],int rent[][COL], char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                                    //Bool that indicates the property has not been purchased yet
    int rate=200;                                             //Cost of property
    char choice;                                               //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[5]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[5][0]='b';
            cout<<"Player 1 Bought "<<prop[5]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[5][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 2 owns 4 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  4 Railroads. Player 1 is charged $"<<rent[5][3]<<endl;
    bank1-=rent[5][3];
    bank2+=rent[5][3];}
    //Player 2 owns 3 railroads
      else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 3 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 3 railroad
       else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[25][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
  //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b')
    { cout<<"Your opponent owns 2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns 2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 2 railroads
       else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns 2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 1 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b')
    { cout<<"Your opponent owns 1 Railroads. Player 1 is charged $"<<rent[5][0]<<endl;
    bank1-=rent[5][0];
    bank2+=rent[5][0];}
   
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[5][0]='b';
            cout<<"Player 2 Bought "<<prop[5]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[5][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    //Player 2 owns 4 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns all 4 Railroads. Player 2 is charged $"<<rent[5][3]<<endl;
    bank2-=rent[5][3];
    bank1+=rent[5][3];}
  //Player 2 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 2 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 2 owns 3 railroads
   else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[25][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 2 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 2 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[25][0]=='b')
    { cout<<"Your opponent owns 2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 2 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 2 owns 1 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b')
    { cout<<"Your opponent owns 1 Railroads. Player 2 is charged $"<<rent[5][0]<<endl;
    bank2-=rent[5][0];
    bank1+=rent[5][0];}
    else
        cout<<""<<endl;}
}
void rr2(string prop [], int rent [][COL], char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                               //Bool that indicates the property has not been purchased yet
    int rate=200;                                        //Cost of property
    char choice;                                         //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[15]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[15][0]='b';
            cout<<"Player 1 Bought "<<prop[15]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[15][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 2 owns 4 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns all 4 Railroads. Player 1 is charged $"<<rent[5][3]<<endl;
    bank1-=rent[5][3];
    bank2+=rent[5][3];}
    //Player 2 owns 3 railroads
      else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 3 railroads
    else if(turn==false&&buy==true&&playr2[25][0]=='b'&&playr2[15][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 3 railroads
  else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[15][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 2 railroads
       else if(turn==false&&buy==true&&playr2[15][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 1 railroads
    else if(turn==false&&buy==true&&playr2[15][0]=='b')
    { cout<<"Your opponent owns  1 Railroads. Player 1 is charged $"<<rent[5][0]<<endl;
    bank1-=rent[5][0];
    bank2+=rent[5][0];}
   
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[15][0]='b';
            cout<<"Player 2 Bought "<<prop[15]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[15][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    //Player 1 owns 4 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns all 4 Railroads. Player 2 is charged $"<<rent[5][3]<<endl;
    bank2-=rent[5][3];
    bank1+=rent[5][3];}
  //Player 1 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 1 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 1 owns 3 railroads
  else if(turn==true&&buy==true&&playr1[25][0]=='b'&&playr1[15][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  
  //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[15][0]=='b'&&playr1[25][0]=='b')
    { cout<<"Your opponent owns 2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[15][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 1 owns 1 railroads
    else if(turn==true&&buy==true&&playr1[15][0]=='b')
    { cout<<"Your opponent owns 1 Railroads. Player 2 is charged $"<<rent[5][0]<<endl;
    bank2-=rent[5][0];
    bank1+=rent[5][0];}
    else
        cout<<""<<endl;}
    
}
void rr3(string prop [],int rent[][COL], char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
            static bool buy=false;                         //Bool that indicates the property has not been purchased yet
    int rate=200;                                          //Cost of property
    char choice;                                           //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[25]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[25][0]='b';
            cout<<"Player 1 Bought "<<prop[25]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[25][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 2 owns 4 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns all 4 Railroads. Player 1 is charged $"<<rent[5][3]<<endl;
    bank1-=rent[5][3];
    bank2+=rent[5][3];}
    //Player 2 owns 3 railroads
      else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 3 railroads
    else if(turn==false&&buy==true&&playr2[25][0]=='b'&&playr2[15][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 3 railroads
   else if(turn==false&&buy==true&&playr2[25][0]=='b'&&playr2[5][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
    //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[15][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 2 railroads
       else if(turn==false&&buy==true&&playr2[25][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
    //Player 2 owns 1 railroads
    else if(turn==false&&buy==true&&playr2[25][0]=='b')
    { cout<<"Your opponent owns  1 Railroads. Player 1 is charged $"<<rent[5][0]<<endl;
    bank1-=rent[5][0];
    bank2+=rent[5][0];}
   
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[25][0]='b';
            cout<<"Player 2 Bought "<<prop[25]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[25][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    //Player 1 owns 4 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns all 4 Railroads. Player 2 is charged $"<<rent[5][3]<<endl;
    bank2-=rent[5][3];
    bank1+=rent[5][3];}
  //Player 1 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 1 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[25][0]=='b'&&playr1[15][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 1 owns 3 railroads
   else if(turn==true&&buy==true&&playr1[25][0]=='b'&&playr1[5][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
  //Player 1 owns 2 railroads
  
    else if(turn==true&&buy==true&&playr1[25][0]=='b'&&playr1[15][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[25][0]=='b')
    { cout<<"Your opponent owns 2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[25][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
  //Player 1 owns 1 railroads
    else if(turn==true&&buy==true&&playr1[25][0]=='b')
    { cout<<"Your opponent owns 1 Railroads. Player 2 is charged $"<<rent[5][0]<<endl;
    bank2-=rent[5][0];
    bank1+=rent[5][0];}
    else
        cout<<""<<endl;}
    
}
void rr4(string prop [], int rent[][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;                                //Bool that indicates the property has not been purchased yet
    int rate=200;                                         //Cost of property
    char choice;                                          //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[35]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[35][0]='b';
            cout<<"Player 1 Bought "<<prop[35]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[35][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 2 owns 4 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns all 4 Railroads. Player 1 is charged $"<<rent[5][3]<<endl;
    bank1-=rent[5][3];
    bank2+=rent[5][3];}
     //Player 2 owns 3 railroads
      else if(turn==false&&buy==true&&playr2[35][0]=='b'&&playr2[15][0]=='b'&&playr2[25][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
     //Player 2 owns 3 railroads
    else if(turn==false&&buy==true&&playr2[25][0]=='b'&&playr2[5][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
     //Player 2 owns 3 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[15][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 1 is charged $"<<rent[5][2]<<endl;
    bank1-=rent[5][2];
    bank2+=rent[5][2];}
   //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[5][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
     //Player 2 owns 2 railroads
    else if(turn==false&&buy==true&&playr2[15][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
     //Player 2 owns 2 railroads
       else if(turn==false&&buy==true&&playr2[25][0]=='b'&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 1 is charged $"<<rent[5][1]<<endl;
    bank1-=rent[5][1];
    bank2+=rent[5][1];}
     //Player 2 owns 1 railroads
    else if(turn==false&&buy==true&&playr2[35][0]=='b')
    { cout<<"Your opponent owns  1 Railroads. Player 1 is charged $"<<rent[5][0]<<endl;
    bank1-=rent[5][0];
    bank2+=rent[5][0];}
   
  else 
  {cout<<""<<endl;
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<". Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[35][0]='b';
            cout<<"Player 2 Bought "<<prop[35]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[35][0]=='b')      
        cout<<"You already own this property"<<endl;
        
     //Player 1 owns 4 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns all 4 Railroads. Player 2 is charged $"<<rent[5][3]<<endl;
    bank2-=rent[5][3];
    bank1+=rent[5][3];}
   //Player 1 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[35][0]=='b'&&playr1[15][0]=='b'&&playr1[25][0]=='b')
    { cout<<"Your opponent owns  3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
   //Player 1 owns 3 railroads
    else if(turn==true&&buy==true&&playr1[25][0]=='b'&&playr1[5][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
   //Player 1 owns 3 railroads
   else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[15][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 3 Railroads. Player 2 is charged $"<<rent[5][2]<<endl;
    bank2-=rent[5][2];
    bank1+=rent[5][2];}
   //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[25][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
   //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[5][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
   //Player 1 owns 2 railroads
    else if(turn==true&&buy==true&&playr1[15][0]=='b'&&playr1[35][0]=='b')
    { cout<<"Your opponent owns  2 Railroads. Player 2 is charged $"<<rent[5][1]<<endl;
    bank2-=rent[5][1];
    bank1+=rent[5][1];}
   //Player 1 owns 1 railroads
    else if(turn==true&&buy==true&&playr1[35][0]=='b')
    { cout<<"Your opponent owns 1 Railroads. Player 2 is charged $"<<rent[5][0]<<endl;
    bank2-=rent[5][0];
    bank1+=rent[5][0];}
    else
        cout<<""<<endl;}
    
}
int frePark(string prop [])
{
    //Outputs that the player hase landed on free parking
    cout<<"You landed on "<<prop[20]<<endl;
    
}
int jail(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int goToJail(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int luxTax(string prop [], int &bank1,int &bank2,bool turn)
{
    //Notifies user that it landed on luxery tax 
    cout<<"You have landed on "<<prop[38]<<endl;
    //Player 1's turn
    if(turn==false)
    //Subtracts 75 from users bank
    {cout<<"Player 1 $75 has been taken from you"<<endl;
    bank1-=75;}
    //Player 2's turn
    if(turn==true)
        {cout<<"Player 2 $75 has been taken from you"<<endl;
        //Takes 75 from users bank
      bank2-=75;}
}
int incTax(string prop[],int &bank1,int &bank2,bool turn)
{
    char choice;
    int amt;
   //Notifies user that they landed on income tax
    cout<<"You have landed on "<<prop[4]<<endl;
    //Player 1's turn
    if(turn==false)
    {
        //Prompts user if they would like to pay $200 or 10% total cash
        cout<<"Would you like to Pay $200 or 10% of your total Cash. Press t to pay 200 or c to pay 10% of cash." <<endl; 
        cin>>choice;
        //Executes if t is chosen
        if(choice=='t'||choice=='T')
        {
            bank1-=200;
        }
        //Executes if c is chosen
        else if(choice=='c'||choice=='C')
        { amt=bank1*.10;
          bank1-=amt;
          cout<<"10% has been taken from you in the amount of $"<<amt<<endl;
        }
    }
       //Player 2's turn
        if(turn==true)
    {
        //Prompts user if they would like to pay $200 or 10% total cash
        cout<<"Would you like to Pay $200 or 10% of your total Cash. Press t to pay 200 or c to pay 10% of cash." <<endl; 
        cin>>choice;
        //If t is chosen
        if(choice=='t'||choice=='T')
        {
            bank2-=200;
        }
        //if c is chosen
        else if(choice=='c'||choice=='C')
        { amt=bank2*.10;
          bank2-=amt;
          cout<<"10% has been taken from you in the amount of $"<<amt<<endl;
        }
    }
    
    
    
}
void watWork(string prop [], char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn, int die)
{   static bool buy=false;                                       //Bool that indicates the property has not been purchased yet
    int rate=150;                                                //Cost of property
    char choice;                                                 //Players choice to buy property
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    cout<<"Welcome to "<<prop[28]<<endl;
 if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[28][0]='b';
            cout<<"Player 1 Bought "<<prop[28]<<endl;}}
            
    //Die is a pointer to the dice roll so proper multiplication
    
    else if(turn==false&&buy==true&&playr1[28][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 2 has both utilities
    else if(turn==false&&buy==true&&playr2[12][0]=='b'&&playr2[28][0]=='b')
    { cout<<"Your opponent owns all utilities. Player 1 is charged $"<<(die*10)<<endl;
    bank1-=(die*10);
    bank2+=(die*10);}
    //player 2 has 1 utilites
    else if(turn==false&&buy==true&&playr2[28][0]=='b')
    { cout<<"Your opponent owns this utility. Player 1 is charged $"<<(die*4)<<endl;
    bank1-=(die*4);
    bank2+=(die*4);}
    else
        cout<<"";
    
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
 if(turn==true&&buy==false)
    {  cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank2-=rate;
            playr2[28][0]='b';
            cout<<"Player 2 Bought "<<prop[28]<<endl;}}
            
    
   else if(turn==true&&buy==true&&playr2[28][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 1 has both utilities
    else if(turn==true&&buy==true&&playr1[12][0]=='b'&&playr1[28][0]=='b')
    { cout<<"Your opponent owns all utilities. Player 2 is charged $"<<(die*10)<<endl;
    bank2-=(die*10);
    bank1+=(die*10);}
    //Player 1 has one utility
    else if(turn==true&&buy==true&&playr1[28][0]=='b')
    { cout<<"Your opponent owns this utilities. Player 2 is charged $"<<(die*4)<<endl;
    bank2-=(die*4);
    bank1+=(die*4);}
           else
               cout<<" ";
}
void elecCom(string prop [], char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn, int die)
{  static bool buy=false;
    int rate=150;                                      //Cost of property
    char choice;                                       //Players choice to buy property
    
    cout<<"Welcome to "<<prop[12]<<endl;
   
     //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
 if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[12][0]='b';
            cout<<"Player 1 Bought "<<prop[12]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[12][0]=='b')      
        cout<<"You already own this property"<<endl;
 //Player 2 owns all utilities
    else if(turn==false&&buy==true&&playr2[12][0]=='b'&&playr2[28][0]=='b')
    { cout<<"Your opponent owns all utilities. Player 1 is charged $"<<(die*10)<<endl;
    bank1-=(die*10);
    bank2+=(die*10);}
    else if(turn==false&&buy==true&&playr2[12][0]=='b')
        //Player 2 owns one utility
    { cout<<"Your opponent owns this utility. Player 1 is charged $"<<(die*4)<<endl;
    bank1-=(die*4);
    bank2+=(die*4);}
    else
        cout<<"";
 if(turn==true&&buy==false)
     
      //Prompts user if they wish to purchase the property and then places a 'b' in players array
    //To indicate that that player 1 owns the property if other player lands on it.
    {  cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $"<<rate<<" Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank2-=rate;
            playr2[12][0]='b';
            cout<<"Player 2 Bought "<<prop[12]<<endl;}}
            
    
   else if(turn==true&&buy==true&&playr2[12][0]=='b')      
        cout<<"You already own this property"<<endl;
    //Player 1 owns all utilites
    else if(turn==true&&buy==true&&playr1[12][0]=='b'&&playr1[28][0]=='b')
    { cout<<"Your opponent owns all utilities. Player 2 is charged $"<<(die*10)<<endl;
    bank2-=(die*10);
    bank1+=(die*10);}
    //Player one owns one utility
    else if(turn==true&&buy==true&&playr1[12][0]=='b')
    { cout<<"Your opponent owns this utilities. Player 2 is charged $"<<(die*4)<<endl;
    bank2-=(die*4);
    bank1+=(die*4);}
           else
               cout<<" ";
    
}
void start()
{
    //Inform user that they are on start
    cout<<"You Have Landed on Start"<<endl;
}
int menu(string prop [],int rent [][COL],char playr1[][COL], char playr2[][COL], int &bank1,int &bank2,bool turn)
{
    char choice;
    char house;
    cout<<"Would you like to purchase houses. Press y for yes and n for no"<<endl;
    cin>>choice;
    if(turn==false)
    {
    if(choice=='y'||choice=='Y')
    {
        if(playr1[1][0]=='b'&&playr1[3][0]=='b')
        { cout<<"You own "<<prop[1][0]<<" and "<<prop[3][0]<<endl;
         cout<<"Press m to place a house on "<<prop[1][0]<<" and b for "<<prop[3][0];
         cin>>house;
         if(house=='m'||house=='M')
         { if(playr1[1][1]!='b')
             playr1[1][1]='b';
         else if(playr1[1][2]!='b')
             playr1[1][2]='b';
         else if(playr1[1][3]!='b')
             playr1[1][3]='b';
         else if(playr1[1][4]!='b')
              playr1[1][4]='b';
         else if(playr1[1][5]!='b')
             playr1[1][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='b'||house=='B')
         { if(playr1[3][1]!='b')
             playr1[3][1]='b';
         else if(playr1[3][2]!='b')
             playr1[3][2]='b';
         else if(playr1[1][3]!='b')
             playr1[3][3]='b';
         else if(playr1[1][4]!='b')
              playr1[3][4]='b';
         else if(playr1[3][5]!='b')
             playr1[3][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
        }
if(playr1[6][0]=='b'&&playr1[8][0]=='b'&&playr1[9][0]=='b')
        { cout<<"You own "<<prop[6][0]<<" and "<<prop[8][0]<<" and "<<prop[9][0]<<endl;
         cout<<"Press o to place a house on "<<prop[6][0]<<" and v for "<<prop[8][0]<<" and c for "<<prop[9][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr1[6][1]!='b')
             playr1[6][1]='b';
         else if(playr1[1][2]!='b')
             playr1[6][2]='b';
         else if(playr1[1][3]!='b')
             playr1[6][3]='b';
         else if(playr1[6][4]!='b')
              playr1[6][4]='b';
         else if(playr1[6][5]!='b')
             playr1[6][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr1[8][1]!='b')
             playr1[8][1]='b';
         else if(playr1[8][2]!='b')
             playr1[8][2]='b';
         else if(playr1[8][3]!='b')
             playr1[8][3]='b';
         else if(playr1[1][4]!='b')
              playr1[8][4]='b';
         else if(playr1[8][5]!='b')
             playr1[8][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr1[9][1]!='b')
             playr1[9][1]='b';
         else if(playr1[3][2]!='b')
             playr1[9][2]='b';
         else if(playr1[9][3]!='b')
             playr1[9][3]='b';
         else if(playr1[1][4]!='b')
              playr1[9][4]='b';
         else if(playr1[9][5]!='b')
             playr1[9][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr1[11][0]=='b'&&playr1[13][0]=='b'&&playr1[14][0]=='b')
        { cout<<"You own "<<prop[11][0]<<" and "<<prop[13][0]<<" and "<<prop[14][0]<<endl;
         cout<<"Press o to place a house on "<<prop[11][0]<<" and v for "<<prop[13][0]<<" and c for "<<prop[14][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr1[11][1]!='b')
             playr1[11][1]='b';
         else if(playr1[1][2]!='b')
             playr1[11][2]='b';
         else if(playr1[1][3]!='b')
             playr1[11][3]='b';
         else if(playr1[6][4]!='b')
              playr1[11][4]='b';
         else if(playr1[6][5]!='b')
             playr1[11][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr1[13][1]!='b')
             playr1[13][1]='b';
         else if(playr1[13][2]!='b')
             playr1[13][2]='b';
         else if(playr1[13][3]!='b')
             playr1[13][3]='b';
         else if(playr1[13][4]!='b')
              playr1[13][4]='b';
         else if(playr1[13][5]!='b')
             playr1[13][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr1[14][1]!='b')
             playr1[14][1]='b';
         else if(playr1[14][2]!='b')
             playr1[14][2]='b';
         else if(playr1[14][3]!='b')
             playr1[14][3]='b';
         else if(playr1[14][4]!='b')
              playr1[14][4]='b';
         else if(playr1[14][5]!='b')
             playr1[14][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

        }
        if(playr1[16][0]=='b'&&playr1[18][0]=='b'&&playr1[19][0]=='b')
        { cout<<"You own "<<prop[16][0]<<" and "<<prop[18][0]<<" and "<<prop[19][0]<<endl;
         cout<<"Press o to place a house on "<<prop[16][0]<<" and v for "<<prop[18][0]<<" and c for "<<prop[19][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr1[16][1]!='b')
             playr1[16][1]='b';
         else if(playr1[16][2]!='b')
             playr1[16][2]='b';
         else if(playr1[16][3]!='b')
             playr1[16][3]='b';
         else if(playr1[16][4]!='b')
              playr1[16][4]='b';
         else if(playr1[16][5]!='b')
             playr1[16][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr1[18][1]!='b')
             playr1[18][1]='b';
         else if(playr1[3][2]!='b')
             playr1[18][2]='b';
         else if(playr1[18][3]!='b')
             playr1[18][3]='b';
         else if(playr1[18][4]!='b')
              playr1[18][4]='b';
         else if(playr1[18][5]!='b')
             playr1[18][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr1[19][1]!='b')
             playr1[19][1]='b';
         else if(playr1[19][2]!='b')
             playr1[19][2]='b';
         else if(playr1[19][3]!='b')
             playr1[19][3]='b';
         else if(playr1[19][4]!='b')
              playr1[19][4]='b';
         else if(playr1[19][5]!='b')
             playr1[19][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr1[21][0]=='b'&&playr1[23][0]=='b'&&playr1[24][0]=='b')
        { cout<<"You own "<<prop[21][0]<<" and "<<prop[23][0]<<" and "<<prop[24][0]<<endl;
         cout<<"Press o to place a house on "<<prop[21][0]<<" and v for "<<prop[23][0]<<" and c for "<<prop[24][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr1[21][1]!='b')
             playr1[21][1]='b';
         else if(playr1[21][2]!='b')
             playr1[21][2]='b';
         else if(playr1[1][3]!='b')
             playr1[21][3]='b';
         else if(playr1[21][4]!='b')
              playr1[21][4]='b';
         else if(playr1[21][5]!='b')
             playr1[21][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr1[23][1]!='b')
             playr1[23][1]='b';
         else if(playr1[23][2]!='b')
             playr1[23][2]='b';
         else if(playr1[23][3]!='b')
             playr1[23][3]='b';
         else if(playr1[23][4]!='b')
              playr1[23][4]='b';
         else if(playr1[23][5]!='b')
             playr1[23][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr1[24][1]!='b')
             playr1[24][1]='b';
         else if(playr1[24][2]!='b')
             playr1[24][2]='b';
         else if(playr1[24][3]!='b')
             playr1[24][3]='b';
         else if(playr1[24][4]!='b')
              playr1[24][4]='b';
         else if(playr1[24][5]!='b')
             playr1[24][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr1[26][0]=='b'&&playr1[27][0]=='b'&&playr1[29][0]=='b')
        { cout<<"You own "<<prop[26][0]<<" and "<<prop[27][0]<<" and "<<prop[29][0]<<endl;
         cout<<"Press o to place a house on "<<prop[6][0]<<" and v for "<<prop[8][0]<<" and c for "<<prop[9][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr1[26][1]!='b')
             playr1[26][1]='b';
         else if(playr1[26][2]!='b')
             playr1[26][2]='b';
         else if(playr1[26][3]!='b')
             playr1[26][3]='b';
         else if(playr1[26][4]!='b')
              playr1[26][4]='b';
         else if(playr1[26][5]!='b')
             playr1[26][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr1[27][1]!='b')
             playr1[27][1]='b';
         else if(playr1[27][2]!='b')
             playr1[27][2]='b';
         else if(playr1[27][3]!='b')
             playr1[27][3]='b';
         else if(playr1[27][4]!='b')
              playr1[27][4]='b';
         else if(playr1[27][5]!='b')
             playr1[27][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr1[29][1]!='b')
             playr1[29][1]='b';
         else if(playr1[29][2]!='b')
             playr1[29][2]='b';
         else if(playr1[29][3]!='b')
             playr1[29][3]='b';
         else if(playr1[29][4]!='b')
              playr1[29][4]='b';
         else if(playr1[29][5]!='b')
             playr1[29][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr1[31][0]=='b'&&playr1[32][0]=='b'&&playr1[34][0]=='b')
        { cout<<"You own "<<prop[31][0]<<" and "<<prop[32][0]<<" and "<<prop[34][0]<<endl;
         cout<<"Press o to place a house on "<<prop[31][0]<<" and v for "<<prop[32][0]<<" and c for "<<prop[34][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr1[31][1]!='b')
             playr1[31][1]='b';
         else if(playr1[31][2]!='b')
             playr1[31][2]='b';
         else if(playr1[31][3]!='b')
             playr1[31][3]='b';
         else if(playr1[31][4]!='b')
              playr1[31][4]='b';
         else if(playr1[6][5]!='b')
             playr1[31][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr1[32][1]!='b')
             playr1[32][1]='b';
         else if(playr1[32][2]!='b')
             playr1[32][2]='b';
         else if(playr1[32][3]!='b')
             playr1[32][3]='b';
         else if(playr1[32][4]!='b')
              playr1[32][4]='b';
         else if(playr1[32][5]!='b')
             playr1[32][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr1[34][1]!='b')
             playr1[34][1]='b';
         else if(playr1[34][2]!='b')
             playr1[34][2]='b';
         else if(playr1[34][3]!='b')
             playr1[34][3]='b';
         else if(playr1[34][4]!='b')
              playr1[34][4]='b';
         else if(playr1[34][5]!='b')
             playr1[34][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr1[37][0]=='b'&&playr1[39][0]=='b')
        { cout<<"You own "<<prop[37][0]<<" and "<<prop[39][0]<<endl;
         cout<<"Press o to place a house on "<<prop[37][0]<<" and v for "<<prop[39][0]<<endl;
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr1[37][1]!='b')
             playr1[37][1]='b';
         else if(playr1[37][2]!='b')
             playr1[37][2]='b';
         else if(playr1[37][3]!='b')
             playr1[37][3]='b';
         else if(playr1[37][4]!='b')
              playr1[37][4]='b';
         else if(playr1[37][5]!='b')
             playr1[37][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr1[39][1]!='b')
             playr1[39][1]='b';
         else if(playr1[39][2]!='b')
             playr1[39][2]='b';
         else if(playr1[39][3]!='b')
             playr1[39][3]='b';
         else if(playr1[39][4]!='b')
              playr1[39][4]='b';
         else if(playr1[39][5]!='b')
             playr1[39][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
    }}
        if(turn==true)
    {
    if(choice=='y'||choice=='Y')
    {
        if(playr2[1][0]=='b'&&playr2[3][0]=='b')
        { cout<<"You own "<<prop[1][0]<<" and "<<prop[3][0]<<endl;
         cout<<"Press m to place a house on "<<prop[1][0]<<" and b for "<<prop[3][0];
         cin>>house;
         if(house=='m'||house=='M')
         { if(playr2[1][1]!='b')
             playr2[1][1]='b';
         else if(playr2[1][2]!='b')
             playr2[1][2]='b';
         else if(playr2[1][3]!='b')
             playr2[1][3]='b';
         else if(playr2[1][4]!='b')
              playr2[1][4]='b';
         else if(playr2[1][5]!='b')
             playr2[1][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='b'||house=='B')
         { if(playr2[3][1]!='b')
             playr2[3][1]='b';
         else if(playr2[3][2]!='b')
             playr2[3][2]='b';
         else if(playr2[1][3]!='b')
             playr2[3][3]='b';
         else if(playr2[1][4]!='b')
              playr2[3][4]='b';
         else if(playr2[3][5]!='b')
             playr2[3][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
        }
if(playr2[6][0]=='b'&&playr2[8][0]=='b'&&playr2[9][0]=='b')
        { cout<<"You own "<<prop[6][0]<<" and "<<prop[8][0]<<" and "<<prop[9][0]<<endl;
         cout<<"Press o to place a house on "<<prop[6][0]<<" and v for "<<prop[8][0]<<" and c for "<<prop[9][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr2[6][1]!='b')
             playr2[6][1]='b';
         else if(playr2[1][2]!='b')
             playr2[6][2]='b';
         else if(playr2[1][3]!='b')
             playr2[6][3]='b';
         else if(playr2[6][4]!='b')
              playr2[6][4]='b';
         else if(playr2[6][5]!='b')
             playr2[6][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr2[8][1]!='b')
             playr2[8][1]='b';
         else if(playr2[8][2]!='b')
             playr2[8][2]='b';
         else if(playr2[8][3]!='b')
             playr2[8][3]='b';
         else if(playr2[1][4]!='b')
              playr2[8][4]='b';
         else if(playr2[8][5]!='b')
             playr2[8][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr2[9][1]!='b')
             playr2[9][1]='b';
         else if(playr2[9][2]!='b')
             playr2[9][2]='b';
         else if(playr2[9][3]!='b')
             playr2[9][3]='b';
         else if(playr2[1][4]!='b')
              playr2[9][4]='b';
         else if(playr2[9][5]!='b')
             playr2[9][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr2[11][0]=='b'&&playr2[13][0]=='b'&&playr2[14][0]=='b')
        { cout<<"You own "<<prop[11][0]<<" and "<<prop[13][0]<<" and "<<prop[14][0]<<endl;
         cout<<"Press o to place a house on "<<prop[11][0]<<" and v for "<<prop[13][0]<<" and c for "<<prop[14][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr2[11][1]!='b')
             playr2[11][1]='b';
         else if(playr2[1][2]!='b')
             playr2[11][2]='b';
         else if(playr2[1][3]!='b')
             playr2[11][3]='b';
         else if(playr2[6][4]!='b')
              playr2[11][4]='b';
         else if(playr2[6][5]!='b')
             playr2[11][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr2[13][1]!='b')
             playr2[13][1]='b';
         else if(playr2[13][2]!='b')
             playr2[13][2]='b';
         else if(playr2[13][3]!='b')
             playr2[13][3]='b';
         else if(playr2[13][4]!='b')
              playr2[13][4]='b';
         else if(playr2[13][5]!='b')
             playr2[13][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr2[14][1]!='b')
             playr2[14][1]='b';
         else if(playr2[14][2]!='b')
             playr2[14][2]='b';
         else if(playr2[14][3]!='b')
             playr2[14][3]='b';
         else if(playr2[14][4]!='b')
              playr2[14][4]='b';
         else if(playr2[14][5]!='b')
             playr2[14][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

        }
        if(playr2[16][0]=='b'&&playr2[18][0]=='b'&&playr2[19][0]=='b')
        { cout<<"You own "<<prop[16][0]<<" and "<<prop[18][0]<<" and "<<prop[19][0]<<endl;
         cout<<"Press o to place a house on "<<prop[16][0]<<" and v for "<<prop[18][0]<<" and c for "<<prop[19][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr2[16][1]!='b')
             playr2[16][1]='b';
         else if(playr2[16][2]!='b')
             playr2[16][2]='b';
         else if(playr2[16][3]!='b')
             playr2[16][3]='b';
         else if(playr2[16][4]!='b')
              playr2[16][4]='b';
         else if(playr2[16][5]!='b')
             playr2[16][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr2[18][1]!='b')
             playr2[18][1]='b';
         else if(playr2[3][2]!='b')
             playr2[18][2]='b';
         else if(playr2[18][3]!='b')
             playr2[18][3]='b';
         else if(playr2[18][4]!='b')
              playr2[18][4]='b';
         else if(playr2[18][5]!='b')
             playr2[18][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr2[19][1]!='b')
             playr2[19][1]='b';
         else if(playr2[19][2]!='b')
             playr2[19][2]='b';
         else if(playr2[19][3]!='b')
             playr2[19][3]='b';
         else if(playr2[19][4]!='b')
              playr2[19][4]='b';
         else if(playr2[19][5]!='b')
             playr2[19][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr2[21][0]=='b'&&playr2[23][0]=='b'&&playr2[24][0]=='b')
        { cout<<"You own "<<prop[21][0]<<" and "<<prop[23][0]<<" and "<<prop[24][0]<<endl;
         cout<<"Press o to place a house on "<<prop[21][0]<<" and v for "<<prop[23][0]<<" and c for "<<prop[24][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr2[21][1]!='b')
             playr2[21][1]='b';
         else if(playr2[21][2]!='b')
             playr2[21][2]='b';
         else if(playr2[1][3]!='b')
             playr2[21][3]='b';
         else if(playr2[21][4]!='b')
              playr2[21][4]='b';
         else if(playr2[21][5]!='b')
             playr2[21][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr2[23][1]!='b')
             playr2[23][1]='b';
         else if(playr2[23][2]!='b')
             playr2[23][2]='b';
         else if(playr2[23][3]!='b')
             playr2[23][3]='b';
         else if(playr2[23][4]!='b')
              playr2[23][4]='b';
         else if(playr2[23][5]!='b')
             playr2[23][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr2[24][1]!='b')
             playr2[24][1]='b';
         else if(playr2[24][2]!='b')
             playr2[24][2]='b';
         else if(playr2[24][3]!='b')
             playr2[24][3]='b';
         else if(playr2[24][4]!='b')
              playr2[24][4]='b';
         else if(playr1[24][5]!='b')
             playr2[24][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr2[26][0]=='b'&&playr2[27][0]=='b'&&playr2[29][0]=='b')
        { cout<<"You own "<<prop[26][0]<<" and "<<prop[27][0]<<" and "<<prop[29][0]<<endl;
         cout<<"Press o to place a house on "<<prop[6][0]<<" and v for "<<prop[8][0]<<" and c for "<<prop[9][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr2[26][1]!='b')
             playr2[26][1]='b';
         else if(playr2[26][2]!='b')
             playr2[26][2]='b';
         else if(playr2[26][3]!='b')
             playr2[26][3]='b';
         else if(playr2[26][4]!='b')
              playr2[26][4]='b';
         else if(playr2[26][5]!='b')
             playr2[26][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr2[27][1]!='b')
             playr2[27][1]='b';
         else if(playr2[27][2]!='b')
             playr2[27][2]='b';
         else if(playr2[27][3]!='b')
             playr2[27][3]='b';
         else if(playr2[27][4]!='b')
              playr2[27][4]='b';
         else if(playr2[27][5]!='b')
             playr2[27][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr2[29][1]!='b')
             playr2[29][1]='b';
         else if(playr2[29][2]!='b')
             playr2[29][2]='b';
         else if(playr2[29][3]!='b')
             playr2[29][3]='b';
         else if(playr2[29][4]!='b')
              playr2[29][4]='b';
         else if(playr2[29][5]!='b')
             playr2[29][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr2[31][0]=='b'&&playr2[32][0]=='b'&&playr2[34][0]=='b')
        { cout<<"You own "<<prop[31][0]<<" and "<<prop[32][0]<<" and "<<prop[34][0]<<endl;
         cout<<"Press o to place a house on "<<prop[31][0]<<" and v for "<<prop[32][0]<<" and c for "<<prop[34][0];
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr2[31][1]!='b')
             playr2[31][1]='b';
         else if(playr2[31][2]!='b')
             playr2[31][2]='b';
         else if(playr2[31][3]!='b')
             playr2[31][3]='b';
         else if(playr2[31][4]!='b')
              playr2[31][4]='b';
         else if(playr2[31][5]!='b')
             playr2[31][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr2[32][1]!='b')
             playr2[32][1]='b';
         else if(playr2[32][2]!='b')
             playr2[32][2]='b';
         else if(playr2[32][3]!='b')
             playr2[32][3]='b';
         else if(playr2[32][4]!='b')
              playr2[32][4]='b';
         else if(playr2[32][5]!='b')
             playr2[32][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
           if(house=='c'||house=='C')
         { if(playr2[34][1]!='b')
             playr2[34][1]='b';
         else if(playr2[34][2]!='b')
             playr2[34][2]='b';
         else if(playr2[34][3]!='b')
             playr2[34][3]='b';
         else if(playr2[34][4]!='b')
              playr2[34][4]='b';
         else if(playr2[34][5]!='b')
             playr2[34][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
        if(playr2[37][0]=='b'&&playr2[39][0]=='b')
        { cout<<"You own "<<prop[37][0]<<" and "<<prop[39][0]<<endl;
         cout<<"Press o to place a house on "<<prop[37][0]<<" and v for "<<prop[39][0]<<endl;
         cin>>house;
         if(house=='o'||house=='O')
         { if(playr2[37][1]!='b')
             playr2[37][1]='b';
         else if(playr2[37][2]!='b')
             playr2[37][2]='b';
         else if(playr2[37][3]!='b')
             playr2[37][3]='b';
         else if(playr2[37][4]!='b')
              playr2[37][4]='b';
         else if(playr2[37][5]!='b')
             playr2[37][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }
         if(house=='v'||house=='V')
         { if(playr2[39][1]!='b')
             playr2[39][1]='b';
         else if(playr2[39][2]!='b')
             playr2[39][2]='b';
         else if(playr2[39][3]!='b')
             playr2[39][3]='b';
         else if(playr2[39][4]!='b')
              playr2[39][4]='b';
         else if(playr2[39][5]!='b')
             playr2[39][5]='b';
         else
             cout<<"You  cannot put a house here"<<endl;
         }

}
    }}

}