/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

/*****************************************************************************
 *  Copyright 2019 Varun Mohan<varunmadhavam@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction,including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *****************************************************************************/

/**
 * @file stats.c
 * @brief Program calculates statistics on an array of elements.
 *
 * This program contains various functions to calculate and print
 * different staistics like mean, median, maximum and minimum of a 
 * set of elemnts in an array.
 *
 * @author Varun Mohan
 * @date 10/08/2019
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
/*#define SIZE (40)
unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
	                    114, 88,   45,  76, 123,  87,  25,  23,
		            200, 122, 150, 90,   92,  87, 177, 244,
		            201,   6,  12,  60,   8,   2,   5,  67,
		              7,  87, 250, 230,  99,   3, 100,  90};
 
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                               7,  87, 250, 230,  99,   3, 100,  90};

  printf("\nThe array is : ");
  print_array(test,SIZE);
  printf("\n");
  sort_array(test,SIZE);
  printf("The sorted(descending order) array is : ");
  print_array(test,SIZE);
  printf("\n");
  print_statistics(test,SIZE);
}*/

void print_statistics(unsigned char *array, unsigned int size)
{
 printf("\n********************* Data Statistics ************************");
 printf("\nMean : %u, Median : %u, Maximum : %u, Minimum : %u\n\n",find_mean(array,size),find_median(array,size),find_maximum(array,size),find_minimum(array,size));
}

void print_array(unsigned char *array, unsigned int size)
{
 #ifdef VERBOSE
   unsigned int i;
   for(i=0;i<size;i++)
   {
      PRINTF("%d ", array[i]);
   }     
   PRINTF("\n");
 #endif
}

unsigned char find_median(unsigned char * array, unsigned int size)
{
 sort_array(array,size);
 if((size%2)!=0)
   return array[(size/2)-1];
 else
   {
     unsigned char mid1=array[(size/2)-1];
     unsigned char mid2=array[(size/2)];
     return (mid1+mid2)/2;
   }

}

unsigned char find_mean(unsigned char * array, unsigned int size)
{
 unsigned int i;
 unsigned int sum=0;

 for(i=0;i<size;i++)
    sum=sum+array[i];

 return sum/size;
}

unsigned char find_maximum(unsigned char * array, unsigned int size)
{
 unsigned int i;
 unsigned char max=array[0];

 for(i=1;i<size;i++)
    if(array[i]>max)
      max=array[i];

 return max;
}

unsigned char find_minimum(unsigned char * array, unsigned int size)
{
 unsigned int i;
 unsigned char min=array[0];

 for(i=1;i<size;i++)
    if(array[i]<min)
      min=array[i];

 return min;
}

void sort_array(unsigned char * array, unsigned int size)
{
 unsigned int i,j;
 for(i=0;i<size-1;i++)
    for(j=0;j<size-1;j++)
       if(array[j]<array[j+1])
         swap(&array[j],&array[j+1]);
}

void swap(unsigned char *a,unsigned char *b)
{
 unsigned char temp;
 temp=*a;
 *a=*b;
 *b=temp;
}
