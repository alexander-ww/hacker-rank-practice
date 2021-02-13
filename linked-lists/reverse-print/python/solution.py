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
    a node in a singly linked list
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
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node

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
        print(node.data, end='')
        node = node.next
        if node:
            print(sep, end='')

def reversePrint(head):
    """ Prints a list in reverse order.

    This method accepts the head of a
    linked list as input and prints the
    linked list in reverse order to
    the console.

    :param head: The head of the linked list.
    :type head: SinglyLinkedListNode

    Complexity:
    - O(n) time
    - O(n) space
    """

    # get the list size
    # O(n) time and O(1) space
    size = 0
    current = head
    while current is not None:
        size += 1
        current = current.next

    # store the reversed values
    # O(n) time and O(n) space
    index = 0
    values = list()
    for _ in range(size):
        values.append(0)
    current = head
    while current is not None:
        value = current.data
        values[(size - 1) - index] = value
        index += 1
        current = current.next

    # print the reversed values
    # O(n) time
    for i in range(size):
        print(values[i])


if __name__ == '__main__':
    tests = int(input())

    for tests_itr in range(tests):
        llist_count = int(input())

        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        reversePrint(llist.head)
