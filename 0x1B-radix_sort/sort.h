#ifndef __SORT_H_
#define __SORT_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void count_radix_sort(int *array, size_t size, int exp);

#endif /* __SORT_H_ */
