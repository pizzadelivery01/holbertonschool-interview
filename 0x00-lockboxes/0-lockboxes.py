#!/usr/bin/python3
"""
lockboxes algo to check if all boxs can be opened from first box with keys
"""


def canUnlockAll(boxes):
    """
    Return True if all boxes open
    """
    boxlist = [boxes[0]]
    boxesleft = [range(1, len(boxes))]
    while (len(boxlist) > 0):
        for i in boxlist:
            for j in i:
                if j in boxesleft:
                    boxlist.append(boxes[j])
                    boxesleft.remove(j)
                if len(boxesleft) == 0:
                    return True
        boxlist.pop(0)

    return False
