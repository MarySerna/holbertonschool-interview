#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - adds two sandpiles together and topples once
 * @grid1: grid to be added
 * @grid2: grid to be added
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	add_piles(grid1, grid2);
	while (grid_unstable(grid1))
	{
		print_grid(grid1);
		topple(grid1, grid2);
		add_piles(grid1, grid2);
	}
}

/**
 * add_piles - adds two sandpiles together
 * @grid1: grid to be added, changed to new value
 * @grid2: grid to be added, zero'd out after
 * 
 * Return: void.
 */
void add_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
}

/**
 * grid_unstable - check if grid is stable
 * @grid: grid with values that must be < 3
 *
 * Return: 1 if unstable, else 0
 */
int grid_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * print_grid - print the array as a grid
 * @grid: grid being printed
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - topple cells of the sandpile > 3
 * @grid1: grid being toppled
 * @grid2: save tmp values of overflow
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				if (i > 0)
					grid2[i - 1][j] += 1;

				if (j > 0)
					grid2[i][j - 1] += 1;

				if (i < 2)
					grid2[i + 1][j] += 1;

				if (j < 2)
					grid2[i][j + 1] += 1;

				grid1[i][j] -= 4;
			}
	add_piles(grid1, grid2);
}