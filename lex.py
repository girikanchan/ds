def lexicographicallySmallestSequence(n, a, b):
    result = []
    a_set = set(a)
    b_set = set(b)
    
    # Combine the unique elements from both lists
    combined_set = a_set | b_set
    
    # Sort the unique elements
    combined_list = sorted(list(combined_set))
    
    return combined_list

if __name__ == '__main__':
    n = int(input().strip())

    a_count = int(input().strip())
    a = []
    for _ in range(a_count):
        a_item = int(input().strip())
        a.append(a_item)

    b_count = int(input().strip())
    b = []
    for _ in range(b_count):
        b_item = int(input().strip())
        b.append(b_item)

    result = lexicographicallySmallestSequence(n, a, b)
    for item in result:
        print(item)