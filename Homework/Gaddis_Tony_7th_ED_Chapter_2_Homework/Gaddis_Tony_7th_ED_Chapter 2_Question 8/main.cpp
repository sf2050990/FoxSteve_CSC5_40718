/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 11:08 PM
 * Purpose: Gaddis_Tony_7th_ED_Chapter_2_Question_8
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ 
    //Initialize Variables
    float item1=12.95;
    float item2=24.95;
    float item3=6.95;
    float item4=14.95;
    float item5=3.95;
    float saletax=.06;
    float tax1;
    float tax2;
    float tax3;
    float tax4;
    float tax5;
    float total1;
    float total2;
    float total3;
    float total4;
    float total5;
    
    //Calculates the amount of tax for items 1-5.
    tax1=item1*saletax;
    tax2=item2*saletax;
    tax3=item3*saletax;
    tax4=item4*saletax;
    tax5=item5*saletax;
    
    //Calculates the total sales price for items 1-5.
    total1=item1+tax1;
    total2=item2+tax2;
    total3=item3+tax3;
    total4=item4+tax4;
    total5=item5+tax5;
    
    //Output original price, subtotal, tax amount, and total price
    cout<<setprecision(2)<<fixed<<"Items"<<setw(8)<<"Price"<<setw(10)<<"Subtotal"<<setw(7)<<"Tax"<<setw(13)<<"Total Price";
    cout<<endl<<"-------------------------------------------"<<endl;
    cout<<"Item 1"<<setw(7)<<item1<<setw(10)<<item1<<setw(7)<<tax1<<setw(13)<<total1<<endl;
    cout<<"Item 2"<<setw(7)<<item2<<setw(10)<<item2<<setw(7)<<tax2<<setw(13)<<total2<<endl;
    cout<<"Item 3"<<setw(7)<<item3<<setw(10)<<item3<<setw(7)<<tax3<<setw(13)<<total3<<endl;
    cout<<"Item 4"<<setw(7)<<item4<<setw(10)<<item4<<setw(7)<<tax4<<setw(13)<<total4<<endl;
    cout<<"Item 5"<<setw(7)<<item5<<setw(10)<<item5<<setw(7)<<tax5<<setw(13)<<total5<<endl;
    
    //Exit Program
    return  0;     
}



