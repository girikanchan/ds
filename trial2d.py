# Ask the user to enter the input as a string
user_input = input("Enter a list of lists in the format [[1,2,3],[3,6,9]]: ")

# Parse the user input into a Python list using eval()
try:
    user_list = eval(user_input)

    # Check if the user input is a valid list of lists
    if isinstance(user_list, list) and all(isinstance(sublist, list) for sublist in user_list):
        print("User input:", user_list)
    else:
        print("Invalid input. Please enter a list of lists.")
except SyntaxError:
    print("Invalid input. Please enter a valid list of lists.")
