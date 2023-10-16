class HashTable:
    def __init__(self):
        self.MAX = 100
        self.arr = [None for i  in range(self.MAX)]

    def hash(self,key):
        h = 0
        for char in key:
            h += ord(char)
        return h % self.MAX

    def __setitem__(self,key,val):
        h = self.hash(key)
        self.arr[h] = val

    def __getitem__(self,key):
        h = self.hash(key)
        return self.arr[h]


if __name__ == '__main__':
    ha = HashTable()
    ha['hello'] = 120
    ha['hey'] = 12
    ha['hello']
