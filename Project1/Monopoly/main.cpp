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

//Function Prototype
int rollDie(string [], char [][7],int&,int&, int );
char purp1(string[], char[][7],char [][7], int&,int&,bool);
int purp2(string[], char[][7],char[][7], int&,int&,bool);
int teal1(string[], int[][6],char[][7],char[][7], int&,int&, bool);
int teal2(string[],int [][6],char[][7],char[][7], int&,int&,int);
int teal3(string[], int [][6],char[][7],char[][7], int&,int&,int);
int pink1(string[], int [][6],char[][7], char[][7],int&,int&,int);
int pink2(string[], int[][6],char[][7],char[][7], int&,int&,int);
int pink3(string[], char[][7],char[][7], int&,int&,int);
int orange1(string[], char[][7],char[][7], int&,int&,int);
int orange2(string[], char[][7],char[][7], int&,int&,int);
int orange3(string[], char[][7],char[][7], int&,int&,int);
int red1(string[], char[][7],char[][7], int&,int&,int);
int red2(string[], char[][7],char[][7], int&,int&,int);
int red3(string[], char[][7], char[][7],int&,int&,int);
int yellow1(string[], char[][7],char[][7], int&,int&,int);
int yellow2(string[], char[][7],char[][7], int&,int&,int);
int yellow3(string[], char[][7],char[][7], int&,int&,int);
int green1(string[], char[][7],char[][7], int&,int&,int);
int green2(string[], char[][7],char[][7], int&,int&,int);
int green3(string[], char[][7],char[][7], int&,int&,int);
int blue1(string[], char[][7],char[][7], int&,int&,int);
int blue2(string[], char[][7],char[][7], int&,int&,int);
int start(string[], char[][7],char[][7], int&,int&,int);
int chance(string[], char[][7], char[][7],int&,int&,int);
int comChest(string[], char[][7],char[][7], int&,int&,int);
int incTax(string[], char[][7],char[][7], int&,int&,int);
int luxTax(string[], char[][7],char[][7], int&,int&,int);
int jail(string[], char[][7],char[][7], int&,int&,int);
int goToJail(string[], char[][7],char[][7], int&,int&,int);
int rr1(string[], char[][7],char[][7], int&,int&,int);
int rr2(string[], char[][7],char[][7], int&,int&,int);
int rr3(string[], char[][7],char[][7], int&,int&,int);
int rr4(string[], char[][7], char[][7],int&,int&,int);
int elecCom(string[], char[][7],char[][7], int&,int&,int);
int watWork(string[], char[][7], char[][7],int&,int&,int);
int frePark(string[], char[][7], char[][7],int&,int&,int);



//Execution Begins Here!

