/* 
 **************************************************************************
 * Purpose: The purpose of this program is to apply the usage of selection
 * and repetition structures which calculate and display the number of    
 * integers inputted, the sum, the average, and the square root of the    
 * sum of all numbers.                                                    
 *                                                                        
 *   Author: James Ortiz                                                  
 *   Modified: 4/14/2016                                                  
 **************************************************************************
 */

//Pre-processor directives:
#include <stdio.h> //Library for input and output
#include <math.h>  //Library for mathematical functions


//Function declarations:

void getData(int* num);
void current_largest(int num, int* large_int);
void current_smallest(int num, int* small_int);
void counter_20(int num, int* greater_than_20);
void between_counter(int num, int* between_10_and_90);
void print_results(int num, int number_of_ints, int* small_int,
    int* large_int, int* greater_than_20, int* between_10_and_90, 
    int sum, float average, float sq_root);


int main(void) //main header
{              //opening bracket
    
    //Variable Declarations:
    
    //Variables of type int:
    /*
     The variable "number" is used to store the value of the integer inputted.
     The variable "number_of_ints" keeps track of the integers imputed.
     The variable "small_int" stores the smallest integer inputted.
     The variable "large_int" stores the largest integer inputted.
     
     The variable "greater_than_twenty" counts and stores the number of 
     integers that are greater than 20.
   
     The variable "between_ten_and_ninety" counts and stores the 
     number of integers that have a value between 10 and 90.
    
     The variable "sum" adds up the numerical values of all integers inputted.
     
     */
    
    int number;    
    int number_of_ints = 0;
    int small_int;
    int large_int;
    int greater_than_twenty;
    int between_ten_and_ninety;
    int sum;
        
    //Variables of type "double":
    /*
     The variable "average" stores the average value of all of the integers
     The variable "sq_root" stores the square root value of all of the integer
     values inputted.
     */
    float average;
    float sq_root;
    
    getData(&number);  //Calls the "getData" function for user input.

    //While-do loop - Repeats if the number is not 99999
    while (number != 99999)
    {   //opening bracket

        //Increments the value of "number_of_ints by 1
        number_of_ints += 1; 
        //Adds sum to the most recent integer inputted.
        sum = sum + number; 

        //Invokes the function "current_largest"
        //Takes in two parameters: "number", and "large_int"
        current_largest(number, &large_int);

        //Invokes the function current_smallest
        //Takes in two parameters: "number", and "small_int"
        current_smallest(number, &small_int);

        //Invokes the function "counter_20"
        //Takes in two parameters: "number" and "greater_than_twenty"
        counter_20(number, &greater_than_twenty);

        //Invokes the function "between_counter"
        //Takes in two parameters: "number" and 
        //"between_ten_and_ninety".
        between_counter(number, &between_ten_and_ninety);

        //Invokes the function "getData" once again
        //Takes in the parameter: "number"
        getData(&number);


    }   //closing block of "while" loop

    //Calculates the average of all of the integers
    average = (float) sum / number_of_ints;

    //Calculates the square root value of all of the integers.
    //Uses the mathematical function "sqrt" provided by the
    //math.h library.
    sq_root = sqrt(sum);

    //The invokes the function "print_results":
    //Takes in 9 parameters: "number", "number_of_ints", "small_int",
    //"large_int", "greater_than_twenty", "between_ten_and_ninety",
    //"sum", "average", "sq_root".

    print_results(number, number_of_ints, &small_int, &large_int,
                    &greater_than_twenty, &between_ten_and_ninety,
                    sum, average, sq_root);   

        
    

    return 0; //Terminates main
    
} //closing bracket for "main"

//==========Function Definitions==========//


/*
=================getData===========================
The function "getData" receives the address of the 
parameter of "num", and assigns it to the 
value that is inputted by the user. The function
is of return type "void", and accepts one parameter.
===================================================
 */
void getData(int* num)
{
    //Displays message asking user to enter 
    //the next integer
    printf("Enter next integer: ");
    
    //Stores it into the variable
    scanf("%d", num);
    
    //Returns control to "main"
    return;
    
} //getData

