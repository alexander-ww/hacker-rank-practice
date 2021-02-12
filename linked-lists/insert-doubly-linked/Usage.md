# Insert Doubly Linked

Given a reference to the head of a doubly-linked list and an integer, _data_,
create a new DoublyLinkedListNode object having data value _data_ and
insert it at the proper location to maintain the sort.

## Example

_head_ refers to the list 1 <-> 2 <-> 4 -> _NULL_

_data_ = 3

Return a reference to the new list: 1 <-> 2 <-> 3 <-> 4 -> _NULL_

## Function Description

Complete the _sortInserted_ function.

_sortInserted_ has two parameters:

1. DoublyLinkedListNode pointer head: a reference to the head of a doubly-linked list
2. int data: An integer denoting the value of the _data_ field for the DoublyLinkedListNode you must insert into the list

## Returns

- DoublyLinkedListNode pointer: a reference to the head of the list
<b>Note:</b> Recall that an empty list (i.e., where _head_ == _NULL_) and a list with one element are sorted lists.

## Input Format

The first line contains an integer _t_, the number of test cases.

Each of the test cases is in the following format:
- The first line contains an integer _n_, the number of elements in the linked list.
- Each of the next _n_ lines contains an integer, the data for each node of the linked list.
- The last line contains an integer, _data_, which needs to be inserted into the sorted doubly-linked list.

## Constraints
- 1 <= _t_ <= 10
- 1 <= _n_ <= 1000
- 1 <= _DoublyLinkedListNode.data_ <= 1000

## Sample Input

```
1          t = 1
4          n = 4
1          node data values = 1, 3, 4, 10
3
4
10
5          data = 5
```

## Sample Output

```
1 3 4 5 10
```

## Explanation

The initial doubly linked list is: 1 <-> 3 <-> 4 <-> 10 -> _NULL_

The doubly linked list after insertion is: 1 <-> 3 <-> 4 <-> 5 <-> 10 -> _NULL_
