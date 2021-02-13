#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    """ A linked list node.

    The SinglyLinkedListNode class
    provides a means for representing
    a node in a singly-linked list.
    """

    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    """ A linked list.

    The SinglyLinkedList class provides
    a means for representing a singly
    linked list.
    """

    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node


        self.tail = node

def print_singly_linked_list(node, sep):
    """ Prints a singly-linked list.

    This method accepts a singly-linked list
    node and a string representing a separator
    to use. Upon the receipt of these inputs,
    the method traverses the list from the
    provided linked list node and prints the
    value of each node to the console for
    viewing.

    :param node: The provided linked list node.
    :type node: SinglyLinkedListNode
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

def insertNodeAtPosition(head, data, position):
    """
    """

    # the node to insert
    insert = SinglyLinkedListNode(data)

    # handle empty list
    if head is None:
        head = insert

    # handle non-empty list
    else:
        count = 1
        inserted = False
        current = head
        previous = head

        # iterate through list
        while current.next is not None:

            # update tracking
            previous = current
            current = current.next

            # handle at position
            if count == position:
                previous.next = insert
                insert.next = current
                inserted = true
                break

            # update position
            count += 1

        # handle insert one node (head)
        if not inserted and count == 0:
            insert.next = head

        # handle insert one node (tail)
        if not inserted and count > 0:
            current.next = insert

    return head

if __name__ == '__main__':

    llist_count = int(input())

    llist = SinglyLinkedList()

    for _ in range(llist_count):
        llist_item = int(input())
        llist.insert_node(llist_item)

    data = int(input())

    position = int(input())

    llist_head = insertNodeAtPosition(llist.head, data, position)

    print_singly_linked_list(llist_head, ' ')
