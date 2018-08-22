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
#include <math.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

	printf("\r\nInitial dataset:");
    print_array(test, SIZE);
	
	printf("\r\nStatistical analytics on the dataset:\r\n");
	print_statistics(test, SIZE);
	
	printf("\r\nSorted dataset:");
	print_array(test, SIZE);
	
}


void print_statistics(unsigned char * ptr, unsigned int size){
    printf("\tMinimum: %d\r\n", find_minimum(ptr, size));
    printf("\tMaximum: %d\r\n", find_maximum(ptr, size));
    printf("\tMean: %d\r\n", find_mean(ptr, size));
    printf("\tMedian: %d\r\n", find_median(ptr, size));
}


void print_array(unsigned char * ptr, unsigned int size){
	int i = 0;
    while(i < size){
		if(i%10 == 0){
			printf("\r\n\t");
		}
		printf("%3u", ptr[i++]);
		if(i < size){
			printf(", ");
		}
		else{
			printf(".\r\n");
		}
	}
}


int find_median(unsigned char * ptr, unsigned int size){
	int median;
	sort_array(ptr, size);
	if (size%2 != 0){
		median = ptr[size/2 + 1];
	}
	else{
		median = find_mean(ptr + size/2 - 1, 2);
	}
	return median;
}


int find_mean(unsigned char * ptr, unsigned int size){
	int mean;
	float sum = 0;
	int i = 0;
	while(i < size){
		sum += ptr[i++];
	}
	mean = floor(sum/size);
	return mean;
}


int find_maximum(unsigned char * ptr, unsigned int size){
	int max;
	int i = 0;
	if(size > 0){
		max = ptr[i++];
		while(i < size){
			if(max < ptr[i]){
				max = ptr[i];
			}
			i++;
		}
	}
	return max;
}


int find_minimum(unsigned char * ptr, unsigned int size){
	int min;
	int i = 0;
	if(size > 0){
		min = ptr[i++];
		while(i < size){
			if(min > ptr[i]){
				min = ptr[i];
			}
			i++;
		}
	}
	return min;
}


void sort_array(unsigned char * ptr, unsigned int size){
	quick_sort(ptr, 0, size-1);
}


void swap(unsigned char * a, unsigned char * b){
    unsigned char t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(unsigned char * ptr, unsigned int begin, unsigned int end){
	int i, j, pivot;

	if (begin < end){
		pivot = ptr[begin];
		i = begin;
		j = end;
		i++;
		while ( i < j ){      
			while (ptr[i] <= pivot && i < end) i++; 
			while (ptr[j] > pivot) j--;
			if (i < j){
				swap(&ptr[i], &ptr[j]);
			}
		}

		swap (&ptr[begin], &ptr[j]);
		quick_sort(ptr, begin, j-1);
		quick_sort(ptr, j+1, end);
	}
}
