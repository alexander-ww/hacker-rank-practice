#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

def print_singly_linked_list(node, sep):
    while node:
        print(str(node.data))
        node = node.next

def insertNodeAtTail(head, data):

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
