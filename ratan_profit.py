def solve(v):
    n = len(v)
    if n == 0:
        return 0
    mx = v[0]
    for i in range(1, n):
        mx = max(mx, v[i])
    if mx <= 0:
        return 0
    mxSum = 0
    cSum = 0
    for i in range(n):
        cSum += v[i]
        if cSum < 0:
            cSum = 0
        mxSum = max(mxSum, cSum)
    return mxSum

def main():
    n = int(input())
    price = list(map(int, input().split()))
    diff = []
    for i in range(n - 2, -1, -1):
        diff.append(price[i + 1] - price[i])
    ans = solve(diff)
    if ans < 0:
        print(0)
    else:
        print(ans)

if __name__ == "__main__":
    main()
