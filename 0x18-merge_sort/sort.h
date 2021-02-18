#ifndef MERGE_S
#define MERGE_S

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge(int *array, int *subarray, int left, int right, int mid);
void merge_split(int *array, int *subarray, int left, int right);

#endif
