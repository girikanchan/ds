x = int(input())
y = int(input())
mat = []
for i in range(0,x):
    mat.append([])

for i in range(0,x):
    for j in range(0,y):
        mat[i].append(j)
        mat[i][j] = 0

for i in range(0,x):
    for j in range(0,y):
        mat[i][j] = int(input())

print(mat)
