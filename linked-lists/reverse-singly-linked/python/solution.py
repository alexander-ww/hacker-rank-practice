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
    a node in a singly linked list.
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

    string = ""
    while node:
        string += str(node.data)
        node = node.next
        if node:
            string += sep
    print(string)

def reverse(head):
    """ Reverses a singly-linked list.

    This method accepts the head of a singly
    linked list as input and reverses that
    singly linked list and returns the head
    of that reversed list as output.

    :param head: The head of the linked list.
    :type head: SinglyLinkedListNode
    :return: The head of the reversed list.
    :rtype: SinglyLinkedListNode

    Complexity:
    - O(n) time
    - O(1) space
    """

    # initialize pointers
    s = None
    e = None

    # iterative popping and building
    while head is not None:
        s = head.next
        head.next = e
        e = head
        head = s

    return e

if __name__ == '__main__':

    tests = int(input())

    for tests_itr in range(tests):
        llist_count = int(input())

        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        llist1 = reverse(llist.head)

        print_singly_linked_list(llist1, ' ')
