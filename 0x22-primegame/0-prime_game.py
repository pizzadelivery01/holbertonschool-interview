#!/usr/bin/python3
""" Return: name of the player that won the most rounds """


def isWinner(x, nums):
    """ sovles prime game"""
    if not nums or x < 1:
        return None
    n = max(nums)
    sorter = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not sorter[i]:
            continue
        for j in range(i*i, n + 1, i):
            sorter[j] = False

    sorter[0] = sorter[1] = False
    c = 0
    for i in range(len(sorter)):
        if sorter[i]:
            c += 1
        sorter[i] = c

    player1 = 0
    for n in nums:
        player1 += sorter[n] % 2 == 1
    if player1 * 2 == len(nums):
        return None
    if player1 * 2 > len(nums):
        return "Maria"
    return "Ben"
