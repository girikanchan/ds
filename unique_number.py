def max_delete_for_unique_occurance(s):
    frequency_map = {}
    for letter in s:
        frequency_map[letter] = frequency_map.get(letter,0) + 1

    occurance_set = set()
    total_deletions = 0

    for count in frequency_map.values():
        while count in occurance_set:
            total_deletions +=1
            count -= 1
        if count>0:
            occurance_set.add(count)
    return total_deletions

s = "abcaabccd"
result = max_delete_for_unique_occurance(s)
print(result)
