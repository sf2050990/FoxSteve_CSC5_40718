/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 7, 2015, 6:05 PM
 * Purpose: Gaddis_7th_ED_Chap_2_Prob_17
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Variables
const float CNVPERC=100;          //Constant to convert percent into decimal
//Execution Begins Here!

int main() 
{
    //Initialization of variables
    unsigned short shares= 600;         //Number of Shares
    float price=21.77;                  //initial price per share
    char rate=2;                        //Percent paid to the broker
    float stocks;                       //Initial amount spent on stocks
    float broker;                       //Amount paid to broker
    float total;                        //Total amount paid
    
    //calculates initial total of amount spent
    stocks=shares*price;
    
    //calculates amount paid to the broker
    broker=stocks*(rate/CNVPERC);
    
    //calculates the total amount spent 
    total=stocks+broker;
    
    //Output findings and script
    cout<<setprecision(2)<<fixed<<showpoint<<"Kathryn bought "<<shares<< " stocks at "<<price<<" dollars which equates to "<<endl;
    cout<<stocks<< " dollars she originally spent. She had to pay 2% to her broker"<<endl;
    cout<<"which equals "<<broker<<" in fees. Kathryn spent "<<total<< " dollars"<<endl;
    cout<<"in total.";
    
   //End of program
    return 0;
}
