/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 7, 2015, 6:05 PM
 * Purpose: Gaddis_Tony_7th_ED_Chapter_2_Question_17
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Variables
const float CNVPERC=100;
//Execution Begins Here!

int main() 
{
    //Initialization of variables
    unsigned short shares= 600;
    float price=21.77;
    char rate=2;
    float stocks;
    float broker;
    float total;
    
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
