def selection_sort(arr):
    n = len(arr)

    for i in range(n):
        min_index = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr


# -------- Main Program --------
T = int(input())

while T > 0:
    n = int(input())

    arr = []
    for i in range(n):
        arr.append(int(input()))

    sorted_arr = selection_sort(arr)

    for x in sorted_arr:
        print(x)

    T -= 1
