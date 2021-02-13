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
    """ Prints a singly-linked list.

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

    to_print = ""
    while node:
        to_print += str(node.data)
        node = node.next
        if node:
            to_print += sep
    print(to_print)

def has_cycle(head):
    """ Determines if a list has a cycle.

    This method accepts the head of a linked
    list as input and determines whether the
    linked list contains any cycles. There is
    a fast pointer and a slow pointer, and if
    the two catch up to each other then there
    is a cycle (because this would be impossible
    if there were not a cycle).

    :param head: The provided head of a linked list.
    :type head: SinglyLinkedListNode
    :return: True if there is a cycle; False otherwise.
    :rtype: bool
    """

    # default status
    # O(1) time and O(1) space
    cycle = False

    # maintain list tracking
    # O(1) time and O(1) space
    slow = head
    fast = head

    # handle non-empty list
    if head is not None:

        # iterate throug list
        # O(n) time and O(1) space
        while fast is not None and fast.next is not None:

            # update the slow pointer
            # O(1) time
            slow = slow.next

            # update the fast pointer
            # O(1) time
            fast = fast.next.next

            # check if cycle is present
            # O(1) time
            if slow == fast:
                cycle = True
                break

    return cycle


if __name__ == '__main__':

    tests = int(input())

    for tests_itr in range(tests):
        index = int(input())

        llist_count = int(input())

        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        extra = SinglyLinkedListNode(-1);
        temp = llist.head;

        for i in range(llist_count):
            if i == index:
                extra = temp

            if i != llist_count-1:
                temp = temp.next

        temp.next = extra

        result = has_cycle(llist.head)

        print(str(int(result)))
