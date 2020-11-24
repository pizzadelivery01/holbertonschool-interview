#!/usr/bin/python3

def rain(walls):

    result = 0
    left_max = 0
    right_max = 0
    lo = 0
    hi = len(walls) - 1

    while(lo <= hi):
        if(walls[lo] < walls[hi]):
            if(walls[lo] > left_max):
                left_max = walls[lo]
            else:
                result += left_max - walls[lo]
            lo += 1
        else:
            if(walls[hi] > right_max):
                right_max = walls[hi]
            else:
                result += right_max - walls[hi]
            hi -= 1

    return result
