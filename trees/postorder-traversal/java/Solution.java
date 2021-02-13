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
     * Writes post-order listing.
     *
     * <p>
     * This method prefers to visit right
     * nodes first and then visit left nodes.
     * </p>
     *
     * Complexity:
     * - O(n) time
     * - O(n) space
     */
    public static void postOrder(Node root) {
        Stack<Integer> stack = new Stack<Integer>();
        stack = postOrder(stack, root);
        while (!stack.empty()) {
            Integer top = stack.pop();
            System.out.print(top.toString() + " ");
        }
    }

    /**
     * Maintains a stack while traversing in post order.
     *
     * Complexity:
     * - O(n) time
     * - O(n) space
     */
    public static Stack<Integer> postOrder(Stack<Integer> stack, Node node) {
        if (node != null) {
            stack.push(Integer.valueOf(node.data));
            stack = postOrder(stack, node.right);
            stack = postOrder(stack, node.left);
        }
        return stack;
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
        postOrder(root);
        System.out.println();
    }
}
