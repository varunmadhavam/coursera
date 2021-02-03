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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 * 
 * @author Varun Mohan
 * @date August 18 2019
 * 
 */
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t* my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  uint8_t* tmp;
  size_t i;
  
  tmp=dst;
 
  if(dst>src)
  {
     uint8_t* ends = src + (length-1);
     uint8_t* endd = dst + (length-1);
     for(i=1;i<=length;i++)
     {
       *endd=*ends;
       endd-=1;
       ends-=1;
     }
  }
  else
  {
    for(i=1;i<=length;i++)
     {
       *tmp=*src;
       tmp+=1;
       src+=1;
     }
  }
  return dst;
  
}

uint8_t* my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
  uint8_t* tmp=dst;
  size_t i;
  for(i=1;i<=length;i++)
  {
    *tmp=*src;
    tmp+=1;
    src+=1;
  }
  return dst;

}

uint8_t* my_memset(uint8_t * src, size_t length, uint8_t value)
{
  size_t i=0;
  uint8_t* tmp;
  tmp=src;
  for(i=1;i<=length;i++)
  {
    *tmp=value;
    tmp+=1;
  }
  return src;
}

uint8_t* my_memzero(uint8_t * src, size_t length)
{
  size_t i=0;
  uint8_t* tmp;
  tmp=src;
  for(i=1;i<=length;i++)
  {
    *tmp=0;
    tmp+=1;
  }
  return src;
}

uint8_t* my_reverse(uint8_t * src, size_t length)
{
  uint8_t *tmp,*end;
  uint8_t data;
  tmp=src;
  end=src+((int)length-1);
  while (tmp<end)
  {
    data=*tmp;
    *tmp=*end;
    *end=data;
    tmp+=1;
    end-=1;
  }
  return src;
  
}

int32_t* reserve_words(size_t length)
{
  return (int32_t*)malloc(4*length);
}

void free_words(uint32_t * src)
{
  free(src);
}
