/******************************************************************************
 * Copyright (C) 2018 by Viviana Quirama
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. The author
 * is not liable for any misuse of this material.
 *
 *****************************************************************************/

/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls.
 *
 * @author Viviana Quirama
 * @date 06/09/2018
 *
 */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero.
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a given number of bytes from source to destination
 *
 * This function takes two byte pointers (one source and one destination) and
 * a length of bytes to move from the source location to the destination.
 * It is able to handle overlap of source and destination, without data
 * corruption.
 *
 * @param src Pointer to the source
 * @param dst Pointer to the destination
 * @param lenght Number of bytes to move
 *
 * @return Pointer to the destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a given number of bytes from source to destination
 *
 * This function takes two byte pointers (one source and one destination) and
 * a length of bytes to copy from the source location to the destination.
 *
 * The behavior is undefined if there is overlap of source and destination.
 * Copy should still occur, but will likely corrupt your data.
 *
 * @param src Pointer to the source
 * @param dst Pointer to the destination
 * @param lenght Number of bytes to copy
 *
 * @return Pointer to the destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets the given number of bytes from source to a value
 *
 * This function takes a pointer to a source memory location, a length in
 * bytes and set all locations of that memory to a given value.
 *
 * @param src Pointer to the source
 * @param lenght Number of bytes to set
 * @param value Value to set in all memory locations
 *
 * @return Pointer to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets the given number of bytes from source to a value
 *
 * This function takes a pointer to a memory location, a length in bytes and
 * zero out all of the memory.
 *
 * @param src Pointer to the source
 * @param lenght Number of bytes to set
 *
 * @return Pointer to the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of some bytes from a memory location
 *
 * This function takes a pointer to a memory location and a length in bytes
 * and reverse the order of all of the bytes.
 *
 * @param src Pointer to the source
 * @param lenght Number of bytes to reverse
 *
 * @return Pointer to the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates words in memory
 *
 * This function takes a take number of words to allocate in dynamic memory
 *
 * @param lenght Number of words to allocate
 *
 * @return Pointer to memory if successful allocation, otherwise NULL
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free words in memory
 *
 * This function free a dynamic memory allocation by providing the pointer
 * source to the function.
 *
 * @param src Pointer to the source
 * 
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
