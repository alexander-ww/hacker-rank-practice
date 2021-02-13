# Delete Node

Delete the node at a given position in a linked list and return a
reference to the head node. The head is at position 0. The list
may be empty after you delete the node. In that case, return a
null value.

## Example

_llist_ = 0 -> 1 -> 2 -> 3

_position_ = 2

After removing the node at position 2, _llist'_ = 0 -> 1 -> 3.

## Function Description

Complete the _deleteNode_ function.

_deleteNode_ has the following parameters:
- SinglyLinkedListNode pointer llist: a reference to the head node in the list.
- int position: the position of the node to remove

## Returns

- SinglyLinkedListNode pointer: a reference to the head of the modified list

## Input Format

The first line of input contains an integer _n_, the number
of elements in the linked list. Each of the next _n_ lines
contains an integer, the node data value in order. The last
line contains an integer, _position_, the position of the node
to delete.

## Constraints

- 1 <= _n_ <= 1000
- 1 <= _list[i]_ <= 1000, where _list[i]_ is the ith element of the linked list.

## Sample Input

```
8
20
6
2
19
7
4
15
9
3
```

## Sample Output

```
20 6 2 7 4 15 9
```

## Explanation

The original list is 20 -> 6 -> 2 -> 19 -> 7 -> 4 -> 15 -> 9.
After deleting the node at position 3, the list is
20 -> 6 -> 2 -> 7 -> 4 -> 15 -> 9.
