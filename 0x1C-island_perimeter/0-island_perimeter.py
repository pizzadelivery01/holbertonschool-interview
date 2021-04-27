#!/usr/bin/python3
"""
Island Perimeter Algo
"""


def island_perimeter(grid):
    """ looks for water"""
    perimeter = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perimeter += 4
                if row and grid[row - 1][col] == 1:
                    perimeter -= 2
                if col and grid[row][col - 1] == 1:
                    perimeter -= 2
    return perimeter
