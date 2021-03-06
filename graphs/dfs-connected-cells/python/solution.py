import math
import os
import random
import re
import sys

class Node:

    def __init__(self, id):
        self.__id = id
        self.__children = set()

    def get_id(self):
        return self.__id

    def add_child(self, child):
        self.__children.add(child)

    def get_children(self):
        return self.__children

class Graph:

    def __init__(self, grid):

        # setup empty nodes
        self.__nodes = dict()

        # build the graph nodes
        node_id = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[i])):
                value = grid[i][j]
                if value == 1:
                    node = Node(node_id)
                    self.__nodes[node_id] = node
                node_id += 1

        # add horizontal edge cnnections (bidirectional)
        for i in range(0, len(grid)):
            for j in range(0, len(grid[i]) - 1):
                curr_value = grid[i][j]
                next_value = grid[i][j + 1]
                if curr_value == 1 and next_value == 1:
                    node_id = i * len(grid[i]) + j
                    src_node_id = node_id
                    dst_node_id = src_node_id + 1
                    self.__nodes[src_node_id].add_child(dst_node_id)
                    self.__nodes[dst_node_id].add_child(src_node_id)

        # add vertical edge connections (bidirectional)
        for i in range(0, len(grid) - 1):
            for j in range(0, len(grid[i])):
                curr_value = grid[i][j]
                next_value = grid[i + 1][j]
                if curr_value == 1 and next_value == 1:
                    src_node_id = i * len(grid[i]) + j
                    dst_node_id = (i + 1) * len(grid[i + 1]) + j
                    self.__nodes[src_node_id].add_child(dst_node_id)
                    self.__nodes[dst_node_id].add_child(src_node_id)

        # add left diagonal edge connections (bidirectional)
        for i in range(0, len(grid) - 1):
            for j in range(0, len(grid[i])):
                if j - 1 >= 0:
                    curr_value = grid[i][j]
                    next_value = grid[i + 1][j - 1]
                    if curr_value == 1 and next_value == 1:
                        src_node_id = i * len(grid[i]) + j
                        dst_node_id = (i + 1) * len(grid[i + 1]) + j - 1
                        self.__nodes[src_node_id].add_child(dst_node_id)
                        self.__nodes[dst_node_id].add_child(src_node_id)

        # add right diagonal edge connections (bidirectional)
        for i in range(0, len(grid) - 1):
            for j in range(0, len(grid[i])):
                if j + 1 < len(grid[i]):
                    curr_value = grid[i][j]
                    next_value = grid[i + 1][j + 1]
                    if curr_value == 1 and next_value == 1:
                        src_node_id = i * len(grid[i]) + j
                        dst_node_id = (i + 1) * len(grid[i + 1]) + j + 1
                        self.__nodes[src_node_id].add_child(dst_node_id)
                        self.__nodes[dst_node_id].add_child(src_node_id)

    def dfs(self, root, visited):

        if root in visited:
            return visited

        else:
            visited.add(root)
            for child in self.__nodes[root].get_children():
                if not child in visited:
                    visited = self.dfs(child, visited)
            return visited

    def has_nodes(self):
        no_nodes = True
        for node_id in self.__nodes.keys():
            no_nodes = False
            break
        return not no_nodes

    def region_size(self):

        # build the current maximum size
        max_size = 0

        # build the set of remaining nodes
        remaining = set()
        for node_id in self.__nodes.keys():
            remaining.add(node_id)

        # explore all disjoint regions
        while remaining:

            # select a root node
            root = 0
            for node in remaining:
                root = node
                break

            # reset the visited set
            visited = set()

            # explore the size of a region
            visited = self.dfs(root, visited)

            current_size = 0
            for node in visited:
                current_size += 1
                remaining.remove(node)

            # updatethe maximum region size
            if current_size > max_size:
                max_size = current_size

        return max_size

def maxRegion(grid):
    graph = Graph(grid)
    size = 0
    if graph.has_nodes():
        size = graph.region_size()
    return size

if __name__ == '__main__':

    n = int(input())
    m = int(input())
    grid = []

    for _ in range(n):
        grid.append(list(map(int, input().rstrip().split())))

    res = maxRegion(grid)
    print(str(res))
