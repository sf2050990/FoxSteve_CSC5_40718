/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 22, 2015, 10:05 AM
 * Purpose: Gaddis_7th_ED_Chap_7_Prob_16
 *          2D Array operations
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
void getTotal(int[][5]);                            //Function prototype to get total amount in the Array
void getAverage(int[][5]);                          //Function prototype to get Average in the Array
void getRowTotal(int[][5],int);                     //Function prototype to get total amount in a row
void getColumnTotal(int[][5],int);                  //Function prototype to get total amount in the a column
void getHighestInRow(int[][5],int);                 //Function prototype to get the highest number is a row
void getLowestInRow(int[][5],int);                  //Function prototype to get the lowest number is a row

//Execution Begins Here!
int main() 
{
    //Declare variable
    int array[10][5]={{10, 20, 90, 62, 3},     //two dimensional array with ten rows and five columns 
                     {20, 9, 12, 70, 33},
                     {33, 80, 8, 33, 15},
                     {12, 77, 12, 66, 7},
                     {5, 88, 50, 99, 20},
                     {63, 32, 55, 10, 36},
                     {28, 9, 42, 78, 86},
                     {55, 23, 99, 46, 12},
                     {70, 8, 66, 37, 40},
                     {40, 65, 77, 32, 55}};
    int row;                                    //Holds a given row 
    int col;                                    //Holds a given column
    int highrow;                                //Holds a given rows highest number
    int highcol;                                //Holds a given rows Lowest number
    
   //Function call to calculate total in array
   getTotal(array);
   ///Function call to calculate average number in an array
   getAverage(array);
   
   //Prompt user to enter rows and columns to calculate row total, column total, highest number is a row,
   //and lowest number in a row
   cout<<"Please enter a row you wish to calculate the total. The number should"<<endl;
   cout<<"Between one and ten."<<endl;
   cin>>row;
   //Function call to get row total
   getRowTotal(array,row-1);
   cout<<"Please enter a column you wish to calculate the total. The number should"<<endl;
   cout<<"Between one and five."<<endl;
   cin>>col;
   //Function call to get column total
   getColumnTotal(array,col-1);
   cout<<"Please enter a row you wish view the highest number. The number should"<<endl;
   cout<<"Between one and ten."<<endl;
   cin>>highrow;
   //Function call to find the highest number in a given row
   getHighestInRow(array,highrow-1);
   cout<<"Please enter a row you wish view the lowest number. The number should"<<endl;
   cout<<"Between one and ten."<<endl;
   cin>>highcol;
   //Function call to find the lowest number in a given row
   getLowestInRow(array,highcol-1);
  
   //Exit Program
    return 0;
}
//getTotal Function
void getTotal(int array[][5])
{
    //Declare variables
    int total=0;
    
    //Loops to cycle through rows
    for(int row=0; row<10; row++)
    {
        //Loops through columns
        for(int col=0;col<5;col++)
            //Accumulates total amount in the array 
            total+=array[row][col];
    }
    //Output total value
    cout<<"The total values in the array is "<<total<<endl;
}
//getAverage Function
void getAverage(int array[][5])
{
    //Declare variables
    int total=0;                    //Accumulator for calculating average
    float average;                  //Holds the average number in the array
    int count=0;                    //Counter
    //Loops to cycle through rows
    for(int row=0; row<10; row++)
    {
        //Loops to cycle through columns
        for(int col=0;col<5;col++)
        { 
            //Accumulates total in array
            total+=array[row][col];
            //Increments counter
            count++;
        }
    }
    //Calculates average
    average=total/count;
    cout<<"The average amount in the array is "<<average<<endl;
    
}
//getRowTotal Function
void getRowTotal(int array[][5],int num1)
{
    //Declare variables
    int total=0;                              //Accumulator for row total
    //Loops through a given row
    for (int row=num1;row<num1+1;row++)
    {
        //loops through columns in that row
        for(int col=0;col<5;col++)
            //Accumulates total in row
            total+=array[row][col];
    }
    //Outputs the total amount in a row
    cout<<"The total amount for the  row"<<num1+1<<" in an array is "<<total<<endl;
}
//getColumnTotal function
void getColumnTotal(int array[][5],int num1)
{
    int total=0;                              //Accumulator for column total
    //Loops through rows
    for(int row=0;row<10;row++ )
    {    //Loops through given column
         for(int col=num1;col<num1+1;col++)
         //Accumulates column total
         total+=array[row][col];
    }
    //Output total of the column
    cout<<"The total for column#"<<num1+1<< " is "<<total<<endl;
}
//getHighestInRow Function
void getHighestInRow(int array[][5],int num1)
{
    //Declare variables
    int count=0;                                       //Counter
    int highest=array[0][0];                           //Holds highest number in row
    //Loops through given row
    for (int row=num1;row<num1+1;row++)             
    {   //Loops through columns
        for(int col=0;col<5;col++)
        {      
           //Conditionally executes if a number is higher then highest variables and stores it in highest variable 
           if(array[num1][count]>highest)
        {  //Holds highest number in the given row
            highest=array[num1][count];
        } 
             //Increments counter
             count++;
        }
    }
    //Output the highest number is a row
    cout<<"The highest number in row #"<<num1+1<<" is "<<highest<<endl;
}
//getLowestInRow Function
void getLowestInRow(int array[][5],int num1)
{
    //Declare variables
    int count=0;                                      //Counter
    int lowest=array[0][0];                           //Stores beginning value in element 1 in lowest variable
    //Loops to cycle through a given row
    for (int row=num1;row<num1+1;row++)
    {
        //Loops to cycle through columns
        for(int col=0;col<5;col++)
        {      
        //Conditionally executes if a number is lower than lowest variable and stores that value in lowest    
        if(array[num1][count]<lowest)
        {
            lowest=array[num1][count];
        }
             count++;
        }
    }
    //Outputs lowest number in a row
    cout<<"The lowest number in row #"<<num1+1<<" is "<<lowest<<endl;
    
}