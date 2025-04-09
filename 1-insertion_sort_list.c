#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;
if (list == NULL || *list == NULL)
return;
current = (*list)->next; /* Start with the second node */
while (current != NULL)
{
temp = current;
while (temp->prev != NULL && temp->n < temp->prev->n)
{
/* Swap nodes */
listint_t *prev_node = temp->prev;
listint_t *next_node = temp->next;
/* Adjust pointers */
if (next_node)
next_node->prev = prev_node; /* Link next node to previous */
if (prev_node->prev)
prev_node->prev->next = temp; /* Link previous's previous to current */
else
*list = temp; /* Update head if we are at the beginning */
temp->prev = prev_node->prev;
prev_node->next = next_node;
prev_node->prev = temp;
temp->next = prev_node;
/* Print the list after each swap */
print_list(*list);
}
current = current->next;
}
}
