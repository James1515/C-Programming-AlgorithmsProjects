/* 
 * File:   main.c
 * Author: jamesortiz
 *
 * Created on March 20, 2016, 6:40 PM
 */

#include <stdio.h>
#include <stdlib.h>

void getData(int* num);

void if_structure(int num, int* great_then_1);
void display_data(int num, int great_then_1);

/*
 * 
 */
int main(void)

{
    int num;
    int greater_than_1;
    
    
    getData(&num);
    if_structure(num, &greater_than_1);

    return (EXIT_SUCCESS);
}

void getData(int* num)
{
    printf("Please enter a number: \n");
    scanf("%d", num);
    
    return;
}

void if_structure(int num, int* great_then_1)
{
    int temp;
    temp = 50;
    *great_then_1 = temp;
    if (num > *great_then_1)
    {
        printf("Number is greater than 50.\n");
        
        printf("The value is: %d\n", num);        
        
    }
    else
    {
        printf("Number is less than 1.\n");
        
    }
    
    return;
}



