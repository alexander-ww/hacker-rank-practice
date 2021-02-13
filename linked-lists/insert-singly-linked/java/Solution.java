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
     * Inserts a node at a position.
     *
     * <p>
     * This method accepts the head of a singly-linked
     * list, the data for a node to insert, and the position
     * at which to insert the node. Upon the receipt of
     * these inputs, the method inserts the node with
     * the indicated data at the position in the singly
     * linked list. The head of the modified singly-linked
     * list is returned as output.
     * </p>
     *
     * @param head The provide head of the linked list.
     * @param data The data of the node to insert.
     * @param position The position at which to insert.
     *
     * @return The head of the modified list.
     *
     * Complexity:
     * - O(n) time
     * - O(1) time
     */
    static SinglyLinkedListNode insertNodeAtPosition(SinglyLinkedListNode head, int data, int position) {

        // the node to insert
        SinglyLinkedListNode insert = new SinglyLinkedListNode(data);

        // handle empty list
        if (head == null) {
            head = insert;
        }

        // handle non-empty list
        else {
            int count = 1;
            boolean inserted = false;
            SinglyLinkedListNode current = head;
            SinglyLinkedListNode previous = head;

            // iterate through list
            while (current.next != null) {

                // update tracking
                previous = current;
                current = current.next;

                // handle at position
                if (count == position) {
                    previous.next = insert;
                    insert.next = current;
                    inserted = true;
                    break;
                }

                // update position
                count += 1;
            }

            // handle insert one node (head)
            if (!inserted && count == 0) {
                insert.next = head;
            }

            // handle insert one node (tail)
            if (!inserted && count > 0) {
                current.next = insert;
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

        int data = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int position = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        SinglyLinkedListNode llist_head = insertNodeAtPosition(llist.head, data, position);

        printSinglyLinkedList(llist_head, " ");

        scanner.close();
    }
}
