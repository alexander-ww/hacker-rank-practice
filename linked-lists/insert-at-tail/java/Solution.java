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

        public SinglyLinkedList() {
            this.head = null;
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
        while (node != null) {
            System.out.println(String.valueOf(node.data));
            node = node.next;
        }
    }

    /**
     * Inserts a node at the tail of a list.
     *
     * <p>
     * This method accepts a node representing the
     * head of a linked list and a value for the data of
     * a new node to add to the end of the linked list.
     * Upon the receipt of these inputs, the method
     * adds the new node to the end of the linked list.
     * </p>
     *
     * @param head The provided linked list node.
     * @param data The provided data for the node to insert.
     *
     * @return The head of the modified linked list.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static SinglyLinkedListNode insertNodeAtTail(SinglyLinkedListNode head, int data) {

        // create last node
        SinglyLinkedListNode last = new SinglyLinkedListNode(data);

        // handle empty list
        if (head == null) {
            head = last;
        }

        // handle non-empty list
        else {

            // create a current node
            SinglyLinkedListNode current = head;

            // navigate to the last node
            while (current.next != null) {
                current = current.next;
            }

            // add the last node
            current.next = last;
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
            
          SinglyLinkedListNode llist_head = insertNodeAtTail(llist.head, llistItem);

          llist.head = llist_head;
        }

        printSinglyLinkedList(llist.head, "\n");

        scanner.close();
    }
}
