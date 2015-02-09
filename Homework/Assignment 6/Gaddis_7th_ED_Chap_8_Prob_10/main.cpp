/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 08, 2015, 6:05 PM
 * Purpose: Gaddis_7th_ED_Chap_8_Prob_10
 *        Sorting menus with arrays
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
void priArr(int []);                   //Function prototype for printing array
void sortArr(int []);                  //Function prototype for sorting array using bubble sort
void sortArr2(int[]);                   //Function prototype for sorting array using selection sort
//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables

    int array1[8]={9,55, 26, 14, 98, 62, 45, 72};         //First array with eight integers
    int array2[8]={9,55, 26, 14, 98, 62, 45, 72};          //Second array with eight integers
    
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
void priArr(int array[8])
{
    //Print out array
    for(int count=0;count<8;count++)
        cout<<array[count]<<" ";
    cout<<endl;
}
void sortArr(int array[8])
{
    //Declare variables
    int temp;                                      //Temporarily holds a value for sorting
    bool swap;                                     //Bool that indicates a swap took place
    //Loops while bool is true
    do
    {swap=false;
    //Loops through the array
    for(int count=0;count<7;count++)
    {
        //Conditionally executes if previous value is greater than next value in the array
        if(array[count]>array[count+1])
        {
            temp=array[count];                       //Temporary variables holds value in array
            array[count]=array[count+1];             //That value is switched with th next value
            array[count+1]=temp;                     //Temporary variables is stored in the array position that was swithed
            swap=true;                               //Bool is set to true;
        }
    }
    }while(swap);
    priArr(array);                                   //Function call to print array
}
void sortArr2(int array[])
{
    int minDex;
    int minVal;
    
      for(int count=0; count<7;count++)
    {
          minDex=count;
          minVal=array [count];
          for(int index=count+1;index<8;index++)
          { if(array[index]<minVal)
              {
                  minVal=array[index];
                  minDex= index;
              }
          }
      
    array[minDex]=array[count];
    array[count]=minVal;
      }
     priArr(array);                                   //Function call to print array
}