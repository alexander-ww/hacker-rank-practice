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


def preOrder(root):
    """ Prints the pre-order traversal.

    The time bound is optimal since
    every node has to be viewed once.
    The space bound is not optimal
    since we can develop an iterative
    solution that avoids use of the
    stack.

    The optimal complexities for this
    problem are O(n) time and O(1) space.

    Complexity:
    - O(n) time
    - O(n) space
    """

    if root is not None:
        sys.stdout.write(str(root.info) + " ")
        preOrder(root.left)
        preOrder(root.right)


tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

preOrder(tree.root)
print()
