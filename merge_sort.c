#include "sort.h"

void merge(int *array, int left, int mid, int right);
void merge_sort_rec(int *array, int left, int right);

/**
 * merge_sort - Sorts an array using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
merge_sort_rec(array, 0, size - 1);
}

void merge_sort_rec(int *array, int left, int right)
{
int mid;
if (left < right)
{
mid = left + (right - left) / 2;
merge_sort_rec(array, left, mid);
merge_sort_rec(array, mid + 1, right);
merge(array, left, mid, right);
}
}

void merge(int *array, int left, int mid, int right)
{
int i, j, k;
int left_size = mid - left + 1;
int right_size = right - mid;
int *L = malloc(left_size * sizeof(int));
int *R = malloc(right_size * sizeof(int));
for (i = 0; i < left_size; i++)
L[i] = array[left + i];
for (j = 0; j < right_size; j++)
R[j] = array[mid + 1 + j];
i = 0;
j = 0;
k = left;
while (i < left_size && j < right_size)
{
if (L[i] <= R[j])
{
array[k] = L[i];
i++;
}
else
{
array[k] = R[j];
j++;
}
k++;
}
while (i < left_size)
{
array[k] = L[i];
i++;
k++;
}
while (j < right_size)
{
array[k] = R[j];
j++;
k++;
}
free(L);
free(R);
}
