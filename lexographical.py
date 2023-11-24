n=int(input())
a=""
for i in range(n):
    p=input()
    s=input()
    for j in p:
        if j in a:
            continue
        elif j in s:
            a=a+j
    print(a)
    print("\n")