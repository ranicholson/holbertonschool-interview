#!/usr/bin/python3


def rotate_2d_matrix(matrix):
    """Function to rotate n x n matrix 90 degrees"""
    n = len(matrix)

    for x in range(0, int(n / 2)):
        for y in range(x, n-x-1):
            numHolder = matrix[x][y]
            matrix[x][y] = matrix[n-1-y][x]
            matrix[n-1-y][x] = matrix[n-1-x][n-1-y]
            matrix[n-1-x][n-1-y] = matrix[y][n-1-x]
            matrix[y][n-1-x] = numHolder
