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
    a node in a doubly-linked list
    """

    def __init__(self, node_data):
        self.data = node_data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    """ A doubly-linked list.

    The DoublyLinkedList class provides
    a means for representing a doubly
    linked list.
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
    provided doubly-linked list node and
    prints the value of each node to the
    console for viewing.

    :param node: The provided doubly-linked list node.
    :type node: DoublyLinkedListNode
    :param sep: The provided separator.
    :type sep: str
    """

    to_print = ""
    while node:
        to_print += str(node.data)
        node = node.next
        if node:
            to_print += sep
    print(to_print)

def sortedInsert(head, data):
    """ Inserts a node into a sorted doubly-linked list.

    This method accepts a node to the head of a
    doubly-linked list and a data value for the
    node to insert. Upon the receipt of these
    inputs, the method inserts the new node
    into the doubly-linked list and returns the
    head of the modified list as output.

    :param head: The head of the doubly-linked list.
    :type head: DoublyLinkedListNode
    :param data: The data of the node to insert.
    :type data: int
    :return: The head of the modified list.
    :type: DoublyLinkedListNode

    Complexity:
    - O(n) time
    - O(1) space
    """

    # store inserted list
    inserted = head
    to_insert = DoublyLinkedListNode(data)

    # handle empty list
    if inserted is None:
        inserted = to_insert

    # handle non-empty list
    else:

        # indicate if insertion occurred
        already_inserted = False

        # iterate through list
        # O(n) time and O(1) space
        while inserted is not None:

            # handle insertion
            if inserted.data >= data:

                # handle insertion between nodes
                if inserted.prev is not None:
                    prev = inserted.prev
                    inserted.prev.next = to_insert
                    inserted.prev = to_insert
                    to_insert.next = inserted
                    to_insert.prev = prev

                # handle insertion before first node
                else:
                    inserted.prev = to_insert
                    to_insert.next = inserted

                # update iteration status
                already_inserted = True

            # handle full traversal without iteration
            if inserted.next is None and not already_inserted:
                inserted.next = to_insert
                to_insert.prev = inserted
                already_inserted = True

            # handle insertion (rewind to head)
            if already_inserted:
                while inserted is not None:
                    if inserted.prev is not None:
                        inserted = inserted.prev
                    else:
                        break
                break

            # update list pointer
            inserted = inserted.next

    return inserted

if __name__ == '__main__':

    t = int(input())

    for t_itr in range(t):
        llist_count = int(input())

        llist = DoublyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        data = int(input())

        llist1 = sortedInsert(llist.head, data)

        print_doubly_linked_list(llist1, ' ')
