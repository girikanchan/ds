def reverse(n):
    while(n>0):
        ld = n%10;
        rev = rev * 10 + ld
        n = n/10
    return rev

n = input(int())
print(reverse(n))
