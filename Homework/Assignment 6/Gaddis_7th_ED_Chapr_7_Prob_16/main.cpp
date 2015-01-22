/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 22, 2015, 10:05 AM
 * Purpose: Gaddis_7th_ED_Chap_7_Prob_16
 *          2D operations
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
void getTotal(int[][5]);
void getAverage(int[][5]);
void getRowTotal(int[][5],int);
void getColumnTotal(int[][5],int);
void getHighestInRow(int[][5],int);
void getLowestInRow(int[][5],int);

//Execution Begins Here!

int main(int argc, char** argv) 
{
    int array[10][5]=      {{10, 20, 90, 62, 3}, 
                            {20, 9, 12, 70, 33},
                            {33, 80, 8, 33, 15},
                            {12, 77, 12, 66, 7},
                            {5, 88, 50, 99, 20},
                            {63, 32, 55, 10, 36},
                            {28, 9, 42, 78, 86},
                            {55, 23, 99, 46, 12},
                            {70, 8, 66, 37, 40},
                            {40, 65, 77, 32, 55}};
   getTotal(array);
   getAverage(array);
   getRowTotal(array,0);
   getColumnTotal(array,3);
   getHighestInRow(array,3);
   getLowestInRow(array,3);
  
    return 0;
}

void getTotal(int array[][5])
{
    int total=0;
    
    for(int row=0; row<10; row++)
    {
        for(int col=0;col<5;col++)
            total+=array[row][col];
    }
    cout<<"The total values in the array is "<<total<<endl;
}
void getAverage(int array[][5])
{
    int total=0;
    float average;
    int count=0;
    for(int row=0; row<10; row++)
    {
        for(int col=0;col<5;col++)
        { total+=array[row][col];
            count++;
        }
    }
    average=total/count;
    cout<<"The average amount in the array is "<<average<<endl;
    
}
void getRowTotal(int array[][5],int num1)
{
    int total=0;
    for (int row=num1;row<num1+1;row++)
    {
        for(int col=0;col<5;col++)
            total+=array[row][col];
    }
    
    cout<<"The total amount for the first row in an array is "<<total<<endl;
}
void getColumnTotal(int array[][5],int num1)
{
    int total=0;
    
    for(int row=0;row<10;row++)
           
    { for(int col=num1;col<4;col++)
         total+=array[row][col];
    }
    
    cout<<"The total for column#"<<num1+1<< " is "<<total<<endl;
}
void getHighestInRow(int array[][5],int num1)
{
    int count=0;
    int highest=array[0][0];
    for (int row=num1;row<num1+1;row++)
    {
        for(int col=0;col<5;col++)
        {      
        if(array[num1][count]>highest)
        {
            highest=array[num1][count];
        }
             count++;
        }
    }
    cout<<"The highest number in row #"<<num1+1<<" is "<<highest<<endl;
}
void getLowestInRow(int array[][5],int num1)
{
    int count=0;
    int lowest=array[0][0];
    for (int row=num1;row<num1+1;row++)
    {
        for(int col=0;col<5;col++)
        {      
        if(array[num1][count]<lowest)
        {
            lowest=array[num1][count];
        }
             count++;
        }
    }
    cout<<"The lowest number in row #"<<num1+1<<" is "<<lowest<<endl;
    
}