#!/usr/bin/python3

"""Trying to determine if all lockboxes can be opened
    Keys inside boxes open boxes with matching number
"""


def canUnlockAll(boxes):
    """ Method to determine if all boxes can be opened
boxes (list): list of lists containing boxes and keys
Return: True if all boxes can be opened, otherwise False
    """
    if len(boxes) == 0:
        return (False)

    key_list = boxes[0]
    box_count = len(boxes) - 1
    x = 0
    while x < len(key_list):
        if x < len(boxes) - 1:
            if boxes[x] == []:
                x += 1
                continue
            key_list.extend(boxes[x])
            boxes[x] = []
            box_count -= 1
            if box_count == 0:
                return (True)
        x += 1
    return (False)
