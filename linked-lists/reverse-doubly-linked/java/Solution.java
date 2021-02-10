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
     * A doubly-linked list node.
     *
     * <p>
     * The DoublyLinkedListNode class
     * provides a means for representing
     * a node in a doubly linked list.
     * </p>
     */
    static class DoublyLinkedListNode {
        public int data;
        public DoublyLinkedListNode next;
        public DoublyLinkedListNode prev;

        public DoublyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
            this.prev = null;
        }
    }

    /**
     * A doubly-linked list.
     *
     * <p>
     * The DoublyLinkedList class provides a
     * means for representing a doubly-linked list.
     * </p>
     */
    static class DoublyLinkedList {
        public DoublyLinkedListNode head;
        public DoublyLinkedListNode tail;

        public DoublyLinkedList() {
            this.head = null;
            this.tail = null;
        }

        public void insertNode(int nodeData) {
            DoublyLinkedListNode node = new DoublyLinkedListNode(nodeData);

            if (this.head == null) {
                this.head = node;
            } else {
                this.tail.next = node;
                node.prev = this.tail;
            }

            this.tail = node;
        }
    }

    /**
     * Prints a doubly-linked list.
     *
     * <p>
     * This method accepts a doubly-linked list
     * node and a string representing a separator
     * to use. Upon the receipt of these inputs,
     * the method traverses the list from the
     * provided doubly-linked list node and
     * prints the value of each node to the
     * console for viewing.
     * </p>
     *
     * @param node The provided doubly-linked list node.
     * @param sep The provided separator.
     */
    public static void printDoublyLinkedList(DoublyLinkedListNode node, String sep) {
        String to_print = "";
        while (node != null) {
            to_print += String.valueOf(node.data);
            to_print += sep;
            node = node.next;
        }
        System.out.println(to_print);
    }

    /**
     * Reverses a doubly linked list.
     *
     * <p>
     * This method accepts a node representing
     * the head of a doubly-linked list and reverses
     * the doubly linked list by swapping its previous
     * and next pointers. The produced result is the
     * head of the reversed doubly-linked list.
     * </p>
     *
     * @param head The head of the original list.
     *
     * @return The head of the reversed list.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static DoublyLinkedListNode reverse(DoublyLinkedListNode head) {
        DoublyLinkedListNode reversed = head;

        // handle non-empty list
        if (reversed != null) {

            // reverse previous and next pointers
            // O(n) time and O(1) space
            DoublyLinkedListNode curr = reversed;
            DoublyLinkedListNode next = null;
            DoublyLinkedListNode prev = null;
            DoublyLinkedListNode temp = null;

            // traverse forward and swap pointers
            while (curr != null) {

                // save previous and next
                prev = curr.prev;
                next = curr.next;

                // update current node
                curr.prev = next;
                curr.next = prev;

                // go to next node
                curr = next;
            }

            // rewind to head
            // O(n) time and O(1) space
            while (reversed != null) {
                if (reversed.prev != null) {
                    reversed = reversed.prev;
                }
                else {
                    break;
                }
            }
        }

        return reversed;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            DoublyLinkedList llist = new DoublyLinkedList();

            int llistCount = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < llistCount; i++) {
                int llistItem = scanner.nextInt();
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                llist.insertNode(llistItem);
            }

            DoublyLinkedListNode llist1 = reverse(llist.head);

            printDoublyLinkedList(llist1, " ");
        }

        scanner.close();
    }
}