int main()
{
    string prop[40];
   char playr1[40][7];
   char playr2[40][7];
    int bank1=2000;
    int bank2=2000;
    int player1=0;
    int player2=0;
    int rent[40][6];
    int count=0;
    
    char ch;
    
    cout<<"Welcome to the game of Monopoly where fortunes are won....and Lost"<<endl;
    cout<<"How far will your bank roll take you."<<endl;
    
    ifstream inputFile;
    inputFile.open("C:\\Users\\Invictus1\\Desktop\\sf2050990\\FoxSteve_CSC5_40718\\Project1\\Properties.txt");
    while(count<40&&inputFile>>prop[count])
    count++;
    inputFile.close();
    
     ifstream inputfile;
    inputfile.open("C:\\Users\\Invictus1\\Desktop\\sf2050990\\FoxSteve_CSC5_40718\\Project1\\rent.txt");
    for(int row=0;row<40;row++)   
    {
        for(int cols=0;cols<6;cols++)
            inputfile>>rent[row][cols];
    }
    inputfile.close();
    
    for(int row=0;row<39;row++)
    {
        for(int col=0; col<7;col++)
        { playr1[row][col]='?';}
    }
        for(int row=0;row<39;row++)
    {
        for(int col=0; col<7;col++)
        { playr2[row][col]='?';}
    }
       
    
    
    
    do
    {
        bool turn=false;
        if(turn==false)
        {  
          cout<<"Player One it is turn. Press enter to continue."<<endl;
          cin.get(ch);
          player1+=rollDie(prop, playr1, bank1,bank2, turn);    
          cout<<"Player 1 "<<player1<<endl;
          
          pink2(prop,rent,playr1,playr2,bank1,bank2,turn);
          cout<<"bank 1 "<<bank1<<endl;
     for(int row=0;row<39;row++)
         {
        for(int col=0; col<7;col++)
        { cout<<playr1[row][col];}
             }
          if(player1>39)
        { player1-=39;
          cout<<"Player 1 Passed Go!!Collect $200!!"<<endl;
          cout<<"Player 1  "<<player1<<endl;
         bank1+=200;}}
        
           if (player1==0)
                  start(prop, playr1,playr2, bank1,bank2,turn);
           else if(player1==1)
                 purp1(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==2)
                  comChest(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==3)
                   purp2(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==4)
                incTax(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==5)
                rr1(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==6)
                teal1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player1==7)
                teal2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==8)
                chance(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==9)
                teal3(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==10)
                jail(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==11)
                pink1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player1==12)
                elecCom(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==13)
                pink2(prop,rent, playr1,playr2,bank1,bank2,turn);
            else if(player1==14)
                pink3(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==15)
                rr2(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==16)
                orange1(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==17)
                comChest(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==18)
                orange2(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==19)
                orange3(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==20)
                frePark(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==21)
                red1(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==22)
                chance(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==23)
                red2(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==24)
                red3(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==25)
                rr3(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==26)
                yellow1(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==27)
               yellow2(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==28)
                watWork(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==29)
                yellow3(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==30)
                goToJail(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==31)
                green1(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==32)
                green2(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==33)
                comChest(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==34)
                green3(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==35)
               rr4(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==36)
               chance(prop, playr1,playr2,bank1,bank2,turn);
            else if(player1==37)
               blue1(prop, playr1,playr2,bank1,bank2,turn);
           else if(player1==38)
                luxTax(prop, playr1,playr2,bank1,bank2,turn);
           else if(player1==39)
               blue2(prop, playr1,playr2,bank1,bank2,turn);
           else
             cout<<"ERROR. Somthing Went Wrong!!!"<<endl;
        
           turn=true;
        
    if(turn=true)
        {   
            cout<<"Player Two it is your turn. Press Enter to continue"<<endl;
            cin.get(ch);
            player2+=rollDie(prop, playr2,bank1,bank2, turn);
            cout<<"Player 2 "<<player2<<endl;
          pink2(prop,rent,playr1,playr2,bank1,bank2,turn);
          cout<<"Bank 2 "<<bank2<<endl;
      if(player2>39)
        {player2-=39;
        cout<<"Player 2 Passed Go!!Collect $200!!"<<endl;
         cout<<"Player 2  "<<player2<<endl; 
        bank2+=200;}}
            if (player2==0)
                start(prop,playr1, playr2, bank1,bank2,turn);
            else if(player2==1)
                  purp1(prop,playr1,  playr2,bank1,bank2,turn);
            else if(player2==2)
                  comChest(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==3)
                   purp2(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==4)
                incTax(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==5)
                rr1(prop,playr1, playr2,bank1,bank2,turn);
            else if(player2==6)
                teal1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==7)
                teal2(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==8)
                chance(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==9)
                teal3(prop,rent,playr1, playr2,bank1,bank2,turn);
            else if(player2==10)
                jail(prop,playr1, playr2,bank1,bank2,turn);
            else if(player2==11)
                pink1(prop,rent,playr1,playr2,bank1,bank2,turn);
            else if(player2==12)
                elecCom(prop,playr1, playr2,bank1,bank2,turn);
            else if(player2==13)
                pink2(prop,rent,playr1, playr2,bank1,bank2,turn);
            else if(player2==14)
                pink3(prop,playr1, playr2,bank1,bank2,turn);
            else if(player2==15)
                rr2(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==16)
                orange1(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==17)
                comChest(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==18)
                orange2(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==19)
                orange3(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==20)
                frePark(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==21)
                red1(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==22)
                chance(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==23)
                red2(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==24)
                red3(prop, playr1,playr2,bank1,bank2,turn);
            else if(player2==25)
                rr3(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==26)
                yellow1(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==27)
               yellow2(prop,playr1, playr2,bank1,bank2,turn);
            else if(player2==28)
                watWork(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==29)
                yellow3(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==30)
                goToJail(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==31)
                green1(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==32)
                green2(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==33)
                comChest(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==34)
                green3(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==35)
               rr4(prop,playr1, playr2,bank1,bank2,turn);
            else if(player2==36)
               chance(prop,playr1,playr2,bank1,bank2,turn);
            else if(player2==37)
               blue1(prop,playr1,playr2,bank1,bank2,turn);
           else if(player2==38)
                luxTax(prop,playr1,playr2,bank1,bank2,turn);
           else if(player2==39)
               blue2(prop,playr1, playr2,bank1,bank2,turn);
           else
               cout<<"ERROR. Somthing Went Wrong!!!"<<endl;
    }while(true);
    return 0;
}

