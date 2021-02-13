import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

/**
 * A solution.
 *
 * <p>
 * The solution class provides a
 * runnable solution to the problem.
 * </p>
 */
public class Solution {

    /**
     * A linked list node.
     *
     * <p>
     * The SinglyLinkedListNode class
     * provides a means for representing
     * a node in a singly linked list.
     * </p>
     */
    static class SinglyLinkedListNode {
        public int data;
        public SinglyLinkedListNode next;

        public SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    /**
     * A linked list.
     *
     * <p>
     * The SinglyLinkedList class provides
     * a means for representing a singly
     * linked list.
     * </p>
     */
    static class SinglyLinkedList {
        public SinglyLinkedListNode head;
        public SinglyLinkedListNode tail;

        public SinglyLinkedList() {
            this.head = null;
            this.tail = null;
        }

        public void insertNode(int nodeData) {
            SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

            if (this.head == null) {
                this.head = node;
            } else {
                this.tail.next = node;
            }

            this.tail = node;
        }
    }

    /**
     * Prints a singly linked list.
     *
     * <p>
     * This method accepts a singly linked list
     * node and a string representing a separator
     * to use. Upon the receipt of these inputs,
     * the method traverses the list from the provided
     * linked list node and prints the value of each
     * node to the console for viewing.
     * </p>
     *
     * @param node The provided linked list node.
     * @param sep The provided separator.
     */
    public static void printSinglyLinkedList(SinglyLinkedListNode node, String sep) {
        String toPrint = "";
        while (node != null) {
            toPrint += String.valueOf(node.data);
            node = node.next;
            if (node != null) {
                toPrint += sep;
            }
        }
        System.out.println(toPrint);
    }

    /**
     * Compares two linked lists.
     *
     * <p>
     * This method accepts the head of a linked list and
     * the head of a linked list. Upon the receipt of these
     * inputs, the method checks for whether the two
     * linked lists are equal in terms of the content that
     * they contain. If the two lists are equal, then a value
     * of true is returned; Otherwise, a value of false is
     * returned.
     * </p>
     *
     * @param head1 The head of the first linked list.
     * @param head2 The head of the second linked list.
     *
     * @return True if equal; False otherwise.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static boolean compareLists(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {

        // have linked list references
        // O(1) time and O(1) space
        boolean areEqual = true;
        SinglyLinkedListNode c1 = head1;
        SinglyLinkedListNode c2 = head2;

        // iterate through linked lists
        // O(n) time and O(1) space
        while (c1 != null && c2 != null) {
            if (c1.data != c2.data) {
                areEqual = false;
                break;
            }
            c1 = c1.next;
            c2 = c2.next;
        }

        // handle early termination
        // O(1) time and O(1) space
        if (c1 != null || c2 != null) {
            areEqual = false;
        }

        return areEqual;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int tests = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int testsItr = 0; testsItr < tests; testsItr++) {
            SinglyLinkedList llist1 = new SinglyLinkedList();

            int llist1Count = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < llist1Count; i++) {
                int llist1Item = scanner.nextInt();
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
                llist1.insertNode(llist1Item);
            }
          
              SinglyLinkedList llist2 = new SinglyLinkedList();

            int llist2Count = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < llist2Count; i++) {
                int llist2Item = scanner.nextInt();
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
                llist2.insertNode(llist2Item);
            }

            boolean result = compareLists(llist1.head, llist2.head);

            System.out.println(String.valueOf(result ? 1 : 0));
        }

        scanner.close();
    }
}
