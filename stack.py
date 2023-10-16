import collections
from collections import deque

class stack:
    def __init__(self):
        self.container = deque()

    def push(self,val):
        self.container.append(val)

    def pop(self):
        self.container.pop()

    def peek(self):
        return self.container[-1]

    def is_empty(self):
        return len(self_container)==0

    def size(self):
        return len(self.container)

if __name__ == '__main__':
    st = stack()
    for i in range(0,5):
       ele = input()
       st.push(ele)
    h = st.size()
    print(h)
