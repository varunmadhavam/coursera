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
 * @file stats.h 
 * @brief Header file for statistical functions
 *
 * This files contains the function declarations for the various statistical
 * functions along with proper documentation of the function.
 *
 * @author Varun Mohan
 * @date 10/08/2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints the statistics of an array of elements.
 *
 * This function takes in an array of unsigned chars and 
 * prints important statistics like minimum, maximum, 
 * mean and median.
 *
 * @param array An unsigned char pointer to the array.
 * @param size An unsigned integer denoting the size of the array.
 *
 */
void print_statistics(unsigned char *array, unsigned int size);

/**
 * @brief Prints an array on to the screen.
 *
 * This function takes in an array  and prints all its
 * elements on to the screen begining from the 0th element.
 *
 * @param array An unsigned char pointer to the array.
 * @param size An unsigned integer denoting the size of the array.
 *
 */
void print_array(unsigned char *array, unsigned int size);


/**
 * @brief Returns the median of the elements in an array
 *
 * Given an array, this function calculates the median of the 
 * elements in the array and returns it.
 *
 * @param array An unsigned char pointer to the array.
 * @param size An unsigned integer denoting the size of the array.
 *
 * @return The median value.
 */
unsigned char find_median(unsigned char * array, unsigned int size);


/**
 * @brief Returns the mean of the elements in an array
 *
 * Given an array, this function calculates the mean of the 
 * elements in the array and returns it.
 *
 * @param array An unsigned char pointer to the array.
 * @param size An unsigned integer denoting the size of the array.
 *
 * @return The mean value.
 */
unsigned char find_mean(unsigned char * array, unsigned int size);


/**
 * @brief Returns the maximum of the elements in an array
 *
 * Given an array, this function finds the biggest 
 * elements in the array and returns it.
 *
 * @param array An unsigned char pointer to the array.
 * @param size An unsigned integer denoting the size of the array.
 *
 * @return The biggest element in the array.
 */
unsigned char find_maximum(unsigned char * array, unsigned int size);


/**
 * @brief Returns the minimum of the elements in a array
 *
 * Given an array, this function finds the smallest
 * elements in the array and returns it.
 *
 * @param array An unsigned char pointer to the array.
 * @param size An unsigned integer denoting the size of the array.
 *
 * @return The smallest element in the array.
 */
unsigned char find_minimum(unsigned char * array, unsigned int size);


/**
 * @brief Sorts the given array in descending order.
 *
 * Given an array, sorts the array from largest to smallest. 
 * (The zeroth Element will be the largest value, and the 
 * last element (n-1) will be the smallest value.)
 *
 * @param array An unsigned char pointer to the array.
 * @param size An unsigned integer denoting the size of the array.
 *
 */
void sort_array(unsigned char * array, unsigned int size);


/**
 * @brief Swaps two variables in memory.
 *
 * This function takes the addresses of two variables of 
 * type unsigned char  and swaps their value
 *
 * @param a The first varibale.
 * @param b The second variable..
 *
 */
void swap(unsigned char *a, unsigned char *b);

#endif /* __STATS_H__ */
