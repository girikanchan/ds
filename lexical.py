def lexicographically_smallest_string(S):
    n = len(S)
    ray = list(S)
    ben = []
    kevin = []
    while ray:
        ben.append(ray.pop(0))
        while ben and kevin and ben[-1] <= kevin[0]:
            kevin.insert(0, ben.pop())
    return ''.join(kevin)

S = 'bda'
print(lexicographically_smallest_string(S))