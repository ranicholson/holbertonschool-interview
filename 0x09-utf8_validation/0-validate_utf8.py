#!/usr/bin/python3
"""Method to determine if dataset is a valid UTF-8 encoding"""


def validUTF8(data):
    """Checks for valid UTF-8 encoding"""
    count = 0
    for item in data:
        item = item & 255
        if count == 0:
            if (item >> 7) == 0:
                count = 0
            elif (item >> 5) == 6:
                count = 1
            elif (item >> 4) == 14:
                count = 2
            elif (item >> 3) == 30:
                count = 3
            else:
                return False
        else:
            if (item >> 6) != 0b10:
                return False
            count -= 1

    if count > 0:
        return False

    return True
