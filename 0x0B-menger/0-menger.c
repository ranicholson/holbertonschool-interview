#include "menger.h"

/**
 * menger - Function to print a 2d version of a Menger Sponge
 * @level: The level of the Menger Sponge to be drawn
 */

void menger(int level)
{
	char spongeChar = '#';
	int levelSize = pow(3, level);
	int heightLoop, widthLoop = 0;
	int spaceChecker = 1;

	if (level < 0)
		return;

	for (; heightLoop < levelSize; heightLoop++)
	{
		for (widthLoop = 0; widthLoop < levelSize; widthLoop++)
		{
			spaceChecker = 1;
			spongeChar = '#';
			while (spaceChecker < levelSize)
			{
				if ((heightLoop / spaceChecker) % 3 == 1 &&
					(widthLoop / spaceChecker) % 3 == 1)
				{
					spongeChar = ' ';
					break;
				}
				spaceChecker *= 3;
			}
			printf("%c", spongeChar);
		}
		printf("\n");
	}
}
