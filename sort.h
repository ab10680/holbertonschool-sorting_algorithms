#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */

/* Definition for doubly linked list */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Function prototypes for sorting algorithms */
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);

/* Prototypes for print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */
