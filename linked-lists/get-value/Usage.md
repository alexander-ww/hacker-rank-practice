# Get Value

Given a pointer to the head of a linked list and a specific
position, determine the data value at that position. Count
backwards from the tail node. The tail is at position 0, its
parent is at 1 and so on.

## Example

_head_ refers to 3 -> 2 -> 1 -> 0 -> _NULL_

_positionFromTail_ = 2

Each of the data values matches its distance from
the tail. The value 2 is at the desired position.

## Function Description

Complete the _getNode_ function.

_getNode_ has the following parameters:
- SinglyLinkedListNode pointer head: refers to the head of the list
- int positionFromTail: the item to retrieve

## Returns

- int: the value at the desired position

## Input Format

The first line contains an integer _t_, the number of test cases.

Each test case has the following format:
The first line contains an integer _n_, the number of elements
in the linked list. The next _n_ lines contain an integer, the data
value for an element of the linked list. The last line contains an
integer _positionFromTail_, the position from the tail to retrieve
the value of.

## Constraints

- 1 <= _t_ <= 10
- 1 <= _n_, _m_ <= 1000
- 1 <= _list[i]_ <= 1000, where _list[i]_ is the ith element of the linked list.
- 0 <= _positionFromTail_ < _n_

## Sample Input

```
2
1
1
0
3
3
2
1
2
```

## Sample Output

```
1
3
```

## Explanation

In the first case, there is one element in the linked list 
with a value of 1. The last (only) element contains 1.

In the second case, the list is 3 -> 2 -> 1 -> _NULL_.
The element with the position of 2 from the tail contains 3.
