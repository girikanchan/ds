#square the number given in list
def square_number(number):
    squared_number = []
    for n in number:
        square_number.append(n*n)
    return squared_number

number = [2,3,4,5,6,7]
square_number(number)