# Find Nearest Clone

In this challenge, there is a connected undirected graph where each of the nodes is a color.
Given a color, find the shortest path connecting any two nodes of that color. Each edge has
a weight of. If there is not a pair or if the color is not found, print -1.

## Function Description

Complete the findShortest function in the editor below. It should return an integer
representing the length of the shortest path between two nodes of the same color,
or -1 if it is not possible.

_findShortest_ has the following parameter(s):
- _g nodes_: an integer, the number of nodes
- _g from_: an array of integers, the start nodes for each edge
- _g to_: an array of integers, the end nodes for each edge
- _ids_: an array of integers, the color id per node
- _val_: an integer, the id of the color to match

## Input Format

The first line contains two space-separated integer _n_ and _m_, the number
of nodes and edges in the graph. Each of the next _m_ lines contains two space
separated integers _g from[i]_ and _g to[i]_, the nodes connected by an edge.
The next line contains _n_ space-separated integers, _ids[i]_, representing the
color id of each node from 1 to _n_. The last line contains the id of the color to
analyze.

### Note:
The nodes are indexed from 1 to _n_.

## Constraints

- 1 <= _n_ <= 10^6
- 1 <= _m_ <= 10^6
- 1 <= _ids[i]_ <= 10^8

## Output Format

Print the single integer representing the smallest path length or -1.

## Sample Input 1

```
4 3
1 2
1 3
4 2
1 2 1 1
1
```

## Sample Output 1

```
1
```

## Sample Input 2

```
4 3
1 2
1 3
4 2
1 2 3 4
2
```

## Sample Output 2

```
-1
```

## Sample Input 3

```
5 4
1 2
1 3
2 4
3 5
1 2 3 3 2
2
```

## Sample Output 3

```
-1
```
