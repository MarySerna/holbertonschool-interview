#!/usr/bin/python3
"""
Calculates the fewest number of operations needed to result in exactly n H characters.
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n H characters.
    """
    i = 2
    m = 0
    r = n
    while True:
        if r % i == 0:
            r /= i
            m += i
        else:
            i += 1
        if r == 1 or i == n:
            break

    return m
