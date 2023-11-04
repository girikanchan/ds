# Read the inputs
m1 = int(input())
m2 = int(input())
N = int(input())
populations = list(map(int, input().split()))

# Initialize variables to keep track of the total time for each center
time_center1 = 0
time_center2 = 0

# Sort the villages by population in descending order
populations.sort(reverse=True)

# Distribute the villages to the two centers
for i in range(N):
    if i % 2 == 0:
        time_center1 += populations[i] * m1
    else:
        time_center2 += populations[i] * m2

# Find the maximum time among the two centers
max_time = max(time_center1, time_center2)

# Output the result
print(max_time)
