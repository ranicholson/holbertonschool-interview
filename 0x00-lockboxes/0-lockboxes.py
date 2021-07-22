#!/usr/bin/python3

"""Trying to determine if all lockboxes can be opened
    Keys inside boxes open boxes with matching number
"""


def canUnlockAll(boxes):
    """ Method to determine if all boxes can be opened
boxes (list): list of lists containing boxes and keys
Return: True if all boxes can be opened, otherwise False
    """
    if len(boxes) == 1:
        return (True)

    if boxes[0] == []:
        return (False)

    key_list = boxes[0]
    key_chain = [0]
    while len(key_chain) < len(boxes):
        for key in key_list[:]:
            if key >= len(boxes):
                key_list.remove(key)
                continue
            key_list.extend(boxes[key])
            boxes[key] = []
            key_chain.append(key)
            key_list.remove(key)
            key_chain = list(set(key_chain))
        if len(key_list) == 0 and len(key_chain) < len(boxes):
            return (False)

    return (True)
