def merge(a, l, m, r, counters):
    n1 = m - l + 1
    n2 = r - m

    L = a[l:m + 1]
    R = a[m + 1:r + 1]

    i = 0
    j = 0
    k = l

    while i < n1 and j < n2:
        counters[0] += 1   # comparisons

        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
            counters[1] += (n1 - i)   # inversions
        k += 1

    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1


def merge_sort(a, l, r, counters):
    if l < r:
        m = l + (r - l) // 2

        merge_sort(a, l, m, counters)
        merge_sort(a, m + 1, r, counters)
        merge(a, l, m, r, counters)


# -------- Main Program (C++ Style) --------
T = int(input())
a = []
while T > 0:
    n = int(input())

  
    for _ in range(n):
        x = int(input())
        a.append(x)

    comparisons = 0
    inversions = 0

    counters = [comparisons, inversions]

    merge_sort(a, 0, n - 1, counters)

    # Sorted array
    print(*a)

    # Comparisons
    print(counters[0])

    # Inversions
    print(counters[1])

    a.clear()
    T -= 1