/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on February 8, 2015, 6:05 PM
 * Purpose: Gaddis_7th_ED_Chap_8_9
 *         Sorting Array's
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
void priArr(int []);                    //Function prototype for printing array;
void sortArr(int []);                  //Function prototype for sorting array using bubble sort
void sortArr2(int[]);                   //Function prototype for sorting array using selection sort
//Execution Begins Here!

int main(int argc, char** argv) {
    int array1[]= {19,33,85,98,45,66,21,7,69,12,78,32,58,62,10,9,78,96,11,56};     //Array 1 with twenty integers
     int array2[]= {19,33,85,98,45,66,21,7,69,12,78,32,58,62,10,9,78,96,11,56};    //second Array Identical to first
    
     
    //Function call to priArr Function and sortArr Function to display array contents
    cout<<"Array 1 Contents = ";
    priArr(array1);
    cout<<"Array 1 Contents Sorted with Bubble Sort = ";
    sortArr(array1);
    cout<<"Array 2 Contents = ";
    priArr(array2);
    cout<<"Array 2 Contents Sorted Selection Sort = ";
    sortArr2(array2);
    return 0;
}
//priArr Function
void priArr(int array[])
{
    //Print out array
    for(int count=0;count<20;count++)
        cout<<array[count]<<" ";
    cout<<endl;
}
//sortArr Function using bubble sort


void sortArr(int array[8])
{
    //Declare variables
    int temp;                                      //Temporarily holds a value for sorting
    bool swap;                                     //Bool that indicates a swap took place
    int numSwp=0;
    //Loops while bool is true
    do
    {swap=false;
    //Loops through the array
    for(int count=0;count<19;count++)
    {
        //Conditionally executes if previous value is greater than next value in the array
        if(array[count]>array[count+1])
        {
            temp=array[count];                       //Temporary variables holds value in array
            array[count]=array[count+1];             //That value is switched with th next value
            array[count+1]=temp;                     //Temporary variables is stored in the array position that was swithed
            swap=true;                               //Bool is set to true;
            if(swap)
                numSwp++;
        }
    }
    }while(swap);
    
    priArr(array);                                   //Function call to print array
    //Outputs number of exchanges
    cout<<"The number of exchanges was "<<numSwp<<endl;
    
}
//sortArr2 Function utilizing selection sort
void sortArr2(int array[])
{
    //Declare variables
    int minDex;                               //Minimum index           
    int minVal;                               //Minimum value
    int numSwp=0;
    
    //Loops and compares each number in  the array and sorts them
      for(int count=0; count<19;count++)
    {
          minDex=count;
          minVal=array [count];
          for(int index=count+1;index<20;index++)
          { if(array[index]<minVal)
              {
                  minVal=array[index];
                  minDex= index;
                  numSwp++;
              }
          }
      
    array[minDex]=array[count];
    array[count]=minVal;
      }
     
     priArr(array);                                   //Function call to print array
     //Output the number of exchanges
     cout<<"The number of exchanges was "<<numSwp<<endl;
}

