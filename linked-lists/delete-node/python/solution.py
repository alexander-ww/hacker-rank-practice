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

def deleteNode(head, position):
    """ Deletes a node.

    This method accepts a node representing
    the head of a linked list and an integer
    representing the index of the node that
    is to be removed. Upon the receipt of
    these inputs, the method iterates through
    the linked list and removes the node at
    the position specified. The head of the
    modified list is then returned.

    :param head: The head of the linked list.
    :type head: SinglyLinkedListNode
    :param position: The index of the node to remove.
    :type position: int
    :return: The head of the modified linked list.
    :rtype: SinglyLinkedListNode

    Complexity:
    - O(n) time
    - O(1) space
    """

    # handle non-empty list
    if head is None:

        # iterate through nodes
        count = 0
        previous = head
        current = head

        while current is not None:

            # handle position
            if count == position:

                # handle first node
                if count == 0:
                    head = current.next

                # handle last node
                elif current.next is None:
                    previous.next = None

                # handle in between nodes
                else:
                    previous.next = current.next

            # update tracking
            previous = current
            current = current.next
            count += 1

    return head


if __name__ == '__main__':

    llist_count = int(input())

    llist = SinglyLinkedList()

    for _ in range(llist_count):
        llist_item = int(input())
        llist.insert_node(llist_item)

    position = int(input())

    llist1 = deleteNode(llist.head, position)

    print_singly_linked_list(llist1, ' ')