/*
=================current_largest==================
The "current_largest" function checks and see if
the next imputed integer is larger than the 
previous one. If it is, it will assign that number 
to the address of the variable "large_int". 

The function is of return type "void", and accepts
two parameters.
===================================================
 */

void current_largest(int num, int* large_int)
{
    //If.. Control-Structure:
    //True if "large_int" is less 
    //than "num".
    if (*large_int < num) 
    {
        //Assigns "large_int" to the largest integer.
        *large_int = num;
    }
    
    //Returns control to "main"
    return; 
    
} //current_largest


/*
===============current_smallest====================
The "current_smallest function checks and see if
the next inputed integer is less than the previous 
one. If it is, it will assign that number to the 
address of the variable "small_int".

The function is of return type "void", and accepts
two parameters.
===================================================
 */

void current_smallest(int num, int* small_int)
{
    //If.. Control structure:
    //True if num is less than "*small_int"
    if(num < *small_int)
    {
        //Assigns "small_int" to the smallest recent integer.
        *small_int = num;
    }
   
    //Returns control to "main"
    return;
   
} //current_smallest

/*
===================counter_20======================
The "counter_20" function keeps track of all
inputted integers that are greater than 20. If
the next integer is indeed greater than 20, then 
it will increment the value of the address of
"greater_than_20". 

The function is of return type "void", and accepts 
two parameters.
===================================================
 */
void counter_20(int num, int* greater_than_20)
{
    //If.. Control-Structure:
    //True if "num" is greater than 20.
    if(num > 20)
    {
        //Increments the value of the address of "greater_than_20 by 1
        *greater_than_20 += 1;
    }
    
    //Returns control to "main"
    return;
    
} //counter_20

/*
=================between_counter===================
The "between_counter" function keeps track of all
inputted integers that are between the values of 
10 and 90, inclusive. If the next integer contains
a value that is in the range 10-90, it will 
increment the value of the address of 
"between_10_and_90". 

The function is of return type "void", and accepts 
two parameters. 
===================================================
 */

void between_counter(int num, int* between_10_and_90)
{
    //If.. Control-Structure:
    //If num >=10 && num <= 90 is true
    //Then the address of "between_10_and_90 
    //is incremented.
    if(num >= 10 && num <= 90)
    {
        //Increments the value of the address of 
        //"between_10_and_90" by 1.
        *between_10_and_90 += 1;
    }
    
    //Returns control to "main"
    return;
    
} //between_counter


/*
=================print_results=====================
The function "print_results" displays important
information that is related to the program.
This includes: the number of integers,
the smallest integer, the largest integer,
the number of integers that have a value 
greater than 20, the number of integers that
contain a value between 10 and 90, the sum,
average, and also the square root of all of
the integer values.

 * This function includes an "If-else"
 * control statement.

 * If the number of integers is great than 
 * zero it will display this information,
 * however, if the number of integers is 
 * equal to zero and the first number inputted
 * is 99999 it will display "No integers were 
 * input".


The function is of return type "void", and takes in
9 parameters. 
===================================================
 */


void print_results(int num, int number_of_ints, int* small_int,
        int* large_int, int* greater_than_20, int* between_10_and_90, 
        int sum, float average, float sq_root)
{
    
    if (number_of_ints > 0)
    {
        //Displays information to the monitor related to the program.
        printf("Number of integers:\t\t%3d\n", number_of_ints);
        printf("Smallest:\t\t%11d\n", *small_int);
        printf("Largest:\t\t%11d\n", *large_int);
        printf("Numbers greater than 20:\t %2d\n", *greater_than_20);
        printf("Numbers between 10 and 90:\t %2d\n", *between_10_and_90);
        printf("Sum:\t\t\t%11d\n", sum);
        printf("Average:\t\t  %11.2f\n", average);
        printf("Square Root of Sum:\t  %11.2f\n", sq_root);
    }
    else 
        if(number_of_ints == 0 && num == 99999)
        {
            printf("No integers were input.\n");
        }

    
    //Returns control to "main"
    return;
    
} //print_results






