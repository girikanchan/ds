#adding diagonal values in python of 2d array
arr = [[1,2,3],[1,2,3],[4,5,6]]
for i in range(len(arr)):
    total = 0
    total += arr[i][i]
print(total)