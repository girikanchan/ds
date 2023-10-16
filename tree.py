class Tree:
    def __init__(self,data):
        self.data = data
        self.children = [ ]
        self.parent = None

    def add_child(self,child):
        child.parent = self
        self.children.append(child)

    def get_level(self):
        level = 0
        p = self.parent
        while p:
            level +=1
            p= p.parent
        return level
        

    def print_tree(self):
        spaces = ' ' * self.get_level() *3
        prefix = spaces + "|_ " if self.parent else ""
        print(prefix +self.data)
        if self.children:
            for child in self.children:
                 child.print_tree()


def bulid_product():
    root = Tree("Electronics")
    
    laptop = Tree("Laptop")
    laptop.add_child(Tree("hp"))
    laptop.add_child(Tree("dell"))
    
    tv = Tree("Tv")
    tv.add_child(Tree("onida"))
    tv.add_child(Tree("samsung"))
    tv.add_child(Tree("LG"))
    
    root.add_child(laptop)
    root.add_child(tv)
    #print(laptop.get_level())
    return root

if __name__ == '__main__':
    root = bulid_product()
    print(root.get_level())
    root.print_tree()
    pass
    
