from collections import Counter

arr = [1,2,3,5,89,9,1,3,5,3,3,89]
arr.sort()
arrsum = 0
for i in range(0,len(arr)):
    arrsum +=arr[i]

mean = arrsum/len(arr)
n = len(arr)

if n% 2 ==1:
    median = arr[n//2]
else:
    median = (arr[n//2]+arr[n//2]-1)/2
val = Counter(arr)
findmode = dict(val)
mode = [i for i, v in findmode.items() if v == max(list(val.values()))]  
findMode = "The mode of a number is / are: " + ', '.join(map(str, mode))
print(findMode)

print( mean)
print(median)

