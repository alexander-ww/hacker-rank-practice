# Print Elements

This is an opportunity to practice traversing a linked list. Given a
pointer to the head node of a linked list, print each node's _data_
element, one per line. If the head pointer is null (indicating the
list is empty), there is nothing to print.

## Function Description

Complete the _printLinkedList_ function.

_printLinkedList_ has the following parameter(s):
- SinglyLinkedListNode head: a reference to the head of the list

## Print

- For each node, print its _data_ value on a new line.

# Input Format

The first line of input contains _n_, the number of elements in the linked
list. The next _n_ lines contain one element each, the _data_ values for
each node.

<b>Note</b>: Do not read any input from the standard input stream or console.
Complete the _printLinkedList_ function.

## Constraints
- 1 <= _n_ <= 1000
- 1 <= _list[i]_ <= 1000, where _list[i]_ is the ith element of the linked list.

## Sample Input

```
2
16
13
```

## Sample Output

```
16
13
```

## Explanation

There are two elements in the linked list. They are represented as 16 -> 13 -> _NULL_.
So, the _printLinkedList_ function should print 16 and 13 each on a new line.
