from Node import Node

class Btree:
    """_summary_
    """

    def __init__(self, node = None):
        self.__root = node

    def insert(self, node) -> bool:
        if not self.__root:
            self.__root = node
            return True
        
        self.__root.insert(node)
    
    def printTree(self):
        return self.__root.printNTree(self.__root)

class BTree_Node:
    """_summary_
    """

    def __init__(self, name):
        self._node = Node(name)
        self._left = None
        self._right = None
    
    def setLeftChild(self, node) -> bool:
        self._left = node
        return True

    def setRightChild(self, node) -> bool:
        self._right = node
        return True

    def insert(self, node) -> bool:
        if self.getId() > node.getId():
            if not self._left:
                return self.setLeftChild(node)
            else:
                print(f"Insertando nodo{node.getId()}")
                return self._left.insert(node)
        
        if not self._right:
            return self.setRightChild(node)
        else:
            print(f"Insertando nodo{node.getId()}")
            return self._right.insert(node)
    
    def getId(self):
        return self._node.getId()

    def getName(self):
        return self._node.getName()

    def printNTree(self, node):
        tree = []
        if node:
            tree = self.printNTree(node._left)
            tree.append(node.getName())
            tree += self.printNTree(node._right)

        return tree


if __name__ == "__main__":
    n1 = BTree_Node("First")
    n2 = BTree_Node("Second")
    n3 = BTree_Node("Third")
    n4 = BTree_Node("Root")
    n5 = BTree_Node("Fourth")
    n6 = BTree_Node("Fifth")
    n7 = BTree_Node("Sixth")

    binaryTree = Btree()

    binaryTree.insert(n4)
    binaryTree.insert(n1)
    binaryTree.insert(n2)
    binaryTree.insert(n3)
    binaryTree.insert(n5)
    binaryTree.insert(n6)
    binaryTree.insert(n7)

    print(binaryTree.printTree())
