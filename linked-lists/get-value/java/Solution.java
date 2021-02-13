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
     * Gets the node at a given position.
     *
     * <p>
     * This method accepts a node representing the
     * head of a singly-linked list and a position from
     * the tail of the list. Upon the receipt of these
     * inputs, the method acquires the value at the
     * node in the specified position in the list.
     * </p>
     *
     * @param head The provided head of the list.
     * @param positionFromTail The provided position from the tail.
     *
     * @return The value of the node at the given tail position.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static int getNode(SinglyLinkedListNode head, int positionFromTail) {

        int data = 0;

        // get the list size
        // O(n) time and O(1) space
        int size = 0;
        SinglyLinkedListNode c = head;
        while (c != null) {
            size += 1;
            c = c.next;
        }

        // compute the tail position
        // O(n) time and O(1) space
        int count = 0;
        int position = (size - 1) - positionFromTail;
        c = head;
        while (c != null) {
            if (count == position) {
                data = c.data;
                break;
            }
            c = c.next;
            count += 1;
        }

        return data;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int tests = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int testsItr = 0; testsItr < tests; testsItr++) {
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

            int result = getNode(llist.head, position);

            System.out.println(String.valueOf(result));
        }

        scanner.close();
    }
}

