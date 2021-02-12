# Insert at Head

Given a pointer to the head of a linked list, insert a new node before the head.
The _next_ value in the new node should point to _head_ and the _data_ value
should be replaced with a given value. Return a reference to the new head of
the list. The head pointer may be null, meaning that the initial list is empty.

## Function Description

Complete the function _insertNodeAtHead_ in the editor below.

_insertNodeAtHead_ has the following parameters(s):
- SinglyLinkedListNode llist: a reference to the head of a list
- data: the value to insert in the _data_ field of the new node

## Input Format

The first line contains an integer _n_, the number of elements to be
inserted at the head of the list. The next _n_ lines contain an integer
each, the elements to be inserted, one per function call.

## Constraints

- 1 <= _n_ <= 1000
- 1 <= _list[i]_ <= 1000

## Sample Input

```
5
383
484
392
975
321
```

## Sample Output

```
321
975
392
484
383
```

## Explanation

Initially the list is _NULL_. After inserting 383, the list is 383 -> _NULL_

After inserting 484, the list is 484 -> 383 -> _NULL_

After inserting 392, the list is 392 -> 484 -> 383 -> _NULL_

After inserting 975, the list is 975 -> 392 -> 484 -> 383 -> _NULL_

After inserting 321, the list is 321 -> 975 -> 392 -> 484 -> 383 -> _NULL_
