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
 * @file data.c
 * @brief Abstraction of Integer/ASCII convertions.
 *
 * This files  provides the implemtataion  of functions for converting data from a 
 * standard integer type into an ASCII string and vice versa.
 *
 * @author Varun Mohan
 * @date August 18th 2019
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base)
{
  int32_t result=0;
  int32_t sign=1;
  uint8_t i;

  for(i=1;i<=digits;i++)
  {
    if(i==1)
    {
      if(*ptr=='-')
      {
         sign=-1;
         ptr+=1;
        continue;
      }   
    }
    result = result*base + lookup(*ptr);
    ptr+=1;
  }
  
  return sign*result;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
 uint8_t lenght=1;
 uint8_t sign=0;
 uint8_t *str,*pstr;

 if(data<0)
 {
     sign=1;
     data=-data;
     lenght+=1;
 }

 str=(uint8_t*)reserve_words(8);
 pstr=str;
 *str='\0';
 str+=1;

 while (data>0)
 {
    *str=lookup_r(data%base);
    data=data/base;
    str+=1;
    lenght+=1;
 }

 if(sign==1)
    *str='-';

 pstr=my_reverse(pstr,lenght);
 my_memcopy(pstr,ptr,lenght);
 free_words((uint32_t*)pstr);
 
 return lenght-1;
}

uint32_t lookup(char c)
{
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'a':
    case 'A':
        return 10;
    case 'b':
    case 'B':
        return 11;
    case 'c':
    case 'C':
        return 12;
    case 'd':
    case 'D':
        return 13;
    case 'e':
    case 'E':
        return 14;
    case 'f':
    case 'F':
        return 15;
    default:
        return 0;
    }
}

uint8_t lookup_r(int32_t c)
{
    switch (c)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    default:
        return '0';
    }
}
