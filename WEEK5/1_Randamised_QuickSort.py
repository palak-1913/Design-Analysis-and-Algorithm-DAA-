import random
import time


def partition_direct(arr, low, high, counters):
    pivot_index = random.randint(low, high)
    pivot = arr[pivot_index]

    i = low
    j = high

    while i <= j:
        # Move i to the right
        while arr[i] < pivot:
            counters[0] += 1
            i += 1
        counters[0] += 1

        # Move j to the left
        while arr[j] > pivot:
            counters[0] += 1
            j -= 1
        counters[0] += 1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            counters[1] += 1
            i += 1
            j -= 1

    return i


def quick_sort(arr, low, high, counters):
    if low < high:
        index = partition_direct(arr, low, high, counters)

        quick_sort(arr, low, index - 1, counters)
        quick_sort(arr, index, high, counters)


# -------- Main Program (Like C++) --------
random.seed(time.time())

T = int(input())
arr = []
while T > 0:
    n = int(input())

    

    for _ in range(n):
        x = int(input())
        arr.append(x)

    comparisons = 0
    swaps = 0

    counters = [comparisons, swaps]

    quick_sort(arr, 0, n - 1, counters)

    # Print sorted array
    print(*arr)
    print(counters[0])
    print(counters[1])

    arr.clear()
    T -= 1