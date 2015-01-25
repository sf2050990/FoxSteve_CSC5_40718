/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 22, 2015, 6:05 PM
 * Purpose: Gaddis_7th_ED_Chap_6_Prob_13
 *          Order status of wire spools
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;


//Function Prototype
void order(int,int,float);                 //Function prototype for order

//Execution Begins Here!
int main()
{
    //Declare variables
    int numOrd;                             //Number of spools ordered
    int numItem;                            //Number of items in stock
    float speChar;                          //amount of special charges 
    
    //Prompt user for the amount of spools ordered, total spools in stock, and special charges
    //per spool
    cout<<"How many spools have been ordered?"<<endl;
    cin>>numOrd;
    
    cout<<"How many spools are in stock"<<endl;
    cin>>numItem;
    
    cout<<"What are the total special charges associated with this order per spool if any? "<<endl;
    cin>>speChar;
    
    //Send inputs to order function
    order(numOrd,numItem,speChar);
    return 0;
}
//Order function
void order(int numOrd,int numItem,float speChar)
{
    //Declare variables
    float itemCos=100.00;                     //Cost of individual spool
    float shipCos=10.00;                      //Shipping cost per spool
    //Calculate the amount of spools in order or back order
    int ordShip=numItem-numOrd;
    //Calculate sub item cost
    float subItem=numOrd*itemCos;
    //Calculate special charges per spool
    float totSpec=numOrd*speChar;
    //Calculate total shipping cost
    float totShip=shipCos*numOrd+totSpec;
    //Calculate total bill
    float totBill=subItem+totShip;
    
    //Conditionally executes if number ordered is greater than the numbers in stock
    //Outputs number of spools available
    if(numOrd>numItem)
      cout<<"The number of spools ready for order is "<<numItem<<endl;
     //Conditionally executes if number ordered greater than 0
     //Outputs the full order amount
    if(ordShip>0)
      cout<<"The number of spools ready to ship is "<<numOrd<<endl;
     //Conditionally executes if number ordered is greater than the numbers in stock
     //Ouputs the number of spools on back order
    else
      cout<<"The number of spools on back order is "<<ordShip*-1<<endl;
    
     //Outputs subcost, shipping cost,and total bill   
      cout<<setprecision(2)<<fixed<<showpoint;
      cout<<"The subcost of this order is $"<<subItem<<endl;
      cout<<"The total shipping cost is $"<<totShip<<endl;
      cout<<"The total Bill for this order is $"<<totBill<<endl;
      
}