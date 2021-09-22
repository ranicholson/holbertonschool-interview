#!/usr/bin/python3
"""Method to determine if dataset is a valid UTF-8 encoding"""


def validUTF8(data):
    """Checks for valid UTF-8 encoding"""
    count = 0
    for item in data:
        if count == 0:
            if (item >> 5) == 0b110:
                count = 1
            elif (item >> 4) == 0b1110:
                count = 2
            elif (item >> 3) == 0b11110:
                count = 3
            elif (item >> 7):
                count = 0
        else:
            if (item >> 6) != 0b10:
                return False
            count -= 1
    if count > 0:
        return False

    return True
