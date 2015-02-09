/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on February 8, 2015, 10:05 AM
 * Purpose: Gaddis_7th_ED_Chap_8_Prob_8
 *          sorting algorithms
 */
// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
int linSrch(int [], int);
int binSrch(int [],int);
void sortArr(int [],int);
//Execution Begins Here!

int main(int argc, char** argv) {
    int array1[]={20,14,99,86,44,78,68,22,5,6,88,56,41,33,26,55,74,9,66,20};
    int array2[]={20,14,99,86,44,78,68,22,5,6,88,56,41,33,26,55,74,9,66,20};
    int value;
    cout<<"Please enter a value that you would like to search for between 1-99"<<endl;
    cin>>value;
    
linSrch(array1,value);    
sortArr(array2,value);

    
    return 0;
}
 int linSrch(int array[],int value)
    {
        int index=0;
        int position=-1;
        int swap=0;
        bool found=false;
        
        while(index<20&&!found)
        {
            if(array[index]==value)
            {
                found= true;
                position=index;
                swap++;
            }
            index++;
        }
        cout<<"The number of comparisons made is "<<swap<<endl;
        cout<<"The number was found in array subscript "<<position<<" or the "<<position+1<< " position in the array"<<endl;
        return position;
    }
    int binSrch(int array[], int value)
    {
        int first=0;
        int last=20-1;
        int middle;
        int  position=-1;
        bool found=false;
        int swap=0;
        
        while(!found&&first<=last)
        {middle=(first+last)/2;
        if(array[middle]==value)
        {
            found= true;
            position=middle;
            swap++;
        }
        else if(array[middle]>value)
        {last=middle-1;
         swap++;
        }   
        else
        {first=middle+1;
        swap++;}
    }
         cout<<"The number of comparisons made is "<<swap<<endl;
        cout<<"The number was found in array subscript "<<position<<" or the "<<position+1<< " position in the array"<<endl;
        return position;
    }
    void sortArr(int array[],int value)
{
    //Declare variables
    int temp;                                      //Temporarily holds a value for sorting
    bool swap;                                     //Bool that indicates a swap took place
    //Loops while bool is true
    do
    {swap=false;
    //Loops through the array
    for(int count=0;count<20;count++)
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
    binSrch(array,value);
}