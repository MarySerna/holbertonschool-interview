#!/usr/bin/python3
"""
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total
"""


def makeChange(coins, total):
    """
    - If total is 0 or less, return 0
    - If total cannot be met by any number of coins you have, return -1
    """
    if total <= 0:
        return 0

    array = [float('inf')] * (total + 1)
    array[0] = 0

    for i in range(1, len(array)):
        for j in range(len(coins)):
            if coins[j] <= i:
                array[i] = min(array[i], array[i - coins[j]] + 1)

    return array[i] if array[i] != float('inf') else -1