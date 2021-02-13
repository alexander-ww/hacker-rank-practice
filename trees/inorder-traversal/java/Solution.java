import java.util.*;
import java.io.*;

class Node {
    Node left;
    Node right;
    int data;
    
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {

    /**
     * Prints the in-order traversal.
     *
     * <p>
     * This method accepts a pointer to the
     * root node of a binary tree and prints
     * the tree in order.
     * </p>
     *
     * @param root The provided root node.
     *
     * Complexity:
     * - O(n) time
     * - O(n) space
     */
    public static void inOrder(Node root) {
        if (root != null) {
            if (root.left != null) {
                inOrder(root.left);
                System.out.print(Integer.valueOf(root.data).toString() + " ");
                inOrder(root.right);
            }
            else {
                System.out.print(Integer.valueOf(root.data).toString() + " ");
                inOrder(root.right);
            }
        }
    }

    public static Node insert(Node root, int data) {
        if(root == null) {
            return new Node(data);
        } else {
            Node cur;
            if(data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        Node root = null;
        while(t-- > 0) {
            int data = scan.nextInt();
            root = insert(root, data);
        }
        scan.close();
        inOrder(root);
        System.out.println();
    }
}
