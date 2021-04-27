#!/usr/bin/python3
"""returns a list of lists of integers representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """returns a list of lists of integers representing the Pascal’s triangle of n"""
    pascal = [[1]]
    for _ in range(n - 1):
        pascal += [[1] + [pascal[-1][i] + pascal[-1][i + 1]
                   for i in range(len(pascal[-1]) - 1)] + [1]]
    return pascal if n > 0 else []
