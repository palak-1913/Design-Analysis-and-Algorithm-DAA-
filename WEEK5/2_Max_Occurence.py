# Finds alphabet with max occurrence
def findMaxOcc(arr):
    count = [0] * 26   # frequency array for a-z

    # count frequency
    for ch in arr:
        count[ord(ch) - ord('a')] += 1

    maxCount = 0
    result = ''

    # find max occurring character
    for i in range(26):
        if count[i] > maxCount:
            maxCount = count[i]
            result = chr(i + ord('a'))

    # output result
    if maxCount <= 1:
        print("No Duplicates Present")
    else:
        print(result, maxCount)


# main program
T = int(input())

arr = []   # declared outside loop

while T > 0:
    n = int(input())

    for _ in range(n):
        ch = input().strip()
        arr.append(ch)

    findMaxOcc(arr)

    arr.clear()   # clear for next test case
    T -= 1