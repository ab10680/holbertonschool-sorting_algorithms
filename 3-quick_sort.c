#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
if (*a != *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
swap(&array[i], &array[j]);
print_array(array, size);
}
}
swap(&array[i + 1], &array[high]);
print_array(array, size);
return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *               using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}
