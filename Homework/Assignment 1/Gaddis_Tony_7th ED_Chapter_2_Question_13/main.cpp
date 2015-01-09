/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 6, 2015, 6:05 PM
 * Purpose:Gaddis_Tony_7th_ED_Chapter_2_Question_13
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global variables
const char CONPERC=100;

int main() 
{
    //Initialization of variables
    float rate=40;
    float cost=12.67;
    float price;
    
    //Calculation of total sales cost of a circuit board
    price=(cost*(rate/CONPERC))+cost;
    
    //Output of total sales cost of circuit board
    cout<<setprecision(2)<<fixed<<"The unit cost of a circuit board is "<<cost;
    cout<<" dollars in addition to the"<<endl;
    cout<<"company making a 40% profit off this price, which in turn equals "<<endl;
    cout<<"a sales price of "<<price<<" dollars";

   //Exit program
    return 0;    
}
