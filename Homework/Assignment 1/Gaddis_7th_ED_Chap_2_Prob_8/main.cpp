/* 
 * File:   main.cpp
 * Author: Steve Fox
 *
 * Created on January 8, 2015, 11:08 PM
 * Purpose: Gaddis_7th_ED_Chap_2_Prob_8
 */
// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constant
const char CONPERC=100;                //Constant for converting percent into decimal
int main()
{ 
    //Initialize Variables
    float item1=12.95;                 //Price for item 1
    float item2=24.95;                 //Price for item 2
    float item3=6.95;                  //Price for item 3
    float item4=14.95;                 //Price for item 4
    float item5=3.95;                  //Price for item 5
    float saletax=6;                   //sales tax
    float tax1;                        //tax on item 1
    float tax2;                        //tax on item 2
    float tax3;                        //tax on item 3
    float tax4;                        //tax on item 4
    float tax5;                        //tax on item 5
    float total1;                      //Total for item 1
    float total2;                      //Total for item 2
    float total3;                      //Total for item 3
    float total4;                      //Total for item 4
    float total5;                      //Total for item 5
    
    //Calculates the amount of tax for items 1-5.
    tax1=item1*(saletax/CONPERC);
    tax2=item2*(saletax/CONPERC);
    tax3=item3*(saletax/CONPERC);
    tax4=item4*(saletax/CONPERC);
    tax5=item5*(saletax/CONPERC);
    
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



