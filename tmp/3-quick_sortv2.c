#include "sort.h"

void simple_swap(int *first, int *second)
{
	int copy_value = *first;
	*first = *second;
	*second = copy_value;
}

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    /* pivot */
    int i = (low - 1);  /* Index of smaller element*/
 	int j;

    for (j = low; j <= high- 1; j++) 
    { 
        /* If current element is smaller than the pivot */
        if (arr[j] < pivot) 
        { 
            i++;    /* increment index of smaller element */
			print_array(arr, 10);
            simple_swap(&arr[i], &arr[j]);
        } 
    } 
    simple_swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
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
