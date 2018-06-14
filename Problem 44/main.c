
/**************************************************************
* Purpose: This program is designed to create customer's bills
* for a carpet installation company using functions as modules
* and sub-modules.
*  Written By: James Ortiz
*  Modified: 03/2/2016
***************************************************************
*/


#include <stdio.h>   //Pre-processor directive


//Function declarations 

//Function declaration for "getData"
void getData(int* length, int* width, float* discount, 
        float* cost_per_sq_feet); 

//Function declaration for "Calculate"
void Calculate(int width, int length, float discount, float cost_per_square_feet,
        int* area, float* carpet_cost, float* labor_cost, float* install_price, 
        float* total_discount, float* sub_total, float* tax, float* total_price, 
        const float* labor_price, const float* tax_rate); 

//Function declaration for "installedPrice"
void installedPrice(int width, int length, float cost_per_square_feet,
        int* area, float* carpet_cost, float* labor_cost, 
        const float* labor_price, float* install_price);

//Function declaration for "subTotal"
void subTotal(float* install_price, float discount, float* total_discount,
        float* sub_total);

//Function declaration for "totalPrice"
void totalPrice(float sub_tot, float* tx, const float* tx_rate, float* tot_pr);

//Function declaration for "printResult"
void printResult(int width, int length, float cost_per_square_feet, float discount,
        int area, float carpet_cost, float labor_cost, float install_price, 
        float total_discount, float sub_total, float tax, float total_price, 
        const float labor_price);

//Function declaration for "printMeasurements"
void printMeasurements(int width, int length, int area);

//Function declaration for "printCharges"
void printCharges(float cost_per_square_feet, float discount, float carpet_cost,
        float labor_cost, float install_price, float total_discount,
        const float labor_price, float sub_total,
        float total_price, float tax);


int main(void) //"main" header
{              //Opening bracket
  
  //Variable Declarations:
    
  //Constants (type float):
    
  //The constant variable "labor" is created to keep track of the labor cost.
  //The constant variable "tax_rate" is created to keep track of the tax rate 
  //of the carpet work.
  const float labor = 0.35;
  const float tax_rate = .085;
  
  //Variables of type int:
  /*
   * "area" is used to store the value of the area of the carpet work.
   * "length" is used to store the length of the carpet work, "width" is used
   * to store the width of the carpet work, and "discount" holds the discount 
   * value for the carpet work.
  */
  
  int area;
  int length;
  int width;
  float discount;
  
  //Variables of type float:
  /*
   * The variable "cost_per_square_feet" is used to store the cost per square foot 
   * of the carpet work. "carpet_cost" is used to store the value of the carpet,
   * "labor_cost" holds the total value of the labor involved in the carpet work.
   * 
   * The variable "installed_price" holds the value of the price of the carpet
   * installation, "total_discount" holds the value of the total discount of 
   * the carpet work. The "sub_total" variable is used to calculate the 
   * subtotal, and finally "tax" and "total_price" are used to calculate 
   * the tax of the purchase, and the total price of all of the carpet work.
   */
  
  float cost_per_square_feet;
  float carpet_cost;
  float labor_cost;
  float installed_price;
  float total_discount;
  float sub_total;
  float tax;
  float total_price;
  
  //Function Calls:
  //"getData" receives input from the user and stores it in the variables:
  //length, width, discount, and cost_per_square_feet.
  getData(&length, &width, &discount, &cost_per_square_feet);
  
  //The "calculate" function calls three other sub-functions;
  //"installedPrice", "subTotal", and "totalPrice". These are 
  //then used to calculate all of the charges that are 
  //associated with the program.
  Calculate(width, length, discount, cost_per_square_feet, &area,
          &carpet_cost, &labor_cost, &installed_price, &total_discount,
          &sub_total, &tax, &total_price, &labor, &tax_rate);
  
  //The "printResult" function calls two other functions called
  //"printMeasurements" and "printCharges", which display as output the values
  //associated with the measurements and the charges of the carpet work.
  printResult(width, length, cost_per_square_feet, discount, area, 
          carpet_cost, labor_cost, installed_price, total_discount,
          sub_total, tax, total_price, labor);
  
  return 0; //Terminates the program
} //Closing bracket - main

//****************Function Definitions***********************//

/*
========================getData=============================
The "getData" function reads and stores the input of 
length, width, the customer discount, and the
cost per square foot of carpet from the keyboard.
============================================================
*/
void getData(int* length, int* width, float* discount, 
        float* cost_per_sq_feet)
{ 
  
  //The following statements ask the user for input regarding
  //length, width, the customer discount, and the cost per square 
  //foot of the carpet itself.
  printf("Enter length in feet (integer): ");
  scanf("%d", length);
  printf("Enter width in feet (integer): ");
  scanf("%d", width);
  printf("Enter discount rate (float): "); 
  scanf("%f", discount);
  printf("Enter cost per sq. ft. (float): ");
  scanf("%f", cost_per_sq_feet);

  return; //Sends control back to main
} //getData

/*
============================Calculate==================================
 This function calls all three sub-functions: installedPrice, subTotal,
 and totalPrice. 
=======================================================================
 */

