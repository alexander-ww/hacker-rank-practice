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

    :param node: The provided head to the list.
    :type node: SinglyLinkedListNode
    :param sep: The provided separator.
    :type sep: str
    """

    string = ""
    while node:
        string += (str(node.data))
        node = node.next
        if node:
            string += (sep)
    print(string)

def mergeLists(head1, head2):
    """ Merges two sorted singly-linked lists.

    This method accepts two singly-linked list
    nodes that are the heads of two sorted
    singly-linked lists. Upon the receipt of
    these inputs, the method merges the two
    singly-linked list nodes into one singly
    linked list and returns the node that is
    the head of the merged list.

    :param head1: The head to the first sorted list.
    :type head1: SinglyLinkedListNode
    :param head2: The head to the second sorted list.
    :type head2: SinglyLinkedListNode
    :return: The sorted singly-linked list.
    :rtype: SinglyLinkedListNode

    Complexity:
    - O(n) time
    - O(1) space
    """

    # initialize variables
    # O(1) time and O(1) space
    c1 = head1
    c2 = head2
    head = None
    merged = None

    # finished status
    finished = False

    # check both as none
    # O(1) time and O(1) space
    both_null = c1 is None and c2 is None

    # handle both as none
    # O(1) time and O(1) space
    if both_null:
        head = None
        finished = True

    # handle one as none
    # O(1) time and O(1) space
    elif c1 is None:
        head = c2
        finished = True

    # handle one as none
    # O(1) time and O(1) space
    elif c2 is None:
        head = c1
        finished = True

    # handle both populated
    # O(n) time and O(1) space
    else:

        while not finished:

            # handle empty head
            if head is None:
                if c1.data <= c2.data:
                    head = c1
                    c1 = c1.next
                else:
                    head = c2
                    c2 = c2.next
                merged = head

            # handle populatedhead
            else:

                # handle full merge
                if c1 is None and c2 is None:
                    finished = True

                # handle full merge
                elif c1 is not None and c2 is None:
                    merged.next = c1
                    c1 = c1.next
                    finished = True

                # handle full merge
                elif c1 is None and c2 is not None:
                    merged.next = c2
                    c2 = c2.next
                    finished = True

                # handle performing merge by data
                else:
                    if c1.data <= c2.data:
                        merged.next = c1
                        c1 = c1.next
                        merged = merged.next
                    else:
                        merged.next = c2
                        c2 = c2.next
                        merged = merged.next

    return head

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

        llist3 = mergeLists(llist1.head, llist2.head)

        print_singly_linked_list(llist3, ' ')
