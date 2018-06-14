/* 
 * File:   broker.c
 * Author: jamesortiz
 *
 * Created on November 29, 2015, 5:47 PM
 */

#include <stdio.h>


/*
 * Purpose:
 * The minimum charge is $39.00. This program asks the user to enter the amount 
 * of the trade, then displays the amount of the commission.
 */

//Main Header
int main(void)
{
    //Variable declatations to support float variables
    float commission, value;
    
    //Accepts the users input of value
    printf("Enter value of trade:");
    scanf("%f", &value);
    
    //Checks to see which value goes accoring to condition
    if (value < 2500.00f)
    {
        commission = 30.00f + .017f * value;
    }
    else 
        if (value < 6500.00f)
        {
            commission = 56.0f + .0066f * value;
        }
        else
            if(value < 20000.00f)
            {
                commission = 76.0f + .0034f * value;
            }
            else 
                if(value < 50000.00f)
                {
                    commission = 100.00f + .0022f * value;
                }
                else 
                    if(value < 500000.00f)
                    {
                        commission = 155.00f + .0011f * value;
                    }
                    else
                    {
                        commission = 255.00f + .0009f * value;
                    }
    if (commission < 39.00f) //Determines the minimum amount of commission
    {
        commission = 39.00f;
    }
    
    //Displays the commission value.
    printf("Commission: $%.2f\n", commission);
                        
    //Terminates program
    return 0;
}

//
//Output:
//Enter value of trade: 30000
//Commission: $166.00
//