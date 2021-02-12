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
     * Inserts a node into a sorted doubly-linked list.
     *
     * <p>
     * This method accepts a node to the head of a
     * doubly-linked list and a data value for the node
     * to insert. Upon the receipt of these inputs, the
     * method inserts the new node into the doubly
     * linked list and returns the head of the modified
     * list as output.
     * </p>
     *
     * @param head The head of the doubly-linked list.
     * @param data The data of the node to insert.
     *
     * @return The head of the modified list.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static DoublyLinkedListNode sortedInsert(DoublyLinkedListNode head, int data) {

        // store inserted list
        DoublyLinkedListNode inserted = head;
        DoublyLinkedListNode toInsert = new DoublyLinkedListNode(data);

        // handle empty list
        if (inserted == null) {
            inserted = toInsert;
        }

        // handle non-empty list
        else {

            // indicate if insertion occurred
            boolean alreadyInserted = false;

            // iterate through list
            // O(n) time and O(1) space
            while (inserted != null) {

                // handle insertion
                if (inserted.data >= data) {

                    // handle insertion between nodes
                    if (inserted.prev != null) {
                        DoublyLinkedListNode prev = inserted.prev;
                        inserted.prev.next = toInsert;
                        inserted.prev = toInsert;
                        toInsert.next = inserted;
                        toInsert.prev = prev;
                    }

                    // handle insertion before first node
                    else {
                        inserted.prev = toInsert;
                        toInsert.next = inserted;
                    }

                    // update iteration status
                    alreadyInserted = true;
                }

                // handle full traversal without insertion
                if (inserted.next == null && !alreadyInserted) {
                    inserted.next = toInsert;
                    toInsert.prev = inserted;
                    alreadyInserted = true;
                }

                // handle insertion (rewind to head)
                if (alreadyInserted) {
                    while (inserted != null) {
                        if (inserted.prev != null) {
                            inserted = inserted.prev;
                        }
                        else {
                            break;
                        }
                    }
                    break;
                }

                // update list pointer
                inserted = inserted.next;
            }
        }

        return inserted;
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

            int data = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            DoublyLinkedListNode llist1 = sortedInsert(llist.head, data);

            printDoublyLinkedList(llist1, " ");
        }

        scanner.close();
    }
}
