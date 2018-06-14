/* 
 * File:   dweight.c
 * Author: jamesortiz
 *
 * Created on November 17, 2015, 8:13 PM
 * 
 * Purpose: Computes the Dimensional Weight of a 12" x 10" x 8" box.
 * 
 * Chapter 2 Section 2.4
 */

#include <stdio.h>

int main(void) 
{
    int height = 8, length = 12, width = 10;
    int volume, weight;
    
    volume = height * length * width;
    weight = (volume + 165) / 166;
    
    //Displays information as Output
    
    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume: (in cubic inches) %d\n", volume);
    printf("Weight: (in cubic pounds) %d\n", weight);
    
    return (0);
}

