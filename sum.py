def max_sum_string(numstr):
    max_sum = float('-inf')
    
    for i in range(len(numstr)):
        for j in range(i + 1, len(numstr)):
            num1 = int(numstr[i] + numstr[j])
            if j + 1 < len(numstr):  # Check if there are more characters left
                num2 = int(numstr[j + 1:])
                max_sum = max(max_sum, num1 + num2)

    return max_sum

numstr = "4132"
result = max_sum_string(numstr)
print(result)
