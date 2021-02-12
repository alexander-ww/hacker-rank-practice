# Merge Sorted Lists

Given pointers to the heads of two sorted linked lists, merge them into
a single, sorted linked list. Either head pointer may be null, meaning
that the corresponding list is empty.

## Example

_headA_ refers to 1 -> 3 -> 7 -> _NULL_

_headB_ refers to 1 -> 2 -> _NULL_

The new list is 1 -> 1 -> 2 -> 3 -> 7 -> _NULL_

## Function Description

Complete the _mergeLists_ function.

_mergeLists_ has the following parameters:
- SinglyLinkedListNode pointer _headA_: a reference to the head of a list
- SinglyLinkedListNode pointer _headB_: a reference to the head of a list

## Returns
- SinglyLinkedListNode pointer: a reference to the head of the merged list

## Input Format

The first line contains an integer _t_, the number of test cases.

The format for each test case is as follows:
The first line contains an integer_n_, the length of the first linked list.
The next _n_ lines contain an integer each, the elements of the linked list.
The next line contains an integer _m_, the length of the second linked list.
The next _m_ lines contain an integer each, the elements of the second linked
list.

## Constraints
- 1 <= _t_ <= 10
- 1 <= _n_, _m_ <= 1000
- 1 <= _list[i]_ <= 1000, where _list[i]_ is the ith element of the list

## Sample Input

```
1
3
1
2
3
2
3
4
```

## Sample Output

```
1 2 3 3 4
```

## Explanation

The first linked list is: 1 -> 3 -> 7 -> _NULL_

The second linked lis is: 3 -> 4 -> _NULL_

Hence, the merged linked list is: 1 -> 2 -> 3 -> 3 -> 4 -> _NULL_
