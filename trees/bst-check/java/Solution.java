/**
 * Performs in-order traversal.
 *
 * <p>
 * This method accepts a node representing
 * the root of a binary tree, and a vector of
 * data for nodes that have been traversed.
 * Upon the receipt of these inputs, the
 * method traverses the binary tree in order
 * and updates the traversed vector accordingly.
 * The end result is the return of the traversed
 * vector.
 * </p>
 *
 * @param root The provided root node.
 * @param traversed The vector of traversed node data.
 *
 * @return The vector of traversed node data.
 *
 * Complexity:
 * - O(n) time
 * - O(n) space
 */
ArrayList<Integer> inOrder(Node root, ArrayList<Integer> traversed) {
    if (root != null) {
        if (root.left != null) {
            traversed = inOrder(root.left, traversed);
            traversed.add(root.data);
            traversed = inOrder(root.right, traversed);
        }
        else {
            traversed.add(root.data);
            traversed = inOrder(root.right, traversed);
        }
    }
    return traversed;
}

/**
 * Checks if a binary tree is a BST.
 *
 * <p>
 * This method accepts a node representing
 * the root of a binary tree. Upon the
 * receipt of this input, the method checks
 * to see if the tree is a binary search
 * tree. This check is performed by seeing
 * whether the in-order traversal of the
 * binary tree is sorted. If the traversal
 * is sorted, then the tree is a BST.
 * </p>
 *
 * @param root The provided root node.
 * @return True if a BST; False otherwise.
 *
 * Complexity:
 * - O(n) time
 * - O(n) space
 */
boolean checkBST(Node root) {

    // default value
    boolean isBST = true;

    // handle populated tree
    if (root != null) {

        // in-order traversal of tree
        ArrayList<Integer> traversed = new ArrayList<Integer>();
        traversed = inOrder(root, traversed);

        // see if in-order traversal is sorted
        Integer previous = Integer.valueOf(0);
        for (int i = 0; i < traversed.size(); i++) {
            if (i == 0) {
                previous = traversed.get(i);
                continue;
            }
            if (traversed.get(i) > previous) {
                previous = traversed.get(i);
            }
            else {
                isBST = false;
                break;
            }
        }
    }

    return isBST;
}
