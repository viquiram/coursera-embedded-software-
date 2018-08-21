/******************************************************************************
 * Copyright (C) 2018 by Viviana Quirama
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. The author 
 * is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Implementation file for statistical analytics on a dataset 
 *
 * This file contains the implementations of functions that allow to analize
 * an array of unsigned char data items and report analytics on the maximum, 
 * minimum, mean, and median of the data set. In addition, it is possible to 
 * reorder this data set from large to small and print the data to the screen 
 * in a nicely formatted presentation.
 *
 * @author Viviana Quirama
 * @date 22/08/2018
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}


void print_statistics(unsigned char * ptr, unsigned int size){

}


void print_array(unsigned char * ptr, unsigned int size){

}


int find_median(unsigned char * ptr, unsigned int size){

}


int find_mean(unsigned char * ptr, unsigned int size){

}


int find_maximum(unsigned char * ptr, unsigned int size){

}


int find_minimum(unsigned char * ptr, unsigned int size){

}


void sort_array(unsigned char * ptr, unsigned int size){

}

