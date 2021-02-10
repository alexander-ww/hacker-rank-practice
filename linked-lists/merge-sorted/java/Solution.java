import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
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
        String to_print = "";
        while (node != null) {
            to_print += String.valueOf(node.data);
            node = node.next;
            if (node != null) {
                to_print += sep;
            }
        }
        System.out.println(to_print);
    }

    /**
     * Merges two sorted singly-linked lists.
     *
     * <p>
     * This method accepts two singly-linked list
     * nodes that are the heads of two sorted
     * singly-linked lists. Upon the receipt of
     * these inputs, the method merges the two
     * singly-linked list nodes into one singly-linked
     * list and returns the node that is the head of
     * the merged list.
     * </p>
     *
     * @param head1 The head to the first sorted list.
     * @param head2 The head to the second sorted list.
     *
     * @return The sorted singly-linked list.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static SinglyLinkedListNode mergeLists(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {

        // initialize variables
        // O(1) time and O(1) space
        SinglyLinkedListNode c1 = head1;
        SinglyLinkedListNode c2 = head2;
        SinglyLinkedListNode head = null;
        SinglyLinkedListNode merged = null;

        // finished status
        boolean finished = false;

        // check bot as null
        // O(1) time and O(1) space
        boolean bothNull = c1 == null && c2 == null;

        // handle both as null
        // O(1) time and O(1) space
        if (bothNull) {
            head = null;
            finished = true;
        }

        // handle one as null
        // O(1) time and O(1) space
        else if (c1 == null) {
            head = c2;
            finished = true;
        }

        // handle one as null
        // O(1) time and O(1) space
        else if (c2 == null) {
            head = c1;
            finished = true;
        }

        // handle both non-null
        // O(n) time and O(1) space
        else {

            while (!finished) {

                // handle null head
                if (head == null) {
                    if (c1.data <= c2.data) {
                        head = c1;
                        c1 = c1.next;
                    }
                    else {
                        head = c2;
                        c2 = c2.next;
                    }
                    merged = head;
                }

                // handle populated head
                else {

                    // handle full merge
                    if (c1 == null && c2 == null) {
                        finished = true;
                    }

                    // handle full merge
                    else if (c1 != null && c2 == null) {
                        merged.next = c1;
                        c1 = c1.next;
                        finished = true;
                    }

                    // handle full merge
                    else if (c1 == null && c2 != null) {
                        merged.next = c2;
                        c2 = c2.next;
                        finished = true;
                    }

                    // handle performing merge by data
                    else {
                        if (c1.data <= c2.data) {
                            merged.next = c1;
                            c1 = c1.next;
                            merged = merged.next;
                        }
                        else {
                            merged.next = c2;
                            c2 = c2.next;
                            merged = merged.next;
                        }
                    }
                }
            }
        }

        return head;
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

            SinglyLinkedListNode llist3 = mergeLists(llist1.head, llist2.head);

            printSinglyLinkedList(llist3, " ");
        }

        scanner.close();
    }
}
