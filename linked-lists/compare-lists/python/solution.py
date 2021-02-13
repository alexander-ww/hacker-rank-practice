#!/bin/python3

import os
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
    value of each node to the console for viewing.

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

def compare_lists(llist1, llist2):
    """ Compares two linked lists.

    This method accepts the head of a linked list
    and the head of a linked list. Upon the receipt
    of these inputs, the method checks for whether
    the two linked lists are equal in terms of the
    content that they contain. If the two lists are
    equal, then a value of true is returned; Otherwise,
    a value of false is returned.

    :param llist1: The head of the first linked list.
    :type llist1: SinglyLinkedListNode
    :param llist2: The head of the second linked list.
    :type llist2: SinglyLinkedListNode
    :return: True if equal; False otherwise.
    :rtype: bool

    Complexity:
    - O(n) time
    - O(1) space
    """

    # have linked list references
    # O(1) time and O(1) space
    are_equal = True
    c1 = llist1
    c2 = llist2

    # iterate through linked lists
    # O(n) time and O(1) space
    while c1 is not None and c2 is not None:
        if c1.data != c2.data:
            are_equal = False
            break
        c1 = c1.next
        c2 = c2.next

    # handle early termination
    # O(1) time and O(1) space
    if c1 is not None or c2 is not None:
        are_equal = False

    return are_equal


if __name__ == '__main__':

    tests = int(input())

    for tests_itr in range(tests):
        llist1_count = int(input())
        llist1 = SinglyLinkedList()

        for _ in range(llist1_count):
            llist1_item = int(input())
            llist1.insert_node(llist1_item)
            
        llist2_count = int(input())
        llist2 = SinglyLinkedList()

        for _ in range(llist2_count):
            llist2_item = int(input())
            llist2.insert_node(llist2_item)

        result = compare_lists(llist1.head, llist2.head)

        print(str(int(result)))
