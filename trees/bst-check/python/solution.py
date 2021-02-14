def inOrder(root, traversed):
    """ Performs in-order traversal.

    This method accepts a node representing
    the root of a binary tree, and a list of
    data for nodes that have been traversed.
    Upon the receipt of these inputs, the
    method traverses the binary tree in order
    and updates the traversed list accordingly.
    The end result is the return of the traversed
    list.

    :param root: The provided root node.
    :type root: Node
    :param traversed: The traversed list of node data.
    :type traversed: list of <int>
    :return: The traversed list of node data.
    :rtype: list of <int>

    Complexity:
    - O(n) time
    - O(n) space
    """

    if root is not None:
        if root.left is not None:
            traversed = inOrder(root.left, traversed)
            traversed.append(root.data)
            traversed = inOrder(root.right, traversed)
        else:
            traversed.append(root.data)
            traversed = inOrder(root.right, traversed)
    return traversed

def checkBST(root):
    """ Checks if a binary tree is a BST.

    This method accepts a node representing
    the root of a binary tree. Upon the
    receipt of this input, the method checks
    to see if the tree is a binary search tree.
    This check is performed by seeing whether
    the in-order traversal of the binary tree
    is sorted. If the traversal is sorted, then
    the tree is a BST.

    :param root: The provided root node.
    :type root: Node
    :return True if a BST; False otherwise.

    Complexity:
    - O(n) time
    - O(n) space
    """

    isBST = True
    if root is not None:
        traversed = list()
        traversed = inOrder(root, traversed)
        previous = 0
        for i in range(len(traversed)):
            if i == 0:
                previous = traversed[i]
                continue
            if traversed[i] > previous:
                previous = traversed[i]
            else:
                isBST = False
                break
    return isBST
