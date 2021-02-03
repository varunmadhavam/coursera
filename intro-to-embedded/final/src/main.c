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
 * Copyright 2019 Varun Mohan<varunmadhavam@gmail.com>
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
 * @file main.c
 * @brief Main entry point to the Course1 final Assessment
 *
 * This main function call the cousrse respective functions
 * based on the the compile time switch. for Eg if -DCOURSE1
 * call course1()
 *
 * @author Varun Mohan
 * @date August 17th 2019
 *
 */

#include "course1.h"

int main(void) 
{
#ifdef COURSE1
  course1();
#endif
return 0;
}

