#!/usr/bin/python3
"""
Module to determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened.
    """
    totalBoxes = len(boxes)
    boxesState = [False] + [True] * (totalBoxes - 1)
    keys = boxes[0]
    for key in keys:
        if key < totalBoxes and boxesState[key] is True:
            boxesState[key] = False
            keys.extend(boxes[key])
    return not any(boxesState)
