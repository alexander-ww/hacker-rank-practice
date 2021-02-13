# Compare Lists

You're given the pointer to the head nodes of two linked lists.
Compare the data in the nodes of the linked lists to check if
they are equal. If all data attributes are equal and the lists are
the same length, return 1. Otherwise, return 0.

## Example

_llist1_ = 1 -> 2 -> 3 -> _NULL_

_llist2_ = 1 -> 2 -> 3 -> 4 -> _NULL_

The two lists have equal data attributes for the first 3 nodes.
_llist2 is longer, though, so the lists are not equal. Return 0.

## Function Description

Complete the _compare lists_ function.

_compare lists_ has the following parameters:
- SinglyLinkedListNode _llist1_: a reference to the head of a list
- SinglyLinkedListNode _llist2_: a reference to the head of a list

## Returns

- int: return 1 if the lists are equal, or 0 otherwise

## Input Format

The first line contains an integer _t_, the number of test cases.

Each of the test cases has the following format:
The first line contains an integer _n_, the number of nodes in
the first linked list. Each of the next _n_ lines contains an integer,
each a value for a data attribute. The next line contains an integer
_m_, the number of nodes in the second linked list. Each of the
next _m_ lines contains an integer, each a value for a data attribute.

## Constraints

- 1 <= _t_ <= 10
- 1 <= _n_, _m_ <= 1000
- 1 <= _llist1[i]_, _llist2[i]_ <= 1000

## Output Format

Compare the two linked lists and return 1 if the lists are equal.
Otherwise, return 0. Do NOT print anything to the console.

The output is handled by the code in the editor and it is as follows:
For each test case, in a new line, print 1 if the two lists are equal,
else print 0.

## Sample Input

```
2
2
1
2
1
1
2
1
2
2
1
2
```

## Sample Output

```
0
1
```

## Explanation

There are _t_ = 2 test cases, each with a pair of linked lists.

- In the first case, linked lists are: 1 -> 2 -> _NULL_ and 1 -> _NULL_
- In the second case, linked lists are: 1 -> 2 -> _NULL_ and 1 -> 2 -> _NULL_
