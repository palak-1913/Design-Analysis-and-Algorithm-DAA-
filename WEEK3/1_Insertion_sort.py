def insertion_sort_count(arr):
    comparisons = 0
    shifts = 0
    n = len(arr)

    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0:
            comparisons += 1

            if arr[j] > key:
                arr[j + 1] = arr[j]
                shifts += 1
                j -= 1
            else:
                break

        arr[j + 1] = key

    return comparisons, shifts


# Main program
T = int(input())

while T > 0:
    n = int(input())
    arr = list(map(int, input().split()))

    comparisons, shifts = insertion_sort_count(arr)

    # Print sorted array
    print(*arr)
    print(comparisons)
    print(shifts)

    T -= 1