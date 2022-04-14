#!/usr/bin/python3

"""
Returns list of integers representing pascal triangle
"""


def pascal_triangle(n):
    """pascal triangle fun"""

    if n <= 0:
        return []

    pascTriag = [[1]]

    for x in range(1, n):
        triagRow = [1]

        for y in range(1, x):
            triagNum = pascTriag[x-1][y-1] + pascTriag[x-1][y]
            triagRow.append(triagNum)
        triagRow.append(1)
        pascTriag.append(triagRow)

    return pascTriag
