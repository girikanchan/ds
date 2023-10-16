def check_unique(s):
    frequency_map = {}
    for i in s:
        frequency_map[i] = frequency_map.get(i,0)+1
    occurance_set = set()

    for count in frequency_map.values():
        if count in occurance_set:
            return False
        else:
            occurance_set.add(count)
    return True

s = [1,2,2,1,1,2]
print(check_unique(s))
