#!/usr/bin/python3
"""
Rain challenge
"""


def rain(walls):
    """
    Calculate how much water will be
    retained after it rains
    """
    left_max, right_max, waterain = 0, 0, 0
    left, right = 0, len(walls) - 1

    if not walls:
        return (0)
    while (left <= right):
        left_max = max(left_max, walls[left])
        right_max = max(right_max, walls[right])
        if left_max < right_max:
            waterain += left_max - walls[left]
            left += 1
        else:
            waterain += right_max - walls[right]
            right -= 1

    return waterain
