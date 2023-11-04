from collections import deque

def find_minimum_clicks(N, links, start, end):
    # Create an adjacency list to represent the web page links
    graph = [[] for _ in range(N)]
    for i in range(N):
        for page in links[i]:
            graph[i].append(page)

    # Initialize a queue for BFS and a visited array to keep track of visited pages
    queue = deque()
    visited = [False] * N

    # Start from the initial web page and set its distance to 0
    queue.append((start, 0))
    visited[start - 1] = True

    while queue:
        current_page, clicks = queue.popleft()

        # Check if the current page is the end page
        if current_page == end:
            return clicks

        # Explore the linked pages from the current page
        for linked_page in graph[current_page - 1]:
            if not visited[linked_page - 1]:
                visited[linked_page - 1] = True
                queue.append((linked_page, clicks + 1))

    # If the end page cannot be reached, return -1
    return -1

# Input
N = int(input())
links = []
for _ in range(N):
    links.append(list(map(int, input().split())))
start, end = map(int, input().split())
 
# Find and print the minimum number of clicks
result = find_minimum_clicks(N, links, start, end)
print(result)
