import re
'''
Python Regex – 

To get List of all Numbers from String, we use:

numbers = re.findall('[0-9]+', str)
'''
def find_sum_of_number_divisble_by_three_and_last_divisible_by_3(input_string):
    # Initialize variables to store the sum and last divisible by 3.
    total_sum = 0
    find_sum_of_number_divisble_by_three_and_last_divisible_by_3 = None

    # Use regular expression to find all numbers in the string.
    numbers = re.findall(r'\d+', input_string)

    # Iterate through the extracted numbers.
    for number in numbers:
        num = int(number)
        # Check if the number is divisible by 3.
        if num % 3 == 0: 
            total_sum += num # if number is divisible by three 
            find_sum_of_number_divisble_by_three_and_last_divisible_by_3 = num  #getting the last number divisible by 3

    return total_sum, find_sum_of_number_divisble_by_three_and_last_divisible_by_3

# Example:
'''
# Get input from the user.
input_string = input("Enter a string: ")

'''

input_string = "the best 6 out of 8 will get 9 points"
sum_result, last_result = find_sum_of_number_divisble_by_three_and_last_divisible_by_3(input_string)
print("Sum of numbers divisible by 3:", sum_result)
print("Last number divisible by 3:", last_result)
