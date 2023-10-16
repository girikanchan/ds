class BST:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None


    def add_child(self,data):
        if data == self.data:
            return

        if data < self.data:
            if self.left:
                self.left.add_child(data)
            else:
                self.left = BST(data)
        else:
            if self.right:
                self.right.add_child(data)
            else:
                self.right = BST(data)

    def in_order(self):
        elements = []
        if self.left:
            elements += self.left.in_order()
        elements.append(self.data)
        if self.right:
            elements += self.right.in_order()
            #elements.append(self.data)
        return elements

    def find_max(self):
        if self.right is None:
            return self.data
        return self.right.find_max()
    def find_min(self):
        if self.left is None:
            return self.data
        return self.left.find_min()

def bulid_tree(elements):
    root = BST(elements[0])
    for i in range(1, len(elements)):
        root.add_child(elements[i])
    return root
        

if __name__ == '__main__':
    number = [14, 34, 1, 0, 3, 67]
    number_tree = bulid_tree(number)
    print(number_tree.in_order())
    print(number_tree.find_max())
    print(number_tree.find_min())

