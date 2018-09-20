/******************************************************************************
 * Copyright (C) 2018 by Viviana Quirama
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. The author
 * is not liable for any misuse of this material.
 *
 *****************************************************************************/

/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Viviana Quirama
 * @date 06/09/2018
 *
 */
#include "memory.h"
#include "platform.h"

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

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  bool overlap = false;
  unsigned int i;

  if(src == NULL || dst == NULL){
#ifdef VERBOSE
    PRINTF("Memory Error: Argument is a NULL pointer.\r\n");
#endif
  }
  else{
    if((src < dst) && (src + length > dst)){
      overlap = true;
    }

    if(!overlap){
      my_memcopy(src, dst, length);
    }
    else{
      i = length;
      while(i > 0){
        *(dst + i - 1) = *(src + i - 1);
        i--;
      }
    }
  }
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  unsigned int i;

  if(src == NULL || dst == NULL){
#ifdef VERBOSE
    PRINTF("Memory Error: Argument is a NULL pointer.\r\n");
#endif
  }
  else{
    i = 0;
    while(i < length){
      *(dst + i) = *(src + i);
      i++;
    }
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  unsigned int i;

  if(src == NULL){
#ifdef VERBOSE
    PRINTF("Memory Error: Argument is a NULL pointer.\r\n");
#endif
  }
  else{
    i = 0;
    while(i < length){
      *(src + i) = value;
      i++;
    }
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  unsigned int i;

  if(src == NULL){
#ifdef VERBOSE
    PRINTF("Memory Error: Argument is a NULL pointer.\r\n");
#endif
  }
  else{
    i = 0;
    while(i < length){
      *(src + i) = 0;
      i++;
    }
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  uint8_t * dest;
  uint8_t aux;

  if(src == NULL){
#ifdef VERBOSE
    PRINTF("Memory Error: Argument is a NULL pointer.\r\n");
#endif
  }
  else{
    dest = src + length - 1;
    while(src < dest){
      aux = *src;
      *src = *dest;
      *dest = aux;
      src++;
      dest--;
    }
  }
  return src;
}

int32_t * reserve_words(size_t length){
  int32_t * ptr = (int32_t *)malloc(length * sizeof(int32_t));
  if(ptr == NULL){
#ifdef VERBOSE
    PRINTF("Memory Error: No memory available.\r\n");
#endif
  }
  return ptr;
}

void free_words(uint32_t * src){
  free(src);
}
