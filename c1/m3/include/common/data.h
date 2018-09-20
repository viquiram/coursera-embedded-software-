/******************************************************************************
 * Copyright (C) 2018 by Viviana Quirama
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. The author
 * is not liable for any misuse of this material.
 *
 *****************************************************************************/

/**
 * @file data.h
 * @brief Abstraction of data manipulation
 *
 * This header file provides an abstraction of basic data manipulation.
 *
 * @author Viviana Quirama
 * @date 19/09/2018
 *
 */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifndef __DATA_H__
#define __DATA_H__

#define BASE_2    2
#define BASE_8    8
#define BASE_10  10
#define BASE_16  16

/**
 * @brief Converts data from an integer into an ASCII string
 *
 * This function converts a number passed in as a signed 32-bit integer into
 * an ASCII string. This character string is copied to the uint8_t* pointer
 * passed in as a parameter.
 *
 * The final string ends with a null terminator character. Its maximum size is
 * 33 bytes (32 bits for binary conversion plus null terminator). In case of
 * converting into a negative decimal value, the string must include the
 * negative sign.
 *
 * This function is able to support bases 2, 8, 10 and 16.
 *
 * @param data Sign 32-bit integer to convert
 * @param ptr Pointer to the ASCII string
 * @param base Value of the base to convert to
 *
 * @return Length of the converted data (including null terminator and
 * negative sign)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts data from an ASCII string into an integer
 *
 * This function converts a number passed in as an ASCII string into a signed
 * 32-bit integer. This character string is passed in as a uint8_t pointer.
 * The number of digits in the character set is also passed in as a uint8_t
 * integer.
 *
 * This function is able to handle sign data and supports bases 2, 8, 10 and
 * 16.
 *
 * @param ptr Pointer to the ASCII string
 * @param digits The number of digits in the character set
 * @param base Value of the base to convert from
 *
 * @return Length of the converted data (including null terminator and
 * negative sign)
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
