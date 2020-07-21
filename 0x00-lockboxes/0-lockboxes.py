#!/usr/bin/python3
"""
lockboxes algorithim to check if all boxs can be opened from first box with keys
"""


def canUnlockAll(boxes):
    """ 
    checks if all boxes can be unlocked 
    by calling function to get collectable keys
    then compare to amount of boxes
    """
    if boxes:
        keys = [0]
        needed = [i[0] for i in enumerate(boxes)]

        getKeys(boxes, keys)

        if sorted(keys) == needed:
            return True
        else:
            return False
    
    else:
        return False


def getKeys(boxes, keys, key=0):
    for each in boxes[key]:
        if each not in keys and each < len(boxes):
            keys.append(each)
            getKeys(boxes, keys, each)