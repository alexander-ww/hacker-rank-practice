#!/bin/python3

import math
import os
import random
import re
import sys

class DoublyLinkedListNode:
    """ A doubly-linked list node.

    The DoublyLinkedListNode class
    provides a means for representing
    a node in a doubly-linked list.
    """

    def __init__(self, node_data):
        self.data = node_data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    """ A doubly-linked list.

    The DoublyLinkedList class
    provides a means for representing
    a doubly-linked list.
    """

    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = DoublyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node
            node.prev = self.tail


        self.tail = node

def print_doubly_linked_list(node, sep):
    """ Prints a doubly-linked list.

    This method accepts a doubly-linked list
    node and a string representing a separator
    to use. Upon the receipt of these inputs,
    the method traverses the list from the
    provided doubly-linked list node and prints
    the value of each node to the console for
    viewing.

    :param node: The provided doubly-linked list node.
    :type node: DoublyLinkedListNode
    :param sep: The provided separator.
    :type sep: str
    """

    to_print = ""
    while node:
        to_print += str(node.data)
        to_print += sep
        node = node.next
    print(to_print)

def reverse(head):
    """ Reverses a doubly-linked list.

    This method accepts a node representing
    the head of a doubly-linked list and
    reverses the doubly-linked list by
    swapping its previous and next pointers.
    The produced result is the head of the
    reversed doubly-linked list.

    :param head: The head of the original list.
    :type head: DoublyLinkedListNode
    :return: The head of the reversed list.
    :rtype: DoubleLinkedListNode

    Complexity:
    - O(n) time
    - O(1) space
    """

    reversed = head

    # handle non-empty list
    if reversed is not None:

        # reverse previous and next pointers
        # O(n) time and O(1) space
        curr = reversed
        next = None
        prev = None
        temp = None

        # traverse forward and swap pointers
        while curr is not None:

            # save previous and next
            prev = curr.prev
            next = curr.next

            # update current node
            curr.prev = next
            curr.next = prev

            # go to next node
            curr = next

        # rewind to head
        # O(n) time and O(1) space
        while reversed is not None:
            if reversed.prev is not None:
                reversed = reversed.prev
            else:
                break

    return reversed


if __name__ == '__main__':

    t = int(input())

    for t_itr in range(t):
        llist_count = int(input())

        llist = DoublyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        llist1 = reverse(llist.head)

        print_doubly_linked_list(llist1, ' ')
