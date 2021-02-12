# Left Rotation

A left rotation operation on an array of size _n_ shifts each of the
array's elements 1 unit to the left. Given an integer, _d_, rotate
the array that many steps left and return the result.

## Example

_d_ = 2

_arr_ = [1, 2, 3, 4, 5]

After 2 rotations, _arr'_ = [3, 4, 5, 1, 2]

## Function Description

Complete the _rotateLeft_ function.

_rotateLeft_ has the following parameters:
- int d: the amount to rotate by
- int arr[n]: the array to rotate

## Returns

- int[n]: the rotated array

## Input Format

The first line contains two space-separated integers that denote _n_, the
number of integers, and _d_, the number of left rotations to perform. The
second line contains _n_ space-separated integers that describe _arr[]_.

## Constraints

- 1 <= _n_ <= 10^5
- 1 <= _d_ <= _n_
- 1 <= _a[i]_ <= 10^6

## Sample Input

```
5 4
1 2 3 4 5
```

## Sample Output

```
5 1 2 3 4
```

## Explanation

To perform _d_ = 4 left rotations, the array undergoes the following sequence of
changes: [1, 2, 3, 4, 5] -> [2, 3, 4, 5, 1] -> [3, 4, 5, 1, 2] -> [4, 5, 1, 2, 3] -> 
[5, 1, 2, 3, 4].
