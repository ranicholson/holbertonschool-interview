#!/usr/bin/python3
"""Finds the minimum number of operations needed"""


def minOperations(n):
    """
    Determine the minimum number of copy/paste operations to get n characters
    Args: n: number of characters to create
    Return: Minimum number of operatrions
    """
    totalOperations = 0

    for x in range(2, n + 1):
        while (n % x == 0):
            totalOperations += x
            n = n / x

    return (totalOperations)
