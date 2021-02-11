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

def removeDuplicates(head):
    """ Removes duplicates.

    This method accepts a linked list node
    representing the head of a linked list
    and removes all duplicates from the
    linked list.

    :param head: The head of the linked list.
    :type head: SinglyLinkedListNode
    :return: The head of the list with duplicates removed.
    :rtype: SinglyLinkedListNode

    Complexity:
    - O(n) time
    - O(1) space
    """

    # revise list
    revised_head = None
    revised = None

    # handle empty list
    if head is None:
        revised_head = head

    # handle non-empty list
    else:

        # iterate through list
        # O(n) time and O(1) space
        previous = -1
        current = head
        while current is not None:
            if current.data != previous:
                if revised is None:
                    revised = current
                    revisedHead = revised
                else:
                    revised.next = current
                    revised = revised.next
            else:
                if current.next is None:
                    revised.next = None
                    revised = revised.next
            previous = current.data
            current = current.next

    return revised_head


if __name__ == '__main__':

    t = int(input())

    for t_itr in range(t):
        llist_count = int(input())

        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        llist1 = removeDuplicates(llist.head)

        print_singly_linked_list(llist1, ' ')
