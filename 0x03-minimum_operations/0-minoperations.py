#!/usr/bin/python3
"""calculates the fewest number of operations needed
to result in exactly n H characters in the file"""

from math import sqrt


def minOperations(n):
    """Sums all the factors of n to find the 'minimum operations'"""
    sumFactors = 0
    if n <= 1:
        return 0
    for i in range(2, int(sqrt(n) + 1)):
        while n % i == 0:
            sumFactors += i
            n /= i
            if n <= 1:
                break
    if n > 1:
        sumFactors += int(n)
    return sumFactors
