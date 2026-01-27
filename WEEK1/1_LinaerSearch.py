# Given an array of nonnegative integers, design a linear algorithm and implement it 
# using a program to find whether given key element is present in the array or not. Also, find total number of occurences for the target element.
# (Time Complexity = O(n), where n is the size of input) 

def linear_Search(arr,n,key):
    occurence = 0
    idx = -1
    for i in range(n):
        if key==arr[i]:
            idx = i
            occurence+=1
    return idx,occurence


t = int(input("Enter the test cases: "))
while(t>0):
    arr = []
    n = int(input("Enter the size: "))
    for i in range(n):
        num = int(input())
        arr.append(num)

    key = int(input("Enter the target: "))
    idx , occurence = linear_Search(arr,n,key)
    
    if(idx!=-1):
        print(f"element found at {idx}")
        print(f"element occured at {occurence} times")
    else:
        print("element not found")

    arr.clear()

    t-=1