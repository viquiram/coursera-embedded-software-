/******************************************************************************
 * Copyright (C) 2018 by Viviana Quirama
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. The author
 * is not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Header file for statistical analytics on a dataset
 *
 * This file contains the declarations of some functions that allow to analize
 * an array of unsigned char data items and report analytics on the maximum,
 * minimum, mean, and median of the data set. In addition, it is possible to
 * reorder this data set from large to small and print the data to the screen
 * in a nicely formatted presentation.
 *
 * @author Viviana Quirama
 * @date 22/08/2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Function that prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 * @param ptr An unsigned char pointer to an n-element data array
 * @param size An unsigned integer as the size of the array
 *
 * @return void
 */
void print_statistics(unsigned char * ptr, unsigned int size);


/**
 * @brief Given an array of data and a length, prints the array to the screen.
 *
 * @param ptr An unsigned char pointer to an n-element data array
 * @param size An unsigned integer as the size of the array
 *
 * @return void
 */
#ifdef VERBOSE
void print_array(unsigned char * ptr, unsigned int size);
#endif

/**
 * @brief Given an array of data and a length, returns the median value
 * 
 * After calling this function, the array is sorted.
 *
 * @param ptr An unsigned char pointer to an n-element data array
 * @param size An unsigned integer as the size of the array
 *
 * @return Median value (rounded down to the nearest integer) of the dataset
 */
unsigned char find_median(unsigned char * ptr, unsigned int size);


/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param ptr An unsigned char pointer to an n-element data array
 * @param size An unsigned integer as the size of the array
 *
 * @return Mean value (rounded down to the nearest integer) of the dataset
 */
unsigned char find_mean(unsigned char * ptr, unsigned int size);


/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param ptr An unsigned char pointer to an n-element data array
 * @param size An unsigned integer as the size of the array
 *
 * @return Maximum value of the dataset
 */
unsigned char find_maximum(unsigned char * ptr, unsigned int size);


/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param ptr An unsigned char pointer to an n-element data array
 * @param size An unsigned integer as the size of the array
 *
 * @return Minimum value of the dataset
 */
unsigned char find_minimum(unsigned char * ptr, unsigned int size);


/**
 * @brief Given an array of data and a length, sorts the array from largest
 * to smallest.
 *
 * The zeroth Element should be the largest value, and the last element (n-1)
 * should be the smallest value.
 *
 * @param ptr An unsigned char pointer to an n-element data array
 * @param size An unsigned integer as the size of the array
 *
 * @return void
 */
void sort_array(unsigned char * ptr, unsigned int size);


/**
 * @brief A utility function to swap two unsigned char items.
 *
 * @param a An unsigned char pointer to the first element
 * @param b An unsigned char pointer to the second element
 *
 * @return void
 */
void swap(unsigned char * a, unsigned char  * b);


/**
 * @brief Function that implements the QuickSort algorithm in descending order
 *
 * @param ptr Array to be sorted
 * @param begin Starting index
 * @param end Ending index
 *
 * @return void
 */
void quick_sort(unsigned char * ptr, unsigned int begin, unsigned int end);

#endif /* __STATS_H__ */
