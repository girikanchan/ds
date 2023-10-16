def dfs(node,graph,visited,k):
    if visited[node]:
        return 0

    visited[node] = True
    connected_nodes = 1

    for neighbor in graph[node]:
        connected_nodes += dfs(neighbor,graph,visited,k)
        return connected_nodes

def find(graph,n,k):
    num_upright_node = 0
    visited = [False]*n

    for node in range(n):
        connected_nodes = dfs(node,graph,visited,k)
        if connected_nodes >=k:
            num_upright_node += 1
    return num_upright_node

graph = {
    0: [1,2],
    1: [0,2,3],
    2: [0,1,3]
    }
n = 3
k = 2
print(find(graph,n,k))
