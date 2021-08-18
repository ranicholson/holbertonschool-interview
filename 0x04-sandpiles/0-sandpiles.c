#include "sandpiles.h"


/**
 * sandpiles_sum - function to compute sum of two sandpiles
 * @grid1: left 3x3 grid
 * @grid2: right 3x3grid
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y, tempGrid[3][3], pileCheck;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
			tempGrid[x][y] = grid1[x][y];
		}
	}
	pileCheck = collapseChecker(grid1);
	while (pileCheck == 1)
	{
		pilePrinter(grid1);
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				if (grid1[x][y] > 3)
					tempGrid[x][y] -= 4;
				if (x != 0 && grid1[x - 1][y] > 3)
					tempGrid[x][y]++;
				if (x != 2 && grid1[x + 1][y] > 3)
					tempGrid[x][y]++;
				if (y != 0 && grid1[x][y - 1] > 3)
					tempGrid[x][y]++;
				if (y != 2 && grid1[x][y + 1] > 3)
					tempGrid[x][y]++;
			}
		}
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
				grid1[x][y] = tempGrid[x][y];
		}
		pileCheck = collapseChecker(grid1);
	}
}


/**
 * collapseChecker - checks if the pile of the sand will collapse
 * @grid: pile of sand to check
 * Return: 1 if the pile will collapse
 */

int collapseChecker(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (1);
		}
	}

	return (0);
}


/**
 * pilePrinter - prints sandpile
 * @grid: grid to print out
 */

void pilePrinter(int grid[3][3])
{
	int x, y;

	printf("=\n");

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y != 0)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}
