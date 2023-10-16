def Last_man_left_with_gun(n):
    if n == 1:
        return 1
    else:
        # Calculate the position of the last person left using recursion
        return (Last_man_left_with_gun(n - 1) + 1) % n + 1

# Number of men in the circle
n = 100

# Finding the last person left
survivor = Last_man_left_with_gun(n)

print("The person left with the gun is number:", survivor)
