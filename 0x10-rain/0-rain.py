#!/usr/bin/python3
"""
Funciton to measure amount of rain water caught
between walls of various sizes provided in a list
"""


def rain(walls):
    """Calculatin rain water caught"""

    listLength = len(walls)

    if (listLength <= 0):
        return (0)

    rainWater = 0

    for x in range(1, listLength - 1):
        wallCheck1 = wallCheck2 = walls[x]

        for y in range(x):
            wallCheck1 = max(wallCheck1, walls[y])

        for z in range(x + 1, listLength):
            wallCheck2 = max(wallCheck2, walls[z])

        rainWater += min(wallCheck1, wallCheck2) - walls[x]

    return (rainWater)
