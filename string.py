#You are given a binary string, find maximum number of substrings containing "011" or "100" when only a single bit is flipped.
'''def max_substrings_with_flip(binary_string):
    count = 0
    n = len(binary_string)
    
    for i in range(n - 2):
        if binary_string[i:i+3] == "011" or binary_string[i:i+3] == "100":
            count += 1
    
    for i in range(n - 2):
        # Flip 0 to 1
        if binary_string[i:i+3] == "001" or binary_string[i:i+3] == "010":
            count += 1
        # Flip 1 to 0
        if binary_string[i:i+3] == "110" or binary_string[i:i+3] == "101":
            count += 1
            
    return count

# Example usage
binary_string = "101101100111"
result = max_substrings_with_flip(binary_string)
print(result)  # Output will be the maximum number of valid substrings after flipping a single bit'''
'''def max_deletions_for_unique_occurrences(S):
    frequency_map = {}
    
    # Count the occurrences of each letter
    for letter in S:
        frequency_map[letter] = frequency_map.get(letter, 0) + 1
    
    occurrence_counts = set()
    total_deletions = 0
    
    # Count how many letters occur a certain number of times
    for count in frequency_map.values():
        while count in occurrence_counts:
            total_deletions += 1
            count -= 1
        if count > 0:
            occurrence_counts.add(count)
    
    return total_deletions

# Example usage
S = "abcaabccd"
result = max_deletions_for_unique_occurrences(S)
print(result)  # Output will be the maximum number of deletions needed'''
import heapq
from collections import defaultdict

def main():
    str_input = input()
    char_count = defaultdict(int)
    
    for char in str_input:
        char_count[char] += 1
    
    queue = []
    
    for count in char_count.values():
        queue.append(-count)
    
    heapq.heapify(queue)
    
    count = 0
    while len(queue) > 0:
        top = -heapq.heappop(queue)
        if len(queue) == 0:
            break
        curr_top = -queue[0]
        if top == curr_top:
            top -= 1
            if top >= 0:
                count += 1
                heapq.heappush(queue, -top)
    
    print(count)

if __name__ == "__main__":
    main()


