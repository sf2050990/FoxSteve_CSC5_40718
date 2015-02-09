/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 6, 2015, 6:05 PM
 * Purpose: Our first program
 * I am at github
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
float sum(float[][6],float[][6],int);
float total(float [][6],int);
float difQuar(float,float,int,int);

//Function Prototype

//Execution Begins Here!

int main() 
{
    float sales[4][6];
    float div1;
    float div2;
    float div3;
    float div4;
    for(int row=0;row<4;row++)
    {
        for(int col=0;col<6;col++)
        {
            cout<<"Enter Quarter #"<<row+1<<" Division #"<<col+1<<" Sales."<<endl;
            cin>>sales[row][col];
        }
    }
    for(int row=0;row<4;row++)
    {
        for(int col=0; col<6;col++)
        {
            cout<<"Quarter #"<<row+1<<" Division #"<<col+1<<"  "<<sales[row][col]<<endl;
        }
    }
    
   sum(sales,sales,0);
   sum(sales,sales,1);
   sum(sales,sales,2);
   div1=total(sales,0);
   div2=total(sales,1);
   div3=total(sales,2);
   div4=total(sales,3);
   difQuar(div1,div2,1,2);
   difQuar(div2, div3,2,3);
   difQuar(div3,div4,3,4);
  

 
    
 
            
    return 0;
}
float sum(float num[][6],float num2[][6],int row)
{

   
        for(int cols=0;cols<6;cols++)
        {   
           
           cout<<"The difference between Quarter #"<<row+1<<"Division #"<<cols+1<<" and Quarter #";
           cout<<row+2<<"Division #"<<cols+1<<" is "<<num[row+1][cols]-num2[row][cols]<<endl;         
        }
}
float total(float sales[][6], int row)
{
    int total=0;
    for(int count=0; count<6; count++)
    total+=sales[row][count];
        
            cout<<"The total sales for quarter #"<<row+1<< " is "<< total<<endl;
            return total;
}
float difQuar(float num1,float num2, int num3, int num4)
{
    float total=num2-num1;
    cout<<"The difference between Quarter #"<<num3<< " and Quarter #"<<num4<<" is "<<total<<endl;
   
}
