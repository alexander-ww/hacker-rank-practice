# Insert Singly Linked

Given the pointer to the head node of a linked list and an
integer to insert at a certain position, create a new node with
the given integer as its _data_ attribute, insert this node at the
desired position and return the head node.

A position of 0 indicates head, a position of 1 indicates one
node away from the head and so on. The head pointer given
may be null, meaning that the initial list is emtpy.

## Example

_head_ refers to the first node in the list 1 -> 2 -> 3

_data_ = 4

_position_ = 2

Insert a node at position 2 with _data_ = 4. The new list is 1 -> 2 -> 4 -> 3

## Function Description

Complete the function _insertNodeAtPosition_. It must
return a reference to the head node of your finished list.

_insertNodeAtPosition_ has the following parameters:
- head: a SinglyLinkedListNode pointer to the head of the list
- data: an integer value to insert as data in your new node
- position: an integer position to insert the new node, zero-based indexing

## Returns

- SinglyLinkedListNode pointer: a reference to the head of the revised list

## Input Format

The first line contains an integer _n_, the number of elements in the linked list.

Each of the next _n_ lines contains an integer, SinglyLinkedListNode[i].data.

The next line contains an integer _data_, the data of the node that is to be inserted.

The last line contains an integer _position_.

## Constraints

- 1 <= _n_ <= 1000
- 1 <= _SinglyLinkedListNode[i].data_ <= 1000, where _SinglyLinkedListNode[i]_ is the ith element of the linked list.
- 0 <= _position_ <= _n_

## Sample Input

```
3
16
13
7
1
2
```

## Sample Output

```
16 13 1 7
```

## Explanation

The initial linked list is 16 -> 13 -> 7. Insert 1 at the position 2 which
currently has 7 in it. The updated linked list is 16 ->13 -> 1 -> 7.
