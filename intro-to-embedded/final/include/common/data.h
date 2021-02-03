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
 * @file data.h
 * @brief Abstraction of Integer/ASCII convertions.
 *
 * This header file provides an abstraction of converting data from a 
 * standard integer type into an ASCII string and vice versa.
 *
 * @author Varun Mohan
 * @date August 18th 2019
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief convert data from a standard integer type into an ASCII string.
 *
 * Convert data from a standard integer type into an ASCII string.
 * Support bases 2 to 16.
 *
 * @param data The number to be converted.
 * @param ptr A pinter to store the address of the converted string.
 * @param base Base of the input number.
 *
 * @return length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief converts data back from an ASCII represented string into an integer type. 
 *
 * converts data back from an ASCII represented string 
 * into an integer type. Supports bases 2 to 16.
 *
 * @param ptr The character string to be converted.
 * @param digits The number of digits in your character set.
 * @param The base of the input data.
 *
 * @return converted 32-bit signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief converts a digit to its corresponding character. 
 *
 * retunr the correspoding character for a digit. Eg returns
 * '1' for 1 or 'F' for 15.
 *
 * @param c The character  to be converted.
 *
 * @return The value of the character in decimal.
 */
uint8_t  lookup_r(int32_t c);

/**
 * @brief converts a character to its corresponding digit. 
 *
 * returns the correspoding digit for a character. Eg returns
 * 1 for '1' or 15 for 'f'|'F'.
 *
 * @param c The digit  to be converted.
 *
 * @return The decimal value of the character.
 */
uint32_t lookup(char c);

#endif /* __DATA_H__ */
