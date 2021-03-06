# DFS Connected Cells

Consider a matrix where each cell contains either a 0 or a 1 and any
cell containing a 1 is called a filled cell. Two cells are said to be connected
if they are adjacent to each other horizontally, vertically, or diagonally. In the
diagram below, the two colored regions show cells connected to the filled
cells. Black on white are not connected.

Cells adjacent to filled cells:
If one or more filled cells are also connected, they form a region. Note that
each cell in a region is connected to at least one other cell in the region but
is not necessarily directly connected to all the other cells in the region.

Regions:
Given an _n_ by _m_ matrix, find and print the number of cells in the largest
region in the matrix.

## Function Description

Complete the function _maxRegion_. It must return an integer value, the size
of the largest region.

_maxRegion_ has the following parameter(s):
- grid: a two-dimensional array of integers

## Input Format

The first line contains an integer, _n_, the number of rows in the matrix, _grid_.
The second line contains an integer _m_, the number of columns in the matrix.
Each of the following _n_ lines contains a row of _m_ space-separated integers, _grid[i][j]_.

## Constraints

- 0 < _n_, _m_ < 10
- _grid[i][j]_ in {0, 1}

## Output Format

Print the number of cells in the largest region in the given matrix.

## Sample Input

```
4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0
```

## Sample Output

```
5
```
