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

    This method accepts a singly linked list
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

def getNode(head, positionFromTail):
    """ Gets the node at the given position.

    This method accepts a node representing the
    head of a singly-linked list and a postion
    from the tail of the list. Upon the receipt
    of these inputs, the method acquires the
    value at the node in the specified position
    in the list.

    :param head: The provided head of the list.
    :type head: SinglyLinkedListNode
    :param positionFromTail: The provided position from the tail.
    :type positionFromTail: int
    :return: The value of the node at the given tail position.
    :rtype: int

    Complexity:
    - O(n) time
    - O(1) space
    """

    data = 0

    # get the list size
    # O(n) time and O(1) space
    size = 0
    c = head
    while c is not None:
        size += 1
        c = c.next

    # compute the tail position
    # O(n) time and O(1) space
    count = 0
    position = (size - 1) - positionFromTail
    c = head
    while c is not None:
        if count == position:
            data = c.data
            break
        c = c.next
        count += 1

    return data


if __name__ == '__main__':

    tests = int(input())

    for tests_itr in range(tests):
        llist_count = int(input())

        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        position = int(input())

        result = getNode(llist.head, position)

        print(str(result))
