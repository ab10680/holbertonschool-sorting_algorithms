#include "sort.h"

/**
 * insertion_sort - Sorts an array using the Insertion sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void insertion_sort(int *array, size_t size)
{
size_t i, j;
int key;
if (array == NULL || size < 2)
return;
for (i = 1; i < size; i++)
{
key = array[i];
j = i - 1;
while (j < size && array[j] > key)
{
array[j + 1] = array[j];
j--;
}
array[j + 1] = key;
}
}
