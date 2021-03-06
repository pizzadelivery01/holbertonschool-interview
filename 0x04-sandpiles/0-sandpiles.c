#include "sandpiles.h"

/**
 * sandpiles_sum - adds sandpiles with print
 * @grid1: first
 * @grid2: second
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);
	while (!stable_check(grid1))
	{
		print_g(grid1);
		toppling(grid1);
	}
}
/**
 * print_g - print
 * @grid: grid
 * Return: void
 */
void print_g(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * add_grids - adds grids
 * @grid1: first
 * @grid2: second
 * Return: void
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}
/**
 * stable_check - checking if stable
 * @grid: grid
 * Return: int
 */
int stable_check(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}
/**
 * toppling - topples if unstable
 * @grid1: grid
 * Return: void
 */
void toppling(int grid1[3][3])
{
	int i, j;
	int temp[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			temp[i][j] = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					temp[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					temp[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					temp[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					temp[i][j + 1] += 1;
			}
		}
	}
	add_grids(grid1, temp);
}
