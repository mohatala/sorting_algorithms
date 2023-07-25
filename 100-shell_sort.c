#include "sort.h"

/**
*swap - the positions of two elements
*@array: array
*@itm1: array element
*@itm2: array element
*/
void swap(int *array, int itm1, int itm2)
{

	int temp;

	temp = array[itm1];
	array[itm1] = array[itm2];
	array[itm2] = temp;
}
/**
 * shell_sort - function that sorts using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gp = 1, j, idx = 0;

	if (array == NULL || size < 2)
		return;
	while (gp < size / 3)
		gp = 3 * gp + 1;
	while (gp >= 1)
	{
		for (j = gp; j < size; j++)
			for (idx = j; idx >= gp &&
			 (array[idx] < array[idx - gp]); idx -= gp)
				swap(array, idx, idx - gp);
		print_array(array, size);
		gp /= 3;
	}
}
