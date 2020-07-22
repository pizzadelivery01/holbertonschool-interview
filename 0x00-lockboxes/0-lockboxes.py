#!/usr/bin/python3
"""
lockboxes algo to check if all boxs can be opened from first box with keys
"""


def canUnlockAll(boxes):
    """
    checks if all boxes can be unlocked
    by calling function to get collectable keys
    then compare to amount of boxes
    """
    if boxes != []:
        keys = [0]
        needed = [i[0] for i in enumerate(boxes)]

        getKeys(boxes, keys)

        if len(keys) == len(needed):
            return True
        else:
            return False

    else:
        return False


def getKeys(boxes, keys, key=0):
    """
    recursivly searches boxes for all collectable keys
    """
    for each in boxes[key]:
        if each is None:
            continue
        if each not in keys and each < len(boxes):
            keys.append(each)
            getKeys(boxes, keys, each)
