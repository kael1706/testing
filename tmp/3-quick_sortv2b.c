#include "sort.h"

void simple_swap(int *first, int *second)
{
	int copy_value = *first;
	*first = *second;
	*second = copy_value;
}

int partition(int arr[], int lo, int hi)
{
	int pivot = arr[hi];
	int i = lo;
	int j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			print_array(arr, 10);
			simple_swap(&arr[i], &arr[j]);
			i = i + 1;
		}
	}
	simple_swap(&arr[i], &arr[hi]);
	return (i);
}

/* 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void q_sort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        /* Separately sort elements before */
        /* partition and after partition */
        q_sort(arr, low, pi - 1); 
        q_sort(arr, pi + 1, high); 
    } 
} 

void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1);
}
