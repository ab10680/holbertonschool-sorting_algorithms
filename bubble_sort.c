#include "sort.h"

/**
 * bubble_sort - Sorts an array using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;
int swapped;
if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++)
{
swapped = 0;
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
swapped = 1;
}
}
if (!swapped)
break; /* Stop if the array is sorted */
}
}
