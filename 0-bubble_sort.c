#include "sort.h"
/**
 * bubble_sort - sort array from min to max
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t j, inx, temp = 0;

	if (size < 2)
		return;
	for (j = 0; j < size; j++)
		for (inx = 0; inx < size; inx++)
		{
			if (array[inx] > array[inx + 1] && array[inx + 1])
			{
			temp = array[inx];
			array[inx] = array[inx + 1];
			array[inx + 1] = temp;
			print_array(array, size);
			}
		}
}
