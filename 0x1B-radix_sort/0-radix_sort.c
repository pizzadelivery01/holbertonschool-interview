#include "sort.h"

/**
 * count_radix_sort - Counting sort
 * @array: Array to be sorted
 * @size: Size of the @array
 * @pow: Exponent
 * Return: Nothing.
 */
void count_radix_sort(int *array, size_t size, int pow)
{
	int freq[10] = {0}, j;
	int *output = NULL;
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < size; i++)
		freq[(array[i] / pow) % 10]++;
	for (i = 1; i < 10; i++)
		freq[i] += freq[i - 1];
	for (j = size - 1; j >= 0; j--)
	{
		output[freq[(array[j] / pow) % 10] - 1] = array[j];
		freq[(array[j] / pow) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Radix sorting
 * @array: Array to be sorted
 * @size: Size of the @array
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	uint i = 1;
	int max = 0, pow = 1;

	if (!array || size < 2)
		return;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	while (max)
	{
		count_radix_sort(array, size, pow);
		pow *= 10;
		max /= 10;
	}
}
