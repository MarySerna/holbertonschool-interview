#!/usr/bin/python3
"""
Calculates the fewest number of operations needed to result in exactly n H characters.
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n H characters.
    """

    if n <= 1:
        return 0

    i = 2
    m = 0
    r = n
    while r > 1 and i <= n:
        if r % i == 0:
            r /= i
            m += i
        else:
            i += 1
    return m

