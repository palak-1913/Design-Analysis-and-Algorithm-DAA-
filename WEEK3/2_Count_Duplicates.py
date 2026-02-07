def count_duplicates(arr):
    freq = {}
    duplicates = 0

    # Count frequency of each element
    for x in arr:
        if x in freq:
            freq[x] += 1
        else:
            freq[x] = 1

    # Count duplicates
    for x in freq:
        if freq[x] > 1:
            duplicates += freq[x] - 1

    return duplicates


# -------- Main Program --------
T = int(input())

while T > 0:
    n = int(input())

    arr = []
    for i in range(n):
        arr.append(int(input()))

    result = count_duplicates(arr)
    print(result)

    T -= 1