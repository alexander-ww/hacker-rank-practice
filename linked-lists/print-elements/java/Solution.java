import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

/**
 * Solution for linked list printing.
 *
 * <p>
 * The Solution class provides a means
 * for running the solution for printing
 * the elements of a singly linked list.
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
     * Prints the list.
     *
     * <p>
     * This method accepts a pointer to
     * the head of the singly linked list
     * and prints the contents of the
     * singly linked list node-by-node.
     * </p>
     *
     * @param head The head of the list.
     *
     * Complexity
     * - O(n) time
     * - O(1) space
     */
    static void printLinkedList(SinglyLinkedListNode head) {
        SinglyLinkedListNode node = head;
        while (node != null) {
            System.out.println(node.data);
            node = node.next;
        }
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

        printLinkedList(llist.head);

        scanner.close();
    }
}
