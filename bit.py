'''def get_bit(n,pos):
    return ((n & (1<<pos)) !=0)

print(get_bit(5,2))'''

def set_bit(n,pos):
    return (n | (1<<pos))

print(set_bit(5,1))
