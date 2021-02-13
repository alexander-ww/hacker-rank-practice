# Reverse Print

Given a pointer to the head of a singly-linked list, print each _data_
value from the reversed list. If the given list is empty, do not print anything.

## Example

_head*_ refers to the linked list with _data_ values 1 -> 2 -> 3 -> _NULL_

Print the following:

```
3
2
1
```

## Function Description

Complete the _reversePrint_ function.

_reversePrint_ has the following parameters:
- SinglyLinkedListNode pointer head: a reference to the head of the list

## Prints

The _data_ values of each node in the reversed list.

## Input Format

The first line of input contains _t_, the number of test cases.

The input of each test case is as follows:
- The first line contains an integer _n_, the number of elements in the list.
- Each of the next _n_ lines contains a data element for a list node.

## Constraints
- 1 <= _n_ <= 1000
- 1 <= _list[i]_ <= 1000, where _list[i]_ is the ith element in the list.

## Sample Input

```
3
5
16
12
4
2
5
3
7
3
9
5
5
1
18
3
13
```

## Sample Output

```
5
2
4
12
16
9
3
7
13
3
18
1
5
```

## Explanation

There are three test cases. There are no blank lines between test case
output. The first linked list has 5 elements: 16 -> 12 -> 4 -> 2 -> 5. 
Printing this in reverse order produces:

```
5
4
2
4
12
16
```

The second linked list has 3 elements 7 -> 3 -> 9 -> _NULL_.
Printing this in reverse order produces.

```
9
3
7
```

The third linked list has 5 elements: 5 -> 1 -> 18 -> 3 -> 13 -> _NULL_.
Printing this in reverse order produces:

```
13
3
18
1
5
```
