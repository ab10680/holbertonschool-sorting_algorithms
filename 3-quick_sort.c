#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto scheme.
 * @array: The array to be partitioned.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of the full array.
 *
 * Return: Index of the pivot after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j, temp;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j && array[i] != array[j])
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
else if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
}
}
}
if ((i + 1) != high && array[i + 1] != array[high])
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}
else if ((i + 1) != high)
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
}
return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for quick sort.
 * @array: The array to sort.
 * @low: Start index.
 * @high: End index.
 * @size: Size of the full array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pivot;
if (low < high)
{
pivot = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}
