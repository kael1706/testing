  
#include "sort.h"

void simple_swap(int *first, int *second)
{
	int copy_value = *first;
	*first = *second;
	*second = copy_value;
}

void bubble_sort(int *array, size_t size)
{
	size_t k, l, n;
	int sort_status = 0;
	n = size - 1;

	if (array == NULL || n <= 0)
		return;
	for (k = 0; k < n; k++)
	{
		for (l = 0; l < n - k; l++)
		{
			if (array[l] > array[l + 1])
			{
				simple_swap(&array[l], &array[l + 1]);
				print_array(array, size);
				sort_status = 1;
			}
		}
		if (sort_status == 0)
			break;
	}
}
