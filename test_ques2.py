def divide(a, b):
    try:
        result = a / b
        return result
    except ZeroDivisionError:
        print("Error: Division by zero")
        return None

def main():
    numbers = [9, 33, 0, 7, 2, 82, 77]
    n = len(numbers)

    '''
    x = int(input())
    mat = []
    for i in range(0,x):
        mat.append([])
    
    for i in range(0,x):
        mat[i]= int(input())
    
    print(mat)

    '''
    if n < 2:
        print("Array must have at least two numbers/elements to perform division.")
        return

    # Divide the first number by the last number of the array
    result = divide(numbers[0], numbers[-1])
    if result is not None:
        print(f"{numbers[0]} / {numbers[-1]} = {result:.3f}")
    else:
        print(f"{numbers[0]} / {numbers[-1]} = Undefined (Division by Zero)")

    # Divide each number by the next number
    for i in range(n - 1):
        num1 = numbers[i]
        num2 = numbers[i + 1]
        result = divide(num1, num2)
        if result is not None:
            print(f"{num1} / {num2} = {result:.3f}")
        else:
            print(f"{num1} / {num2} = Undefined (Division by Zero)")

if __name__ == "__main__":
    main()
