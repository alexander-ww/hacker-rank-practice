# Delete Duplicates

You are given the pointer to the head node of a sorted linked list, where
the data in the nodes is in ascending order. Delete nodes and return a
sorted list with each distinct value in the original list. The given head
pointer may be null, indicating tht the list is empty.

## Example

_head_ refers to the first node in the list 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> 3 -> _NULL_.

Remove 1 of the 2 data values and return _head_ pointing to the revised list 1 -> 2 -> 3 -> _NULL_.

## Function Description

Complete the _removeDuplicates_ function.

_removeDuplicates_ has the following parameter:
- SinglyLinkedListNode pointer head: a reference to the head of the list

## Returns
- SinglyLinkedListNode pointer: a reference to the head of the revised list

## Input Format

The first line contains an integer _t_, the number of test cases.

The format for each test case is as follows:

The first line contains an integer _n_, the number of elements in the linked list.

Each of the next _n_ lines contains an integer, the _data_ value for each of the elements of the linked list.

## Constraints
- 1 <= _t_ <= 10
- 1 <= n <= 1000
- 1 <= _list[i]_ <= 1000

## Sample Input

```
1         t = 1
5         n = 5
1         data values = 1, 2, 2, 3, 4
2
2
3
4
```

## Sample Output

```
1 2 3 4
```

## Explanation

The initial linked list is: 1 -> 2 -> 2 -> 3 -> 4 -> _NULL_

The final linked list is: 1 -> 2 -> 3 -> 4 -> _ NULL
