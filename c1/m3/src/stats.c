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
#include "platform.h"


void print_statistics(unsigned char * ptr, unsigned int size){
    PRINTF("\tMinimum: %d\r\n", find_minimum(ptr, size));
    PRINTF("\tMaximum: %d\r\n", find_maximum(ptr, size));
    PRINTF("\tMean: %d\r\n", find_mean(ptr, size));
    PRINTF("\tMedian: %d\r\n", find_median(ptr, size));
}


void print_array(unsigned char * ptr, unsigned int size){
#ifdef VERBOSE
    int i = 0;
    while(i < size){
        if(i%10 == 0){
            PRINTF("\r\n\t");
        }
        PRINTF("%3u", ptr[i++]);
        if(i < size){
            PRINTF(", ");
        }
        else{
            PRINTF(".\r\n");
        }
    }
#endif
}


unsigned char find_median(unsigned char * ptr, unsigned int size){
    unsigned char median;
    sort_array(ptr, size);
    if (size%2 != 0){
        median = ptr[size/2 + 1];
    }
    else{
        median = find_mean(ptr + size/2 - 1, 2);
    }
    return median;
}


unsigned char find_mean(unsigned char * ptr, unsigned int size){
    unsigned char mean;
    unsigned int sum = 0;
    unsigned int i = 0;
    while(i < size){
        sum += ptr[i++];
    }
    mean = sum/size;
    return mean;
}


unsigned char find_maximum(unsigned char * ptr, unsigned int size){
    unsigned char max;
    unsigned int i = 0;
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


unsigned char find_minimum(unsigned char * ptr, unsigned int size){
    unsigned char min;
    unsigned int i = 0;
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
    unsigned int i, j, pivot;

    if (begin < end){
        pivot = ptr[begin];
        i = begin + 1;
        j = end;
        while ( i < j ){
            while (ptr[i] > pivot && i < end) i++;
            while (ptr[j] < pivot) j--;
            if (i < j){
                swap(&ptr[i++], &ptr[j++]);
            }
        }
        if(pivot < ptr[j]){
            swap (&ptr[begin], &ptr[j]);
        }
        quick_sort(ptr, begin, j-1);
        quick_sort(ptr, j+1, end);
    }
}
