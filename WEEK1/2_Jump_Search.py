# Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not.
# Also, find total number of comparisons for each input case.

import math

def jump_search(arr, key):
    n = len(arr)
    comparisons = 0

    step = int(math.sqrt(n))
    prev = 0

    
    while prev < n and arr[min(step, n) - 1] < key:
        comparisons += 1
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return False, comparisons

   
    while prev < min(step, n):
        comparisons += 1
        if arr[prev] == key:
            return True, comparisons
        prev += 1

    return False, comparisons


t = int(input("enter no. of test cases: "))

while t > 0:
    n = int(input("enter size: "))
    arr = []
    for i in range(n):
        num = int(input())
        arr.append(num)
    key = int(input("enter the target value: "))

    is_present, comparisons = jump_search(arr, key)

    if is_present:
        print("Present", comparisons)
    else:
        print("Not Present", comparisons)

    t -= 1