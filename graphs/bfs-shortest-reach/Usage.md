# BFS Shortest Reach

Consider an undirected graph consisting of _n_ nodes where each node is labeled
from 1 to _n_ and the edge between any two nodes is always of length 6. We define
node _s_ to be the starting position for a BFS. Given a graph, determine the distances
from the start node to each of its descendants and return the list in node number order,
ascending. If a node is disconnected, it's distance should be -1.

## Function Description

The first line contains an integer, _q_, the number of queries.

Each of the following _q_ sets of lines is as follows:
- The first line contains two space-separated integers, _n_ and _m_, the number of nodes and the number of edges.
- Each of the next _m_ lines contains two space-separated integers, _u_ and _v_, describing an edge connecting node _u_ to node _v_.
- The last line contains a single integer, _s_, the index of the starting node.

## Constraints

- 1 <= _q_ <= 10
- 2 <= _n_ <= 1000
- 1 <= _m_ <= _n_ (_n_ - 1) / 2
- 1 <= _u_, _v_, _s_ <= _n_

## Output Format

For each of the _q_ queries, print a single line of _n_ - 1 space separated integers denoting the
shortest distances to each of the _n_ - 1 other nodes from starting position _s_. These distances
should be listed sequentially by node number (i.e., 1, 2, ..., _n_), but should not include node _s_.
If some node is unreachable from _s_, print - 1 as the distance to that node.

## Sample Input

```
2
4 2
1 2
1 3
1
3 1
2 3
2
```

## Sample Output

```
6 6 -1
-1 6
```
