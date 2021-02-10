#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    """ A linked list node.

    The SinglyLinkedList node class
    provides a means for representing
    a node in a singly linked list.
    """

    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    """ A linked list.

    The SinglyLinkedList class
    provides a means for representing
    a singly linked list.
    """

    def __init__(self):
        self.head = None

def print_singly_linked_list(node, sep):
    """ Prints a singly linked list.

    This method accepts a singly linked list
    node and a string representing a separator
    to use. Upon the receipt of these inputs,
    the method traverses the list from the
    provided linked list node and prints the
    value of each node to the console for viewing.

    :param node: The provided linked list node.
    :type node: SinglyLinkedListNode
    :param sep: The provided separator.
    :type sep: str
    """

    while node:
        print(str(node.data))
        node = node.next

def insertNodeAtTail(head, data):
    """ Inserts a node at the tail of a list.

    This method accepts a node representing the
    head of a linked list and a value for the data
    of a new node to add to the end of the linked
    list. Upon the receipt of these inputs, the
    method adds the new node to the end of the
    linked list.

    :param head: The provided linked list node.
    :type head: SinglyLinkedListNode
    :param data: The provided data for the node to insert.
    :type data: int

    :return: The head of the modified linked list.
    :rtype: SinglyLinkedListNode

    Complexity:
    - O(n) time
    - O(1) space
    """

    # create last node
    last = SinglyLinkedListNode(data)

    # handle empty list
    if head is None:
        head = last

    # handle non-empty list
    else:

        # create a current node
        current = head

        # navigate to the last node
        while current.next is not None:
            current = current.next

        # add the last node
        current.next = last

    return head

if __name__ == '__main__':

    llist_count = int(input())

    llist = SinglyLinkedList()

    for i in range(llist_count):
        llist_item = int(input())
        llist_head = insertNodeAtTail(llist.head, llist_item)
        llist.head = llist_head

    print_singly_linked_list(llist.head, '\n')