void Calculate(int width, int length, float discount, float cost_per_square_feet,
        int* area, float* carpet_cost, float* labor_cost, float* install_price, 
        float* total_discount, float* sub_total, float* tax, float* total_price, 
        const float* labor_price, const float* tax_rate)
{
    
    //Called sub-functions:
    
    //"installedPrice" calculates the area, carpet cost, the labor cost,
    //and the installed price of the carpet work.
    installedPrice(width, length, cost_per_square_feet, area, 
            carpet_cost, labor_cost, labor_price,
            install_price);

    //"subTotal" calculates the total discount, and the sub total
    //of the program.
    subTotal(install_price, discount, total_discount, sub_total);    
    
    //"totalPrice" calculates the total tax, and also the total 
    //price of the carpet work.
    totalPrice(*sub_total, tax, tax_rate, total_price);
    
    
    return;//Sends control back to main
}//Calculate

/*
========================installedPrice===============================
 The "installedPrice" function calculates the area, the carpet cost,
 the labor cost, and the install price.
=====================================================================
*/

void installedPrice(int width, int length, float cost_per_square_feet,
        int* area, float* carpet_cost, float* labor_cost, 
        const float* labor_price, float* install_price) 
{
    //Calculates the area
    *area = (length * width);
    
    //Calculates the carpet cost.
    *carpet_cost = (*area * cost_per_square_feet);
    
    //Calculates the labor cost.
    *labor_cost = (*area * *labor_price);
    
    //Calculates the install price.
    *install_price = *carpet_cost + *labor_cost;
    
    return; //Sends control back to main
} //installedPrice

/*
===========================subTotal================================
 The "subTotal" function calculates the total discount, and the 
 subtotal of the carpet work in the program.
===================================================================
 */

void subTotal(float* install_price, float discount, float* total_discount,
        float* sub_total)
{
    //Calculates the total discount.
    *total_discount = (*install_price *  discount)/100.0;
    
    //Calculates the sub total.
    *sub_total = *install_price - *total_discount;
    
    return; //Sends control back to main
}//subTotal


/*
===========================totalPrice==============================
 The "totalPrice" function calculates the tax, and total price
 of the carpet work in the program.
===================================================================
 */
void totalPrice(float sub_total, float* tax, const float* tax_rate,
        float* total_price)
{
    
    *tax = (sub_total * *tax_rate); //Calculates the total tax.
    
    *total_price = (sub_total + *tax); //Calculates the total price,
    
    return; //Sends control back to main
    
}//totalPrice

/*
============================printResult================================
The "printResult" function calls two sub-functions: "printMeasurements"
and "printCharges". The function is of type void, but accepts 
parameters.
=======================================================================
 */

void printResult(int width, int length, float cost_per_square_feet, float discount,
        int area, float carpet_cost, float labor_cost, float install_price, 
        float total_discount,float sub_total, float tax, float total_price, 
        const float labor_price)
{
    
    //Function Calls:
    
    //The function "printMeasurements"
    printMeasurements(width, length, area);
    
    printCharges(cost_per_square_feet, discount, carpet_cost, labor_cost,
            install_price, total_discount, labor_price, sub_total,
            total_price, tax);
    
    return; //Sends control back to main
} //printResult

/*
======================printMeasurements============================
 The "printMeasurements" function displays the results of the 
 length, width, and area of the carpet work. The function is of
type void, but accepts parameters.
===================================================================
 */

void printMeasurements(int width, int length, int area)
{
    //These statements display the values realted to the measurements.
    //Length, width, and area are displayed.
    
    printf("\t\tMEASUREMENTS\n");
    printf("Length\t%d ft\n", length);
    printf("Width\t%d ft\n", width);
    printf("Area\t%d square ft\n", area);
    
    return; //Sends control back to main
} //printMeasurements

/*
========================printCharges===========================================
The "printCharges" function is designed to display the charges
on the screen. These include the carpet cost, labor cost, the 
installed price, the customer discount, the total discount, the sub-total, the 
tax and the total balance. The function is of type "void", but 
accepts parameters.
==============================================================================
 */

void printCharges(float cost_per_square_feet, float discount, float carpet_cost,
        float labor_cost, float install_price, float total_discount,
        const float labor_price, float sub_total,
        float total_price, float tax)
{
    //The following statements display information related to the charges
    //of the program. 
    
    printf("\t\tCHARGES\n");
    
    printf("DESCRIPTION     COST PER SQ.FT     CHARGE\n");
    printf("-----------     --------------     ------------\n");
    printf("Carpet\t\t%6.2f\t\t   $%7.2f\n", cost_per_square_feet, carpet_cost);
    printf("Labor\t\t%6.2f\t\t   $%7.2f\n", labor_price, labor_cost);
    printf("                                   ------------\n");
    printf("INSTALLED PRICE\t\t\t   $%7.2f\n", install_price);
    printf("Discount\t %5.2f%%\t\t   $%7.2f\n", discount, total_discount);
    printf("                                   ------------\n");
    printf("SUBTOTAL\t\t\t   $%7.2f\n", sub_total);
    printf("Tax\t\t\t\t   $%7.2f\n", tax);
    printf("TOTAL\t\t\t\t   $%7.2f\n", total_price);
    
    
    return; //Sends control back to main
    
}//printCharges




