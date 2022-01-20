#ifndef SORT_H_
#define SORT_H_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void splitMerge(int *array, int *newArray, size_t size);
void mergeMerge(int *array, int *newArray, size_t size);

#endif