int rollDie(string prop [], char player[][7], int &bank1, int &bank2, int turn)
{
    int die1;
    int die2;
    int sum;
    int total;
    unsigned seed=static_cast<int>(time(0));
    srand(seed);
   
    do
    {
       die1=rand()%6+1;
       die2=rand()%6+1;
       sum=die1+die2;
    
    if(die1==die2)
        cout<<"You got doubles!! You get to go again!!"<<endl;
        cout<<"You rolled a "<<die1<<" and "<<die2<<" which equals "<<sum<<endl;
        return sum;
        total+=sum;
        
    
    }while(die1==die2);
    return total;
}
char purp1(string prop[], char playr1[][7], char playr2[][7], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;
    int rate=60;
    char choice;
    int rent=2;
    int house1=10;
    int house2=30;
    int house3=90;
    int house4=160;
    int hotel=250;
    
    cout<<"Welcome to "<<prop[1]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[1][0]='b';
            cout<<"Player 1 Bought "<<prop[1]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[1][0]=='b')      
        cout<<"You already own this property"<<endl;
    
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b'&&playr2[1][3]=='b'&&playr2[1][4]=='b'&&playr2[1][5]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 1 is charged $60"<<endl;
    bank1-=260;
    bank2+=260;}
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b'&&playr2[1][3]=='b'&&playr2[1][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 1 is charged $60"<<endl;
    bank1-=160;
    bank2+=160;}
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b'&&playr2[1][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[1]<<" Player 1 is charged $90"<<endl;
    bank1-=90;
    bank2+=90;}
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b'&&playr2[1][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[1]<<" Player 1 is charged $30"<<endl;
    bank1-=30;
    bank2+=30;}
    else if(turn==false&&buy==true&&playr2[1][0]=='b'&&playr2[1][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[1]<<" Player 1 is charged $10"<<endl;
    bank1-=10;
    bank2+=10;}
    
    else if(turn==false&&buy==true&&playr2[1][0]=='b')
    { cout<<"Your opponent owns "<<prop[1]<< " Player 1 is charged $2"<<endl;
    bank1-=2;
    bank2+=2;}
    
    else
        cout<<""<<endl;
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[1][0]='b';
            cout<<"Player 2 Bought "<<prop[1]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[1][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b'&&playr1[1][3]=='b'&&playr1[1][4]=='b'&&playr1[1][5]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 2 is charged $60"<<endl;
    bank2-=260;
    bank1+=260;}
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b'&&playr1[1][3]=='b'&&playr1[1][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 2 is charged $60"<<endl;
    bank2-=160;
    bank1+=160;}
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b'&&playr1[1][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[1]<<" Player 2 is charged $90"<<endl;
    bank2-=90;
    bank1+=90;}
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b'&&playr1[1][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[1]<<" Player 2 is charged $30"<<endl;
    bank2-=30;
    bank1+=30;}
    else if(turn==true&&buy==true&&playr1[1][0]=='b'&&playr1[1][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[1]<<" Player 2 is charged $10"<<endl;
    bank2-=10;
    bank1+=10;}
    
    else if(turn==true&&buy==true&&playr1[1][0]=='b')
    { cout<<"Your opponent owns "<<prop[1]<< " Player 2 is charged $2"<<endl;
    bank2-=2;
    bank1+=2;}
    else
        cout<<""<<endl;
}
int purp2(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;
    int rate=60;
    char choice;
    int house1=10;
    int house2=30;
    int house3=90;
    int house4=160;
    int hotel=250;
    
    cout<<"Welcome to "<<prop[3]<<endl;
    if(turn==false&&buy==false)
    {  cout<<"Player one this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
         if(choice=='y'||choice=='Y')
        {   buy=true;
            bank1-=rate;
            playr1[3][0];
            cout<<"Player 1 Bought "<<prop[3]<<endl;}}
            
    
    else if(turn==false&&buy==true&&playr1[3][0]=='b')      
        cout<<"You already own this property"<<endl;
    
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b'&&playr2[3][3]=='b'&&playr2[3][4]=='b'&&playr2[3][5]=='b')
    { cout<<"Your opponent has a hotel on this "<<prop[1]<<" Player 1 is charged $460"<<endl;
    bank1-=460;
    bank2+=460;}
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b'&&playr2[3][3]=='b'&&playr2[3][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 1 is charged $320"<<endl;
    bank1-=320;
    bank2+=320;}
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b'&&playr2[3][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[1]<<" Player 1 is charged $180"<<endl;
    bank1-=180;
    bank2+=180;}
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b'&&playr2[3][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[1]<<" Player 1 is charged $60"<<endl;
    bank1-=60;
    bank2+=60;}
    else if(turn==false&&buy==true&&playr2[3][0]=='b'&&playr2[3][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[1]<<" Player 1 is charged $20"<<endl;
    bank1-=20;
    bank2+=20;}
    
    else if(turn==false&&buy==true&&playr2[3][0]=='b')
    { cout<<"Your opponent owns "<<prop[3]<< " Player 1 is charged $2"<<endl;
    bank1-=4;
    bank2+=4;}
  else 
        cout<<""<<endl;
    
    
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[3][0]='b';
            cout<<"Player 2 Bought "<<prop[1]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[3][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b'&&playr1[3][3]=='b'&&playr1[3][4]=='b'&&playr1[3][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[1]<<" Player 2 is charged $450"<<endl;
    bank2-=450;
    bank1+=450;}
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b'&&playr1[3][3]=='b'&&playr1[3][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[1]<<" Player 2 is charged $320"<<endl;
    bank2-=320;
    bank1+=320;}
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b'&&playr1[3][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[1]<<" Player 2 is charged $180"<<endl;
    bank2-=180;
    bank1+=180;}
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b'&&playr1[3][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[1]<<" Player 2 is charged $60"<<endl;
    bank2-=60;
    bank1+=60;}
    else if(turn==true&&buy==true&&playr1[3][0]=='b'&&playr1[3][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[1]<<" Player 2 is charged $20"<<endl;
    bank2-=20;
    bank1+=20;}
    
    else if(turn==true&&buy==true&&playr1[3][0]=='b')
    { cout<<"Your opponent owns "<<prop[3]<< " Player 2 is charged $2"<<endl;
    bank2-=4;
    bank1+=4;}
    else
        cout<<""<<endl;
    
}
int teal1(string prop[],int rent[][6],char playr1[][7], char playr2[][7], int &bank1,int &bank2,bool turn)
{
    static bool buy=false;
    int rate=100;
    char choice;
    
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
    
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b'&&playr2[6][3]=='b'&&playr2[6][4]=='b'&&playr2[6][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[6]<<" Player 1 is charged $"<<rent[6][5]<<endl;
    bank1-=rent[6][5];
    bank2+=rent[6][5];}
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b'&&playr2[6][3]=='b'&&playr2[6][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[6]<<" Player 1 is charged "<<rent[6][4]<<endl;
    bank1-=rent[6][4];
    bank2+=rent[6][4];}
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b'&&playr2[6][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[6]<<" Player 1 is charged $"<<rent[6][3]<<endl;
    bank1-=rent[6][3];
    bank2+=rent[6][3];}
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b'&&playr2[6][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[6]<<" Player 1 is charged $"<<rent[6][2]<<endl;
    bank1-=rent[6][2];
    bank2+=rent[6][2];}
    else if(turn==false&&buy==true&&playr2[6][0]=='b'&&playr2[6][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[6]<<" Player 1 is charged $"<<rent[6][1]<<endl;
    bank1-=rent[6][1];
    bank2+=rent[6][1];}
    
    else if(turn==false&&buy==true&&playr2[3][0]=='b')
    { cout<<"Your opponent owns "<<prop[3]<< " Player 1 is charged $"<<rent[6][0]<<endl;
    bank1-=rent[6][0];
    bank2+=rent[6][0];}
  else 
        cout<<""<<endl;
    
    
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[6][0]='b';
            cout<<"Player 2 Bought "<<prop[6]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[6][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b'&&playr1[6][3]=='b'&&playr1[6][4]=='b'&&playr1[6][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][5]<<endl;
    bank2-=rent[6][5];
    bank1+=rent[6][5];}
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b'&&playr1[6][3]=='b'&&playr1[6][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][4]<<endl;
    bank2-=rent[6][4];
    bank1+=rent[6][4];}
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b'&&playr1[6][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][3]<<endl;
    bank2-=rent[6][3];
    bank1+=rent[6][3];}
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b'&&playr1[6][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][2]<<endl;
    bank2-=rent[6][2];
    bank1+=rent[6][2];}
    else if(turn==true&&buy==true&&playr1[6][0]=='b'&&playr1[6][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[6]<<" Player 2 is charged $"<<rent[6][1]<<endl;
    bank2-=rent[6][1];
    bank1+=rent[6][1];}
    
    else if(turn==true&&buy==true&&playr1[6][0]=='b')
    { cout<<"Your opponent owns "<<prop[6]<< " Player 2 is charged $"<<rent[6][0]<<endl;
    bank2-=rent[6][0];
    bank1+=rent[6][0];}
    else
        cout<<""<<endl;

    
    
}
int teal2(string prop [],int rent[][6],  char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    static bool buy=false;
    int rate=100;
    char choice;
    
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
    
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b'&&playr2[7][3]=='b'&&playr2[7][4]=='b'&&playr2[7][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[7]<<" Player 1 is charged $"<<rent[7][5]<<endl;
    bank1-=rent[7][5];
    bank2+=rent[7][5];}
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b'&&playr2[7][3]=='b'&&playr2[7][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[7]<<" Player 1 is charged "<<rent[7][4]<<endl;
    bank1-=rent[7][4];
    bank2+=rent[7][4];}
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b'&&playr2[7][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[7]<<" Player 1 is charged $"<<rent[7][3]<<endl;
    bank1-=rent[7][3];
    bank2+=rent[7][3];}
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b'&&playr2[7][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[7]<<" Player 1 is charged $"<<rent[7][2]<<endl;
    bank1-=rent[7][2];
    bank2+=rent[7][2];}
    else if(turn==false&&buy==true&&playr2[7][0]=='b'&&playr2[7][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[7]<<" Player 1 is charged $"<<rent[7][1]<<endl;
    bank1-=rent[7][1];
    bank2+=rent[7][1];}
    
    else if(turn==false&&buy==true&&playr2[7][0]=='b')
    { cout<<"Your opponent owns "<<prop[7]<< " Player 1 is charged $"<<rent[7][0]<<endl;
    bank1-=rent[7][0];
    bank2+=rent[7][0];}
  else 
        cout<<""<<endl;
    
    
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[7][0]='b';
            cout<<"Player 2 Bought "<<prop[7]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[7][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b'&&playr1[7][3]=='b'&&playr1[7][4]=='b'&&playr1[7][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][5]<<endl;
    bank2-=rent[7][5];
    bank1+=rent[7][5];}
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b'&&playr1[7][3]=='b'&&playr1[7][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][4]<<endl;
    bank2-=rent[7][4];
    bank1+=rent[7][4];}
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b'&&playr1[7][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][3]<<endl;
    bank2-=rent[7][3];
    bank1+=rent[7][3];}
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b'&&playr1[7][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[7]<<" Player 2 is charged $"<<rent[7][2]<<endl;
    bank2-=rent[7][2];
    bank1+=rent[7][2];}
    else if(turn==true&&buy==true&&playr1[7][0]=='b'&&playr1[7][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[7]<<" Player 2 is charged $"<<rent[6][1]<<endl;
    bank2-=rent[7][1];
    bank1+=rent[7][1];}
    
    else if(turn==true&&buy==true&&playr1[7][0]=='b')
    { cout<<"Your opponent owns "<<prop[7]<< " Player 2 is charged $"<<rent[7][0]<<endl;
    bank2-=rent[7][0];
    bank1+=rent[7][0];}
    
    else
        cout<<""<<endl;
   
}
int teal3(string prop [], int rent[][6],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    static bool buy=false;
    int rate=120;
    char choice;
    
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
    
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b'&&playr2[9][3]=='b'&&playr2[9][4]=='b'&&playr2[9][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[9]<<" Player 1 is charged $"<<rent[9][5]<<endl;
    bank1-=rent[9][5];
    bank2+=rent[9][5];}
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b'&&playr2[9][3]=='b'&&playr2[9][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[9]<<" Player 1 is charged "<<rent[9][4]<<endl;
    bank1-=rent[9][4];
    bank2+=rent[9][4];}
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b'&&playr2[9][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][3]<<endl;
    bank1-=rent[9][3];
    bank2+=rent[9][3];}
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b'&&playr2[9][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][2]<<endl;
    bank1-=rent[9][2];
    bank2+=rent[9][2];}
    else if(turn==false&&buy==true&&playr2[9][0]=='b'&&playr2[9][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][1]<<endl;
    bank1-=rent[9][1];
    bank2+=rent[9][1];}
    
    else if(turn==false&&buy==true&&playr2[9][0]=='b')
    { cout<<"Your opponent owns "<<prop[9]<< " Player 1 is charged $"<<rent[9][0]<<endl;
    bank1-=rent[9][0];
    bank2+=rent[9][0];}
  else 
        cout<<""<<endl;
    
    
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[9][0]='b';
            cout<<"Player 2 Bought "<<prop[9]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[9][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b'&&playr1[9][3]=='b'&&playr1[9][4]=='b'&&playr1[9][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][5]<<endl;
    bank2-=rent[9][5];
    bank1+=rent[9][5];}
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b'&&playr1[9][3]=='b'&&playr1[9][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[9]<<" Player 2 is charged $"<<rent[7][9]<<endl;
    bank2-=rent[9][4];
    bank1+=rent[9][4];}
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b'&&playr1[9][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][3]<<endl;
    bank2-=rent[9][3];
    bank1+=rent[9][3];}
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b'&&playr1[9][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][2]<<endl;
    bank2-=rent[9][2];
    bank1+=rent[9][2];}
    else if(turn==true&&buy==true&&playr1[9][0]=='b'&&playr1[9][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[9]<<" Player 2 is charged $"<<rent[9][1]<<endl;
    bank2-=rent[9][1];
    bank1+=rent[9][1];}
    
    else if(turn==true&&buy==true&&playr1[9][0]=='b')
    { cout<<"Your opponent owns "<<prop[9]<< " Player 2 is charged $"<<rent[9][0]<<endl;
    bank2-=rent[9][0];
    bank1+=rent[9][0];}
    
    else
        cout<<""<<endl;
 
}
int pink1(string prop [],int rent[][6], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    static bool buy=false;
    int rate=140;
    char choice;
    
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
    
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b'&&playr2[11][3]=='b'&&playr2[11][4]=='b'&&playr2[11][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[11]<<" Player 1 is charged $"<<rent[11][5]<<endl;
    bank1-=rent[11][5];
    bank2+=rent[11][5];}
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b'&&playr2[11][3]=='b'&&playr2[11][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[11]<<" Player 1 is charged "<<rent[11][4]<<endl;
    bank1-=rent[11][4];
    bank2+=rent[11][4];}
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b'&&playr2[11][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[11]<<" Player 1 is charged $"<<rent[11][3]<<endl;
    bank1-=rent[11][3];
    bank2+=rent[11][3];}
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b'&&playr2[11][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 1 is charged $"<<rent[11][2]<<endl;
    bank1-=rent[11][2];
    bank2+=rent[11][2];}
    else if(turn==false&&buy==true&&playr2[11][0]=='b'&&playr2[11][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[9]<<" Player 1 is charged $"<<rent[9][1]<<endl;
    bank1-=rent[11][1];
    bank2+=rent[11][1];}
    
    else if(turn==false&&buy==true&&playr2[9][0]=='b')
    { cout<<"Your opponent owns "<<prop[11]<< " Player 1 is charged $"<<rent[11][0]<<endl;
    bank1-=rent[11][0];
    bank2+=rent[11][0];}
  else 
        cout<<""<<endl;
    
    
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[11][0]='b';
            cout<<"Player 2 Bought "<<prop[11]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[11][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b'&&playr1[11][3]=='b'&&playr1[11][4]=='b'&&playr1[11][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][5]<<endl;
    bank2-=rent[11][5];
    bank1+=rent[11][5];}
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b'&&playr1[11][3]=='b'&&playr1[11][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][9]<<endl;
    bank2-=rent[11][4];
    bank1+=rent[11][4];}
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b'&&playr1[11][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][3]<<endl;
    bank2-=rent[11][3];
    bank1+=rent[11][3];}
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b'&&playr1[11][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][2]<<endl;
    bank2-=rent[11][2];
    bank1+=rent[11][2];}
    else if(turn==true&&buy==true&&playr1[11][0]=='b'&&playr1[11][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][1]<<endl;
    bank2-=rent[11][1];
    bank1+=rent[11][1];}
    
    else if(turn==true&&buy==true&&playr1[11][0]=='b')
    { cout<<"Your opponent owns "<<prop[11]<< " Player 2 is charged $"<<rent[11][0]<<endl;
    bank2-=rent[11][0];
    bank1+=rent[11][0];}
    
    else
        cout<<""<<endl;
    
}
int pink2(string prop [],int rent[][6],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    static bool buy=false;
    int rate=140;
    char choice;
    
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
    
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b'&&playr2[13][3]=='b'&&playr2[13][4]=='b'&&playr2[13][5]=='b')
    { cout<<"Your opponent has a hotel on  "<<prop[13]<<" Player 1 is charged $"<<rent[13][5]<<endl;
    bank1-=rent[13][5];
    bank2+=rent[13][5];}
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b'&&playr2[13][3]=='b'&&playr2[13][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[13]<<" Player 1 is charged "<<rent[13][4]<<endl;
    bank1-=rent[13][4];
    bank2+=rent[13][4];}
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b'&&playr2[13][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[13]<<" Player 1 is charged $"<<rent[13][3]<<endl;
    bank1-=rent[13][3];
    bank2+=rent[13][3];}
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b'&&playr2[13][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 1 is charged $"<<rent[13][2]<<endl;
    bank1-=rent[13][2];
    bank2+=rent[13][2];}
    else if(turn==false&&buy==true&&playr2[13][0]=='b'&&playr2[13][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[13]<<" Player 1 is charged $"<<rent[13][1]<<endl;
    bank1-=rent[13][1];
    bank2+=rent[13][1];}
    
    else if(turn==false&&buy==true&&playr2[13][0]=='b')
    { cout<<"Your opponent owns "<<prop[13]<< " Player 1 is charged $"<<rent[11][0]<<endl;
    bank1-=rent[13][0];
    bank2+=rent[13][0];}
  else 
        cout<<""<<endl;
    
    
    if(turn==true&&buy==false)
    {
        cout<<"Player two this property is not purchased yet. Would you like"<<endl;
        cout<<"to purchase this property for $60. Press Y for Yes and No for no."<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {  buy=true;
            bank2-=rate;
            playr2[13][0]='b';
            cout<<"Player 2 Bought "<<prop[13]<<endl;}}
            
    else if(turn==true&&buy==true&&playr2[13][0]=='b')      
        cout<<"You already own this property"<<endl;
        
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b'&&playr1[13][3]=='b'&&playr1[13][4]=='b'&&playr1[13][5]=='b')
    { cout<<"Your opponent has a Hotel on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][5]<<endl;
    bank2-=rent[13][5];
    bank1+=rent[13][5];}
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b'&&playr1[13][3]=='b'&&playr1[13][4]=='b')
    { cout<<"Your opponent has four house on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][9]<<endl;
    bank2-=rent[13][4];
    bank1+=rent[13][4];}
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b'&&playr1[13][3]=='b')
    { cout<<"Your opponent has three house on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][3]<<endl;
    bank2-=rent[13][3];
    bank1+=rent[13][3];}
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b'&&playr1[13][2]=='b')
    { cout<<"Your opponent has two house on this "<<prop[11]<<" Player 2 is charged $"<<rent[11][2]<<endl;
    bank2-=rent[13][2];
    bank1+=rent[13][2];}
    else if(turn==true&&buy==true&&playr1[13][0]=='b'&&playr1[13][1]=='b')
    { cout<<"Your opponent has one house on this "<<prop[13]<<" Player 2 is charged $"<<rent[13][1]<<endl;
    bank2-=rent[13][1];
    bank1+=rent[13][1];}
    
    else if(turn==true&&buy==true&&playr1[13][0]=='b')
    { cout<<"Your opponent owns "<<prop[13]<< " Player 2 is charged $"<<rent[13][0]<<endl;
    bank2-=rent[13][0];
    bank1+=rent[13][0];}
    
    else
        cout<<""<<endl;
    
}
int pink3(string prop [],  char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int orange1(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int orange2(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int orange3(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int red1(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int red2(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int red3(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int yellow1(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int yellow2(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int yellow3(string prop [], char playr1[][7], char playr2[][7],int &bank1,int &bank2,int turn)
{
    
}
int green1(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int green2(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int green3(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int blue1(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int blue2(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int chance(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int comChest(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int rr1(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int rr2(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int rr3(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int rr4(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int frePark(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int jail(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int goToJail(string prop [],char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int luxTax(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int incTax(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int watWork(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int elecCom(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}
int start(string prop [], char playr1[][7], char playr2[][7], int &bank1,int &bank2,int turn)
{
    
}