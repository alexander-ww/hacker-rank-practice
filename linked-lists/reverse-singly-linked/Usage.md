# Reverse Singly Linked

Given the pointer to the head node of a linked list, change the _next_
pointers of the nodes so that their order is reversed. The head pointer
given may be null, meaning that the initial list is empty.

## Example

_head_ references the list 1 -> 2 -> 3 -> _NULL_

Manipulate the _next_ pointers of each node in place and return _head_,
now referencing the head of the list 3 -> 2 -> 1 -> _NULL_.

## Function Description

Complete the _reverse_ function.

_reverse_ has the following parameter:
- SinglyLinkedListNode pointer head: a reference to the head of a list

## Returns

-SinglyLinkedListNode pointer: a reference to the head of the reversed list

## Input Format

The first line contains an integer _t_, the number of test cases.

Each test case has the following format:
The first line contains an integer _n_, the number of elements in the
linked list. Each of the next _n_ lines contains an integer, the _data_
values of the elements in the linked list.

## Constraints

- 1 <= _t_ <= 10
- 1 <= _n_ <= 1000
- 1 <= _list[i]_ <= 1000, where _list[i]_ is the ith element in the list

## Sample Input

```
1
5
1
2
3
4
5
```

## Sample Output

```
5 4 3 2 1
```

## Explanation

The initial linked list is: 1 -> 2 -> 3 -> 4 -> 5 -> _NULL_

The reversed linked list is: 5 -> 4 -> 3 -> 2 -> 1 -> _NULL_
