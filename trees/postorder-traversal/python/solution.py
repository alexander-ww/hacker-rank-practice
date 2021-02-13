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

def postOrder(root):
    """ Writes post-order listing.

    This method prefers to visit right
    nodes first and then visit left nodes.

    Complexity:
    - O(n) time
    - O(n) space
    """

    try:
        stack
    except NameError:
        stack = list()

    stack = postOrderTrack(stack, root)

    while stack:
        top = stack.pop(0)
        sys.stdout.write(str(top) + " ")

def postOrderTrack(stack, node):
    """ Maintains a stack while traversing in post order.
    
    Complexity:
    - O(n) time
    - O(n) space
    """

    if node is not None:
        stack.insert(0, node.info)
        stack = postOrderTrack(stack, node.right)
        stack = postOrderTrack(stack, node.left)
    return stack


tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

postOrder(tree.root)
print()
