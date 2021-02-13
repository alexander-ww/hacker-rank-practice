# Cycle Detection

A linked list is said to contain a cycle if any node is visited
more than once while traversing the list. Given a pointer to
the head of a linked list, determine if it contains a cycle. If
it does, return 1. Otherwise, return 0.

## Example

_head_ refers to the list of nodes 1 -> 2 -> 3 -> _NULL_

The numbers shown are the node numbers, not their
data values. There is no cycle in this list, so return 0.

_head_ refers to the list of nodes 1 -> 2 -> 3 -> 1 -> _NULL_

There is a cycle where node 3 
points back to node 1, so return 1.

## Function Description

Complete the _has cycle_ function.

It has the following parameter:
- SinglyLinkedListNode pointer head: a reference to the head of the list

## Returns
- int: 1 if there is a cycle or 0 if there is not

Note: If the list is empty, _head_ will be null.

## Input Format

The code stub reads from stdin and passes the appropriate
argument to your function. The input format is shown below:

```
1          t = number of test cases
2          i = cycle start index
1          n = list size
1          nodes in the list
```

```
1          t = number of test cases
1          i = cycle start index
3          n = list size
1          nodes in the list
2          ...
3          ...
```

## Constraints

- 0 <= _list size_ <= 1000

## Sample Inputs

```
1
3
1
1
```

```
1
2
3
1
2
3
```

## Sample Outputs

```
0
```

```
1
```

## Explanation

1. The first list has no cycle, so return 0.
2. The second list has a cycle, so return 1.
