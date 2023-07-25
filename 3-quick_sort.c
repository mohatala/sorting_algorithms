#include "sort.h"
/**
*swap - the positions of two elements
*@array: array
*@it1: array element
*@it2: array element
*/
void swap(int *array, ssize_t it1, ssize_t it2)
{
	int tmp;

	tmp = array[it1];
	array[it1] = array[it2];
	array[it2] = tmp;
}
/**
 *lomuto_partition - lomuto partition
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the pos of the last element
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pv = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pv)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - quiksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t pos = 0;


	if (first < last)
	{
		pos = lomuto_partition(array, first, last, size);

		qs(array, first, pos - 1, size);
		qs(array, pos + 1, last, size);
	}
}
/**
 *quick_sort -quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
