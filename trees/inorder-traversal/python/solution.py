import sys

class Node:
    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None
        self.level = None

    def __str__(self):
        return str(self.info)

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def create(self, val):
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

def inOrder(root):
    """ Prints the in-order traversal.

    This method accepts a pointer to the
    root node of a binary tree and prints
    the tree in order.

    :param root: The provided root node.
    :type root: Node

    Complexity:
    - O(n) time
    - O(n) space
    """

    if root is not None:
        if root.left is not None:
            inOrder(root.left)
            sys.stdout.write(str(root.info) + " ")
            inOrder(root.right)
        else:
            sys.stdout.write(str(root.info) + " ")
            inOrder(root.right)


tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

inOrder(tree.root)
print()
