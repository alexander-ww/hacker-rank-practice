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
     * Determines if a list has a cycle.
     *
     * <p>
     * This method accepts the head of a linked list
     * as input and determines whether the linked
     * list contains any cycles. There is a fast pointer
     * and a slow pointer, and if the two catch up to
     * each other then there is a cycle (because this
     * would be impossible if there were not a cycle).
     * </p>
     *
     * @param head The provided head of a linked list.
     *
     * @return True if there is a cycle; False otherwise
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    static boolean hasCycle(SinglyLinkedListNode head) {

        // default status
        // O(1) time and O(1) space
        boolean cycle = false;

        // maintain list tracking
        // O(1) time and O(1) space
        SinglyLinkedListNode slow = head;
        SinglyLinkedListNode fast = head;

        // handle non-empty list
        if (head != null) {

            // iterate through list
            // O(n) time and O(1) space
            while (fast != null && fast.next != null) {

                // update the slow pointer
                // O(1) time
                slow = slow.next;

                // update the fast pointer
                // O(1) time
                fast = fast.next.next;

                // check if cycle is present
                // O(1) time
                if (slow == fast) {
                    cycle = true;
                    break;
                }
            }
        }

        return cycle;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int tests = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int testsItr = 0; testsItr < tests; testsItr++) {
            int index = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            SinglyLinkedList llist = new SinglyLinkedList();

            int llistCount = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < llistCount; i++) {
                int llistItem = scanner.nextInt();
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
                llist.insertNode(llistItem);
            }
          
            SinglyLinkedListNode extra = new SinglyLinkedListNode(-1);
            SinglyLinkedListNode temp = llist.head;

            for (int i = 0; i < llistCount; i++) {
                if (i == index) {
                    extra = temp;
                }
                if (i != llistCount-1) {
                    temp = temp.next;
                }
            }

            temp.next = extra;

            boolean result = hasCycle(llist.head);

            System.out.println(String.valueOf(result ? 1 : 0));
        }

        scanner.close();
    }
}

