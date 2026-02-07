def find_three_indices(arr, n):
    for k in range(n - 1, 1, -1):
        i = 0
        j = k - 1

        while i < j:
            s = arr[i] + arr[j]

            if s == arr[k]:
                return True, i, j, k
            elif s < arr[k]:
                i += 1
            else:
                j -= 1

    return False, -1, -1, -1


T = int(input())

arr = []
while T > 0:
    n = int(input())

    for i in range(n):
        arr.append(int(input()))

    found, iPos, jPos, kPos = find_three_indices(arr, n)

    if found:
        print(iPos, jPos, kPos)
    else:
        print("No sequence found")
    arr.clear()
    T -= 1

print("End of Program")