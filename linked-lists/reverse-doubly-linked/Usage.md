# Reverse Doubly Linked

Given the pointer to the head node of a doubly-linked list, reverse
the order of the nodes in place. That is, change the next and prev
pointers of the nodes so that the direction of the list is reversed.
Return a reference to the head node of the reversed list.

## Note

The head node might be _NULL_ to indicate that the list is empty.

## Function Description

Complete the _reverse_ function.

_reverse_ has the following parameter(s):
- DoublyLinkedListNode head: a reference to the head of a DoublyLinkedList

Returns
- DoublyLinkedListNode: a reference to the head of the reversed list

## Input Format

The first line contains an integer _t_, the number of test cases.

Each test case is of the following format:
- The first line contains an integer _n_, the number of elements in the linked list
- The next _n_ lines contain an integer each denoting an element of the linked list

## Constraints

- 1 <= _t_ <= 10
- 0 <= _n_ <= 1000
- 0 <= DoublyLinkedListNode.data <= 1000

# Output Format

Return a reference to the head of your reversed list. The provided code will
print the reverse array as one line of space-separated integers for each test
case.

## Sample Input

```
1
4
1
2
3
4
```

## Sample Output

```
4 3 2 1
```

## Explanation

The initial doubly linked list is: 1 <-> 2 <-> 3 <-> 4 -> _NULL_

The reversed doubly linked list is: 4 <-> 3 <-> 2 <-> 1 -> _NULL_
