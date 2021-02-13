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
     * Deletes a node.
     *
     * <p>
     * This method accepts a node representing the
     * head of a linked list and an integer representing
     * the index of the node that is to be removed.
     * Upon the receipt of these inputs, the method
     * iterates through the linked list and removes the
     * node at the position specified. The head of the
     * modified list is then returned.
     * </p>
     *
     * @param head The head of the linked list.
     * @param position The index of the node to remove.
     *
     * @return The head of the modified linked list.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static SinglyLinkedListNode deleteNode(SinglyLinkedListNode head, int position) {

        // handle non-empty list
        if (head != null) {

            // iterate through nodes
            int count = 0;
            SinglyLinkedListNode previous = head;
            SinglyLinkedListNode current = head;

            while (current != null) {

                // handle position
                if (count == position) {

                    // handle first node
                    if (count == 0) {
                        head = current.next;
                    }

                    // handle last node
                    else if (current.next == null) {
                        previous.next = null;
                    }

                    // handle in between nodes
                    else {
                        previous.next = current.next;
                    }
                }

                // update tracking
                previous = current;
                current = current.next;
                count += 1;
            }
        }

        return head;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        SinglyLinkedList llist = new SinglyLinkedList();

        int llistCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < llistCount; i++) {
            int llistItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            llist.insertNode(llistItem);
        }

        int position = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        SinglyLinkedListNode llist1 = deleteNode(llist.head, position);

        printSinglyLinkedList(llist1, " ");

        scanner.close();
    }
}
